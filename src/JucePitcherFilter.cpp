/*  Pehr Hovey http://pehrhovey.net
	
	MAT240A Fall 2008
	University of California Santa Barbara
	JucePitcherFilter.cpp

	Juce Pitcher
	Pitch Shifting and Vocal Removal VST Plugin

	Based on JUCE VST example, uses SoundTouch library for pitch-shifting

*/
/*
  ==============================================================================

   This file is part of the JUCE library - "Jules' Utility Class Extensions"
   Copyright 2004-7 by Raw Material Software ltd.

  ------------------------------------------------------------------------------

   JUCE can be redistributed and/or modified under the terms of the
   GNU General Public License, as published by the Free Software Foundation;
   either version 2 of the License, or (at your option) any later version.

   JUCE is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with JUCE; if not, visit www.gnu.org/licenses or write to the
   Free Software Foundation, Inc., 59 Temple Place, Suite 330,
   Boston, MA 02111-1307 USA

  ------------------------------------------------------------------------------

   If you'd like to release a closed-source product which uses JUCE, commercial
   licenses are also available: visit www.rawmaterialsoftware.com/juce for
   more information.

  ==============================================================================
*/

#include "includes.h"
#include "JucePitcherFilter.h"
#include "JucePitcherComponent.h"

//==============================================================================
/**
    This function must be implemented to create a new instance of your
    plugin object.
*/
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new JucePitcherFilter();
}

//==============================================================================
JucePitcherFilter::JucePitcherFilter()
{
    sampleRate = 44100;
	//Store in VST parameter range
	gain = 1.0; //Main gain
	
	pitch0=0.50; //No pitch change
	gain0=0.75;

	pitch1=0.50; //no pitch change
	gain1=0.75;

	voxWetDry = 1;

	voxRemoveEnabled = 0;
	pitchShiftEnabled = 1;

	bassMix = 0.5;

	bassMixFreq = mapToVST(50,500,150);
	
	fMax = 20000;
	freq0 = mapToVST(0,fMax,1000); //Hz  
	freq1 = mapToVST(0,fMax,6000);

	processor_0 = new soundtouch::SoundTouch();
	processor_0->setChannels(1);
	processor_0->setSampleRate(sampleRate);

	processor_1 = new soundtouch::SoundTouch();
	processor_1->setChannels(1);
	processor_1->setSampleRate(sampleRate);
	
	filter_0 = new IIRFilter(); 
	filter_0->makeLowPass(sampleRate, mapFromVST(0,fMax,freq0));

	filter_1 = new IIRFilter();
	filter_1->makeHighPass(sampleRate, mapFromVST(0,fMax,freq1));

	bass_mix_filter = new IIRFilter();
	bass_mix_filter->makeLowPass(sampleRate, bassMixFreq); //low-freq signal to mix into the vox removed signal

	
}

JucePitcherFilter::~JucePitcherFilter()
{
}

//==============================================================================

const String JucePitcherFilter::getName() const
{
    return "Juce Pitcher Filter";
}

int JucePitcherFilter::getNumParameters()
{
    return kNumParams;
}

float JucePitcherFilter::getParameter (int index)
{
    float v = 0; 

	switch (index) 
	{ 
		case kGain0 :		v = gain0;	break; 
		case kPitch0 :		v = pitch0;	break; 
			
		case kGain1 :		v = gain1;	break; 
		case kPitch1 :		v = pitch1;	break; 
		
		case kFreq0 :		v = freq0;	break; 
		case kFreq1 :		v = freq1;	break; 

		case kGain :		v = gain;		break;
		
		case kVoxRemove :		v = voxRemoveEnabled;		break;
		case kVoxWetDry :		v =  voxWetDry;		break;
		case kBassMix :		v =  bassMix;		break;
		case kBassMixFreq :		v =  bassMixFreq;		break;
		case kPitchShift :		v =  pitchShiftEnabled;		break;

			
	} 
	
	return v; 
}

//Will be called from JUCE or from HOST. HOST uses 0-1.0 for range of parameters
void JucePitcherFilter::setParameter (int index, float newValue)
{
    switch (index) 
	{ 
		case kGain0:{	
						gain0 = newValue; 
						sendChangeMessage (this); 
						break; 
					}
		case kPitch0:{	
							pitch0 = newValue; 
							processor_0->setPitchSemiTones((float)(pitch0-0.5)*24); //-12.0 to 12.0  

							sendChangeMessage (this); 
							break; 
						}
		case kGain1:{	
						gain1 = newValue; 
						sendChangeMessage (this); 
						break; 
					}
		case kPitch1:{	
							pitch1 = newValue; 
							processor_1->setPitchSemiTones((float)(pitch1-0.5)*24); //-12.0 to 12.0  

							sendChangeMessage (this); 
							break; 
						}

	 	case kFreq0:{	
					freq0 = newValue; 
					setFilter0Freq(freq0);
					sendChangeMessage (this); 
					break; 
				}
		
		case kFreq1:{	
					freq1 = newValue;
					setFilter1Freq(freq1);
					sendChangeMessage (this); 
					break; 
				}
		case kBassMixFreq :{	
					bassMixFreq = newValue;
					setBassMixFreq(bassMixFreq);
					sendChangeMessage (this); 
					break; 
				}

		case kGain:{
						gain = newValue; 
						sendChangeMessage (this); 
						break; 
					}	
		   	case kVoxWetDry:{
						voxWetDry = newValue; 
						sendChangeMessage (this); 
						break; 
		}	
		   	case kVoxRemove:{
				
						voxRemoveEnabled = newValue; 
			
						sendChangeMessage (this); 
						break; 
		}
			case	kBassMix :{
		
						bassMix = newValue; 
			
						sendChangeMessage (this); 
						break; 
		}
			case	kPitchShift :{
		
						pitchShiftEnabled = newValue; 
			
						sendChangeMessage (this); 
						break; 
		}
	}
	
}

//Displayed near the sliders in the VST host's GUI
const String JucePitcherFilter::getParameterName (int index)
{
    switch (index) 
	{ 
		case kGain0 :		return T("Gain-0"); 
							break; 
		case kPitch0 :	    return T("Pitch-0");
							break; 
		
		case kGain1 :		return T("Gain-1"); 
							break; 
		case kPitch1 :	    return T("Pitch-1");
							break; 
		case kFreq0 :	    return T("Freq-0");
							break; 
		case kFreq1 :	    return T("Freq-1");
							break; 
		case kVoxWetDry :	    return T("Vox Remove Wet/Dry");
							break; 
		case kVoxRemove :	    return T("Vox Remove Enable");
							break; 


		case kGain :		return T("Master Gain");
							break;
		case kBassMix	:	return T("Bass+"); break;
		case kPitchShift :	return T("Pitch Shift Enable"); break;
		case kBassMixFreq : return T("Bass Mix Cutoff Freq"); break;
		default:			return String::empty; break;
	} 
}

const String JucePitcherFilter::getParameterText (int index)
{
    switch (index) 
	{ 
		case kGain0 :		return String (gain0, 2);	break; 
		case kPitch0 :		return String (pitch0, 2);	break; 

		case kGain1 :		return String (gain1, 2);	break; 
		case kPitch1 :		return String (pitch1, 2);	break; 
		case kFreq0 :		return String (freq0, 2);	break; 
		case kFreq1 :		return String (freq1, 2);	break; 

		case kGain :		return String (gain, 2);		break; 
		case kVoxWetDry :		return String (voxWetDry, 2);		break; 
		case kVoxRemove :		return String (voxRemoveEnabled, 2);		break; 
		case kBassMix	:		return String(bassMix, 2); break;
		case kPitchShift :		return String(pitchShiftEnabled, 2); break;
		case kBassMixFreq :		return String(bassMixFreq, 2); break;
		default:			return String::empty;
	} 
}



const String JucePitcherFilter::getInputChannelName (const int channelIndex) const
{
    return String (channelIndex + 1);
}

const String JucePitcherFilter::getOutputChannelName (const int channelIndex) const
{
    return String (channelIndex + 1);
}

bool JucePitcherFilter::isInputChannelStereoPair (int index) const
{
    return true; //Need stereo input for vocal removal
}

bool JucePitcherFilter::isOutputChannelStereoPair (int index) const
{
    return false; // ends up mono due to vocal removing
}

bool JucePitcherFilter::acceptsMidi() const
{
    return false;
}

bool JucePitcherFilter::producesMidi() const
{
    return false;
}

void JucePitcherFilter::prepareToPlay (double sampleRate, int samplesPerBlock)
{
	// do your pre-playback setup stuff here..
}
   
void JucePitcherFilter::releaseResources()
{
	// when playback stops, you can use this as an opportunity to free up any
	// spare memory, etc.
}

void JucePitcherFilter::processBlock (AudioSampleBuffer& buffer,
                                   MidiBuffer& midiMessages)
{
	int numSamples = buffer.getNumSamples(); 
	
	if(voxRemoveEnabled > 0.5){ //Try removing center-mixed content
		
		//Keep the original buffer intact so we can wet/dry mix it
		AudioSampleBuffer voxBuffer = AudioSampleBuffer(1,numSamples); 	
		voxBuffer.copyFrom(0,0,buffer,0,0,numSamples);

		//Make one for the bass mix too
		AudioSampleBuffer voxBassBuffer = AudioSampleBuffer(1,numSamples); 	
		voxBassBuffer.copyFrom(0,0,buffer,0,0,numSamples);
		
		float* bass_in = voxBassBuffer.getSampleData(0, 0);

		//Run Low-Pass filter 
		bass_mix_filter->processSamples(bass_in, numSamples);		
		voxBassBuffer.applyGain(0,0,numSamples,bassMix);


		float* in_left = voxBuffer.getSampleData(0, 0);
		float* in_right = buffer.getSampleData(1,0);
		
		for(int i=0; i < numSamples; i++) //Invert left channel
		{
			*in_left = (-*in_left);			
			in_left++;
		
		}
	voxBuffer.addFrom(0,0,buffer,1,0,numSamples); //add the uninverted right channel to the inverted left channel to cancel out center content
	
	//voxBuffer.applyGain(0,0,numSamples,1-bassMix); //wet/dry bass mix
	voxBuffer.addFrom(0,0,voxBassBuffer,0,0,numSamples); //Add the gained bass signal in too...

	//Mix with original signal according to wet/dry slider...
	voxBuffer.applyGain(0,0,numSamples,voxWetDry); //wetDry==1 means maxgain for this
	buffer.applyGain(0,0,numSamples,(1-voxWetDry));

	buffer.addFrom(0,0,voxBuffer,0,0,numSamples);//Mix in the effect		
	buffer.copyFrom(1,0,buffer,0,0,numSamples); //replace original right channel with the processed sound
	//now the original input buffer has Left and Right channels the same but without vocals/center channel
	}
	
		if(pitchShiftEnabled > 0.5){

		//Split the signal into multiple paths for two bands
		AudioSampleBuffer buffer0 = buffer; //shallow copy
		
		AudioSampleBuffer buffer1 = AudioSampleBuffer(1,numSamples); 
		buffer1.copyFrom(0,0,buffer0,0,0,numSamples);
		
		float* in_0 = buffer0.getSampleData(0, 0);
		
		float* in_1 = buffer1.getSampleData(0, 0);
		

		//Filter the samples
		if(filter0_enabled)
			filter_0->processSamples(in_0, numSamples);		

		if(filter1_enabled)
			filter_1->processSamples(in_1, numSamples);		
		
		
			//Perform the Pitch Shifting...
			processor_0->putSamples(in_0, numSamples);
			processor_0->receiveSamples(in_0, numSamples);

			processor_1->putSamples(in_1, numSamples);
			processor_1->receiveSamples(in_1, numSamples);

			
			//Channel-specific gain
			buffer0.applyGain (0, 0, buffer0.getNumSamples(), gain0); 
			buffer1.applyGain (0, 0, buffer1.getNumSamples(), gain1); 
		

			//Combine into output buffer (buffer == buffer0 already)
			buffer.addFrom(0,0,buffer1,0,0,numSamples);
			buffer.copyFrom(1,0,buffer,1,0,numSamples);
		}

		buffer.applyGain (0, 0, buffer.getNumSamples(), gain); //apply overall gain




    // in case we have more outputs than inputs, we'll clear any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
    {
        buffer.clear (i, 0, buffer.getNumSamples());
    }
}

//============== Methods to handle parameter translation between VST and the application=======

void JucePitcherFilter::setFilter0Freq(float freq) {
	//0->1 goes to 0->1000
	filter_0->makeLowPass(sampleRate, mapFromVST(0,fMax,freq));
}

void JucePitcherFilter::setFilter1Freq(float freq) {
	//0->1 goes to 1000->6000
	filter_1->makeHighPass(sampleRate, mapFromVST(1000,fMax,freq));
}

void JucePitcherFilter::setBassMixFreq(float freq) {
	//0->1 goes to 1000->6000
	bass_mix_filter->makeLowPass(sampleRate, mapFromVST(50,500,freq));
}

float JucePitcherFilter::mapToVST(float min, float max, float val){
//Val is a GUI component value from min->max that needs to be from 0->1
return (val-min)/(max-min);

}

float JucePitcherFilter::mapFromVST(float min, float max, float val){
//Val is from VST and must be value from min->max
return min+(max-min)*val;

}

//Called from the GUI
void JucePitcherFilter::setFilter0Enabled(bool state){
	filter0_enabled = state;
}
void JucePitcherFilter::setFilter1Enabled(bool state){
	filter1_enabled = state;
}




//==============================================================================
AudioProcessorEditor* JucePitcherFilter::createEditor()
{
    return new JucePitcherComponent (this);
}

//==============================================================================
void JucePitcherFilter::getStateInformation (MemoryBlock& destData)
{
    // you can store your parameters as binary data if you want to or if you've got
    // a load of binary to put in there, but if you're not doing anything too heavy,
    // XML is a much cleaner way of doing it - here's an example of how to store your
    // params as XML..

    // create an outer XML element..
    XmlElement xmlState (T("MYPLUGINSETTINGS"));

    // add some attributes to it..
    xmlState.setAttribute (T("pluginVersion"), 1);
    xmlState.setAttribute (T("pitch0"), pitch0);
	xmlState.setAttribute (T("gain0"), gain0);

	xmlState.setAttribute (T("pitch1"), pitch1);
	xmlState.setAttribute (T("gain1"), gain1);

	xmlState.setAttribute (T("gain"), gain);
    // you could also add as many child elements as you need to here..


    // then use this helper function to stuff it into the binary blob and return it..
    copyXmlToBinary (xmlState, destData);
}

void JucePitcherFilter::setStateInformation (const void* data, int sizeInBytes)
{
    // use this helper function to get the XML from this binary blob..
    XmlElement* const xmlState = getXmlFromBinary (data, sizeInBytes);

    if (xmlState != 0)
    {
        // check that it's the right type of xml..
        if (xmlState->hasTagName (T("MYPLUGINSETTINGS")))
        {
            // ok, now pull out our parameters..
            pitch0 = (float) xmlState->getDoubleAttribute (T("pitch0"), pitch0);
			gain0 = (float) xmlState->getDoubleAttribute (T("gain0"), gain0);

			pitch1 = (float) xmlState->getDoubleAttribute (T("pitch1"), pitch1);
			gain1 = (float) xmlState->getDoubleAttribute (T("gain1"), gain1);

			gain = (float) xmlState->getDoubleAttribute (T("gain"), gain);

            sendChangeMessage (this);
        }

        delete xmlState;
    }
}
