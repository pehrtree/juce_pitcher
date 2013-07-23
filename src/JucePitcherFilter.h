/*  Pehr Hovey http://pehrhovey.net
	
	MAT240A Fall 2008
	University of California Santa Barbara
	JucePitcherFilter.h

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

#ifndef DEMOJUCEPLUGINFILTER_H
#define DEMOJUCEPLUGINFILTER_H
#include "SoundTouch.h"

enum 
 { 
	 // Parameters identifiers 
	 kPitch0, //Pitch bend for band 0
	 kGain0,  //Gain for band 0
	 kGain, //Overall gain
	 kPitch1,
	 kGain1,
	 kFreq1,	
	 kFreq0,
	 kVoxWetDry,
	 kVoxRemove,
	 kBassMix,
	 kPitchShift,
	 kBassMixFreq,

	
	 
	 kNumParams 
 };

//==============================================================================
/**
    A simple plugin filter that just applies a gain change to the audio
    passing through it.

*/
class JucePitcherFilter  : public AudioProcessor,
                        public ChangeBroadcaster
{
public:
    //==============================================================================
    JucePitcherFilter();
    ~JucePitcherFilter();

	
    //==============================================================================
	
	void prepareToPlay (double sampleRate, int samplesPerBlock);
	void releaseResources();

	void processBlock (AudioSampleBuffer& buffer,
                       MidiBuffer& midiMessages);

    //==============================================================================
    AudioProcessorEditor* createEditor();

    //==============================================================================
    const String getName() const;

    int getNumParameters();

    float getParameter (int index);
    void setParameter (int index, float newValue);

    const String getParameterName (int index);
    const String getParameterText (int index);

    const String getInputChannelName (const int channelIndex) const;
    const String getOutputChannelName (const int channelIndex) const;
    bool isInputChannelStereoPair (int index) const;
    bool isOutputChannelStereoPair (int index) const;

    bool acceptsMidi() const;
    bool producesMidi() const;

    //==============================================================================
    int getNumPrograms()                                        { return 0; }
    int getCurrentProgram()                                     { return 0; }
    void setCurrentProgram (int index)                          { }
    const String getProgramName (int index)                     { return String::empty; }
    void changeProgramName (int index, const String& newName)   { }

    //==============================================================================
    void getStateInformation (MemoryBlock& destData);
    void setStateInformation (const void* data, int sizeInBytes);

    //==============================================================================
    juce_UseDebuggingNewOperator

	//This allows the GUI to disable either filter
	void setFilter0Enabled(bool state);
	void setFilter1Enabled(bool state);

private:
	
	float *input, *output;							// Input and Output pointers for call-back


	int  sampleRate;
	//Values from host parameter sliders, store as VST parameter values, 0->1.0
	float gain, gain0,gain1,gain2,gain3;
	float pitch0, pitch1,pitch2,pitch3;
	float freq0, freq1, freq2, freq3;

	float bassMixFreq;	//cuttoff for LP filter
	float voxWetDry; //slider to fade between vox-removed and dry signal
	float voxRemoveEnabled;
	float bassMix; //slider to mix in un-processed low freqs

	IIRFilter * bass_mix_filter;  //Low-pass filter to mix bass into the vox-removed signal

	//--------------------------------------------------------------------------
	float pitchShiftEnabled;  // < 0.5 == false Use Float for easy use as VST param
	
	//Use these flags to decide whether or not to call the filter->process methods
	//Setting the actual filter inactive clears the filter coeffs so use this method instead
	bool filter0_enabled;
	bool filter1_enabled;
	
	

	float fMax; //max frequency a filter could use as a parameter

	void setFilter0Freq(float freq);
	void setFilter1Freq(float freq);
	void setBassMixFreq(float freq);

	
	IIRFilter * filter_0;  //Low-pass filter to create band 0 signal
	IIRFilter * filter_1; // High-pass filter to create band 1 signal


	//The SoundTouch proccessing objects
	soundtouch::SoundTouch * processor_0;
	soundtouch::SoundTouch * processor_1;
	soundtouch::SoundTouch * processor_2;
	soundtouch::SoundTouch * processor_3;

	float mapToVST(float min,float max ,float val);
	float mapFromVST(float min, float max, float val);


	
};


#endif
