/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  3 Dec 2008 3:01:33 am

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.11

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_JUCEPITCHERCOMPONENT_JUCEPITCHERCOMPONENT_F7F570C__
#define __JUCER_HEADER_JUCEPITCHERCOMPONENT_JUCEPITCHERCOMPONENT_F7F570C__

//[Headers]     -- You can add your own extra header files here --

/*  Pehr Hovey http://pehrhovey.net
	
	MAT240A Fall 2008
	University of California Santa Barbara
	JucePitcherComponent.h

	JUCE GUI window for Juce Pitcher VST plugin.

	Koolaid Guy image taken from google image search

*/

#include "juce.h"
#include "JucePitcherFilter.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class JucePitcherComponent  : public AudioProcessorEditor,
                              public ChangeListener,
                              public SliderListener,
                              public ButtonListener
{
public:
    //==============================================================================
    JucePitcherComponent (JucePitcherFilter* const ownerFilter);
    ~JucePitcherComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void changeListenerCallback (void* source);
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void buttonClicked (Button* buttonThatWasClicked);

    // Binary resources:
    static const char* kool_aid_man_waving_jpg;
    static const int kool_aid_man_waving_jpgSize;

    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.

	void updateParametersFromFilter();

	// handy wrapper method to avoid having to cast the filter to a JucePitcherFilter
    // every time we need it..
    JucePitcherFilter* getFilter() const throw()       { return (JucePitcherFilter*) getAudioProcessor(); }
	float mapToVST(float min,float max ,float val);
	float mapFromVST(float min, float max, float val);

    //[/UserVariables]

    //==============================================================================
    Slider* pitchSlider0;
    Slider* gainSlider;
    Label* label;
    Label* label2;
    Label* label4;
    Slider* gainSlider0;
    Label* label3;
    Label* label5;
    Slider* pitchSlider1;
    Label* label6;
    Label* label7;
    Label* label8;
    Label* label9;
    Slider* freqSlider0;
    Label* label10;
    Slider* freqSlider1;
    Label* label11;
    Slider* gainSlider1;
    Label* label12;
    Label* label13;
    Label* label14;
    Label* label15;
    Slider* voxRemoveSlider;
    ToggleButton* voxRemoveToggle;
    Label* label16;
    Label* label17;
    ToggleButton* filter0EnableToggle;
    ToggleButton* filter1EnableToggle;
    Label* label18;
    Label* label19;
    Slider* bassMixSlider;
    ToggleButton* pitchShiftEnable;
    Label* label20;
    Slider* bassMixFreqSlider;
    Label* label21;
    Image* internalCachedImage1;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    JucePitcherComponent (const JucePitcherComponent&);
    const JucePitcherComponent& operator= (const JucePitcherComponent&);
};


#endif   // __JUCER_HEADER_JUCEPITCHERCOMPONENT_JUCEPITCHERCOMPONENT_F7F570C__
