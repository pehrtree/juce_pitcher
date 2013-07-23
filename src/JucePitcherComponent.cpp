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

//[Headers] You can add your own extra header files here...
//Author info here to escape the wrath of the Jucer
/*Pehr Hovey http://pehrhovey.net
	
	MAT240A Fall 2008
	University of California Santa Barbara
	JucePitcherComponent.cpp

	JUCE GUI window for Juce Pitcher VST plugin.

	Koolaid Guy image taken from google image search

*/
#include "JucePitcherComponent.h"
//[/Headers]

#include "JucePitcherComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
float fMax=20000; //Max freq of a slider
//[/MiscUserDefs]

//==============================================================================
JucePitcherComponent::JucePitcherComponent (JucePitcherFilter* const ownerFilter)
    : AudioProcessorEditor (ownerFilter),
      pitchSlider0 (0),
      gainSlider (0),
      label (0),
      label2 (0),
      label4 (0),
      gainSlider0 (0),
      label3 (0),
      label5 (0),
      pitchSlider1 (0),
      label6 (0),
      label7 (0),
      label8 (0),
      label9 (0),
      freqSlider0 (0),
      label10 (0),
      freqSlider1 (0),
      label11 (0),
      gainSlider1 (0),
      label12 (0),
      label13 (0),
      label14 (0),
      label15 (0),
      voxRemoveSlider (0),
      voxRemoveToggle (0),
      label16 (0),
      label17 (0),
      filter0EnableToggle (0),
      filter1EnableToggle (0),
      label18 (0),
      label19 (0),
      bassMixSlider (0),
      pitchShiftEnable (0),
      label20 (0),
      bassMixFreqSlider (0),
      label21 (0),
      internalCachedImage1 (0)
{
    addAndMakeVisible (pitchSlider0 = new Slider (T("Pitch Slider 0")));
    pitchSlider0->setRange (-12, 12, 1);
    pitchSlider0->setSliderStyle (Slider::RotaryVerticalDrag);
    pitchSlider0->setTextBoxStyle (Slider::TextBoxBelow, false, 30, 20);
    pitchSlider0->addListener (this);

    addAndMakeVisible (gainSlider = new Slider (T("gain slider")));
    gainSlider->setRange (0, 100, 1);
    gainSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    gainSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 30, 20);
    gainSlider->setColour (Slider::thumbColourId, Colour (0xffffc3bb));
    gainSlider->setColour (Slider::rotarySliderFillColourId, Colour (0x7fff0000));
    gainSlider->setColour (Slider::textBoxHighlightColourId, Colour (0x40ee4e11));
    gainSlider->addListener (this);

    addAndMakeVisible (label = new Label (T("new label"),
                                          T("The Juce Pitcher")));
    label->setFont (Font (T("Arial Black"), 54.1000f, Font::plain));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (Label::textColourId, Colours::red);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label2 = new Label (T("new label"),
                                           T("Pitch")));
    label2->setFont (Font (T("Arial Black"), 26.2000f, Font::plain));
    label2->setJustificationType (Justification::centred);
    label2->setEditable (false, false, false);
    label2->setColour (Label::textColourId, Colours::blue);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label4 = new Label (T("new label"),
                                           T("Master\nGain")));
    label4->setFont (Font (T("Arial Black"), 26.0000f, Font::plain));
    label4->setJustificationType (Justification::centred);
    label4->setEditable (false, false, false);
    label4->setColour (Label::textColourId, Colours::red);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (gainSlider0 = new Slider (T("gain 0 slider")));
    gainSlider0->setRange (0, 100, 1);
    gainSlider0->setSliderStyle (Slider::RotaryVerticalDrag);
    gainSlider0->setTextBoxStyle (Slider::TextBoxBelow, false, 30, 20);
    gainSlider0->addListener (this);

    addAndMakeVisible (label3 = new Label (T("new label"),
                                           T("Gain")));
    label3->setFont (Font (T("Arial Black"), 26.0000f, Font::plain));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (Label::textColourId, Colours::blue);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label5 = new Label (T("new label"),
                                           T("Pehr Hovey / MAT240A")));
    label5->setFont (Font (T("Arial Black"), 45.7000f, Font::plain));
    label5->setJustificationType (Justification::centredLeft);
    label5->setEditable (false, false, false);
    label5->setColour (Label::textColourId, Colours::red);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (pitchSlider1 = new Slider (T("Pitch Slider 1")));
    pitchSlider1->setRange (-12, 12, 1);
    pitchSlider1->setSliderStyle (Slider::RotaryVerticalDrag);
    pitchSlider1->setTextBoxStyle (Slider::TextBoxBelow, false, 30, 20);
    pitchSlider1->setColour (Slider::thumbColourId, Colour (0xfff5bbff));
    pitchSlider1->setColour (Slider::rotarySliderFillColourId, Colour (0x7fe400ff));
    pitchSlider1->setColour (Slider::textBoxHighlightColourId, Colour (0x40bd11ee));
    pitchSlider1->addListener (this);

    addAndMakeVisible (label6 = new Label (T("new label"),
                                           T("Pitch")));
    label6->setFont (Font (T("Arial Black"), 26.2000f, Font::plain));
    label6->setJustificationType (Justification::centred);
    label6->setEditable (false, false, false);
    label6->setColour (Label::textColourId, Colour (0xffd000ff));
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label7 = new Label (T("new label"),
                                           T("Gain")));
    label7->setFont (Font (T("Arial Black"), 26.0000f, Font::plain));
    label7->setJustificationType (Justification::centredLeft);
    label7->setEditable (false, false, false);
    label7->setColour (Label::textColourId, Colour (0xffd000ff));
    label7->setColour (TextEditor::textColourId, Colours::black);
    label7->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label8 = new Label (T("new label"),
                                           T("Band 0")));
    label8->setFont (Font (T("Arial Black"), 26.0000f, Font::plain));
    label8->setJustificationType (Justification::centredLeft);
    label8->setEditable (false, false, false);
    label8->setColour (Label::textColourId, Colours::blue);
    label8->setColour (TextEditor::textColourId, Colours::black);
    label8->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label9 = new Label (T("new label"),
                                           T("Band 1")));
    label9->setFont (Font (T("Arial Black"), 26.0000f, Font::plain));
    label9->setJustificationType (Justification::centredLeft);
    label9->setEditable (false, false, false);
    label9->setColour (Label::backgroundColourId, Colour (0xd000ff));
    label9->setColour (Label::textColourId, Colour (0xffd000ff));
    label9->setColour (TextEditor::textColourId, Colours::black);
    label9->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (freqSlider0 = new Slider (T("freq 0 slider")));
    freqSlider0->setRange (0, 20000, 1);
    freqSlider0->setSliderStyle (Slider::LinearVertical);
    freqSlider0->setTextBoxStyle (Slider::TextBoxBelow, false, 50, 20);
    freqSlider0->addListener (this);

    addAndMakeVisible (label10 = new Label (T("new label"),
                                            T("Freq")));
    label10->setFont (Font (T("Arial Black"), 26.0000f, Font::plain));
    label10->setJustificationType (Justification::centredLeft);
    label10->setEditable (false, false, false);
    label10->setColour (Label::textColourId, Colour (0xffff9700));
    label10->setColour (TextEditor::textColourId, Colours::black);
    label10->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (freqSlider1 = new Slider (T("freq 1 slider")));
    freqSlider1->setRange (0, 20000, 1);
    freqSlider1->setSliderStyle (Slider::LinearVertical);
    freqSlider1->setTextBoxStyle (Slider::TextBoxBelow, false, 50, 20);
    freqSlider1->addListener (this);

    addAndMakeVisible (label11 = new Label (T("new label"),
                                            T("Freq")));
    label11->setFont (Font (T("Arial Black"), 26.0000f, Font::plain));
    label11->setJustificationType (Justification::centredLeft);
    label11->setEditable (false, false, false);
    label11->setColour (Label::textColourId, Colour (0xffffdd00));
    label11->setColour (TextEditor::textColourId, Colours::black);
    label11->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (gainSlider1 = new Slider (T("Gain Slider 1")));
    gainSlider1->setRange (0, 100, 1);
    gainSlider1->setSliderStyle (Slider::RotaryVerticalDrag);
    gainSlider1->setTextBoxStyle (Slider::TextBoxBelow, false, 30, 20);
    gainSlider1->setColour (Slider::thumbColourId, Colour (0xfff5bbff));
    gainSlider1->setColour (Slider::rotarySliderFillColourId, Colour (0x7fe400ff));
    gainSlider1->setColour (Slider::textBoxHighlightColourId, Colour (0x40bd11ee));
    gainSlider1->addListener (this);

    addAndMakeVisible (label12 = new Label (T("new label"),
                                            T("Low-Pass")));
    label12->setFont (Font (T("Arial Black"), 26.0000f, Font::plain));
    label12->setJustificationType (Justification::centredLeft);
    label12->setEditable (false, false, false);
    label12->setColour (Label::textColourId, Colour (0xffffa100));
    label12->setColour (TextEditor::textColourId, Colours::black);
    label12->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label13 = new Label (T("new label"),
                                            T("High-Pass")));
    label13->setFont (Font (T("Arial Black"), 26.0000f, Font::plain));
    label13->setJustificationType (Justification::centredLeft);
    label13->setEditable (false, false, false);
    label13->setColour (Label::textColourId, Colour (0xffffd300));
    label13->setColour (TextEditor::textColourId, Colours::black);
    label13->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label14 = new Label (T("new label"),
                                            T("Dry        Wet")));
    label14->setFont (Font (T("Arial Black"), 26.0000f, Font::plain));
    label14->setJustificationType (Justification::centredLeft);
    label14->setEditable (false, false, false);
    label14->setColour (Label::textColourId, Colour (0xff7af005));
    label14->setColour (TextEditor::textColourId, Colours::black);
    label14->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label15 = new Label (T("new label"),
                                            T("Vocal\nRemoval")));
    label15->setFont (Font (T("Arial Black"), 33.1000f, Font::plain));
    label15->setJustificationType (Justification::centred);
    label15->setEditable (false, false, false);
    label15->setColour (Label::textColourId, Colours::chartreuse);
    label15->setColour (TextEditor::textColourId, Colours::black);
    label15->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (voxRemoveSlider = new Slider (T("vox Remove Slider")));
    voxRemoveSlider->setRange (0, 100, 1);
    voxRemoveSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    voxRemoveSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 30, 20);
    voxRemoveSlider->setColour (Slider::thumbColourId, Colour (0xffc2ffbb));
    voxRemoveSlider->setColour (Slider::rotarySliderFillColourId, Colour (0x7f11ff00));
    voxRemoveSlider->setColour (Slider::textBoxHighlightColourId, Colour (0x4011ee14));
    voxRemoveSlider->addListener (this);

    addAndMakeVisible (voxRemoveToggle = new ToggleButton (T("vox Remove Toggle")));
    voxRemoveToggle->setButtonText (String::empty);
    voxRemoveToggle->addButtonListener (this);

    addAndMakeVisible (label16 = new Label (T("new label"),
                                            T("Enable")));
    label16->setFont (Font (T("Arial Black"), 26.0000f, Font::plain));
    label16->setJustificationType (Justification::centred);
    label16->setEditable (false, false, false);
    label16->setColour (Label::textColourId, Colours::chartreuse);
    label16->setColour (TextEditor::textColourId, Colours::black);
    label16->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label17 = new Label (T("new label"),
                                            T("Pitch Shifting")));
    label17->setFont (Font (T("Arial Black"), 42.7000f, Font::plain));
    label17->setJustificationType (Justification::centred);
    label17->setEditable (false, false, false);
    label17->setColour (Label::textColourId, Colours::red);
    label17->setColour (TextEditor::textColourId, Colours::black);
    label17->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (filter0EnableToggle = new ToggleButton (T("vox Remove Toggle")));
    filter0EnableToggle->setButtonText (String::empty);
    filter0EnableToggle->addButtonListener (this);
    filter0EnableToggle->setToggleState (true, false);

    addAndMakeVisible (filter1EnableToggle = new ToggleButton (T("vox Remove Toggle")));
    filter1EnableToggle->setButtonText (String::empty);
    filter1EnableToggle->addButtonListener (this);
    filter1EnableToggle->setToggleState (true, false);

    addAndMakeVisible (label18 = new Label (T("new label"),
                                            T("http://pehrhovey.net")));
    label18->setFont (Font (T("Arial Black"), 24.2000f, Font::plain));
    label18->setJustificationType (Justification::centredLeft);
    label18->setEditable (false, false, false);
    label18->setColour (Label::textColourId, Colours::blue);
    label18->setColour (TextEditor::textColourId, Colours::black);
    label18->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label19 = new Label (T("new label"),
                                            T("Bass+")));
    label19->setFont (Font (T("Arial Black"), 26.0000f, Font::plain));
    label19->setJustificationType (Justification::centredLeft);
    label19->setEditable (false, false, false);
    label19->setColour (Label::textColourId, Colour (0xff7af005));
    label19->setColour (TextEditor::textColourId, Colours::black);
    label19->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (bassMixSlider = new Slider (T("bass Mix Slider")));
    bassMixSlider->setRange (0, 100, 1);
    bassMixSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    bassMixSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 30, 20);
    bassMixSlider->setColour (Slider::thumbColourId, Colour (0xffc2ffbb));
    bassMixSlider->setColour (Slider::rotarySliderFillColourId, Colour (0x7f11ff00));
    bassMixSlider->setColour (Slider::textBoxHighlightColourId, Colour (0x4011ee14));
    bassMixSlider->addListener (this);

    addAndMakeVisible (pitchShiftEnable = new ToggleButton (T("pitchShiftEnable")));
    pitchShiftEnable->setButtonText (String::empty);
    pitchShiftEnable->addButtonListener (this);

    addAndMakeVisible (label20 = new Label (T("new label"),
                                            T("Enable")));
    label20->setFont (Font (T("Arial Black"), 26.0000f, Font::plain));
    label20->setJustificationType (Justification::centred);
    label20->setEditable (false, false, false);
    label20->setColour (Label::textColourId, Colours::red);
    label20->setColour (Label::outlineColourId, Colours::white);
    label20->setColour (TextEditor::textColourId, Colours::black);
    label20->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (bassMixFreqSlider = new Slider (T("freq 0 slider")));
    bassMixFreqSlider->setRange (50, 500, 10);
    bassMixFreqSlider->setSliderStyle (Slider::LinearVertical);
    bassMixFreqSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 50, 20);
    bassMixFreqSlider->addListener (this);

    addAndMakeVisible (label21 = new Label (T("new label"),
                                            T("Freq")));
    label21->setFont (Font (T("Arial Black"), 26.0000f, Font::plain));
    label21->setJustificationType (Justification::centredLeft);
    label21->setEditable (false, false, false);
    label21->setColour (Label::textColourId, Colour (0xff7af005));
    label21->setColour (TextEditor::textColourId, Colours::black);
    label21->setColour (TextEditor::backgroundColourId, Colour (0x0));

    internalCachedImage1 = ImageCache::getFromMemory (kool_aid_man_waving_jpg, kool_aid_man_waving_jpgSize);

    //[UserPreSize]

	gainSlider->setValue(ownerFilter->getParameter (kGain)*100, false);
	pitchSlider0->setValue((ownerFilter->getParameter (kPitch0)-0.5)*24, false); //to -12 -> +12 range
	gainSlider0->setValue(ownerFilter->getParameter (kGain0)*100, false); //gain for band 0

	pitchSlider1->setValue((ownerFilter->getParameter (kPitch1)-0.5)*24, false); //to -12 -> +12 range
	gainSlider1->setValue(ownerFilter->getParameter (kGain1)*100, false); //gain for band 0

	freqSlider0->setValue(mapFromVST(0,fMax,ownerFilter->getParameter(kFreq0)), false); //filter freq for band 0
	freqSlider1->setValue(mapFromVST(0,fMax,ownerFilter->getParameter(kFreq1)), false); //filter freq for band 1

	bassMixFreqSlider->setValue(mapFromVST(50,500,ownerFilter->getParameter(kBassMixFreq)), false); //filter freq for Bass Mix

	//Initialize vox sliders to disabled
	voxRemoveSlider->setValue(mapFromVST(0,100,ownerFilter->getParameter(kVoxWetDry)),false);
	bassMixSlider->setValue(mapFromVST(0,100,ownerFilter->getParameter(kBassMix)),false);
	voxRemoveSlider->setEnabled(false);
	bassMixSlider->setEnabled(false);
	pitchShiftEnable->setEnabled(true);
    //[/UserPreSize]

    setSize (1024, 500);

    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

JucePitcherComponent::~JucePitcherComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (pitchSlider0);
    deleteAndZero (gainSlider);
    deleteAndZero (label);
    deleteAndZero (label2);
    deleteAndZero (label4);
    deleteAndZero (gainSlider0);
    deleteAndZero (label3);
    deleteAndZero (label5);
    deleteAndZero (pitchSlider1);
    deleteAndZero (label6);
    deleteAndZero (label7);
    deleteAndZero (label8);
    deleteAndZero (label9);
    deleteAndZero (freqSlider0);
    deleteAndZero (label10);
    deleteAndZero (freqSlider1);
    deleteAndZero (label11);
    deleteAndZero (gainSlider1);
    deleteAndZero (label12);
    deleteAndZero (label13);
    deleteAndZero (label14);
    deleteAndZero (label15);
    deleteAndZero (voxRemoveSlider);
    deleteAndZero (voxRemoveToggle);
    deleteAndZero (label16);
    deleteAndZero (label17);
    deleteAndZero (filter0EnableToggle);
    deleteAndZero (filter1EnableToggle);
    deleteAndZero (label18);
    deleteAndZero (label19);
    deleteAndZero (bassMixSlider);
    deleteAndZero (pitchShiftEnable);
    deleteAndZero (label20);
    deleteAndZero (bassMixFreqSlider);
    deleteAndZero (label21);
    ImageCache::release (internalCachedImage1);

    //[Destructor]. You can add your own custom destruction code here..
		getFilter()->removeChangeListener (this);
	deleteAllChildren();
    //[/Destructor]
}

//==============================================================================
void JucePitcherComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    g.setColour (Colours::black);
    g.drawImage (internalCachedImage1,
                 12, 84, 388, 332,
                 0, 0, internalCachedImage1->getWidth(), internalCachedImage1->getHeight());

    g.setColour (Colours::silver);
    g.fillRect (668, 88, 4, 344);

    g.setColour (Colours::silver);
    g.fillRect (508, 44, 4, 388);

    g.setColour (Colours::silver);
    g.fillRect (852, 44, 4, 388);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void JucePitcherComponent::resized()
{
    pitchSlider0->setBounds (528, 104, 72, 96);
    gainSlider->setBounds (872, 104, 72, 96);
    label->setBounds (16, 16, 344, 48);
    label2->setBounds (528, 192, 72, 48);
    label4->setBounds (872, 208, 80, 64);
    gainSlider0->setBounds (528, 272, 72, 96);
    label3->setBounds (536, 376, 56, 24);
    label5->setBounds (16, 400, 360, 40);
    pitchSlider1->setBounds (701, 102, 72, 96);
    label6->setBounds (696, 192, 72, 48);
    label7->setBounds (704, 376, 56, 24);
    label8->setBounds (528, 72, 64, 24);
    label9->setBounds (704, 72, 64, 24);
    freqSlider0->setBounds (600, 80, 72, 288);
    label10->setBounds (608, 376, 56, 23);
    freqSlider1->setBounds (776, 80, 72, 288);
    label11->setBounds (784, 376, 56, 23);
    gainSlider1->setBounds (696, 272, 72, 96);
    label12->setBounds (520, 416, 96, 24);
    label13->setBounds (696, 416, 96, 24);
    label14->setBounds (360, 200, 128, 56);
    label15->setBounds (368, 24, 120, 88);
    voxRemoveSlider->setBounds (384, 144, 72, 96);
    voxRemoveToggle->setBounds (376, 112, 23, 24);
    label16->setBounds (400, 96, 80, 56);
    label17->setBounds (528, 24, 200, 56);
    filter0EnableToggle->setBounds (624, 416, 23, 24);
    filter1EnableToggle->setBounds (800, 416, 23, 24);
    label18->setBounds (16, 432, 360, 24);
    label19->setBounds (328, 320, 128, 56);
    bassMixSlider->setBounds (384, 264, 72, 96);
    pitchShiftEnable->setBounds (744, 40, 23, 24);
    label20->setBounds (768, 24, 80, 56);
    bassMixFreqSlider->setBounds (440, 272, 72, 88);
    label21->setBounds (448, 344, 128, 56);
    //[UserResized] Add your own custom resize handling here..



    //[/UserResized]
}

void JucePitcherComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == pitchSlider0)
    {
        //[UserSliderCode_pitchSlider0] -- add your slider handling code here..
		//translatefrom  to 0-1.0 range
		//float vst_val = (float)(pitchSlider0->getValue()/24)+0.5; //from -12->12 to 0->1
		float vst_val = mapToVST(-12,12, pitchSlider0->getValue());
		getFilter()->setParameterNotifyingHost (kPitch0,vst_val );
        //[/UserSliderCode_pitchSlider0]
    }
    else if (sliderThatWasMoved == gainSlider)
    {
        //[UserSliderCode_gainSlider] -- add your slider handling code here..

         getFilter()->setParameterNotifyingHost (kGain, (float)gainSlider->getValue()/100);

        //[/UserSliderCode_gainSlider]
    }
    else if (sliderThatWasMoved == gainSlider0)
    {
        //[UserSliderCode_gainSlider0] -- add your slider handling code here..
		 getFilter()->setParameterNotifyingHost (kGain0, (float)gainSlider0->getValue()/100);
        //[/UserSliderCode_gainSlider0]
    }
    else if (sliderThatWasMoved == pitchSlider1)
    {
        //[UserSliderCode_pitchSlider1] -- add your slider handling code here..
		//translatefrom  to 0-1.0 range
		//float vst_val = (float)(pitchSlider1->getValue()/24)+0.5; //from -12->12 to 0->1
		float vst_val = mapToVST(-12,12, pitchSlider1->getValue());
		getFilter()->setParameterNotifyingHost (kPitch1, vst_val );
        //[/UserSliderCode_pitchSlider1]
    }
    else if (sliderThatWasMoved == freqSlider0)
    {
        //[UserSliderCode_freqSlider0] -- add your slider handling code here..
		float vst_val = mapToVST(0,fMax, freqSlider0->getValue());
		getFilter()->setParameterNotifyingHost (kFreq0, vst_val );
        //[/UserSliderCode_freqSlider0]
    }
    else if (sliderThatWasMoved == freqSlider1)
    {
        //[UserSliderCode_freqSlider1] -- add your slider handling code here..
		float vst_val = mapToVST(0,fMax, freqSlider1->getValue());
		getFilter()->setParameterNotifyingHost (kFreq1, vst_val );
        //[/UserSliderCode_freqSlider1]
    }
    else if (sliderThatWasMoved == gainSlider1)
    {
        //[UserSliderCode_gainSlider1] -- add your slider handling code here..
		getFilter()->setParameterNotifyingHost (kGain1, (float)gainSlider1->getValue()/100);
        //[/UserSliderCode_gainSlider1]
    }
    else if (sliderThatWasMoved == voxRemoveSlider)
    {
        //[UserSliderCode_voxRemoveSlider] -- add your slider handling code here..
		float vst_val = mapToVST(0,100, voxRemoveSlider->getValue());
		getFilter()->setParameterNotifyingHost (kVoxWetDry, vst_val );
        //[/UserSliderCode_voxRemoveSlider]
    }
    else if (sliderThatWasMoved == bassMixSlider)
    {
        //[UserSliderCode_bassMixSlider] -- add your slider handling code here..
		float vst_val = mapToVST(0,100, bassMixSlider->getValue());
		getFilter()->setParameterNotifyingHost (kBassMix, vst_val );
        //[/UserSliderCode_bassMixSlider]
    }
    else if (sliderThatWasMoved == bassMixFreqSlider)
    {
        //[UserSliderCode_bassMixFreqSlider] -- add your slider handling code here..
		float vst_val = mapToVST(50,500, bassMixFreqSlider->getValue());
		getFilter()->setParameterNotifyingHost (kBassMixFreq, vst_val );
        //[/UserSliderCode_bassMixFreqSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void JucePitcherComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
	bool state = buttonThatWasClicked->getToggleState();
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == voxRemoveToggle)
    {
        //[UserButtonCode_voxRemoveToggle] -- add your button handler code here..
		if(buttonThatWasClicked->getToggleState()){
			getFilter()->setParameterNotifyingHost (kVoxRemove, (float)1.0 );
			voxRemoveSlider->setEnabled(true);
			bassMixSlider->setEnabled(true);
		}else{
			getFilter()->setParameterNotifyingHost (kVoxRemove, (float)0.0 );
			voxRemoveSlider->setEnabled(false);
			bassMixSlider->setEnabled(false);
		}
        //[/UserButtonCode_voxRemoveToggle]
    }
    else if (buttonThatWasClicked == filter0EnableToggle)
    {
        //[UserButtonCode_filter0EnableToggle] -- add your button handler code here..
		getFilter()->setFilter0Enabled(state);
		freqSlider0->setEnabled(state); //enable/disable the frequency slider to reflect filter state

        //[/UserButtonCode_filter0EnableToggle]
    }
    else if (buttonThatWasClicked == filter1EnableToggle)
    {
        //[UserButtonCode_filter1EnableToggle] -- add your button handler code here..
		getFilter()->setFilter1Enabled(state);
		freqSlider1->setEnabled(state); //enable/disable the frequency slider to reflect filter state
        //[/UserButtonCode_filter1EnableToggle]
    }
    else if (buttonThatWasClicked == pitchShiftEnable)
    {
        //[UserButtonCode_pitchShiftEnable] -- add your button handler code here..
		if(buttonThatWasClicked->getToggleState()){
			getFilter()->setParameterNotifyingHost (kPitchShift, (float)1.0 );
			pitchSlider0->setEnabled(true);
			pitchSlider1->setEnabled(true);
			gainSlider0->setEnabled(true);
			gainSlider1->setEnabled(true);
			freqSlider0->setEnabled(true);
			freqSlider1->setEnabled(true);
			filter0EnableToggle->setEnabled(true);
			filter1EnableToggle->setEnabled(true);
		}else{
			getFilter()->setParameterNotifyingHost (kPitchShift, (float)0.0 );
			pitchSlider0->setEnabled(false);
			pitchSlider1->setEnabled(false);
			gainSlider0->setEnabled(false);
			gainSlider1->setEnabled(false);
			freqSlider0->setEnabled(false);
			freqSlider1->setEnabled(false);
			filter0EnableToggle->setEnabled(false);
			filter1EnableToggle->setEnabled(false);
		}
        //[/UserButtonCode_pitchShiftEnable]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void JucePitcherComponent::changeListenerCallback (void* source)
{
    // this is the filter telling us that it's changed, so we'll update our
    // display of the time, midi message, etc.
    updateParametersFromFilter();
}

void JucePitcherComponent::updateParametersFromFilter()
{
    JucePitcherFilter* const filter = getFilter();

    // we use this lock to make sure the processBlock() method isn't writing to the
    // lastMidiMessage variable while we're trying to read it, but be extra-careful to
    // only hold the lock for a minimum amount of time..
    filter->getCallbackLock().enter();

    // take a local copy of the info we need while we've got the lock..
    const float newPitch0 = filter->getParameter (kPitch0);
	const float newGain0 = filter->getParameter (kGain0);

	const float newPitch1 = filter->getParameter (kPitch1);
	const float newGain1 = filter->getParameter (kGain1);

	const float newFreq0 = filter->getParameter (kFreq0);
	const float newFreq1 = filter->getParameter (kFreq1);


	const float newGain = filter->getParameter (kGain);

	const float newVoxWetDry = filter->getParameter(kVoxWetDry);
	const float newVoxRemoveEnabled = filter->getParameter(kVoxRemove);
	const float newBassMix = filter->getParameter(kBassMix);
	const float newBassMixFreq = filter->getParameter(kBassMixFreq);
	const float newPitchShiftEnabled = filter->getParameter(kPitchShift);
    // ..release the lock ASAP
    filter->getCallbackLock().exit();

    // ..and after releasing the lock, we're free to do the time-consuming UI stuff..

    /* Update our slider.

       (note that it's important here to tell the slider not to send a change
       message, because that would cause it to call the filter with a parameter
       change message again, and the values would drift out.
    */

//Values come in the range 0-1.0 from VST host
gainSlider->setValue (newGain*100, false);
pitchSlider0->setValue (mapFromVST(-12,12,newPitch0), false); //-12 to +12
gainSlider0->setValue (newGain0*100, false);

pitchSlider1->setValue (mapFromVST(-12,12,newPitch1), false); //-12 to +12
gainSlider1->setValue (newGain1*100, false);

freqSlider0->setValue (mapFromVST(0, fMax,newFreq0), false);

freqSlider1->setValue (mapFromVST(0, fMax,newFreq1), false);

voxRemoveSlider->setValue (mapFromVST(0, 100,newVoxWetDry), false);

voxRemoveToggle->setToggleState ((newVoxRemoveEnabled > 0.5), false);
voxRemoveToggle->setToggleState ((newPitchShiftEnabled > 0.5), false);

bassMixSlider->setValue (mapFromVST(0, 100,newBassMix), false);
bassMixFreqSlider->setValue (mapFromVST(50, 500,newBassMixFreq), false);

}


//Two convenicence methods to map to (or from) the VST 0-1.0 range for parameters
//All parameters in the plugin are stored as native 0-1.0 so dsp cycles aren't spent converting
float JucePitcherComponent::mapToVST(float min, float max, float val){
//Val is a GUI component value from min->max that needs to be from 0->1
return (val-min)/(max-min);

}

float JucePitcherComponent::mapFromVST(float min, float max, float val){
//Val is from VST and must be value from min->max
return min+(max-min)*val;

}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="JucePitcherComponent" componentName=""
                 parentClasses="public AudioProcessorEditor, public ChangeListener, public SliderListener"
                 constructorParams="JucePitcherFilter* const ownerFilter" variableInitialisers="AudioProcessorEditor (ownerFilter)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="0" initialWidth="1024" initialHeight="500">
  <BACKGROUND backgroundColour="ffffffff">
    <IMAGE pos="12 84 388 332" resource="kool_aid_man_waving_jpg" opacity="1"
           mode="0"/>
    <RECT pos="668 88 4 344" fill="solid: ffc0c0c0" hasStroke="0"/>
    <RECT pos="508 44 4 388" fill="solid: ffc0c0c0" hasStroke="0"/>
    <RECT pos="852 44 4 388" fill="solid: ffc0c0c0" hasStroke="0"/>
  </BACKGROUND>
  <SLIDER name="Pitch Slider 0" id="251e506958de0745" memberName="pitchSlider0"
          virtualName="" explicitFocusOrder="0" pos="528 104 72 96" min="-12"
          max="12" int="1" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="30" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="gain slider" id="bab1b9cbdbfc0370" memberName="gainSlider"
          virtualName="" explicitFocusOrder="0" pos="872 104 72 96" thumbcol="ffffc3bb"
          rotarysliderfill="7fff0000" textboxhighlight="40ee4e11" min="0"
          max="100" int="1" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="30" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="11bd14c0ab9e95d5" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="16 16 344 48" textCol="ffff0000"
         edTextCol="ff000000" edBkgCol="0" labelText="The Juce Pitcher"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Arial Black" fontsize="54.1" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="a15e5a897bccae9e" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="528 192 72 48" textCol="ff0000ff"
         edTextCol="ff000000" edBkgCol="0" labelText="Pitch" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Arial Black"
         fontsize="26.2" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="b6828a358def63c8" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="872 208 80 64" textCol="ffff0000"
         edTextCol="ff000000" edBkgCol="0" labelText="Master&#10;Gain" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Arial Black"
         fontsize="26" bold="0" italic="0" justification="36"/>
  <SLIDER name="gain 0 slider" id="f0d198eecdfb3f8a" memberName="gainSlider0"
          virtualName="" explicitFocusOrder="0" pos="528 272 72 96" min="0"
          max="100" int="1" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="30" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="b8b03695fc07a198" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="536 376 56 24" textCol="ff0000ff"
         edTextCol="ff000000" edBkgCol="0" labelText="Gain" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Arial Black"
         fontsize="26" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="e5c8fe71bb6dc21e" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="16 400 360 40" textCol="ffff0000"
         edTextCol="ff000000" edBkgCol="0" labelText="Pehr Hovey / MAT240A"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Arial Black" fontsize="45.7" bold="0" italic="0" justification="33"/>
  <SLIDER name="Pitch Slider 1" id="ab1c8387821f359c" memberName="pitchSlider1"
          virtualName="" explicitFocusOrder="0" pos="701 102 72 96" thumbcol="fff5bbff"
          rotarysliderfill="7fe400ff" textboxhighlight="40bd11ee" min="-12"
          max="12" int="1" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="30" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="93e4bb8291ec9aee" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="696 192 72 48" textCol="ffd000ff"
         edTextCol="ff000000" edBkgCol="0" labelText="Pitch" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Arial Black"
         fontsize="26.2" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="5e565b17e0ab2e19" memberName="label7" virtualName=""
         explicitFocusOrder="0" pos="704 376 56 24" textCol="ffd000ff"
         edTextCol="ff000000" edBkgCol="0" labelText="Gain" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Arial Black"
         fontsize="26" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="12fd477adaae88e7" memberName="label8" virtualName=""
         explicitFocusOrder="0" pos="528 72 64 24" textCol="ff0000ff"
         edTextCol="ff000000" edBkgCol="0" labelText="Band 0" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Arial Black"
         fontsize="26" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="2a0a985388d05976" memberName="label9" virtualName=""
         explicitFocusOrder="0" pos="704 72 64 24" bkgCol="d000ff" textCol="ffd000ff"
         edTextCol="ff000000" edBkgCol="0" labelText="Band 1" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Arial Black"
         fontsize="26" bold="0" italic="0" justification="33"/>
  <SLIDER name="freq 0 slider" id="318c39b2c6561621" memberName="freqSlider0"
          virtualName="" explicitFocusOrder="0" pos="600 80 72 288" min="0"
          max="20000" int="1" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="4dcb8af25ecb684f" memberName="label10" virtualName=""
         explicitFocusOrder="0" pos="608 376 56 23" textCol="ffff9700"
         edTextCol="ff000000" edBkgCol="0" labelText="Freq" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Arial Black"
         fontsize="26" bold="0" italic="0" justification="33"/>
  <SLIDER name="freq 1 slider" id="37b535decfd3aeb0" memberName="freqSlider1"
          virtualName="" explicitFocusOrder="0" pos="776 80 72 288" min="0"
          max="20000" int="1" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="e905c3a54c17fe2" memberName="label11" virtualName=""
         explicitFocusOrder="0" pos="784 376 56 23" textCol="ffffdd00"
         edTextCol="ff000000" edBkgCol="0" labelText="Freq" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Arial Black"
         fontsize="26" bold="0" italic="0" justification="33"/>
  <SLIDER name="Gain Slider 1" id="10104aa40d87f780" memberName="gainSlider1"
          virtualName="" explicitFocusOrder="0" pos="696 272 72 96" thumbcol="fff5bbff"
          rotarysliderfill="7fe400ff" textboxhighlight="40bd11ee" min="0"
          max="100" int="1" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="30" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="ac139d1e3539bdaf" memberName="label12" virtualName=""
         explicitFocusOrder="0" pos="520 416 96 24" textCol="ffffa100"
         edTextCol="ff000000" edBkgCol="0" labelText="Low-Pass" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Arial Black"
         fontsize="26" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="cc0c850a89e6b128" memberName="label13" virtualName=""
         explicitFocusOrder="0" pos="696 416 96 24" textCol="ffffd300"
         edTextCol="ff000000" edBkgCol="0" labelText="High-Pass" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Arial Black"
         fontsize="26" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="5a1a44b48495ed85" memberName="label14" virtualName=""
         explicitFocusOrder="0" pos="360 200 128 56" textCol="ff7af005"
         edTextCol="ff000000" edBkgCol="0" labelText="Dry        Wet"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Arial Black" fontsize="26" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="274007a6991dffc7" memberName="label15" virtualName=""
         explicitFocusOrder="0" pos="368 24 120 88" textCol="ff7fff00"
         edTextCol="ff000000" edBkgCol="0" labelText="Vocal&#10;Removal" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Arial Black"
         fontsize="33.1" bold="0" italic="0" justification="36"/>
  <SLIDER name="vox Remove Slider" id="fff783a15bbc63a0" memberName="voxRemoveSlider"
          virtualName="" explicitFocusOrder="0" pos="384 144 72 96" thumbcol="ffc2ffbb"
          rotarysliderfill="7f11ff00" textboxhighlight="4011ee14" min="0"
          max="100" int="1" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="30" textBoxHeight="20" skewFactor="1"/>
  <TOGGLEBUTTON name="vox Remove Toggle" id="1ba3b8ceee0ff192" memberName="voxRemoveToggle"
                virtualName="" explicitFocusOrder="0" pos="376 112 23 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <LABEL name="new label" id="16b8e8c74de3f238" memberName="label16" virtualName=""
         explicitFocusOrder="0" pos="400 96 80 56" textCol="ff7fff00"
         edTextCol="ff000000" edBkgCol="0" labelText="Enable" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Arial Black"
         fontsize="26" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="307d58898fed8a60" memberName="label17" virtualName=""
         explicitFocusOrder="0" pos="528 24 200 56" textCol="ffff0000"
         edTextCol="ff000000" edBkgCol="0" labelText="Pitch Shifting"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Arial Black" fontsize="42.7" bold="0" italic="0" justification="36"/>
  <TOGGLEBUTTON name="vox Remove Toggle" id="2bc906ece59a4527" memberName="filter0EnableToggle"
                virtualName="" explicitFocusOrder="0" pos="624 416 23 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="vox Remove Toggle" id="dfa9a4d91e8ed935" memberName="filter1EnableToggle"
                virtualName="" explicitFocusOrder="0" pos="800 416 23 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <LABEL name="new label" id="3f2569fadf5fff7b" memberName="label18" virtualName=""
         explicitFocusOrder="0" pos="16 432 360 24" textCol="ff0000ff"
         edTextCol="ff000000" edBkgCol="0" labelText="http://pehrhovey.net"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Arial Black" fontsize="24.2" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="32857205bf4370f4" memberName="label19" virtualName=""
         explicitFocusOrder="0" pos="328 320 128 56" textCol="ff7af005"
         edTextCol="ff000000" edBkgCol="0" labelText="Bass+" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Arial Black"
         fontsize="26" bold="0" italic="0" justification="33"/>
  <SLIDER name="bass Mix Slider" id="df51e6d77fddb62b" memberName="bassMixSlider"
          virtualName="" explicitFocusOrder="0" pos="384 264 72 96" thumbcol="ffc2ffbb"
          rotarysliderfill="7f11ff00" textboxhighlight="4011ee14" min="0"
          max="100" int="1" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="30" textBoxHeight="20" skewFactor="1"/>
  <TOGGLEBUTTON name="pitchShiftEnable" id="46f8c723165abc77" memberName="pitchShiftEnable"
                virtualName="" explicitFocusOrder="0" pos="744 40 23 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <LABEL name="new label" id="4a8567d01b66fdb9" memberName="label20" virtualName=""
         explicitFocusOrder="0" pos="768 24 80 56" textCol="ffff0000"
         outlineCol="ffffffff" edTextCol="ff000000" edBkgCol="0" labelText="Enable"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Arial Black" fontsize="26" bold="0" italic="0" justification="36"/>
  <SLIDER name="freq 0 slider" id="cdcbe35ecfaf40f9" memberName="bassMixFreqSlider"
          virtualName="" explicitFocusOrder="0" pos="440 272 72 88" min="50"
          max="500" int="10" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="68ac71e8e0419385" memberName="label21" virtualName=""
         explicitFocusOrder="0" pos="448 344 128 56" textCol="ff7af005"
         edTextCol="ff000000" edBkgCol="0" labelText="Freq" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Arial Black"
         fontsize="26" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: kool_aid_man_waving_jpg, 188220, "..\..\gui\kool_aid_man_waving.jpg"
static const unsigned char resource_JucePitcherComponent_kool_aid_man_waving_jpg[] = { 255,216,255,224,0,16,74,70,73,70,0,1,2,1,1,44,1,44,0,0,255,225,29,15,69,120,105,102,0,0,77,77,0,42,0,0,0,8,0,7,1,
18,0,3,0,0,0,1,0,1,0,0,1,26,0,5,0,0,0,1,0,0,0,98,1,27,0,5,0,0,0,1,0,0,0,106,1,40,0,3,0,0,0,1,0,2,0,0,1,49,0,2,0,0,0,28,0,0,0,114,1,50,0,2,0,0,0,20,0,0,0,142,135,105,0,4,0,0,0,1,0,0,0,164,0,0,0,208,0,45,
198,192,0,0,39,16,0,45,198,192,0,0,39,16,65,100,111,98,101,32,80,104,111,116,111,115,104,111,112,32,67,83,50,32,87,105,110,100,111,119,115,0,50,48,48,55,58,48,54,58,50,57,32,49,48,58,50,48,58,51,55,0,
0,0,0,3,160,1,0,3,0,0,0,1,255,255,0,0,160,2,0,4,0,0,0,1,0,0,1,244,160,3,0,4,0,0,0,1,0,0,2,48,0,0,0,0,0,0,0,6,1,3,0,3,0,0,0,1,0,6,0,0,1,26,0,5,0,0,0,1,0,0,1,30,1,27,0,5,0,0,0,1,0,0,1,38,1,40,0,3,0,0,0,
1,0,2,0,0,2,1,0,4,0,0,0,1,0,0,1,46,2,2,0,4,0,0,0,1,0,0,27,217,0,0,0,0,0,0,0,72,0,0,0,1,0,0,0,72,0,0,0,1,255,216,255,224,0,16,74,70,73,70,0,1,2,0,0,72,0,72,0,0,255,237,0,12,65,100,111,98,101,95,67,77,0,
2,255,238,0,14,65,100,111,98,101,0,100,128,0,0,0,1,255,219,0,132,0,12,8,8,8,9,8,12,9,9,12,17,11,10,11,17,21,15,12,12,15,21,24,19,19,21,19,19,24,17,12,12,12,12,12,12,17,12,12,12,12,12,12,12,12,12,12,12,
12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,1,13,11,11,13,14,13,16,14,14,16,20,14,14,14,20,20,14,14,14,14,20,17,12,12,12,12,12,17,17,12,12,12,12,12,12,17,12,12,12,12,12,12,12,12,12,12,12,12,12,
12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,255,192,0,17,8,0,160,0,143,3,1,34,0,2,17,1,3,17,1,255,221,0,4,0,9,255,196,1,63,0,0,1,5,1,1,1,1,1,1,0,0,0,0,0,0,0,3,0,1,2,4,5,6,7,8,9,10,11,1,0,1,5,1,1,1,1,
1,1,0,0,0,0,0,0,0,1,0,2,3,4,5,6,7,8,9,10,11,16,0,1,4,1,3,2,4,2,5,7,6,8,5,3,12,51,1,0,2,17,3,4,33,18,49,5,65,81,97,19,34,113,129,50,6,20,145,161,177,66,35,36,21,82,193,98,51,52,114,130,209,67,7,37,146,
83,240,225,241,99,115,53,22,162,178,131,38,68,147,84,100,69,194,163,116,54,23,210,85,226,101,242,179,132,195,211,117,227,243,70,39,148,164,133,180,149,196,212,228,244,165,181,197,213,229,245,86,102,118,
134,150,166,182,198,214,230,246,55,71,87,103,119,135,151,167,183,199,215,231,247,17,0,2,2,1,2,4,4,3,4,5,6,7,7,6,5,53,1,0,2,17,3,33,49,18,4,65,81,97,113,34,19,5,50,129,145,20,161,177,66,35,193,82,209,240,
51,36,98,225,114,130,146,67,83,21,99,115,52,241,37,6,22,162,178,131,7,38,53,194,210,68,147,84,163,23,100,69,85,54,116,101,226,242,179,132,195,211,117,227,243,70,148,164,133,180,149,196,212,228,244,165,
181,197,213,229,245,86,102,118,134,150,166,182,198,214,230,246,39,55,71,87,103,119,135,151,167,183,199,255,218,0,12,3,1,0,2,17,3,17,0,63,0,245,84,146,73,37,41,37,87,169,229,187,11,6,220,150,52,61,236,
0,48,56,237,110,231,56,86,199,90,255,0,204,169,174,126,235,95,254,141,84,250,185,214,95,213,250,123,174,186,161,78,77,22,191,31,38,182,153,104,177,145,38,189,222,237,143,107,152,255,0,250,8,88,186,235,
186,241,142,70,7,37,122,65,17,39,250,197,213,73,115,127,87,250,151,91,234,93,74,203,222,29,251,40,54,198,146,246,177,173,245,154,253,141,171,19,96,23,189,148,179,117,87,219,115,172,223,123,44,244,253,
63,230,215,67,109,181,211,83,237,181,193,149,214,210,231,184,240,26,209,185,206,41,70,86,47,243,86,76,102,18,225,36,19,253,83,197,254,15,247,153,164,178,250,71,93,171,170,100,101,80,202,95,75,177,125,
50,75,203,76,182,208,231,178,118,19,233,218,221,159,165,165,255,0,205,173,68,129,4,88,68,225,40,30,25,10,58,105,231,234,82,73,36,138,213,36,146,73,41,73,36,146,74,82,139,30,199,180,61,142,14,107,181,14,
6,65,249,133,197,103,245,78,161,119,85,56,182,94,227,137,151,117,216,215,99,144,3,90,202,46,107,107,244,246,183,212,253,102,173,213,228,239,179,244,172,191,254,45,71,234,207,83,203,170,252,12,58,222,42,
195,183,35,33,191,103,107,91,5,142,23,222,215,23,17,185,191,165,110,234,253,47,79,216,163,247,71,21,87,135,213,183,247,28,158,209,201,99,65,199,95,212,225,148,165,255,0,69,238,82,73,37,35,81,255,208,245,
84,146,73,37,48,186,170,174,169,244,220,208,250,173,105,99,216,237,65,107,134,215,52,255,0,89,171,131,233,253,103,27,162,117,60,188,86,93,115,113,243,26,233,55,84,95,117,23,179,117,85,93,109,53,185,239,
200,101,140,217,234,123,126,209,252,199,173,95,243,214,43,95,89,58,207,75,234,119,254,206,200,174,218,219,141,115,216,203,182,11,154,108,110,234,108,253,91,30,223,183,86,250,221,239,199,190,186,253,95,
207,254,103,249,204,124,174,187,214,109,198,163,11,168,6,154,232,123,93,234,92,194,220,146,4,237,222,108,217,187,115,125,190,187,113,217,234,40,50,100,23,99,244,118,59,255,0,130,233,114,188,180,140,76,
100,9,25,43,138,23,193,233,253,28,144,50,227,227,254,235,209,253,83,250,196,203,158,238,155,149,97,117,206,176,156,87,150,0,94,30,195,149,115,46,117,21,178,143,90,183,139,255,0,73,250,47,91,254,49,55,
89,235,247,182,206,169,211,175,109,108,173,184,207,118,57,26,60,186,107,99,43,115,183,57,183,125,173,183,178,202,246,50,191,75,244,149,126,149,114,221,35,31,55,51,168,184,97,86,31,110,164,151,2,106,175,
120,115,119,89,252,173,159,205,215,239,223,254,143,211,247,173,76,235,250,46,59,43,182,234,43,234,182,129,182,187,44,45,163,8,17,244,133,63,79,237,126,239,167,232,87,212,63,240,221,127,205,163,3,41,99,
187,173,127,230,163,62,60,88,185,162,4,120,129,17,151,12,106,227,146,248,180,253,223,240,191,125,211,232,29,83,19,31,12,211,211,90,44,112,45,179,34,219,142,207,90,199,199,218,94,44,39,218,250,31,233,179,
103,248,58,255,0,224,214,174,71,85,206,118,63,218,40,167,211,164,187,107,8,111,173,107,255,0,169,72,179,30,182,127,37,254,181,191,241,107,144,167,39,174,117,33,250,142,46,43,41,105,218,209,70,27,3,36,
237,246,182,206,160,234,247,187,244,141,250,12,77,233,245,22,218,220,124,145,88,182,240,231,87,95,236,246,60,60,50,107,177,219,250,77,205,200,246,127,159,254,141,74,8,225,3,74,238,61,33,175,60,114,148,
228,72,34,86,73,18,253,102,79,235,113,124,174,235,242,250,190,69,110,188,99,101,217,72,250,46,200,201,102,24,31,214,167,9,148,228,127,219,136,52,178,203,9,117,227,26,247,188,77,84,87,145,145,115,220,223,
164,235,125,123,175,217,244,127,193,236,255,0,174,127,131,84,186,118,94,99,28,27,139,123,50,0,211,236,245,220,235,8,35,247,112,250,175,217,186,174,59,255,0,226,115,110,255,0,136,86,113,13,46,203,12,200,
198,30,172,59,213,187,22,91,105,17,238,175,55,167,122,85,228,190,188,143,161,101,180,244,239,253,42,150,158,31,95,251,149,112,209,54,78,155,8,239,253,217,198,50,255,0,210,107,226,94,252,155,63,81,96,181,
132,23,31,70,252,154,0,108,199,186,223,95,211,255,0,183,25,95,252,74,59,186,230,119,77,32,102,125,163,22,176,226,208,252,166,140,140,125,63,53,217,20,179,27,45,158,239,240,223,173,178,191,231,44,88,153,
157,126,250,178,25,93,142,126,27,43,208,99,182,167,210,43,113,99,253,213,215,119,164,235,93,69,142,169,190,179,216,255,0,83,244,191,240,106,223,64,234,23,221,129,127,78,253,159,126,99,114,9,125,151,61,
199,208,152,107,34,219,50,26,214,85,189,181,250,185,23,50,203,111,251,71,171,145,233,239,77,227,143,21,1,246,47,151,45,49,3,50,125,58,80,148,129,249,184,186,207,230,225,254,171,216,224,245,42,242,158,
250,28,5,121,53,53,175,125,97,219,154,88,249,244,178,40,180,71,173,143,102,215,108,179,254,220,101,104,25,191,88,186,78,14,95,217,50,109,45,120,143,85,193,174,44,175,116,108,57,22,180,108,165,174,221,
244,159,252,223,248,93,140,89,31,87,107,15,234,24,149,98,56,221,135,209,240,78,27,243,34,27,115,220,105,210,185,250,84,183,208,245,25,255,0,164,110,162,219,180,186,199,213,204,60,241,110,85,45,244,122,
137,111,178,246,185,204,220,90,61,140,189,173,246,89,91,246,250,111,220,205,254,159,243,127,152,140,184,171,211,87,226,193,1,136,76,12,156,66,36,126,134,224,244,249,191,71,244,158,67,174,100,227,100,117,
108,139,113,44,223,72,176,185,150,86,68,23,22,214,219,118,190,29,237,245,25,249,138,125,11,26,195,214,122,75,36,137,47,185,160,242,43,99,30,214,127,159,179,106,200,125,150,213,150,90,250,11,217,65,34,
202,93,45,238,217,101,187,63,155,119,248,55,174,179,234,75,45,206,204,204,235,25,13,13,112,140,122,154,221,26,209,163,223,91,27,251,181,214,220,127,252,17,86,136,50,200,47,247,174,191,231,59,60,193,142,
30,84,136,234,56,56,56,255,0,127,140,112,127,232,111,94,146,73,43,110,11,255,209,245,84,146,73,37,48,20,210,219,29,107,88,209,107,196,57,224,13,196,14,206,119,210,92,79,215,12,10,207,87,47,201,186,218,
107,201,169,159,103,180,138,220,192,246,146,204,140,102,59,33,244,182,159,209,50,171,235,175,212,247,223,109,215,126,146,191,81,119,42,22,85,93,172,53,218,198,216,199,125,38,56,2,15,197,174,66,81,4,81,
22,201,139,44,177,203,138,36,131,85,99,119,206,178,186,139,48,176,6,15,79,173,142,169,192,206,133,244,130,78,219,47,203,190,198,214,254,171,147,99,135,243,94,157,56,21,255,0,133,251,79,232,22,61,151,221,
116,186,231,155,108,36,151,90,248,47,51,31,78,221,161,238,111,183,217,95,243,84,255,0,128,101,107,209,126,180,97,227,59,165,49,198,182,129,69,181,53,173,0,15,101,175,102,45,172,17,249,187,46,223,255,0,
25,93,75,207,108,198,123,50,31,72,247,22,56,183,227,224,171,115,28,90,11,244,254,232,217,216,248,87,181,40,202,70,55,147,136,153,100,151,170,127,67,250,63,51,173,210,254,177,217,139,102,61,54,48,12,122,
198,209,96,4,150,70,231,139,75,155,244,183,56,189,182,83,183,252,55,249,229,198,234,152,151,117,6,231,90,67,107,233,148,237,197,173,198,13,150,57,251,155,58,127,131,250,111,92,171,240,250,230,125,143,
118,5,204,195,196,166,199,84,30,230,239,125,142,172,236,186,192,54,189,190,147,108,107,235,175,247,214,147,241,28,222,209,248,37,239,78,34,55,82,173,105,112,229,48,100,148,248,56,177,223,167,143,244,103,
127,60,163,234,226,254,171,173,147,214,241,94,231,156,170,49,111,177,255,0,206,6,49,237,159,39,250,110,125,126,223,251,176,207,87,254,13,82,207,234,152,246,83,140,220,65,99,24,55,54,252,107,7,218,106,
108,109,53,90,223,181,54,223,73,206,155,27,179,29,213,255,0,214,214,115,171,219,162,163,151,135,153,117,236,183,31,57,248,172,99,99,211,107,55,2,233,250,110,27,216,215,255,0,109,52,103,145,38,200,141,
255,0,46,140,146,248,126,40,196,74,48,150,82,63,70,225,194,127,193,201,193,15,75,185,87,91,207,168,69,57,182,48,14,26,199,221,0,120,54,171,109,202,173,159,216,98,139,178,122,207,86,7,29,214,91,144,235,
92,202,234,164,216,231,151,61,196,157,219,46,127,216,234,244,234,101,182,251,232,222,178,168,126,67,234,140,150,108,185,132,177,251,126,131,163,139,169,255,0,131,177,171,87,161,229,140,92,218,239,119,
209,162,198,94,96,73,218,205,204,200,129,255,0,133,110,189,232,251,147,59,200,213,139,242,89,62,91,20,32,103,143,16,18,174,40,130,37,243,126,236,163,41,55,250,87,83,191,163,117,54,52,11,113,169,23,122,
57,248,87,63,112,105,113,104,178,237,222,230,186,214,53,236,203,251,67,63,159,165,143,253,37,222,173,62,151,163,174,7,235,115,49,178,58,131,142,35,155,105,203,56,237,46,172,135,3,99,153,151,79,210,111,
231,122,95,102,255,0,192,215,124,166,195,167,20,110,192,58,125,92,206,119,134,67,22,81,30,25,100,143,168,14,241,120,190,164,214,159,172,157,69,145,165,212,22,184,120,145,86,63,254,96,159,252,95,228,236,
187,63,1,199,89,109,204,31,248,29,191,250,33,15,51,34,155,190,180,94,250,156,31,91,131,155,184,112,98,156,110,21,47,171,182,28,111,173,85,129,160,177,206,173,222,97,204,179,255,0,70,178,149,16,144,247,
1,26,131,47,250,77,179,14,46,76,196,244,199,9,255,0,137,127,247,175,162,36,146,74,211,144,255,0,255,210,245,84,146,73,37,41,36,149,78,169,152,252,60,55,217,80,14,189,196,87,75,93,193,123,206,214,238,254,
75,63,156,127,242,16,148,132,98,101,35,66,34,201,240,9,0,146,0,220,232,228,253,104,205,99,159,71,78,99,229,251,134,70,67,65,26,50,179,250,187,95,251,190,174,78,203,25,255,0,133,173,92,198,29,109,200,205,
178,194,36,57,196,143,135,10,89,214,250,45,203,184,56,185,206,180,210,199,187,87,59,211,62,131,173,123,191,57,246,92,50,110,254,218,159,67,111,185,84,51,247,56,73,21,197,82,167,103,150,199,237,96,145,
29,183,243,95,175,245,140,110,137,70,51,172,99,108,187,50,225,69,45,177,254,149,99,232,250,151,95,126,219,61,58,105,107,217,249,138,206,118,45,123,73,100,17,217,195,130,59,57,90,235,95,86,122,111,95,195,
175,27,168,53,251,42,127,171,91,234,112,99,193,141,175,110,231,54,207,101,141,250,126,212,76,188,86,85,67,106,173,187,107,173,161,149,176,118,107,70,198,48,127,85,173,82,74,35,133,135,22,105,251,166,206,
154,83,202,101,83,5,96,117,142,164,112,50,112,235,113,244,234,185,196,221,102,208,243,181,164,15,77,173,113,252,239,240,143,250,108,255,0,6,186,49,151,139,153,110,77,88,238,47,118,37,158,149,206,130,27,
191,95,99,31,244,108,217,179,222,168,229,99,82,247,53,214,214,219,13,103,117,101,205,7,105,253,230,207,209,85,232,70,87,33,99,179,170,37,44,184,184,113,76,70,86,42,95,221,151,168,122,81,56,65,35,193,61,
54,186,155,91,99,121,97,144,145,7,83,247,149,2,132,59,51,102,141,139,122,62,149,99,47,205,167,24,237,125,149,1,145,211,108,120,39,110,200,115,42,123,135,189,213,51,232,122,127,232,255,0,154,253,37,107,
165,179,169,223,212,234,53,85,81,162,161,45,200,220,65,37,195,218,234,52,252,221,223,246,229,127,232,215,43,245,82,167,182,203,250,141,129,206,171,25,190,157,96,71,114,219,46,62,239,162,218,255,0,71,234,
59,247,23,85,142,92,236,167,189,148,190,134,60,111,181,175,218,90,231,104,26,250,246,23,109,118,223,166,169,231,205,60,103,38,60,114,225,140,171,139,251,223,167,193,254,55,169,196,230,99,31,116,154,190,
13,187,3,213,229,110,102,70,39,92,205,124,7,12,107,222,226,201,135,122,119,53,134,183,199,231,51,99,126,159,250,69,14,146,243,127,214,108,39,87,171,157,104,46,104,236,0,115,207,253,6,61,203,107,235,47,
74,103,83,156,156,55,236,207,199,97,104,61,172,103,210,251,61,159,218,254,101,255,0,152,255,0,235,163,253,68,233,120,248,248,214,230,58,44,204,179,218,94,56,99,8,107,189,38,127,109,191,165,127,248,79,
209,254,101,117,171,92,166,88,101,224,136,52,99,188,127,185,255,0,124,201,62,102,49,229,77,143,89,143,183,254,55,87,171,73,36,150,155,142,255,0,255,211,245,84,146,73,37,41,98,117,171,223,70,85,119,228,
212,247,225,208,221,244,154,246,144,110,139,28,255,0,85,174,123,31,236,166,191,209,123,61,63,125,158,244,110,183,245,131,23,164,154,235,176,143,86,233,45,144,242,3,70,155,221,232,178,215,170,85,190,158,
173,67,178,133,245,229,250,204,117,117,62,178,77,109,46,105,246,49,159,152,255,0,223,245,63,75,255,0,129,170,28,254,124,99,28,177,158,43,149,15,78,145,255,0,10,127,247,44,248,177,200,84,200,168,247,255,
0,189,120,108,140,130,252,76,58,73,212,48,88,243,226,231,13,79,249,206,122,208,195,203,187,15,22,220,140,124,103,230,222,192,5,88,181,2,92,247,184,236,100,199,208,169,179,190,235,63,209,172,61,196,183,
28,158,244,179,242,45,190,145,120,99,193,79,39,212,11,185,56,126,170,113,139,212,125,95,207,126,127,77,173,249,14,103,237,10,71,167,212,41,96,44,244,111,4,135,208,250,156,92,234,246,254,247,243,119,127,
59,79,232,209,179,192,21,238,28,141,71,201,114,127,90,112,186,129,13,250,195,245,118,215,99,245,172,74,246,222,43,137,201,199,31,153,101,78,221,86,69,184,251,125,181,216,207,211,83,236,254,114,140,117,
139,137,254,54,197,212,138,186,182,4,89,30,235,241,29,0,255,0,232,53,223,71,251,57,31,245,181,96,139,22,28,96,76,38,4,244,215,118,223,78,232,24,253,43,43,54,250,46,177,237,203,116,250,78,209,172,19,191,
199,244,175,220,239,109,158,207,98,158,75,36,192,212,149,149,127,248,192,232,251,73,171,31,37,238,236,215,6,48,127,156,219,46,255,0,168,92,254,119,214,30,173,215,175,110,14,51,5,21,92,118,138,107,36,151,
15,248,123,143,185,204,107,126,159,243,117,127,33,66,113,78,70,206,158,37,209,199,206,96,194,4,113,250,207,232,194,29,101,47,23,85,255,0,229,44,161,118,21,230,166,97,19,88,201,104,222,219,30,237,174,178,
160,205,205,109,152,245,177,190,247,254,123,236,246,123,22,131,162,79,97,224,135,139,139,94,30,45,120,181,25,109,66,55,113,185,199,220,247,255,0,109,202,110,42,45,205,13,134,206,132,98,99,19,41,255,0,
57,146,165,146,190,94,47,221,136,254,167,201,253,119,174,250,188,208,254,159,131,142,63,155,113,125,247,15,222,139,15,167,91,191,145,187,222,255,0,248,186,150,157,185,23,208,195,132,214,185,206,172,134,
177,205,27,141,140,119,244,118,51,254,27,111,232,173,255,0,138,251,71,243,43,23,234,206,64,24,216,207,39,70,62,202,29,241,159,90,191,243,152,109,93,86,21,59,250,181,150,29,91,85,97,205,31,202,176,250,
123,191,176,204,119,255,0,219,214,44,241,132,228,230,142,35,160,148,142,191,213,245,206,95,244,92,92,231,134,82,145,23,70,71,252,46,36,88,189,23,33,205,7,37,254,139,78,190,155,33,206,254,211,221,250,47,
236,250,118,255,0,198,173,92,92,90,49,107,244,233,108,2,75,156,78,165,206,63,73,239,119,231,57,25,37,179,135,150,195,135,249,184,128,127,123,121,127,140,209,158,89,207,230,63,78,138,73,36,148,203,31,255,
212,244,158,173,155,110,22,19,174,166,177,109,238,115,43,165,142,59,90,95,99,133,108,222,239,221,247,44,222,153,245,183,6,246,186,158,164,91,211,115,105,37,182,213,115,182,176,199,231,215,107,246,55,251,
15,247,255,0,231,199,236,101,98,227,230,99,191,27,37,130,202,108,16,230,153,30,96,135,55,220,199,181,222,230,61,158,246,46,23,235,38,35,112,242,217,138,220,187,179,136,100,185,183,134,61,236,31,224,107,
101,172,101,111,115,157,239,246,217,255,0,5,254,145,69,146,82,143,168,87,15,80,220,229,49,98,205,250,169,92,114,19,113,152,253,208,232,125,100,204,197,235,54,83,135,211,67,50,95,89,38,204,198,186,106,
107,79,210,168,88,223,109,187,191,195,127,219,95,206,122,158,142,13,217,116,116,124,202,223,210,220,109,178,184,25,63,187,145,175,185,155,63,145,254,6,223,204,64,217,212,218,231,244,240,13,47,126,194,
218,88,217,46,47,115,41,13,157,205,221,252,227,63,55,98,222,197,250,158,112,113,78,78,115,247,100,216,90,202,169,105,147,185,230,0,182,223,220,111,210,186,138,63,49,150,126,177,123,21,108,158,177,57,24,
142,26,185,254,237,68,58,21,131,150,198,49,202,92,66,91,67,244,178,113,126,151,253,235,202,245,10,235,171,32,250,46,223,65,37,212,60,112,234,172,62,190,59,191,178,199,250,31,241,180,90,139,137,126,216,
90,125,115,164,131,93,249,21,22,254,168,7,172,26,8,105,97,46,119,232,153,249,174,163,101,151,236,111,248,31,83,254,13,96,49,229,134,15,63,193,51,20,198,76,96,131,100,104,123,179,96,200,37,31,42,5,232,
106,202,112,0,181,208,71,16,87,63,215,62,169,116,254,167,107,178,177,221,246,44,167,153,176,181,179,83,207,239,58,166,237,244,172,119,231,62,175,251,105,88,175,36,132,79,181,24,229,60,78,81,219,69,217,
57,108,121,5,72,2,30,83,254,98,245,22,190,44,202,199,12,238,230,151,147,30,76,244,154,182,186,119,73,195,233,85,185,180,77,151,60,69,183,184,67,136,253,198,55,252,21,123,191,51,252,245,117,247,146,130,
231,74,50,201,57,138,39,68,97,228,240,96,151,28,99,234,232,100,120,171,201,68,161,61,202,68,168,68,148,162,41,150,115,39,71,107,234,205,236,223,126,29,174,216,203,128,123,95,201,107,155,254,16,127,81,
222,155,215,89,137,155,109,25,21,92,225,15,99,134,62,101,127,201,113,110,203,153,255,0,20,247,50,207,252,47,101,171,135,250,191,69,189,67,235,14,47,79,198,127,166,91,190,220,155,118,238,13,174,177,238,
167,111,239,93,99,235,166,207,244,123,255,0,210,255,0,55,215,181,174,171,33,149,229,141,151,209,17,58,203,90,119,54,187,155,236,117,180,111,254,103,38,191,234,127,166,198,85,121,136,75,22,88,103,249,98,
72,60,93,191,70,92,95,237,32,229,243,7,28,167,56,68,241,16,61,64,126,247,242,249,222,185,37,67,7,63,35,50,231,69,109,110,59,26,67,173,105,46,14,124,136,109,78,45,102,237,190,255,0,87,255,0,86,43,235,86,
19,140,226,37,19,113,59,26,175,250,78,100,162,98,104,238,164,146,73,57,15,255,213,245,78,23,153,229,245,42,178,58,219,242,28,73,23,91,234,48,158,237,6,42,103,245,253,6,215,237,94,135,213,91,107,186,94,
99,105,5,214,186,139,69,109,111,37,197,142,218,27,252,173,203,205,198,45,25,121,37,152,239,101,184,217,93,72,99,7,48,203,75,54,54,250,160,143,228,40,57,143,209,14,151,195,56,98,114,76,246,225,255,0,7,
230,151,253,23,103,16,14,175,245,177,183,178,125,42,26,219,108,112,236,43,45,181,159,231,92,202,63,240,85,208,245,92,236,91,241,152,113,45,23,222,210,44,167,211,50,195,32,214,125,91,134,234,233,175,210,
177,255,0,164,119,253,111,214,254,105,101,253,64,164,138,115,242,7,209,125,205,169,191,245,176,93,255,0,163,214,206,79,64,196,190,215,90,215,190,157,230,94,198,109,44,36,253,39,134,90,203,26,199,187,249,
10,57,67,36,176,145,1,25,28,151,197,199,253,111,38,62,106,112,251,199,9,36,71,8,16,133,107,242,247,113,176,49,221,147,149,78,53,110,245,26,199,250,217,22,196,7,16,70,247,6,159,240,126,207,179,82,223,220,
255,0,139,185,112,253,127,17,221,27,173,101,96,53,187,241,91,105,118,61,109,16,234,234,179,109,245,178,168,255,0,180,245,122,236,199,99,63,127,244,107,215,48,240,113,240,171,244,232,110,166,11,222,227,
46,113,26,75,221,254,172,103,248,53,230,255,0,93,75,143,214,108,155,223,197,94,141,85,147,160,108,51,213,175,254,222,118,69,222,149,191,233,170,244,126,159,166,166,228,121,56,198,38,18,169,25,122,164,
123,127,117,169,159,156,158,57,70,120,201,141,30,17,253,126,47,243,159,222,112,171,200,169,192,16,240,1,208,110,211,95,250,135,127,97,200,187,138,176,49,177,114,218,94,230,108,180,232,231,176,150,58,127,
151,183,233,255,0,215,16,93,210,203,15,232,236,17,224,91,31,244,177,157,140,173,79,225,146,58,194,86,15,127,218,187,23,252,101,128,38,25,177,152,202,59,240,159,250,49,245,127,233,70,27,146,146,120,213,
47,177,95,199,168,62,251,127,244,178,118,244,211,99,162,203,116,3,80,1,63,249,250,203,155,255,0,65,48,124,55,55,120,253,172,242,255,0,140,124,173,88,140,254,162,63,247,50,154,39,221,91,39,123,128,35,145,
201,255,0,53,168,14,186,251,154,239,68,122,85,141,13,206,231,251,59,127,244,95,253,186,197,117,248,24,244,180,190,193,12,7,218,201,146,79,159,230,179,250,181,42,185,37,228,0,225,180,126,109,96,113,253,
149,52,57,8,195,89,158,35,219,104,253,141,89,252,107,38,113,88,107,28,14,156,81,60,83,255,0,6,127,247,143,75,254,42,113,75,250,142,102,67,180,56,148,10,203,123,206,75,253,71,127,152,204,26,155,251,139,
210,45,162,155,128,23,86,219,0,224,60,7,71,249,203,207,127,197,197,39,19,59,59,34,227,178,105,169,182,180,234,67,222,235,29,69,90,127,163,166,167,88,255,0,229,222,187,225,157,138,127,62,20,89,65,227,144,
62,95,131,22,34,12,1,142,198,255,0,52,224,0,0,2,0,208,0,157,65,214,214,214,135,19,237,60,21,93,221,70,166,184,180,9,142,233,139,219,105,40,214,253,236,14,130,39,177,82,73,79,255,214,245,85,141,213,126,
172,227,245,12,170,50,107,190,204,43,41,112,121,244,3,97,206,110,231,211,102,219,26,246,182,202,236,177,254,255,0,240,149,190,202,236,252,207,79,101,36,8,7,66,186,19,148,13,196,209,219,237,115,122,23,
71,29,31,13,216,222,177,200,125,150,58,219,44,45,12,27,157,181,190,198,54,118,183,107,63,125,105,36,146,64,0,40,116,84,229,41,200,202,70,229,35,100,169,114,127,92,254,173,230,103,187,246,143,79,123,221,
121,173,184,215,208,3,93,52,131,107,155,101,77,176,127,59,93,151,254,145,175,255,0,1,252,215,233,191,156,223,127,83,165,143,45,123,92,35,186,29,189,88,56,109,199,99,156,255,0,18,19,225,35,25,9,14,140,
115,128,156,76,101,177,124,167,10,214,83,113,198,182,105,190,184,99,233,124,181,236,112,27,93,85,140,179,223,237,255,0,212,138,254,67,157,85,123,200,49,223,77,23,71,245,167,26,142,161,211,114,109,203,
170,145,147,77,97,213,100,191,101,110,97,15,99,90,215,100,188,215,178,167,250,155,44,109,182,122,127,219,92,213,93,23,31,35,166,190,218,234,125,153,21,220,198,53,149,250,118,213,101,111,220,205,216,249,
56,162,218,110,253,45,111,174,207,78,253,244,255,0,134,244,149,168,243,188,16,55,9,31,24,87,253,22,180,190,23,239,229,140,163,150,17,214,140,50,241,92,135,247,163,30,7,62,187,45,207,207,198,196,199,46,
15,186,214,179,216,3,136,4,254,149,251,93,237,217,83,63,75,99,221,244,24,197,124,54,188,44,188,140,27,94,69,212,216,230,147,105,13,115,192,63,161,181,159,70,191,78,234,118,91,87,166,186,204,62,155,211,
186,126,225,131,140,204,114,225,181,238,108,185,228,3,244,29,115,203,236,219,187,243,119,108,79,149,133,133,154,0,203,161,151,237,16,215,56,67,128,253,214,218,205,182,109,254,70,244,35,205,152,228,226,
171,29,191,238,145,155,144,142,76,62,221,240,158,255,0,247,50,121,75,28,214,183,121,18,91,171,124,138,200,198,170,222,163,159,86,45,13,251,69,182,88,11,195,72,218,26,211,189,229,246,253,22,49,187,127,
72,255,0,240,107,172,179,234,199,76,251,105,31,101,46,196,183,26,207,72,2,231,109,202,172,187,107,36,7,63,244,213,122,126,141,111,119,233,63,74,137,210,241,114,58,70,83,241,110,198,52,87,145,83,173,14,
101,86,89,236,167,243,242,114,216,125,26,119,254,147,211,192,170,171,125,15,208,253,163,35,213,181,28,156,231,184,72,132,8,173,248,170,191,244,36,242,191,11,60,182,43,158,88,207,143,229,16,226,227,225,
235,253,206,22,255,0,77,233,244,244,236,97,85,126,235,92,26,114,46,146,77,143,19,175,233,9,119,167,94,247,182,150,126,231,252,34,184,219,33,164,109,4,158,29,220,40,144,65,130,8,35,144,116,41,53,174,118,
141,4,252,21,82,73,54,117,109,128,0,160,40,6,245,93,85,213,210,43,12,222,225,249,206,42,188,221,117,178,214,157,206,61,134,136,248,27,170,176,250,180,23,3,193,219,36,45,134,65,104,33,187,103,183,8,37,
141,13,177,180,181,182,153,120,26,144,136,146,72,33,255,215,245,84,146,73,37,41,82,205,25,174,246,212,61,159,201,229,93,73,37,57,56,253,42,203,14,236,130,90,223,221,238,85,139,113,27,75,38,151,186,177,
160,12,100,75,137,208,13,206,253,229,121,83,234,158,179,113,219,117,45,47,117,15,109,142,96,212,150,141,31,180,126,119,181,219,208,148,168,89,216,110,145,169,167,141,202,201,111,81,181,163,6,255,0,75,
97,125,99,168,54,170,158,49,237,253,46,62,110,55,82,171,168,93,93,180,213,236,163,208,253,70,171,63,194,126,155,214,178,165,162,252,94,169,134,220,39,99,57,216,53,155,159,111,80,193,115,153,107,64,177,
129,173,175,22,214,177,140,170,154,239,170,183,89,70,51,41,245,62,213,109,191,241,146,119,75,250,157,149,156,254,169,145,131,93,249,55,73,177,182,2,250,156,226,3,93,111,217,108,63,102,245,158,214,251,
237,244,119,162,95,148,252,236,150,138,134,218,41,236,222,9,3,107,43,111,245,103,114,50,207,143,65,18,37,197,160,17,32,159,86,242,244,254,234,68,37,212,85,126,240,98,214,237,104,108,204,119,61,207,114,
136,202,109,121,134,49,206,159,0,173,226,116,171,45,247,93,53,179,176,238,86,197,117,182,182,54,182,253,22,136,9,104,5,14,136,37,230,242,176,50,205,23,99,23,93,142,47,97,111,173,65,115,108,99,143,185,
182,84,250,220,207,207,107,61,74,183,126,151,232,127,132,65,175,234,229,89,56,85,226,100,89,86,102,67,27,75,44,203,178,151,25,199,162,199,221,141,65,172,228,189,236,186,191,82,218,217,127,173,235,217,
255,0,106,61,85,214,44,156,222,155,147,94,67,178,240,29,14,126,182,85,216,147,244,157,180,150,183,223,249,223,247,244,12,204,7,166,36,139,179,95,55,248,42,3,136,234,105,231,48,223,213,153,213,78,6,70,
37,214,87,147,147,123,159,212,31,142,106,101,116,214,199,182,191,70,198,100,223,93,190,163,217,137,239,200,101,126,163,61,95,233,87,89,250,14,159,163,58,191,73,237,26,90,28,67,199,245,78,207,106,166,109,
235,86,143,76,99,144,79,36,152,31,31,115,90,175,244,222,156,252,65,54,59,115,200,214,56,146,119,20,189,209,57,122,65,2,181,36,112,250,191,69,38,52,53,175,166,173,244,146,73,21,170,73,36,146,83,255,208,
245,84,146,73,37,41,36,146,73,74,73,36,146,83,86,222,153,129,115,247,217,67,28,227,169,49,18,124,225,26,186,41,168,1,91,26,192,56,0,0,136,146,2,49,4,144,0,189,233,36,147,185,82,73,36,138,20,146,73,36,
165,36,146,73,41,73,36,146,74,82,73,36,146,159,255,217,255,237,35,152,80,104,111,116,111,115,104,111,112,32,51,46,48,0,56,66,73,77,4,4,0,0,0,0,0,7,28,2,0,0,2,0,2,0,56,66,73,77,4,37,0,0,0,0,0,16,70,12,
242,137,38,184,86,218,176,156,1,161,176,167,144,119,56,66,73,77,4,47,0,0,0,0,0,74,0,3,0,0,0,72,0,0,0,72,0,0,0,0,0,0,0,0,0,0,2,222,255,255,2,64,0,0,255,238,255,255,255,238,255,255,3,6,0,0,2,82,0,0,3,103,
5,40,0,0,3,252,255,255,0,1,127,255,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,56,66,73,77,3,233,0,0,0,0,0,120,0,3,0,0,0,72,0,72,0,0,0,0,2,222,2,64,255,238,255,238,3,6,2,82,3,103,5,40,3,252,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,127,255,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,56,66,73,77,3,237,0,0,0,0,0,16,1,44,0,
0,0,1,0,1,1,44,0,0,0,1,0,1,56,66,73,77,4,38,0,0,0,0,0,14,0,0,0,0,0,0,0,0,0,0,63,128,0,0,56,66,73,77,4,13,0,0,0,0,0,4,0,0,0,30,56,66,73,77,4,25,0,0,0,0,0,4,0,0,0,30,56,66,73,77,3,243,0,0,0,0,0,9,0,0,0,
0,0,0,0,0,1,0,56,66,73,77,4,10,0,0,0,0,0,1,0,0,56,66,73,77,39,16,0,0,0,0,0,10,0,1,0,0,0,0,0,0,0,1,56,66,73,77,3,245,0,0,0,0,0,72,0,47,102,102,0,1,0,108,102,102,0,6,0,0,0,0,0,1,0,47,102,102,0,1,0,161,153,
154,0,6,0,0,0,0,0,1,0,50,0,0,0,1,0,90,0,0,0,6,0,0,0,0,0,1,0,53,0,0,0,1,0,45,0,0,0,6,0,0,0,0,0,1,56,66,73,77,3,248,0,0,0,0,0,112,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,3,232,0,0,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,3,232,0,0,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,3,232,0,0,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,3,232,0,0,56,66,73,77,4,8,0,0,0,0,0,41,0,0,0,1,0,0,2,64,0,0,2,64,0,0,0,5,255,
255,252,133,0,0,0,0,14,1,0,0,64,243,0,0,0,85,145,1,0,0,85,118,1,0,56,66,73,77,4,30,0,0,0,0,0,4,0,0,0,0,56,66,73,77,4,26,0,0,0,0,3,91,0,0,0,6,0,0,0,0,0,0,0,0,0,0,2,48,0,0,1,244,0,0,0,19,0,107,0,111,0,111,
0,108,0,95,0,97,0,105,0,100,0,95,0,109,0,97,0,110,0,95,0,119,0,97,0,118,0,105,0,110,0,103,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,244,0,0,2,48,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,0,0,0,1,0,0,0,0,0,0,110,117,108,108,0,0,0,2,0,0,0,6,98,111,117,110,100,115,79,98,106,99,0,0,0,1,0,0,0,0,0,0,82,99,116,49,0,0,0,4,0,0,0,0,84,111,112,32,108,
111,110,103,0,0,0,0,0,0,0,0,76,101,102,116,108,111,110,103,0,0,0,0,0,0,0,0,66,116,111,109,108,111,110,103,0,0,2,48,0,0,0,0,82,103,104,116,108,111,110,103,0,0,1,244,0,0,0,6,115,108,105,99,101,115,86,108,
76,115,0,0,0,1,79,98,106,99,0,0,0,1,0,0,0,0,0,5,115,108,105,99,101,0,0,0,18,0,0,0,7,115,108,105,99,101,73,68,108,111,110,103,0,0,0,0,0,0,0,7,103,114,111,117,112,73,68,108,111,110,103,0,0,0,0,0,0,0,6,111,
114,105,103,105,110,101,110,117,109,0,0,0,12,69,83,108,105,99,101,79,114,105,103,105,110,0,0,0,13,97,117,116,111,71,101,110,101,114,97,116,101,100,0,0,0,0,84,121,112,101,101,110,117,109,0,0,0,10,69,83,
108,105,99,101,84,121,112,101,0,0,0,0,73,109,103,32,0,0,0,6,98,111,117,110,100,115,79,98,106,99,0,0,0,1,0,0,0,0,0,0,82,99,116,49,0,0,0,4,0,0,0,0,84,111,112,32,108,111,110,103,0,0,0,0,0,0,0,0,76,101,102,
116,108,111,110,103,0,0,0,0,0,0,0,0,66,116,111,109,108,111,110,103,0,0,2,48,0,0,0,0,82,103,104,116,108,111,110,103,0,0,1,244,0,0,0,3,117,114,108,84,69,88,84,0,0,0,1,0,0,0,0,0,0,110,117,108,108,84,69,88,
84,0,0,0,1,0,0,0,0,0,0,77,115,103,101,84,69,88,84,0,0,0,1,0,0,0,0,0,6,97,108,116,84,97,103,84,69,88,84,0,0,0,1,0,0,0,0,0,14,99,101,108,108,84,101,120,116,73,115,72,84,77,76,98,111,111,108,1,0,0,0,8,99,
101,108,108,84,101,120,116,84,69,88,84,0,0,0,1,0,0,0,0,0,9,104,111,114,122,65,108,105,103,110,101,110,117,109,0,0,0,15,69,83,108,105,99,101,72,111,114,122,65,108,105,103,110,0,0,0,7,100,101,102,97,117,
108,116,0,0,0,9,118,101,114,116,65,108,105,103,110,101,110,117,109,0,0,0,15,69,83,108,105,99,101,86,101,114,116,65,108,105,103,110,0,0,0,7,100,101,102,97,117,108,116,0,0,0,11,98,103,67,111,108,111,114,
84,121,112,101,101,110,117,109,0,0,0,17,69,83,108,105,99,101,66,71,67,111,108,111,114,84,121,112,101,0,0,0,0,78,111,110,101,0,0,0,9,116,111,112,79,117,116,115,101,116,108,111,110,103,0,0,0,0,0,0,0,10,
108,101,102,116,79,117,116,115,101,116,108,111,110,103,0,0,0,0,0,0,0,12,98,111,116,116,111,109,79,117,116,115,101,116,108,111,110,103,0,0,0,0,0,0,0,11,114,105,103,104,116,79,117,116,115,101,116,108,111,
110,103,0,0,0,0,0,56,66,73,77,4,40,0,0,0,0,0,12,0,0,0,1,63,240,0,0,0,0,0,0,56,66,73,77,4,17,0,0,0,0,0,1,1,0,56,66,73,77,4,20,0,0,0,0,0,4,0,0,0,2,56,66,73,77,4,12,0,0,0,0,27,245,0,0,0,1,0,0,0,143,0,0,0,
160,0,0,1,176,0,1,14,0,0,0,27,217,0,24,0,1,255,216,255,224,0,16,74,70,73,70,0,1,2,0,0,72,0,72,0,0,255,237,0,12,65,100,111,98,101,95,67,77,0,2,255,238,0,14,65,100,111,98,101,0,100,128,0,0,0,1,255,219,0,
132,0,12,8,8,8,9,8,12,9,9,12,17,11,10,11,17,21,15,12,12,15,21,24,19,19,21,19,19,24,17,12,12,12,12,12,12,17,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,1,13,11,11,
13,14,13,16,14,14,16,20,14,14,14,20,20,14,14,14,14,20,17,12,12,12,12,12,17,17,12,12,12,12,12,12,17,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,255,192,0,17,8,0,
160,0,143,3,1,34,0,2,17,1,3,17,1,255,221,0,4,0,9,255,196,1,63,0,0,1,5,1,1,1,1,1,1,0,0,0,0,0,0,0,3,0,1,2,4,5,6,7,8,9,10,11,1,0,1,5,1,1,1,1,1,1,0,0,0,0,0,0,0,1,0,2,3,4,5,6,7,8,9,10,11,16,0,1,4,1,3,2,4,2,
5,7,6,8,5,3,12,51,1,0,2,17,3,4,33,18,49,5,65,81,97,19,34,113,129,50,6,20,145,161,177,66,35,36,21,82,193,98,51,52,114,130,209,67,7,37,146,83,240,225,241,99,115,53,22,162,178,131,38,68,147,84,100,69,194,
163,116,54,23,210,85,226,101,242,179,132,195,211,117,227,243,70,39,148,164,133,180,149,196,212,228,244,165,181,197,213,229,245,86,102,118,134,150,166,182,198,214,230,246,55,71,87,103,119,135,151,167,183,
199,215,231,247,17,0,2,2,1,2,4,4,3,4,5,6,7,7,6,5,53,1,0,2,17,3,33,49,18,4,65,81,97,113,34,19,5,50,129,145,20,161,177,66,35,193,82,209,240,51,36,98,225,114,130,146,67,83,21,99,115,52,241,37,6,22,162,178,
131,7,38,53,194,210,68,147,84,163,23,100,69,85,54,116,101,226,242,179,132,195,211,117,227,243,70,148,164,133,180,149,196,212,228,244,165,181,197,213,229,245,86,102,118,134,150,166,182,198,214,230,246,
39,55,71,87,103,119,135,151,167,183,199,255,218,0,12,3,1,0,2,17,3,17,0,63,0,245,84,146,73,37,41,37,87,169,229,187,11,6,220,150,52,61,236,0,48,56,237,110,231,56,86,199,90,255,0,204,169,174,126,235,95,254,
141,84,250,185,214,95,213,250,123,174,186,161,78,77,22,191,31,38,182,153,104,177,145,38,189,222,237,143,107,152,255,0,250,8,88,186,235,186,241,142,70,7,37,122,65,17,39,250,197,213,73,115,127,87,250,151,
91,234,93,74,203,222,29,251,40,54,198,146,246,177,173,245,154,253,141,171,19,96,23,189,148,179,117,87,219,115,172,223,123,44,244,253,63,230,215,67,109,181,211,83,237,181,193,149,214,210,231,184,240,26,
209,185,206,41,70,86,47,243,86,76,102,18,225,36,19,253,83,197,254,15,247,153,164,178,250,71,93,171,170,100,101,80,202,95,75,177,125,50,75,203,76,182,208,231,178,118,19,233,218,221,159,165,165,255,0,205,
173,68,129,4,88,68,225,40,30,25,10,58,105,231,234,82,73,36,138,213,36,146,73,41,73,36,146,74,82,139,30,199,180,61,142,14,107,181,14,6,65,249,133,197,103,245,78,161,119,85,56,182,94,227,137,151,117,216,
215,99,144,3,90,202,46,107,107,244,246,183,212,253,102,173,213,228,239,179,244,172,191,254,45,71,234,207,83,203,170,252,12,58,222,42,195,183,35,33,191,103,107,91,5,142,23,222,215,23,17,185,191,165,110,
234,253,47,79,216,163,247,71,21,87,135,213,183,247,28,158,209,201,99,65,199,95,212,225,148,165,255,0,69,238,82,73,37,35,81,255,208,245,84,146,73,37,48,186,170,174,169,244,220,208,250,173,105,99,216,237,
65,107,134,215,52,255,0,89,171,131,233,253,103,27,162,117,60,188,86,93,115,113,243,26,233,55,84,95,117,23,179,117,85,93,109,53,185,239,200,101,140,217,234,123,126,209,252,199,173,95,243,214,43,95,89,58,
207,75,234,119,254,206,200,174,218,219,141,115,216,203,182,11,154,108,110,234,108,253,91,30,223,183,86,250,221,239,199,190,186,253,95,207,254,103,249,204,124,174,187,214,109,198,163,11,168,6,154,232,123,
93,234,92,194,220,146,4,237,222,108,217,187,115,125,190,187,113,217,234,40,50,100,23,99,244,118,59,255,0,130,233,114,188,180,140,76,100,9,25,43,138,23,193,233,253,28,144,50,227,227,254,235,209,253,83,
250,196,203,158,238,155,149,97,117,206,176,156,87,150,0,94,30,195,149,115,46,117,21,178,143,90,183,139,255,0,73,250,47,91,254,49,55,89,235,247,182,206,169,211,175,109,108,173,184,207,118,57,26,60,186,
107,99,43,115,183,57,183,125,173,183,178,202,246,50,191,75,244,149,126,149,114,221,35,31,55,51,168,184,97,86,31,110,164,151,2,106,175,120,115,119,89,252,173,159,205,215,239,223,254,143,211,247,173,76,
235,250,46,59,43,182,234,43,234,182,129,182,187,44,45,163,8,17,244,133,63,79,237,126,239,167,232,87,212,63,240,221,127,205,163,3,41,99,187,173,127,230,163,62,60,88,185,162,4,120,129,17,151,12,106,227,
146,248,180,253,223,240,191,125,211,232,29,83,19,31,12,211,211,90,44,112,45,179,34,219,142,207,90,199,199,218,94,44,39,218,250,31,233,179,103,248,58,255,0,224,214,174,71,85,206,118,63,218,40,167,211,164,
187,107,8,111,173,107,255,0,169,72,179,30,182,127,37,254,181,191,241,107,144,167,39,174,117,33,250,142,46,43,41,105,218,209,70,27,3,36,237,246,182,206,160,234,247,187,244,141,250,12,77,233,245,22,218,
220,124,145,88,182,240,231,87,95,236,246,60,60,50,107,177,219,250,77,205,200,246,127,159,254,141,74,8,225,3,74,238,61,33,175,60,114,148,228,72,34,86,73,18,253,102,79,235,113,124,174,235,242,250,190,69,
110,188,99,101,217,72,250,46,200,201,102,24,31,214,167,9,148,228,127,219,136,52,178,203,9,117,227,26,247,188,77,84,87,145,145,115,220,223,164,235,125,123,175,217,244,127,193,236,255,0,174,127,131,84,186,
118,94,99,28,27,139,123,50,0,211,236,245,220,235,8,35,247,112,250,175,217,186,174,59,255,0,226,115,110,255,0,136,86,113,13,46,203,12,200,198,30,172,59,213,187,22,91,105,17,238,175,55,167,122,85,228,190,
188,143,161,101,180,244,239,253,42,150,158,31,95,251,149,112,209,54,78,155,8,239,253,217,198,50,255,0,210,107,226,94,252,155,63,81,96,181,132,23,31,70,252,154,0,108,199,186,223,95,211,255,0,183,25,95,
252,74,59,186,230,119,77,32,102,125,163,22,176,226,208,252,166,140,140,125,63,53,217,20,179,27,45,158,239,240,223,173,178,191,231,44,88,153,157,126,250,178,25,93,142,126,27,43,208,99,182,167,210,43,113,
99,253,213,215,119,164,235,93,69,142,169,190,179,216,255,0,83,244,191,240,106,223,64,234,23,221,129,127,78,253,159,126,99,114,9,125,151,61,199,208,152,107,34,219,50,26,214,85,189,181,250,185,23,50,203,
111,251,71,171,145,233,239,77,227,143,21,1,246,47,151,45,49,3,50,125,58,80,148,129,249,184,186,207,230,225,254,171,216,224,245,42,242,158,250,28,5,121,53,53,175,125,97,219,154,88,249,244,178,40,180,71,
173,143,102,215,108,179,254,220,101,104,25,191,88,186,78,14,95,217,50,109,45,120,143,85,193,174,44,175,116,108,57,22,180,108,165,174,221,244,159,252,223,248,93,140,89,31,87,107,15,234,24,149,98,56,221,
135,209,240,78,27,243,34,27,115,220,105,210,185,250,84,183,208,245,25,255,0,164,110,162,219,180,186,199,213,204,60,241,110,85,45,244,122,137,111,178,246,185,204,220,90,61,140,189,173,246,89,91,246,250,
111,220,205,254,159,243,127,152,140,184,171,211,87,226,193,1,136,76,12,156,66,36,126,134,224,244,249,191,71,244,158,67,174,100,227,100,117,108,139,113,44,223,72,176,185,150,86,68,23,22,214,219,118,190,
29,237,245,25,249,138,125,11,26,195,214,122,75,36,137,47,185,160,242,43,99,30,214,127,159,179,106,200,125,150,213,150,90,250,11,217,65,34,202,93,45,238,217,101,187,63,155,119,248,55,174,179,234,75,45,
206,204,204,235,25,13,13,112,140,122,154,221,26,209,163,223,91,27,251,181,214,220,127,252,17,86,136,50,200,47,247,174,191,231,59,60,193,142,30,84,136,234,56,56,56,255,0,127,140,112,127,232,111,94,146,
73,43,110,11,255,209,245,84,146,73,37,48,20,210,219,29,107,88,209,107,196,57,224,13,196,14,206,119,210,92,79,215,12,10,207,87,47,201,186,218,107,201,169,159,103,180,138,220,192,246,146,204,140,102,59,
33,244,182,159,209,50,171,235,175,212,247,223,109,215,126,146,191,81,119,42,22,85,93,172,53,218,198,216,199,125,38,56,2,15,197,174,66,81,4,81,22,201,139,44,177,203,138,36,131,85,99,119,206,178,186,139,
48,176,6,15,79,173,142,169,192,206,133,244,130,78,219,47,203,190,198,214,254,171,147,99,135,243,94,157,56,21,255,0,133,251,79,232,22,61,151,221,116,186,231,155,108,36,151,90,248,47,51,31,78,221,161,238,
111,183,217,95,243,84,255,0,128,101,107,209,126,180,97,227,59,165,49,198,182,129,69,181,53,173,0,15,101,175,102,45,172,17,249,187,46,223,255,0,25,93,75,207,108,198,123,50,31,72,247,22,56,183,227,224,171,
115,28,90,11,244,254,232,217,216,248,87,181,40,202,70,55,147,136,153,100,151,170,127,67,250,63,51,173,210,254,177,217,139,102,61,54,48,12,122,198,209,96,4,150,70,231,139,75,155,244,183,56,189,182,83,183,
252,55,249,229,198,234,152,151,117,6,231,90,67,107,233,148,237,197,173,198,13,150,57,251,155,58,127,131,250,111,92,171,240,250,230,125,143,118,5,204,195,196,166,199,84,30,230,239,125,142,172,236,186,192,
54,189,190,147,108,107,235,175,247,214,147,241,28,222,209,248,37,239,78,34,55,82,173,105,112,229,48,100,148,248,56,177,223,167,143,244,103,127,60,163,234,226,254,171,173,147,214,241,94,231,156,170,49,
111,177,255,0,206,6,49,237,159,39,250,110,125,126,223,251,176,207,87,254,13,82,207,234,152,246,83,140,220,65,99,24,55,54,252,107,7,218,106,108,109,53,90,223,181,54,223,73,206,155,27,179,29,213,255,0,214,
214,115,171,219,162,163,151,135,153,117,236,183,31,57,248,172,99,99,211,107,55,2,233,250,110,27,216,215,255,0,109,52,103,145,38,200,141,255,0,46,140,146,248,126,40,196,74,48,150,82,63,70,225,194,127,193,
201,193,15,75,185,87,91,207,168,69,57,182,48,14,26,199,221,0,120,54,171,109,202,173,159,216,98,139,178,122,207,86,7,29,214,91,144,235,92,202,234,164,216,231,151,61,196,157,219,46,127,216,234,244,234,101,
182,251,232,222,178,168,126,67,234,140,150,108,185,132,177,251,126,131,163,139,169,255,0,131,177,171,87,161,229,140,92,218,239,119,209,162,198,94,96,73,218,205,204,200,129,255,0,133,110,189,232,251,147,
59,200,213,139,242,89,62,91,20,32,103,143,16,18,174,40,130,37,243,126,236,163,41,55,250,87,83,191,163,117,54,52,11,113,169,23,122,57,248,87,63,112,105,113,104,178,237,222,230,186,214,53,236,203,251,67,
63,159,165,143,253,37,222,173,62,151,163,174,7,235,115,49,178,58,131,142,35,155,105,203,56,237,46,172,135,3,99,153,151,79,210,111,231,122,95,102,255,0,192,215,124,166,195,167,20,110,192,58,125,92,206,
119,134,67,22,81,30,25,100,143,168,14,241,120,190,164,214,159,172,157,69,145,165,212,22,184,120,145,86,63,254,96,159,252,95,228,236,187,63,1,199,89,109,204,31,248,29,191,250,33,15,51,34,155,190,180,94,
250,156,31,91,131,155,184,112,98,156,110,21,47,171,182,28,111,173,85,129,160,177,206,173,222,97,204,179,255,0,70,178,149,16,144,247,1,26,131,47,250,77,179,14,46,76,196,244,199,9,255,0,137,127,247,175,
162,36,146,74,211,144,255,0,255,210,245,84,146,73,37,41,36,149,78,169,152,252,60,55,217,80,14,189,196,87,75,93,193,123,206,214,238,254,75,63,156,127,242,16,148,132,98,101,35,66,34,201,240,9,0,146,0,220,
232,228,253,104,205,99,159,71,78,99,229,251,134,70,67,65,26,50,179,250,187,95,251,190,174,78,203,25,255,0,133,173,92,198,29,109,200,205,178,194,36,57,196,143,135,10,89,214,250,45,203,184,56,185,206,180,
210,199,187,87,59,211,62,131,173,123,191,57,246,92,50,110,254,218,159,67,111,185,84,51,247,56,73,21,197,82,167,103,150,199,237,96,145,29,183,243,95,175,245,140,110,137,70,51,172,99,108,187,50,225,69,45,
177,254,149,99,232,250,151,95,126,219,61,58,105,107,217,249,138,206,118,45,123,73,100,17,217,195,130,59,57,90,235,95,86,122,111,95,195,175,27,168,53,251,42,127,171,91,234,112,99,193,141,175,110,231,54,
207,101,141,250,126,212,76,188,86,85,67,106,173,187,107,173,161,149,176,118,107,70,198,48,127,85,173,82,74,35,133,135,22,105,251,166,206,154,83,202,101,83,5,96,117,142,164,112,50,112,235,113,244,234,185,
196,221,102,208,243,181,164,15,77,173,113,252,239,240,143,250,108,255,0,6,186,49,151,139,153,110,77,88,238,47,118,37,158,149,206,130,27,191,95,99,31,244,108,217,179,222,168,229,99,82,247,53,214,214,219,
13,103,117,101,205,7,105,253,230,207,209,85,232,70,87,33,99,179,170,37,44,184,184,113,76,70,86,42,95,221,151,168,122,81,56,65,35,193,61,54,186,155,91,99,121,97,144,145,7,83,247,149,2,132,59,51,102,141,
139,122,62,149,99,47,205,167,24,237,125,149,1,145,211,108,120,39,110,200,115,42,123,135,189,213,51,232,122,127,232,255,0,154,253,37,107,165,179,169,223,212,234,53,85,81,162,161,45,200,220,65,37,195,218,
234,52,252,221,223,246,229,127,232,215,43,245,82,167,182,203,250,141,129,206,171,25,190,157,96,71,114,219,46,62,239,162,218,255,0,71,234,59,247,23,85,142,92,236,167,189,148,190,134,60,111,181,175,218,
90,231,104,26,250,246,23,109,118,223,166,169,231,205,60,103,38,60,114,225,140,171,139,251,223,167,193,254,55,169,196,230,99,31,116,154,190,13,187,3,213,229,110,102,70,39,92,205,124,7,12,107,222,226,201,
135,122,119,53,134,183,199,231,51,99,126,159,250,69,14,146,243,127,214,108,39,87,171,157,104,46,104,236,0,115,207,253,6,61,203,107,235,47,74,103,83,156,156,55,236,207,199,97,104,61,172,103,210,251,61,
159,218,254,101,255,0,152,255,0,235,163,253,68,233,120,248,248,214,230,58,44,204,179,218,94,56,99,8,107,189,38,127,109,191,165,127,248,79,209,254,101,117,171,92,166,88,101,224,136,52,99,188,127,185,255,
0,124,201,62,102,49,229,77,143,89,143,183,254,55,87,171,73,36,150,155,142,255,0,255,211,245,84,146,73,37,41,98,117,171,223,70,85,119,228,212,247,225,208,221,244,154,246,144,110,139,28,255,0,85,174,123,
31,236,166,191,209,123,61,63,125,158,244,110,183,245,131,23,164,154,235,176,143,86,233,45,144,242,3,70,155,221,232,178,215,170,85,190,158,173,67,178,133,245,229,250,204,117,117,62,178,77,109,46,105,246,
49,159,152,255,0,223,245,63,75,255,0,129,170,28,254,124,99,28,177,158,43,149,15,78,145,255,0,10,127,247,44,248,177,200,84,200,168,247,255,0,189,120,108,140,130,252,76,58,73,212,48,88,243,226,231,13,79,
249,206,122,208,195,203,187,15,22,220,140,124,103,230,222,192,5,88,181,2,92,247,184,236,100,199,208,169,179,190,235,63,209,172,61,196,183,28,158,244,179,242,45,190,145,120,99,193,79,39,212,11,185,56,126,
170,113,139,212,125,95,207,126,127,77,173,249,14,103,237,10,71,167,212,41,96,44,244,111,4,135,208,250,156,92,234,246,254,247,243,119,127,59,79,232,209,179,192,21,238,28,141,71,201,114,127,90,112,186,129,
13,250,195,245,118,215,99,245,172,74,246,222,43,137,201,199,31,153,101,78,221,86,69,184,251,125,181,216,207,211,83,236,254,114,140,117,139,137,254,54,197,212,138,186,182,4,89,30,235,241,29,0,255,0,232,
53,223,71,251,57,31,245,181,96,139,22,28,96,76,38,4,244,215,118,223,78,232,24,253,43,43,54,250,46,177,237,203,116,250,78,209,172,19,191,199,244,175,220,239,109,158,207,98,158,75,36,192,212,149,149,127,
248,192,232,251,73,171,31,37,238,236,215,6,48,127,156,219,46,255,0,168,92,254,119,214,30,173,215,175,110,14,51,5,21,92,118,138,107,36,151,15,248,123,143,185,204,107,126,159,243,117,127,33,66,113,78,70,
206,158,37,209,199,206,96,194,4,113,250,207,232,194,29,101,47,23,85,255,0,229,44,161,118,21,230,166,97,19,88,201,104,222,219,30,237,174,178,160,205,205,109,152,245,177,190,247,254,123,236,246,123,22,131,
162,79,97,224,135,139,139,94,30,45,120,181,25,109,66,55,113,185,199,220,247,255,0,109,202,110,42,45,205,13,134,206,132,98,99,19,41,255,0,57,146,165,146,190,94,47,221,136,254,167,201,253,119,174,250,188,
208,254,159,131,142,63,155,113,125,247,15,222,139,15,167,91,191,145,187,222,255,0,248,186,150,157,185,23,208,195,132,214,185,206,172,134,177,205,27,141,140,119,244,118,51,254,27,111,232,173,255,0,138,
251,71,243,43,23,234,206,64,24,216,207,39,70,62,202,29,241,159,90,191,243,152,109,93,86,21,59,250,181,150,29,91,85,97,205,31,202,176,250,123,191,176,204,119,255,0,219,214,44,241,132,228,230,142,35,160,
148,142,191,213,245,206,95,244,92,92,231,134,82,145,23,70,71,252,46,36,88,189,23,33,205,7,37,254,139,78,190,155,33,206,254,211,221,250,47,236,250,118,255,0,198,173,92,92,90,49,107,244,233,108,2,75,156,
78,165,206,63,73,239,119,231,57,25,37,179,135,150,195,135,249,184,128,127,123,121,127,140,209,158,89,207,230,63,78,138,73,36,148,203,31,255,212,244,158,173,155,110,22,19,174,166,177,109,238,115,43,165,
142,59,90,95,99,133,108,222,239,221,247,44,222,153,245,183,6,246,186,158,164,91,211,115,105,37,182,213,115,182,176,199,231,215,107,246,55,251,15,247,255,0,231,199,236,101,98,227,230,99,191,27,37,130,202,
108,16,230,153,30,96,135,55,220,199,181,222,230,61,158,246,46,23,235,38,35,112,242,217,138,220,187,179,136,100,185,183,134,61,236,31,224,107,101,172,101,111,115,157,239,246,217,255,0,5,254,145,69,146,
82,143,168,87,15,80,220,229,49,98,205,250,169,92,114,19,113,152,253,208,232,125,100,204,197,235,54,83,135,211,67,50,95,89,38,204,198,186,106,107,79,210,168,88,223,109,187,191,195,127,219,95,206,122,158,
142,13,217,116,116,124,202,223,210,220,109,178,184,25,63,187,145,175,185,155,63,145,254,6,223,204,64,217,212,218,231,244,240,13,47,126,194,218,88,217,46,47,115,41,13,157,205,221,252,227,63,55,98,222,197,
250,158,112,113,78,78,115,247,100,216,90,202,169,105,147,185,230,0,182,223,220,111,210,186,138,63,49,150,126,177,123,21,108,158,177,57,24,142,26,185,254,237,68,58,21,131,150,198,49,202,92,66,91,67,244,
178,113,126,151,253,235,202,245,10,235,171,32,250,46,223,65,37,212,60,112,234,172,62,190,59,191,178,199,250,31,241,180,90,139,137,126,216,90,125,115,164,131,93,249,21,22,254,168,7,172,26,8,105,97,46,119,
232,153,249,174,163,101,151,236,111,248,31,83,254,13,96,49,229,134,15,63,193,51,20,198,76,96,131,100,104,123,179,96,200,37,31,42,5,232,106,202,112,0,181,208,71,16,87,63,215,62,169,116,254,167,107,178,
177,221,246,44,167,153,176,181,179,83,207,239,58,166,237,244,172,119,231,62,175,251,105,88,175,36,132,79,181,24,229,60,78,81,219,69,217,57,108,121,5,72,2,30,83,254,98,245,22,190,44,202,199,12,238,230,
151,147,30,76,244,154,182,186,119,73,195,233,85,185,180,77,151,60,69,183,184,67,136,253,198,55,252,21,123,191,51,252,245,117,247,146,130,231,74,50,201,57,138,39,68,97,228,240,96,151,28,99,234,232,100,
120,171,201,68,161,61,202,68,168,68,148,162,41,150,115,39,71,107,234,205,236,223,126,29,174,216,203,128,123,95,201,107,155,254,16,127,81,222,155,215,89,137,155,109,25,21,92,225,15,99,134,62,101,127,201,
113,110,203,153,255,0,20,247,50,207,252,47,101,171,135,250,191,69,189,67,235,14,47,79,198,127,166,91,190,220,155,118,238,13,174,177,238,167,111,239,93,99,235,166,207,244,123,255,0,210,255,0,55,215,181,
174,171,33,149,229,141,151,209,17,58,203,90,119,54,187,155,236,117,180,111,254,103,38,191,234,127,166,198,85,121,136,75,22,88,103,249,98,72,60,93,191,70,92,95,237,32,229,243,7,28,167,56,68,241,16,61,64,
126,247,242,249,222,185,37,67,7,63,35,50,231,69,109,110,59,26,67,173,105,46,14,124,136,109,78,45,102,237,190,255,0,87,255,0,86,43,235,86,19,140,226,37,19,113,59,26,175,250,78,100,162,98,104,238,164,146,
73,57,15,255,213,245,78,23,153,229,245,42,178,58,219,242,28,73,23,91,234,48,158,237,6,42,103,245,253,6,215,237,94,135,213,91,107,186,94,99,105,5,214,186,139,69,109,111,37,197,142,218,27,252,173,203,205,
198,45,25,121,37,152,239,101,184,217,93,72,99,7,48,203,75,54,54,250,160,143,228,40,57,143,209,14,151,195,56,98,114,76,246,225,255,0,7,230,151,253,23,103,16,14,175,245,177,183,178,125,42,26,219,108,112,
236,43,45,181,159,231,92,202,63,240,85,208,245,92,236,91,241,152,113,45,23,222,210,44,167,211,50,195,32,214,125,91,134,234,233,175,210,177,255,0,164,119,253,111,214,254,105,101,253,64,164,138,115,242,
7,209,125,205,169,191,245,176,93,255,0,163,214,206,79,64,196,190,215,90,215,190,157,230,94,198,109,44,36,253,39,134,90,203,26,199,187,249,10,57,67,36,176,145,1,25,28,151,197,199,253,111,38,62,106,112,
251,199,9,36,71,8,16,133,107,242,247,113,176,49,221,147,149,78,53,110,245,26,199,250,217,22,196,7,16,70,247,6,159,240,126,207,179,82,223,220,255,0,139,185,112,253,127,17,221,27,173,101,96,53,187,241,91,
105,118,61,109,16,234,234,179,109,245,178,168,255,0,180,245,122,236,199,99,63,127,244,107,215,48,240,113,240,171,244,232,110,166,11,222,227,46,113,26,75,221,254,172,103,248,53,230,255,0,93,75,143,214,
108,155,223,197,94,141,85,147,160,108,51,213,175,254,222,118,69,222,149,191,233,170,244,126,159,166,166,228,121,56,198,38,18,169,25,122,164,123,127,117,169,159,156,158,57,70,120,201,141,30,17,253,126,
47,243,159,222,112,171,200,169,192,16,240,1,208,110,211,95,250,135,127,97,200,187,138,176,49,177,114,218,94,230,108,180,232,231,176,150,58,127,151,183,233,255,0,215,16,93,210,203,15,232,236,17,224,91,
31,244,177,157,140,173,79,225,146,58,194,86,15,127,218,187,23,252,101,128,38,25,177,152,202,59,240,159,250,49,245,127,233,70,27,146,146,120,213,47,177,95,199,168,62,251,127,244,178,118,244,211,99,162,
203,116,3,80,1,63,249,250,203,155,255,0,65,48,124,55,55,120,253,172,242,255,0,140,124,173,88,140,254,162,63,247,50,154,39,221,91,39,123,128,35,145,201,255,0,53,168,14,186,251,154,239,68,122,85,141,13,
206,231,251,59,127,244,95,253,186,197,117,248,24,244,180,190,193,12,7,218,201,146,79,159,230,179,250,181,42,185,37,228,0,225,180,126,109,96,113,253,149,52,57,8,195,89,158,35,219,104,253,141,89,252,107,
38,113,88,107,28,14,156,81,60,83,255,0,6,127,247,143,75,254,42,113,75,250,142,102,67,180,56,148,10,203,123,206,75,253,71,127,152,204,26,155,251,139,210,45,162,155,128,23,86,219,0,224,60,7,71,249,203,207,
127,197,197,39,19,59,59,34,227,178,105,169,182,180,234,67,222,235,29,69,90,127,163,166,167,88,255,0,229,222,187,225,157,138,127,62,20,89,65,227,144,62,95,131,22,34,12,1,142,198,255,0,52,224,0,0,2,0,208,
0,157,65,214,214,214,135,19,237,60,21,93,221,70,166,184,180,9,142,233,139,219,105,40,214,253,236,14,130,39,177,82,73,79,255,214,245,85,141,213,126,172,227,245,12,170,50,107,190,204,43,41,112,121,244,3,
97,206,110,231,211,102,219,26,246,182,202,236,177,254,255,0,240,149,190,202,236,252,207,79,101,36,8,7,66,186,19,148,13,196,209,219,237,115,122,23,71,29,31,13,216,222,177,200,125,150,58,219,44,45,12,27,
157,181,190,198,54,118,183,107,63,125,105,36,146,64,0,40,116,84,229,41,200,202,70,229,35,100,169,114,127,92,254,173,230,103,187,246,143,79,123,221,121,173,184,215,208,3,93,52,131,107,155,101,77,176,127,
59,93,151,254,145,175,255,0,1,252,215,233,191,156,223,127,83,165,143,45,123,92,35,186,29,189,88,56,109,199,99,156,255,0,18,19,225,35,25,9,14,140,115,128,156,76,101,177,124,167,10,214,83,113,198,182,105,
190,184,99,233,124,181,236,112,27,93,85,140,179,223,237,255,0,212,138,254,67,157,85,123,200,49,223,77,23,71,245,167,26,142,161,211,114,109,203,170,145,147,77,97,213,100,191,101,110,97,15,99,90,215,100,
188,215,178,167,250,155,44,109,182,122,127,219,92,213,93,23,31,35,166,190,218,234,125,153,21,220,198,53,149,250,118,213,101,111,220,205,216,249,56,162,218,110,253,45,111,174,207,78,253,244,255,0,134,244,
149,168,243,188,16,55,9,31,24,87,253,22,180,190,23,239,229,140,163,150,17,214,140,50,241,92,135,247,163,30,7,62,187,45,207,207,198,196,199,46,15,186,214,179,216,3,136,4,254,149,251,93,237,217,83,63,75,
99,221,244,24,197,124,54,188,44,188,140,27,94,69,212,216,230,147,105,13,115,192,63,161,181,159,70,191,78,234,118,91,87,166,186,204,62,155,211,186,126,225,131,140,204,114,225,181,238,108,185,228,3,244,
29,115,203,236,219,187,243,119,108,79,149,133,133,154,0,203,161,151,237,16,215,56,67,128,253,214,218,205,182,109,254,70,244,35,205,152,228,226,171,29,191,238,145,155,144,142,76,62,221,240,158,255,0,247,
50,121,75,28,214,183,121,18,91,171,124,138,200,198,170,222,163,159,86,45,13,251,69,182,88,11,195,72,218,26,211,189,229,246,253,22,49,187,127,72,255,0,240,107,172,179,234,199,76,251,105,31,101,46,196,183,
26,207,72,2,231,109,202,172,187,107,36,7,63,244,213,122,126,141,111,119,233,63,74,137,210,241,114,58,70,83,241,110,198,52,87,145,83,173,14,101,86,89,236,167,243,242,114,216,125,26,119,254,147,211,192,
170,171,125,15,208,253,163,35,213,181,28,156,231,184,72,132,8,173,248,170,191,244,36,242,191,11,60,182,43,158,88,207,143,229,16,226,227,225,235,253,206,22,255,0,77,233,244,244,236,97,85,126,235,92,26,
114,46,146,77,143,19,175,233,9,119,167,94,247,182,150,126,231,252,34,184,219,33,164,109,4,158,29,220,40,144,65,130,8,35,144,116,41,53,174,118,141,4,252,21,82,73,54,117,109,128,0,160,40,6,245,93,85,213,
210,43,12,222,225,249,206,42,188,221,117,178,214,157,206,61,134,136,248,27,170,176,250,180,23,3,193,219,36,45,134,65,104,33,187,103,183,8,37,141,13,177,180,181,182,153,120,26,144,136,146,72,33,255,215,
245,84,146,73,37,41,82,205,25,174,246,212,61,159,201,229,93,73,37,57,56,253,42,203,14,236,130,90,223,221,238,85,139,113,27,75,38,151,186,177,160,12,100,75,137,208,13,206,253,229,121,83,234,158,179,113,
219,117,45,47,117,15,109,142,96,212,150,141,31,180,126,119,181,219,208,148,168,89,216,110,145,169,167,141,202,201,111,81,181,163,6,255,0,75,97,125,99,168,54,170,158,49,237,253,46,62,110,55,82,171,168,
93,93,180,213,236,163,208,253,70,171,63,194,126,155,214,178,165,162,252,94,169,134,220,39,99,57,216,53,155,159,111,80,193,115,153,107,64,177,129,173,175,22,214,177,140,170,154,239,170,183,89,70,51,41,
245,62,213,109,191,241,146,119,75,250,157,149,156,254,169,145,131,93,249,55,73,177,182,2,250,156,226,3,93,111,217,108,63,102,245,158,214,251,237,244,119,162,95,148,252,236,150,138,134,218,41,236,222,9,
3,107,43,111,245,103,114,50,207,143,65,18,37,197,160,17,32,159,86,242,244,254,234,68,37,212,85,126,240,98,214,237,104,108,204,119,61,207,114,136,202,109,121,134,49,206,159,0,173,226,116,171,45,247,93,
53,179,176,238,86,197,117,182,182,54,182,253,22,136,9,104,5,14,136,37,230,242,176,50,205,23,99,23,93,142,47,97,111,173,65,115,108,99,143,185,182,84,250,220,207,207,107,61,74,183,126,151,232,127,132,65,
175,234,229,89,56,85,226,100,89,86,102,67,27,75,44,203,178,151,25,199,162,199,221,141,65,172,228,189,236,186,191,82,218,217,127,173,235,217,255,0,106,61,85,214,44,156,222,155,147,94,67,178,240,29,14,126,
182,85,216,147,244,157,180,150,183,223,249,223,247,244,12,204,7,166,36,139,179,95,55,248,42,3,136,234,105,231,48,223,213,153,213,78,6,70,37,214,87,147,147,123,159,212,31,142,106,101,116,214,199,182,191,
70,198,100,223,93,190,163,217,137,239,200,101,126,163,61,95,233,87,89,250,14,159,163,58,191,73,237,26,90,28,67,199,245,78,207,106,166,109,235,86,143,76,99,144,79,36,152,31,31,115,90,175,244,222,156,252,
65,54,59,115,200,214,56,146,119,20,189,209,57,122,65,2,181,36,112,250,191,69,38,52,53,175,166,173,244,146,73,21,170,73,36,146,83,255,208,245,84,146,73,37,41,36,146,73,74,73,36,146,83,86,222,153,129,115,
247,217,67,28,227,169,49,18,124,225,26,186,41,168,1,91,26,192,56,0,0,136,146,2,49,4,144,0,189,233,36,147,185,82,73,36,138,20,146,73,36,165,36,146,73,41,73,36,146,74,82,73,36,146,159,255,217,0,56,66,73,
77,4,33,0,0,0,0,0,85,0,0,0,1,1,0,0,0,15,0,65,0,100,0,111,0,98,0,101,0,32,0,80,0,104,0,111,0,116,0,111,0,115,0,104,0,111,0,112,0,0,0,19,0,65,0,100,0,111,0,98,0,101,0,32,0,80,0,104,0,111,0,116,0,111,0,115,
0,104,0,111,0,112,0,32,0,67,0,83,0,50,0,0,0,1,0,56,66,73,77,4,1,0,0,0,0,0,182,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,1,0,2,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,57,39,184,1,10,50,24,1,57,39,184,1,10,50,24,1,57,39,184,1,10,50,24,0,2,1,57,39,184,255,241,160,90,1,57,39,184,255,241,160,90,1,57,39,184,255,241,160,90,0,2,0,0,
39,35,255,241,160,90,0,0,39,35,255,241,160,90,0,0,39,35,255,241,160,90,0,2,0,0,39,35,1,10,50,24,0,0,39,35,1,10,50,24,0,0,39,35,1,10,50,24,56,66,73,77,4,6,0,0,0,0,0,7,0,8,0,0,0,1,1,0,255,225,58,154,104,
116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,109,47,120,97,112,47,49,46,48,47,0,60,63,120,112,97,99,107,101,116,32,98,101,103,105,110,61,34,239,187,191,34,32,105,100,61,34,87,53,77,48,77,
112,67,101,104,105,72,122,114,101,83,122,78,84,99,122,107,99,57,100,34,63,62,10,60,120,58,120,109,112,109,101,116,97,32,120,109,108,110,115,58,120,61,34,97,100,111,98,101,58,110,115,58,109,101,116,97,
47,34,32,120,58,120,109,112,116,107,61,34,51,46,49,46,49,45,49,49,50,34,62,10,32,32,32,60,114,100,102,58,82,68,70,32,120,109,108,110,115,58,114,100,102,61,34,104,116,116,112,58,47,47,119,119,119,46,119,
51,46,111,114,103,47,49,57,57,57,47,48,50,47,50,50,45,114,100,102,45,115,121,110,116,97,120,45,110,115,35,34,62,10,32,32,32,32,32,32,60,114,100,102,58,68,101,115,99,114,105,112,116,105,111,110,32,114,
100,102,58,97,98,111,117,116,61,34,34,10,32,32,32,32,32,32,32,32,32,32,32,32,120,109,108,110,115,58,101,120,105,102,61,34,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,109,47,101,120,
105,102,47,49,46,48,47,34,62,10,32,32,32,32,32,32,32,32,32,60,101,120,105,102,58,67,111,108,111,114,83,112,97,99,101,62,45,49,60,47,101,120,105,102,58,67,111,108,111,114,83,112,97,99,101,62,10,32,32,32,
32,32,32,32,32,32,60,101,120,105,102,58,80,105,120,101,108,88,68,105,109,101,110,115,105,111,110,62,53,48,48,60,47,101,120,105,102,58,80,105,120,101,108,88,68,105,109,101,110,115,105,111,110,62,10,32,
32,32,32,32,32,32,32,32,60,101,120,105,102,58,80,105,120,101,108,89,68,105,109,101,110,115,105,111,110,62,53,54,48,60,47,101,120,105,102,58,80,105,120,101,108,89,68,105,109,101,110,115,105,111,110,62,
10,32,32,32,32,32,32,32,32,32,60,101,120,105,102,58,78,97,116,105,118,101,68,105,103,101,115,116,62,51,54,56,54,52,44,52,48,57,54,48,44,52,48,57,54,49,44,51,55,49,50,49,44,51,55,49,50,50,44,52,48,57,54,
50,44,52,48,57,54,51,44,51,55,53,49,48,44,52,48,57,54,52,44,51,54,56,54,55,44,51,54,56,54,56,44,51,51,52,51,52,44,51,51,52,51,55,44,51,52,56,53,48,44,51,52,56,53,50,44,51,52,56,53,53,44,51,52,56,53,54,
44,51,55,51,55,55,44,51,55,51,55,56,44,51,55,51,55,57,44,51,55,51,56,48,44,51,55,51,56,49,44,51,55,51,56,50,44,51,55,51,56,51,44,51,55,51,56,52,44,51,55,51,56,53,44,51,55,51,56,54,44,51,55,51,57,54,44,
52,49,52,56,51,44,52,49,52,56,52,44,52,49,52,56,54,44,52,49,52,56,55,44,52,49,52,56,56,44,52,49,52,57,50,44,52,49,52,57,51,44,52,49,52,57,53,44,52,49,55,50,56,44,52,49,55,50,57,44,52,49,55,51,48,44,52,
49,57,56,53,44,52,49,57,56,54,44,52,49,57,56,55,44,52,49,57,56,56,44,52,49,57,56,57,44,52,49,57,57,48,44,52,49,57,57,49,44,52,49,57,57,50,44,52,49,57,57,51,44,52,49,57,57,52,44,52,49,57,57,53,44,52,49,
57,57,54,44,52,50,48,49,54,44,48,44,50,44,52,44,53,44,54,44,55,44,56,44,57,44,49,48,44,49,49,44,49,50,44,49,51,44,49,52,44,49,53,44,49,54,44,49,55,44,49,56,44,50,48,44,50,50,44,50,51,44,50,52,44,50,53,
44,50,54,44,50,55,44,50,56,44,51,48,59,56,52,69,48,54,54,56,57,48,48,53,66,51,48,50,53,66,53,68,68,49,69,67,68,69,52,52,69,66,57,53,55,60,47,101,120,105,102,58,78,97,116,105,118,101,68,105,103,101,115,
116,62,10,32,32,32,32,32,32,60,47,114,100,102,58,68,101,115,99,114,105,112,116,105,111,110,62,10,32,32,32,32,32,32,60,114,100,102,58,68,101,115,99,114,105,112,116,105,111,110,32,114,100,102,58,97,98,111,
117,116,61,34,34,10,32,32,32,32,32,32,32,32,32,32,32,32,120,109,108,110,115,58,116,105,102,102,61,34,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,109,47,116,105,102,102,47,49,46,48,
47,34,62,10,32,32,32,32,32,32,32,32,32,60,116,105,102,102,58,79,114,105,101,110,116,97,116,105,111,110,62,49,60,47,116,105,102,102,58,79,114,105,101,110,116,97,116,105,111,110,62,10,32,32,32,32,32,32,
32,32,32,60,116,105,102,102,58,88,82,101,115,111,108,117,116,105,111,110,62,51,48,48,48,48,48,48,47,49,48,48,48,48,60,47,116,105,102,102,58,88,82,101,115,111,108,117,116,105,111,110,62,10,32,32,32,32,
32,32,32,32,32,60,116,105,102,102,58,89,82,101,115,111,108,117,116,105,111,110,62,51,48,48,48,48,48,48,47,49,48,48,48,48,60,47,116,105,102,102,58,89,82,101,115,111,108,117,116,105,111,110,62,10,32,32,
32,32,32,32,32,32,32,60,116,105,102,102,58,82,101,115,111,108,117,116,105,111,110,85,110,105,116,62,50,60,47,116,105,102,102,58,82,101,115,111,108,117,116,105,111,110,85,110,105,116,62,10,32,32,32,32,
32,32,32,32,32,60,116,105,102,102,58,78,97,116,105,118,101,68,105,103,101,115,116,62,50,53,54,44,50,53,55,44,50,53,56,44,50,53,57,44,50,54,50,44,50,55,52,44,50,55,55,44,50,56,52,44,53,51,48,44,53,51,49,
44,50,56,50,44,50,56,51,44,50,57,54,44,51,48,49,44,51,49,56,44,51,49,57,44,53,50,57,44,53,51,50,44,51,48,54,44,50,55,48,44,50,55,49,44,50,55,50,44,51,48,53,44,51,49,53,44,51,51,52,51,50,59,69,48,57,53,
54,49,55,57,70,56,54,53,67,68,54,67,56,53,70,68,49,67,51,52,66,53,67,69,68,66,67,65,60,47,116,105,102,102,58,78,97,116,105,118,101,68,105,103,101,115,116,62,10,32,32,32,32,32,32,60,47,114,100,102,58,68,
101,115,99,114,105,112,116,105,111,110,62,10,32,32,32,32,32,32,60,114,100,102,58,68,101,115,99,114,105,112,116,105,111,110,32,114,100,102,58,97,98,111,117,116,61,34,34,10,32,32,32,32,32,32,32,32,32,32,
32,32,120,109,108,110,115,58,120,97,112,61,34,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,109,47,120,97,112,47,49,46,48,47,34,62,10,32,32,32,32,32,32,32,32,32,60,120,97,112,58,67,114,
101,97,116,101,68,97,116,101,62,50,48,48,54,45,48,55,45,48,50,84,50,48,58,49,49,58,52,55,45,48,53,58,48,48,60,47,120,97,112,58,67,114,101,97,116,101,68,97,116,101,62,10,32,32,32,32,32,32,32,32,32,60,120,
97,112,58,77,111,100,105,102,121,68,97,116,101,62,50,48,48,55,45,48,54,45,50,57,84,49,48,58,50,48,58,51,55,45,48,55,58,48,48,60,47,120,97,112,58,77,111,100,105,102,121,68,97,116,101,62,10,32,32,32,32,
32,32,32,32,32,60,120,97,112,58,77,101,116,97,100,97,116,97,68,97,116,101,62,50,48,48,55,45,48,54,45,50,57,84,49,48,58,50,48,58,51,55,45,48,55,58,48,48,60,47,120,97,112,58,77,101,116,97,100,97,116,97,
68,97,116,101,62,10,32,32,32,32,32,32,32,32,32,60,120,97,112,58,67,114,101,97,116,111,114,84,111,111,108,62,65,100,111,98,101,32,80,104,111,116,111,115,104,111,112,32,67,83,50,32,87,105,110,100,111,119,
115,60,47,120,97,112,58,67,114,101,97,116,111,114,84,111,111,108,62,10,32,32,32,32,32,32,60,47,114,100,102,58,68,101,115,99,114,105,112,116,105,111,110,62,10,32,32,32,32,32,32,60,114,100,102,58,68,101,
115,99,114,105,112,116,105,111,110,32,114,100,102,58,97,98,111,117,116,61,34,34,10,32,32,32,32,32,32,32,32,32,32,32,32,120,109,108,110,115,58,120,97,112,77,77,61,34,104,116,116,112,58,47,47,110,115,46,
97,100,111,98,101,46,99,111,109,47,120,97,112,47,49,46,48,47,109,109,47,34,10,32,32,32,32,32,32,32,32,32,32,32,32,120,109,108,110,115,58,115,116,82,101,102,61,34,104,116,116,112,58,47,47,110,115,46,97,
100,111,98,101,46,99,111,109,47,120,97,112,47,49,46,48,47,115,84,121,112,101,47,82,101,115,111,117,114,99,101,82,101,102,35,34,62,10,32,32,32,32,32,32,32,32,32,60,120,97,112,77,77,58,68,101,114,105,118,
101,100,70,114,111,109,32,114,100,102,58,112,97,114,115,101,84,121,112,101,61,34,82,101,115,111,117,114,99,101,34,62,10,32,32,32,32,32,32,32,32,32,32,32,32,60,115,116,82,101,102,58,105,110,115,116,97,
110,99,101,73,68,62,117,117,105,100,58,51,99,57,49,55,99,57,51,45,100,54,101,100,45,49,49,100,97,45,57,98,49,56,45,102,54,53,48,50,99,98,99,101,100,50,97,60,47,115,116,82,101,102,58,105,110,115,116,97,
110,99,101,73,68,62,10,32,32,32,32,32,32,32,32,32,32,32,32,60,115,116,82,101,102,58,100,111,99,117,109,101,110,116,73,68,62,97,100,111,98,101,58,100,111,99,105,100,58,112,104,111,116,111,115,104,111,112,
58,57,97,48,97,53,57,54,99,45,100,54,101,99,45,49,49,100,97,45,57,98,49,56,45,102,54,53,48,50,99,98,99,101,100,50,97,60,47,115,116,82,101,102,58,100,111,99,117,109,101,110,116,73,68,62,10,32,32,32,32,
32,32,32,32,32,60,47,120,97,112,77,77,58,68,101,114,105,118,101,100,70,114,111,109,62,10,32,32,32,32,32,32,32,32,32,60,120,97,112,77,77,58,68,111,99,117,109,101,110,116,73,68,62,97,100,111,98,101,58,100,
111,99,105,100,58,112,104,111,116,111,115,104,111,112,58,55,52,98,102,57,54,57,49,45,48,98,57,56,45,49,49,100,98,45,98,53,52,102,45,57,99,48,57,102,100,102,48,57,55,53,56,60,47,120,97,112,77,77,58,68,
111,99,117,109,101,110,116,73,68,62,10,32,32,32,32,32,32,32,32,32,60,120,97,112,77,77,58,73,110,115,116,97,110,99,101,73,68,62,117,117,105,100,58,50,51,48,53,52,50,57,50,54,52,50,54,68,67,49,49,57,67,
69,56,70,51,53,51,50,67,57,66,49,53,66,67,60,47,120,97,112,77,77,58,73,110,115,116,97,110,99,101,73,68,62,10,32,32,32,32,32,32,60,47,114,100,102,58,68,101,115,99,114,105,112,116,105,111,110,62,10,32,32,
32,32,32,32,60,114,100,102,58,68,101,115,99,114,105,112,116,105,111,110,32,114,100,102,58,97,98,111,117,116,61,34,34,10,32,32,32,32,32,32,32,32,32,32,32,32,120,109,108,110,115,58,100,99,61,34,104,116,
116,112,58,47,47,112,117,114,108,46,111,114,103,47,100,99,47,101,108,101,109,101,110,116,115,47,49,46,49,47,34,62,10,32,32,32,32,32,32,32,32,32,60,100,99,58,102,111,114,109,97,116,62,105,109,97,103,101,
47,106,112,101,103,60,47,100,99,58,102,111,114,109,97,116,62,10,32,32,32,32,32,32,60,47,114,100,102,58,68,101,115,99,114,105,112,116,105,111,110,62,10,32,32,32,32,32,32,60,114,100,102,58,68,101,115,99,
114,105,112,116,105,111,110,32,114,100,102,58,97,98,111,117,116,61,34,34,10,32,32,32,32,32,32,32,32,32,32,32,32,120,109,108,110,115,58,112,104,111,116,111,115,104,111,112,61,34,104,116,116,112,58,47,47,
110,115,46,97,100,111,98,101,46,99,111,109,47,112,104,111,116,111,115,104,111,112,47,49,46,48,47,34,62,10,32,32,32,32,32,32,32,32,32,60,112,104,111,116,111,115,104,111,112,58,67,111,108,111,114,77,111,
100,101,62,51,60,47,112,104,111,116,111,115,104,111,112,58,67,111,108,111,114,77,111,100,101,62,10,32,32,32,32,32,32,32,32,32,60,112,104,111,116,111,115,104,111,112,58,72,105,115,116,111,114,121,47,62,
10,32,32,32,32,32,32,60,47,114,100,102,58,68,101,115,99,114,105,112,116,105,111,110,62,10,32,32,32,60,47,114,100,102,58,82,68,70,62,10,60,47,120,58,120,109,112,109,101,116,97,62,10,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,60,63,120,112,97,99,107,101,116,32,101,110,100,61,34,119,
34,63,62,255,238,0,14,65,100,111,98,101,0,100,64,0,0,0,1,255,219,0,132,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,
1,1,1,1,1,1,1,1,1,1,1,2,2,1,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,255,192,0,17,8,2,48,1,244,3,1,17,0,2,17,1,3,17,1,255,221,0,4,0,63,255,
196,1,162,0,0,0,6,2,3,1,0,0,0,0,0,0,0,0,0,0,7,8,6,5,4,9,3,10,2,1,0,11,1,0,0,6,3,1,1,1,0,0,0,0,0,0,0,0,0,6,5,4,3,7,2,8,1,9,0,10,11,16,0,2,1,3,4,1,3,3,2,3,3,3,2,6,9,117,1,2,3,4,17,5,18,6,33,7,19,34,0,8,
49,20,65,50,35,21,9,81,66,22,97,36,51,23,82,113,129,24,98,145,37,67,161,177,240,38,52,114,10,25,193,209,53,39,225,83,54,130,241,146,162,68,84,115,69,70,55,71,99,40,85,86,87,26,178,194,210,226,242,100,
131,116,147,132,101,163,179,195,211,227,41,56,102,243,117,42,57,58,72,73,74,88,89,90,103,104,105,106,118,119,120,121,122,133,134,135,136,137,138,148,149,150,151,152,153,154,164,165,166,167,168,169,170,
180,181,182,183,184,185,186,196,197,198,199,200,201,202,212,213,214,215,216,217,218,228,229,230,231,232,233,234,244,245,246,247,248,249,250,17,0,2,1,3,2,4,4,3,5,4,4,4,6,6,5,109,1,2,3,17,4,33,18,5,49,6,
0,34,19,65,81,7,50,97,20,113,8,66,129,35,145,21,82,161,98,22,51,9,177,36,193,209,67,114,240,23,225,130,52,37,146,83,24,99,68,241,162,178,38,53,25,84,54,69,100,39,10,115,131,147,70,116,194,210,226,242,
85,101,117,86,55,132,133,163,179,195,211,227,243,41,26,148,164,180,196,212,228,244,149,165,181,197,213,229,245,40,71,87,102,56,118,134,150,166,182,198,214,230,246,103,119,135,151,167,183,199,215,231,247,
72,88,104,120,136,152,168,184,200,216,232,248,57,73,89,105,121,137,153,169,185,201,217,233,249,42,58,74,90,106,122,138,154,170,186,202,218,234,250,255,218,0,12,3,1,0,2,17,3,17,0,63,0,223,227,223,186,247,
94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,
94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,
94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,
94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,
94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,
94,247,238,189,215,189,251,175,117,255,208,223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,
247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,
247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,
247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,
247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,
247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,255,209,223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,
238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,
238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,
238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,
238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,
238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,255,210,223,227,223,186,247,94,247,238,
189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,
189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,
189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,
189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,
189,215,189,251,175,116,156,221,251,183,109,108,61,173,184,119,174,242,205,227,246,214,211,218,152,124,134,224,220,121,252,181,66,82,227,112,248,108,85,52,149,185,12,133,109,67,157,49,211,211,83,66,204,
223,147,107,0,73,3,219,114,203,28,17,73,52,174,22,37,4,146,124,128,233,251,91,91,139,219,152,44,237,33,105,46,165,112,168,170,42,89,152,208,0,61,73,235,88,111,144,255,0,206,15,229,254,124,82,111,46,132,
196,245,127,71,117,150,224,204,36,29,87,75,218,91,79,47,190,123,19,176,118,211,213,136,104,119,238,243,160,167,175,197,98,122,235,108,238,84,81,53,5,46,169,114,13,75,42,187,233,39,136,127,127,247,30,230,
202,67,244,144,168,80,9,210,64,46,87,200,154,154,2,114,66,255,0,62,179,187,219,95,186,70,211,190,109,210,220,115,54,227,59,93,44,100,191,134,193,35,73,41,253,154,84,51,72,80,208,59,80,40,53,165,122,185,
223,229,193,243,7,63,243,43,227,252,155,203,176,54,198,43,100,247,6,192,222,89,238,176,237,221,171,132,171,150,179,11,73,187,246,231,219,74,153,140,11,212,19,84,184,13,205,136,173,167,174,165,18,92,170,
202,201,169,180,220,200,28,171,204,17,115,38,209,6,229,24,21,110,52,243,249,211,202,190,158,70,163,172,85,247,99,219,249,61,182,231,11,206,94,19,52,150,122,86,72,157,133,9,70,174,13,48,74,144,65,35,143,
30,143,253,253,137,58,141,58,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,255,211,223,227,223,186,247,94,247,238,
189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,210,99,39,189,182,118,19,47,143,192,102,119,102,218,196,231,114,
218,78,43,11,147,207,98,168,50,249,61,76,81,127,135,99,106,234,225,173,173,212,226,195,198,141,114,45,237,166,158,20,96,143,42,135,62,68,128,127,101,122,81,29,165,220,209,73,60,86,178,52,9,241,48,82,84,
125,164,10,14,148,192,223,219,189,39,235,191,126,235,221,123,223,186,247,85,191,243,147,249,132,96,254,41,212,227,250,223,98,236,245,237,142,254,220,59,98,175,122,81,108,202,140,204,123,103,103,236,125,
141,71,87,252,54,94,193,237,77,225,44,53,41,183,118,228,185,70,20,180,84,208,71,54,67,41,84,12,84,241,146,11,0,207,48,243,45,174,197,11,22,1,166,9,168,212,209,85,120,2,198,135,137,192,3,39,203,169,87,
219,63,106,183,143,113,175,81,97,102,135,109,241,68,90,194,235,121,101,32,183,133,10,84,106,96,163,83,179,16,145,175,115,26,117,81,57,223,231,27,243,199,163,183,182,219,164,239,46,143,234,12,158,35,117,
67,6,111,23,180,233,105,55,255,0,89,230,243,152,10,233,45,79,253,207,220,219,170,42,252,77,101,75,43,5,129,171,225,165,142,89,10,135,41,170,226,62,139,220,219,184,110,227,134,250,200,162,178,134,1,145,
163,170,158,12,164,146,104,125,105,246,245,146,113,253,211,118,93,247,97,220,183,94,84,230,143,170,22,140,99,153,162,150,43,129,20,171,150,89,81,40,113,231,161,143,202,188,58,216,83,226,255,0,201,46,186,
249,99,211,27,75,187,186,194,108,143,247,115,116,71,91,79,87,139,205,83,45,30,123,107,238,76,53,91,227,119,22,212,220,20,136,242,199,79,153,192,101,32,146,9,130,59,198,197,67,35,50,176,62,229,141,183,
112,131,116,179,138,242,220,159,13,188,143,16,124,193,251,62,92,120,245,134,252,209,203,91,159,40,239,119,187,14,236,128,93,194,120,140,171,169,21,87,83,230,172,8,35,207,212,14,140,23,181,253,7,250,247,
191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,
191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,
191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,232,129,255,0,48,175,153,117,31,15,250,171,109,77,178,246,238,63,123,247,167,113,111,42,30,
177,232,237,149,149,168,150,155,15,95,187,178,48,203,85,89,184,183,60,212,196,86,65,180,54,118,34,9,107,242,13,21,157,210,53,137,74,180,129,129,22,253,188,126,232,180,15,24,13,114,230,138,15,14,21,44,
126,64,117,35,123,99,200,82,243,255,0,48,254,239,146,102,139,106,130,51,45,196,138,42,202,128,128,21,107,141,110,196,42,214,160,86,190,93,107,31,219,95,56,255,0,154,31,70,111,172,103,116,84,252,139,206,
239,170,100,175,155,41,30,195,202,109,28,14,7,165,247,221,38,49,245,229,246,198,27,108,80,83,255,0,17,195,227,170,224,138,72,104,235,154,162,74,197,58,100,114,204,79,184,115,250,245,189,71,185,135,146,
225,252,2,223,237,78,105,129,195,79,150,63,195,214,125,109,95,119,15,104,121,139,150,55,29,171,107,182,166,253,4,53,46,28,180,168,212,252,76,78,91,204,174,5,112,7,86,83,243,223,230,142,216,249,129,241,
135,225,166,195,216,53,53,56,237,147,243,7,25,63,117,119,53,4,85,44,43,177,125,53,212,16,209,229,119,158,194,200,180,68,89,55,15,96,26,124,44,197,180,135,72,36,22,245,17,236,113,204,251,252,115,108,214,
76,152,73,80,200,224,30,1,56,175,230,248,207,167,88,223,236,159,182,55,150,94,228,239,241,110,17,106,186,218,166,16,68,72,193,154,98,66,73,254,214,32,206,63,211,15,78,139,7,203,188,38,14,139,225,14,27,
114,205,139,199,67,186,55,102,224,164,207,10,149,137,82,124,126,46,153,146,28,86,38,155,128,82,142,134,142,20,142,53,91,40,81,192,226,222,226,123,219,104,206,193,105,127,52,96,222,92,74,89,141,51,166,
148,3,236,167,89,157,200,119,87,146,251,195,187,237,54,247,47,251,163,111,180,48,42,103,73,106,119,49,28,53,19,82,124,250,95,127,45,175,150,155,19,226,222,43,229,207,96,111,165,202,228,113,91,159,108,
252,115,222,91,99,105,109,232,99,174,221,91,243,177,51,216,204,214,193,199,109,29,163,141,146,88,133,126,119,112,229,177,193,100,60,71,4,48,180,211,50,197,25,32,67,237,38,241,14,215,177,111,48,220,28,
65,61,2,142,36,177,37,64,31,97,252,128,251,58,199,223,189,55,33,238,60,209,207,124,151,105,180,68,162,234,226,41,145,157,176,136,136,193,153,228,111,37,85,253,164,128,50,105,215,46,207,254,112,191,55,
250,243,123,141,239,87,179,250,77,250,243,108,213,12,246,251,232,250,12,94,224,175,220,212,27,6,158,170,35,156,167,160,237,103,201,195,141,204,239,220,22,36,180,206,32,160,143,28,103,141,163,82,234,53,
21,247,94,234,205,107,187,91,219,73,18,125,51,74,16,208,84,2,120,2,213,175,202,163,207,203,167,32,251,158,236,242,114,76,251,187,111,119,7,118,41,216,213,93,37,233,80,76,96,18,168,77,6,78,162,51,214,207,
123,43,118,225,247,246,207,218,187,235,110,206,106,182,246,243,219,120,45,215,130,169,101,10,243,225,247,14,46,151,47,142,153,208,18,17,228,164,172,66,69,205,143,30,230,200,101,89,225,138,100,29,174,160,
143,204,87,172,7,187,181,150,202,238,234,206,113,73,225,145,145,135,244,148,149,63,204,116,167,246,231,73,250,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,
221,123,175,255,212,223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,69,183,229,247,124,211,124,
99,248,213,220,61,233,61,52,85,181,91,3,103,215,228,176,184,233,88,4,201,238,90,166,139,23,182,168,24,91,84,137,83,156,174,128,58,142,74,106,246,95,186,222,254,239,219,238,110,199,196,139,143,180,224,
127,135,161,23,41,108,50,115,63,50,108,251,12,102,159,83,58,169,62,139,197,143,251,200,61,104,151,242,79,174,123,206,174,167,107,252,132,237,216,55,6,226,203,118,171,79,159,199,246,86,234,201,101,223,
51,189,243,84,179,125,198,102,76,22,78,158,190,9,246,150,23,9,90,237,71,137,165,199,248,18,146,150,157,8,212,196,147,140,187,206,233,187,189,218,95,206,242,44,18,147,225,185,252,90,77,11,86,153,21,197,
5,40,56,117,216,127,108,57,55,219,155,157,143,113,229,13,167,233,165,221,172,35,81,113,2,168,62,8,113,218,172,8,238,98,59,152,181,73,98,107,138,117,177,167,242,69,249,243,187,251,171,23,184,254,52,247,
70,243,170,222,59,195,103,224,33,222,61,59,187,55,29,66,203,188,55,47,92,83,212,38,35,113,109,29,209,88,2,12,214,230,235,76,203,67,23,221,149,243,214,99,106,161,150,75,178,187,123,153,57,7,153,165,221,
237,158,198,246,74,221,68,48,79,18,7,243,56,161,28,72,21,7,135,92,253,251,204,251,67,109,200,27,228,59,214,201,101,225,109,23,78,86,68,95,130,57,106,72,42,51,165,100,21,199,0,192,211,136,235,97,47,114,
55,88,177,215,143,60,127,95,126,235,221,106,113,187,187,159,103,100,62,91,124,141,249,1,219,84,241,230,182,142,208,238,157,221,81,87,130,152,174,141,201,132,248,237,136,195,109,46,165,216,75,229,13,175,
25,46,246,203,87,228,165,135,148,122,150,214,86,224,123,199,174,106,221,173,155,153,22,77,197,117,237,240,188,147,52,127,239,214,139,178,8,190,194,249,62,92,79,93,29,246,139,146,119,155,191,108,237,246,
78,83,99,15,50,238,209,65,103,28,227,141,186,94,179,75,125,113,242,97,2,172,96,212,16,49,94,170,87,229,255,0,202,222,209,249,133,190,234,59,59,183,114,20,56,188,54,18,9,41,40,98,162,131,236,118,206,195,
218,139,86,106,163,194,227,100,32,203,147,205,86,54,152,226,68,215,83,85,84,202,21,110,125,128,238,119,93,211,152,183,54,220,119,6,15,112,195,66,40,20,10,60,145,84,112,85,243,39,142,73,61,102,95,46,242,
39,34,123,21,201,114,114,151,42,187,52,174,68,151,51,59,106,146,121,66,208,200,231,225,80,51,165,5,0,21,251,122,219,127,249,53,116,134,242,232,239,130,189,123,69,191,177,217,12,22,232,236,140,246,239,
238,10,205,181,148,138,74,124,142,219,161,236,28,196,153,108,22,38,190,154,95,220,167,200,166,19,237,228,169,70,1,150,105,24,17,112,125,228,207,39,216,205,183,236,118,144,206,8,145,134,175,178,180,167,
237,2,189,113,211,223,46,101,178,230,175,114,119,237,195,110,42,214,113,178,194,172,40,67,120,99,73,96,71,16,77,105,242,234,212,189,138,58,136,186,247,191,117,238,189,239,221,123,174,137,176,191,215,250,
15,234,127,167,191,117,238,170,3,229,167,243,91,197,117,6,244,220,157,85,241,227,171,215,228,38,251,216,53,107,67,218,91,134,163,118,82,108,254,169,235,28,187,83,253,212,123,79,45,186,133,30,90,183,113,
239,198,167,180,146,226,113,148,211,75,71,27,6,168,120,137,11,236,25,191,115,149,150,206,205,18,5,121,20,209,137,52,80,127,132,121,179,122,129,129,230,107,212,251,237,159,176,28,199,238,4,48,223,92,78,
108,172,37,21,138,168,76,146,45,105,172,2,84,36,117,192,119,35,81,248,65,233,5,240,51,249,201,224,190,84,119,36,95,30,251,99,170,147,167,251,39,59,79,151,168,216,57,172,38,232,93,225,176,55,205,86,6,21,
171,204,109,154,92,148,148,56,220,142,27,116,81,99,201,169,74,122,152,244,212,194,172,99,55,82,61,183,203,188,233,109,189,220,253,27,196,18,98,59,104,77,15,157,50,1,21,25,30,189,25,251,189,247,111,230,
79,106,246,180,223,94,240,93,109,122,130,191,110,153,35,213,128,196,2,192,169,56,168,56,197,122,187,192,110,47,244,246,55,235,27,250,239,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,
123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,
123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,90,222,255,0,54,220,173,68,255,0,204,7,225,198,14,
169,139,227,112,63,28,62,76,111,44,77,59,155,196,155,158,111,224,184,88,235,35,94,64,172,135,26,29,99,107,2,161,141,143,184,211,158,92,139,139,113,228,45,228,63,180,255,0,177,78,179,23,238,193,107,19,
109,92,205,53,7,140,215,214,169,95,232,209,154,159,239,84,253,157,17,143,157,177,197,144,248,249,241,211,39,2,171,37,62,52,135,85,0,221,180,122,245,30,65,212,15,231,235,238,27,220,229,13,109,180,16,120,
196,71,243,235,50,189,146,182,54,220,225,238,20,14,50,37,83,249,87,135,68,95,226,161,220,11,181,251,149,114,149,34,108,39,86,80,237,158,153,234,196,214,223,238,43,3,218,59,214,191,179,55,69,13,56,36,136,
229,155,39,80,82,64,150,186,34,131,236,202,238,238,89,182,5,149,154,166,129,0,251,73,36,15,180,241,233,117,135,44,216,108,254,236,110,43,110,131,245,164,107,167,255,0,107,8,9,159,144,20,207,86,69,252,
195,50,49,80,244,22,201,218,244,204,4,24,218,60,45,40,141,26,224,72,180,136,242,3,110,6,131,254,199,219,188,198,203,22,221,180,90,169,194,168,31,200,116,87,236,173,171,205,205,124,213,187,204,63,82,89,
36,106,252,139,16,58,174,175,138,56,218,188,141,86,243,239,28,245,84,245,178,245,165,38,27,166,186,174,138,70,38,130,143,116,238,31,61,110,95,59,29,53,252,19,228,176,88,108,129,138,158,98,12,144,26,169,
52,149,191,178,235,52,77,167,101,190,188,136,82,89,159,183,230,199,26,191,103,66,238,98,177,181,223,185,254,199,105,138,16,82,218,6,146,118,243,32,85,180,87,200,28,84,112,52,29,25,111,150,98,21,135,3,
180,210,56,16,214,236,13,197,139,171,149,21,68,147,156,150,219,174,141,222,114,5,228,118,152,234,185,189,253,132,119,26,1,27,145,223,25,141,191,48,192,215,163,14,81,182,55,60,187,205,23,108,199,75,74,
104,9,192,3,128,31,224,235,105,111,229,189,150,155,57,240,47,226,78,78,161,218,73,106,122,43,96,130,238,110,197,105,176,208,82,165,205,207,210,56,64,250,241,239,48,54,7,47,178,237,174,120,152,87,252,29,
113,171,220,56,5,183,60,243,100,3,130,223,204,63,227,103,163,177,236,223,160,111,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,255,213,223,227,223,
186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,85,245,252,211,250,215,43,218,159,2,126,68,237,236,20,18,85,
102,113,27,78,143,125,80,82,68,11,75,88,122,247,59,138,222,117,212,113,198,160,153,101,172,197,225,103,137,23,251,78,227,217,31,50,64,110,54,107,213,81,82,160,55,228,164,19,252,171,212,129,237,94,235,
22,205,238,7,44,94,206,212,135,234,2,19,228,60,64,99,4,252,129,96,79,237,235,93,142,233,205,71,222,31,203,207,173,169,40,229,90,253,199,241,203,119,86,198,190,6,50,12,158,192,222,49,195,158,219,249,154,
112,63,84,19,227,114,10,247,255,0,2,62,162,222,241,239,121,144,207,203,182,150,110,79,212,237,247,18,41,249,164,135,82,183,217,145,215,79,253,174,240,249,87,222,253,215,112,80,23,104,230,125,190,55,7,
248,110,33,26,36,66,125,117,41,20,61,17,223,229,237,189,229,234,159,155,127,27,119,36,21,51,81,194,157,245,183,48,21,115,211,201,227,47,183,59,107,5,151,217,217,220,124,156,168,122,74,188,132,116,204,
200,125,38,64,167,234,7,187,114,29,227,91,239,246,52,122,43,16,15,207,52,255,0,3,126,206,151,125,236,249,110,59,238,65,230,6,17,2,203,1,145,113,193,163,33,199,230,51,215,208,59,222,79,117,199,46,188,120,
4,255,0,79,126,235,221,105,21,242,99,166,59,15,119,252,249,222,255,0,7,54,12,184,236,94,239,236,143,147,219,183,112,226,43,183,4,82,205,140,195,245,255,0,99,224,104,251,44,111,204,149,12,79,19,230,177,
248,44,93,5,96,138,157,8,73,171,145,99,98,57,247,143,187,239,44,201,186,115,128,179,97,72,75,183,231,169,181,15,248,205,79,229,140,245,210,223,108,61,211,180,228,159,99,159,156,80,150,189,130,221,35,1,
120,151,74,194,84,19,192,150,32,31,69,169,235,97,31,140,95,201,179,225,247,199,106,252,6,239,206,97,115,189,245,217,184,41,169,242,20,187,219,184,235,147,61,67,142,205,67,226,144,101,118,206,196,130,58,
125,153,183,101,134,117,38,3,29,36,147,66,166,222,70,35,87,185,87,104,228,189,147,105,240,221,45,67,206,190,103,133,126,67,63,206,189,97,215,60,123,247,238,47,60,139,155,123,205,225,173,182,201,14,98,
132,149,4,122,51,215,91,124,234,104,125,58,182,32,45,107,127,75,31,197,254,150,224,113,248,246,45,234,23,235,151,191,117,238,189,239,221,123,175,123,247,94,234,186,127,153,191,201,61,231,241,235,227,204,
24,206,166,168,138,151,187,187,207,119,226,58,99,170,50,19,167,146,29,181,152,221,11,51,103,183,221,68,103,134,131,98,237,122,106,188,143,62,159,44,72,15,4,251,15,115,46,228,219,118,222,76,79,166,226,
67,165,79,167,155,55,228,181,252,250,147,253,164,228,216,121,211,155,237,108,175,80,182,215,2,153,166,81,130,234,180,211,24,255,0,154,142,85,126,194,122,163,12,39,97,117,63,195,191,139,57,106,157,189,
139,135,63,217,27,233,119,14,11,96,214,110,117,92,158,70,12,13,109,68,195,120,118,230,225,158,168,73,38,67,123,246,94,110,73,234,230,170,146,238,177,20,69,33,64,30,224,121,119,107,113,111,115,50,196,36,
191,154,169,22,161,81,28,89,213,37,14,12,146,31,63,33,158,186,77,183,251,111,186,243,103,59,108,252,189,245,77,109,200,251,32,138,123,227,17,209,245,23,148,12,150,171,167,253,6,221,52,174,145,141,85,232,
3,254,81,157,71,156,236,223,157,253,55,154,74,89,62,223,171,113,251,251,228,70,246,171,41,165,49,116,155,131,17,85,215,125,121,142,157,128,253,170,189,195,89,148,171,171,138,51,98,212,244,250,173,97,127,
103,222,222,216,60,251,204,119,10,191,167,16,169,63,96,35,252,38,157,5,62,249,28,221,105,105,201,178,236,171,40,250,139,185,82,37,95,58,33,89,24,253,138,20,2,124,137,3,207,173,216,125,207,125,114,215,
175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,
175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,
175,123,247,94,235,93,143,231,47,181,165,196,252,176,254,93,189,167,24,113,71,157,203,119,63,69,230,30,218,99,84,221,219,61,178,216,120,204,159,66,211,86,209,202,66,159,245,28,123,142,249,226,220,52,219,
124,191,196,174,159,224,35,252,39,172,176,251,177,238,98,35,205,155,125,123,215,233,238,7,251,71,210,223,200,142,171,175,228,189,65,203,252,118,235,220,91,157,83,109,138,252,150,41,193,229,151,237,234,
30,33,127,169,7,211,238,1,186,148,248,118,209,31,244,50,195,249,158,186,25,237,173,152,183,231,110,102,157,69,22,234,24,220,126,96,30,137,239,64,212,125,151,88,103,145,184,59,139,229,54,58,41,62,133,100,
167,219,184,122,10,117,70,189,181,44,111,33,181,248,23,246,109,116,250,118,109,190,49,230,224,244,97,109,15,141,238,15,57,92,156,248,86,110,163,229,217,142,141,79,243,11,221,116,109,180,177,116,130,78,
41,21,178,83,198,57,180,84,212,108,254,161,205,129,9,238,251,244,226,105,172,160,67,82,20,15,219,78,145,251,69,183,181,165,190,243,184,202,180,136,41,207,217,147,254,126,130,94,176,219,242,236,174,156,
248,213,177,38,136,211,228,183,59,87,118,254,236,70,186,201,54,79,119,215,189,78,59,206,13,152,253,182,33,32,85,191,208,15,108,115,35,248,48,109,182,10,112,168,24,253,166,159,228,255,0,15,79,123,127,17,
190,139,220,14,109,151,50,74,90,52,39,208,215,135,228,71,82,190,67,229,87,57,217,152,138,100,113,42,161,74,24,148,115,123,210,74,172,163,142,1,30,194,151,76,94,222,246,79,48,191,224,167,66,254,88,176,
22,92,151,118,24,81,164,12,199,231,94,182,154,254,84,149,198,191,249,119,124,80,151,88,127,182,235,26,124,89,97,167,235,134,204,101,241,14,190,159,79,162,74,34,56,254,158,242,243,149,155,95,47,237,109,
95,244,33,254,94,184,155,238,204,94,15,185,28,228,132,80,253,116,135,246,208,255,0,151,171,10,246,127,212,121,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,
126,235,221,127,255,214,223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,81,107,104,169,114,52,
117,120,250,234,120,170,232,171,169,167,163,172,164,157,4,144,85,82,213,68,240,84,83,204,140,10,188,83,195,35,43,3,193,7,222,153,67,43,43,10,169,20,61,89,29,227,116,146,54,33,212,130,8,226,8,224,127,35,
214,159,191,37,122,43,117,127,47,206,249,201,117,100,56,170,220,231,199,94,211,167,203,203,210,21,245,15,228,166,200,236,234,153,42,114,59,147,161,171,234,164,62,38,223,61,99,87,89,45,102,218,242,17,46,
67,11,33,129,110,208,133,247,1,115,167,47,205,181,92,61,197,172,101,237,220,17,254,154,63,225,255,0,77,31,151,153,80,15,93,35,246,55,220,13,191,220,125,138,219,107,221,47,210,14,102,179,112,193,206,52,
78,40,22,81,230,33,184,3,76,180,194,74,53,96,53,122,169,94,192,199,213,245,198,247,164,221,221,127,84,107,151,21,151,195,111,77,137,92,53,166,172,230,202,207,208,239,60,30,62,168,91,201,21,82,214,98,90,
150,68,32,48,50,17,107,251,142,182,155,161,97,185,90,79,27,246,43,212,31,145,255,0,80,253,157,102,23,59,109,239,206,188,131,127,99,184,219,148,220,196,13,28,201,64,126,36,40,88,122,169,4,144,124,248,245,
244,34,232,238,210,192,247,119,79,117,151,111,109,154,152,42,176,157,143,178,54,230,239,162,122,121,82,100,139,248,206,50,158,174,166,141,228,75,3,61,5,100,146,65,40,176,43,44,108,164,2,45,239,46,108,
174,82,238,210,218,229,13,85,208,31,218,51,251,14,58,225,94,245,182,79,179,110,251,150,211,114,133,103,182,157,227,32,224,246,177,21,252,192,168,249,30,151,59,147,113,224,54,134,3,51,186,119,86,103,25,
183,118,214,222,198,213,230,51,153,220,213,109,62,59,19,136,197,208,66,245,21,185,12,133,117,83,199,79,75,73,75,4,101,221,221,130,128,61,189,44,177,195,27,203,51,133,137,69,73,38,128,15,159,72,173,237,
231,187,158,27,91,88,90,75,153,24,42,170,130,89,152,154,0,0,201,36,240,29,81,117,95,121,255,0,45,31,151,255,0,58,254,54,119,159,85,252,132,196,237,111,147,93,55,150,203,237,141,181,150,203,109,189,193,
181,246,215,123,108,13,193,143,201,98,242,155,23,29,156,220,184,188,78,23,117,212,39,241,41,42,48,245,20,181,15,80,178,51,8,214,72,222,222,193,173,127,176,238,155,197,157,205,173,250,165,252,45,67,81,
64,234,113,166,167,21,254,19,199,169,208,242,231,186,92,153,200,124,193,179,239,28,177,59,114,165,250,44,141,144,198,222,84,33,150,90,33,44,131,0,56,96,20,142,52,34,189,95,88,250,95,145,254,7,241,236,
109,212,11,215,126,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,94,95,230,219,186,166,172,249,61,212,27,82,166,178,88,241,61,119,241,215,177,123,30,8,252,140,33,164,207,239,237,217,67,
214,145,229,4,127,161,42,233,176,116,245,105,28,159,169,67,155,125,125,197,62,227,221,60,74,168,27,181,96,39,243,118,211,95,216,15,89,173,247,66,217,214,226,255,0,113,220,22,21,121,205,212,104,1,21,36,
70,141,40,31,97,125,63,179,170,52,237,90,204,183,115,246,126,11,21,183,54,222,119,124,253,253,93,22,198,234,30,168,218,145,53,86,228,236,220,206,38,24,161,254,19,139,129,7,143,27,180,177,60,79,154,203,
76,82,150,138,156,53,219,81,3,220,71,182,88,92,238,83,164,48,68,75,177,3,30,67,128,81,249,127,42,158,179,243,123,230,109,167,218,254,79,152,238,151,169,13,201,215,61,204,142,64,163,200,107,147,196,183,
146,129,147,195,173,181,127,151,7,194,72,190,26,116,213,76,27,182,171,25,184,123,239,180,171,233,119,127,118,239,12,108,90,104,101,204,199,75,246,216,61,143,182,245,122,160,217,125,123,137,43,143,199,
198,44,36,211,36,199,213,41,182,72,114,222,197,30,199,96,176,208,125,67,101,136,255,0,142,143,144,254,100,158,184,251,238,215,185,23,190,229,243,85,198,237,35,58,237,113,146,182,241,177,248,82,185,99,
253,55,61,205,249,15,46,172,67,216,139,168,191,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,166,29,193,186,182,206,210,199,75,151,221,123,139,5,182,49,52,226,243,229,55,22,95,31,
132,199,66,63,6,90,204,149,69,53,52,96,216,254,166,30,219,146,104,161,93,82,202,170,190,164,129,254,30,159,183,181,185,188,144,67,105,109,36,178,158,10,138,88,159,176,0,79,85,215,219,63,206,23,249,114,
244,237,93,78,43,61,242,115,100,110,125,195,75,44,144,73,181,186,201,114,61,153,184,218,120,205,188,81,227,118,109,30,89,164,105,27,133,33,180,147,205,237,207,178,59,142,104,216,237,241,245,193,222,188,
16,22,255,0,6,63,159,82,30,211,237,7,184,187,194,44,182,252,177,60,86,228,124,115,82,20,253,178,21,232,190,82,255,0,58,237,175,191,36,104,122,3,224,255,0,206,78,237,228,136,114,116,29,58,251,47,110,84,
146,1,136,197,157,221,85,244,240,34,201,127,172,137,25,3,240,125,161,28,216,179,154,88,236,247,83,31,146,211,252,253,30,201,236,212,251,114,135,230,46,122,216,172,125,85,174,68,142,63,218,160,39,246,19,
215,42,207,157,127,205,3,120,44,178,245,207,242,195,198,108,106,9,81,141,45,87,125,252,141,217,187,114,186,53,32,5,105,177,91,126,143,32,100,144,19,125,30,85,246,240,220,57,162,224,176,183,229,205,3,200,
200,224,127,208,61,39,28,167,237,61,141,87,115,247,80,207,32,226,45,44,229,144,127,189,57,95,219,78,144,21,157,213,252,242,247,57,104,233,58,247,224,103,82,195,170,233,46,79,119,111,173,237,145,208,121,
208,87,27,21,69,4,132,115,244,17,253,62,190,244,33,231,153,199,246,22,112,159,155,87,252,173,210,133,139,216,75,49,89,55,30,97,188,111,69,134,56,215,237,238,161,233,182,88,191,158,54,101,25,235,190,80,
252,50,218,96,29,75,75,128,232,253,237,154,111,169,32,26,217,106,27,80,176,177,186,1,249,183,187,254,236,231,55,29,251,173,154,55,200,87,252,10,122,247,239,159,98,33,63,165,202,59,252,223,54,158,36,31,
178,159,229,234,47,247,91,249,208,160,21,18,124,236,232,200,64,112,198,58,127,138,149,213,180,161,72,5,151,201,84,209,202,234,135,129,200,39,242,125,217,118,94,111,165,127,172,54,133,171,195,79,253,11,
213,63,172,254,202,84,143,245,184,221,136,245,250,192,15,242,4,117,154,70,254,114,248,187,77,23,205,239,139,121,115,205,169,179,255,0,19,247,78,38,6,28,112,211,98,107,164,113,254,191,183,63,115,243,138,
208,141,234,208,253,171,255,0,66,244,223,245,131,216,247,52,147,144,183,184,215,213,111,16,255,0,199,151,169,180,157,195,252,233,54,226,179,29,221,252,190,123,76,199,118,240,213,109,206,228,216,53,115,
1,253,129,34,188,180,209,179,125,46,69,135,191,125,15,58,199,74,73,99,41,251,72,63,228,234,191,85,236,53,209,161,181,230,91,74,249,255,0,139,202,63,101,1,199,219,211,212,31,63,255,0,154,22,200,100,126,
195,248,5,213,29,143,68,150,242,207,209,189,253,70,181,210,5,54,118,131,27,189,105,41,155,83,1,233,82,255,0,235,159,116,50,243,148,4,120,188,188,146,39,172,110,9,253,149,63,224,235,95,213,255,0,102,175,
234,187,127,185,87,54,178,30,31,87,104,192,15,181,163,174,58,86,99,255,0,157,158,196,218,210,165,55,200,223,136,95,47,254,61,50,216,85,228,242,125,102,123,31,109,210,139,29,83,28,215,93,212,230,53,211,
173,174,91,194,13,185,183,182,159,153,36,181,96,187,150,203,119,7,204,166,161,251,71,78,47,180,79,185,2,121,91,158,118,61,204,121,5,184,16,185,255,0,105,54,156,159,74,244,115,250,79,249,150,124,22,249,
5,44,52,61,105,242,99,172,43,115,147,149,84,218,251,139,59,22,200,221,126,70,3,246,63,187,123,192,97,114,237,58,147,98,139,17,96,126,163,218,251,94,96,217,239,9,88,111,147,88,242,110,211,251,26,157,5,
183,191,109,185,235,151,193,147,115,229,155,165,128,127,162,34,25,35,255,0,123,143,82,211,231,90,116,120,162,150,41,163,142,104,100,73,98,149,22,72,165,137,214,72,164,71,1,145,210,68,37,25,24,27,130,13,
143,179,128,65,0,131,80,122,4,16,65,32,140,142,178,123,223,90,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,170,102,254,121,56,
26,101,248,141,178,123,77,18,69,204,244,119,201,46,143,236,28,77,92,96,159,180,134,93,217,14,217,205,235,58,73,88,167,195,103,37,70,60,14,121,246,18,231,40,131,109,113,205,78,232,230,82,63,58,143,242,
245,57,125,222,239,164,182,247,10,27,32,127,74,238,210,104,152,122,246,235,95,216,202,58,164,142,251,170,13,139,221,123,110,34,190,26,93,205,45,125,52,127,149,167,201,162,213,41,95,200,66,28,17,239,25,
183,133,17,110,87,17,112,77,122,191,104,235,173,30,218,91,248,215,27,118,227,76,201,108,20,255,0,181,52,232,148,236,58,255,0,224,189,80,38,150,69,167,130,135,228,110,244,172,146,105,157,33,68,48,208,225,
230,230,89,89,17,66,7,6,228,218,222,204,175,156,182,221,182,42,130,95,77,104,5,122,93,203,246,192,243,191,60,25,24,8,217,138,212,144,6,64,226,77,58,73,124,135,238,173,155,191,98,106,44,150,254,219,76,
249,26,204,94,38,101,92,205,61,83,209,99,170,114,52,52,217,10,137,214,153,229,17,199,75,66,100,119,39,128,170,125,167,176,182,188,184,191,134,89,109,220,196,13,73,32,210,131,61,26,111,119,92,189,203,188,
163,186,109,214,27,165,177,190,104,156,4,87,82,197,155,183,20,251,107,209,197,220,189,137,177,183,87,99,96,179,251,15,115,96,119,78,205,194,109,188,6,11,7,144,192,228,32,173,166,20,248,92,108,20,69,36,
88,142,186,87,15,15,233,117,83,254,30,245,204,210,52,187,139,182,146,19,74,129,95,64,60,186,45,246,238,202,51,237,220,214,48,74,26,237,230,98,244,60,42,113,95,62,30,189,2,121,204,177,205,118,174,223,156,
146,99,155,47,35,221,174,108,137,79,80,199,233,198,157,55,246,31,184,82,54,219,175,82,191,225,35,161,158,227,8,177,229,247,183,20,236,132,215,237,167,91,75,255,0,36,93,195,83,184,191,150,207,64,201,80,
133,6,34,78,194,192,210,158,8,150,151,27,216,123,149,99,149,72,250,171,52,134,222,242,215,147,88,158,93,219,193,252,42,71,236,235,135,222,250,219,165,191,186,92,214,35,53,15,50,191,230,200,184,234,216,
253,138,58,136,250,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,255,215,223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,
123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,208,35,242,23,227,207,84,124,160,234,189,201,211,221,199,182,161,220,155,59,114,66,133,130,72,244,89,156,
30,90,152,249,113,59,151,107,230,96,211,91,129,220,216,74,176,179,82,86,64,203,36,82,47,229,75,41,73,125,99,109,184,219,181,181,210,86,51,251,65,245,7,200,244,117,203,252,195,187,114,182,235,107,189,108,
183,70,27,232,142,8,200,97,230,172,56,50,48,193,83,196,124,250,211,251,230,215,192,222,228,248,154,153,106,30,196,175,173,221,93,87,81,149,165,167,216,31,39,96,197,249,48,85,145,207,50,174,15,15,223,184,
220,92,44,221,117,189,232,228,209,1,220,113,33,196,101,52,134,168,241,57,39,220,7,205,92,139,115,99,43,221,91,45,84,159,136,97,88,31,35,252,15,233,94,210,122,233,215,177,255,0,121,93,131,153,225,182,217,
249,136,120,119,162,50,173,29,127,81,113,66,97,45,253,180,62,126,25,253,72,198,20,183,71,103,249,24,124,194,172,235,189,227,186,62,4,246,221,76,248,133,201,101,179,155,187,160,255,0,138,207,174,44,126,
104,171,101,59,19,169,224,169,118,40,33,73,73,205,225,81,91,199,61,37,68,194,43,233,246,44,246,227,152,75,196,219,37,225,43,112,135,0,250,142,35,253,183,31,180,31,94,160,143,189,151,181,107,99,123,15,
184,219,4,98,77,166,228,1,51,32,193,7,17,75,142,31,192,245,200,52,175,86,149,252,228,246,158,239,221,223,3,59,30,61,169,143,201,230,241,219,119,115,117,230,243,236,77,189,136,134,106,170,172,255,0,86,
109,93,221,141,203,111,204,124,148,52,247,159,35,67,22,26,6,169,169,167,80,222,104,41,221,8,42,72,246,54,230,200,166,151,102,155,193,174,25,75,83,248,107,159,217,199,242,235,30,125,147,190,219,108,61,
198,216,102,220,153,86,54,46,136,205,128,178,186,149,140,215,200,234,52,7,200,145,214,179,191,41,186,91,175,169,250,127,172,251,243,171,107,95,116,109,29,199,143,198,82,118,142,29,50,211,86,68,55,84,19,
26,236,110,234,219,117,113,148,147,110,174,79,22,105,234,176,245,84,94,19,68,232,22,59,4,43,239,29,247,11,22,219,210,211,114,179,153,188,114,116,203,83,82,37,6,181,242,236,113,149,253,157,117,55,144,55,
195,205,183,92,199,200,92,215,183,195,217,170,77,190,69,64,160,218,178,209,98,52,248,154,54,212,178,134,169,52,169,245,235,97,143,228,229,243,43,114,124,133,234,77,211,211,253,167,185,231,221,221,175,
209,47,130,74,77,229,146,49,174,95,178,58,131,117,210,203,87,215,155,211,38,136,20,207,158,160,142,154,124,70,94,80,61,117,244,38,70,245,75,238,119,228,125,252,239,91,96,89,222,183,81,224,250,145,195,
249,28,87,210,157,115,99,239,9,237,154,123,121,206,14,108,45,188,61,162,236,177,85,31,12,114,41,163,160,244,83,80,232,60,149,169,229,213,203,3,127,99,110,160,46,189,239,221,123,173,127,254,99,124,238,
249,109,186,59,39,191,54,39,195,12,150,201,217,187,7,226,181,20,16,118,135,98,103,246,228,91,199,113,110,253,247,21,45,38,91,59,182,246,206,54,182,190,131,19,139,219,123,74,134,178,158,26,186,162,100,
169,169,172,153,162,140,42,169,111,113,167,51,243,110,225,105,45,204,59,74,13,48,10,185,197,77,13,24,212,214,128,28,112,169,61,101,159,179,254,202,114,126,247,97,176,110,94,224,222,220,70,251,188,230,
43,88,227,52,25,168,86,98,1,37,154,133,168,123,66,138,154,156,116,104,191,149,215,243,13,202,252,210,218,123,195,102,246,158,23,11,182,123,235,170,33,192,86,238,104,246,219,76,54,182,253,217,123,158,158,
70,219,61,147,181,233,170,139,213,99,105,114,53,20,179,210,215,80,187,200,104,107,161,100,14,202,86,199,220,167,204,171,204,22,140,101,1,111,16,119,1,192,249,84,125,135,143,150,69,56,245,30,251,229,236,
245,199,180,188,196,182,144,206,211,108,147,150,240,157,169,169,74,156,198,244,193,32,16,65,252,74,125,122,174,255,0,231,5,31,222,124,175,254,29,21,67,83,77,149,248,147,134,198,73,80,24,168,165,129,59,
188,76,242,223,240,86,26,217,27,252,109,207,176,79,185,70,147,82,185,48,160,31,110,179,214,71,125,202,230,22,146,95,222,58,86,56,110,221,233,246,91,159,240,16,58,23,63,148,47,78,245,135,90,245,38,111,
231,135,96,136,34,220,125,193,37,118,197,233,122,122,168,5,94,67,107,244,246,217,204,213,97,241,88,29,157,67,105,42,42,55,31,101,238,58,10,140,142,65,160,79,45,69,225,66,222,52,62,198,62,217,114,156,242,
219,36,182,214,250,239,36,7,60,21,16,124,78,205,193,69,107,86,62,66,131,141,58,134,190,245,158,233,221,111,252,227,123,177,207,116,87,107,177,147,184,2,127,86,118,21,225,231,164,16,168,163,133,73,249,
245,105,85,29,185,188,119,246,235,167,217,152,61,251,178,58,159,43,87,11,207,73,182,170,104,211,122,239,249,45,27,72,32,203,36,115,71,182,176,117,198,49,127,180,89,42,42,16,240,90,252,123,150,227,143,
151,118,229,38,104,38,191,152,28,178,183,133,0,255,0,74,126,55,31,58,0,125,58,197,231,218,249,146,226,212,95,8,62,146,196,210,133,151,83,231,212,84,42,255,0,58,122,244,93,223,230,54,246,217,155,130,163,
3,146,221,187,95,116,79,141,174,150,134,175,29,187,118,205,94,202,170,157,224,153,162,144,65,158,197,212,100,49,212,210,18,164,255,0,148,66,20,126,77,189,156,166,211,176,95,218,165,212,155,101,213,156,
14,196,44,137,34,202,42,56,254,155,81,200,30,101,73,251,58,220,219,70,255,0,109,59,91,218,238,22,183,151,43,26,187,71,165,163,96,175,240,247,168,40,9,161,160,57,61,29,190,167,239,253,151,218,143,252,38,
153,167,192,111,8,105,22,178,175,107,101,222,17,85,45,49,30,170,252,21,116,46,244,59,135,19,126,68,244,206,214,91,107,85,250,123,13,238,188,189,119,182,196,151,145,200,151,27,91,154,44,209,229,107,252,
46,40,10,55,244,88,15,149,122,79,5,240,146,121,44,174,96,123,125,201,62,40,164,20,111,181,124,153,127,164,164,252,233,212,238,232,249,21,209,127,29,176,41,185,123,195,181,182,63,88,97,166,58,105,103,221,
217,250,60,101,78,65,239,167,197,138,198,51,190,83,45,54,174,52,83,67,43,95,241,236,43,119,127,101,98,186,238,238,82,49,243,57,63,96,226,127,33,208,155,102,229,237,243,152,110,62,151,99,218,167,186,152,
113,17,169,96,63,211,30,10,62,100,142,171,247,116,127,51,93,221,190,153,113,223,14,62,33,119,95,127,253,250,55,240,190,206,222,180,176,244,79,71,133,32,162,228,134,236,223,145,193,184,51,152,232,100,33,
155,236,49,146,121,80,29,13,123,123,42,253,243,123,121,69,217,182,107,137,193,224,236,60,56,254,221,77,146,63,33,208,218,63,111,246,189,172,52,156,233,206,150,59,121,79,138,8,201,186,186,255,0,75,225,
195,85,86,255,0,78,226,158,125,5,237,213,255,0,205,43,228,60,226,78,222,249,127,176,62,48,237,58,137,26,121,54,63,196,94,190,109,197,186,82,22,81,171,31,87,219,29,154,37,79,22,139,131,45,61,34,48,60,175,
189,126,233,230,75,202,125,118,239,29,180,126,107,10,234,111,247,163,143,231,249,116,176,115,31,181,187,16,43,177,114,85,214,235,114,5,60,93,198,95,14,63,180,65,14,126,192,88,138,113,234,30,71,249,84,
124,48,153,215,61,242,99,119,118,39,200,60,228,100,75,54,225,249,55,242,15,116,238,120,217,87,150,72,246,173,22,83,11,181,233,168,217,238,124,43,74,85,127,79,211,219,241,242,126,211,33,6,228,79,116,254,
178,57,63,200,83,166,31,222,62,116,133,76,91,15,208,109,54,254,75,103,109,20,103,229,222,202,206,72,245,174,122,16,240,155,147,249,102,252,97,163,142,131,98,81,116,94,204,147,31,165,96,167,235,61,129,
182,14,82,51,16,178,248,178,145,208,85,215,172,160,129,102,19,3,197,253,136,45,54,27,75,125,63,73,180,196,132,121,233,31,225,53,61,2,119,78,105,230,109,241,217,247,142,97,189,185,36,231,196,153,200,255,
0,121,173,63,151,73,253,197,252,208,190,53,225,213,198,221,193,118,62,250,158,61,90,2,165,69,61,39,228,3,102,109,1,88,142,44,182,246,117,30,213,122,226,128,128,191,47,246,58,15,17,18,158,237,32,252,233,
209,124,220,223,205,231,43,11,50,108,79,141,34,88,213,136,142,163,51,37,100,142,215,189,139,10,106,112,11,95,234,47,237,82,108,79,150,150,127,240,127,150,157,111,197,139,225,18,231,211,160,59,116,127,
53,159,151,121,116,63,221,46,158,216,27,122,70,96,148,241,84,193,43,77,35,219,209,18,45,69,76,78,210,55,214,192,18,127,167,187,254,235,219,163,211,227,94,40,36,210,154,150,164,250,122,159,203,61,56,162,
87,168,142,9,24,1,82,66,177,0,122,147,74,1,243,38,157,9,125,33,242,99,249,128,118,28,53,61,133,220,251,175,96,116,183,77,226,230,120,42,178,20,155,79,248,150,225,207,214,129,232,196,109,186,73,164,255,
0,45,200,72,108,2,71,125,39,151,40,62,166,210,108,123,78,220,144,201,184,69,43,221,75,79,14,221,15,235,73,232,72,201,141,15,169,26,136,224,60,250,69,104,247,251,196,210,218,109,11,30,132,4,203,112,230,
144,194,6,73,45,128,196,15,203,231,229,209,146,173,249,15,184,182,86,28,239,237,203,138,249,39,73,180,29,211,238,183,175,247,143,106,228,234,232,96,157,192,143,43,95,215,43,65,162,147,25,37,195,120,201,
140,170,159,213,249,247,89,221,75,77,103,251,163,103,105,163,90,189,180,110,77,204,107,253,38,86,45,81,231,196,143,49,209,174,223,203,118,183,179,65,21,183,51,95,9,38,52,142,226,104,89,44,229,127,224,
73,25,66,231,130,147,69,99,133,61,4,155,195,228,127,205,105,169,39,223,191,29,187,7,170,126,70,117,162,198,39,169,160,93,179,30,27,176,54,196,23,212,98,220,155,113,36,146,107,68,159,170,120,181,67,127,
237,123,73,105,182,108,251,159,233,217,200,209,93,211,251,41,88,2,126,72,248,86,251,13,27,229,211,91,213,134,247,203,18,152,121,131,110,116,136,31,237,80,106,79,181,184,145,95,149,71,72,173,189,252,196,
254,99,64,4,153,190,133,217,185,228,10,117,174,58,25,149,201,91,137,44,168,178,88,131,245,250,216,251,102,93,145,99,149,161,145,164,73,135,21,34,135,246,122,124,250,72,183,86,210,70,178,173,194,152,143,
2,8,167,237,175,30,132,140,119,243,58,203,198,86,30,200,248,179,83,26,242,38,108,122,70,204,159,134,96,38,128,49,110,47,107,251,74,219,67,37,64,184,207,207,167,4,136,227,181,193,7,243,233,117,143,254,
97,191,10,115,172,33,222,56,93,227,214,149,114,0,146,9,232,107,163,165,141,137,0,179,181,51,24,10,255,0,200,38,255,0,159,117,22,123,154,252,15,169,126,218,255,0,35,214,154,24,91,184,162,150,251,5,127,
111,30,158,166,235,15,229,153,242,174,154,74,89,223,160,251,30,162,188,17,226,221,56,13,187,69,186,35,145,141,195,211,230,99,167,199,103,41,170,213,143,18,71,48,144,31,207,178,59,237,146,206,228,55,239,
13,142,23,175,19,160,3,246,234,90,31,231,208,151,104,230,206,108,216,89,14,203,204,247,214,224,112,11,51,148,251,10,49,40,71,200,138,116,142,200,127,45,30,204,233,196,77,193,240,111,229,255,0,120,252,
124,16,90,170,143,97,86,238,105,251,159,164,50,5,61,113,83,84,236,253,235,81,146,173,164,199,126,52,82,85,198,21,77,133,135,176,219,242,180,81,18,251,54,233,113,104,255,0,194,73,146,51,246,131,220,7,237,
232,115,23,186,99,115,30,23,61,114,118,221,187,70,112,102,69,22,183,67,212,137,35,1,9,243,37,148,215,167,189,173,252,195,190,92,124,106,172,131,110,124,246,248,219,83,186,118,109,28,201,73,63,201,255,
0,139,212,117,219,171,108,44,2,86,95,227,59,239,169,165,15,187,182,156,33,72,50,154,31,189,138,48,9,211,111,109,181,206,253,180,138,238,251,119,141,106,63,209,160,238,20,245,100,25,95,159,90,126,84,228,
94,106,213,39,34,243,71,210,238,108,43,244,27,133,34,146,191,195,13,198,34,151,229,93,4,227,171,113,234,78,236,234,126,248,218,84,91,235,167,123,3,107,246,30,214,174,84,49,229,182,198,86,155,37,29,60,
140,46,212,153,26,120,156,85,226,235,225,55,18,65,81,28,115,70,192,134,80,71,179,123,75,219,91,232,132,214,147,172,145,250,131,195,228,71,16,126,222,163,157,219,102,221,118,43,183,176,222,54,249,109,238,
199,225,117,34,163,213,79,6,95,233,41,32,250,244,41,123,85,209,103,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,213,113,127,55,60,61,38,111,249,112,252,176,165,172,
88,216,82,117,186,230,105,204,159,238,186,236,14,225,194,102,168,93,15,213,100,251,170,5,0,142,121,183,178,30,103,80,219,22,225,95,37,7,246,48,234,70,246,142,118,183,247,43,147,157,13,9,188,85,252,152,
50,159,228,122,213,255,0,189,243,25,74,189,219,46,51,15,87,133,198,213,229,182,142,206,171,170,203,231,214,174,170,135,21,44,152,106,99,37,103,240,108,122,181,126,102,168,55,41,78,173,26,51,254,183,85,
231,222,52,111,49,218,73,187,60,151,51,50,194,21,106,0,171,28,14,208,124,190,103,174,203,242,2,239,105,202,182,207,177,109,235,62,226,183,18,34,151,112,145,198,60,153,201,201,167,146,168,169,232,4,199,
117,7,64,99,117,229,119,101,14,246,239,45,209,91,91,54,90,177,183,238,94,93,189,176,163,204,84,36,113,84,85,99,250,247,109,207,79,143,142,41,35,130,53,11,60,179,57,68,93,76,79,183,91,127,130,8,146,59,
43,60,168,160,45,228,62,207,63,158,122,114,15,105,247,221,206,242,226,247,153,55,250,25,31,84,130,10,130,199,207,184,254,204,99,165,107,100,241,20,49,45,62,223,216,157,115,181,168,99,26,98,164,192,236,
93,187,78,138,128,17,102,158,124,125,69,92,188,113,234,144,251,40,155,119,220,103,53,107,146,7,160,192,232,117,183,123,103,201,182,17,149,27,66,202,252,75,72,75,18,125,125,58,113,217,91,80,238,76,141,
101,101,53,5,5,43,4,38,166,76,118,62,151,30,179,5,7,79,148,81,197,10,16,8,227,143,175,186,106,158,232,82,89,89,128,28,14,127,195,211,91,172,155,39,43,13,59,117,132,48,72,248,58,6,146,126,218,96,244,130,
174,104,49,221,142,172,204,171,6,7,21,185,178,181,46,197,172,177,227,48,25,42,151,144,146,56,210,83,253,191,180,87,224,139,55,141,126,39,116,81,249,184,29,38,222,47,188,109,134,234,102,60,98,255,0,13,
7,91,106,127,38,29,173,85,180,255,0,150,119,197,90,74,216,76,21,89,141,143,93,186,228,70,5,88,141,213,185,51,89,216,93,131,0,111,36,21,170,223,236,125,229,183,42,196,98,216,172,84,142,32,159,218,77,63,
151,92,64,247,150,241,47,189,203,230,201,145,170,162,231,79,251,194,170,159,230,58,180,63,98,30,163,30,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,
235,255,208,223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,213,112,127,53,126,
248,236,143,143,159,16,55,38,233,234,140,207,247,79,121,110,205,235,176,122,186,147,125,248,96,153,182,5,31,96,231,226,193,215,238,248,13,88,52,48,87,99,233,228,49,210,203,56,48,197,85,60,108,195,129,
236,63,204,247,183,54,27,84,146,218,154,76,204,20,31,49,90,228,122,19,74,3,234,122,147,189,160,229,189,175,154,185,239,106,218,247,133,213,183,128,242,50,86,129,252,49,93,38,153,167,153,3,36,3,213,19,
226,126,70,124,161,248,219,176,55,150,3,27,217,152,15,152,221,7,217,219,83,37,139,221,59,39,228,206,231,203,230,247,38,200,203,228,168,170,177,155,146,158,167,50,244,245,27,182,133,98,119,102,170,197,
86,211,79,65,58,128,244,114,196,8,30,225,123,78,125,190,219,224,154,11,253,55,22,115,33,20,36,177,83,144,81,213,136,117,96,120,241,86,226,167,172,207,221,253,135,229,110,112,221,236,215,98,180,151,96,
230,171,73,192,80,138,22,43,132,4,24,166,134,68,30,19,171,129,85,96,85,211,131,134,234,150,242,121,12,156,57,13,169,150,218,251,147,53,140,220,155,27,31,179,83,110,111,156,85,68,152,205,197,73,184,182,
52,113,255,0,1,221,184,154,134,119,154,146,183,25,52,97,32,89,89,140,212,107,226,154,225,219,216,27,247,196,233,185,29,202,221,116,49,96,64,173,48,40,51,79,51,74,215,200,245,155,207,237,141,141,247,33,
67,202,27,234,164,242,104,112,245,21,95,212,169,104,232,124,133,104,72,243,200,167,87,231,211,127,240,160,173,213,131,235,154,125,163,242,31,227,94,95,178,187,15,29,137,24,201,183,167,94,231,118,222,19,
103,239,176,176,26,102,200,110,60,46,232,150,41,54,173,93,124,98,245,144,70,42,233,181,51,24,238,140,20,76,123,127,186,86,143,104,22,250,220,125,64,90,28,210,191,104,161,255,0,103,208,112,235,158,60,219,
247,41,230,171,61,254,70,229,141,205,70,210,210,106,77,97,153,227,21,173,1,79,138,159,132,224,254,121,234,171,83,176,224,147,160,59,31,25,246,116,88,44,94,242,222,57,140,150,217,218,24,201,164,155,17,
181,168,50,251,151,35,184,40,246,214,21,164,72,154,124,46,217,167,175,251,74,105,74,32,101,66,81,85,8,30,226,125,219,118,134,245,174,252,5,164,44,192,40,251,9,53,167,165,13,7,89,161,237,239,35,238,123,
14,227,202,240,110,50,25,47,237,97,62,44,132,100,246,5,238,57,203,17,168,142,151,127,203,191,230,21,71,195,222,223,219,219,202,151,100,231,187,35,39,189,54,151,98,116,102,55,100,224,39,161,160,168,207,
102,86,183,21,216,123,39,248,174,99,32,223,107,131,192,226,103,142,173,170,107,89,100,120,33,145,180,163,150,10,69,28,141,189,29,154,123,217,217,53,197,225,240,173,50,105,67,242,21,31,111,167,81,39,222,
147,219,105,57,234,125,178,202,206,104,224,184,241,214,66,237,82,2,229,31,72,25,102,53,4,12,2,120,145,199,173,161,62,4,127,50,141,179,243,47,114,118,47,84,110,126,188,201,244,207,124,245,92,81,100,183,
54,194,173,203,197,185,112,185,157,181,81,90,248,232,119,54,207,220,241,208,226,219,43,69,75,144,95,183,171,138,90,88,38,166,149,146,225,131,131,238,101,229,222,105,181,230,15,30,52,140,199,115,31,21,
62,159,152,7,242,35,174,126,251,169,236,246,243,237,139,237,215,51,222,71,119,179,93,143,211,153,5,59,169,93,44,181,52,52,200,32,144,104,125,58,179,163,123,113,245,254,158,197,61,67,253,106,171,218,24,
26,255,0,143,31,44,190,108,244,70,67,207,5,55,120,73,154,238,237,157,44,203,42,174,231,235,222,205,165,198,197,155,159,23,52,182,90,234,189,135,190,176,255,0,105,90,23,83,69,28,232,214,10,65,48,71,56,
218,79,183,95,238,44,128,152,100,13,95,244,146,16,213,255,0,106,194,135,174,140,251,35,186,217,115,95,38,114,60,218,151,247,142,203,120,134,152,168,120,181,2,8,28,60,72,155,80,245,161,166,107,209,115,
254,78,242,238,60,47,243,5,234,236,46,54,162,122,96,221,109,242,23,5,187,96,93,65,107,118,126,39,39,183,50,24,42,106,229,253,50,38,59,115,205,35,211,150,253,6,87,11,96,79,187,251,122,210,46,247,34,161,
253,50,13,105,194,154,106,127,152,29,9,254,250,241,237,179,114,141,189,225,141,126,161,174,97,100,111,62,229,53,167,158,71,31,90,14,149,223,206,43,180,19,57,243,91,178,240,219,111,41,29,67,236,30,156,
235,29,129,153,106,105,86,101,162,204,230,178,185,77,237,95,138,62,54,211,29,85,62,56,193,36,201,250,148,186,220,115,237,191,115,46,193,221,35,72,223,224,11,90,121,17,154,127,49,213,190,228,60,164,215,
60,159,190,238,183,118,231,195,150,73,52,98,149,170,132,174,127,58,116,132,248,211,243,123,49,215,255,0,25,250,195,164,246,174,203,222,155,219,229,38,201,196,55,89,245,107,102,113,99,253,11,237,221,175,
144,203,76,105,55,253,14,231,165,150,60,110,31,31,79,139,173,146,167,49,61,78,156,154,188,38,157,44,8,62,228,205,155,221,11,43,14,69,180,217,109,96,72,174,144,81,192,192,184,53,168,105,100,173,116,173,
79,233,140,87,61,64,92,233,247,112,220,174,253,227,230,78,102,221,238,73,229,233,110,90,69,114,42,246,235,74,20,138,34,59,164,118,3,75,231,7,242,233,95,209,95,35,123,134,147,190,179,91,71,124,215,108,
77,211,187,54,102,38,151,177,240,253,157,214,144,101,241,152,188,173,45,54,226,24,122,138,124,238,223,204,201,81,87,141,90,234,212,99,67,80,36,241,215,83,6,112,160,114,69,92,131,238,0,231,89,239,118,61,
235,108,182,142,221,80,248,115,67,31,134,81,171,64,78,78,165,60,13,73,198,105,208,107,221,127,102,87,144,118,125,175,127,229,253,230,250,105,110,71,234,217,221,72,36,47,25,93,101,0,1,68,114,5,202,232,
0,169,162,154,249,90,167,200,253,163,128,221,217,109,135,220,248,138,80,54,159,110,227,168,102,201,165,61,180,227,55,90,105,167,201,211,48,23,17,180,181,0,220,27,92,216,251,29,216,137,102,219,175,182,
105,71,251,177,177,145,164,74,126,36,225,42,138,241,160,1,214,153,165,122,129,54,173,205,246,125,210,43,161,39,248,141,202,36,14,79,225,63,21,180,135,228,65,49,183,161,167,72,204,198,201,221,29,45,246,
149,56,236,149,126,67,110,151,90,252,125,126,62,173,232,179,219,74,186,88,217,70,67,110,100,148,153,113,149,161,28,134,140,94,10,143,163,161,250,251,73,183,238,82,91,153,124,48,173,12,170,86,72,218,165,
36,82,41,70,30,68,126,22,25,83,145,208,131,115,219,246,206,111,142,56,239,35,240,119,72,94,177,202,160,107,82,15,31,233,46,59,144,224,138,142,153,190,51,252,94,235,89,119,118,75,120,109,222,188,203,124,
140,239,26,154,214,204,215,247,135,120,238,186,205,243,89,136,199,228,229,150,170,150,42,172,214,238,25,95,238,110,66,138,254,21,198,227,41,213,217,81,93,95,73,191,180,208,242,55,42,109,144,195,189,180,
237,29,172,197,168,103,95,30,228,184,57,88,195,29,37,5,113,33,160,245,238,232,53,204,190,226,115,237,204,211,242,149,203,197,20,22,193,71,129,98,22,214,208,169,24,121,132,125,237,35,1,82,140,199,137,166,
58,61,221,149,93,242,75,174,54,229,94,67,21,210,120,13,237,146,167,129,222,149,176,59,179,239,32,5,16,144,36,199,228,82,26,229,41,126,52,130,167,241,237,98,88,236,151,238,5,159,48,21,115,141,19,175,135,
95,177,193,43,251,72,167,64,164,185,188,182,204,251,77,83,248,161,58,255,0,106,208,55,248,107,213,47,246,255,0,203,143,154,251,130,44,242,239,28,198,27,227,174,210,193,9,37,205,100,247,5,100,88,10,92,
109,37,217,3,75,87,38,151,144,31,162,132,212,204,126,128,159,119,191,218,173,118,43,102,190,220,199,135,102,188,101,38,177,255,0,189,173,70,125,6,122,52,217,245,243,5,236,91,102,201,3,221,110,114,30,216,
81,79,136,127,218,154,127,62,30,125,17,44,38,111,115,247,254,97,233,122,247,27,242,59,229,181,105,102,242,231,182,126,46,167,101,117,74,207,174,196,62,255,0,223,211,99,40,234,168,213,255,0,92,180,208,
200,0,250,95,216,58,78,124,219,75,24,246,45,166,123,194,63,18,128,145,255,0,189,54,127,60,117,44,143,104,119,109,182,36,184,231,78,99,219,54,68,57,240,164,147,199,186,167,252,208,134,180,111,42,22,227,
209,215,235,79,229,147,243,135,127,52,82,196,191,20,254,54,96,28,3,37,126,74,163,115,119,231,97,211,43,216,128,41,85,48,155,89,170,148,27,18,28,174,191,161,32,95,217,100,219,247,58,94,138,66,44,236,162,
175,149,100,112,63,227,181,249,227,167,22,215,217,173,149,79,142,187,230,245,118,60,170,150,80,31,200,7,150,135,210,189,10,123,183,249,73,228,176,20,19,84,246,231,206,46,236,220,235,12,6,106,154,62,190,
192,108,190,161,219,16,32,225,130,77,67,69,85,149,68,111,162,234,152,159,160,23,62,208,126,239,223,247,41,18,43,174,102,189,150,102,52,9,23,109,79,160,3,39,242,20,232,194,219,158,249,79,109,82,251,47,
181,187,45,180,75,147,37,201,146,229,135,204,153,14,159,229,158,189,215,127,203,103,226,13,62,38,74,189,215,180,62,68,246,237,109,83,44,24,186,173,239,242,3,121,109,29,175,89,52,134,201,52,249,57,242,
120,42,122,168,152,253,69,60,19,51,11,217,79,179,216,189,184,129,14,174,99,222,165,182,142,149,43,36,237,36,223,148,81,212,131,254,152,129,235,209,69,231,189,188,203,59,180,60,163,179,237,236,224,228,
219,237,208,36,107,246,200,234,104,62,206,140,63,94,255,0,47,175,135,253,85,185,225,222,248,158,162,218,27,151,122,227,99,83,140,218,219,127,115,110,90,173,141,180,100,151,214,181,155,207,176,55,214,106,
85,200,212,196,63,80,81,19,1,125,8,69,189,138,182,158,91,229,253,186,72,231,229,205,161,227,146,184,188,187,213,52,196,255,0,203,188,29,193,79,161,210,116,249,176,232,11,204,62,226,115,230,251,107,54,
223,205,220,208,207,102,77,13,157,168,138,8,207,202,105,81,85,138,250,141,64,31,37,60,122,29,119,246,254,248,173,180,113,216,250,206,237,236,154,109,199,154,199,188,48,96,118,143,86,81,179,109,93,147,
5,68,134,20,160,219,200,176,69,29,70,78,89,24,6,173,99,229,119,230,53,83,234,41,185,135,120,181,177,18,91,54,254,155,117,196,236,17,231,150,80,215,211,151,237,210,186,3,188,85,38,154,35,1,128,63,23,74,
185,43,147,249,215,152,164,91,141,143,145,103,220,182,232,80,200,177,8,89,44,34,17,2,229,228,50,24,227,148,32,21,38,66,80,210,186,107,146,94,119,71,199,8,122,31,229,135,94,246,223,78,98,59,7,113,245,47,
98,116,198,243,222,155,159,107,238,236,198,103,62,149,217,88,177,18,213,140,61,100,25,201,170,196,18,100,41,38,73,26,41,135,237,50,157,63,143,112,198,219,201,146,114,247,186,155,20,54,23,18,165,177,105,
11,201,168,177,12,3,106,239,20,45,171,20,12,78,120,245,148,23,254,243,65,238,47,221,163,155,246,190,107,183,176,254,176,89,221,219,37,176,72,34,131,244,25,151,44,17,64,11,25,174,162,60,184,112,232,159,
96,251,71,226,222,251,221,35,115,96,178,91,255,0,225,207,103,65,93,47,219,238,173,163,45,70,91,100,181,98,204,224,190,83,17,3,199,52,9,228,22,145,99,38,224,159,73,250,123,147,118,222,126,229,110,101,185,
158,202,120,110,35,187,73,52,86,88,130,213,129,32,19,36,96,199,82,71,226,10,126,125,7,247,239,101,253,227,246,243,102,178,148,254,236,230,30,89,154,221,101,240,163,151,92,138,133,3,145,26,76,124,114,161,
72,53,67,32,244,3,135,83,251,31,177,54,126,123,49,14,203,239,122,236,63,101,211,213,64,43,48,221,219,241,167,47,146,218,27,186,172,126,159,226,57,12,109,58,209,83,201,152,84,93,115,36,144,199,43,144,125,
103,235,236,93,186,91,77,61,189,182,221,184,129,123,104,65,49,131,33,89,162,30,97,38,140,150,83,232,9,101,167,151,81,62,201,177,89,220,174,227,204,92,169,4,251,38,225,19,233,158,27,184,149,237,36,36,87,
41,40,10,233,228,72,1,150,180,61,8,59,35,227,45,14,111,110,211,118,15,89,124,191,238,185,58,160,205,21,54,83,57,57,192,246,68,155,57,228,149,105,192,223,91,39,123,99,98,207,99,169,169,228,112,178,205,
79,87,52,42,57,36,14,125,144,69,203,51,221,191,131,202,188,217,127,5,245,9,22,215,69,36,47,79,40,164,33,67,154,126,19,70,63,62,144,239,124,200,54,89,218,219,159,253,177,217,156,2,63,198,109,68,182,226,
135,241,48,140,144,23,250,64,16,6,105,208,185,218,191,3,254,64,237,156,9,204,99,119,103,198,207,144,216,99,70,42,22,159,122,236,140,223,81,110,90,218,105,99,242,196,212,249,189,173,145,220,219,126,127,
52,44,25,100,52,209,169,189,237,236,141,55,126,109,179,98,173,45,165,201,92,17,34,180,47,80,104,69,65,34,163,129,192,207,77,197,111,237,230,236,224,27,61,215,108,102,161,6,25,82,234,33,92,215,76,138,143,
79,58,106,252,250,169,206,201,232,204,5,26,85,101,187,35,227,183,126,124,124,154,146,70,243,118,103,82,35,119,71,92,208,72,140,127,202,171,106,246,90,83,238,108,93,39,246,139,205,64,66,47,212,251,48,135,
159,90,218,131,124,217,103,130,63,227,74,77,31,237,81,81,252,250,48,151,219,53,190,32,242,159,57,109,247,242,30,16,76,77,157,193,249,1,33,49,177,251,27,61,72,235,78,224,249,201,209,216,87,221,255,0,23,
62,71,224,126,75,117,118,49,139,86,225,169,242,141,184,42,241,209,195,204,148,89,156,13,109,179,184,90,148,140,89,150,104,99,101,63,235,123,20,89,93,242,239,48,70,101,178,158,55,245,40,69,71,218,184,32,
143,58,142,128,123,222,201,191,114,213,207,209,239,251,76,246,119,39,128,149,40,173,243,73,5,81,129,242,163,103,171,95,248,109,252,219,58,135,228,214,70,147,167,251,207,111,63,83,247,84,191,228,34,131,
42,86,12,22,228,172,30,137,6,14,190,99,27,65,85,35,125,32,147,234,126,135,241,237,61,222,209,61,149,46,45,31,84,95,46,138,245,164,224,199,34,103,204,31,240,255,0,171,61,15,61,215,240,142,109,129,95,93,
242,155,225,182,245,61,19,223,20,8,107,243,57,124,46,52,214,117,159,105,227,96,127,51,237,158,242,216,20,45,21,14,228,196,85,21,208,50,176,71,30,94,128,177,150,57,77,138,251,5,110,91,28,119,146,139,221,
181,150,207,119,227,172,10,71,39,244,101,65,140,255,0,16,21,30,117,234,66,216,57,226,91,123,68,229,206,108,182,125,215,148,142,4,108,213,184,181,175,250,37,156,205,220,133,120,152,152,152,223,133,58,53,
95,10,126,115,109,207,148,148,187,131,175,247,126,30,159,171,190,77,245,117,37,1,237,206,154,155,39,30,74,58,106,124,128,43,140,223,123,3,54,21,33,222,93,103,185,130,121,104,178,16,106,104,75,120,42,22,
57,86,197,54,223,185,60,242,207,183,223,64,97,221,160,52,146,51,252,153,79,226,67,228,71,73,185,171,148,142,201,13,142,245,180,221,253,111,40,223,84,219,93,1,74,211,226,138,85,255,0,67,158,62,14,135,211,
82,212,116,126,189,155,116,11,235,222,253,215,186,43,191,43,62,93,244,255,0,195,253,129,6,246,237,44,149,125,78,75,59,144,93,191,215,221,119,181,232,206,107,176,251,63,119,78,63,200,246,182,199,219,145,
58,212,100,235,229,36,52,178,182,138,122,88,175,36,210,34,253,75,119,61,214,215,106,135,197,184,98,88,225,84,124,76,125,0,255,0,47,1,208,171,148,121,55,124,231,93,209,118,189,146,219,83,1,170,73,27,17,
196,158,111,35,121,15,65,146,78,0,61,81,206,247,254,119,63,42,241,27,130,73,113,31,20,58,131,11,132,138,118,97,178,247,95,118,207,144,236,164,164,242,93,33,205,203,182,48,117,123,87,5,152,240,240,244,
254,121,252,110,108,88,218,222,227,75,223,116,18,214,228,196,109,82,128,156,84,177,31,34,69,5,71,236,235,50,185,107,238,67,187,111,251,95,214,14,98,117,144,142,214,49,4,141,143,244,67,182,178,191,50,22,
190,67,171,57,248,29,252,207,250,87,230,251,230,54,76,56,204,167,80,119,254,210,164,74,205,219,210,59,218,174,142,76,209,199,179,21,27,135,100,230,105,196,52,27,231,108,49,3,85,77,42,172,144,147,105,99,
65,98,71,27,7,52,109,251,244,74,97,112,179,145,93,53,227,254,148,249,211,204,16,8,244,235,26,189,214,246,87,156,125,164,220,154,215,126,182,241,44,11,81,39,64,116,31,64,195,58,9,242,169,163,121,19,208,
91,252,231,123,111,19,129,248,199,142,248,249,77,89,17,223,31,41,183,174,3,173,241,52,34,104,86,92,126,203,199,100,169,55,31,100,110,234,216,221,139,195,135,219,251,99,27,32,146,98,186,60,211,70,183,187,
123,77,206,87,209,219,109,77,110,92,9,101,32,125,138,50,198,158,148,20,251,79,70,62,192,242,205,222,249,207,182,123,140,81,19,105,183,3,51,26,84,23,248,99,79,181,152,240,227,64,79,90,199,239,45,209,75,
190,123,35,119,238,60,97,45,131,251,213,197,97,28,11,44,184,204,74,125,157,52,145,155,216,43,172,119,22,227,222,52,110,215,11,61,220,206,6,11,99,242,235,181,126,222,109,147,109,92,185,103,111,48,164,165,
117,176,254,147,122,254,84,233,184,143,246,246,224,253,5,239,254,240,73,246,87,208,244,49,0,129,231,212,74,153,13,149,22,250,216,168,0,126,89,152,112,127,63,239,30,236,171,83,83,192,116,212,174,34,141,
156,154,0,58,62,61,55,177,6,221,235,28,158,232,202,197,226,106,138,26,137,162,242,46,147,163,198,196,94,252,92,147,199,177,53,133,166,155,57,174,100,20,199,88,189,207,28,195,251,203,153,97,219,237,156,
149,89,0,52,63,183,170,204,223,181,181,85,208,246,214,67,22,30,92,133,118,216,168,217,88,52,139,153,38,220,61,141,148,164,217,248,136,34,210,46,210,188,185,50,64,28,155,31,100,203,9,187,189,218,237,83,
58,238,85,191,36,171,31,240,116,54,230,203,216,246,142,77,186,158,229,192,81,30,79,201,84,177,254,67,173,252,62,62,245,236,61,77,209,93,55,214,16,192,180,195,175,186,191,98,108,249,33,80,23,69,70,223,
219,56,220,109,81,32,1,234,122,170,119,99,254,36,251,204,11,24,126,158,202,214,10,80,164,106,63,48,51,252,250,225,102,251,126,119,77,235,119,220,139,84,220,92,203,39,251,219,150,31,200,244,47,251,85,209,
87,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,255,209,223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,
94,247,238,189,215,189,251,175,117,239,126,235,221,98,158,120,105,96,154,166,162,68,134,158,158,41,39,158,105,24,44,113,67,10,25,37,146,70,60,42,70,138,73,63,128,61,232,144,1,36,224,117,181,5,136,85,21,
98,113,214,181,189,217,255,0,10,9,172,218,123,254,182,131,168,126,47,77,190,186,178,131,43,95,142,162,223,123,195,176,147,102,228,183,109,54,43,35,87,139,170,207,96,118,253,30,7,56,216,220,45,101,109,
20,171,68,249,9,34,146,170,52,242,132,8,192,251,140,119,79,115,44,172,47,26,218,43,93,106,60,201,32,145,92,26,0,104,15,17,231,242,235,49,185,43,238,121,204,252,215,203,201,188,203,189,199,4,238,129,132,
106,154,244,146,1,10,73,117,44,64,43,171,64,32,19,164,154,142,172,95,226,191,205,175,140,159,204,239,174,55,191,86,110,109,136,152,237,192,118,237,49,236,206,128,237,8,113,121,118,200,237,76,180,130,42,
109,201,130,172,162,154,124,86,239,218,83,87,69,161,43,232,217,101,163,170,69,89,86,25,66,92,81,179,239,251,79,52,218,73,26,0,73,29,200,217,199,168,224,127,144,97,232,58,132,249,243,219,110,118,246,111,
123,180,158,234,70,74,57,48,220,197,85,26,135,145,174,81,233,157,39,136,173,9,21,232,180,246,215,242,42,233,205,195,89,89,145,233,30,239,237,62,160,90,148,148,38,211,220,49,226,187,139,97,192,111,251,
52,148,184,237,226,35,220,84,88,216,82,200,34,92,155,105,81,193,31,79,101,59,143,183,219,77,235,23,70,210,223,210,1,191,97,193,254,103,161,223,42,253,233,61,193,229,216,225,134,233,99,186,141,41,70,12,
209,62,61,74,213,73,62,186,7,84,247,242,175,249,77,124,135,248,175,181,51,29,181,186,171,182,103,103,244,230,222,211,46,243,222,29,53,139,206,96,55,183,95,224,217,213,38,223,57,190,178,205,85,101,241,
219,135,107,97,174,37,201,199,142,171,90,170,122,112,210,34,50,171,90,63,222,125,183,150,198,57,46,98,101,240,84,241,92,210,191,137,129,21,160,243,161,61,101,103,183,31,124,145,204,27,141,158,203,184,
194,241,95,202,64,65,49,82,178,55,251,236,74,160,21,102,224,186,214,132,226,163,29,21,140,63,78,212,195,85,149,218,153,163,65,87,146,198,173,53,69,54,79,25,32,170,198,102,176,249,58,56,171,240,187,131,
19,47,62,124,110,99,29,83,28,241,55,212,6,210,121,7,220,103,54,223,53,189,204,246,147,15,212,67,229,230,15,2,62,68,117,150,135,157,97,189,179,176,222,236,93,190,146,101,174,147,197,29,73,14,141,232,85,
129,31,179,160,103,176,112,217,29,189,44,56,105,228,111,178,166,105,62,221,45,97,114,127,60,15,167,251,197,253,162,104,202,49,66,56,116,58,216,174,237,119,20,123,196,95,213,112,43,251,58,104,235,204,181,
6,2,122,204,251,228,35,160,207,109,92,198,71,47,183,214,86,2,89,37,205,236,204,158,53,166,166,191,38,88,171,113,212,232,126,167,247,63,199,217,213,132,235,29,142,228,165,136,149,163,90,127,189,117,28,
115,190,205,38,225,206,92,152,69,190,187,38,153,210,95,64,6,115,232,8,39,171,30,254,85,61,187,182,58,135,229,206,87,182,123,51,43,185,114,121,217,62,60,110,122,218,93,169,181,48,89,93,211,188,183,254,
225,236,158,194,197,207,73,138,199,97,241,176,202,77,53,21,22,5,234,164,158,161,224,166,167,184,103,145,86,228,15,253,182,152,65,119,115,116,226,73,37,96,66,170,130,204,237,129,64,7,175,26,156,15,51,214,
31,253,238,236,134,225,183,109,187,22,219,28,48,217,65,116,186,164,145,214,56,161,142,52,97,86,102,35,36,181,0,0,177,244,207,87,157,185,255,0,153,63,110,229,178,66,151,174,250,71,101,109,154,72,228,107,
197,217,123,238,109,205,187,170,34,33,124,95,113,180,186,174,155,49,143,193,203,114,117,9,179,19,48,250,105,4,31,115,172,86,60,209,118,4,137,182,69,107,1,243,158,78,239,247,136,234,71,230,122,192,41,45,
121,31,111,5,46,249,142,230,246,231,210,210,10,70,15,252,213,152,174,161,254,208,124,143,85,251,243,55,47,242,79,229,46,63,101,110,138,188,31,80,237,174,209,234,28,189,94,239,234,124,238,27,19,185,233,
183,92,241,79,70,208,110,174,179,168,138,174,174,105,114,123,71,177,49,136,41,42,99,168,137,150,41,150,41,133,157,47,237,173,195,219,158,96,230,59,105,221,39,182,150,88,81,152,105,70,10,104,166,177,180,
142,66,128,124,181,112,106,98,167,161,151,183,254,239,114,175,182,155,204,50,197,111,184,174,223,116,233,28,202,242,70,65,171,118,204,35,64,88,180,100,150,197,42,186,133,105,213,62,108,238,233,236,142,
155,236,92,31,124,116,54,241,202,245,158,226,205,224,55,125,6,31,115,85,224,48,123,132,226,240,251,170,177,105,183,199,95,238,92,78,228,11,142,76,222,212,220,248,178,145,85,106,87,137,226,87,177,13,239,
28,109,55,91,158,90,190,113,11,233,184,161,94,21,63,195,138,252,133,15,204,99,174,176,115,47,183,60,161,239,191,41,108,247,155,173,194,197,107,8,140,202,129,138,13,72,42,174,8,56,14,166,180,249,250,244,
93,43,251,72,102,119,70,126,83,184,183,47,112,246,22,234,220,25,45,207,188,50,88,106,44,159,97,111,45,213,187,179,18,134,200,102,183,20,251,122,138,166,138,10,185,82,37,134,8,21,146,26,122,116,88,208,
0,61,160,189,143,118,223,102,38,43,105,25,137,169,102,193,36,253,181,39,161,166,199,188,251,91,237,39,47,67,177,90,238,240,91,216,196,160,98,128,80,112,2,164,10,126,103,214,189,24,94,186,248,189,243,167,
124,134,203,245,175,196,110,232,132,213,210,187,224,114,123,162,143,25,177,176,16,86,213,58,172,121,138,252,126,228,202,83,26,248,104,224,45,34,68,240,178,73,46,157,106,202,8,246,111,183,123,121,204,147,
180,82,92,88,72,97,168,197,10,131,249,181,63,111,80,239,61,125,234,189,159,134,210,246,195,107,230,75,127,173,42,65,112,162,86,7,229,225,134,166,120,228,17,228,107,213,167,236,159,142,223,47,186,171,175,
106,54,119,87,252,1,235,205,189,155,220,18,195,148,236,62,211,238,79,152,27,103,41,217,157,139,184,18,21,73,115,59,154,178,151,19,29,21,37,53,57,184,164,199,82,44,116,116,80,218,56,215,139,153,167,96,
135,126,229,251,99,111,99,202,209,105,106,106,45,40,212,212,245,35,0,122,1,251,122,192,205,255,0,157,57,55,153,247,166,222,249,151,221,43,185,217,107,225,199,14,222,226,40,212,146,104,129,154,181,53,163,
49,169,110,133,236,38,233,254,100,155,111,167,107,58,127,61,241,99,227,38,232,197,255,0,23,124,206,26,186,151,229,110,38,28,166,6,173,138,151,17,35,98,36,134,72,221,148,144,3,41,5,175,253,44,34,27,207,
60,45,252,59,148,124,183,16,153,64,20,18,252,84,245,207,152,193,245,29,2,46,237,189,148,187,158,66,57,227,112,72,36,82,172,173,99,81,66,106,52,209,177,67,66,190,148,233,3,157,223,127,204,82,171,23,30,
35,57,240,251,13,156,164,80,138,255,0,220,207,145,187,31,55,51,164,96,42,233,167,200,37,30,182,95,168,4,242,125,191,109,189,111,240,93,71,53,247,36,187,219,7,171,36,115,12,142,58,115,90,3,195,236,233,
107,199,237,132,150,183,11,180,251,162,182,251,145,136,170,73,61,140,148,86,165,3,144,132,212,142,63,54,232,97,199,252,238,238,206,160,197,108,189,171,69,252,190,126,88,245,230,211,219,211,67,91,186,234,
246,214,43,104,118,109,86,238,202,184,83,144,203,229,50,27,79,42,103,155,88,4,70,154,61,10,21,69,128,247,93,195,156,119,29,194,230,107,189,231,149,239,163,106,105,69,141,67,71,26,15,133,84,10,80,15,63,
94,61,21,108,158,218,114,132,118,147,165,135,186,59,45,221,228,149,37,229,121,32,119,115,241,51,120,139,197,142,126,93,42,62,72,127,52,223,140,221,149,182,240,114,71,185,187,135,163,247,62,50,85,92,134,
3,182,250,147,177,54,5,236,163,83,156,227,226,39,194,171,65,40,34,237,80,18,252,234,183,191,114,223,53,114,194,238,182,177,111,230,75,123,38,144,7,241,81,148,105,62,164,3,143,94,181,39,181,252,247,99,
182,111,79,203,246,246,91,133,247,211,177,133,173,110,96,152,235,242,162,23,21,52,173,1,31,151,64,188,191,56,186,229,246,108,51,238,13,235,213,253,235,176,171,106,98,162,168,162,204,46,223,223,146,210,
125,210,122,67,202,146,157,193,65,27,40,34,247,178,159,199,179,173,247,158,249,115,99,183,123,219,75,165,142,197,165,41,91,103,50,71,78,32,188,77,168,21,35,207,79,30,141,121,103,216,174,99,230,251,235,
125,189,236,238,151,124,22,194,90,92,32,182,144,154,119,120,114,174,144,28,31,32,78,56,116,63,245,135,123,244,70,224,160,161,27,51,61,95,176,224,101,84,165,160,193,100,241,251,159,108,66,56,180,113,237,
188,168,131,33,72,145,125,52,70,250,128,28,123,221,167,51,114,215,48,195,12,129,44,46,84,140,24,152,91,201,246,81,104,53,125,171,209,15,49,123,67,207,124,163,115,115,12,191,95,12,171,146,46,17,166,83,
243,241,27,81,35,230,26,157,31,190,186,236,188,197,4,73,22,56,236,190,206,161,117,12,167,105,231,134,211,221,137,30,158,76,155,95,118,24,105,170,38,81,245,88,106,79,63,79,106,164,217,118,9,136,240,55,
57,236,228,254,27,132,214,149,244,241,99,242,62,68,175,81,149,217,230,91,60,223,236,203,50,143,199,11,113,249,232,99,95,216,122,103,236,157,247,182,243,93,139,215,47,186,49,219,143,102,224,168,127,138,
213,100,83,176,118,197,102,63,13,79,184,45,73,14,2,162,186,170,88,167,195,228,161,128,60,207,17,242,60,98,80,24,243,111,102,251,94,195,185,216,109,155,204,219,115,195,61,227,232,84,123,121,21,220,69,147,
46,149,4,58,146,66,130,64,173,9,28,58,37,155,117,219,174,175,54,251,125,193,100,138,209,67,179,36,170,81,12,157,162,48,196,246,145,198,130,180,175,207,162,23,242,123,227,71,201,253,191,218,27,211,187,
54,134,229,125,249,128,204,98,210,175,108,101,124,201,154,168,192,81,176,215,62,59,110,82,78,102,198,98,105,165,139,252,213,77,50,107,10,72,178,253,125,198,59,165,191,54,223,220,173,183,46,220,195,109,
50,13,105,170,154,165,149,77,76,78,207,132,39,240,212,81,155,181,186,202,142,67,231,47,103,237,57,114,203,111,231,157,162,226,64,101,49,220,4,44,169,20,14,52,173,192,17,247,205,163,253,17,1,5,69,29,107,
66,58,175,237,217,242,15,176,86,10,125,189,158,200,103,49,245,84,224,67,37,110,229,130,163,199,19,133,211,56,196,227,99,142,28,109,52,112,183,30,89,3,201,33,230,223,159,113,55,51,243,183,184,43,115,53,
143,51,94,222,91,93,131,70,86,83,8,252,149,2,169,3,200,230,191,33,214,87,251,121,236,167,179,114,218,67,190,242,70,215,181,238,22,12,53,70,208,72,46,90,149,198,183,145,157,195,158,37,66,173,60,252,250,
199,212,91,210,151,55,189,54,235,135,219,18,225,118,198,110,28,238,119,115,118,53,114,147,153,220,43,32,24,101,143,23,18,203,83,83,139,163,153,174,148,112,141,82,30,88,143,101,156,153,191,88,108,252,199,
97,187,110,22,41,117,20,37,216,153,26,140,101,101,43,27,234,163,30,198,33,128,0,154,252,250,52,247,155,146,55,173,199,144,119,189,150,195,112,185,177,220,239,163,72,162,134,206,29,73,29,170,48,123,136,
218,172,168,30,100,5,25,219,180,3,74,83,171,80,249,105,216,123,179,173,254,59,239,73,71,98,229,55,70,248,236,74,253,183,179,101,173,73,102,142,171,37,149,171,137,243,153,227,182,182,253,51,180,152,92,
62,47,25,83,13,26,44,41,16,43,233,114,77,253,229,5,119,166,229,193,115,107,224,38,238,241,179,65,41,74,36,43,41,8,10,99,83,21,93,108,186,139,53,123,137,207,92,229,228,189,171,149,119,63,115,236,54,235,
253,190,99,202,118,114,6,185,128,73,169,166,22,244,96,38,108,40,18,73,64,250,0,93,61,170,13,58,169,222,188,248,159,190,247,36,248,137,247,116,21,152,10,60,181,170,169,246,221,44,38,175,125,101,225,152,
235,142,87,198,128,87,19,29,113,99,251,213,36,48,4,144,167,218,126,90,229,136,246,189,173,150,193,21,45,70,102,185,149,180,164,143,248,154,164,85,216,154,154,45,122,156,125,195,247,154,198,251,120,147,
198,145,174,55,5,20,130,222,21,212,176,71,193,16,1,64,170,160,1,82,64,52,243,234,208,54,119,194,189,191,177,48,20,249,62,228,203,109,14,149,235,248,214,42,181,193,211,8,114,27,235,52,136,67,35,214,86,
63,147,35,61,76,250,125,90,66,70,62,129,127,30,204,68,251,101,172,138,246,141,45,221,218,16,117,17,225,194,8,56,57,37,138,131,78,37,65,251,58,132,239,57,163,153,249,142,89,173,45,109,243,40,40,114,100,
144,43,10,16,8,164,81,212,122,7,97,242,52,160,229,214,157,199,241,131,102,62,123,170,58,235,172,42,232,240,187,159,7,184,161,164,220,185,39,141,242,27,135,33,61,5,81,171,150,190,146,75,253,181,61,74,182,
165,22,7,159,167,211,219,107,107,184,37,245,141,245,193,43,60,147,171,175,110,144,78,176,73,94,3,206,180,198,58,44,221,54,219,237,195,105,220,25,247,136,102,54,80,120,114,194,142,24,196,129,104,20,154,
157,88,20,39,62,135,61,60,118,31,200,238,163,232,31,137,157,79,155,238,158,194,198,109,122,205,193,181,98,199,237,140,12,159,115,151,222,187,202,166,152,205,28,20,27,79,105,227,210,167,59,159,169,138,
155,198,172,98,143,196,130,218,156,123,38,231,235,205,191,108,230,77,249,238,38,88,226,250,150,32,113,36,145,86,210,7,204,253,159,62,144,123,103,203,156,197,205,86,155,101,174,203,182,75,113,50,196,186,
136,194,70,42,104,100,115,69,79,204,212,250,116,7,252,26,249,183,241,255,0,183,251,30,183,171,112,121,237,205,178,59,70,182,142,163,39,134,235,254,206,219,89,61,133,159,221,184,120,46,106,170,246,205,
62,93,35,164,220,34,8,253,82,211,68,239,58,37,203,37,175,236,29,182,243,14,215,185,59,67,101,114,69,199,240,176,166,175,80,40,72,63,103,30,164,126,122,246,215,155,249,82,198,45,199,121,218,213,182,194,
104,101,140,137,17,9,225,174,153,79,74,250,249,142,140,239,200,31,229,217,241,115,189,50,53,27,253,246,141,119,79,119,63,218,48,160,238,238,139,173,61,121,191,41,106,81,90,72,106,50,244,248,165,135,110,
110,248,18,107,25,32,201,82,204,179,40,42,90,198,254,223,184,217,172,230,149,110,161,13,111,124,56,73,9,208,192,250,144,48,223,179,61,6,182,126,125,230,61,174,219,247,92,243,199,127,176,177,238,181,188,
81,60,36,122,41,106,188,103,208,163,2,14,122,213,79,231,15,199,238,201,234,93,233,22,208,238,138,108,101,102,240,159,47,59,116,119,202,221,133,65,253,219,192,246,70,78,133,154,166,139,107,246,78,22,152,
172,27,7,180,94,24,129,138,88,202,208,228,36,4,71,98,69,196,156,191,205,183,246,23,246,219,47,51,176,120,102,58,98,185,2,138,199,201,37,28,21,207,174,42,120,143,62,141,119,222,70,216,249,143,98,189,230,
191,110,195,195,113,106,158,37,222,217,35,23,146,5,252,83,90,191,197,52,0,241,83,87,65,235,214,192,127,201,55,230,118,232,249,39,209,123,167,100,118,124,255,0,125,216,253,53,155,131,100,238,227,89,16,
105,115,24,201,168,196,184,76,172,241,53,195,189,101,29,226,158,247,188,136,215,246,245,196,190,37,238,237,103,42,105,186,180,156,163,83,129,86,26,163,112,60,181,45,107,243,29,3,57,131,98,139,108,181,
229,189,222,198,86,125,159,117,177,19,196,90,154,145,213,140,115,196,222,165,36,24,52,248,72,232,161,127,50,30,189,222,191,15,254,73,108,255,0,147,61,24,37,161,220,125,121,75,149,237,142,182,251,54,41,
252,119,104,208,207,13,111,120,124,125,206,248,153,70,83,106,110,141,186,103,200,98,233,164,191,218,228,35,213,30,157,71,217,47,51,217,189,214,214,156,195,103,219,187,237,212,44,71,250,36,21,238,86,245,
167,151,202,189,12,125,172,222,45,238,55,11,143,111,183,198,213,203,59,225,240,232,217,16,93,208,253,61,196,127,194,218,232,142,71,21,52,53,235,101,126,152,237,93,171,222,125,79,215,93,197,177,234,214,
187,104,246,102,206,192,111,76,5,74,176,123,227,243,216,232,107,162,130,70,0,15,61,35,74,98,147,253,173,8,246,245,157,204,119,150,208,93,69,253,156,138,24,126,127,230,225,212,119,188,237,87,91,30,237,
184,236,247,201,166,238,218,103,141,199,205,73,31,207,143,66,119,181,61,22,245,170,199,243,94,205,238,92,95,243,20,164,155,56,237,6,74,155,226,28,244,127,21,27,45,40,166,195,29,227,153,221,85,180,253,
185,89,183,106,42,153,104,219,121,197,136,74,56,194,161,21,34,152,221,120,247,17,243,220,215,17,95,181,1,53,132,4,249,86,186,143,89,221,247,88,180,217,238,57,106,239,91,167,140,55,32,215,35,241,20,84,
30,8,62,122,107,168,250,87,231,213,99,116,174,119,101,225,105,178,187,123,188,182,134,239,199,100,39,168,146,79,239,12,116,21,50,198,146,49,111,36,179,202,21,131,107,144,150,45,171,232,125,195,47,100,
186,203,76,24,124,199,151,219,214,118,239,156,197,205,17,61,164,252,167,123,110,214,136,160,120,108,87,32,96,83,62,67,167,126,194,232,237,189,186,101,195,111,222,157,236,122,252,110,230,218,21,235,152,
217,123,195,105,230,37,219,219,247,103,215,161,87,89,113,121,42,102,89,213,24,160,18,193,32,120,100,181,153,125,234,202,242,231,104,159,198,181,159,204,87,136,225,195,30,163,200,244,198,227,185,237,220,
251,182,142,94,231,222,93,166,181,35,94,144,203,158,35,53,5,79,167,236,35,160,111,114,195,219,219,223,117,86,110,238,225,237,78,193,237,29,253,89,141,92,5,126,246,223,249,201,178,187,128,109,248,74,159,
238,254,41,81,41,232,48,88,137,153,3,77,21,36,81,154,130,1,145,155,129,237,94,229,204,87,219,155,120,151,51,22,106,83,36,159,230,115,79,151,71,252,143,236,247,37,114,117,186,175,46,109,113,69,110,91,86,
0,29,222,180,255,0,61,105,229,211,188,16,99,240,88,227,174,72,168,232,168,160,121,103,168,149,132,112,195,20,66,237,44,140,108,21,1,34,254,200,78,185,156,105,21,99,229,243,234,95,2,11,59,119,119,112,144,
34,213,152,240,0,121,158,167,153,149,162,73,148,234,142,72,214,88,216,125,29,36,80,241,184,252,217,148,220,123,165,13,116,211,61,56,8,101,87,6,168,69,65,245,29,11,189,23,213,153,30,210,222,84,208,199,
77,44,152,154,41,163,150,178,163,67,120,180,169,190,155,218,215,54,231,235,236,227,108,176,123,201,210,36,24,28,122,140,61,200,231,24,57,115,107,149,22,81,245,82,2,20,124,253,122,56,159,43,55,150,47,172,
186,233,118,102,50,72,160,171,158,144,82,8,98,109,46,177,172,122,13,212,115,115,254,247,236,77,189,58,90,91,71,99,22,13,0,61,99,255,0,183,187,109,199,48,111,207,186,79,86,80,213,169,245,175,68,255,0,225,
47,71,85,119,143,202,239,138,125,99,85,79,53,69,6,75,176,171,126,69,118,44,8,182,88,122,247,166,163,18,109,213,175,98,172,177,69,152,223,21,180,201,18,183,18,20,36,2,71,180,220,131,99,251,223,154,193,
11,91,107,80,7,230,123,155,246,0,63,111,72,62,245,28,231,31,47,114,6,233,107,12,186,103,149,60,4,21,252,114,224,254,196,13,94,183,166,247,148,157,114,31,175,123,247,94,235,222,253,215,186,247,191,117,
238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,191,255,210,223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,
117,239,126,235,221,53,231,49,113,230,240,185,140,52,178,52,49,101,241,121,12,92,146,167,235,138,58,250,73,169,30,68,191,246,145,101,184,255,0,17,238,146,39,137,28,145,215,226,82,63,104,167,78,67,33,134,
104,166,2,165,24,31,216,107,214,152,157,99,141,217,251,54,159,185,190,11,124,164,217,143,129,220,56,172,212,248,186,173,207,143,161,73,55,190,196,207,224,114,121,57,54,55,97,225,232,157,22,183,114,117,
87,98,109,218,184,103,74,234,63,52,48,207,229,138,96,140,188,227,230,225,183,195,12,251,150,221,186,90,144,146,21,164,170,42,240,200,128,128,105,196,198,224,140,140,126,125,117,7,149,185,151,114,186,181,
228,238,127,228,93,233,90,234,210,45,45,106,237,166,11,168,36,211,226,68,199,130,92,64,213,160,32,26,82,149,232,158,102,54,63,115,124,73,223,251,111,181,58,155,121,75,13,94,195,206,201,150,216,157,167,
180,67,87,255,0,5,106,167,81,149,196,231,240,72,234,185,109,155,186,105,19,197,152,195,206,4,115,173,164,143,68,200,173,236,37,99,121,127,203,91,128,187,134,80,202,8,238,94,13,246,250,19,231,94,35,7,169,
231,153,246,142,80,247,183,151,229,219,111,236,4,59,172,145,247,193,38,9,62,69,28,143,137,72,170,48,200,249,130,71,91,35,252,93,254,121,159,27,123,11,5,142,195,124,152,168,79,143,61,137,21,52,81,212,230,
235,33,200,102,250,115,120,84,34,34,75,147,218,59,211,31,75,86,248,116,169,144,23,108,118,98,58,74,170,95,208,205,33,26,140,241,177,243,230,209,185,64,191,83,40,134,224,12,140,210,191,225,31,102,126,222,
185,149,238,15,221,179,159,121,58,254,117,219,44,30,255,0,109,12,104,84,82,85,21,192,116,52,7,237,74,131,232,58,193,243,175,249,174,124,99,206,116,111,97,116,207,199,13,255,0,182,251,203,181,187,103,103,
103,246,69,44,155,122,89,165,235,238,187,196,110,108,101,70,39,43,190,187,43,119,213,83,195,135,198,96,176,184,250,185,102,74,116,121,170,235,37,81,18,37,218,254,220,223,249,171,105,75,11,139,123,123,
165,121,100,82,181,28,20,28,18,107,79,46,0,100,244,155,219,95,101,121,219,113,230,77,174,255,0,116,217,167,180,219,45,166,73,88,178,247,200,81,131,4,137,69,75,49,32,10,154,0,51,94,168,63,169,119,78,11,
113,239,185,34,218,181,149,57,29,145,178,54,46,201,235,44,14,94,186,54,134,108,237,30,194,192,83,225,164,206,180,47,251,145,67,147,170,137,228,137,91,145,25,91,251,129,110,238,163,188,221,100,157,7,233,
4,80,61,72,81,74,255,0,151,174,151,91,109,87,91,55,42,218,217,93,32,23,178,76,242,149,28,20,200,107,167,242,20,252,235,208,57,223,249,106,58,252,243,195,72,160,136,89,129,117,181,174,63,63,208,253,127,
175,178,11,182,13,57,210,112,9,234,99,228,59,89,224,177,86,148,157,76,1,207,69,123,33,73,19,94,173,144,25,33,142,77,12,69,202,220,114,203,249,13,207,215,159,116,70,33,177,82,58,25,92,219,169,6,106,85,
151,63,236,245,103,95,20,59,7,170,250,131,37,242,7,45,216,25,67,79,147,47,213,59,39,25,183,227,154,104,231,202,224,49,27,26,147,52,86,120,161,100,53,24,249,50,89,86,37,88,248,217,185,42,125,229,47,177,
182,14,219,38,227,115,18,254,163,58,169,106,10,140,22,32,30,62,149,235,141,127,124,173,214,75,190,116,216,44,228,115,244,235,20,242,129,154,22,105,52,87,210,180,28,125,58,52,219,7,230,207,88,238,93,229,
79,183,42,170,48,29,47,214,148,244,213,85,219,147,179,55,4,212,120,172,94,34,146,145,117,188,116,229,214,26,71,200,78,138,124,74,236,196,189,172,164,241,238,118,240,182,253,182,27,141,207,124,185,65,105,
12,108,218,93,180,9,24,124,41,83,147,95,48,50,71,88,125,111,99,188,111,151,150,123,63,46,217,79,113,185,207,42,160,17,70,210,50,43,113,125,43,192,47,241,28,15,62,149,187,123,183,62,79,252,172,207,86,224,
62,1,244,192,218,93,89,20,162,151,33,242,175,188,41,242,91,127,108,228,105,145,173,54,111,13,5,116,20,251,171,125,73,107,201,24,137,104,241,205,109,42,74,253,99,219,254,118,230,14,96,95,3,100,183,3,110,
83,137,30,177,91,175,252,210,132,102,66,61,77,75,121,211,169,242,203,145,189,184,246,214,37,155,157,119,47,169,230,93,57,180,182,43,61,209,62,147,79,152,173,199,147,1,220,58,91,245,255,0,242,148,248,155,
181,230,103,249,15,216,29,139,243,19,176,171,55,6,95,118,100,118,126,22,178,109,179,213,84,27,163,113,213,10,237,193,83,67,181,54,228,212,248,232,41,171,107,253,78,42,170,102,214,62,168,13,238,27,181,
228,93,184,204,247,187,149,110,46,153,139,22,35,195,74,147,83,165,64,213,79,149,71,217,210,237,231,239,17,207,87,22,137,179,242,177,77,159,99,141,2,34,70,76,179,21,81,69,215,43,212,22,3,205,86,162,184,
52,234,214,250,159,160,98,235,204,20,84,61,61,212,29,71,241,227,103,211,70,12,107,142,219,152,145,147,16,170,88,207,81,94,96,165,140,56,69,245,18,231,252,79,177,69,189,190,223,96,171,21,156,8,163,250,
10,23,249,229,191,159,80,166,231,186,238,219,220,237,115,189,110,87,23,119,13,196,203,35,63,242,39,79,242,232,31,238,31,147,159,18,58,120,213,71,221,63,43,227,203,101,233,117,253,206,220,219,89,197,174,
151,200,183,13,2,227,182,240,100,83,123,141,44,252,126,125,153,197,5,228,255,0,216,90,254,100,127,148,244,132,37,40,41,164,126,206,171,163,126,255,0,56,207,130,219,122,87,165,217,125,95,216,125,140,80,
178,138,186,197,139,21,75,57,83,195,107,174,146,162,118,86,252,221,65,246,99,22,209,184,48,171,202,171,246,117,237,43,230,122,45,185,111,231,131,179,193,150,61,171,241,7,10,33,26,190,222,76,190,231,148,
74,110,125,13,40,167,165,42,109,253,0,246,163,247,44,148,30,37,239,219,213,214,37,106,104,212,126,192,127,201,208,127,39,243,176,223,109,57,151,31,241,123,174,169,148,27,162,62,71,43,41,81,126,61,75,28,
64,220,254,125,251,247,85,186,101,247,1,251,87,252,253,60,182,55,18,158,203,105,90,167,248,15,249,186,82,99,191,158,71,107,81,128,100,248,215,178,194,15,249,85,202,229,169,218,223,79,169,13,199,251,126,
61,176,109,118,229,36,126,245,90,255,0,166,31,228,61,43,254,174,238,110,186,155,105,158,135,133,99,106,127,49,210,251,17,252,242,176,53,232,41,123,31,227,59,85,209,201,233,170,134,147,39,142,204,83,52,
100,129,34,253,158,102,142,72,228,83,127,161,255,0,91,222,155,109,142,225,10,11,164,120,253,8,13,254,17,211,71,105,185,178,111,17,22,88,102,30,99,82,48,252,193,4,117,3,49,242,135,249,44,252,142,12,189,
209,241,202,151,175,51,245,188,75,184,40,54,75,109,138,248,167,144,250,166,92,246,198,173,162,109,104,252,134,120,159,253,111,97,251,206,67,219,110,129,45,181,194,73,243,143,244,219,254,50,105,252,186,
23,108,254,228,251,141,203,69,127,118,115,125,234,162,240,89,24,202,158,191,11,212,254,194,58,78,201,252,185,254,33,246,148,103,63,240,139,231,166,79,103,214,203,254,81,139,216,219,235,47,67,189,177,49,
212,88,52,84,129,178,114,225,119,69,4,122,192,3,73,153,208,112,47,238,63,221,61,165,177,119,105,109,100,146,222,110,35,80,243,255,0,78,148,35,237,210,122,157,185,99,239,123,207,123,92,105,107,204,187,
69,190,229,101,74,49,29,172,71,157,81,195,161,175,165,71,73,185,246,223,243,87,248,155,80,13,86,203,162,239,29,157,66,65,139,112,245,158,70,139,117,199,37,60,39,137,230,218,251,141,104,115,112,235,84,
190,152,90,91,19,96,79,30,201,134,215,238,79,46,41,27,125,243,220,218,47,0,79,138,180,255,0,143,15,217,212,131,7,184,191,118,95,114,10,175,48,237,39,103,221,159,226,101,13,6,78,63,14,168,205,63,46,172,
15,226,135,243,40,198,247,190,204,236,45,137,185,242,56,30,177,249,57,177,169,162,159,9,210,221,175,89,46,213,218,189,229,129,8,242,229,118,208,218,27,243,237,169,232,247,42,173,52,144,68,244,146,13,114,
201,25,0,139,251,48,218,249,227,121,146,27,200,230,180,75,94,98,133,117,68,106,99,214,71,16,13,65,13,242,60,107,81,208,3,220,15,102,57,79,103,220,118,11,237,163,119,109,219,219,141,193,138,79,52,104,37,
150,201,142,3,63,135,80,99,200,106,159,194,15,3,208,147,218,61,183,221,191,30,247,6,192,236,207,143,249,188,150,115,162,123,47,13,142,221,244,93,89,154,139,251,195,132,90,58,217,17,55,30,213,198,71,55,
145,232,242,59,127,32,179,82,149,129,213,213,85,13,185,247,51,199,117,183,243,119,46,237,92,218,168,22,119,211,29,214,140,29,98,132,72,71,171,0,65,52,248,193,245,234,5,216,118,43,93,175,152,57,163,219,
110,96,0,110,150,165,222,198,114,116,157,0,124,5,188,210,165,100,90,228,35,83,128,232,215,117,247,97,124,28,249,133,69,225,206,224,118,174,202,223,211,17,13,110,222,207,45,62,54,170,74,199,64,102,16,172,
198,150,41,89,37,82,10,176,71,31,227,239,119,182,59,184,183,164,114,197,185,237,3,128,120,210,125,35,248,90,57,67,58,17,232,42,184,173,124,186,12,17,188,114,149,243,51,165,222,217,126,77,76,144,201,44,
10,255,0,210,89,160,101,142,69,62,68,247,121,16,58,10,59,239,249,89,109,124,229,4,219,143,168,162,139,23,156,166,31,123,138,169,194,84,68,97,146,122,114,37,128,198,162,209,137,3,198,45,168,72,132,112,
25,126,190,227,205,227,148,121,75,126,73,35,185,218,83,109,221,191,5,197,178,148,85,113,144,38,130,186,89,43,241,20,10,224,26,138,240,234,108,228,47,188,111,185,60,155,61,188,115,111,210,239,124,176,199,
76,214,55,239,226,23,136,225,188,11,162,60,72,228,161,237,14,89,9,0,17,231,211,95,199,126,147,249,53,188,115,53,88,46,219,159,110,82,227,240,209,82,253,230,241,151,109,208,69,184,232,69,10,152,30,161,
114,53,111,56,21,50,192,128,22,0,5,211,123,183,181,252,189,99,188,236,118,241,167,51,115,13,190,235,12,107,166,222,222,18,230,53,207,199,44,133,87,20,192,141,65,98,78,72,28,73,253,199,230,159,110,183,
153,218,243,219,78,79,220,54,89,238,88,181,204,215,45,25,105,1,24,138,8,145,154,164,19,253,171,157,35,240,169,60,4,158,195,249,13,212,63,26,169,114,184,174,165,199,98,247,22,228,166,251,129,184,187,111,
120,212,199,61,29,53,106,2,147,61,21,77,65,190,66,122,119,28,21,62,48,220,40,111,167,177,77,193,186,220,34,125,207,121,188,142,29,186,17,197,136,142,24,148,121,14,10,61,2,173,93,189,9,61,4,182,30,87,150,
238,107,75,1,4,237,119,114,195,195,180,129,90,107,203,150,62,101,86,174,107,230,239,165,20,121,168,24,166,78,225,249,79,147,222,83,230,55,150,228,222,107,131,219,139,84,35,200,118,94,253,168,146,154,133,
106,170,28,132,135,5,135,144,61,86,67,33,80,78,154,90,116,141,229,250,21,136,15,100,18,111,86,222,9,190,141,205,182,208,191,4,178,141,6,67,252,113,64,115,66,62,22,150,166,153,8,58,200,27,14,66,109,164,
65,181,94,219,69,38,236,71,125,141,155,120,133,86,159,5,213,226,208,99,253,26,59,114,22,189,173,43,83,172,31,22,59,103,171,178,189,247,178,246,190,215,221,251,131,117,103,247,52,210,212,102,63,189,88,
236,230,15,36,180,240,211,212,69,14,66,151,23,158,166,165,157,177,117,73,82,85,37,137,66,222,192,129,236,163,102,223,246,89,57,154,202,219,110,187,146,229,174,164,67,35,185,114,85,227,106,138,234,39,226,
82,64,34,148,199,1,209,151,62,114,166,255,0,115,237,190,255,0,184,223,109,182,182,22,251,93,172,171,12,49,36,104,178,71,56,161,210,99,3,81,71,85,45,168,146,107,90,146,79,68,203,119,100,187,27,178,126,
73,111,56,119,134,231,175,170,201,227,247,180,125,115,46,237,158,101,25,45,161,214,148,25,90,108,77,38,222,218,158,83,163,105,237,250,10,82,215,138,132,68,245,85,12,100,153,216,159,112,71,185,219,166,
231,125,205,220,207,245,83,48,95,222,18,169,63,45,84,95,76,1,154,117,151,31,119,158,88,228,190,77,246,147,147,183,75,13,186,25,119,38,229,244,187,84,97,80,247,30,19,53,88,31,137,139,12,150,174,145,142,
141,199,80,245,14,230,249,231,252,196,250,235,120,245,124,82,108,126,180,248,139,187,58,219,114,110,13,224,242,24,39,199,237,29,147,20,152,253,181,182,232,230,167,26,243,61,141,218,114,208,203,61,109,
173,20,24,239,84,164,150,3,217,167,39,237,50,238,59,130,95,91,39,133,104,154,15,165,17,40,23,135,25,26,156,126,103,168,67,221,174,110,179,228,95,109,165,229,109,225,254,179,152,119,69,184,118,20,168,241,
174,78,185,41,92,165,189,184,32,32,243,108,1,214,220,187,138,168,10,74,186,128,170,129,210,105,116,47,209,67,106,54,36,16,44,63,226,61,205,196,229,136,225,215,62,162,64,12,106,115,78,170,7,228,151,81,
109,207,145,219,27,182,186,155,117,192,146,226,119,118,213,207,71,77,82,255,0,231,113,25,236,117,36,217,45,187,184,40,229,177,122,122,252,46,94,150,41,227,145,8,97,164,143,161,62,208,110,86,145,223,89,
93,89,200,48,241,154,124,152,10,171,15,66,8,226,51,212,135,203,59,205,207,44,111,59,54,251,102,105,53,188,235,81,228,200,196,44,145,176,224,85,208,208,131,81,235,195,162,17,255,0,9,214,193,231,50,178,
252,138,237,58,234,90,164,162,205,110,13,163,177,106,107,164,64,148,217,157,201,177,113,85,116,59,167,39,72,192,104,153,31,35,50,234,113,127,83,123,103,149,111,46,119,88,183,61,214,237,79,136,203,4,53,
63,136,196,133,73,253,148,175,219,208,155,223,77,179,110,229,171,142,87,229,93,187,72,134,33,121,118,16,127,161,71,121,55,139,28,103,210,148,106,15,78,143,175,243,90,204,98,43,41,250,119,109,214,52,82,
215,229,247,126,91,31,75,78,72,243,156,93,110,221,201,210,101,88,95,145,78,41,102,109,103,133,176,231,216,210,40,195,109,123,216,147,251,35,107,37,125,62,6,255,0,47,80,166,211,36,144,238,251,60,176,215,
198,91,184,74,211,141,68,138,71,66,39,242,9,206,100,115,63,203,27,164,233,235,230,158,120,182,222,127,179,182,190,26,73,153,221,70,223,195,111,236,236,56,88,41,203,147,106,106,90,22,88,208,14,0,95,113,
255,0,38,187,62,197,0,106,246,187,1,246,86,189,74,222,254,193,28,30,232,111,205,26,128,100,88,93,169,252,109,18,234,63,153,169,234,230,125,138,186,134,186,4,59,207,227,111,69,124,150,219,84,219,71,189,
122,183,104,118,110,10,130,169,235,241,80,110,124,92,85,117,88,74,249,16,35,215,224,178,106,35,201,97,107,93,0,13,45,52,177,59,40,177,36,113,237,29,230,223,103,184,70,35,188,183,87,81,194,188,71,216,120,
143,203,163,173,143,152,247,238,90,186,55,187,6,237,61,165,201,20,38,54,43,168,122,48,24,97,246,131,213,81,119,15,242,26,248,199,185,105,43,114,93,9,216,125,213,241,195,123,172,50,201,135,201,109,221,
255,0,156,222,123,74,58,213,5,233,162,201,236,221,237,89,152,162,169,197,153,64,18,69,20,145,29,23,210,65,246,24,188,228,157,178,117,111,165,102,137,252,171,220,181,249,131,154,125,135,169,155,151,254,
241,220,253,181,77,16,221,94,27,251,64,70,160,234,35,114,60,233,36,97,77,125,9,175,204,117,64,251,143,167,123,147,170,251,135,176,62,59,247,14,63,29,181,62,76,117,182,41,247,158,219,205,109,88,228,160,
216,223,35,122,165,102,104,98,223,155,86,132,217,33,203,211,148,211,144,163,75,189,60,218,129,30,147,238,31,223,249,106,91,105,103,133,226,165,194,103,28,24,122,175,200,255,0,176,115,214,127,123,87,238,
230,217,204,155,110,221,185,199,55,139,178,204,193,36,87,204,150,242,226,168,255,0,103,21,106,81,135,112,232,57,155,113,75,152,38,170,182,235,85,115,28,224,130,174,147,68,116,200,142,182,186,178,184,183,
245,247,30,152,138,146,160,214,152,251,58,204,171,19,106,150,177,11,102,30,9,21,31,97,225,79,151,69,239,228,22,226,158,61,185,182,118,213,20,166,63,239,174,247,192,97,43,92,18,9,198,69,89,5,93,100,31,
215,69,66,160,86,189,174,47,236,223,103,132,120,211,206,194,166,40,137,30,149,225,208,47,220,93,193,163,219,54,173,182,35,79,173,190,138,54,35,248,3,6,97,249,224,31,151,70,35,105,45,14,229,220,248,252,
12,245,145,81,211,75,60,80,25,153,130,4,137,72,137,65,38,192,0,56,246,130,8,75,178,3,230,120,244,113,204,155,227,109,123,117,212,240,69,86,65,64,7,203,29,93,46,207,168,233,239,141,221,100,249,67,146,199,
203,83,37,55,220,204,235,44,38,122,153,12,92,42,250,139,0,79,185,26,205,118,253,154,204,191,136,26,86,21,227,214,13,239,215,156,209,207,60,194,201,44,110,16,53,6,13,0,175,84,175,218,253,159,147,249,23,
220,116,244,52,62,81,69,148,204,45,13,28,100,234,17,210,25,139,75,53,185,0,36,10,73,63,64,61,130,55,157,192,4,187,220,36,224,170,72,31,63,33,251,122,201,110,79,218,35,229,77,144,120,159,219,4,171,124,
201,234,247,255,0,145,191,84,38,229,222,95,39,254,89,203,78,159,221,250,220,198,31,227,79,79,187,0,196,236,254,164,15,38,242,204,82,182,144,5,54,119,121,87,149,12,166,206,105,79,244,30,229,223,103,246,
89,44,54,86,190,184,31,227,19,29,71,214,174,117,159,228,84,126,68,117,205,239,189,183,56,13,215,152,246,206,90,137,235,244,234,211,75,156,107,147,10,167,236,81,95,150,174,182,42,247,48,245,136,93,123,
223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,255,211,223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,
186,247,94,247,238,189,215,189,251,175,116,84,62,94,252,203,233,111,133,61,115,73,216,93,197,146,201,22,207,101,63,187,187,31,102,237,186,3,151,222,91,247,115,53,60,149,67,9,182,241,66,72,145,218,10,104,
204,181,53,51,188,52,180,145,122,229,145,65,23,43,221,183,139,45,154,216,220,222,73,69,242,30,103,253,94,103,252,189,12,57,39,145,121,135,220,13,230,61,147,151,109,60,75,147,66,204,112,136,164,210,172,
104,79,30,0,2,79,144,234,145,41,127,225,68,236,219,152,253,255,0,196,60,220,91,45,170,60,107,246,93,181,180,234,247,170,83,95,71,220,201,140,154,130,139,14,243,31,213,225,90,147,254,167,89,60,251,143,
23,221,93,176,204,85,173,136,135,237,53,255,0,5,63,213,199,172,167,155,238,75,207,113,109,159,84,55,68,250,189,53,211,225,62,154,250,86,181,167,206,159,151,151,70,186,171,228,239,242,158,254,99,116,248,
109,185,219,245,59,111,104,246,138,210,36,24,10,46,216,130,94,162,237,237,189,44,140,146,52,59,55,125,153,241,242,212,198,178,254,159,176,200,77,12,128,223,65,230,194,4,221,185,79,153,80,25,101,79,18,
148,5,187,88,124,131,131,252,171,212,63,113,201,190,243,251,73,117,44,214,150,151,113,218,134,171,24,65,150,6,167,155,199,66,50,63,137,65,249,245,82,159,204,39,225,157,39,194,245,219,59,227,168,190,78,
210,118,191,90,239,141,203,140,219,115,117,38,251,221,152,60,239,112,225,127,143,207,44,52,25,173,163,83,141,155,239,123,19,103,80,16,159,196,18,174,156,212,82,64,76,226,125,42,71,176,7,56,242,133,157,
172,47,119,183,223,161,39,138,212,87,215,32,26,17,79,58,10,31,182,163,41,189,129,247,231,117,230,61,210,46,94,230,206,88,98,192,26,92,199,27,42,41,20,226,127,208,223,248,64,52,106,17,74,158,170,35,113,
226,177,181,153,25,170,241,176,73,67,29,116,41,53,66,99,228,101,166,51,93,150,91,195,119,130,88,245,41,32,149,60,123,136,18,86,81,232,71,219,95,203,252,221,116,82,45,186,214,242,219,195,220,35,73,36,82,
66,179,1,168,143,42,215,53,167,31,67,210,34,163,11,60,177,26,47,226,21,146,80,25,4,134,141,36,16,211,23,7,134,146,150,156,69,4,142,9,189,217,73,246,247,143,67,156,159,245,122,244,149,182,8,98,109,80,64,
138,62,74,1,253,180,232,196,245,118,113,182,134,22,122,106,67,166,166,161,25,110,1,186,220,21,189,239,123,255,0,182,247,69,153,148,187,46,43,209,46,229,177,164,242,198,211,124,32,215,164,118,234,174,122,
186,195,228,115,36,172,75,187,90,230,231,241,245,63,215,219,60,73,39,143,66,253,170,5,138,33,165,104,41,210,46,166,47,44,50,197,114,11,163,1,245,60,253,7,31,224,125,217,77,13,124,186,52,117,14,140,164,
86,163,163,9,67,77,67,216,189,189,213,241,117,54,197,61,233,218,253,167,215,152,220,22,239,233,124,94,89,240,147,108,173,211,177,104,215,19,137,236,157,227,158,251,90,138,12,30,201,202,226,226,72,235,
22,102,74,151,49,43,66,24,146,61,206,190,211,243,78,245,179,11,221,187,110,219,77,202,92,12,41,58,64,117,173,28,159,225,3,226,60,41,231,142,185,141,247,160,246,215,150,119,57,83,119,230,126,97,93,173,
118,219,134,172,218,4,141,44,82,229,160,142,58,130,242,150,161,65,154,30,56,61,91,199,68,255,0,46,126,187,217,27,159,21,190,190,81,201,134,249,19,220,116,114,67,91,180,186,111,107,99,126,199,165,58,154,
66,3,167,143,21,84,211,38,127,47,4,150,83,144,201,249,102,125,58,163,141,47,196,190,187,45,222,233,112,55,62,104,187,91,171,165,248,18,148,183,135,228,137,141,100,127,19,99,207,61,97,141,255,0,184,86,
251,70,219,47,46,123,107,182,201,179,236,210,98,121,203,3,184,94,83,206,105,198,97,67,196,67,17,0,12,30,174,94,159,175,179,217,77,176,251,135,182,119,126,31,173,58,179,5,72,103,109,191,73,85,30,220,218,
248,188,117,60,101,130,214,84,22,166,251,227,28,43,107,18,23,240,170,61,156,52,209,198,85,98,82,210,1,64,79,249,7,0,62,67,168,205,17,220,154,3,86,53,167,18,73,243,39,137,62,164,231,170,212,239,207,231,
37,241,183,160,162,200,236,95,137,155,9,187,143,122,209,180,180,82,111,42,250,113,140,216,116,85,8,26,54,154,158,123,125,238,103,68,128,31,72,84,54,250,145,239,210,34,68,134,231,117,188,72,109,198,114,
114,126,207,62,132,123,71,43,239,27,212,235,111,182,216,75,52,196,240,69,45,251,79,1,213,26,119,127,203,127,154,31,45,51,146,85,246,23,103,110,170,108,93,91,21,161,216,219,13,235,177,24,26,74,114,74,164,
17,209,99,12,98,91,134,177,121,25,137,246,26,159,220,94,95,177,118,183,216,246,217,111,46,1,166,173,61,181,251,115,95,203,169,227,102,251,183,115,3,91,165,247,55,111,150,91,77,153,21,40,210,43,77,79,178,
189,191,159,236,232,46,195,124,53,237,77,194,5,112,216,121,210,146,143,44,217,44,213,66,210,151,213,235,105,102,170,175,148,105,185,55,36,159,207,181,17,111,62,230,223,171,75,183,242,209,72,127,138,65,
161,0,245,171,82,163,237,61,57,63,43,253,221,182,77,54,251,215,62,52,215,35,5,32,38,89,28,143,244,162,128,252,128,234,109,79,198,253,191,180,75,29,239,216,61,51,178,26,46,100,254,241,246,30,9,166,142,
215,187,73,5,53,101,75,13,63,144,64,62,202,175,27,159,101,44,187,167,58,237,182,32,254,21,150,58,143,247,141,71,161,30,215,39,178,176,180,109,203,94,208,239,187,211,1,135,120,102,10,223,239,74,163,174,
161,219,255,0,26,40,5,171,254,88,244,93,35,47,47,30,62,186,167,32,202,1,245,8,254,214,142,79,32,254,132,125,125,135,159,98,179,185,37,183,47,119,87,85,115,165,165,63,178,139,158,135,176,115,198,247,99,
161,54,31,186,193,88,128,237,241,34,140,31,204,187,10,126,206,157,104,199,195,102,156,172,223,49,250,203,198,182,214,22,143,49,25,39,143,208,211,80,68,24,127,182,247,165,229,94,74,43,166,111,116,165,102,
251,38,167,243,29,57,63,185,158,242,134,38,215,238,231,109,20,126,93,176,18,63,48,79,66,246,212,192,124,27,203,207,10,79,242,163,174,114,113,106,30,104,198,232,76,20,174,156,6,16,26,248,132,106,236,57,
231,218,184,57,31,144,102,210,96,247,47,191,230,204,135,243,212,189,7,55,31,120,253,250,183,86,73,61,140,69,138,159,242,142,146,15,216,185,232,224,237,175,135,255,0,2,251,26,146,157,246,255,0,124,186,
213,203,26,139,99,119,166,202,220,48,151,97,195,44,109,83,13,78,141,95,65,97,236,201,121,17,105,77,163,159,221,189,52,207,27,127,34,192,244,0,187,247,215,154,160,145,255,0,172,254,203,216,113,206,187,
25,163,254,106,180,252,250,127,200,255,0,39,205,133,185,225,122,141,139,221,216,58,216,164,23,138,44,230,6,38,45,113,198,185,177,117,51,41,191,250,222,253,253,92,231,251,19,91,46,107,119,65,195,90,215,
249,138,255,0,179,210,53,247,163,218,189,205,116,111,222,208,91,36,135,137,130,66,135,246,56,7,162,251,187,127,147,79,120,237,137,95,33,179,6,223,220,114,65,105,160,170,217,187,142,124,86,82,235,234,86,
138,154,119,134,97,37,254,130,254,234,219,199,186,27,127,198,144,93,198,56,140,84,254,68,14,150,65,121,247,108,230,0,86,75,93,199,106,157,177,83,86,81,95,152,60,58,100,219,245,255,0,204,51,226,229,74,
64,50,125,150,112,244,62,134,195,239,76,85,102,225,195,188,113,21,45,26,84,184,156,170,105,31,80,195,143,109,167,184,215,176,54,157,227,150,100,141,252,217,42,63,201,210,169,189,145,228,13,246,51,39,43,
123,141,107,45,120,36,148,175,248,107,95,219,208,183,146,249,125,209,221,239,143,135,104,252,206,248,207,181,179,213,23,88,206,238,162,196,194,245,148,82,31,72,173,130,102,138,159,51,142,168,137,253,65,
225,156,50,145,113,236,205,121,135,147,249,137,68,55,177,33,144,255,0,191,80,6,7,228,227,35,160,195,123,85,238,207,32,201,38,227,201,187,164,222,10,228,253,52,165,149,135,163,66,73,12,8,242,166,122,18,
182,127,197,204,230,95,110,80,143,128,127,52,243,244,152,44,45,108,185,236,23,66,247,22,67,253,34,236,76,85,109,65,243,212,197,136,254,35,32,222,91,84,74,237,234,20,146,186,106,228,131,111,106,45,182,
59,205,162,43,175,234,166,250,208,218,220,45,30,9,64,150,23,80,106,50,1,42,117,100,26,87,212,211,162,171,159,113,173,55,61,206,214,95,117,249,2,27,173,210,3,164,94,91,106,181,188,78,221,4,50,159,210,150,
170,104,67,87,3,243,233,1,220,153,30,250,218,21,112,101,62,92,124,71,220,24,170,154,8,2,86,247,159,197,193,62,247,193,86,120,64,81,145,220,91,62,1,67,186,113,147,250,117,52,138,142,52,155,220,251,220,
124,195,190,108,157,251,182,207,32,140,127,162,219,31,17,105,234,64,202,254,103,161,158,202,252,151,191,199,37,159,42,115,156,44,28,154,88,238,170,33,124,249,71,35,86,38,30,148,249,142,150,159,25,63,152,
99,117,158,254,217,114,117,215,201,28,95,103,245,229,126,90,147,31,158,216,153,172,157,109,14,229,195,210,73,58,69,89,143,205,109,157,195,21,46,75,23,93,74,173,245,69,98,25,120,99,236,93,180,115,110,205,
205,122,108,46,175,34,145,159,180,52,138,35,154,54,56,86,12,116,146,1,165,84,147,94,130,188,233,236,244,150,59,110,227,187,216,242,212,251,126,233,111,25,150,145,49,123,91,133,94,230,3,73,100,21,90,149,
101,165,13,60,186,216,135,229,229,101,68,253,27,69,186,246,101,109,85,14,11,115,230,118,246,79,113,215,225,230,240,77,89,129,203,82,40,167,50,207,1,191,218,200,242,198,36,177,183,171,159,175,180,86,16,
8,183,31,165,187,0,20,98,173,233,131,67,79,35,231,79,95,46,162,206,87,149,39,188,46,136,175,55,211,185,132,48,198,176,164,166,15,157,105,131,214,188,189,43,215,27,71,186,251,3,228,118,249,249,57,190,171,
48,61,123,241,222,150,76,236,27,121,242,63,194,118,229,62,30,130,105,216,228,42,194,7,45,73,77,79,78,165,153,21,167,154,73,64,5,111,127,96,168,210,247,120,223,183,253,215,153,164,45,103,97,117,36,113,
66,127,177,133,99,252,75,31,194,91,77,40,198,165,152,140,245,152,220,199,190,218,123,123,237,255,0,182,91,31,181,123,114,14,96,230,93,189,38,189,191,211,174,250,226,73,143,116,38,99,220,137,174,171,225,
41,88,213,86,154,79,68,51,3,188,48,61,169,190,83,190,123,66,25,246,245,6,102,182,178,110,136,235,236,110,42,9,225,234,62,160,197,72,97,197,238,90,45,191,84,146,80,83,246,103,104,136,117,199,144,170,73,
38,162,165,98,202,65,32,251,134,121,227,154,231,220,239,92,164,172,169,90,34,138,126,154,83,20,242,14,220,73,242,63,151,89,35,237,31,181,119,112,108,242,53,165,148,119,55,49,168,18,60,204,66,207,114,255,
0,27,59,124,77,13,185,63,217,174,24,227,207,174,250,243,189,182,61,63,207,57,251,119,41,135,255,0,70,187,46,61,173,85,30,222,160,146,92,222,235,76,76,244,13,140,141,169,164,200,69,79,145,174,147,39,156,
142,157,230,125,40,177,52,197,149,64,227,217,143,182,187,158,223,107,190,139,235,137,150,222,220,171,252,69,154,135,78,50,106,73,36,87,237,39,164,30,250,114,110,249,99,200,54,252,171,53,204,187,174,232,
27,186,85,141,99,241,53,177,37,66,138,42,162,3,165,107,228,51,214,30,243,220,155,118,163,125,247,78,250,216,223,198,40,49,61,179,187,177,51,236,40,179,120,249,112,219,130,77,181,141,154,171,45,184,247,
116,248,106,155,100,112,184,204,214,110,88,97,161,90,149,142,121,146,23,147,64,91,92,159,220,237,207,103,220,185,131,116,186,217,217,154,11,169,86,86,212,180,33,180,128,252,9,195,61,74,255,0,70,158,125,
8,254,235,156,167,205,86,252,169,203,150,188,229,102,170,187,77,140,182,162,141,169,100,86,145,188,21,173,0,44,144,208,61,42,1,243,61,78,248,193,242,227,187,62,39,207,187,235,58,151,115,71,183,155,125,
201,139,169,221,244,249,93,167,134,222,184,124,205,118,10,9,169,113,121,133,199,101,140,83,227,50,244,244,83,180,50,73,4,161,39,142,218,214,235,127,100,251,15,59,238,123,34,73,4,26,124,22,165,69,1,225,
90,113,31,63,151,66,95,117,126,235,220,169,238,77,221,166,227,52,210,69,119,8,33,70,166,92,55,21,212,56,173,115,145,213,148,117,103,243,123,238,234,185,126,239,181,183,30,211,223,27,106,146,187,26,187,
227,104,158,173,167,216,27,151,31,215,249,105,86,142,179,178,54,86,240,193,100,235,112,53,178,236,234,137,82,124,134,35,35,28,50,212,81,107,104,28,186,219,220,131,177,251,133,61,236,200,46,244,152,245,
0,70,144,166,135,241,6,30,106,115,66,40,71,3,214,33,251,153,247,78,139,148,160,105,182,66,230,176,179,44,190,48,145,124,84,200,134,72,153,67,210,64,8,73,16,144,173,74,142,158,55,175,202,77,201,242,111,
124,110,127,142,127,7,51,16,102,178,57,51,89,132,237,239,149,194,138,106,174,171,233,109,173,88,30,151,47,79,179,114,14,139,77,190,59,63,33,68,239,13,20,20,229,169,233,93,139,187,18,182,246,58,55,119,
27,220,210,109,91,3,106,168,164,183,7,224,137,15,29,39,205,200,199,80,84,60,187,97,201,59,125,159,54,123,139,9,141,112,246,187,102,160,46,110,228,25,67,42,214,177,91,173,1,98,71,112,61,92,31,198,30,164,
234,63,134,63,29,48,219,43,102,34,224,54,7,95,96,38,159,33,184,243,111,28,85,185,58,132,141,171,51,123,151,53,84,218,4,217,60,189,99,60,243,57,60,187,5,28,1,236,95,103,97,14,223,109,107,182,89,175,232,
70,40,61,88,147,86,99,243,99,251,0,3,203,168,103,152,185,131,116,230,205,243,113,230,13,226,93,123,149,203,213,169,240,162,129,68,141,7,146,32,237,95,219,231,214,181,223,47,62,82,238,14,251,175,239,143,
148,84,233,93,22,194,216,84,149,255,0,29,254,45,97,99,87,146,179,176,187,203,180,82,109,173,136,254,5,1,230,174,124,62,50,182,124,157,83,32,97,4,74,138,108,88,123,115,156,239,98,229,254,85,184,180,86,
255,0,30,187,30,24,30,103,87,197,251,20,255,0,62,133,222,209,242,219,115,55,62,236,209,72,163,247,101,155,253,85,195,31,133,98,135,188,234,255,0,76,64,2,191,62,182,166,254,93,159,28,166,248,157,240,175,
227,207,67,215,170,46,123,102,117,254,58,77,214,200,133,11,110,221,195,44,251,143,114,164,161,189,77,37,54,91,41,44,36,159,175,143,143,97,237,138,200,237,251,85,165,179,255,0,104,22,167,237,108,159,217,
195,242,232,171,220,78,100,28,219,206,156,195,191,167,246,19,220,54,143,249,166,189,137,251,85,65,252,250,58,158,205,250,5,245,239,126,235,221,123,223,186,247,84,175,252,235,126,62,238,45,213,209,219,
47,229,143,83,109,217,243,29,221,240,215,117,69,217,152,202,108,101,48,151,41,186,122,170,162,212,125,175,178,164,17,145,61,101,13,78,220,45,88,176,0,255,0,185,76,116,143,83,123,8,243,118,223,245,22,73,
125,20,117,184,128,215,28,74,31,136,126,88,63,183,169,211,216,94,111,93,135,155,27,99,191,185,209,179,238,138,34,98,79,106,204,51,11,250,14,238,210,113,134,227,214,179,191,36,223,111,165,78,206,238,190,
176,168,90,222,173,238,220,5,46,237,192,86,209,146,105,40,171,234,226,89,43,177,146,148,178,195,85,79,59,52,114,70,64,101,116,60,123,129,119,157,181,99,185,19,70,7,131,38,71,249,71,93,96,246,219,154,110,
46,54,169,182,139,217,79,215,90,54,154,19,146,190,95,179,162,69,216,185,10,140,230,27,19,147,245,73,46,210,220,184,157,199,233,187,48,165,165,157,35,200,20,176,37,188,116,239,175,254,65,62,210,217,162,
195,35,199,248,100,66,191,153,24,232,65,205,141,37,229,133,149,217,201,179,187,142,111,246,160,128,231,242,20,39,228,58,93,214,231,235,233,42,22,187,29,85,34,234,211,60,85,17,55,13,27,168,146,57,21,193,
210,67,130,8,183,22,246,150,56,144,213,94,161,129,232,65,120,233,114,167,93,26,38,21,30,132,17,80,127,48,122,239,47,217,27,207,63,75,29,14,83,59,144,170,165,141,64,88,102,168,118,141,80,216,15,73,107,
112,191,224,61,190,209,212,10,146,126,222,136,160,218,246,235,105,90,104,109,81,92,154,147,79,62,150,123,15,115,197,215,123,79,177,59,22,158,19,89,184,177,27,86,179,31,180,161,208,92,201,185,247,11,38,
23,6,145,128,9,51,203,146,173,140,11,114,125,146,238,54,178,238,55,155,110,218,63,178,146,96,94,158,106,185,35,246,116,143,154,46,150,211,100,158,228,184,88,80,85,143,200,15,243,3,214,246,159,0,58,6,155,
227,31,195,159,143,253,52,130,249,61,181,215,184,122,237,211,80,241,248,234,43,119,150,230,140,238,109,217,85,85,127,83,212,54,119,45,58,150,111,81,84,31,210,222,242,231,99,179,91,13,170,202,220,10,16,
128,159,180,228,254,202,211,174,33,243,247,48,73,205,60,229,204,59,228,135,182,107,151,211,154,209,20,233,65,254,242,163,163,137,236,219,160,135,94,247,238,189,215,189,251,175,117,239,126,235,221,123,
223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,127,255,212,223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,173,
47,243,230,219,57,168,59,35,227,7,96,230,241,207,95,214,137,183,187,15,97,209,214,213,204,104,246,246,35,178,179,25,13,179,153,199,225,115,25,102,34,151,1,83,216,91,103,19,89,141,162,171,153,163,141,170,
16,66,90,242,0,98,143,115,172,110,174,237,173,204,42,74,105,167,218,65,4,175,218,195,135,173,58,205,79,185,190,255,0,180,237,27,254,253,5,220,194,59,231,85,42,212,12,202,165,93,4,170,191,143,193,144,171,
176,244,53,234,169,55,118,216,248,85,186,168,215,41,179,112,63,35,118,38,230,20,209,201,154,216,89,77,169,69,91,182,177,245,107,8,251,136,105,183,93,84,244,216,234,124,114,200,9,19,74,225,116,27,147,111,
113,12,214,59,100,200,13,148,87,107,114,56,169,80,192,31,58,56,35,31,104,253,189,103,30,219,206,190,235,108,204,214,251,222,229,203,183,219,88,39,69,218,204,82,86,90,212,23,136,3,86,167,144,28,122,46,
84,189,93,141,237,138,131,178,250,139,1,188,59,83,36,42,132,41,180,186,215,102,228,187,170,88,166,44,250,105,242,85,152,250,63,238,14,18,160,21,245,31,190,212,135,146,125,168,176,229,173,218,89,3,91,22,
73,61,22,165,191,61,56,253,189,33,230,159,119,185,78,198,2,252,205,244,132,5,248,164,41,0,175,244,65,62,43,15,66,23,61,27,157,135,252,163,254,109,231,49,49,86,98,62,52,101,246,72,175,165,150,149,234,183,
62,253,234,237,135,184,165,162,149,74,201,77,60,88,244,222,25,220,85,60,160,217,224,15,16,96,108,69,189,140,83,145,121,142,238,32,179,203,41,67,228,116,39,237,21,175,237,234,8,151,239,51,237,46,201,124,
210,237,214,48,188,170,106,10,199,52,170,15,168,45,161,107,232,69,72,233,47,218,223,2,126,99,124,86,192,85,239,221,235,211,219,166,135,104,237,248,161,171,206,110,76,13,102,11,185,246,118,35,27,76,232,
166,163,115,210,109,186,44,110,234,196,224,161,86,180,245,49,82,206,176,165,217,133,129,62,202,119,31,111,247,59,8,254,163,194,58,70,73,226,7,219,166,180,251,105,78,134,252,191,247,169,228,174,113,184,
139,106,146,232,69,60,132,132,83,170,7,44,71,224,103,44,133,189,1,34,190,189,23,29,237,187,250,239,122,225,141,90,109,90,93,143,217,24,227,67,37,101,30,220,168,25,61,157,186,177,25,42,104,234,177,155,
143,111,228,98,188,115,99,50,84,172,36,140,139,125,72,54,32,128,9,220,34,72,152,47,129,225,204,13,8,31,14,60,255,0,63,231,199,172,146,228,59,173,234,224,234,77,200,222,108,46,13,26,76,75,19,121,163,15,
85,225,243,232,48,135,44,105,97,43,18,254,227,3,102,250,219,87,7,79,227,143,167,178,227,235,212,146,246,139,51,106,115,143,245,113,233,158,73,36,150,66,239,169,221,223,254,12,204,79,244,31,155,123,221,
20,130,43,74,116,178,52,210,2,47,75,174,144,232,254,217,249,87,190,170,186,247,166,34,131,17,130,192,201,31,250,83,238,252,212,58,246,47,87,99,174,26,122,104,170,24,172,57,221,237,60,55,251,106,8,139,
21,114,26,75,15,99,222,78,228,123,254,100,185,70,104,244,218,10,18,77,66,129,234,199,143,216,163,39,203,172,103,247,231,239,25,203,158,211,237,147,90,218,220,173,199,48,72,164,71,26,16,206,205,82,40,159,
132,0,126,57,27,181,56,45,91,134,205,255,0,15,126,31,108,126,162,219,143,176,126,62,237,234,141,183,142,201,8,155,176,187,167,55,23,159,177,187,55,39,26,255,0,148,87,213,229,106,23,207,21,45,68,204,205,
20,81,233,138,20,33,81,69,175,239,41,118,205,155,107,229,187,79,2,206,17,170,128,19,248,154,159,196,71,1,232,162,128,124,205,79,92,114,231,110,124,230,159,113,119,137,55,174,102,220,90,89,11,49,68,169,
240,226,13,196,70,190,190,178,26,179,122,211,29,9,255,0,34,254,84,252,96,248,3,136,139,2,180,231,179,187,183,48,158,124,94,194,193,213,46,79,53,87,95,33,43,29,78,225,158,19,60,180,49,73,53,174,173,121,
27,240,61,172,103,105,99,123,139,153,210,27,69,201,102,52,3,252,255,0,103,68,91,102,211,123,186,92,165,157,141,171,203,112,220,21,69,73,255,0,48,249,156,124,250,169,206,200,219,95,58,254,124,79,30,238,
249,35,188,87,161,122,58,103,106,205,187,176,38,121,241,80,190,44,128,244,241,209,109,74,87,76,150,110,113,9,31,189,84,18,59,242,77,189,146,67,125,189,110,243,27,94,81,218,255,0,71,206,230,97,64,125,74,
41,242,30,166,131,169,90,29,171,219,206,70,183,91,158,114,221,77,246,245,255,0,40,86,173,218,164,240,89,166,28,79,244,99,169,242,232,161,246,38,233,248,27,241,130,97,180,49,50,102,251,159,177,105,75,67,
62,223,218,203,73,185,243,191,116,139,232,21,203,68,127,187,219,82,6,110,74,205,44,211,219,232,188,123,36,221,96,228,125,129,218,227,156,119,233,183,93,224,26,152,97,112,34,67,198,142,255,0,0,244,32,22,
63,46,165,62,82,255,0,94,238,127,72,108,125,186,229,59,126,94,229,151,160,73,164,133,132,146,41,243,141,40,102,148,252,192,81,95,49,90,244,0,86,124,188,239,154,225,81,23,86,245,223,88,116,6,30,114,77,
62,75,41,66,119,223,98,45,49,186,249,38,150,97,14,42,130,164,142,84,34,233,67,193,95,96,91,207,124,126,137,90,215,148,54,91,75,72,87,1,163,140,59,143,249,187,32,57,251,19,172,145,229,239,184,165,254,240,
176,110,222,232,243,85,253,228,140,42,201,52,198,36,63,100,16,146,244,249,59,87,57,232,50,151,107,111,190,214,166,174,221,93,221,221,253,215,189,246,252,89,26,60,37,54,15,21,145,173,254,33,188,119,126,
97,244,97,54,78,202,218,88,22,164,130,187,49,150,156,89,85,21,82,8,131,73,33,10,164,251,0,95,115,191,57,243,61,226,90,181,236,179,92,200,216,12,236,192,84,208,118,212,1,232,0,92,249,14,165,139,191,104,
189,151,246,131,109,89,237,54,155,117,184,85,213,219,28,81,5,69,193,121,36,109,79,65,156,150,169,251,104,58,179,47,140,127,202,219,174,118,151,85,238,206,197,238,238,180,217,89,110,197,201,100,168,179,
120,238,187,220,19,73,184,170,186,231,106,34,199,71,71,131,169,205,77,57,143,59,186,242,50,204,38,200,60,90,163,134,99,226,91,133,212,103,254,65,246,236,82,210,211,126,183,142,231,119,185,112,50,49,18,
228,154,128,64,31,49,228,41,231,214,18,123,181,239,226,157,202,234,239,149,36,159,111,229,43,88,72,2,54,53,158,64,48,123,187,128,99,128,104,56,224,83,171,120,147,225,175,199,237,161,180,246,103,199,30,
188,248,247,211,53,157,183,190,49,244,91,143,178,119,238,79,174,118,205,117,78,193,194,228,82,26,145,138,197,85,213,99,229,170,165,175,142,145,132,104,35,99,167,212,231,150,22,61,230,13,191,97,186,220,
26,223,106,217,45,163,176,128,120,106,194,53,169,11,130,228,156,150,99,83,199,2,128,112,234,18,229,30,105,230,197,181,185,231,14,108,230,189,198,84,103,46,144,25,228,210,242,48,194,4,4,40,138,44,3,142,
227,83,208,205,242,19,226,55,197,142,160,248,254,152,44,119,69,117,61,102,70,26,72,41,219,55,85,177,112,15,151,169,173,144,47,154,160,214,154,69,148,153,29,174,5,248,28,15,109,89,108,187,73,157,17,182,
200,26,131,205,7,237,63,62,153,218,121,203,155,55,141,249,238,229,223,239,21,25,201,210,178,176,80,60,128,31,103,73,62,167,254,94,31,9,247,175,198,124,150,229,236,31,139,189,57,159,205,182,222,220,217,
58,124,173,78,211,163,167,200,137,41,49,181,85,20,229,42,105,26,9,1,134,72,129,22,34,222,203,119,253,135,99,101,189,145,118,184,84,164,76,65,81,76,133,36,17,159,151,70,51,123,135,206,246,156,209,105,107,
101,205,87,171,1,184,141,72,241,24,140,186,130,51,229,78,181,29,192,252,118,233,12,182,249,206,80,100,54,92,180,248,202,28,221,96,88,118,230,103,39,129,169,142,130,26,201,35,48,211,212,208,84,163,163,
199,15,232,185,62,165,30,225,46,68,250,109,206,249,224,221,145,229,133,104,78,150,208,218,107,154,17,192,211,135,207,174,155,251,137,182,73,103,202,86,151,155,25,75,109,218,107,112,3,184,241,80,74,80,
21,103,71,168,42,91,226,2,152,38,148,234,234,58,103,249,51,109,190,213,233,122,142,216,248,199,243,39,228,199,83,239,28,34,86,6,218,211,110,38,221,59,110,174,178,24,22,178,141,33,74,154,232,42,224,167,
170,164,113,107,137,24,72,165,109,249,247,48,221,242,115,237,247,172,187,71,49,93,197,102,244,104,216,146,106,141,149,56,35,236,56,226,15,88,1,184,123,198,209,93,254,236,231,111,110,182,91,199,174,137,
127,73,82,68,145,14,137,5,66,159,196,9,92,229,88,26,211,162,213,147,223,127,205,63,226,180,47,83,23,118,245,215,125,237,92,38,66,10,10,172,102,250,197,84,97,115,241,35,76,105,226,251,188,148,48,209,248,
23,200,129,26,83,51,105,99,115,199,191,110,115,115,151,44,237,243,238,119,55,246,247,187,92,50,70,175,169,59,148,73,80,140,198,129,130,18,10,150,213,131,78,142,182,238,79,246,95,220,45,226,199,98,219,
246,11,237,163,126,188,130,105,33,240,37,6,39,48,128,207,26,35,179,3,38,131,173,80,40,12,160,211,135,70,119,175,63,155,127,111,98,169,99,165,249,15,241,51,182,48,120,223,26,154,173,217,176,241,103,182,
54,81,140,11,205,87,36,88,100,200,214,211,210,34,139,150,96,192,47,215,221,237,57,202,202,230,32,251,174,205,52,80,159,244,72,199,139,31,230,8,44,7,251,110,129,251,247,176,119,123,116,238,188,177,206,
214,83,220,47,250,5,201,54,87,31,96,102,162,49,175,144,3,163,43,182,187,255,0,249,112,124,186,167,20,245,180,61,95,152,202,213,234,130,117,163,104,54,198,236,161,169,62,153,35,172,197,6,199,228,169,107,
33,99,102,71,140,176,63,143,102,11,181,242,174,254,130,91,57,109,103,39,128,86,9,32,255,0,107,131,208,42,91,223,119,253,186,155,77,242,238,150,104,162,186,156,52,144,17,234,36,80,200,87,211,32,83,164,
166,234,254,90,253,122,242,201,188,190,50,118,230,91,101,103,105,201,170,161,164,124,187,233,71,30,181,138,58,202,121,35,157,0,227,137,21,135,180,231,151,55,45,170,77,91,77,252,145,31,224,113,85,167,165,
79,31,183,163,184,189,226,181,223,225,91,62,121,229,187,91,251,102,160,50,70,2,201,233,90,140,215,164,141,47,200,255,0,159,255,0,25,221,112,61,141,182,176,125,231,179,233,45,25,57,188,98,205,95,45,34,
250,89,41,243,248,251,72,204,99,6,222,64,199,250,251,126,45,227,115,177,144,38,241,183,56,4,230,72,177,249,208,96,245,75,158,78,246,239,154,96,51,114,142,251,244,183,127,239,139,134,212,149,244,212,104,
203,246,210,131,215,168,25,254,195,254,83,95,50,103,143,17,242,131,161,215,162,123,34,167,76,71,119,190,63,248,5,109,53,113,255,0,119,80,239,124,4,116,213,148,229,102,228,52,162,255,0,75,251,87,38,209,
176,243,16,50,197,20,51,205,199,82,126,156,202,127,33,147,246,131,209,69,174,243,238,159,182,50,105,179,221,46,224,177,225,164,183,143,106,224,121,105,98,200,84,131,195,24,199,67,118,220,254,91,125,161,
73,178,50,56,223,130,31,204,251,178,234,186,239,47,68,148,235,214,253,147,147,192,247,126,194,24,241,34,212,83,227,163,254,39,36,251,135,25,4,78,131,73,133,145,150,223,143,100,195,150,175,182,217,252,
109,171,126,185,130,228,26,133,152,107,95,204,154,215,211,135,14,142,83,221,221,163,114,154,25,249,187,219,77,178,234,225,79,246,214,133,173,37,175,2,212,65,225,147,79,35,231,213,109,252,143,254,89,95,
205,218,106,13,205,183,231,163,234,158,221,216,155,163,33,71,146,222,56,142,174,204,46,196,174,223,82,98,204,50,81,210,103,233,247,2,193,89,62,53,165,165,73,37,162,89,197,60,142,57,186,251,13,238,251,
31,57,220,197,184,67,29,212,82,199,117,47,137,39,134,192,106,106,1,93,45,67,229,192,98,189,78,60,167,239,103,178,241,207,203,242,238,91,101,245,180,155,108,38,40,22,100,214,177,161,98,198,143,16,34,181,
99,221,77,64,116,75,242,125,67,243,139,173,222,182,14,195,248,81,222,114,87,73,165,38,200,224,233,241,57,250,117,138,8,150,158,24,160,108,125,108,209,10,122,106,116,9,26,47,165,84,0,7,184,186,255,0,219,
238,96,46,204,246,242,215,206,168,79,243,29,101,215,41,253,233,61,166,130,205,45,97,222,44,214,16,48,162,83,29,63,41,20,113,175,145,175,175,65,26,65,222,216,252,178,213,81,252,106,249,41,135,202,18,124,
109,79,176,235,214,169,15,213,144,75,76,204,65,184,191,178,207,234,55,48,169,2,56,31,87,250,71,7,252,29,12,230,251,199,251,65,123,9,55,187,133,164,145,122,52,240,17,255,0,26,97,142,132,12,31,91,252,159,
221,85,45,252,39,226,151,123,100,178,149,135,201,45,118,228,160,160,194,44,178,55,251,178,178,191,61,95,28,224,40,60,146,24,129,244,30,213,65,237,183,52,220,184,209,183,202,73,226,116,55,252,252,7,69,
183,223,123,127,101,246,155,113,254,238,173,192,81,64,137,34,17,143,64,138,71,236,61,14,59,107,224,119,207,77,247,61,60,49,108,46,179,234,250,57,207,238,214,238,221,223,46,231,201,210,171,113,171,248,
38,220,164,125,115,47,225,25,180,147,245,32,123,19,217,123,51,190,74,87,235,89,35,95,233,58,175,237,2,173,252,186,136,249,143,239,237,200,182,201,34,114,246,221,61,196,222,68,68,198,191,97,114,169,254,
30,172,59,160,191,145,109,102,226,174,163,205,247,254,247,222,157,186,242,60,18,213,237,120,12,155,3,171,200,91,55,219,214,225,241,243,140,182,122,136,17,204,53,19,120,228,31,85,30,228,109,159,219,126,
95,218,21,90,250,227,199,144,126,21,170,169,35,213,143,115,126,84,31,46,61,98,71,184,63,123,111,112,249,202,105,70,211,109,22,223,17,168,18,61,37,153,71,252,44,80,71,25,244,33,73,30,189,92,251,108,239,
137,31,2,186,246,158,191,176,115,219,3,173,118,206,18,158,216,205,185,69,21,6,27,27,28,203,29,252,88,173,191,64,162,122,250,217,52,219,81,70,118,60,150,39,216,246,61,41,8,183,177,183,72,108,215,240,168,
160,199,159,219,243,36,159,159,88,211,44,187,182,253,184,189,205,229,205,197,246,239,41,203,187,25,36,99,228,42,120,15,64,40,7,144,234,134,254,90,124,196,236,127,159,249,60,246,55,103,238,234,111,141,
127,0,186,250,80,123,47,184,119,116,191,192,169,51,20,84,151,121,139,68,12,117,121,188,166,69,19,199,140,195,82,7,158,121,89,117,40,23,33,168,119,189,163,110,250,155,155,171,128,86,1,82,220,87,81,224,
163,213,143,167,151,159,82,36,190,218,115,38,223,111,180,90,190,220,239,204,187,147,17,13,168,7,198,209,138,202,201,79,211,139,63,27,149,173,13,58,31,63,150,39,195,156,207,203,46,216,235,127,148,219,251,
96,102,186,195,225,63,198,73,171,32,248,59,210,187,170,137,233,51,61,137,185,230,101,143,43,242,59,176,49,213,49,171,86,100,119,20,145,125,212,15,50,216,179,71,28,63,179,13,216,9,20,151,220,221,188,29,
251,114,66,155,124,100,248,49,158,6,135,7,231,234,79,153,192,192,232,111,205,87,251,63,181,124,165,63,183,188,185,119,29,199,54,223,168,59,165,210,100,32,227,244,177,154,156,10,209,168,124,179,199,173,
169,191,195,216,195,172,119,235,222,253,215,186,247,191,117,238,189,239,221,123,168,213,148,180,213,180,149,84,117,148,240,85,209,213,211,205,77,87,75,83,26,77,77,83,77,60,109,21,69,61,68,50,43,71,52,
19,68,229,93,88,16,202,72,62,244,84,48,42,194,170,69,8,249,117,181,102,70,87,70,33,193,168,35,136,35,129,29,105,195,252,195,126,25,212,124,18,165,223,216,1,131,200,230,62,14,118,230,252,169,222,125,105,
189,104,227,106,152,254,42,246,102,232,172,105,50,125,125,186,32,83,36,244,189,115,186,50,210,249,113,89,4,30,42,105,100,48,75,111,73,48,215,54,114,244,246,11,33,183,140,189,139,54,164,62,104,127,131,
254,129,245,251,122,232,119,221,255,0,221,251,110,100,155,111,176,220,238,196,92,217,111,24,71,13,194,234,37,20,18,3,230,234,184,145,114,77,53,15,65,82,148,93,117,151,160,172,130,150,182,40,170,41,107,
225,18,82,84,163,44,244,57,92,117,74,144,181,20,178,199,174,26,138,90,136,155,234,164,131,244,247,20,79,57,141,168,84,171,143,94,186,7,181,45,181,252,43,44,82,44,150,228,80,230,160,130,50,15,228,122,21,
223,227,198,228,195,237,122,122,177,65,83,38,18,21,63,195,229,149,11,26,122,54,33,162,164,50,88,25,35,166,190,152,216,242,16,0,126,158,216,107,153,11,120,229,105,95,63,83,235,211,54,55,27,42,205,251,154,
27,224,210,70,78,133,39,42,190,73,95,48,188,7,203,160,151,43,180,151,29,4,174,83,212,170,127,198,228,1,123,125,8,2,255,0,159,110,37,203,179,113,199,70,55,150,62,12,76,104,52,244,98,254,30,108,92,14,254,
238,239,139,187,79,116,136,167,218,155,147,229,55,94,209,110,74,25,185,143,33,79,131,165,204,238,92,93,28,166,246,48,201,151,196,194,72,32,135,210,7,179,94,90,72,174,57,215,106,182,153,106,52,18,63,106,
131,214,58,125,224,55,107,205,179,218,158,107,150,200,210,113,110,64,35,141,24,133,63,241,146,127,46,190,129,10,44,63,219,255,0,176,23,54,3,129,192,30,242,175,135,14,29,113,183,237,227,215,47,126,235,
221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,255,213,223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,
123,223,186,247,94,247,238,189,215,189,251,175,116,138,236,14,186,216,157,171,180,51,91,11,178,246,150,223,223,91,43,113,82,53,22,115,108,110,124,101,54,103,13,147,167,39,80,90,154,42,216,230,141,158,
39,179,70,224,7,141,192,101,32,128,125,179,60,16,220,196,208,220,68,175,17,226,8,168,255,0,87,207,165,150,27,133,246,215,119,13,246,221,119,36,23,145,154,171,163,21,96,126,68,103,162,47,31,242,147,254,
94,81,214,211,214,55,198,173,177,93,21,45,76,53,80,225,242,251,135,124,230,118,226,60,46,30,56,142,219,204,110,106,236,27,211,33,2,208,181,57,142,220,90,222,201,199,44,236,129,131,125,16,175,250,102,35,
246,22,232,118,222,238,251,142,209,24,127,173,151,33,72,165,70,133,111,79,137,84,48,63,58,215,163,227,179,118,30,201,235,172,29,38,217,216,59,75,110,108,173,187,65,20,80,81,224,246,174,23,29,129,197,83,
69,10,120,227,72,232,177,116,212,176,13,43,249,181,253,156,195,4,54,232,35,130,37,72,199,146,128,7,242,232,3,119,123,121,127,51,220,223,93,73,53,195,26,150,118,102,98,78,77,73,36,244,172,255,0,98,71,251,
239,241,191,183,122,77,213,29,127,52,223,159,125,213,209,61,165,213,31,25,62,61,62,197,219,219,179,177,54,173,126,242,223,29,139,216,152,218,44,190,23,110,109,154,172,212,27,75,111,225,104,177,217,121,
161,193,125,206,127,47,60,191,115,85,92,36,166,167,167,138,197,9,127,113,247,59,115,77,206,198,176,91,89,170,248,210,80,18,212,167,113,160,21,110,208,48,73,39,228,58,201,79,96,189,157,217,253,197,143,
152,55,190,98,185,184,93,175,111,66,193,32,4,200,197,87,91,16,23,189,138,138,81,87,36,159,151,90,193,103,186,123,31,177,114,117,88,205,239,190,240,85,89,154,65,90,180,187,95,171,141,63,101,238,10,244,
172,203,100,51,21,19,32,218,241,141,187,130,198,182,75,41,47,134,21,100,134,154,29,49,198,2,168,247,2,110,17,203,60,242,79,125,115,18,185,63,10,176,127,200,21,168,167,206,189,117,15,146,57,147,111,217,
249,126,210,199,149,54,139,187,139,96,6,171,139,181,54,168,40,0,165,36,239,102,160,0,226,164,228,244,13,110,42,236,78,30,166,40,151,31,188,113,208,205,38,132,151,115,96,101,198,130,252,217,86,72,252,176,
234,176,228,18,8,246,82,208,86,186,24,31,240,245,40,109,156,203,21,218,255,0,142,73,110,175,253,7,212,63,105,255,0,15,66,7,199,110,133,223,31,49,247,198,67,102,108,12,173,86,212,235,45,175,52,9,218,189,
195,5,19,213,125,152,157,133,182,63,95,161,2,28,190,246,202,68,10,153,1,49,208,161,46,255,0,65,238,69,228,94,66,187,230,27,161,45,200,209,107,29,25,139,12,40,242,168,243,99,248,86,191,51,65,214,54,253,
227,62,242,155,71,182,155,59,109,155,33,23,27,237,192,101,69,86,161,122,97,190,107,10,240,103,193,115,84,90,113,235,107,158,130,248,161,176,250,87,169,48,155,91,23,137,198,117,159,76,236,122,119,200,69,
138,201,214,165,60,85,117,122,68,217,29,215,189,243,21,44,143,155,220,25,23,83,44,178,72,198,204,116,168,0,15,121,61,103,111,99,179,219,69,183,109,176,210,53,252,203,19,197,137,243,99,254,96,49,215,31,
183,253,255,0,122,230,205,230,239,127,230,11,163,62,231,57,203,112,10,163,130,34,240,84,81,128,0,249,156,215,160,223,113,252,165,236,31,144,147,229,250,75,224,132,16,99,232,113,49,203,79,190,126,69,238,
56,14,59,101,237,204,124,87,138,174,61,176,204,163,239,171,52,92,164,159,64,5,199,183,101,211,108,224,220,47,137,116,223,12,99,252,46,124,135,84,182,177,82,159,83,121,39,135,102,13,43,74,150,62,136,60,
207,242,232,135,239,157,243,240,251,249,110,210,84,239,77,207,184,71,119,124,141,220,245,19,205,85,217,155,170,145,119,110,234,204,229,141,252,244,221,105,180,106,30,84,167,163,138,160,233,254,37,85,166,
20,54,210,79,180,59,172,219,70,219,20,27,151,56,93,84,82,177,91,32,5,143,204,33,52,11,235,36,159,106,131,78,135,156,169,178,115,159,61,79,62,195,237,238,219,224,109,202,64,158,225,201,84,90,224,248,179,
12,179,28,145,12,89,168,165,58,33,59,55,183,114,31,204,31,179,55,102,55,229,119,202,218,15,133,189,73,75,73,54,111,13,215,19,100,107,177,59,243,185,233,252,77,83,5,53,127,103,86,164,24,12,69,56,210,171,
61,52,83,70,241,242,145,65,244,115,31,127,94,71,59,92,61,139,111,16,237,220,183,27,80,193,9,163,48,31,239,201,56,177,167,18,72,90,154,40,235,35,183,15,102,174,253,133,177,219,55,11,127,111,174,247,222,
115,185,141,91,235,110,35,172,54,225,169,152,109,197,120,241,4,141,92,11,176,38,128,20,206,226,250,59,110,103,183,212,157,5,182,177,216,190,177,164,219,248,30,188,218,59,130,154,26,134,125,249,156,162,
202,86,101,119,142,240,167,201,100,151,248,158,102,154,25,30,42,81,94,246,74,137,3,104,186,139,251,133,189,217,188,229,249,183,43,13,171,151,64,54,118,233,220,65,39,83,121,179,87,36,159,157,62,206,179,
99,238,173,178,243,172,237,119,204,220,214,243,11,169,91,87,112,11,161,120,36,106,5,2,143,232,142,30,125,3,245,104,125,109,96,92,222,196,112,205,197,129,184,231,146,121,246,3,178,93,33,43,192,14,178,191,
125,184,118,98,133,141,43,213,154,124,33,164,219,248,47,144,52,89,157,193,79,60,216,94,132,235,189,187,38,218,113,78,181,116,184,254,210,237,120,106,50,89,141,223,91,68,202,124,245,152,237,177,75,29,12,
50,15,220,130,41,156,161,5,143,188,128,246,103,101,142,234,77,203,123,116,83,44,120,74,230,133,171,66,62,202,26,124,207,203,174,95,253,233,55,237,195,118,152,236,176,201,165,39,153,181,173,126,40,161,
34,136,62,76,228,18,60,233,158,174,127,127,195,138,200,237,250,61,251,181,154,158,187,111,174,87,15,95,155,131,31,50,213,65,69,81,67,147,166,171,171,87,84,38,88,232,107,98,82,202,28,112,215,83,207,188,
159,229,9,146,29,254,218,41,216,6,116,145,20,159,38,116,33,77,125,107,215,62,249,222,222,232,242,206,229,104,200,222,60,45,28,148,167,196,136,224,183,218,64,201,167,144,61,14,89,92,157,94,15,229,77,70,
81,235,24,82,110,201,177,21,244,245,107,117,18,225,242,116,20,149,84,130,38,6,198,33,17,210,44,108,0,183,176,171,69,166,222,88,89,105,34,51,43,125,170,72,61,31,219,152,239,57,98,221,147,33,80,112,206,
72,235,47,206,237,213,75,95,182,112,216,74,26,135,145,215,44,173,88,16,130,139,2,170,24,149,191,4,27,123,246,220,164,202,206,195,203,167,57,62,217,146,230,73,29,127,14,62,222,148,20,61,173,138,217,191,
27,246,238,14,103,142,33,147,218,217,154,57,9,127,24,85,172,198,212,211,177,39,210,5,204,163,252,61,146,239,237,225,88,110,211,55,194,34,97,251,69,58,81,183,237,18,238,28,219,3,32,37,150,225,8,31,233,
92,31,242,117,167,254,210,45,22,243,221,114,33,190,140,166,73,65,23,185,242,100,38,84,91,216,222,224,216,127,95,120,249,237,186,215,115,185,32,118,172,96,255,0,62,186,219,238,32,215,202,251,12,116,238,
40,152,249,132,21,255,0,103,211,207,173,177,191,149,110,11,114,224,182,118,82,25,226,154,61,191,85,137,160,154,116,152,50,160,201,151,47,23,140,48,177,144,65,43,6,31,128,125,229,6,229,3,89,237,251,37,
156,227,252,113,45,193,97,230,186,201,117,83,246,3,252,250,228,47,63,238,150,59,223,49,243,38,235,98,65,182,151,113,113,27,14,14,35,69,141,228,30,161,157,112,124,233,94,132,159,145,63,5,113,157,153,144,
206,214,237,172,142,14,138,45,200,181,3,45,132,203,63,142,146,103,170,37,165,101,210,46,154,164,55,254,183,231,223,173,47,236,254,158,246,195,118,179,51,237,87,80,152,102,78,5,163,108,225,188,153,26,140,
135,200,142,138,109,57,143,113,180,27,69,213,133,219,219,239,155,117,202,92,90,92,40,213,225,74,152,238,92,106,71,82,82,69,243,82,122,170,204,167,242,222,249,127,210,185,121,242,253,75,156,173,92,48,148,
207,30,55,31,86,114,240,68,80,150,79,10,83,213,37,67,69,199,209,161,60,125,111,236,4,190,223,219,109,147,201,63,41,115,243,91,218,183,250,13,220,18,84,127,68,188,122,212,143,157,1,245,235,34,135,222,91,
102,230,203,24,172,125,203,246,157,46,247,37,90,125,77,141,196,74,27,20,36,199,58,163,3,242,212,105,208,123,216,221,57,182,123,30,149,241,95,49,254,51,236,28,190,233,167,210,41,187,87,111,108,172,199,
93,246,93,52,200,52,173,75,238,189,177,143,197,53,85,68,95,168,75,47,145,175,245,39,159,107,45,249,127,106,184,118,143,127,220,246,102,186,165,4,144,201,36,79,251,60,53,161,251,107,209,66,115,124,150,
76,46,61,183,139,152,237,246,230,248,173,103,16,93,91,144,120,143,15,199,124,30,24,31,179,162,251,7,70,246,111,95,206,42,190,37,252,177,220,213,240,68,73,139,171,123,237,36,222,152,104,160,95,87,218,81,
239,74,20,161,220,244,2,61,58,84,200,179,88,125,111,111,102,49,217,238,86,14,35,216,57,194,43,180,242,134,98,179,46,60,131,211,88,199,157,7,76,92,195,202,252,197,27,73,206,190,217,203,99,112,69,77,213,
138,181,164,149,63,137,161,36,194,254,180,30,124,122,22,191,217,132,249,127,212,155,46,147,119,252,144,248,177,189,170,122,238,115,60,82,246,183,78,86,210,118,214,204,69,165,151,193,81,62,79,9,76,241,
110,220,60,113,191,234,19,83,181,129,250,251,85,31,51,95,65,43,91,111,156,171,50,186,241,123,111,213,74,82,186,180,101,169,78,53,60,58,2,95,251,97,203,183,151,14,156,155,238,69,171,92,84,5,183,220,1,179,
154,173,240,168,154,134,18,79,1,145,83,78,147,212,159,36,62,7,252,148,165,108,69,110,224,235,236,142,78,169,108,212,85,98,29,187,159,66,194,204,13,46,74,42,73,76,200,215,5,121,33,189,214,27,222,74,222,
153,30,203,116,138,59,179,192,230,23,4,253,180,24,244,39,166,110,249,115,222,110,69,71,77,211,151,175,155,109,4,134,82,191,83,9,3,228,43,143,58,208,99,164,37,87,196,93,187,140,174,59,143,227,127,200,13,
237,212,57,112,77,69,55,240,77,193,89,75,64,242,3,174,53,49,83,212,61,20,177,222,214,226,214,246,45,182,182,220,173,208,44,206,151,150,116,197,64,36,124,245,46,15,237,234,63,220,55,125,163,113,102,50,
237,230,203,112,7,58,1,85,63,45,13,74,126,66,157,63,208,252,171,254,111,63,27,229,74,104,55,254,212,249,1,182,41,180,248,63,188,212,148,149,85,181,20,137,96,170,245,104,18,93,108,162,196,147,123,251,122,
91,93,142,78,233,212,192,223,200,116,85,4,55,243,146,45,19,199,31,33,159,229,208,245,179,191,158,63,201,124,83,71,71,219,191,10,215,41,160,133,168,171,218,57,105,32,184,28,72,203,12,236,209,139,158,64,
250,115,237,23,238,237,184,230,219,124,140,1,253,42,31,240,244,251,109,219,159,9,118,59,129,255,0,54,203,127,144,244,62,81,255,0,59,111,139,181,169,25,236,239,141,157,187,180,107,220,15,42,199,142,165,
202,66,163,242,218,225,145,73,0,143,109,61,148,168,11,38,241,17,95,249,169,254,207,78,65,178,223,93,58,199,6,199,112,239,232,33,127,242,47,78,53,63,206,123,249,124,197,17,154,159,172,59,74,186,113,98,
148,191,221,136,99,4,219,133,215,53,72,141,121,255,0,94,222,209,202,76,74,76,219,204,1,125,117,255,0,155,163,251,46,65,230,219,233,132,54,92,165,122,242,249,82,7,31,46,58,71,65,142,234,254,125,61,25,183,
41,138,117,23,197,157,199,152,202,144,68,83,238,124,174,35,7,68,27,146,166,68,166,134,178,161,137,63,91,105,62,200,174,55,189,142,18,60,125,237,95,228,128,177,255,0,87,237,234,68,218,190,239,30,236,238,
128,57,229,134,182,131,248,231,116,140,127,51,94,139,246,123,249,177,127,49,239,146,84,245,123,123,163,250,163,5,214,56,218,212,146,23,204,109,140,54,67,43,87,142,164,123,169,150,77,203,159,72,113,120,
241,20,100,147,40,0,47,214,254,203,91,152,82,86,41,180,108,243,206,195,241,56,160,31,51,228,7,219,78,134,176,123,13,202,252,187,26,92,251,137,238,69,141,181,50,208,219,159,22,67,234,160,3,82,126,202,245,
84,29,233,188,54,94,202,220,19,110,143,148,253,217,146,249,23,218,212,242,52,243,245,86,195,221,67,117,203,139,168,190,162,187,211,124,249,103,219,27,70,159,201,233,48,83,121,106,143,42,21,120,62,194,
219,191,48,221,57,240,183,29,196,100,154,67,1,225,242,103,21,80,61,105,169,190,206,166,158,77,217,57,126,194,6,62,215,114,57,133,66,247,110,219,156,100,156,240,104,45,200,212,204,127,9,106,47,165,122,
11,247,47,247,243,191,226,216,155,163,126,239,156,55,79,108,173,181,91,6,111,171,186,51,15,178,235,119,14,197,217,177,193,50,205,141,205,110,28,101,115,37,6,231,205,228,66,44,181,53,21,169,51,202,190,
157,42,188,24,147,120,231,9,205,203,91,91,237,229,237,98,56,10,244,64,120,154,3,93,77,234,199,36,252,186,159,57,115,217,237,193,44,46,183,89,100,123,141,222,249,63,94,230,98,69,204,170,112,0,43,253,140,
96,124,17,165,40,56,231,171,170,232,191,231,25,242,243,226,178,224,242,63,43,35,216,95,41,126,46,153,40,112,249,62,214,233,93,187,69,181,187,23,171,41,157,86,151,27,38,99,100,99,162,199,225,170,240,244,
241,133,95,26,195,31,10,21,101,83,233,34,142,88,247,68,220,220,11,27,216,220,72,7,246,108,21,90,131,31,166,194,138,212,244,63,151,88,217,238,39,221,119,109,49,207,55,46,25,108,119,156,210,57,93,164,134,
86,201,35,91,2,232,196,240,36,176,175,30,182,166,233,174,228,235,95,144,29,107,180,251,119,168,183,102,47,123,117,254,244,197,193,149,192,110,12,76,194,88,42,32,149,71,146,158,166,62,37,162,200,209,202,
12,117,20,242,170,203,12,170,85,128,35,220,217,107,119,111,123,2,92,219,72,26,22,224,71,243,7,208,143,49,214,16,239,27,62,229,176,110,87,123,70,239,104,240,110,16,62,151,70,20,32,250,252,193,25,4,96,142,
132,255,0,106,58,44,235,222,253,215,186,247,191,117,238,189,239,221,123,162,201,243,63,170,112,29,221,241,63,228,63,87,110,108,124,89,60,78,238,234,29,245,68,212,178,196,178,222,186,155,1,91,144,196,205,
24,96,74,79,77,148,164,134,72,221,125,72,202,8,228,123,45,221,237,214,235,107,190,133,135,24,152,143,180,10,131,251,64,232,73,201,251,172,251,39,53,114,254,235,109,33,89,97,187,140,212,122,106,1,191,106,
146,58,209,183,172,35,198,85,124,111,248,215,187,226,160,134,139,49,81,135,168,219,91,156,211,180,130,10,204,190,215,202,213,225,170,107,12,12,237,12,21,51,201,71,251,186,2,135,97,114,61,227,47,48,70,
53,65,40,2,164,127,179,215,106,189,174,188,160,223,44,149,207,132,87,90,231,133,69,69,63,35,213,240,109,253,173,183,247,87,199,106,56,222,138,25,38,108,71,165,252,106,89,100,16,253,65,250,253,127,219,
123,50,130,214,27,141,137,6,129,174,149,175,207,172,125,188,222,119,13,167,220,217,221,103,97,24,151,133,113,74,245,68,157,169,134,108,86,67,51,68,87,74,211,212,84,32,91,31,166,166,3,159,240,246,14,133,
74,190,130,115,94,179,101,110,150,243,106,130,224,26,235,140,31,229,210,127,227,198,252,93,129,190,58,219,119,202,192,71,214,191,33,122,91,127,213,2,250,45,134,135,120,83,96,115,151,126,116,32,199,230,
28,179,126,5,253,156,237,146,139,46,108,229,251,211,240,146,83,243,168,97,95,217,78,177,255,0,222,93,161,247,175,111,185,171,111,74,151,123,73,41,138,228,41,97,254,14,190,136,200,235,34,43,161,12,142,
170,234,202,65,12,172,53,2,8,184,32,131,239,44,65,168,7,174,45,82,152,243,235,151,189,245,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,
253,215,186,255,214,223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,
175,117,82,191,205,131,226,23,72,119,31,76,110,15,145,61,131,187,51,189,97,188,126,59,108,13,227,154,160,223,251,111,25,140,207,156,174,207,20,163,39,149,235,221,211,181,115,81,190,43,116,96,51,185,42,
56,60,49,200,98,150,154,168,172,145,200,188,220,39,205,187,46,223,185,109,243,92,94,96,196,135,52,173,71,240,145,246,240,166,69,79,83,71,178,190,226,115,111,37,243,45,166,219,203,90,100,23,243,198,134,
54,37,64,114,116,137,21,151,42,84,19,94,33,134,8,61,107,185,241,43,224,14,127,229,135,199,10,30,242,220,93,155,155,165,173,124,26,110,120,122,19,167,112,248,61,143,50,226,178,6,106,140,60,242,154,41,41,
14,87,51,145,198,162,178,181,92,205,25,152,152,195,40,231,218,14,80,228,126,91,139,110,131,118,187,219,77,205,228,168,89,98,213,64,20,26,14,52,36,154,96,18,23,128,175,159,82,191,188,94,253,115,218,243,
85,255,0,42,109,155,176,180,176,182,152,66,215,140,12,140,206,20,107,226,52,199,26,177,206,149,47,164,87,160,159,174,191,150,239,122,119,15,100,85,237,186,253,185,219,93,25,241,211,27,149,100,220,121,
158,197,204,165,55,101,111,204,84,101,146,124,6,23,107,81,101,51,56,156,20,117,132,90,92,148,178,137,34,91,148,228,143,107,46,121,70,199,152,111,237,158,30,87,93,171,106,136,213,221,207,234,73,242,68,
169,3,228,114,62,103,164,22,126,244,94,114,22,193,118,38,247,0,243,47,55,221,71,72,161,137,79,210,90,215,241,205,41,84,121,79,252,44,10,28,3,213,206,63,126,252,72,254,95,155,19,15,215,91,31,108,226,119,
30,231,195,82,125,166,202,234,30,190,141,114,21,75,146,147,74,61,94,106,166,157,102,145,242,21,211,141,85,53,82,153,39,153,239,207,211,220,129,99,111,104,145,199,183,108,208,170,90,33,205,56,124,217,155,
204,154,103,246,112,235,28,119,67,204,91,245,229,207,49,243,77,228,143,125,54,76,146,252,76,60,150,52,252,40,7,194,160,0,63,159,65,205,23,89,252,177,249,201,228,237,175,153,91,218,127,143,159,23,113,146,
12,173,23,85,82,214,54,220,138,171,19,1,242,71,14,70,61,112,212,212,207,89,16,176,242,146,206,205,233,82,79,181,243,58,219,82,219,110,80,110,124,228,165,79,216,163,252,189,23,66,246,80,126,164,136,100,
127,194,158,95,107,159,242,14,139,63,205,159,230,59,179,122,31,104,99,254,57,124,68,217,216,218,9,107,34,142,155,5,183,105,144,253,204,180,202,166,52,221,219,237,233,200,168,143,29,33,93,116,212,82,58,
201,82,222,169,10,160,246,15,230,110,101,177,228,216,28,7,73,119,231,5,136,99,81,16,167,199,39,29,78,127,10,126,100,112,234,103,246,135,217,237,247,221,237,226,11,139,212,157,57,101,31,64,104,198,151,
185,113,254,131,111,232,163,30,36,212,162,240,6,188,41,42,143,13,158,220,155,166,183,179,123,91,59,83,190,251,67,46,68,181,185,188,155,137,40,241,49,169,188,56,188,21,23,20,212,52,116,67,210,139,26,133,
95,236,143,207,188,85,230,94,104,220,249,130,238,226,105,238,221,150,67,86,99,241,63,253,2,190,138,40,0,235,179,30,209,251,49,202,190,219,237,27,117,188,59,92,2,242,17,84,141,70,168,160,39,204,87,251,
89,255,0,142,103,169,36,157,61,8,232,240,84,32,90,184,41,171,98,45,171,195,89,75,5,108,74,234,110,31,197,83,28,136,15,248,129,248,246,7,42,240,19,224,179,41,62,98,163,249,142,167,123,152,45,247,8,196,
87,144,36,177,241,163,128,223,225,233,202,171,35,53,93,188,242,52,190,40,210,24,85,202,172,113,64,131,74,67,79,18,217,32,137,7,209,84,0,61,180,20,135,169,36,177,63,105,61,122,222,214,11,88,196,118,209,
36,113,143,37,0,15,229,211,37,66,25,57,31,91,19,112,9,60,126,109,253,120,255,0,97,236,226,217,128,160,39,29,6,183,120,170,204,79,175,71,27,170,190,73,237,126,141,220,155,238,124,198,210,202,111,140,183,
122,108,190,177,168,235,92,38,42,104,241,244,245,123,199,101,197,93,180,247,61,30,111,63,84,146,81,237,220,54,30,142,88,170,234,170,29,93,140,39,208,140,214,30,230,207,109,121,194,207,150,182,109,224,
93,70,207,37,87,74,131,64,90,166,149,62,66,135,237,62,94,189,115,143,222,223,107,57,139,154,249,223,108,182,218,25,80,35,204,100,98,9,164,109,70,4,40,248,137,35,77,61,114,113,210,163,45,242,27,190,113,
85,121,41,246,255,0,113,117,198,38,90,208,235,87,179,182,215,90,231,242,187,14,88,157,9,108,109,110,233,175,202,193,153,202,178,19,161,234,99,167,85,45,118,68,181,135,179,59,143,121,55,101,187,18,65,28,
94,26,144,64,9,128,71,12,177,212,79,207,165,59,127,221,68,110,59,106,157,202,35,173,148,230,73,128,147,34,135,181,84,162,212,126,31,200,245,102,31,29,62,105,225,62,71,236,253,187,181,183,21,4,123,59,228,
127,65,98,169,49,251,147,111,138,193,93,137,223,93,105,81,82,98,219,155,251,98,229,220,69,54,95,23,135,172,99,69,93,4,170,149,116,90,163,242,46,147,127,114,198,195,207,91,119,58,220,93,221,67,111,224,
94,72,161,228,142,189,186,248,59,39,200,225,136,242,36,249,10,245,136,92,233,236,151,50,123,47,123,38,201,186,202,110,57,126,225,219,233,166,165,10,129,82,34,144,112,212,6,21,133,67,83,215,29,24,126,204,
220,53,155,167,110,215,213,100,193,146,166,70,162,120,202,250,130,180,63,182,225,79,36,27,126,61,137,225,80,142,0,232,25,183,66,182,215,72,177,252,52,62,125,19,222,253,249,107,212,219,87,175,167,216,251,
215,127,109,141,191,159,197,109,202,234,124,118,222,147,37,247,57,250,154,135,136,248,203,226,113,235,83,91,76,172,223,218,149,80,1,207,211,216,75,157,239,108,109,118,77,214,213,238,227,250,233,35,33,
99,175,121,39,134,60,190,210,71,82,95,183,188,173,185,92,243,86,215,185,195,101,43,109,198,229,76,146,149,62,26,168,57,53,224,127,42,244,75,255,0,151,55,70,75,242,39,177,107,178,52,176,199,152,198,45,
92,21,116,77,22,154,154,73,167,158,83,47,241,9,52,29,50,193,72,167,208,27,131,37,239,250,125,129,61,153,180,181,219,223,117,222,119,27,97,36,241,0,177,70,223,9,144,228,51,143,52,142,154,169,193,141,6,
115,214,68,253,240,121,194,234,207,151,121,103,149,246,13,211,192,181,187,82,247,55,17,158,225,108,6,159,6,6,252,50,78,106,140,195,41,30,174,4,142,182,91,237,126,236,219,127,18,186,238,155,171,122,254,
92,124,219,210,150,129,170,55,6,89,213,36,167,192,234,135,92,181,149,95,216,155,32,99,31,180,134,225,0,185,30,230,171,27,25,119,187,155,189,195,112,185,240,237,81,26,89,230,126,10,131,226,99,246,240,81,
230,72,29,115,167,192,18,11,73,150,193,221,36,145,109,236,237,98,248,231,148,225,34,143,141,20,101,164,115,240,168,98,79,84,45,159,249,33,222,157,173,184,242,245,116,83,212,209,109,202,106,201,222,44,
214,230,203,230,95,37,154,125,108,205,61,61,21,29,77,52,52,169,51,11,162,168,37,86,220,251,137,247,46,115,159,124,187,158,29,131,148,172,227,217,97,36,44,183,90,228,154,81,192,49,80,193,84,183,16,21,70,
154,241,61,102,94,209,236,214,193,202,27,69,148,188,217,207,55,179,115,76,232,25,237,182,229,134,27,107,83,74,232,214,241,188,146,233,248,89,157,187,136,38,128,116,46,236,159,145,127,33,246,14,26,76,224,
236,170,237,161,138,161,96,101,171,220,27,190,106,44,10,197,18,151,12,178,238,63,185,166,81,161,127,69,201,183,208,31,102,123,92,183,207,108,110,103,216,96,134,37,243,19,201,10,159,244,186,245,40,254,
125,4,185,143,147,185,78,107,177,105,14,247,53,196,173,192,53,164,19,73,95,159,132,99,99,246,227,237,233,73,65,252,230,50,24,233,215,13,184,187,127,170,183,58,163,120,94,108,174,42,147,41,140,152,169,
210,234,114,163,23,139,162,101,123,216,176,125,63,227,239,109,204,60,182,242,120,15,119,60,51,127,18,73,13,202,254,198,72,152,231,250,93,7,91,217,77,233,20,221,89,91,69,42,82,161,74,93,90,55,237,87,157,
70,63,163,249,116,43,255,0,179,183,177,55,237,44,25,220,167,70,116,238,228,165,148,43,127,120,118,77,102,75,0,39,70,0,150,151,39,129,159,43,141,70,147,235,105,52,240,125,152,37,251,64,162,91,13,242,205,
151,254,29,111,36,63,182,68,50,160,63,110,58,45,78,72,222,162,50,91,207,6,236,154,120,136,110,32,188,167,250,88,101,16,202,64,244,227,209,151,131,229,239,93,230,250,107,108,109,205,165,214,149,155,14,
185,59,35,110,224,101,216,181,213,113,101,240,187,199,9,186,107,63,134,103,225,198,100,85,139,101,161,175,160,175,242,3,163,82,74,128,240,87,218,45,215,123,222,246,184,109,183,87,136,219,238,113,93,69,
164,6,12,146,171,26,106,141,199,108,145,145,90,211,230,8,199,69,86,94,221,90,111,59,166,237,107,117,186,174,225,179,79,182,220,23,144,198,209,203,109,36,75,80,179,68,194,176,74,172,160,0,77,40,65,4,130,
15,90,197,252,249,248,201,215,93,53,242,207,176,250,226,92,46,47,47,181,114,25,58,188,254,11,205,75,28,85,24,245,169,171,34,190,142,41,224,241,203,11,67,60,170,195,75,112,206,192,112,61,199,62,234,108,
223,184,57,148,93,109,117,138,199,112,183,75,164,65,193,12,132,137,17,65,252,33,193,43,232,8,30,93,103,71,221,79,157,19,220,207,107,237,109,249,166,36,184,222,246,123,131,183,77,49,168,121,146,37,13,4,
165,129,174,179,17,10,228,241,43,95,62,129,92,23,84,215,109,228,74,158,169,238,46,205,235,121,120,101,161,160,220,85,89,172,18,144,47,167,248,94,70,83,18,198,183,182,144,109,111,96,45,191,157,121,131,
104,127,241,107,201,86,135,240,51,47,242,4,131,249,245,61,243,7,221,235,219,78,113,143,85,222,209,1,144,255,0,191,98,142,79,216,212,87,31,110,175,207,161,63,23,217,95,55,182,156,66,158,135,180,122,239,
177,104,18,193,41,247,142,221,108,101,92,168,45,233,158,166,128,112,236,7,214,196,15,175,177,181,175,189,59,250,32,142,238,85,154,63,49,44,75,39,243,193,254,125,65,59,215,220,83,147,46,37,105,246,118,
250,89,124,140,23,18,197,67,246,54,165,253,134,157,61,127,179,43,242,70,159,246,183,87,198,222,181,222,64,169,18,207,183,119,148,180,34,85,63,93,17,213,81,177,12,125,152,39,186,123,53,201,213,125,203,
214,142,222,116,241,35,254,64,144,63,103,65,59,159,185,231,184,27,95,110,195,207,123,156,104,56,87,192,158,159,153,42,79,76,51,247,148,53,210,121,119,7,193,109,193,85,82,73,242,12,111,99,209,199,76,196,
158,108,30,157,5,136,62,236,252,247,201,82,247,55,47,0,127,163,112,224,126,205,61,110,223,216,143,188,62,219,250,54,94,225,185,143,213,172,98,45,251,67,245,138,78,247,219,216,176,101,162,254,95,193,166,
64,108,219,159,179,96,20,99,232,127,113,104,132,210,145,253,108,183,247,79,235,199,40,129,72,121,126,54,63,210,154,66,63,96,2,189,40,151,216,255,0,188,36,196,181,255,0,186,55,113,165,50,99,181,137,88,
143,180,191,249,122,77,215,252,209,237,140,94,168,182,15,198,255,0,140,125,85,39,233,92,142,75,5,83,216,89,152,27,213,103,136,100,153,104,12,137,245,179,194,110,127,62,218,147,159,17,71,251,172,217,172,
225,30,162,61,109,251,100,36,127,47,183,166,23,238,237,187,93,56,110,110,247,19,125,190,63,192,110,68,74,127,218,197,159,248,215,203,164,222,214,222,159,37,254,83,110,147,183,187,31,187,119,222,119,171,
48,50,127,16,236,172,54,212,150,46,191,235,218,122,20,66,212,59,30,139,31,181,226,160,74,188,198,110,125,41,246,222,89,60,80,6,119,0,91,216,99,123,231,13,217,236,46,110,47,239,100,16,233,33,86,160,2,124,
187,84,5,160,251,58,23,236,94,210,251,127,203,187,165,133,190,209,176,219,201,186,7,5,229,112,101,116,80,114,76,146,106,58,219,133,69,15,161,175,73,125,167,176,186,187,39,242,43,27,177,165,219,216,186,
62,164,234,89,227,220,251,215,7,143,41,77,22,230,221,37,245,225,246,229,101,108,140,102,172,130,150,80,12,226,71,98,193,108,126,190,192,251,109,197,221,190,217,38,239,125,52,146,95,92,146,177,130,126,
8,235,196,15,42,245,56,111,22,145,243,53,236,60,173,203,112,195,105,181,88,160,121,92,47,246,147,176,252,76,73,102,210,48,1,52,25,225,213,176,213,103,58,79,127,194,113,245,120,10,12,107,212,39,141,86,
49,2,199,8,32,164,73,4,144,250,99,88,212,0,163,232,0,183,178,182,146,50,106,16,171,126,125,41,77,151,156,54,127,213,135,112,23,17,175,161,174,7,203,162,171,187,246,156,221,31,185,27,43,138,72,119,23,95,
238,56,165,197,110,61,187,94,171,87,137,204,224,107,199,138,186,138,178,152,131,27,126,211,18,175,109,74,220,142,69,253,210,104,254,165,5,27,77,202,16,200,227,136,97,192,142,142,200,181,230,205,166,107,
75,216,52,222,42,159,145,7,252,222,189,27,255,0,229,65,242,129,126,5,124,197,198,252,75,201,103,36,175,248,149,242,250,162,159,117,116,214,71,45,80,236,122,235,178,242,106,212,244,248,101,169,145,188,
17,208,230,43,33,56,234,164,244,222,163,237,166,54,212,215,153,125,181,230,201,39,65,111,122,66,185,127,14,81,228,36,20,10,227,208,62,1,249,253,157,96,23,222,59,219,19,186,109,55,60,197,109,1,27,254,214,
157,244,227,53,176,57,168,226,90,46,32,255,0,5,71,91,157,143,167,251,127,247,191,115,167,88,9,215,126,253,215,186,247,191,117,238,189,239,221,123,166,77,204,145,73,183,51,241,206,139,36,18,97,50,169,52,
111,250,36,137,232,39,18,35,3,245,86,75,131,254,30,219,152,3,20,160,140,105,63,224,233,235,114,69,196,5,126,32,235,79,218,58,249,253,117,101,38,159,136,29,121,80,0,190,47,186,59,115,23,97,98,161,98,223,
89,70,0,126,69,204,191,143,175,188,99,230,4,6,8,92,12,6,35,174,212,123,81,57,59,172,177,214,161,237,35,63,245,77,122,189,175,143,181,131,33,209,212,48,95,86,154,38,143,77,190,131,199,244,252,155,159,106,
54,118,215,182,5,39,129,61,66,190,225,66,214,252,249,59,249,22,175,85,7,242,75,7,246,219,155,62,222,61,55,169,157,129,183,23,185,183,208,127,79,240,246,20,149,124,59,169,71,207,172,182,228,251,161,115,
203,150,32,181,72,140,116,68,176,212,211,86,215,110,141,177,13,197,70,231,219,89,204,78,60,142,8,203,253,171,86,225,164,65,126,30,60,173,36,69,127,161,250,115,239,123,131,248,113,91,93,131,67,12,200,255,
0,144,61,223,200,244,85,189,218,45,205,181,237,172,162,177,186,48,63,97,20,63,202,189,125,1,126,15,246,253,63,124,124,70,248,241,218,208,84,45,68,219,175,170,118,140,185,67,229,242,203,22,123,27,139,131,
17,158,130,164,146,89,42,225,203,208,204,37,86,245,43,220,31,121,97,179,221,45,238,215,99,114,164,119,70,43,246,129,67,252,199,92,66,231,93,154,94,95,230,222,97,217,165,90,52,23,114,40,31,209,212,74,211,
229,66,40,124,250,53,94,204,186,11,245,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,255,215,223,227,223,186,247,94,247,238,189,
215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,116,94,126,89,116,148,127,36,62,53,119,127,68,181,
111,240,217,187,75,173,183,78,209,160,200,30,82,139,43,146,198,78,152,154,185,5,192,104,105,242,107,19,56,60,21,7,218,13,210,211,235,246,251,187,64,104,206,132,15,183,136,254,99,161,7,42,111,109,203,156,
201,178,111,161,53,11,91,148,144,143,85,86,26,135,230,43,214,151,223,26,247,159,116,245,142,218,160,219,56,61,221,184,58,107,228,63,197,230,172,232,254,233,218,180,212,146,100,38,164,162,219,53,179,195,
128,220,153,205,176,227,207,146,218,153,124,115,33,138,186,4,146,52,176,38,193,212,251,45,229,155,101,223,54,187,107,24,238,218,219,127,219,245,70,202,48,89,42,72,98,63,16,21,161,227,74,87,207,169,219,
220,91,187,62,94,230,45,199,120,186,217,34,221,57,7,152,202,93,219,200,199,9,41,80,36,141,100,92,163,169,173,84,145,81,229,142,142,222,58,171,190,190,68,68,144,246,47,207,142,167,217,59,74,177,68,153,
73,176,213,73,143,205,207,5,174,241,181,25,20,147,196,246,7,134,60,31,98,216,246,23,81,254,236,46,39,184,111,74,208,31,217,212,79,63,53,109,86,172,91,151,121,94,11,102,242,102,253,70,31,239,88,254,93,
10,187,55,178,191,150,247,194,52,122,157,128,115,127,43,59,239,40,200,95,112,80,227,191,188,89,19,92,173,160,152,107,42,146,74,12,84,47,49,54,32,179,16,62,190,206,161,177,187,116,88,98,137,109,237,71,
144,197,127,103,31,242,244,15,190,190,189,220,231,107,155,251,134,119,57,207,1,246,15,47,240,116,70,62,110,252,183,249,9,217,153,140,54,31,55,73,34,118,78,231,198,207,153,234,255,0,143,120,122,150,151,
17,213,251,116,222,40,251,63,182,68,77,166,25,233,163,96,212,144,212,15,220,151,78,149,183,212,51,205,188,211,99,201,246,18,90,216,210,77,246,68,199,3,225,3,248,216,100,234,254,21,227,230,69,58,151,189,
151,246,138,251,220,189,234,27,155,164,49,114,132,18,129,44,134,171,245,13,254,248,140,249,175,251,245,197,66,138,129,158,21,103,183,250,242,109,169,54,75,33,156,174,171,220,59,219,57,52,149,155,167,116,
228,228,121,171,242,117,210,177,105,86,39,144,153,34,164,87,36,42,139,11,88,125,0,30,241,43,117,190,185,220,231,150,75,167,99,86,45,146,73,44,120,179,19,196,159,94,187,37,200,220,185,179,114,126,223,111,
109,181,197,24,144,70,169,169,0,85,68,3,17,196,63,10,15,218,198,164,241,233,242,88,244,115,110,0,213,199,228,255,0,174,63,22,246,65,36,68,87,211,169,102,194,247,80,2,181,30,93,102,138,75,31,175,212,114,
127,175,230,195,253,107,251,47,149,42,15,66,120,37,224,120,245,39,202,25,184,22,254,182,183,210,194,195,159,161,255,0,120,246,141,163,53,206,27,163,33,145,131,214,79,215,96,79,168,216,90,255,0,79,173,
239,110,9,62,221,130,64,40,181,238,232,179,112,181,241,16,181,58,114,254,27,77,185,177,49,237,250,140,192,219,121,108,86,65,179,123,23,115,76,141,53,6,27,63,36,75,79,85,65,155,167,91,201,54,220,207,211,
168,130,168,47,170,50,22,65,202,251,57,178,189,22,211,55,136,154,173,228,26,92,87,203,212,124,193,254,93,68,28,233,202,151,247,95,75,188,108,135,78,245,106,73,95,71,83,197,8,249,138,254,103,166,172,151,
99,230,54,155,182,223,223,184,121,54,110,114,20,177,106,178,106,112,25,52,181,214,191,111,238,24,85,241,249,76,109,66,250,144,135,14,160,217,128,35,217,231,238,212,146,147,91,202,37,132,228,17,199,236,
35,141,122,11,90,243,228,5,13,166,230,159,73,185,46,26,57,1,90,31,232,181,40,65,242,233,227,227,167,125,237,157,129,242,159,164,119,246,91,49,89,81,183,177,121,252,198,11,122,203,181,241,85,219,171,48,
118,30,232,194,86,209,103,105,233,240,152,100,158,183,37,228,172,138,150,72,226,22,253,228,83,113,201,246,47,229,27,153,118,77,226,210,249,131,36,40,224,182,63,15,6,199,216,79,80,119,190,214,241,115,175,
35,110,123,86,222,241,79,188,6,86,183,93,96,82,64,192,131,168,252,35,141,79,207,171,28,237,175,152,251,151,123,98,178,248,36,169,220,31,31,250,202,84,146,58,72,105,169,177,181,255,0,37,59,14,13,108,168,
184,202,89,90,183,111,116,238,14,178,11,107,171,172,251,140,160,7,246,226,140,243,236,111,204,126,232,151,241,45,246,118,48,197,158,236,25,91,243,248,83,237,21,63,62,161,63,111,190,237,59,221,244,246,
123,134,231,110,147,77,80,89,158,162,210,46,28,87,18,92,48,60,20,16,152,205,122,35,153,30,212,142,105,49,123,115,172,118,6,207,234,125,188,213,208,69,85,85,73,7,247,155,126,110,154,202,185,86,58,156,215,
96,118,46,226,90,221,193,185,50,149,122,203,75,119,72,1,54,84,3,143,113,21,238,241,113,123,38,160,218,65,226,65,53,39,213,152,228,159,207,242,29,102,79,43,251,81,203,252,169,111,113,117,121,113,54,227,
185,20,61,210,0,145,162,129,132,134,20,162,70,131,243,39,21,53,234,239,255,0,149,14,242,218,159,29,250,95,229,190,99,23,6,26,125,244,159,35,114,155,59,104,237,232,140,103,41,182,241,149,27,63,3,155,169,
201,85,81,32,50,209,96,242,89,76,140,245,52,150,2,41,86,193,13,131,123,158,253,180,180,123,155,11,149,6,180,145,117,31,58,105,193,245,206,115,252,250,230,215,222,66,57,183,142,123,218,118,229,15,30,212,
150,166,74,31,128,147,35,2,23,203,80,20,4,113,207,14,129,207,144,189,149,253,224,200,100,95,114,238,106,60,38,50,90,183,202,111,109,217,184,114,112,99,40,22,237,229,52,211,87,215,73,18,242,127,221,107,
169,154,193,84,31,167,177,87,59,111,176,203,103,7,38,109,55,42,182,165,196,151,147,86,138,196,26,164,53,63,130,62,39,248,159,236,233,7,181,188,164,219,126,227,47,184,59,214,222,223,83,12,45,111,181,218,
233,171,198,173,137,46,25,22,191,171,49,194,240,211,31,18,43,208,71,183,59,22,191,119,99,106,103,232,93,159,141,172,192,227,208,69,55,126,247,115,213,245,239,67,226,138,11,75,54,29,171,225,143,117,246,
21,92,96,94,56,113,212,190,57,79,6,69,28,251,1,93,243,143,44,114,244,102,45,189,69,205,218,138,7,147,182,21,62,180,248,159,228,7,30,164,65,203,60,205,204,23,137,14,226,102,67,41,175,210,218,15,26,237,
234,112,14,154,164,32,249,150,38,131,203,160,155,55,216,255,0,27,54,70,104,110,190,197,175,202,124,231,238,106,6,111,225,117,251,183,20,219,83,227,206,195,169,176,63,107,177,186,194,41,218,146,190,10,
121,121,21,89,1,81,81,50,139,177,252,123,137,249,135,159,175,55,105,140,147,202,247,13,248,85,170,144,168,254,138,14,52,249,208,31,78,178,55,146,62,237,220,223,123,108,145,202,144,242,222,206,244,47,165,
132,247,243,15,248,100,191,128,252,133,0,225,142,147,155,151,249,131,247,70,226,81,142,159,106,245,5,62,218,141,26,158,155,107,193,215,120,8,177,52,244,140,52,37,58,69,5,52,74,22,40,198,145,192,224,123,
6,203,191,110,179,229,164,64,163,128,8,160,15,217,158,167,141,175,238,199,237,166,219,31,109,214,230,215,196,130,101,55,13,168,145,231,67,81,147,158,139,84,251,223,109,100,243,235,185,104,49,57,14,156,
220,229,140,205,185,122,111,33,46,218,189,94,176,203,45,118,6,61,88,92,149,48,111,172,83,66,192,253,61,175,218,249,167,121,219,37,89,96,186,101,35,248,73,167,236,233,87,48,123,5,203,59,173,139,90,248,
105,112,195,0,202,160,56,20,254,48,5,79,207,163,135,208,127,50,183,159,87,246,46,7,176,251,59,106,226,62,81,99,118,70,26,182,29,129,87,181,164,165,217,187,199,102,238,170,145,166,151,122,238,94,188,168,
120,176,219,202,187,31,21,244,45,35,198,222,79,88,93,94,229,29,167,220,91,29,223,118,216,103,230,249,30,75,11,74,128,136,21,72,169,169,117,7,180,183,219,65,154,245,136,190,228,253,218,249,195,100,229,
78,105,217,253,187,68,182,189,220,157,90,105,37,213,39,140,168,180,72,26,69,5,146,60,2,199,137,0,45,122,174,127,147,255,0,34,119,39,119,119,70,123,178,119,140,25,125,177,53,83,201,71,133,198,110,106,74,
156,118,66,44,123,84,60,242,213,215,73,50,8,37,200,101,42,91,201,32,71,42,130,202,15,23,247,126,124,230,135,231,93,250,93,210,59,65,14,219,28,107,21,188,74,107,225,194,152,64,79,155,31,137,143,241,19,
209,199,177,156,137,183,123,61,201,22,124,176,187,159,143,190,203,51,92,223,76,202,99,241,110,164,29,218,21,178,34,140,118,70,43,192,2,120,244,221,180,251,6,169,32,136,147,52,180,214,75,79,26,52,176,122,
150,233,121,81,90,63,93,184,231,155,123,142,46,44,129,39,25,235,37,54,142,104,64,21,62,169,9,255,0,76,15,249,122,24,232,55,204,115,198,186,152,243,192,182,174,120,191,31,64,190,203,94,207,79,204,116,56,
183,223,117,5,53,242,233,246,61,225,9,183,175,147,200,2,223,64,111,254,246,61,167,250,99,74,211,165,203,189,142,4,245,142,179,125,209,210,192,210,207,83,12,8,170,73,146,121,146,4,2,215,62,169,29,71,227,
250,251,178,217,150,56,74,254,211,214,166,223,226,137,89,158,69,81,230,73,3,252,39,160,95,61,218,20,185,234,175,225,27,113,107,183,78,82,70,101,92,102,216,161,170,205,214,51,49,211,105,62,206,55,134,5,
63,234,164,117,81,253,125,155,218,237,178,225,138,81,71,153,199,81,246,247,206,251,90,235,136,93,9,36,242,88,234,231,249,99,243,233,178,151,172,50,153,55,122,174,200,205,29,135,70,204,36,254,233,96,100,
166,204,118,6,70,159,234,98,170,173,141,164,194,237,88,231,0,169,125,83,84,40,189,150,254,204,30,75,91,37,214,205,226,72,60,135,14,128,255,0,242,32,230,25,0,177,182,250,75,38,57,149,205,88,143,232,175,
151,200,211,163,239,215,3,23,182,58,142,167,39,141,194,80,237,157,159,180,177,89,156,206,59,3,65,172,194,130,130,138,106,185,43,242,53,178,3,62,91,47,90,240,134,168,170,152,179,185,38,214,22,30,227,221,
230,242,235,118,220,34,129,207,105,96,128,14,2,166,152,235,215,54,150,60,188,239,109,102,75,72,19,83,185,226,237,74,231,211,229,210,59,249,119,127,42,79,150,63,57,186,231,113,119,166,223,222,59,67,164,
122,247,119,110,156,221,118,27,121,111,124,70,75,113,230,251,30,178,58,169,162,168,169,219,184,122,9,97,74,45,185,139,171,83,1,170,168,98,103,153,28,70,182,66,125,206,91,111,36,77,188,193,28,149,9,107,
18,132,74,214,134,152,192,28,126,103,31,159,88,233,205,191,121,93,187,218,155,169,246,27,27,19,119,190,74,226,75,130,186,105,29,69,81,11,53,123,168,107,65,156,138,158,145,31,37,126,58,252,144,248,19,219,
56,62,181,239,218,60,109,65,220,209,212,214,245,175,104,236,215,174,155,175,59,46,151,30,67,100,113,180,235,92,137,89,130,221,52,17,176,105,168,42,0,118,140,135,75,169,30,194,188,201,202,119,123,36,140,
178,40,48,145,90,241,20,245,7,207,230,14,71,216,122,157,189,155,247,239,151,189,213,181,34,216,248,27,186,26,60,109,64,65,57,21,80,72,163,80,233,96,116,146,40,104,113,210,238,125,210,55,175,95,104,230,
120,218,29,69,95,212,105,229,137,109,36,124,220,129,236,10,170,209,203,79,195,94,167,149,180,183,107,129,116,170,22,106,103,202,191,111,69,227,179,177,25,13,237,241,143,112,228,112,82,203,23,99,124,109,
221,180,29,155,179,114,52,204,201,145,167,195,45,101,49,202,211,210,78,172,38,137,41,167,138,41,212,6,225,210,227,218,237,158,228,237,220,197,8,173,45,174,211,73,21,252,99,42,127,151,243,234,31,247,43,
105,136,220,165,211,194,13,188,202,82,65,76,16,195,75,3,249,103,173,248,254,24,119,141,15,201,47,138,189,7,221,212,85,70,172,246,15,88,237,108,206,70,102,116,146,83,157,92,116,52,89,241,49,79,211,47,241,
138,105,137,83,98,47,239,46,118,139,175,173,219,44,174,73,171,180,98,191,104,193,254,99,174,49,115,142,199,39,45,243,78,255,0,178,72,180,250,123,167,80,63,163,90,175,252,100,142,140,239,179,30,131,93,
123,223,186,247,94,247,238,189,210,83,126,78,41,118,62,242,169,38,223,111,181,55,20,247,254,158,28,69,100,151,255,0,97,167,219,55,39,77,181,195,122,35,127,128,244,166,201,117,94,90,47,172,170,63,227,67,
173,9,58,168,6,248,53,215,117,128,105,106,222,238,237,58,162,64,229,214,109,243,150,179,158,63,73,9,239,26,119,239,247,2,3,253,35,215,102,189,171,237,230,38,90,96,89,32,253,145,167,249,250,185,95,139,
117,79,39,82,67,16,36,218,54,31,79,235,25,183,31,82,77,200,247,173,134,173,98,224,127,17,255,0,39,81,175,186,177,136,249,189,156,250,15,245,127,46,136,47,201,172,65,108,198,106,98,46,76,146,30,71,6,228,
253,127,214,246,28,190,26,111,36,198,11,30,178,19,219,251,128,219,29,162,131,248,71,248,58,172,41,43,95,110,111,124,54,89,65,95,225,249,154,26,146,65,43,232,142,170,50,223,212,114,151,255,0,111,238,242,
70,46,108,103,132,140,50,48,254,93,31,110,81,159,18,76,96,142,182,244,254,71,61,137,142,173,232,78,223,232,148,158,249,30,136,238,253,204,180,180,250,195,47,247,51,181,85,123,31,106,84,64,47,168,83,153,
50,213,176,129,109,42,97,227,235,238,115,246,175,116,253,225,202,182,136,199,245,98,237,63,145,35,252,42,127,111,92,148,251,209,114,244,155,63,185,51,110,33,41,109,125,2,184,52,167,114,118,56,251,69,23,
62,117,234,237,61,201,93,99,127,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,127,255,208,223,227,223,186,247,94,247,238,189,215,
189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,209,0,139,31,126,235,221,85,39,206,111,229,71,213,
31,45,183,68,61,225,177,119,126,227,248,231,242,171,15,143,142,135,21,222,93,121,227,89,179,244,52,112,60,116,120,30,198,219,147,91,27,188,48,138,52,199,251,203,230,142,43,128,88,88,0,254,229,177,37,221,
194,223,217,220,61,182,230,188,36,66,69,126,208,8,253,191,182,189,74,28,155,238,117,255,0,45,216,73,203,155,190,221,6,235,201,210,181,94,210,224,85,84,158,47,19,113,141,254,99,4,241,234,148,183,63,242,
221,254,108,91,51,39,83,140,174,232,63,132,191,42,177,241,206,241,211,239,185,235,71,91,103,50,49,43,31,29,93,117,2,228,240,236,143,40,0,186,136,201,185,60,159,117,139,122,247,18,200,52,102,72,110,84,
112,102,8,73,252,203,33,254,93,12,90,47,187,158,240,166,231,234,55,189,162,115,198,36,164,168,62,194,67,125,156,122,51,61,3,252,184,191,152,222,229,172,140,111,117,248,143,240,159,106,76,22,12,165,103,
77,108,175,244,173,220,50,211,106,11,57,219,249,189,217,45,102,222,219,117,237,25,34,42,150,122,147,25,228,71,123,123,112,110,28,249,185,118,221,95,67,105,15,153,69,5,255,0,46,32,31,158,175,203,162,75,
233,253,143,217,42,251,70,215,186,239,119,131,42,46,165,240,109,193,242,214,145,209,220,31,53,26,126,211,209,136,249,25,252,149,250,159,27,211,141,189,126,49,73,186,169,190,95,245,221,46,103,118,226,251,
79,122,238,156,142,226,206,252,132,204,75,17,172,205,108,94,234,170,172,127,182,204,225,55,108,113,53,45,40,134,42,116,197,200,241,180,32,42,88,148,238,124,165,107,45,155,201,110,93,183,17,86,46,236,89,
165,62,97,201,245,242,167,15,179,163,190,72,247,219,127,218,57,134,221,119,67,18,114,156,133,99,54,240,198,35,142,213,56,43,219,170,210,133,56,181,73,50,10,234,36,158,181,249,205,237,108,87,105,245,245,
7,107,236,252,93,102,30,102,159,35,135,222,187,62,190,61,25,141,137,189,112,53,82,227,119,78,211,203,195,109,105,81,133,203,67,36,96,176,5,163,10,223,67,238,28,220,118,190,207,30,37,236,60,71,161,244,
63,234,199,93,45,228,206,120,213,36,86,23,115,43,6,10,209,184,248,100,86,21,86,7,230,8,63,159,69,110,178,141,163,105,34,116,101,101,114,8,2,197,72,60,223,233,123,251,10,79,22,138,215,169,243,110,189,248,
10,156,17,211,51,175,141,191,32,18,127,215,191,252,64,255,0,15,100,238,180,5,105,158,135,182,19,151,85,169,207,159,89,65,228,15,161,255,0,109,253,7,63,143,207,180,18,33,29,221,9,32,122,175,204,117,33,
3,92,113,200,224,254,6,163,245,252,146,7,180,165,128,110,209,210,134,4,140,211,169,81,216,143,87,245,96,120,212,65,39,145,244,231,233,237,209,61,56,244,134,123,101,106,157,61,221,61,210,230,114,148,208,
173,60,85,146,154,88,216,178,81,213,8,170,232,148,253,26,212,149,107,44,11,123,115,233,231,218,184,238,101,136,214,9,10,159,145,61,7,47,246,13,178,255,0,87,215,109,176,205,254,153,65,63,180,244,230,119,
190,231,167,133,161,161,174,166,195,51,6,86,168,194,227,177,216,186,167,141,184,49,154,186,42,104,106,80,48,255,0,82,195,143,107,78,225,122,226,141,112,229,126,103,160,244,124,143,202,214,179,248,176,
236,144,9,127,210,215,249,116,133,157,100,158,73,38,153,228,154,89,143,146,89,166,145,166,154,70,190,166,105,36,102,103,123,147,123,146,77,249,247,69,149,170,53,30,238,140,228,181,210,52,172,96,40,20,
20,20,31,179,172,62,16,44,66,144,192,135,4,122,74,216,130,26,255,0,130,15,181,11,49,166,91,164,111,107,146,186,113,208,161,136,223,20,113,214,75,152,205,80,238,56,119,67,227,232,177,50,111,77,147,187,
242,155,47,113,100,113,184,229,41,65,71,159,52,62,106,12,240,160,141,180,67,37,68,45,44,113,250,67,91,143,103,155,127,52,238,155,82,148,179,186,117,98,41,85,98,166,158,134,134,132,117,17,243,87,178,188,
185,205,19,137,228,138,52,238,44,81,145,93,42,124,214,185,82,126,93,48,212,238,12,26,110,24,247,36,59,114,77,203,153,164,144,77,142,200,246,118,115,39,216,77,143,169,4,20,172,164,198,102,165,56,56,107,
16,242,178,10,109,64,139,143,104,47,249,131,118,189,45,227,93,29,45,251,127,111,75,246,111,101,57,90,198,20,89,213,154,139,78,222,193,79,65,74,26,117,27,122,246,54,249,223,243,68,251,199,116,230,51,177,
210,128,180,180,85,21,47,30,54,142,59,53,163,163,198,67,227,162,165,141,0,244,132,69,10,7,30,201,139,146,53,49,171,124,250,149,118,46,89,216,57,114,50,155,38,211,13,177,60,74,168,212,127,219,113,254,125,
33,66,21,35,233,99,244,31,91,17,199,54,231,233,237,179,95,78,132,32,181,13,9,167,159,94,145,79,171,72,224,91,145,254,176,54,30,245,249,117,80,72,245,7,172,35,242,56,184,38,215,252,112,64,32,31,167,215,
252,125,239,135,86,212,223,197,215,145,138,62,165,98,174,10,178,148,102,70,7,139,89,148,130,15,28,17,238,218,15,217,213,90,86,32,167,17,210,166,61,211,184,62,216,80,86,74,153,138,14,2,99,247,5,29,46,102,
149,150,214,33,33,201,69,62,155,142,44,182,183,183,225,154,120,129,48,76,192,143,67,143,207,162,45,211,149,246,93,197,213,55,61,174,15,24,240,213,165,24,215,208,18,9,252,171,210,106,166,135,104,213,74,
205,81,176,240,52,179,72,165,100,124,41,174,192,59,175,58,75,69,141,168,134,0,23,81,176,11,199,181,241,239,23,235,129,113,168,252,192,61,4,47,125,164,228,230,106,190,220,240,201,199,5,151,31,46,24,251,
58,79,182,210,218,43,102,167,198,231,168,150,228,24,169,55,134,93,16,142,117,105,89,76,197,72,252,115,237,241,189,221,224,60,113,55,218,163,164,135,219,29,129,1,17,110,55,200,60,128,153,177,215,7,219,
27,69,192,85,164,220,175,111,212,149,27,215,54,241,56,255,0,21,138,72,91,155,243,207,181,11,186,92,149,168,134,33,254,212,87,164,115,123,119,181,197,93,91,157,251,199,94,6,102,31,224,233,194,142,147,107,
99,74,154,125,145,182,231,153,79,21,25,165,200,103,164,36,125,31,70,70,178,88,153,191,62,165,62,214,199,121,112,217,212,163,236,0,116,85,63,36,108,41,168,188,115,62,127,28,140,223,225,61,40,98,221,25,
152,160,20,116,21,49,225,232,139,18,104,240,20,148,184,74,86,86,224,235,139,27,13,62,176,71,250,162,222,252,242,77,37,75,72,72,233,168,246,141,174,195,88,181,177,141,13,56,211,63,183,174,16,207,98,236,
204,117,187,88,187,177,103,98,255,0,168,150,98,75,53,143,215,218,73,144,28,249,244,170,23,202,1,240,250,116,120,51,241,148,248,103,217,179,82,220,78,189,95,186,140,69,127,87,146,74,25,35,63,65,249,215,
236,37,110,7,245,138,202,163,30,58,255,0,135,168,203,152,164,39,112,189,45,231,214,211,191,201,194,134,143,31,252,177,254,27,197,66,129,32,159,169,105,43,120,177,15,45,110,107,51,85,60,151,4,139,201,52,
165,143,248,159,121,143,203,43,167,100,177,199,16,199,254,52,221,114,103,222,7,105,61,204,231,34,231,184,94,17,251,21,64,233,75,252,208,126,37,225,254,96,124,58,237,62,191,254,29,12,219,255,0,107,97,234,
251,35,167,243,0,34,87,224,123,43,102,210,77,149,193,201,73,84,84,188,80,101,196,47,67,82,128,233,150,10,134,4,18,22,219,230,45,182,61,211,106,185,133,146,178,170,150,95,180,121,126,98,160,244,223,181,
92,231,121,200,188,239,178,111,86,211,148,131,198,88,229,3,131,68,204,53,99,213,112,195,208,142,180,238,248,147,77,47,102,245,94,248,156,211,24,114,88,92,109,22,122,122,82,140,38,165,169,134,73,104,115,
248,230,140,250,151,237,107,33,117,42,126,154,125,226,189,237,161,142,107,200,199,24,187,135,217,255,0,20,122,237,39,245,168,45,199,41,94,248,159,161,184,46,131,156,106,34,160,143,180,255,0,35,211,119,
82,81,69,39,104,110,221,135,91,105,49,91,231,105,238,141,181,83,3,254,137,99,200,226,106,86,11,169,226,241,74,193,135,31,80,61,147,238,76,99,183,180,187,67,73,34,149,88,31,176,142,151,243,205,176,186,
217,36,114,59,144,215,173,146,63,225,57,187,210,187,113,127,46,156,94,208,175,114,242,245,31,112,118,143,93,193,173,137,149,40,169,51,17,102,233,96,112,121,11,78,153,159,26,255,0,64,182,252,123,202,238,
75,159,198,218,88,87,11,33,167,216,193,91,252,167,174,63,253,227,54,244,178,247,34,226,120,192,2,234,214,25,79,219,164,161,255,0,142,231,171,230,246,47,234,7,235,222,253,215,186,247,191,117,238,131,206,
220,156,82,245,87,102,84,177,176,131,175,183,156,196,255,0,79,30,221,200,181,239,248,181,189,165,190,58,108,174,207,252,45,191,192,122,95,181,174,173,211,109,81,196,207,24,255,0,141,142,180,67,235,212,
251,95,129,31,29,131,11,28,174,243,222,57,91,15,247,98,214,110,205,193,80,30,223,218,212,150,62,241,187,127,20,176,181,0,227,81,255,0,7,93,155,246,181,127,228,79,125,78,11,106,7,236,8,58,182,255,0,138,
213,173,254,141,105,161,81,109,72,224,219,139,89,69,133,191,216,251,214,194,105,106,195,207,81,234,60,247,102,21,254,180,72,205,192,1,209,110,249,41,139,15,81,147,125,28,184,146,228,158,111,245,6,230,
252,155,123,35,220,150,151,71,169,107,219,107,141,91,109,186,3,228,58,167,205,253,74,82,185,207,210,204,108,71,212,16,252,143,199,214,222,235,110,195,69,56,231,169,15,117,76,35,17,231,213,210,255,0,39,
238,225,110,183,249,217,179,182,229,101,64,131,110,252,187,248,231,54,32,137,15,237,75,217,253,33,90,245,52,58,78,173,31,119,93,180,170,103,83,253,162,177,1,99,236,109,237,30,227,244,251,150,235,180,187,
81,68,172,0,255,0,76,3,175,243,12,62,211,214,5,125,238,57,100,94,242,213,166,253,20,127,175,101,112,53,31,248,92,189,141,249,6,10,127,62,182,254,95,160,250,253,63,60,159,246,254,242,19,174,120,117,223,
191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,255,209,223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,
186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,209,23,4,125,63,161,254,
135,240,127,216,31,126,235,221,106,197,243,107,169,48,223,28,127,152,126,127,25,135,199,199,67,215,63,55,118,29,103,104,209,99,35,132,69,135,164,238,254,188,120,241,91,254,10,56,128,240,37,70,237,219,
53,52,217,9,194,133,213,50,51,114,73,247,23,243,13,148,118,155,172,138,19,244,46,23,87,203,87,226,0,124,248,254,125,103,15,177,124,207,113,190,114,95,208,207,41,55,251,68,194,53,53,238,240,36,238,140,
255,0,180,96,202,62,84,29,85,119,200,110,171,254,233,103,101,202,99,160,211,139,200,59,207,17,85,37,35,212,125,112,220,14,26,39,63,236,71,184,187,122,176,16,72,88,41,240,207,14,179,179,219,222,104,253,
233,106,150,211,202,62,170,48,1,30,190,132,122,215,162,167,83,15,58,149,77,239,234,255,0,94,195,234,63,216,251,7,206,129,73,36,231,172,129,218,165,224,43,142,163,164,122,172,72,185,31,64,109,193,28,11,
255,0,94,7,178,169,9,21,167,3,208,218,213,198,154,138,83,167,24,105,174,1,22,191,227,250,95,158,45,236,188,149,93,68,231,165,140,228,1,212,248,233,9,177,80,65,181,135,246,174,63,199,241,207,182,131,22,
242,162,244,211,200,40,1,248,201,253,189,17,95,149,63,60,58,191,227,92,243,237,74,42,95,244,133,218,49,198,30,109,169,141,172,74,92,94,223,50,71,228,134,77,209,152,88,234,62,210,105,85,129,90,88,146,74,
141,36,22,8,8,38,76,228,239,110,119,94,101,69,190,158,83,107,180,158,14,69,94,79,249,166,167,20,254,147,99,210,189,97,215,191,223,124,30,75,246,114,238,231,150,54,91,37,223,57,242,60,73,0,125,54,214,134,
152,91,153,82,172,242,208,230,24,178,166,129,220,100,117,81,251,179,249,163,252,164,207,228,94,167,7,146,218,123,47,30,37,118,131,25,134,219,20,53,224,66,79,162,42,154,204,231,241,25,234,89,7,5,148,71,
171,250,15,115,77,151,181,124,161,107,24,89,109,101,158,74,101,158,70,175,236,82,160,126,206,185,225,204,31,125,239,188,38,245,118,211,217,243,76,27,101,181,78,152,173,109,161,84,3,200,19,34,202,231,237,
45,83,213,156,127,47,159,152,123,151,228,224,221,27,27,177,113,152,245,223,123,67,23,6,122,13,195,137,165,90,26,29,193,132,154,173,104,102,90,220,116,119,134,143,39,67,81,50,29,81,90,57,145,239,165,74,
155,198,62,226,242,93,151,45,45,174,231,182,72,194,198,87,208,209,177,212,85,168,72,42,78,74,154,26,131,90,122,245,154,63,116,159,188,207,50,123,187,62,245,201,92,251,28,82,243,45,157,177,185,134,238,
52,88,252,120,149,149,36,142,104,208,4,18,38,181,100,145,2,234,26,131,45,64,38,203,142,40,139,253,9,252,88,21,28,126,0,110,109,238,46,241,63,23,151,89,166,242,33,24,29,112,124,113,85,245,41,28,105,254,
209,6,252,243,192,177,247,239,20,86,186,179,215,144,3,194,132,255,0,62,155,228,199,72,110,200,171,164,1,193,184,60,219,250,220,18,125,232,204,49,83,210,197,85,20,168,167,77,141,68,85,173,37,129,91,130,
20,127,196,216,131,245,247,86,151,134,158,20,233,108,67,95,12,83,168,210,64,194,218,18,228,125,15,244,255,0,19,254,36,123,168,157,78,11,83,165,17,198,160,241,167,81,202,106,91,176,34,205,98,57,91,145,
248,226,223,147,237,223,17,71,158,58,117,237,243,240,131,212,121,33,44,56,250,220,125,126,183,227,250,127,64,61,220,48,35,29,37,120,41,195,7,162,151,243,79,182,119,127,73,252,127,220,187,207,99,90,159,
114,205,146,195,237,234,60,179,83,165,72,192,38,102,115,28,249,132,138,84,120,90,166,40,212,199,1,112,81,102,117,36,27,88,141,121,7,103,178,223,121,138,11,77,196,106,182,84,103,211,195,89,94,11,246,121,
159,80,41,214,50,125,236,253,197,230,143,107,125,158,187,223,121,61,218,29,238,238,250,43,65,114,5,90,213,36,86,102,145,106,8,89,31,73,72,220,252,38,164,119,83,173,109,178,157,187,218,153,172,164,217,
156,159,99,239,170,220,164,242,153,164,174,155,116,230,190,227,202,77,245,43,37,98,8,185,250,5,10,7,227,222,79,197,182,109,176,198,176,197,183,194,177,1,64,2,45,41,251,58,226,21,231,53,115,62,225,121,
38,227,125,204,87,211,95,187,22,105,30,121,89,203,19,82,75,22,173,107,231,209,153,233,223,159,223,33,58,162,122,90,74,221,200,253,139,182,98,49,164,219,127,123,188,185,25,86,5,35,88,199,231,181,127,24,
162,168,100,224,51,201,52,107,245,40,125,134,55,190,65,229,205,228,51,155,79,167,186,254,56,168,166,191,53,166,146,62,84,207,175,83,119,182,223,122,159,121,61,181,120,173,237,57,149,247,45,136,17,170,
210,248,181,196,68,87,58,89,143,139,25,244,100,124,127,9,225,213,242,252,127,249,19,176,62,70,237,15,239,62,203,168,146,147,35,143,240,193,185,182,165,115,199,252,103,109,215,76,164,172,117,42,135,77,
86,62,160,169,251,122,168,255,0,110,80,44,116,184,101,16,7,49,114,197,255,0,44,93,253,53,239,117,187,146,82,64,59,92,15,240,48,243,31,152,199,93,102,246,111,222,190,81,247,183,151,164,221,249,121,154,
223,121,181,11,245,150,46,192,203,108,91,1,212,143,237,109,220,212,36,160,10,30,199,1,186,28,29,69,245,31,168,63,79,175,54,191,63,91,242,61,146,192,198,133,107,212,171,46,162,13,126,31,240,117,18,80,195,
155,240,24,19,200,7,145,127,233,200,30,204,225,99,86,7,211,162,11,180,160,111,51,215,8,73,14,195,139,14,65,45,199,7,232,77,128,3,218,228,21,28,120,244,29,188,81,229,131,211,165,60,133,141,191,198,224,
241,201,181,238,71,245,183,189,72,148,24,232,181,106,172,14,170,117,98,125,69,79,22,251,232,109,223,178,200,18,77,147,219,123,139,8,35,55,55,150,183,29,58,210,173,136,250,52,229,125,129,239,216,218,238,
144,220,214,129,100,86,253,135,61,71,220,207,9,23,179,53,48,235,94,182,9,254,64,155,251,251,227,252,179,250,119,1,60,206,217,110,167,205,239,174,170,204,65,45,203,210,84,109,109,207,94,41,97,38,246,5,
177,245,113,61,191,26,173,239,47,121,62,225,103,217,98,10,126,7,97,249,30,225,252,143,92,178,247,247,109,109,191,220,221,241,244,81,46,86,57,135,207,90,10,255,0,48,122,186,23,85,117,42,192,50,176,179,
43,0,85,148,240,202,65,184,32,175,4,123,20,245,12,117,165,215,79,245,125,39,85,127,48,47,158,189,23,71,78,96,219,180,187,183,178,178,56,58,35,26,198,145,225,183,108,43,188,113,203,12,43,233,142,49,54,
81,217,64,224,3,199,188,111,223,108,82,14,101,220,237,116,246,52,50,255,0,42,145,215,82,249,75,152,167,221,125,147,246,203,125,119,173,205,181,236,72,77,124,214,138,127,193,78,136,198,15,86,47,228,150,
212,88,238,8,220,116,116,114,40,184,37,90,99,79,34,158,77,238,166,222,227,75,218,62,213,114,15,0,58,204,29,239,245,246,27,194,120,24,171,254,94,182,20,255,0,132,239,208,205,137,233,159,152,24,133,86,76,
110,59,230,55,100,67,142,75,254,218,43,199,77,44,202,138,56,93,58,144,31,235,111,121,45,237,171,180,155,32,115,192,172,103,254,169,138,245,200,159,189,0,95,235,166,207,79,139,247,122,215,253,237,169,214,
195,94,228,94,177,167,175,123,247,94,235,222,253,215,186,8,190,64,78,148,221,19,221,85,50,27,71,79,212,189,143,81,33,250,89,32,217,217,137,73,191,248,4,246,146,254,159,67,121,95,247,211,255,0,199,79,70,
187,10,235,223,54,101,245,187,132,126,217,23,173,26,232,227,24,223,133,95,13,241,224,139,84,109,239,226,45,102,176,102,170,122,218,178,223,167,146,126,227,250,123,198,174,97,99,244,182,138,61,73,235,180,
62,213,197,93,255,0,125,114,13,68,74,63,152,234,210,62,38,85,137,118,53,36,38,199,72,127,161,31,67,96,63,31,83,238,251,9,31,78,195,206,189,71,254,237,65,167,152,103,122,121,14,145,95,34,177,218,222,181,
128,23,180,159,82,57,250,223,241,114,45,236,179,121,77,51,87,200,244,48,246,194,224,139,120,148,156,117,76,221,151,64,34,200,204,8,31,231,136,22,191,4,220,112,13,254,182,246,91,11,17,192,249,117,51,223,
13,112,86,158,93,11,221,103,190,79,92,211,252,73,239,120,38,122,121,190,59,124,174,216,85,89,154,136,155,76,145,109,13,229,150,139,108,231,96,114,44,77,45,68,25,20,18,139,219,199,171,219,156,177,120,118,
190,121,30,73,60,106,195,253,52,100,19,252,170,58,199,191,120,54,63,223,156,157,204,187,118,144,205,45,164,128,87,248,130,150,95,216,203,142,190,130,116,243,195,85,4,53,52,242,164,212,245,17,71,60,19,
70,193,163,150,25,145,100,138,68,97,193,73,17,129,7,242,15,188,189,4,48,4,112,35,174,59,178,149,102,86,20,96,104,122,205,239,125,107,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,
175,123,247,94,235,222,253,215,186,255,210,223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,
247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,80,143,243,228,197,195,130,216,63,15,59,178,8,23,248,167,88,252,178,217,152,119,172,30,
153,63,187,253,147,140,201,109,92,198,53,164,252,65,88,242,66,236,63,38,33,236,21,206,113,210,29,190,228,14,228,150,159,147,15,243,142,178,51,238,221,122,233,204,251,246,217,95,210,184,219,156,211,250,
81,48,101,63,104,207,237,234,187,59,167,105,67,185,246,102,110,149,144,61,69,12,114,213,82,49,81,169,94,29,87,181,129,39,201,24,246,1,221,237,197,197,156,180,29,203,159,243,255,0,46,179,91,148,119,71,
218,247,187,57,131,82,55,109,45,246,31,243,26,117,80,249,74,23,166,168,158,7,30,184,229,104,216,219,155,223,134,31,226,125,196,215,130,140,192,138,10,245,154,155,52,254,36,72,192,249,116,219,13,33,46,
65,95,213,114,14,158,71,208,223,131,245,227,217,36,196,83,7,135,67,203,105,192,69,175,151,74,26,60,107,203,167,74,22,191,34,235,97,207,55,227,235,99,236,184,208,147,211,210,94,233,174,113,209,93,249,195,
223,139,241,123,162,114,155,167,31,36,43,191,119,92,237,181,58,250,154,81,175,197,152,171,167,121,42,243,111,9,12,36,167,192,81,6,158,198,202,242,132,91,243,236,111,237,255,0,43,142,104,223,162,130,116,
255,0,117,144,82,73,190,96,30,212,251,93,169,81,252,32,158,177,147,239,67,239,124,158,208,251,105,119,123,179,92,105,231,13,209,154,214,203,214,34,87,245,174,105,78,48,161,164,100,227,196,97,233,213,7,
124,99,248,37,242,7,230,110,71,35,189,224,144,224,246,93,94,82,178,92,231,106,111,22,171,158,28,190,89,231,105,50,73,137,129,73,175,220,89,79,51,159,43,41,88,17,248,121,3,122,125,228,95,50,243,174,195,
201,241,71,105,47,125,224,81,162,8,128,212,23,202,188,2,47,165,115,242,235,147,190,213,123,9,238,55,189,215,119,91,181,133,33,217,76,205,227,110,23,108,194,54,144,154,184,83,221,36,242,146,106,193,3,80,
158,246,29,88,101,47,242,48,157,106,99,53,191,33,33,150,143,210,101,90,61,133,60,85,86,176,215,227,105,179,179,196,15,244,184,246,0,62,245,196,85,130,242,220,186,252,171,42,211,243,237,235,37,19,238,9,
124,179,71,227,123,171,101,224,126,45,54,147,106,252,170,228,126,211,213,147,252,90,248,41,213,159,19,241,121,100,217,239,152,220,187,183,113,193,21,46,224,222,187,131,197,30,70,174,134,158,99,52,24,188,
125,5,40,74,60,102,57,38,179,149,93,82,72,192,23,99,96,4,111,205,156,231,187,243,107,194,46,209,98,178,140,213,34,92,138,255,0,19,49,201,106,87,208,10,154,117,150,158,202,123,17,201,94,200,67,125,62,203,
119,53,247,50,221,70,35,150,238,106,41,240,245,6,240,161,137,73,88,208,176,5,137,44,239,65,82,0,167,70,174,92,0,226,225,174,126,186,150,255,0,83,197,143,248,15,96,210,15,10,117,61,37,237,112,24,117,6,
92,57,65,200,37,69,173,233,228,254,7,31,208,251,163,15,196,62,46,149,37,208,52,167,30,152,170,177,30,153,8,212,63,22,43,97,255,0,36,142,109,97,237,189,68,28,26,253,189,26,219,221,43,16,189,38,106,104,
10,18,10,219,159,79,164,216,143,234,13,255,0,160,252,251,222,178,78,122,53,138,96,188,5,122,103,158,153,144,159,232,63,222,63,169,34,194,255,0,94,125,209,229,205,8,232,202,32,172,160,208,86,157,54,78,
135,131,164,30,5,197,200,181,238,65,254,156,129,254,243,238,209,202,181,163,28,116,178,52,26,64,60,58,128,193,77,129,181,237,197,143,60,155,142,71,248,143,110,248,140,135,3,29,105,161,173,106,58,78,110,
141,169,129,222,123,127,45,181,119,94,34,143,63,183,115,180,207,69,150,196,100,35,242,82,86,210,57,13,227,145,69,153,89,29,67,35,41,86,70,0,169,4,95,217,133,134,229,115,97,117,13,237,149,195,69,119,25,
170,176,242,60,62,194,61,65,168,62,125,6,57,159,148,246,14,113,216,183,62,87,230,157,174,59,222,95,188,77,50,194,245,163,80,213,74,176,161,71,70,1,145,212,134,83,192,250,147,234,47,229,225,241,54,134,
177,234,159,174,178,21,119,157,167,90,90,253,221,159,154,141,53,27,136,68,49,213,66,230,153,126,129,75,125,63,62,199,173,238,135,54,200,129,5,252,74,105,196,68,181,251,106,73,31,203,172,93,183,251,138,
253,222,45,110,126,160,236,219,180,203,171,87,135,37,235,104,255,0,75,216,136,197,127,219,87,231,211,206,235,248,31,241,111,117,97,102,195,47,88,99,182,196,134,157,163,165,206,109,90,170,220,110,94,138,
98,140,169,82,38,121,231,138,177,162,98,27,68,233,34,61,172,192,143,109,89,251,141,205,214,147,172,205,185,137,214,185,71,85,210,127,48,1,21,225,81,210,206,98,251,152,253,223,183,173,174,75,11,62,81,159,
108,186,210,66,92,91,92,202,210,35,82,129,153,37,103,73,64,226,85,169,95,34,58,169,156,254,201,237,79,229,203,223,187,107,118,82,215,84,103,250,247,53,83,45,53,46,98,149,76,20,59,207,105,121,225,57,157,
187,153,164,86,104,232,243,248,232,29,101,85,55,2,85,73,99,58,75,40,152,237,119,13,159,220,190,92,187,181,49,248,119,138,59,144,229,162,146,149,87,83,230,164,240,62,98,160,245,206,77,251,149,125,200,251,
152,251,191,177,239,73,63,212,108,206,197,160,184,64,69,190,227,100,88,9,237,228,92,133,147,73,211,36,108,73,141,244,58,146,52,158,182,4,193,238,12,70,234,192,97,183,70,10,177,43,240,123,131,23,67,153,
195,214,66,117,37,85,6,70,158,58,154,105,69,191,75,248,164,179,15,170,176,32,253,61,227,188,246,247,22,23,119,22,55,42,86,226,39,42,192,249,16,105,252,248,143,145,235,177,123,54,235,180,243,86,193,178,
243,70,193,112,38,216,247,27,100,184,133,129,252,18,10,233,111,233,33,170,48,242,101,35,169,114,47,167,147,250,128,250,125,5,255,0,63,227,199,181,144,201,82,162,189,35,190,138,149,0,100,117,29,69,136,
252,31,207,3,234,56,34,223,78,125,153,198,64,35,56,232,49,121,29,114,58,153,78,224,204,182,22,23,177,189,172,75,113,127,241,2,254,222,124,129,209,52,130,131,230,58,58,255,0,21,119,44,148,57,156,150,17,
165,244,212,192,181,80,169,54,188,177,48,13,245,63,145,254,241,236,27,191,194,25,18,64,51,145,208,87,153,97,47,12,55,42,50,166,135,171,136,254,73,29,155,77,212,255,0,38,190,92,124,54,200,212,10,108,70,
245,170,199,124,164,234,74,121,207,136,79,14,225,72,112,189,137,138,199,70,20,36,194,139,35,13,60,237,167,252,220,96,95,147,238,119,246,151,122,23,123,119,209,202,223,170,20,126,212,26,79,230,86,135,242,
235,159,95,122,126,86,101,109,143,155,32,140,232,21,183,144,129,192,101,226,39,211,241,40,235,102,139,139,95,139,127,95,199,185,147,172,57,235,85,205,253,75,76,191,206,23,230,62,74,152,32,134,14,186,218,
19,215,233,30,129,88,58,215,27,71,35,56,31,71,101,167,4,255,0,137,247,3,115,91,40,231,11,182,254,27,119,255,0,142,1,215,68,61,172,241,27,238,243,202,241,53,106,251,235,5,251,3,215,252,189,83,148,114,137,
254,77,109,227,27,113,253,244,166,210,120,182,145,92,91,252,63,30,225,251,192,14,213,118,127,162,122,207,187,250,142,93,122,140,253,56,175,236,29,108,229,252,134,246,204,152,239,139,221,209,188,26,61,
16,118,47,203,46,242,207,208,190,146,22,106,28,126,126,60,4,82,33,60,58,25,113,175,98,61,228,199,182,176,60,60,179,104,207,197,130,255,0,36,3,174,59,253,229,111,18,227,220,86,183,82,63,197,236,226,67,
246,144,88,255,0,199,186,187,255,0,114,15,88,249,215,189,251,175,117,239,126,235,221,1,223,39,28,71,241,191,191,216,141,64,244,175,105,46,159,235,228,217,25,184,192,227,250,150,246,135,115,52,219,175,
207,252,37,255,0,227,167,163,174,92,207,48,236,95,243,217,15,253,92,94,180,112,106,177,81,240,235,225,180,194,192,197,180,162,163,224,233,3,237,225,146,33,101,54,177,186,30,61,227,111,48,0,96,182,161,
245,235,180,94,214,246,239,155,232,245,141,127,227,221,89,31,196,10,230,109,173,78,165,139,42,146,191,81,111,193,0,129,98,126,158,233,176,63,233,48,254,151,65,95,119,237,215,247,193,122,100,168,255,0,
7,74,158,248,129,103,134,165,185,229,100,231,250,113,253,62,182,30,216,222,133,88,17,233,215,189,184,144,199,225,10,249,142,169,147,182,168,244,100,170,10,169,3,200,220,218,246,55,37,108,127,60,127,135,
178,88,168,205,74,245,144,114,160,107,80,124,169,211,46,54,134,125,197,241,163,228,166,217,132,22,170,164,218,50,238,140,105,4,235,131,35,183,165,143,49,5,76,68,19,166,88,90,134,224,253,69,184,246,89,
112,255,0,75,204,92,189,114,13,63,83,65,251,26,163,249,215,168,191,152,237,213,237,229,86,90,134,90,31,219,67,252,186,223,99,225,223,97,183,109,124,83,248,233,217,111,163,203,189,122,99,174,179,245,30,
50,74,138,154,221,173,141,106,145,201,54,101,157,88,48,252,53,253,230,62,211,49,184,219,108,102,60,76,75,252,133,58,226,223,54,237,223,186,121,163,152,54,209,194,27,201,87,242,14,105,252,186,50,62,204,
58,15,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,95,255,211,223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,
247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,81,151,252,
40,30,170,21,248,79,176,113,122,194,228,51,63,44,190,61,211,98,80,0,100,146,186,155,113,214,215,90,49,245,37,105,233,220,155,115,97,236,33,206,109,77,174,21,252,70,117,167,236,63,241,93,79,63,119,56,228,
111,112,221,215,224,77,182,228,183,216,84,15,240,145,209,27,201,66,179,65,85,12,132,176,154,7,138,67,245,190,184,130,189,248,228,146,125,130,220,106,89,22,156,71,249,58,204,88,216,161,71,28,84,215,246,
117,79,253,129,137,74,45,217,151,165,81,233,74,185,150,196,0,44,178,182,145,207,251,207,184,123,116,77,19,202,180,197,79,89,169,202,23,70,125,166,206,102,108,148,95,240,116,158,199,226,140,242,129,160,
254,171,92,11,253,111,193,226,218,79,176,212,213,36,128,58,144,22,247,195,136,16,115,208,191,183,182,123,212,104,213,21,238,44,61,54,23,252,88,15,117,142,215,81,24,232,61,184,111,222,29,106,227,29,82,
231,243,54,248,203,222,191,38,190,95,252,119,232,157,131,180,119,20,251,77,246,116,85,181,91,170,44,93,99,237,77,191,14,107,58,227,117,103,179,25,53,143,248,116,18,97,241,212,9,232,119,89,100,109,40,128,
151,3,220,249,237,181,214,217,203,156,169,187,238,119,50,168,157,166,36,174,53,54,149,1,20,14,57,169,167,150,115,215,51,254,245,123,79,54,251,163,239,31,38,242,174,211,103,43,109,233,183,198,169,38,150,
240,99,241,100,102,158,87,106,105,26,40,53,87,61,160,12,145,214,192,61,121,208,155,127,173,118,78,212,235,237,165,141,131,27,182,182,110,11,29,128,195,210,83,66,177,196,41,232,41,163,129,167,42,20,22,
154,174,100,105,100,99,234,119,114,73,36,147,238,37,189,75,141,202,250,235,112,187,114,215,19,72,89,137,249,156,15,176,10,1,246,117,153,123,5,206,211,202,92,189,179,242,182,201,26,199,181,88,91,164,81,
133,192,58,64,212,231,213,164,106,187,19,146,77,79,75,131,215,206,0,180,64,255,0,134,139,114,62,128,150,22,183,182,133,128,244,207,70,35,153,211,205,186,131,81,177,37,85,23,128,125,15,209,121,83,248,31,
129,244,247,67,99,74,142,159,143,152,209,141,75,244,155,173,217,205,24,185,131,79,7,251,32,255,0,183,224,31,105,228,180,96,49,209,173,190,247,27,145,71,207,72,218,237,184,209,130,60,90,136,4,142,62,128,
30,62,160,123,71,36,5,120,175,71,214,219,150,174,13,210,54,187,13,160,16,35,38,255,0,80,64,6,195,252,79,252,139,218,41,35,60,64,192,232,254,222,244,18,43,131,210,39,35,139,30,175,73,22,190,147,98,8,111,
207,54,63,211,218,102,4,87,161,13,181,208,34,148,233,17,91,72,16,146,82,215,250,30,72,107,254,116,143,237,115,207,191,56,52,175,203,161,13,164,218,168,43,210,98,166,37,66,64,28,18,69,201,54,181,254,188,
254,71,180,228,112,62,125,28,32,7,58,186,100,150,152,41,107,49,6,252,250,125,67,158,63,60,15,247,191,111,120,161,84,80,84,244,172,70,72,4,28,30,163,48,49,253,72,183,227,81,224,143,169,250,125,27,159,119,
73,43,145,134,235,94,1,108,145,212,66,70,175,169,183,214,229,120,183,250,228,255,0,143,181,11,33,57,99,67,213,77,191,30,188,44,79,22,32,130,108,9,31,139,27,125,109,111,106,4,164,10,30,146,189,176,21,26,
72,232,41,238,78,149,216,29,239,179,101,217,29,139,141,154,191,17,247,145,100,168,42,168,170,13,30,87,13,149,133,36,138,44,142,46,173,67,120,170,12,82,180,108,172,29,36,70,42,192,131,236,243,97,230,77,
195,151,111,133,246,217,32,19,17,165,131,10,171,175,163,125,135,32,140,131,212,81,238,207,179,156,155,239,63,43,142,86,231,59,105,141,180,82,248,208,77,11,5,158,222,82,186,75,199,94,214,12,189,174,142,
52,176,165,114,43,211,223,94,236,44,31,88,108,109,177,215,251,101,235,95,3,180,177,113,226,113,146,100,170,133,86,65,224,142,73,37,15,87,50,164,72,242,59,202,196,133,85,85,250,0,7,186,238,91,165,198,243,
185,93,110,151,97,69,196,205,168,133,194,240,0,82,191,33,210,254,68,228,13,167,219,94,74,216,121,27,99,158,121,182,173,186,38,68,121,200,50,190,183,103,98,212,1,71,115,26,42,128,160,112,233,90,195,240,
69,193,7,145,245,7,158,9,0,1,207,211,221,98,147,133,58,87,127,109,130,69,122,131,42,144,197,129,54,6,196,220,241,199,211,232,63,215,246,119,11,106,10,43,208,54,242,19,220,63,103,92,227,190,177,254,194,
223,214,195,243,107,139,158,61,174,168,208,115,229,208,106,96,87,93,120,116,45,245,166,228,109,185,186,113,25,81,39,137,35,154,56,170,57,36,24,164,112,141,171,155,144,183,191,178,93,194,223,197,134,85,
226,72,192,232,178,242,1,117,107,52,20,171,82,163,237,255,0,87,159,71,135,178,183,166,245,233,173,213,211,159,51,122,126,40,42,187,15,227,198,105,243,53,212,76,106,22,151,119,245,86,224,143,248,126,252,
219,57,129,72,86,122,156,92,116,83,253,222,145,115,27,68,92,114,163,218,46,76,222,238,182,29,224,199,11,0,239,93,33,190,31,16,3,164,55,152,13,240,154,122,142,160,158,125,229,11,62,111,229,157,227,96,189,
140,232,146,62,35,44,172,189,200,203,95,196,172,63,101,71,159,91,24,117,175,243,74,219,237,65,183,43,62,65,245,14,236,234,45,189,185,241,184,108,158,19,182,182,252,233,216,189,55,149,199,231,41,224,170,
199,101,70,231,193,66,213,56,124,117,77,60,234,224,207,19,248,254,140,65,7,216,247,147,126,243,188,129,204,183,243,108,215,243,253,22,245,20,173,20,145,57,238,73,16,149,117,100,96,178,45,8,242,86,20,243,
166,122,231,62,241,237,54,235,103,227,29,170,241,46,89,11,3,25,6,57,65,83,66,40,112,79,230,58,166,157,139,191,232,187,63,228,183,243,18,249,57,68,93,182,230,103,112,101,48,155,59,32,203,34,199,95,182,
49,88,202,29,191,133,201,83,187,42,151,163,201,69,68,210,196,196,0,202,227,129,244,246,222,243,187,91,110,155,199,48,110,150,115,44,150,235,22,149,101,53,29,212,3,246,129,214,113,242,38,205,244,94,220,
251,55,202,43,34,181,228,183,79,60,202,8,37,28,189,116,176,226,164,14,32,245,84,155,111,39,24,238,41,247,85,67,233,165,219,81,103,119,93,92,175,250,82,44,38,54,178,190,228,219,234,94,48,7,245,191,184,
254,237,127,196,60,21,248,164,101,95,247,162,58,204,254,98,117,181,217,46,133,113,225,211,252,3,173,212,255,0,149,167,88,213,117,55,192,127,141,219,115,37,74,104,243,25,141,144,221,131,154,133,197,164,
254,41,217,121,108,142,252,168,105,111,234,47,163,112,32,231,144,5,191,30,242,227,149,236,205,142,195,182,219,145,220,35,7,246,231,174,26,123,169,188,46,251,238,15,53,110,40,250,163,55,76,138,126,81,210,
63,249,247,171,1,246,127,212,127,215,189,251,175,116,147,223,59,219,107,245,206,210,220,27,227,122,230,40,240,27,91,108,99,103,203,102,178,245,210,4,130,146,146,152,106,39,79,235,150,121,94,201,20,104,
11,203,43,42,40,44,64,246,146,250,250,211,109,179,184,191,190,157,98,180,137,11,59,49,160,85,25,36,244,166,206,210,226,254,234,11,59,72,139,220,200,193,85,71,18,79,250,178,124,134,122,160,175,151,223,
52,59,55,124,117,127,96,101,114,187,147,45,211,29,103,155,219,91,143,110,237,46,172,217,244,152,202,206,213,236,57,51,56,90,232,232,229,222,155,163,45,12,244,59,82,130,124,100,166,162,174,130,138,38,150,
10,99,162,73,12,135,142,125,115,71,222,159,153,249,223,155,211,149,61,180,178,142,223,151,82,96,46,47,102,205,97,15,165,202,168,201,241,62,8,198,1,173,107,142,178,131,148,61,163,135,111,155,104,150,226,
220,93,239,82,72,172,1,36,34,80,134,170,168,227,166,159,19,96,156,211,173,125,48,117,79,81,240,139,226,156,174,21,126,206,60,173,10,91,81,91,83,215,87,199,167,159,87,164,21,250,219,220,229,191,175,233,
69,167,134,179,79,178,157,116,55,219,87,166,253,185,178,156,24,135,252,123,171,36,248,119,86,78,220,40,15,42,192,220,127,169,177,31,158,125,164,216,143,108,203,95,159,69,254,237,198,14,227,3,143,225,232,
102,237,200,188,244,117,4,175,5,90,247,245,113,167,250,159,247,159,118,221,135,98,26,116,67,201,15,225,76,162,159,136,117,79,93,195,71,166,190,175,143,211,35,49,54,31,75,127,182,23,191,176,250,53,36,32,
10,99,172,144,132,137,44,227,111,151,81,190,57,199,6,70,110,201,219,21,42,26,13,193,178,51,244,51,161,23,15,28,248,218,184,216,16,125,36,217,253,146,115,25,104,255,0,118,220,41,202,76,167,246,30,163,237,
250,48,67,41,24,161,235,110,207,228,189,159,109,193,252,178,62,38,75,52,166,90,172,86,194,173,219,117,36,146,197,100,219,219,159,59,139,138,59,183,39,69,37,52,126,243,11,149,223,94,199,98,126,68,127,198,
143,249,58,227,191,188,214,162,211,220,222,111,137,71,105,186,213,254,244,170,79,243,39,171,68,246,32,234,48,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,
191,117,238,191,255,212,223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,
251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,107,127,252,241,55,204,91,235,189,126,3,252,88,198,74,181,85,13,217,121,191,145,91,222,145,24,48,162,219,
61,113,140,147,29,134,150,177,1,58,5,102,75,43,40,142,224,95,65,63,211,216,3,156,167,18,79,183,88,171,100,18,231,229,76,15,219,158,178,163,238,215,180,58,127,91,185,145,215,244,214,4,182,67,78,45,35,107,
106,31,146,168,175,219,208,27,83,38,161,44,132,219,94,167,39,232,45,201,224,27,113,236,56,216,12,221,100,181,43,143,62,170,195,179,34,142,167,123,230,26,59,16,213,115,158,56,255,0,118,27,17,111,167,184,
135,119,169,188,151,73,243,61,101,239,37,150,143,98,176,213,80,2,15,240,14,156,54,134,0,214,79,9,49,169,5,193,253,54,224,88,126,1,191,30,201,68,26,152,1,142,143,183,45,200,67,27,213,233,142,141,238,203,
217,11,34,196,76,66,236,170,73,42,108,163,241,110,57,55,255,0,123,246,115,105,100,90,128,46,58,136,247,190,97,101,44,60,79,231,209,136,196,236,136,146,21,95,23,12,0,96,126,154,120,227,250,218,227,216,
130,13,181,112,197,59,186,142,111,57,146,90,186,120,166,158,149,233,81,22,203,167,3,252,202,169,176,177,0,223,253,126,69,128,3,218,245,219,64,20,9,252,186,37,109,254,74,225,255,0,159,89,142,204,167,60,
152,135,251,111,248,213,239,239,103,109,30,107,251,58,175,239,233,15,227,199,219,211,93,86,202,129,150,222,49,249,250,40,213,97,254,191,226,254,217,125,180,102,171,142,149,91,239,238,15,246,159,207,164,
30,107,99,42,163,105,78,64,38,218,111,245,252,27,31,101,151,27,112,2,160,116,38,219,249,129,139,2,95,29,2,59,139,108,8,29,238,159,75,254,45,253,126,159,143,100,55,22,180,36,17,220,58,144,182,173,227,196,
85,5,186,8,114,216,96,186,184,183,62,147,107,173,143,209,109,249,250,127,176,191,178,137,97,43,92,99,161,229,149,240,199,175,65,198,87,26,20,144,84,125,63,3,233,97,193,28,127,103,217,116,177,121,131,208,
178,206,234,180,32,227,160,195,45,67,163,88,32,95,240,69,215,243,244,254,134,227,253,235,218,71,93,92,14,122,22,89,77,171,73,7,61,32,50,52,172,9,107,31,245,254,163,253,128,31,155,112,125,179,192,144,120,
244,40,182,145,89,69,58,78,205,21,137,183,22,254,156,6,31,208,19,249,247,82,0,251,58,55,142,154,71,207,166,170,136,245,16,194,214,176,30,171,155,243,244,254,159,83,239,74,105,90,30,150,68,40,167,208,245,
13,98,145,156,4,83,174,204,64,80,79,208,27,223,139,0,160,115,253,61,191,226,45,56,245,115,18,184,56,224,42,79,0,0,25,36,240,0,113,36,208,117,18,54,130,161,26,90,58,186,74,216,150,70,133,229,162,169,134,
174,37,153,13,158,41,30,154,89,21,37,83,193,86,177,31,211,218,151,241,98,33,102,137,227,106,84,6,82,164,143,81,80,42,62,206,138,44,47,246,205,222,25,167,218,55,75,91,184,17,202,51,65,44,115,42,184,226,
140,99,102,1,135,161,207,92,141,192,186,177,63,237,39,155,219,143,161,23,184,247,181,98,73,4,142,158,104,84,241,20,235,144,32,129,96,15,39,235,254,63,80,121,224,31,106,18,70,174,71,30,144,92,66,120,30,
61,96,144,125,72,39,250,173,174,57,28,220,127,129,228,123,48,133,169,208,110,242,33,164,143,46,162,74,190,146,72,184,34,230,223,155,125,108,127,2,205,236,226,217,242,15,30,128,219,132,64,22,160,207,88,
80,219,155,253,24,142,120,224,125,71,28,31,234,61,155,33,37,72,35,39,160,133,212,121,108,99,167,218,41,74,146,188,92,53,212,142,15,54,63,95,205,189,167,149,53,173,124,199,69,195,181,171,213,138,244,174,
233,167,221,123,20,225,171,150,42,169,104,233,102,199,214,83,76,124,145,212,210,79,19,195,44,50,161,184,104,167,129,202,55,212,29,94,192,155,181,179,193,112,93,24,138,228,17,228,120,130,62,206,129,251,
165,160,182,190,105,41,250,82,127,151,143,74,111,140,31,34,55,135,199,42,170,223,140,25,153,166,205,108,156,72,202,238,94,157,155,44,22,190,138,179,174,171,235,90,92,191,95,214,193,88,37,134,122,189,149,
144,170,97,18,21,230,138,101,35,233,196,15,239,15,183,27,119,49,220,175,184,22,81,248,87,211,105,138,239,69,85,150,225,69,18,112,65,4,9,148,103,250,75,234,122,134,249,163,219,219,59,157,194,121,116,128,
103,93,106,70,42,127,23,231,194,189,27,108,151,83,117,87,120,209,229,50,157,67,156,78,142,236,92,213,35,211,100,240,84,146,205,23,90,111,100,97,171,237,115,24,136,156,140,68,211,63,233,154,17,161,88,242,
163,159,113,174,193,238,63,59,251,121,32,181,221,100,155,114,229,236,2,213,255,0,24,141,71,207,132,170,7,225,106,181,120,30,162,230,180,230,62,69,220,237,247,125,178,98,94,7,212,173,77,84,63,48,112,192,
249,131,92,87,170,218,197,124,84,236,216,187,247,15,241,235,63,131,200,99,119,95,110,111,13,175,176,160,140,133,52,227,109,101,179,148,245,251,159,59,69,149,12,148,117,216,111,238,230,50,97,28,232,215,
45,42,163,46,163,111,121,139,237,191,53,108,158,227,221,114,251,109,23,113,201,19,203,156,129,220,162,186,25,78,82,65,154,169,244,199,83,23,51,123,253,181,238,190,219,239,247,119,208,253,55,49,91,218,
177,42,181,240,165,106,105,5,15,21,58,141,74,30,30,71,173,244,176,88,138,13,189,133,196,96,49,80,10,108,86,11,23,65,135,198,83,173,180,193,143,197,210,197,67,71,8,181,133,163,167,129,71,208,125,61,231,
90,40,141,22,53,20,85,20,31,96,225,215,37,38,153,238,37,150,121,26,178,59,22,39,212,147,83,252,250,118,247,110,155,235,139,58,160,44,196,42,128,73,98,64,85,3,146,88,158,0,3,146,127,167,189,19,64,79,94,
25,199,84,181,242,135,185,35,239,253,233,93,71,133,175,131,37,241,251,165,178,203,2,154,89,210,124,63,111,247,93,35,222,27,60,69,162,202,236,254,176,144,6,54,45,13,78,88,219,212,33,30,249,191,247,190,
247,200,221,220,167,181,60,165,184,124,96,53,236,145,154,209,63,223,117,7,137,225,79,74,159,74,100,159,180,220,151,244,173,6,227,184,91,145,184,78,42,1,25,138,31,207,131,73,143,152,95,74,158,170,95,230,
45,37,98,238,173,135,130,175,145,228,105,122,231,43,184,106,4,135,208,245,219,175,35,61,52,245,83,92,128,24,210,193,166,255,0,217,81,245,3,222,60,251,87,31,211,108,27,181,242,71,166,73,55,8,209,104,63,
12,32,16,62,194,196,154,122,231,172,163,228,99,29,247,49,110,147,10,20,181,131,66,143,77,84,4,143,76,99,170,200,218,143,51,124,37,233,136,203,41,135,110,118,47,96,96,149,144,134,9,246,219,146,190,40,209,
217,110,164,104,0,143,175,30,250,17,186,55,139,97,105,40,31,18,131,251,84,31,242,245,58,123,117,32,143,125,188,140,124,77,8,255,0,15,86,15,240,223,44,23,31,37,59,72,63,74,176,187,0,117,0,7,208,243,107,
123,47,217,223,76,146,39,168,232,195,221,11,125,127,75,56,244,167,70,163,178,217,95,29,59,144,45,165,181,126,71,43,111,235,248,246,171,116,175,134,58,5,242,170,149,186,10,61,71,248,115,213,71,247,36,74,
213,245,132,27,128,77,191,196,216,219,233,205,135,176,194,177,214,184,207,89,37,102,43,99,29,71,151,65,199,199,236,159,240,173,241,184,37,107,31,14,204,221,21,76,47,96,223,109,140,170,148,2,47,207,35,
218,30,99,139,93,148,0,121,207,24,253,172,58,3,243,18,145,20,142,120,10,255,0,128,245,182,15,242,19,172,146,191,249,95,244,5,75,220,6,173,236,116,140,92,17,227,135,176,183,20,41,163,143,74,15,25,176,247,
150,156,162,52,236,118,235,232,204,63,159,92,128,247,233,66,251,165,204,148,243,49,159,219,26,159,242,245,113,190,196,221,67,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,
223,186,247,94,247,238,189,215,255,213,223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,
238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,197,136,80,73,54,28,220,158,0,22,36,146,110,44,0,247,238,189,214,158,155,195,122,47,201,111,158,159,42,126,
84,253,227,100,246,118,217,201,83,252,103,233,10,162,160,83,62,215,235,183,100,222,249,204,106,139,163,193,149,221,179,84,67,229,91,153,4,87,191,30,226,29,198,232,95,110,183,183,128,213,53,105,95,177,
113,95,204,215,174,134,123,109,176,183,44,123,127,176,109,143,16,75,201,193,185,155,215,84,191,0,63,98,1,143,42,244,186,205,100,86,143,27,91,82,231,72,134,158,87,230,220,176,70,255,0,11,125,126,158,208,
220,205,162,39,111,32,58,30,89,192,215,23,80,66,185,44,224,127,62,171,67,46,78,79,113,87,207,125,90,234,100,5,191,63,169,143,210,223,150,62,226,107,230,241,38,102,35,21,61,101,206,206,139,109,182,219,
71,76,5,29,14,253,119,133,87,146,34,20,219,211,107,173,207,58,127,165,207,30,219,134,61,76,164,113,232,59,204,23,250,17,205,122,61,91,23,4,169,12,119,77,64,42,126,45,244,255,0,95,235,236,97,183,219,2,
6,40,122,129,119,237,193,139,190,124,250,28,168,49,128,32,26,120,176,250,1,115,249,63,144,61,138,34,128,42,140,14,128,23,23,140,88,209,179,211,192,199,11,126,149,252,158,46,72,250,216,113,253,125,188,
35,245,61,36,250,134,248,139,116,81,62,90,252,219,248,185,240,135,109,208,238,63,145,93,155,65,181,42,179,81,201,38,218,217,184,186,121,183,6,252,221,17,194,193,37,159,13,181,168,53,86,53,12,77,195,85,
76,97,166,13,233,242,106,227,218,219,45,174,239,112,114,182,177,213,71,18,112,163,237,63,230,4,244,28,230,30,118,216,185,86,20,155,121,190,8,238,59,99,81,170,70,242,168,81,192,124,205,7,207,166,15,134,
63,57,126,59,252,251,217,59,183,124,124,125,200,238,138,138,13,143,159,131,110,110,140,78,241,219,255,0,221,252,214,50,182,182,151,239,113,243,253,186,85,214,211,212,227,235,233,110,99,146,57,73,12,140,
172,1,30,247,184,109,55,27,123,164,119,42,181,97,80,65,168,199,228,58,223,41,243,206,209,205,214,247,87,59,67,200,60,7,10,234,235,165,133,65,32,224,144,65,167,249,58,52,217,76,82,60,108,161,63,4,220,216,
131,244,254,135,129,127,100,23,54,163,77,105,158,164,43,43,226,24,16,221,1,91,191,8,172,178,55,139,144,8,250,3,101,230,228,155,127,95,97,107,235,106,212,211,61,72,251,54,226,123,6,172,116,92,115,248,205,
12,254,158,5,193,226,252,27,253,45,253,111,236,57,52,67,34,153,234,87,218,239,24,133,238,232,36,204,208,219,95,167,128,24,114,57,184,255,0,2,13,151,217,76,176,86,180,232,113,99,115,80,59,179,208,85,153,
162,244,191,166,224,3,166,246,227,242,121,177,250,91,253,231,217,100,177,133,36,142,134,123,125,207,114,244,25,100,169,121,35,128,173,171,143,167,54,63,235,216,251,72,235,146,126,93,12,172,231,173,7,159,
72,218,136,10,158,69,141,137,7,251,38,194,224,128,71,214,195,219,68,84,116,36,133,235,138,244,203,36,108,235,202,242,205,111,173,205,207,34,255,0,79,213,237,179,218,120,244,103,21,75,4,94,36,227,231,94,
168,167,249,132,124,211,221,203,188,51,221,11,213,121,169,246,246,223,192,105,199,111,189,199,136,168,146,12,198,224,204,73,10,189,110,6,151,33,9,89,104,112,184,209,32,142,97,11,43,212,77,168,49,10,186,
91,37,61,175,246,250,198,27,11,94,101,222,109,132,151,242,247,196,140,42,177,167,225,109,60,11,176,205,72,58,71,14,184,223,247,211,251,212,243,38,255,0,205,123,231,180,156,133,187,189,167,37,237,210,152,
110,230,129,138,201,125,58,226,84,105,20,234,22,209,181,80,70,164,9,24,49,122,138,14,135,207,229,151,209,59,255,0,175,182,102,111,181,55,142,94,182,151,23,218,56,188,123,109,125,155,36,243,74,63,133,193,
81,37,84,27,187,35,12,140,209,193,83,145,71,43,74,170,60,134,6,46,231,212,170,3,62,241,115,54,217,184,222,91,236,22,80,135,185,180,144,153,101,160,195,80,15,9,79,19,74,213,252,129,20,226,15,83,71,247,
123,123,53,206,92,175,181,110,222,235,111,215,178,91,108,59,213,159,133,103,103,83,250,232,36,7,235,37,83,128,160,171,44,24,212,192,179,212,41,21,179,214,94,73,35,250,240,44,15,55,228,127,175,253,125,
195,17,182,146,106,122,233,83,40,60,71,14,177,32,10,74,155,221,135,215,233,123,219,139,243,111,106,86,181,7,203,164,23,41,85,34,153,29,113,144,13,55,80,15,230,247,181,185,227,252,125,152,192,213,2,167,
61,6,239,35,160,38,157,68,42,57,254,163,158,7,212,17,201,191,251,31,102,214,205,74,103,29,2,55,72,0,44,122,134,125,45,207,31,94,63,199,240,71,228,2,63,222,189,158,70,106,56,244,11,188,138,164,227,169,
148,242,105,35,83,0,5,128,254,156,253,57,227,129,237,202,102,138,42,122,35,101,210,218,122,31,250,75,119,182,221,221,84,208,203,63,142,147,36,69,52,192,240,154,137,93,15,207,2,228,254,125,135,247,139,
79,22,18,20,100,116,93,186,91,137,237,9,31,218,38,122,29,123,191,106,85,231,105,113,121,141,185,86,152,189,217,183,50,49,238,45,149,153,107,180,20,121,216,97,49,181,29,117,173,230,195,103,169,152,210,
213,198,77,154,55,7,234,1,246,14,136,219,210,230,202,254,19,38,217,113,25,142,100,243,40,77,117,47,163,161,1,144,241,4,116,31,59,122,239,54,50,89,150,211,118,157,209,183,163,143,47,176,240,61,8,253,35,
219,84,155,163,23,135,220,140,179,109,170,177,88,248,157,193,142,153,217,103,218,155,170,130,81,77,147,197,100,46,67,10,88,234,200,104,101,62,153,41,221,24,27,95,222,63,115,127,41,220,237,23,247,187,83,
210,117,0,188,76,63,209,161,106,149,116,254,150,156,48,226,24,31,81,212,93,188,66,171,103,51,221,69,67,27,21,145,72,248,79,10,145,233,92,215,252,157,91,30,71,102,226,254,64,117,236,27,87,122,73,91,134,
222,27,103,193,149,216,219,251,11,33,166,220,219,91,43,75,162,162,139,39,136,201,68,201,63,140,200,138,207,16,109,18,47,34,198,222,241,247,107,230,77,203,219,206,99,143,127,229,185,216,64,238,60,88,181,
21,87,161,249,124,46,167,225,113,144,126,68,142,177,239,121,219,237,237,238,153,161,210,214,146,84,50,145,130,14,8,32,249,116,123,254,6,252,181,221,219,247,33,158,248,221,242,6,166,130,30,251,235,122,
24,170,113,121,232,155,193,77,220,59,22,37,240,211,111,60,108,108,21,31,47,72,17,83,35,20,119,33,143,147,72,245,219,176,158,196,251,199,183,251,161,203,240,52,151,0,238,201,24,173,77,25,192,29,218,151,
202,68,56,122,96,130,24,99,172,98,247,31,145,199,46,220,166,233,182,198,70,209,59,101,127,223,78,115,167,253,33,252,62,148,167,167,86,15,191,59,7,101,117,134,214,202,111,93,255,0,185,177,27,83,107,225,
160,106,140,134,99,51,84,148,180,177,168,7,76,81,3,121,106,234,231,111,76,80,66,175,52,174,66,162,179,16,61,206,55,251,141,142,215,105,53,254,227,116,144,217,198,181,103,114,2,128,56,228,245,27,217,88,
222,110,55,49,218,88,219,60,183,46,104,21,69,79,251,3,212,156,15,62,170,23,228,111,202,29,225,222,152,9,48,24,57,119,87,71,116,102,101,164,138,191,35,58,255,0,11,238,158,229,195,202,165,127,135,109,204,
101,205,79,91,108,236,162,157,51,86,213,17,145,169,133,173,26,70,24,251,231,207,189,95,123,216,111,77,239,40,123,78,134,121,242,147,94,19,72,147,202,138,65,169,60,106,23,141,50,192,117,145,28,131,237,
68,145,220,139,237,197,99,158,241,40,64,227,20,71,213,143,9,28,121,1,128,125,122,14,182,246,210,133,182,150,206,219,216,172,45,54,220,219,130,162,150,139,111,237,202,21,209,71,141,197,66,195,199,18,43,
122,228,153,216,153,37,149,137,121,164,102,102,36,159,124,251,73,100,220,55,249,222,230,233,167,190,145,181,75,35,101,153,201,207,229,228,163,128,20,3,169,148,75,14,223,37,235,70,250,140,81,145,95,50,
212,207,85,155,252,234,118,166,67,29,189,186,70,40,43,235,113,27,75,59,180,41,176,187,165,113,147,61,29,94,118,147,110,228,234,234,6,9,107,226,41,45,29,53,75,86,68,39,8,67,60,103,77,236,125,230,135,221,
254,45,185,95,120,178,146,217,100,186,182,97,36,90,133,66,51,173,11,233,224,77,1,161,60,50,122,16,123,19,163,118,223,55,107,123,169,72,138,69,46,192,113,96,165,113,254,126,170,127,105,102,198,47,168,183,
31,90,10,73,105,49,180,253,149,146,220,219,78,130,21,99,69,67,138,201,8,38,120,105,73,44,85,34,156,58,243,115,253,79,62,242,110,234,237,102,137,21,154,178,83,63,35,214,93,108,60,185,46,221,188,189,220,
106,22,223,83,5,255,0,72,104,87,246,100,14,141,215,199,61,238,187,106,162,52,168,103,85,144,45,216,240,62,128,90,192,139,123,42,130,227,233,166,215,249,116,36,230,142,94,125,226,196,104,3,88,24,232,226,
239,78,199,160,171,197,248,227,169,12,207,27,30,90,247,184,250,31,207,181,55,247,171,42,128,15,151,64,126,90,229,107,168,110,203,73,17,1,79,85,237,216,181,31,196,106,42,166,79,85,245,5,183,63,131,199,
210,220,123,40,70,4,171,14,167,8,108,252,43,69,141,133,8,29,3,157,91,40,164,237,10,10,57,8,88,115,184,252,222,2,65,125,2,69,201,227,167,167,85,23,31,150,126,45,205,207,182,119,240,78,210,243,40,238,138,
68,113,254,213,129,232,1,204,80,106,130,116,60,8,61,109,149,252,128,94,72,127,150,143,87,97,101,176,151,107,239,190,221,219,147,70,47,170,57,113,251,247,46,242,198,234,121,71,18,212,18,71,248,251,202,
174,75,152,79,177,65,32,53,5,201,253,180,63,229,235,143,127,120,56,140,94,233,239,213,226,201,17,255,0,170,106,63,201,213,211,123,21,245,10,245,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,
175,117,239,126,235,221,123,223,186,247,95,255,214,223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,
247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,90,223,205,107,229,123,124,85,248,129,190,178,123,98,174,23,238,46,215,240,116,223,73,97,18,88,
206,71,37,191,119,249,124,37,62,70,154,152,72,42,126,215,110,80,84,79,91,44,200,165,98,104,147,85,181,15,100,28,199,185,174,223,183,74,21,192,185,148,105,81,231,159,136,254,67,249,211,169,47,218,110,80,
126,113,231,93,174,202,72,137,218,224,111,30,225,188,132,81,247,16,77,41,86,52,80,60,234,105,213,4,244,238,194,165,234,94,174,216,221,113,77,59,213,29,165,183,233,104,107,242,12,215,147,41,154,159,85,
110,123,43,59,30,100,159,35,150,169,154,71,98,110,196,223,220,101,10,5,141,64,244,235,160,19,184,150,87,114,160,2,112,7,0,6,0,31,32,0,29,69,237,108,242,227,118,197,90,134,8,213,87,136,115,98,86,196,146,
45,107,223,217,86,243,112,35,182,101,173,9,61,9,121,55,110,107,173,226,7,211,218,153,252,235,142,137,70,26,51,61,83,74,65,37,229,213,126,121,177,34,215,252,114,127,62,227,105,155,83,103,172,151,196,86,
202,171,192,10,116,111,58,211,30,12,148,247,75,18,86,227,235,244,183,234,183,54,246,186,205,65,148,99,135,81,135,51,78,85,28,87,163,211,179,232,52,193,23,164,114,7,227,139,142,62,191,225,207,177,206,223,
29,23,81,234,4,222,103,239,124,244,47,208,209,217,69,129,252,127,198,135,179,181,95,33,208,58,89,142,163,79,46,154,247,190,225,196,117,238,201,222,93,129,184,181,12,14,196,218,91,147,121,230,142,165,75,
227,54,198,30,179,51,91,26,191,26,90,104,168,202,3,253,91,219,241,192,242,73,28,106,123,153,128,31,153,167,72,110,183,20,179,181,185,187,153,191,78,40,217,207,216,160,159,242,117,242,190,249,105,242,119,
176,190,104,252,144,223,125,229,217,217,198,151,37,189,247,27,69,135,134,165,157,113,59,59,103,199,88,212,187,115,111,227,105,139,178,80,226,112,24,166,64,85,52,135,125,114,31,83,147,238,88,180,181,142,
202,218,56,34,29,170,63,105,243,63,159,88,55,191,111,119,188,199,187,221,238,183,242,214,105,95,30,136,191,133,71,162,168,192,31,229,235,232,95,252,170,254,42,124,97,248,193,241,87,3,139,248,197,216,24,
62,226,196,239,217,168,55,63,98,118,238,23,59,141,220,16,110,253,244,49,20,180,213,212,209,201,139,111,182,195,227,176,90,90,10,90,22,81,44,74,11,62,167,102,99,29,111,87,55,119,87,68,220,198,80,38,21,
77,70,61,126,211,235,214,92,251,121,178,236,91,30,195,26,236,183,171,114,179,81,165,148,16,117,61,6,40,62,21,92,133,83,159,51,147,213,133,100,105,52,169,26,108,0,63,94,77,173,123,88,126,125,145,72,42,
189,73,22,210,141,74,67,96,244,16,110,138,2,209,200,72,22,33,190,159,235,92,127,66,61,135,239,161,29,14,118,123,154,21,207,69,159,115,99,202,188,158,155,144,79,215,250,255,0,94,62,191,91,123,9,221,71,
164,154,112,234,91,217,174,234,23,56,232,21,204,209,146,239,192,189,136,181,193,63,224,7,244,227,217,84,209,106,90,1,158,164,43,11,156,33,7,160,171,51,66,72,96,20,11,147,250,71,60,31,207,23,3,217,76,176,
231,61,13,172,46,65,210,9,207,65,102,94,133,174,73,75,131,114,65,32,113,205,136,22,213,199,180,50,71,90,138,231,161,149,149,205,116,143,49,210,2,182,148,133,125,75,127,200,36,90,203,207,22,191,251,235,
123,68,200,65,52,232,89,105,115,82,180,53,233,49,44,110,172,116,15,80,4,169,60,89,130,234,79,175,227,80,247,70,65,85,215,192,145,95,179,163,193,52,190,5,195,219,98,228,67,38,143,147,132,98,191,177,169,
214,152,93,147,81,89,87,216,155,242,171,32,210,61,117,70,243,220,243,86,52,165,140,134,166,76,221,115,77,175,87,171,87,144,159,175,188,245,176,85,75,27,36,65,216,33,64,62,192,160,15,229,215,203,150,249,
45,196,251,214,241,61,211,19,116,247,82,179,147,196,185,145,139,19,243,44,79,86,111,240,27,230,143,97,211,246,54,205,233,46,198,207,75,185,54,30,225,130,29,169,181,101,175,130,155,248,134,210,201,65,77,
163,1,5,53,116,41,12,211,98,38,240,253,179,197,47,144,174,181,101,32,41,6,36,247,51,144,54,171,173,167,112,230,13,174,213,97,221,98,172,178,21,192,149,120,190,161,195,85,59,131,12,224,214,181,235,59,190,
231,159,122,110,119,229,158,122,229,47,108,249,187,126,150,243,219,203,230,75,40,99,150,140,108,93,187,109,222,7,160,101,140,62,148,120,137,42,85,187,64,35,171,224,145,10,240,56,241,146,24,18,44,77,202,
253,79,227,222,50,35,41,201,21,235,182,44,165,89,149,184,131,79,217,212,103,10,10,155,254,65,39,157,86,255,0,124,125,169,140,213,123,78,61,58,75,58,2,42,7,93,55,231,250,220,253,120,63,91,253,79,252,139,
218,216,30,189,7,238,227,193,249,117,17,134,150,176,54,189,197,255,0,31,64,62,156,125,65,246,107,3,145,74,158,29,4,119,40,65,87,61,65,149,120,254,132,27,129,123,222,220,243,111,246,147,253,125,159,65,
32,42,42,122,3,223,69,66,122,225,27,221,191,194,192,243,253,147,126,0,31,79,167,181,53,32,212,30,131,87,9,225,176,233,254,130,169,160,154,41,85,138,188,101,24,16,109,165,209,181,41,252,126,71,215,219,
19,162,178,158,61,48,184,168,166,15,30,143,158,206,206,197,190,182,76,113,185,213,89,69,24,134,80,196,23,14,169,101,109,64,223,213,236,5,185,90,155,105,137,3,183,160,220,136,219,125,253,105,216,77,71,
69,135,120,238,122,158,159,236,20,223,73,79,53,86,217,205,83,211,225,187,99,11,8,46,106,177,116,231,195,142,222,116,116,226,225,178,248,8,156,172,246,26,167,164,224,155,168,246,158,243,96,78,106,217,127,
118,171,4,221,173,216,189,156,158,142,114,208,147,252,18,17,81,232,212,167,72,249,159,100,23,150,210,111,214,137,171,183,77,194,113,213,25,198,191,153,94,7,229,159,46,175,179,225,22,255,0,135,120,117,
61,12,191,196,147,53,81,179,119,89,218,244,153,184,165,21,9,150,218,185,106,17,149,219,53,38,112,72,152,173,35,152,193,250,128,128,30,65,247,130,222,239,236,103,108,230,87,6,219,193,75,219,97,51,70,69,
52,76,141,225,204,180,242,171,80,254,117,29,97,110,241,1,183,191,220,108,25,181,36,69,168,125,64,53,83,251,8,233,111,242,111,99,238,124,22,87,108,118,199,89,79,54,27,182,58,230,190,45,221,176,115,52,186,
162,122,153,41,136,155,39,181,43,153,10,181,94,35,63,76,173,20,144,49,208,197,173,253,171,133,158,201,243,230,229,200,60,199,97,116,46,76,118,109,42,235,201,162,181,104,178,31,95,225,127,84,57,233,0,179,
181,230,93,150,235,111,185,140,72,186,10,178,158,36,124,190,98,149,95,67,210,2,139,183,178,253,199,65,130,237,253,239,185,50,157,193,216,217,73,159,33,139,165,207,64,104,118,15,80,230,145,188,85,88,61,
143,215,168,210,99,105,50,152,89,135,140,228,43,68,245,143,164,56,97,113,236,121,239,39,185,126,229,115,247,49,238,123,31,50,110,111,103,203,176,182,32,137,200,73,163,108,164,132,138,118,56,32,133,92,
249,51,30,158,229,14,66,216,182,187,88,229,142,36,142,219,32,211,50,61,56,248,142,114,126,106,40,58,49,61,85,213,153,77,237,148,125,211,191,42,106,242,149,6,68,150,245,114,201,33,118,253,86,38,75,220,
1,244,31,65,248,247,142,219,214,239,111,179,219,139,29,173,2,41,90,26,83,252,157,26,111,251,253,189,132,31,67,181,162,199,23,244,113,254,14,141,83,96,97,155,119,109,154,58,104,66,82,209,58,21,68,2,200,
177,219,77,135,0,125,61,162,228,87,55,27,186,153,90,174,198,191,207,160,12,151,109,30,213,125,35,159,212,97,254,30,136,31,243,148,234,106,173,227,241,246,147,121,98,168,205,78,75,172,183,29,62,101,230,
140,51,77,6,27,39,26,210,85,190,149,4,154,120,234,227,136,189,254,151,30,242,207,218,173,245,54,47,113,237,33,154,64,182,215,246,198,44,240,46,149,43,249,233,45,209,215,179,187,240,217,121,155,110,158,
71,211,3,191,134,255,0,233,100,237,36,253,149,7,170,89,248,195,180,246,55,103,96,170,104,178,239,162,185,99,99,78,84,129,40,145,146,225,127,173,145,135,211,222,102,53,170,52,142,165,136,57,167,219,214,
115,238,59,238,227,182,248,15,111,70,141,78,107,233,95,245,83,165,94,226,234,108,190,194,173,148,192,30,74,69,144,152,228,3,157,60,233,39,73,32,241,236,158,234,41,17,152,48,234,83,229,174,99,219,183,139,
116,12,64,150,153,31,62,146,83,230,106,192,49,77,51,13,43,99,114,120,254,182,36,254,45,207,180,125,196,121,145,208,214,59,75,100,163,162,12,252,186,15,55,30,102,145,32,151,84,130,255,0,91,177,189,205,
191,23,250,15,111,196,140,105,140,116,150,254,234,40,146,149,20,29,7,125,114,148,121,29,253,30,229,175,169,138,131,108,236,10,106,157,227,185,114,179,182,136,40,113,184,136,158,165,203,200,108,161,165,
241,233,81,123,146,64,252,251,214,244,237,30,218,214,136,186,174,110,79,134,138,50,73,56,199,217,212,87,204,27,132,69,28,212,83,249,117,184,119,242,80,216,153,157,153,240,3,174,115,57,170,9,177,114,246,
222,236,236,78,234,199,227,170,20,199,81,73,130,236,141,209,87,153,219,235,44,68,3,27,205,135,16,203,98,1,253,203,254,125,229,31,35,88,203,183,242,214,223,111,55,199,166,191,200,15,242,117,199,79,126,
119,139,109,235,220,254,98,158,209,129,134,22,88,106,60,204,99,75,127,58,131,243,234,217,125,139,186,135,122,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,
221,123,175,255,215,223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,
175,117,239,126,235,221,123,223,186,247,94,247,238,189,209,21,249,175,243,71,9,241,119,109,226,240,59,103,20,155,255,0,190,55,251,156,127,89,117,141,27,188,181,85,245,14,254,22,207,103,99,166,38,162,135,
110,208,49,37,156,233,51,56,210,166,193,153,99,111,114,125,199,218,125,190,217,166,189,187,158,47,173,49,150,69,102,162,170,142,50,72,124,145,127,107,30,209,158,134,220,151,201,183,92,211,120,89,203,69,
180,196,71,137,37,63,227,41,234,199,249,12,158,181,108,237,181,237,78,243,249,225,71,148,239,173,247,47,96,110,206,129,217,20,123,195,117,80,81,144,187,47,99,246,39,97,164,159,221,173,131,181,113,234,
237,71,0,218,219,115,252,166,161,209,117,52,242,2,89,173,168,192,62,215,115,118,233,238,70,223,123,207,187,137,144,219,93,220,60,118,186,234,164,193,17,210,93,99,225,26,59,215,66,138,146,22,172,106,122,
206,47,109,249,123,110,229,206,95,184,59,109,152,138,25,159,72,243,119,88,233,86,118,226,196,183,229,143,78,140,180,178,232,140,146,121,252,240,69,207,37,143,45,205,201,254,182,247,44,189,17,15,113,6,
157,12,148,107,102,44,49,209,70,238,253,202,42,42,97,197,68,224,136,201,12,3,113,193,231,129,253,61,131,183,187,141,67,66,156,14,166,143,111,118,173,8,215,4,100,231,252,221,6,59,98,45,82,160,181,174,223,
75,243,109,92,145,113,201,62,194,122,181,50,142,165,107,179,166,30,142,215,88,210,122,233,154,195,210,161,141,191,60,131,254,244,127,175,179,109,189,106,253,67,28,215,40,2,64,15,71,143,106,83,126,212,
96,47,225,120,226,214,32,126,63,215,246,60,176,82,168,160,245,3,111,50,177,118,207,67,5,5,45,209,120,250,139,88,243,207,224,219,250,241,236,237,84,232,4,116,12,158,122,177,21,225,208,23,243,15,101,229,
247,159,196,79,148,59,79,5,77,44,249,189,193,208,29,173,142,195,211,197,254,126,124,148,219,63,40,212,145,71,166,236,76,178,168,22,254,151,246,186,200,44,119,118,178,19,194,69,63,207,160,247,48,234,159,
97,222,237,208,254,163,218,200,5,63,210,158,190,73,206,172,172,85,129,86,83,164,169,224,130,190,146,8,252,16,71,185,67,172,43,235,97,111,248,77,207,125,118,62,201,249,243,133,233,12,86,127,50,253,101,
221,123,79,120,82,238,205,154,179,205,54,2,92,222,220,193,84,103,112,59,165,168,89,154,10,60,174,44,208,73,16,169,140,35,188,83,24,220,149,210,1,15,49,91,197,45,131,74,202,60,68,34,135,207,230,62,195,
94,165,63,104,247,107,203,46,106,130,194,41,155,232,238,149,131,167,225,37,84,178,177,30,68,83,143,206,156,58,223,195,33,72,64,62,155,113,107,253,65,226,255,0,235,255,0,91,123,142,202,225,143,89,103,4,
255,0,9,174,58,9,247,45,16,209,37,215,157,60,255,0,67,192,60,126,45,236,154,245,1,83,142,134,27,76,230,169,154,154,244,90,119,93,18,171,185,0,94,237,123,142,61,87,183,30,194,119,73,156,142,165,141,150,
122,128,9,199,64,86,106,150,204,198,195,144,71,208,15,246,60,127,64,61,146,186,233,37,124,250,145,236,103,237,2,189,6,89,122,66,193,172,44,192,147,244,2,224,125,13,135,212,123,67,52,85,4,145,208,190,194,
235,77,20,183,65,110,90,138,236,215,227,130,120,3,245,3,244,181,184,36,255,0,143,178,169,98,60,60,250,25,216,220,240,4,244,28,228,232,244,234,22,95,73,35,232,127,60,243,244,189,237,111,104,93,41,92,119,
116,48,178,185,202,144,122,69,85,211,232,98,214,228,53,205,193,189,190,182,54,250,234,231,218,55,78,32,113,232,87,103,116,22,68,147,138,131,195,215,229,214,172,31,61,62,59,110,238,162,239,13,233,185,6,
14,182,78,191,223,121,186,237,211,182,183,5,37,52,179,98,227,57,89,190,239,37,134,172,158,40,252,84,25,12,117,124,206,162,57,52,151,132,163,169,55,54,204,47,111,121,150,211,127,229,251,8,132,227,247,156,
17,172,114,161,35,85,84,80,48,28,72,96,1,175,173,71,92,3,251,211,123,53,191,123,77,238,167,50,153,182,215,28,165,185,93,203,117,97,112,170,76,47,12,206,95,195,214,6,149,146,22,98,143,25,58,128,1,169,70,
29,57,127,47,207,143,251,199,178,123,199,104,239,118,196,87,81,236,46,186,203,65,185,179,123,134,166,158,106,122,26,154,202,0,207,139,194,227,103,145,18,58,220,141,101,121,140,178,33,62,56,85,153,136,
244,221,55,185,124,203,99,178,242,222,225,102,211,3,184,221,70,99,141,1,5,187,133,25,136,226,21,84,156,249,154,1,209,159,221,27,217,174,101,247,71,221,190,87,191,180,177,145,57,87,104,187,138,242,242,
232,169,17,34,192,194,68,137,90,148,105,165,112,170,168,13,116,150,99,64,58,217,70,66,210,23,114,8,214,197,249,230,215,102,54,35,139,112,126,159,143,120,128,163,72,167,150,58,250,11,145,181,201,35,255,
0,19,19,251,77,122,134,202,72,28,88,27,243,200,252,94,255,0,147,197,191,214,246,252,68,10,250,244,204,159,1,29,122,196,142,120,186,240,126,163,243,245,39,159,199,181,113,246,147,158,7,162,107,132,173,
124,199,80,229,31,170,198,196,242,62,156,21,63,211,241,244,246,107,11,16,216,243,232,51,123,17,33,193,94,35,168,146,40,33,88,126,126,132,127,95,199,248,220,127,173,236,230,221,248,84,84,244,6,191,131,
143,80,141,212,241,112,1,60,106,60,88,220,139,31,233,236,208,80,138,249,244,22,185,142,132,159,62,166,195,37,136,55,63,239,0,243,253,62,159,236,125,185,171,90,16,122,42,200,168,60,122,29,250,95,121,156,
22,108,227,231,144,45,30,68,44,108,172,110,4,151,54,111,232,9,189,191,199,217,46,241,98,38,132,72,160,106,29,20,238,240,153,97,18,168,239,94,184,247,157,69,28,217,121,162,64,179,71,37,51,137,80,242,30,
55,77,13,25,91,145,103,140,145,237,38,201,104,226,141,79,60,31,245,124,250,85,178,92,106,182,240,228,90,163,141,36,30,4,17,66,63,201,213,183,127,43,173,166,219,67,227,232,163,139,202,244,217,30,202,195,
227,177,237,48,54,240,97,240,230,170,160,11,27,176,129,171,188,127,235,15,120,75,247,145,220,18,251,159,84,130,43,21,140,140,212,254,156,128,15,204,233,174,122,193,174,109,91,111,235,71,52,173,169,173,
180,82,200,23,236,13,65,254,175,151,87,7,217,123,66,76,254,204,130,190,36,242,84,81,25,13,209,75,21,69,177,86,181,175,101,111,199,184,146,211,107,19,236,86,219,132,121,144,96,252,199,64,46,94,221,86,203,
120,150,221,143,99,250,250,215,170,216,234,93,165,77,176,251,246,175,101,214,1,77,179,251,142,174,171,51,181,29,244,173,54,31,177,177,176,253,198,111,111,72,77,132,67,113,80,134,168,165,28,121,29,72,228,
143,98,158,96,221,27,152,121,34,45,210,49,171,122,217,148,69,63,241,73,106,198,145,203,243,240,154,138,222,152,225,208,191,116,149,246,200,166,120,201,54,206,117,10,102,132,241,234,219,176,248,202,108,
69,12,84,116,232,170,17,109,244,181,217,64,185,63,227,199,188,112,185,186,123,137,154,103,57,61,71,23,51,155,153,11,59,18,58,127,219,184,228,124,216,172,144,13,99,132,54,55,177,254,159,208,251,29,251,
118,165,183,116,30,96,116,135,118,184,211,100,99,95,63,242,117,155,182,54,150,35,121,109,12,190,7,61,68,181,216,92,214,54,187,17,155,164,117,89,4,184,204,156,15,79,82,64,96,195,201,18,176,116,63,85,117,
7,234,61,202,252,209,53,205,148,22,123,181,147,17,119,107,50,200,132,99,42,107,251,15,3,242,232,179,98,153,162,186,240,245,208,176,237,251,124,186,210,151,179,118,206,245,248,87,242,91,117,245,237,123,
84,195,141,162,202,190,67,111,87,2,203,71,154,219,25,9,5,70,54,186,149,135,165,227,104,28,106,81,202,155,169,250,31,121,249,237,239,55,90,115,215,40,109,60,193,105,32,50,152,194,202,60,210,69,195,3,249,
255,0,147,172,247,228,61,254,30,107,229,123,73,38,125,87,240,129,20,160,241,12,191,11,31,244,203,76,250,131,209,188,147,228,94,7,116,109,216,222,165,161,150,119,167,80,197,180,234,36,45,174,73,177,30,
196,119,37,156,16,203,95,159,82,14,201,182,61,173,210,188,82,209,71,167,69,35,119,239,122,67,83,81,45,36,138,136,218,153,66,91,131,201,250,95,129,237,28,118,229,137,20,234,91,253,230,209,91,170,151,169,
3,160,23,39,184,50,153,202,216,232,104,188,213,53,21,83,173,60,48,68,165,222,89,101,58,80,42,170,155,155,183,181,193,35,183,70,149,200,84,81,82,125,58,10,238,27,164,146,150,26,187,122,61,95,18,62,32,102,
190,96,119,30,223,248,137,182,167,168,143,99,99,42,48,189,137,243,71,125,99,137,48,224,246,77,45,84,117,88,62,164,161,201,68,124,99,114,239,42,152,252,114,194,173,174,42,125,78,194,200,110,103,200,220,
191,113,204,251,210,110,211,198,69,148,120,138,190,75,248,164,251,90,133,87,231,83,195,172,96,247,215,221,43,126,70,229,187,137,162,152,54,239,61,99,183,74,241,122,124,100,127,4,85,212,222,69,168,188,
122,223,27,110,224,49,27,87,1,133,219,59,126,130,159,21,130,219,216,172,126,19,13,140,165,141,98,166,199,226,241,116,177,81,80,81,193,26,0,169,21,53,44,42,128,15,192,247,148,113,198,145,71,28,81,173,35,
85,0,15,64,48,58,229,85,196,243,93,79,53,205,196,133,167,145,139,49,60,73,99,82,79,218,79,79,62,239,211,61,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,
189,215,255,208,223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,
117,239,126,235,221,123,223,186,247,64,23,201,159,144,59,63,227,39,78,110,206,220,222,50,25,105,112,84,194,159,13,134,132,131,91,185,55,53,118,168,112,123,126,133,46,25,231,175,172,182,171,115,28,74,239,
244,95,97,254,103,230,27,62,87,217,174,247,139,211,217,24,162,175,155,185,248,80,124,201,253,130,167,163,174,95,216,238,185,135,117,181,218,237,7,115,158,230,242,68,31,19,31,144,31,206,131,170,15,235,
10,108,182,40,246,111,204,239,146,117,226,191,178,242,91,123,57,191,247,13,93,121,242,83,117,238,197,197,80,73,95,140,218,24,88,92,148,199,72,105,99,138,41,21,45,227,66,35,30,162,196,241,167,221,223,112,
55,175,119,185,201,57,127,111,185,50,195,115,120,144,2,42,4,211,51,105,20,255,0,132,194,43,160,112,36,22,244,235,48,108,54,123,125,163,111,176,218,118,219,125,42,74,164,75,230,197,168,11,183,171,18,73,
169,234,182,254,33,67,156,220,251,35,118,119,158,238,89,23,120,252,144,236,13,201,219,217,95,57,99,53,54,19,41,89,53,54,207,198,122,189,73,21,6,6,36,68,75,217,87,223,74,185,91,97,181,229,157,143,103,229,
235,37,165,173,141,180,112,175,251,69,1,143,251,102,169,252,250,156,164,129,54,251,123,93,186,17,250,112,70,169,246,145,241,31,205,137,61,24,173,205,147,139,27,142,169,169,145,180,8,97,145,217,137,255,
0,105,224,88,216,113,236,218,238,77,33,207,144,29,44,219,109,141,204,208,198,163,4,255,0,151,170,234,220,25,231,206,238,42,186,166,114,241,137,100,84,185,184,23,107,11,17,249,22,246,0,221,36,46,196,215,
61,100,167,45,89,139,123,52,0,121,116,187,218,49,135,158,17,99,109,64,254,79,244,38,223,224,120,246,74,141,223,142,61,28,238,21,16,231,211,163,217,213,208,2,241,18,63,178,191,159,197,184,31,236,45,236,
251,110,29,195,237,234,13,230,231,167,137,156,84,244,120,118,157,61,225,136,233,23,0,31,173,238,45,96,63,165,214,254,199,214,98,128,117,1,239,82,81,220,252,186,26,177,84,122,213,56,36,216,31,241,191,210,
252,126,45,236,241,6,6,58,3,220,79,167,80,175,74,152,241,145,203,20,145,84,193,29,69,60,209,75,79,81,4,195,84,85,52,243,163,67,81,77,34,241,116,158,157,217,27,252,27,219,180,200,32,103,162,199,159,85,
107,240,159,46,180,51,254,97,223,240,154,127,150,184,46,247,222,155,215,225,102,218,194,247,7,75,111,189,199,147,220,184,61,178,55,54,11,109,111,62,185,108,221,108,149,149,27,91,41,69,184,171,49,116,57,
60,78,46,166,119,74,74,186,105,156,154,96,130,68,86,82,72,206,203,123,183,104,81,110,152,172,163,4,158,7,172,127,230,15,110,247,72,239,231,151,102,136,77,102,236,72,90,128,201,83,240,154,145,80,43,131,
230,58,181,63,228,143,252,143,59,31,224,158,243,203,124,157,249,57,152,219,191,233,155,37,180,178,59,71,101,117,166,215,171,76,221,22,194,198,231,94,152,230,243,123,139,114,70,171,69,89,184,234,233,105,
197,52,84,244,154,226,167,137,228,102,150,66,234,20,171,121,221,82,242,49,109,108,15,135,80,73,62,116,242,31,46,134,254,223,114,84,251,13,217,222,55,73,23,235,74,21,72,212,215,64,106,85,152,240,213,76,
0,42,50,115,214,198,217,42,38,84,187,42,143,192,183,32,92,30,47,254,23,246,25,41,199,56,244,234,105,130,227,73,25,199,65,62,228,162,180,110,116,241,99,254,216,159,207,248,129,236,170,233,42,27,29,11,246,
171,138,178,208,244,89,119,141,21,153,253,63,234,136,227,254,55,254,62,194,183,81,229,135,82,190,201,62,18,167,61,0,57,154,123,179,253,56,44,45,244,3,142,126,150,250,31,100,51,70,65,56,234,73,177,154,
154,72,232,55,201,82,145,168,88,255,0,65,248,189,254,188,155,159,104,152,87,207,161,109,164,192,133,32,244,28,101,232,197,216,128,117,5,33,184,229,133,205,191,2,228,251,69,44,32,138,142,133,150,87,53,
10,73,199,65,174,82,144,29,100,253,24,27,139,15,233,107,130,126,135,253,191,178,169,83,142,51,208,198,194,232,246,212,244,30,228,105,188,108,194,214,35,234,63,215,184,13,199,251,79,178,247,25,36,116,49,
178,159,10,58,66,229,177,180,149,208,201,73,145,163,163,175,164,146,218,233,107,169,161,172,165,150,195,131,36,21,9,44,68,173,248,184,62,219,71,150,7,19,219,206,233,32,243,82,85,191,104,32,244,115,61,
150,217,188,89,182,223,187,237,150,215,118,4,212,199,60,81,205,25,62,186,36,86,90,252,192,175,207,166,104,233,41,169,169,163,164,162,166,167,163,164,131,252,205,45,37,60,84,180,209,143,202,199,5,58,71,
18,11,255,0,64,61,179,36,178,203,43,75,60,173,36,167,205,137,39,246,154,158,141,54,203,45,191,106,180,75,13,175,111,183,181,176,67,219,20,49,164,81,143,152,68,10,160,250,154,117,139,235,193,231,234,15,
251,14,63,216,31,117,56,233,105,226,104,58,134,220,142,79,248,31,175,224,145,127,232,47,111,118,86,3,203,61,107,7,4,117,208,229,63,214,252,220,243,205,239,245,227,235,237,74,147,174,181,242,232,174,229,
114,105,212,121,22,255,0,212,14,126,128,255,0,137,191,244,250,251,53,136,140,116,65,123,25,227,94,161,61,175,111,205,254,131,250,127,173,249,0,143,102,240,181,52,208,244,14,220,161,169,106,14,160,56,0,
145,98,64,60,126,45,205,133,191,215,246,115,25,170,174,120,244,14,187,136,143,135,174,8,246,250,243,99,200,60,243,254,242,65,183,181,41,67,90,10,116,67,112,133,75,83,169,116,213,239,73,83,29,76,103,67,
66,235,32,210,77,197,141,236,13,255,0,63,239,30,237,36,97,215,79,26,244,130,74,186,20,39,143,78,109,145,171,220,217,170,104,106,25,165,106,202,152,144,146,75,126,194,155,203,199,214,194,37,35,219,23,1,
54,203,11,155,154,208,34,18,62,223,47,231,208,115,123,220,151,96,217,119,45,202,180,240,32,118,31,233,169,69,31,155,17,214,210,63,25,54,42,236,158,186,232,221,132,41,124,25,26,109,191,81,190,183,26,168,
179,71,151,221,207,247,212,241,204,44,10,203,6,53,225,142,199,232,5,189,242,183,220,93,239,247,207,50,115,126,246,95,84,45,48,183,136,255,0,66,28,55,228,95,81,255,0,138,235,6,26,87,123,61,211,113,153,
171,36,242,28,250,249,159,231,213,158,225,224,141,241,130,138,72,214,72,138,21,100,96,10,144,227,73,22,189,189,168,246,242,249,110,246,137,44,220,212,41,225,212,93,184,51,199,116,46,17,180,201,92,30,138,
79,119,124,105,162,221,16,212,77,136,53,116,240,181,85,54,82,9,49,245,70,143,41,135,204,227,167,21,120,204,214,30,181,65,106,76,158,58,165,67,198,223,70,229,88,21,98,61,171,190,250,174,84,191,253,239,
100,161,173,88,50,186,176,212,140,142,8,120,228,95,197,27,130,107,230,184,35,35,161,214,205,205,113,94,89,254,237,221,5,77,48,122,247,80,119,46,102,171,55,15,82,119,7,131,27,217,169,77,85,81,182,55,2,
210,181,6,31,180,240,248,208,162,162,182,129,77,224,162,222,24,216,173,252,71,28,15,171,252,244,64,163,89,99,206,105,229,27,113,96,220,219,202,209,179,114,217,112,179,70,78,167,180,149,191,3,30,45,11,
86,177,201,198,152,108,140,150,238,91,120,178,109,112,73,174,208,249,143,195,95,35,242,174,7,167,14,141,222,222,31,229,122,174,56,83,110,111,245,224,31,247,159,111,123,107,70,221,166,127,232,211,160,230,
231,152,41,90,231,165,126,65,22,120,30,23,80,124,145,176,210,109,234,227,158,79,226,231,253,227,220,191,189,34,205,101,52,13,248,129,232,146,221,140,114,43,169,200,61,83,239,243,17,248,81,73,242,139,97,
233,192,173,38,55,184,54,44,21,213,253,123,152,116,85,77,197,70,168,213,21,27,39,33,61,212,234,169,96,77,27,147,101,149,180,253,27,217,103,178,126,235,75,237,175,50,205,183,110,5,159,151,46,36,9,50,215,
224,169,160,149,71,244,107,221,242,21,242,234,115,228,62,111,155,149,247,40,55,104,193,146,202,64,18,226,49,230,191,198,62,107,199,242,244,39,173,79,158,179,114,108,252,166,83,108,110,26,42,236,22,119,
7,89,54,43,53,134,200,199,37,45,110,58,190,150,67,13,69,52,244,242,132,145,88,56,224,145,102,22,183,190,150,193,61,166,225,107,111,123,183,220,44,214,83,40,120,221,77,85,148,230,160,255,0,132,117,155,
59,78,235,107,121,107,111,127,183,220,44,214,83,40,100,117,224,71,167,201,135,2,60,186,150,153,26,188,164,145,83,66,30,166,162,161,213,33,134,59,179,201,35,27,0,161,121,107,159,199,189,176,17,43,60,132,
44,96,84,147,209,241,189,241,5,24,224,244,96,126,60,245,78,253,239,78,236,219,191,26,254,60,62,43,37,223,27,195,238,19,53,190,178,79,171,101,244,174,220,166,166,106,172,238,122,182,169,4,131,41,185,241,
248,229,118,167,163,139,84,158,98,7,215,233,173,171,103,184,230,107,251,27,105,105,22,221,43,19,26,49,163,206,84,84,181,56,248,106,1,63,62,30,125,68,126,230,123,151,179,242,78,193,127,185,221,57,104,227,
26,104,153,102,115,128,137,195,137,226,220,20,117,189,79,193,207,132,253,77,240,79,164,49,61,65,214,48,77,146,175,158,102,207,118,39,97,102,17,36,221,189,155,190,171,84,54,95,118,110,74,222,100,146,73,
230,44,180,212,250,140,84,148,225,99,79,237,51,100,238,209,180,219,108,246,137,107,110,162,180,26,143,10,159,242,1,192,14,0,117,202,94,121,231,125,227,159,183,235,141,243,118,146,149,196,113,130,116,69,
31,146,32,63,241,163,197,142,79,71,39,217,167,64,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,255,209,223,227,223,186,247,94,
247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,233,239,221,123,
173,119,254,110,118,21,71,201,127,151,235,213,6,71,159,167,62,45,138,28,158,122,142,38,189,30,231,237,140,188,80,207,75,73,86,65,241,79,30,34,7,72,244,125,80,36,223,234,189,243,227,239,125,238,164,251,
106,255,0,86,118,201,128,152,147,10,208,240,118,90,205,47,30,49,198,66,47,163,55,89,67,236,239,43,165,182,216,55,73,147,252,102,236,106,169,31,12,42,112,62,90,142,126,98,157,20,111,230,117,184,243,24,
79,136,216,158,171,193,212,181,54,228,249,63,218,187,51,167,245,70,196,84,255,0,118,242,53,169,146,221,198,21,82,25,130,226,225,26,255,0,178,19,235,239,22,190,235,252,189,14,253,238,165,181,220,200,94,
219,103,180,146,224,98,163,197,99,225,198,79,206,181,34,191,62,166,238,93,141,47,185,174,41,28,86,27,56,222,90,121,106,2,136,63,111,77,155,127,3,67,182,112,88,125,191,140,133,32,199,109,252,93,6,22,130,
36,80,171,29,54,50,146,42,88,212,1,199,171,198,91,253,115,239,168,17,169,68,249,211,161,212,143,173,139,26,214,189,23,175,144,27,161,112,123,98,162,8,228,180,181,172,33,80,24,95,77,236,71,230,230,252,
251,36,220,100,62,25,81,196,244,58,229,11,31,168,188,18,83,2,157,17,236,43,188,142,206,223,238,194,8,250,92,146,111,170,224,114,72,252,123,3,95,154,177,206,122,200,77,178,58,66,180,60,7,67,254,201,142,
243,68,77,238,24,125,127,223,15,161,30,202,144,157,96,215,173,238,88,133,197,60,186,62,29,95,29,252,127,224,169,107,31,173,192,38,224,31,98,109,179,227,207,80,39,55,48,26,253,51,209,229,218,16,234,138,
3,97,253,144,64,250,94,195,232,62,183,227,216,254,200,84,47,88,251,189,201,70,146,135,61,15,184,58,48,81,72,91,177,178,240,62,159,78,120,250,253,61,159,32,173,7,81,253,220,180,98,73,197,122,94,65,66,25,
121,93,70,220,141,55,228,127,182,246,164,0,60,186,38,146,224,234,161,56,234,75,99,198,157,70,38,31,212,233,96,63,60,220,125,79,189,144,15,30,155,23,4,26,142,154,43,49,106,202,69,172,47,125,32,88,113,199,
63,215,219,102,49,196,116,174,43,158,0,158,145,25,92,89,85,127,73,176,22,32,129,192,23,231,253,107,251,101,144,142,60,122,55,130,232,212,103,160,115,115,80,90,39,224,0,7,214,220,147,255,0,26,3,217,93,
210,83,62,93,12,54,169,251,148,131,209,90,222,148,164,59,255,0,181,43,27,91,143,175,227,253,183,176,173,234,10,154,14,165,221,142,124,38,115,209,115,206,68,177,154,135,145,163,137,33,73,37,150,89,93,98,
134,24,144,106,146,89,101,114,177,199,28,106,46,89,136,80,62,167,217,28,168,89,85,5,117,87,0,10,146,126,93,73,182,82,128,154,153,168,160,84,146,104,0,25,36,158,0,15,50,113,208,37,137,222,123,31,123,28,
162,236,189,233,181,55,123,225,230,20,217,116,219,89,252,94,110,76,84,228,144,34,175,76,125,76,237,72,236,200,64,214,0,36,123,77,119,97,121,107,160,220,218,201,24,110,26,148,173,126,202,241,232,223,99,
230,45,143,121,51,174,205,188,218,221,180,38,146,8,101,73,10,19,252,65,73,167,12,30,24,233,183,41,74,91,93,151,144,13,141,254,188,155,95,243,199,178,226,40,58,28,218,77,66,13,113,208,113,148,164,177,113,
164,27,15,161,255,0,27,220,3,244,224,159,101,179,196,64,200,167,66,235,27,131,69,169,244,232,56,202,82,144,91,143,167,164,155,131,245,28,159,160,250,3,245,254,158,202,229,66,42,71,2,58,26,88,92,18,6,115,
229,210,2,190,2,53,13,35,139,220,219,251,32,253,63,175,211,218,38,79,194,122,23,217,205,171,73,252,186,76,74,164,55,233,176,254,131,233,127,240,231,250,123,76,227,143,203,163,184,136,173,79,77,146,41,
86,63,129,245,22,183,32,222,228,255,0,75,123,168,53,29,43,173,70,175,46,161,183,23,191,54,4,159,175,228,31,160,250,143,118,0,147,65,199,175,117,136,125,74,133,60,128,72,255,0,146,133,207,251,223,245,191,
181,74,14,145,94,29,33,186,25,175,152,235,132,128,149,34,252,95,130,111,97,110,109,110,71,54,246,97,9,197,60,135,68,119,43,129,212,25,69,141,254,191,145,115,248,28,218,227,253,111,102,214,231,3,160,181,
250,2,167,29,66,149,120,252,131,244,23,22,28,223,243,253,125,156,192,117,99,229,208,46,238,49,169,177,212,54,4,22,31,236,47,197,175,254,223,252,125,175,67,129,143,62,131,215,11,90,147,214,9,9,177,31,155,
17,207,231,243,248,191,210,254,214,34,128,73,29,18,200,164,103,203,163,105,240,147,168,199,109,119,182,206,196,87,68,239,133,76,186,84,230,36,17,235,72,112,88,117,25,76,236,206,79,8,130,158,21,136,147,
192,50,123,135,189,242,230,239,234,175,36,110,82,192,224,94,24,142,156,208,151,126,200,135,218,73,213,249,117,143,254,248,111,205,107,182,217,242,253,187,82,226,228,248,143,235,161,77,16,31,244,205,154,
124,186,217,146,77,253,180,58,222,135,113,118,230,238,57,1,139,171,203,81,109,221,185,136,194,208,54,75,55,154,200,202,94,28,62,221,219,216,229,104,254,226,174,104,161,39,150,88,226,137,11,49,0,123,231,
46,219,202,247,220,204,209,236,214,215,177,65,5,180,70,75,137,229,61,145,142,44,237,67,154,215,246,158,177,171,114,19,152,236,182,123,56,245,92,145,195,135,230,122,234,135,230,254,58,128,180,185,46,134,
238,106,90,86,39,75,82,197,181,50,53,26,77,202,153,169,105,115,101,227,110,121,81,123,30,61,140,57,79,150,249,127,96,186,150,56,253,196,219,230,136,250,199,52,124,56,208,176,210,127,203,199,162,123,190,
71,230,25,144,31,6,50,223,109,122,122,159,231,110,194,146,152,154,94,158,239,138,202,150,23,90,35,181,177,84,154,136,250,35,87,85,100,197,28,92,254,89,184,247,33,92,90,114,109,220,15,14,229,207,86,43,
110,120,232,171,183,228,14,58,46,143,145,57,164,56,240,237,163,175,169,52,31,203,61,39,250,243,63,157,249,15,216,251,111,121,111,93,141,136,235,125,165,213,25,60,150,225,235,205,154,50,112,231,247,166,
99,120,229,168,127,132,201,187,183,118,98,142,52,199,227,232,241,184,166,104,169,177,244,250,131,74,236,210,51,105,95,113,255,0,59,115,47,43,108,92,156,220,131,237,228,51,73,105,121,41,146,238,234,65,
221,39,14,197,168,7,200,112,1,84,1,66,73,39,165,215,123,6,227,178,68,242,223,220,51,220,204,161,13,48,136,128,215,66,173,78,73,226,196,244,121,113,114,125,189,70,166,181,137,228,219,253,228,159,193,231,
129,238,51,229,6,109,186,248,51,169,26,186,13,221,39,139,29,7,78,153,76,228,81,45,131,168,33,64,98,8,176,22,250,125,69,129,39,220,135,187,238,234,177,153,3,246,143,159,72,236,236,93,232,52,121,244,18,
103,114,216,218,193,44,115,200,154,139,235,137,148,250,227,149,78,165,116,110,8,33,190,158,225,109,194,95,22,254,75,136,91,26,186,24,89,91,92,65,164,170,26,121,250,117,85,127,62,190,6,237,127,147,216,
106,237,253,178,113,244,155,127,228,6,14,132,212,69,144,165,68,167,135,179,49,52,144,146,216,156,148,42,99,134,124,252,49,173,233,230,62,185,72,208,77,237,239,36,189,142,247,195,112,228,155,152,182,61,
230,225,166,229,105,90,154,88,215,192,114,112,234,79,5,63,136,10,129,199,169,43,147,57,219,116,228,169,191,74,179,236,18,55,234,64,79,192,223,198,135,240,159,229,235,142,181,192,219,29,81,218,91,135,118,
215,245,230,217,195,228,182,74,225,38,56,253,255,0,218,25,234,25,97,92,115,53,196,216,125,157,4,209,175,151,42,98,5,73,255,0,57,27,31,86,155,115,156,155,255,0,57,242,230,209,182,69,189,94,221,45,211,76,
186,173,173,99,96,89,253,30,82,13,2,86,135,52,4,112,175,89,21,23,51,197,190,219,36,219,28,231,232,221,123,156,252,107,90,85,105,228,120,138,249,241,29,108,99,252,189,122,103,175,190,57,239,79,134,245,
59,63,27,21,10,230,251,83,177,182,222,224,205,84,232,147,49,184,50,251,167,175,234,146,142,171,57,146,176,154,182,166,121,224,62,37,99,165,27,133,31,95,113,191,176,190,225,238,252,211,247,128,187,147,
124,187,173,108,244,67,24,196,113,138,48,211,26,212,128,51,199,137,243,235,20,62,240,5,174,182,221,222,218,48,222,12,80,163,1,199,225,112,89,190,223,94,182,153,247,210,190,176,111,175,123,247,94,235,222,
253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,255,210,223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,
186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,5,93,227,217,184,190,153,234,14,200,237,60,204,130,58,13,139,180,51,91,133,
239,167,247,39,162,163,145,168,160,80,196,6,106,138,211,26,1,249,45,236,171,124,220,226,217,182,125,203,116,152,254,156,16,179,254,96,96,126,102,131,163,45,159,111,147,118,221,44,54,216,135,124,210,170,
254,211,159,216,51,214,187,223,31,246,214,85,182,230,219,201,103,188,213,123,243,182,51,21,221,175,191,106,231,13,247,51,230,247,141,100,149,244,148,179,57,245,148,198,99,100,85,69,60,40,123,123,225,47,
187,188,217,115,205,28,239,204,59,157,204,197,160,130,70,137,42,113,95,138,70,251,75,146,62,197,28,58,206,221,162,222,29,179,101,154,68,1,97,84,8,159,233,80,80,126,222,139,39,206,12,172,59,239,249,131,
124,127,234,8,101,251,140,15,199,14,151,207,118,190,118,137,72,104,98,222,251,238,168,224,240,141,52,124,175,221,83,98,226,70,82,126,129,184,247,149,223,115,30,95,54,252,157,204,156,217,60,116,159,113,
191,240,144,255,0,194,173,199,151,200,200,204,127,46,143,125,190,140,182,217,188,238,236,59,238,39,17,169,254,130,10,159,230,127,151,203,165,204,173,162,153,190,160,133,46,77,255,0,192,255,0,135,231,250,
251,205,119,33,80,215,161,90,130,206,0,30,125,86,175,201,61,212,114,59,154,28,68,83,94,26,48,53,170,158,60,151,212,127,195,254,39,216,79,113,146,174,84,112,29,77,156,155,99,224,217,172,132,101,169,208,
85,183,216,221,64,252,148,28,15,161,181,205,191,215,177,246,16,190,166,162,126,93,75,219,116,96,167,167,70,51,100,139,203,16,230,215,31,224,121,31,215,143,101,208,138,176,251,122,103,118,237,142,74,122,
116,124,186,176,2,34,254,164,70,109,107,218,223,239,31,65,236,81,182,124,68,83,211,172,126,231,30,13,249,244,124,118,92,55,134,34,62,164,45,191,60,241,115,238,65,176,21,11,214,58,239,207,70,126,60,58,
49,184,26,67,160,88,2,65,10,13,142,155,144,9,255,0,122,246,32,141,113,171,168,222,246,90,86,157,8,148,116,161,20,127,82,47,199,38,231,250,253,13,236,125,168,208,198,157,18,75,48,173,43,158,156,126,204,
144,91,64,231,235,205,191,199,158,15,36,127,176,231,219,170,163,128,21,167,73,132,231,168,21,84,1,212,217,121,250,144,125,38,227,233,110,63,199,221,12,101,72,4,244,236,119,25,201,161,233,27,147,198,221,
100,186,243,161,175,245,228,1,248,184,228,221,125,181,34,3,246,122,244,109,111,114,65,30,189,1,187,170,131,74,56,10,109,99,107,130,56,185,177,63,226,0,246,87,116,157,173,142,134,187,69,207,122,231,162,
149,190,105,52,201,33,43,126,28,92,222,254,163,197,185,22,246,18,190,90,49,62,93,76,155,4,213,84,36,245,168,79,243,229,249,199,186,118,190,227,160,248,123,213,219,134,179,5,12,184,74,109,193,221,121,60,
69,84,180,181,249,40,243,40,37,193,108,102,171,132,137,97,198,253,136,21,85,209,171,41,149,164,72,218,233,169,72,223,144,246,8,100,141,183,203,184,131,57,106,68,15,0,6,11,211,212,156,3,232,49,214,63,125,
228,253,205,191,130,120,189,187,217,110,218,43,97,26,189,233,83,67,33,112,10,66,72,63,2,173,25,151,21,98,1,168,20,232,5,254,64,29,117,157,172,236,126,247,237,113,89,87,6,217,219,251,51,19,178,39,161,86,
145,104,178,153,205,201,146,254,41,78,245,2,226,41,37,196,209,97,221,146,227,82,253,199,22,191,54,247,66,230,49,183,109,214,90,71,143,36,165,129,243,1,6,105,246,234,29,123,238,113,179,93,191,53,243,71,
49,137,25,118,251,107,17,11,1,240,187,206,224,168,62,186,68,108,71,165,126,125,108,191,145,135,135,252,242,198,224,255,0,172,8,227,159,112,99,12,145,229,215,72,45,165,165,3,112,233,1,149,165,13,174,223,
145,127,233,244,31,139,125,13,135,180,210,169,210,195,203,161,61,140,196,105,206,7,65,166,86,149,78,171,175,208,105,63,224,167,139,159,246,255,0,95,100,211,46,8,252,250,26,109,243,156,100,244,26,228,32,
210,204,109,107,18,191,64,126,132,219,146,7,212,31,246,222,203,228,20,33,188,186,27,216,203,80,23,164,85,100,122,95,142,10,22,231,243,197,190,191,212,31,105,91,137,175,159,66,107,119,12,185,233,158,110,
70,171,31,173,191,167,212,223,129,207,251,111,109,12,18,43,210,245,56,81,79,46,160,105,105,15,164,30,6,163,102,85,3,158,46,79,166,196,218,222,238,152,96,122,219,58,34,151,145,213,80,113,44,66,129,92,10,
146,64,201,192,206,79,88,10,178,203,166,64,85,129,229,72,177,7,77,173,99,115,244,255,0,95,218,165,35,70,170,212,19,210,123,144,195,93,69,48,63,159,94,35,210,223,155,233,191,60,253,7,211,253,143,181,177,
28,254,92,58,36,184,202,158,162,204,182,185,254,150,181,184,176,252,216,127,91,123,51,132,208,175,159,65,171,181,174,170,250,158,161,202,162,220,128,64,227,129,245,252,3,254,31,79,103,22,236,106,13,120,
244,13,189,90,234,234,4,139,197,185,181,249,31,83,249,42,127,215,246,98,166,135,142,58,15,78,156,71,14,162,200,135,79,167,146,8,31,67,234,114,64,85,34,223,146,64,246,182,39,20,53,194,244,77,36,64,183,
167,175,160,30,103,242,235,96,207,229,223,210,143,215,221,23,151,237,26,202,18,187,159,178,167,77,155,179,94,72,202,212,38,222,138,117,147,61,148,132,55,173,70,91,33,251,97,135,234,138,47,200,62,249,229,
247,132,231,95,235,23,59,193,203,208,205,254,235,172,43,52,212,34,154,232,68,72,125,116,46,105,234,122,192,206,112,223,191,172,220,243,185,238,37,255,0,196,161,99,164,121,4,78,212,31,202,191,159,175,86,
149,186,190,61,75,218,221,115,132,217,184,76,135,240,61,231,180,243,24,221,235,177,247,4,144,154,154,12,110,241,198,65,81,20,63,198,233,5,190,243,1,149,167,168,146,150,173,46,25,35,151,90,250,148,123,
138,253,174,188,220,55,78,105,220,54,85,218,222,235,98,221,35,240,46,85,112,241,198,126,25,81,188,140,103,52,224,195,236,29,70,27,158,252,118,187,213,221,217,240,164,130,61,87,208,124,252,197,56,158,139,
71,74,102,240,221,177,190,178,123,123,53,136,139,111,230,42,118,85,69,69,70,54,138,169,107,40,105,183,110,196,221,53,219,83,120,38,30,189,78,140,142,42,73,74,79,12,163,245,68,203,127,80,62,216,231,222,
83,187,228,187,25,237,190,161,110,26,199,115,104,76,148,166,168,166,137,101,128,176,224,27,5,72,245,173,6,122,22,77,190,221,218,195,109,123,20,164,219,204,1,207,161,21,24,245,232,112,202,252,127,157,222,
212,53,132,139,146,53,142,126,160,143,168,226,215,247,30,218,238,236,91,186,49,95,151,75,173,249,213,21,7,140,135,62,157,11,61,77,213,50,236,247,150,182,174,98,243,72,186,108,0,181,185,32,113,245,35,216,
178,11,117,188,69,146,68,160,20,63,234,249,116,22,230,94,101,77,197,86,24,190,30,133,236,205,108,116,81,51,106,0,128,73,228,94,214,107,91,129,237,22,226,235,108,43,30,24,112,245,232,49,101,108,210,176,
28,107,208,1,187,55,231,131,92,72,247,54,35,134,23,63,235,18,120,227,217,87,213,94,93,71,162,67,219,208,239,106,216,215,12,87,29,7,56,108,213,78,74,187,203,35,49,140,53,194,223,232,120,35,235,254,183,
180,179,197,72,197,41,94,143,174,173,82,222,53,85,233,111,184,37,155,33,142,70,167,127,181,172,163,34,122,73,209,180,58,201,29,138,144,224,234,23,62,208,91,48,73,64,39,229,209,85,144,16,92,48,113,88,223,
136,249,30,170,135,228,182,206,201,109,205,231,38,241,142,53,59,51,182,106,226,105,42,81,22,58,109,189,219,88,232,60,25,26,106,221,43,227,165,77,223,142,141,38,142,67,101,154,101,96,110,223,92,156,228,
109,218,45,243,150,33,182,44,91,123,218,65,12,56,180,150,142,106,165,127,139,193,106,130,56,129,242,232,127,201,155,156,91,54,254,251,124,206,18,202,224,13,62,128,159,135,236,244,63,151,67,55,80,87,73,
151,217,127,22,241,184,228,153,119,53,103,204,189,157,138,198,196,26,245,14,54,136,174,168,221,21,180,111,25,213,246,116,184,233,63,117,135,233,189,143,185,19,217,45,170,250,47,127,118,121,109,129,49,
181,180,114,146,43,133,145,129,21,244,52,12,126,99,160,47,187,123,133,173,195,243,61,8,240,98,179,145,79,165,77,0,161,243,169,235,104,95,125,122,235,4,250,247,191,117,238,189,239,221,123,175,123,247,94,
235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,255,211,223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,
189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,83,143,243,58,236,223,244,129,155,235,111,134,59,94,171,247,247,181,125,15,99,119,102,66,2,88,109,126,
170,218,213,105,89,29,37,115,35,21,134,109,207,95,16,141,99,144,2,232,20,142,27,222,42,253,233,189,206,182,228,174,75,186,219,226,144,125,124,201,90,87,37,142,33,65,243,103,238,35,201,86,166,131,169,163,
218,62,93,150,226,238,125,254,68,58,82,177,66,63,138,70,20,102,31,233,7,152,243,233,167,165,54,67,229,51,211,238,201,233,62,218,129,100,142,139,7,76,87,74,199,73,26,165,45,32,85,34,202,34,165,141,71,28,
95,233,239,140,119,158,61,236,111,0,122,203,70,121,27,143,113,37,137,252,201,63,149,58,200,14,107,221,34,177,219,224,218,96,112,89,83,186,159,207,170,21,218,27,165,251,91,231,55,207,62,227,146,65,53,36,
125,153,133,234,45,191,46,162,241,69,137,216,216,234,122,57,163,166,110,109,9,172,163,98,192,113,168,159,125,121,246,63,151,215,150,61,169,228,93,171,77,28,89,44,141,138,18,243,49,144,147,254,245,251,
41,212,171,203,118,102,195,148,54,56,10,209,154,19,33,245,38,70,39,63,149,58,51,27,131,39,22,55,15,93,88,236,2,195,77,52,164,146,22,222,52,118,250,147,111,160,255,0,121,247,46,220,200,162,51,158,141,172,
96,105,238,96,80,62,35,213,57,111,28,211,231,119,110,78,190,71,47,229,169,144,173,219,87,167,200,116,139,255,0,193,109,236,31,51,151,14,255,0,60,117,145,219,85,176,182,181,130,32,56,40,255,0,7,74,157,
182,117,20,36,125,91,241,248,255,0,98,8,246,23,189,61,204,43,208,226,197,116,128,7,167,70,71,101,17,228,132,127,138,150,224,115,199,0,15,240,191,180,81,26,56,233,22,234,107,19,211,137,232,249,245,87,251,
171,252,74,125,126,128,126,127,214,39,216,155,108,248,143,229,214,62,115,143,226,31,111,71,255,0,98,160,104,169,197,173,125,38,214,250,131,253,109,197,253,200,155,125,40,189,99,103,48,177,15,32,232,207,
96,41,88,36,103,73,8,192,144,204,164,106,2,228,149,36,115,166,222,196,49,149,11,221,195,168,202,241,206,163,81,142,132,74,72,53,5,226,252,127,208,188,22,22,231,145,237,88,3,72,39,143,68,50,49,171,26,244,
238,33,83,198,155,15,200,244,219,254,53,244,246,250,168,80,61,122,79,226,31,78,162,84,210,33,83,192,230,214,54,63,95,167,4,113,248,247,110,172,37,28,72,233,43,147,163,5,89,172,79,246,79,250,223,142,79,
227,159,105,228,69,38,131,165,246,243,18,84,116,6,110,234,63,219,127,241,213,107,115,244,23,227,159,101,87,75,134,29,13,54,137,142,164,168,243,232,158,111,186,101,243,182,175,211,116,189,255,0,165,249,
39,241,244,30,194,27,130,30,234,83,169,183,151,38,52,140,147,215,205,151,249,178,201,157,147,249,135,252,166,254,240,44,169,84,189,138,235,70,147,106,186,225,255,0,132,99,91,14,99,212,77,161,124,123,35,
45,184,177,247,50,114,192,140,108,27,87,135,240,248,35,246,249,255,0,62,176,71,221,230,185,127,114,249,201,174,129,241,62,181,233,95,225,160,211,79,150,154,17,210,11,224,127,202,206,204,248,185,223,27,
43,47,179,179,57,6,218,155,167,116,96,54,255,0,96,108,147,60,143,131,221,152,12,158,66,159,29,82,181,88,251,180,63,197,40,98,169,50,210,84,42,137,163,149,64,13,164,178,155,115,6,203,103,189,237,211,219,
220,160,241,2,146,141,76,163,82,160,131,246,129,81,230,58,223,181,190,224,111,190,222,243,94,217,185,237,55,78,45,36,153,18,226,26,157,19,68,88,6,86,94,5,128,36,163,113,86,0,131,199,173,237,107,163,87,
5,212,17,28,168,146,69,172,89,130,74,139,34,171,17,253,181,87,23,31,215,222,46,184,62,116,235,178,54,238,14,150,80,116,16,8,175,26,16,8,175,204,87,164,46,78,14,30,195,155,127,177,183,210,252,15,232,61,
167,113,94,132,118,82,80,143,50,122,14,50,208,18,94,202,63,199,129,107,16,62,191,215,233,236,166,117,238,52,28,49,208,203,111,150,133,115,208,97,151,130,218,136,31,80,196,143,199,7,147,193,36,127,143,
178,153,86,139,67,208,231,110,155,225,53,207,72,10,248,237,205,189,60,15,165,255,0,35,242,120,228,15,105,89,73,2,158,93,11,109,159,203,164,204,194,200,86,199,252,56,177,22,185,34,226,194,254,218,165,122,
54,141,193,33,105,158,171,171,249,150,81,111,169,62,57,197,153,217,89,76,182,62,151,109,111,76,78,79,119,12,61,93,85,29,84,248,41,169,234,168,105,231,153,232,158,57,26,146,135,45,81,3,184,39,64,225,143,
233,30,229,175,103,100,176,78,104,158,222,246,36,105,229,182,97,17,96,8,12,24,22,2,188,9,90,253,180,167,88,29,253,226,27,111,52,220,123,57,203,219,166,197,115,58,236,246,59,192,107,213,141,153,106,146,
70,82,7,144,41,4,162,203,140,213,85,152,54,13,15,68,151,225,239,243,17,220,27,75,35,135,235,78,249,202,84,110,29,147,81,36,88,236,86,253,175,103,169,220,59,78,89,165,9,0,205,213,187,60,217,157,188,172,
116,187,201,122,138,101,245,6,100,26,68,135,207,62,215,217,238,49,220,238,220,187,10,195,186,1,169,162,20,17,203,78,52,92,5,144,249,17,131,230,60,250,196,111,187,55,223,79,152,121,10,243,109,228,143,117,
47,165,220,121,1,219,66,92,185,50,93,109,250,141,3,9,13,90,107,101,63,28,76,75,34,212,198,113,164,222,178,201,20,240,197,81,79,60,21,52,181,80,199,81,73,85,77,50,205,77,83,77,58,172,176,84,83,207,27,50,
77,12,232,193,149,148,144,192,223,222,60,196,174,143,42,74,133,101,6,140,14,8,35,4,16,114,58,236,64,158,218,242,210,218,250,198,230,57,236,103,140,73,28,145,176,104,228,141,133,85,209,135,107,43,12,130,
9,235,28,128,141,67,240,57,3,159,235,205,199,244,227,217,140,53,242,227,209,21,221,123,189,122,143,40,184,254,158,165,28,127,169,181,200,250,123,51,134,184,251,58,7,94,174,79,231,211,124,139,118,111,168,
31,81,97,114,10,142,62,160,243,236,205,8,33,77,115,209,28,195,226,245,233,255,0,103,96,39,220,251,171,1,129,166,66,210,100,242,212,84,252,31,161,154,120,226,66,127,28,205,34,143,246,62,208,111,187,130,
237,91,54,229,125,33,160,142,22,255,0,142,154,255,0,42,245,30,123,135,187,175,47,114,118,255,0,186,86,147,8,12,113,250,235,147,180,83,230,1,39,242,235,113,77,153,182,177,248,201,118,70,200,196,193,163,
3,214,219,103,21,135,165,133,20,0,213,180,212,80,211,240,138,44,101,121,245,49,252,146,73,247,200,157,198,250,226,250,77,223,118,152,150,190,220,110,93,241,146,117,49,165,63,42,117,207,143,247,22,194,
87,102,253,89,73,36,159,78,39,160,67,229,7,124,238,93,199,184,170,126,40,116,142,102,92,60,254,40,166,249,13,217,120,105,180,87,237,204,85,88,30,62,184,219,117,208,233,240,103,114,144,29,53,147,70,218,
225,86,208,44,117,31,121,59,203,18,217,123,45,237,231,239,11,168,149,185,175,113,21,11,248,137,167,106,87,136,68,29,206,71,158,7,69,28,189,203,167,152,183,17,187,110,9,254,235,162,254,201,72,237,52,255,
0,68,97,231,83,132,31,159,76,187,167,109,81,252,127,168,248,173,218,152,170,104,176,251,83,105,111,23,234,221,226,163,90,193,71,179,59,38,142,60,109,37,94,66,96,11,200,180,153,234,120,165,121,28,146,211,
72,73,250,223,220,43,203,23,87,92,239,111,238,79,47,223,202,103,221,47,173,197,228,68,241,107,139,102,44,66,215,133,99,36,0,50,0,232,231,120,184,142,242,226,246,202,33,218,177,213,7,205,15,15,229,213,
158,211,99,156,201,98,61,42,77,154,247,82,191,134,255,0,106,86,4,17,193,227,216,95,96,229,89,165,209,113,58,118,210,188,58,1,205,118,52,227,137,255,0,15,93,228,242,52,244,16,183,173,23,66,144,196,218,
196,5,55,191,208,126,61,136,183,9,225,179,86,134,50,49,142,189,105,111,36,237,93,39,39,162,201,191,187,2,24,150,72,161,156,49,55,6,204,9,63,94,120,228,15,233,236,29,50,189,212,186,178,84,30,164,125,147,
101,106,169,145,41,209,105,175,202,84,228,106,26,73,89,244,72,69,153,143,212,243,197,199,183,210,53,74,129,229,208,250,43,100,134,48,20,119,116,180,198,230,232,176,244,106,228,43,75,161,120,252,220,220,
220,143,233,112,125,160,146,23,145,141,79,111,69,119,22,178,92,72,71,151,82,232,231,222,123,198,118,167,192,227,170,101,132,2,175,50,70,201,77,18,30,67,75,80,250,81,64,227,243,127,118,142,222,40,202,235,
21,108,253,191,231,234,147,71,182,237,145,137,47,39,85,62,149,201,251,7,65,231,98,110,30,143,219,120,108,247,88,118,126,226,165,237,28,214,238,137,105,37,233,94,187,163,155,120,239,92,166,88,29,88,229,
161,131,13,231,147,5,149,167,171,177,142,166,87,135,192,125,71,139,222,80,228,14,80,247,3,117,222,246,235,222,80,219,46,35,184,86,162,202,65,11,67,134,26,72,172,138,195,5,64,33,134,43,208,111,118,221,
225,187,136,75,28,2,40,99,21,18,200,116,170,129,199,141,42,60,233,231,138,116,106,190,11,124,48,221,187,107,114,237,46,236,237,189,171,75,214,84,27,11,111,101,176,29,13,208,80,228,14,114,175,175,49,251,
141,252,185,221,233,190,243,174,239,252,91,178,55,36,114,50,212,105,184,166,87,41,112,64,81,213,143,99,125,150,187,228,201,238,185,187,154,174,60,126,106,187,21,114,84,41,94,221,32,105,21,17,170,41,42,
145,143,132,18,88,150,61,99,215,184,28,245,109,185,193,38,201,180,74,100,183,102,6,89,184,9,10,240,68,31,239,176,115,83,198,131,203,171,120,247,147,93,68,29,123,223,186,247,94,247,238,189,215,189,251,
175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,127,255,212,223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,
189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,116,92,254,88,119,238,63,227,55,67,239,158,221,172,163,92,165,118,14,138,26,29,179,134,102,40,185,157,217,153,157,
49,187,123,29,35,143,209,4,185,9,213,165,60,90,36,107,16,109,236,53,205,252,197,7,42,242,246,229,189,206,186,188,36,237,31,196,231,10,62,202,228,252,129,232,251,150,118,73,57,135,122,178,218,209,180,163,
181,92,255,0,10,46,88,254,204,15,157,58,170,78,141,232,141,223,36,89,173,233,219,25,89,183,7,104,118,133,116,27,183,181,119,77,72,189,77,117,117,66,45,70,55,103,98,100,228,211,109,45,175,76,235,12,16,
166,152,217,212,181,173,107,112,183,221,31,113,55,223,118,185,190,243,114,241,100,123,40,229,117,138,164,233,25,33,165,96,120,49,161,85,2,154,80,1,199,172,176,183,186,219,185,118,202,27,125,182,32,26,
53,209,24,28,16,121,183,250,118,226,79,30,142,22,126,190,143,98,108,141,205,153,166,88,233,41,54,174,212,207,102,129,244,162,68,184,108,61,93,96,115,110,1,6,11,220,254,125,129,218,56,34,159,106,229,235,
86,215,123,119,115,20,110,124,206,183,85,57,252,248,116,24,172,215,247,74,211,18,94,73,0,207,28,176,31,229,235,81,223,130,185,166,159,171,119,14,234,174,125,117,189,143,218,93,131,188,235,167,98,68,149,
15,145,220,117,254,41,89,207,168,144,15,7,159,125,167,178,134,59,11,107,59,4,160,142,24,35,64,61,2,34,168,31,203,172,204,77,191,77,133,172,65,59,82,36,95,179,74,1,209,133,238,221,239,252,47,102,100,33,
130,161,154,106,184,158,21,187,46,176,178,41,6,220,95,147,239,119,115,15,12,168,226,122,52,229,189,169,77,244,76,195,180,26,245,89,212,242,22,170,242,51,93,157,181,158,47,114,196,145,110,7,0,251,34,152,
246,144,120,117,54,192,43,161,124,133,58,21,54,205,255,0,111,252,91,159,245,238,62,159,237,87,246,27,187,201,114,79,66,107,51,218,7,70,71,101,185,18,71,197,185,78,71,224,95,212,111,254,39,218,40,135,122,
244,131,116,95,211,106,241,232,248,117,99,250,163,3,234,68,124,126,120,7,145,249,252,251,18,109,132,134,205,56,245,0,115,138,225,207,219,208,125,252,196,63,154,111,82,255,0,45,30,153,166,206,101,162,163,
223,61,245,189,177,149,105,211,189,67,29,88,71,200,84,68,166,3,188,183,145,133,188,248,173,143,136,169,97,173,172,37,173,148,120,97,185,44,203,45,114,230,215,46,224,218,169,166,217,79,115,127,144,124,
255,0,193,214,29,123,157,205,182,124,179,17,86,163,238,114,131,225,199,242,254,54,244,81,229,252,71,135,159,85,133,255,0,9,193,254,100,191,57,62,104,252,233,249,9,130,249,7,218,123,143,178,250,231,47,
211,249,157,253,83,134,172,138,8,118,143,92,110,92,126,229,197,83,109,170,93,159,140,166,129,32,219,244,53,148,181,245,20,201,2,179,121,33,131,213,173,129,98,52,220,236,173,109,173,163,48,196,170,224,
211,230,69,60,250,129,121,91,126,221,247,77,214,236,94,92,180,145,50,106,35,201,78,161,133,30,67,39,31,46,183,117,161,79,74,169,254,135,159,205,239,199,211,233,207,251,215,178,177,192,116,54,152,154,14,
158,81,120,254,159,65,244,7,232,47,207,31,78,125,176,78,162,122,72,77,115,215,9,22,234,13,133,143,251,111,175,0,3,244,62,238,166,134,135,173,129,156,244,155,200,69,232,144,127,169,185,226,214,231,221,
158,148,207,75,160,146,180,3,136,232,17,221,208,131,12,132,1,192,63,64,47,127,160,228,126,61,149,220,40,206,58,23,237,18,176,113,159,78,137,135,98,66,190,89,200,31,80,215,255,0,97,127,167,251,111,97,27,
241,77,94,149,234,111,229,182,212,17,73,235,90,79,230,163,252,166,177,223,50,119,85,55,115,245,70,227,195,236,78,236,131,29,79,135,220,212,185,228,157,118,190,255,0,199,99,151,197,139,169,172,171,165,
73,103,196,238,44,108,4,66,39,241,188,83,192,21,92,2,138,65,151,45,115,127,238,72,218,198,246,54,123,10,213,74,241,74,241,20,243,95,179,32,253,189,6,189,212,246,41,189,195,184,139,152,185,118,234,43,126,
99,208,22,84,147,182,43,128,162,138,218,133,124,57,20,96,146,10,176,165,104,64,232,141,252,50,254,71,153,254,179,236,221,187,218,95,38,247,142,214,204,210,236,156,205,30,127,111,117,214,200,158,171,39,
6,99,57,139,157,42,177,149,123,151,57,85,79,69,28,88,186,42,200,210,95,182,129,29,170,10,0,238,171,117,101,219,255,0,184,144,205,105,53,166,205,19,137,29,104,100,113,167,72,56,58,71,29,84,224,120,14,136,
189,176,251,172,110,59,118,249,99,190,243,245,237,185,180,181,145,100,75,104,88,200,101,117,32,175,136,244,10,177,130,1,42,181,103,165,13,5,107,176,133,104,46,206,205,111,83,106,227,128,44,57,227,240,
23,240,63,30,225,246,21,90,14,179,194,41,15,19,199,164,125,124,119,6,227,142,71,31,83,123,129,253,121,183,180,204,58,60,181,144,141,38,180,232,59,203,66,44,247,39,234,192,95,241,107,16,0,254,163,217,117,
194,241,168,207,66,251,9,14,58,11,179,49,253,79,28,30,71,35,139,92,255,0,141,137,255,0,99,236,162,81,66,105,145,208,227,110,146,160,14,131,108,132,103,213,199,8,111,97,199,250,255,0,95,241,183,180,45,
81,174,189,12,173,27,244,210,167,164,157,66,11,147,244,31,155,219,143,235,115,253,45,238,186,104,64,175,207,163,176,245,81,65,145,213,106,255,0,49,15,144,88,173,133,214,245,189,25,130,134,60,239,100,118,
245,2,97,206,38,158,213,50,96,182,213,117,84,81,181,109,84,9,170,79,226,121,153,148,65,69,17,23,107,180,159,69,23,150,253,170,229,107,141,203,117,143,153,110,9,143,107,178,98,84,240,241,36,0,240,63,192,
130,165,143,174,61,122,192,79,191,143,190,187,87,45,242,101,207,178,187,50,45,223,56,111,177,198,46,84,119,125,37,175,136,142,138,84,103,234,46,25,87,195,83,149,64,90,149,101,232,147,87,127,42,62,216,
27,11,11,158,196,239,93,177,87,191,106,40,32,173,205,236,44,148,83,227,98,199,207,80,162,95,225,180,155,136,201,83,75,85,91,71,19,5,148,60,81,198,101,184,13,97,127,114,12,126,242,236,7,116,185,179,158,
206,116,177,87,42,179,10,48,106,113,109,35,184,45,120,28,227,211,172,75,155,251,189,253,224,110,74,217,185,143,109,220,246,233,249,146,226,5,150,93,177,153,161,154,16,227,82,160,149,255,0,69,229,10,70,
180,170,233,99,164,18,65,234,205,190,24,117,127,108,116,247,74,210,236,126,222,200,211,85,229,241,249,220,140,216,12,108,25,33,152,254,239,109,201,163,139,193,138,108,138,51,68,241,154,181,146,88,226,
70,43,2,62,145,111,160,139,185,243,119,217,55,221,252,238,27,36,127,164,98,2,70,211,167,92,149,61,212,52,53,11,130,124,250,207,47,186,95,183,94,230,251,97,237,101,223,44,251,157,47,135,113,245,237,37,
157,177,145,101,107,88,10,0,232,89,75,42,137,37,26,150,53,99,166,132,208,106,167,70,161,201,177,250,126,127,198,246,55,231,250,218,222,194,145,121,211,143,89,13,119,141,70,157,98,97,117,111,241,181,200,
252,91,158,63,195,217,165,189,64,74,252,250,8,222,113,39,207,63,225,234,51,11,92,155,112,63,216,255,0,128,6,223,75,127,143,179,56,205,80,116,67,63,16,0,232,197,124,74,196,199,149,239,125,130,147,199,230,
137,55,86,221,214,141,123,50,166,65,43,88,127,201,52,220,251,141,253,223,188,107,78,69,221,202,181,24,193,45,63,222,52,255,0,133,186,199,207,188,21,203,47,44,109,27,104,106,125,69,238,71,170,162,19,254,
19,214,204,187,243,182,79,74,244,151,98,246,244,113,172,251,143,154,29,159,77,38,151,53,155,211,112,212,127,14,219,144,136,136,62,111,180,121,26,160,173,136,34,27,123,192,47,110,249,110,45,255,0,156,246,
216,46,7,251,174,178,65,36,149,225,68,206,79,144,235,13,55,152,13,205,197,190,219,29,116,177,161,255,0,72,62,47,204,240,252,250,46,191,24,186,186,167,111,227,168,163,204,84,75,147,221,89,250,233,119,102,
250,203,212,55,150,167,37,185,242,237,247,85,173,60,172,90,71,74,119,151,198,128,155,0,61,162,247,43,155,27,153,119,203,187,228,198,223,16,49,91,175,144,141,77,53,125,174,114,79,165,7,67,153,213,54,125,
164,64,128,43,149,205,60,177,195,242,29,88,47,107,245,29,23,116,116,222,248,234,138,153,190,205,247,70,220,122,92,85,104,211,175,29,184,41,2,214,96,171,148,145,232,52,249,58,120,253,67,149,6,255,0,143,
97,239,110,55,9,54,126,107,218,55,116,201,138,65,168,127,18,182,28,125,132,18,15,81,36,247,173,107,120,183,131,58,94,167,230,14,27,249,30,144,63,13,187,250,183,177,250,94,175,111,111,164,108,127,112,116,
174,68,245,175,102,99,42,1,74,153,43,176,161,169,49,121,214,73,7,144,199,151,164,167,179,159,248,236,132,95,159,121,3,207,86,54,60,187,107,61,237,157,5,149,200,50,71,229,64,213,98,191,145,199,203,162,
235,253,168,174,232,190,6,108,167,30,36,103,237,226,63,46,164,118,47,101,148,243,211,211,201,234,37,133,149,190,159,80,53,90,220,95,222,55,120,210,222,187,75,33,162,147,254,30,164,173,139,151,199,233,
201,34,244,92,94,176,228,18,183,45,148,171,138,139,21,141,138,90,220,141,117,84,190,58,122,90,120,1,121,102,149,219,128,138,163,253,115,244,23,60,123,82,35,119,146,27,107,88,217,238,36,96,168,170,42,204,
199,130,128,56,159,248,190,134,178,8,172,35,81,78,238,177,45,94,53,118,239,247,239,115,229,113,123,3,100,42,52,148,217,189,227,93,30,26,9,104,254,177,84,44,19,233,168,158,162,173,0,100,134,37,121,52,176,
4,2,125,173,139,104,190,184,191,125,163,110,133,175,55,21,58,88,68,11,5,111,53,212,49,69,200,44,72,4,240,233,12,219,173,189,170,105,146,173,57,206,145,147,254,199,78,189,111,55,96,247,18,137,126,52,244,
94,225,236,122,114,238,145,118,191,112,199,81,214,221,65,76,21,136,53,88,138,106,168,219,113,238,196,22,37,60,48,170,27,114,121,247,146,94,222,253,211,61,192,231,2,151,91,152,91,61,180,138,212,28,159,
145,102,1,126,221,1,189,58,142,185,147,220,61,183,105,13,13,230,228,176,191,15,14,42,73,49,249,49,24,79,204,215,163,155,180,255,0,151,182,242,222,223,111,146,249,71,223,91,159,117,199,117,113,213,189,
56,103,234,190,176,162,140,233,47,69,87,46,42,68,220,219,134,34,190,134,105,103,134,246,184,250,219,222,112,114,23,221,31,219,190,85,142,57,119,91,97,123,122,40,73,57,4,143,233,53,91,246,105,234,18,222,
61,214,186,149,221,118,75,21,140,127,191,101,62,44,135,231,67,218,63,159,207,163,209,213,223,30,250,79,165,105,18,147,171,122,199,103,236,178,177,164,114,87,98,48,180,137,151,170,208,140,134,74,236,212,
241,205,150,173,158,64,199,92,146,204,206,228,146,196,251,201,125,171,151,118,61,146,36,135,104,218,160,183,69,20,26,16,3,143,157,43,252,250,141,183,29,243,120,221,220,190,229,185,77,49,244,102,52,255,
0,121,224,63,33,208,199,254,251,253,127,103,61,21,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,
221,127,255,213,223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,
116,95,126,80,252,124,219,159,40,122,83,120,116,222,230,200,84,225,233,183,28,20,211,227,115,180,81,172,213,120,44,238,46,166,58,236,62,86,40,29,145,42,22,150,174,17,228,140,178,249,35,44,183,4,220,7,
185,171,151,109,185,171,99,189,217,46,164,40,146,129,70,25,42,202,106,173,67,198,135,136,243,21,29,30,114,230,251,113,203,155,189,174,237,110,129,218,58,130,167,131,41,20,101,175,149,71,3,228,122,165,
77,233,214,223,204,159,225,135,93,238,61,199,91,191,186,155,182,122,119,173,112,231,35,54,95,113,153,14,122,12,5,35,69,79,21,42,71,85,75,6,89,234,16,58,34,196,106,38,2,246,87,35,222,9,115,159,221,82,219,
111,131,118,221,196,80,197,104,161,157,228,183,114,149,254,151,132,203,164,49,173,72,30,125,78,187,103,56,114,143,50,94,218,218,173,189,204,59,148,237,164,40,21,93,95,104,52,252,233,209,85,249,89,242,
159,230,52,95,29,187,33,179,219,115,169,54,110,35,115,116,134,99,112,228,106,48,207,95,148,220,20,155,103,114,224,167,72,233,230,134,178,69,135,17,151,171,163,170,4,33,46,241,6,7,235,239,25,185,23,219,
175,108,162,231,206,95,104,111,247,27,189,202,61,210,53,65,38,149,140,203,27,134,173,84,18,234,8,249,3,158,165,158,88,229,91,123,235,171,91,248,229,111,167,138,228,14,227,77,69,27,52,30,99,249,117,84,
95,22,228,254,9,209,253,113,68,154,99,182,7,238,116,158,24,154,202,202,137,206,175,234,78,174,79,231,223,69,46,38,63,81,41,39,241,117,151,54,246,133,172,161,144,143,136,19,251,73,255,0,39,92,251,215,114,
53,69,61,53,24,114,110,67,50,223,80,226,223,79,197,189,182,204,95,236,232,223,106,183,48,72,27,77,7,69,202,129,245,58,31,200,34,220,254,62,167,253,143,211,218,41,254,26,124,186,28,91,176,199,66,182,220,
112,52,27,218,194,252,95,81,250,3,253,125,135,174,151,188,211,161,45,171,10,41,232,199,236,199,253,232,200,39,240,7,54,22,83,199,215,143,104,71,198,132,12,244,159,115,21,141,250,59,221,117,149,24,218,
10,172,159,218,207,144,254,27,140,175,201,12,117,42,179,213,100,31,27,67,61,108,120,250,100,6,239,85,92,208,8,144,0,73,103,30,196,27,112,213,42,37,104,89,128,175,165,72,29,64,188,235,250,48,220,79,160,
185,68,118,210,56,182,144,78,145,243,52,160,251,122,208,27,178,169,62,94,127,51,95,153,123,202,183,11,177,123,11,179,251,115,176,119,197,126,19,19,182,97,197,87,186,236,204,37,21,109,93,62,19,108,214,
75,80,137,141,218,120,61,173,138,135,68,166,119,167,134,54,71,118,245,177,190,81,219,71,103,181,88,67,18,186,172,8,188,106,40,126,127,50,79,92,145,221,46,119,206,114,230,27,219,199,130,89,183,25,165,61,
180,61,128,19,69,167,5,8,49,228,5,15,207,171,210,254,74,223,35,207,242,70,249,157,220,159,20,63,152,119,92,84,244,159,250,121,199,236,138,40,187,91,35,79,29,117,14,210,175,194,213,228,101,219,149,245,
25,154,1,85,73,152,234,237,206,114,210,44,217,10,71,146,58,58,152,149,228,26,86,77,9,111,99,93,202,217,39,181,147,80,90,227,215,163,93,138,226,78,86,220,238,118,237,222,220,198,210,0,53,31,42,86,134,190,
106,107,196,112,61,125,11,176,25,92,102,99,25,140,204,97,242,56,252,206,27,49,69,77,147,195,102,49,53,148,249,28,86,95,25,91,18,84,209,228,49,185,26,71,150,150,186,138,174,9,3,199,44,108,81,148,220,31,
100,67,24,34,135,169,13,157,100,238,86,170,17,142,149,35,73,31,215,233,126,121,191,251,19,254,30,217,29,172,107,211,29,118,72,177,31,235,147,123,14,121,28,126,127,227,126,245,150,63,62,189,210,110,184,
88,56,189,197,191,219,146,77,195,11,223,235,237,195,64,163,86,122,83,110,123,168,7,64,190,238,0,71,48,35,235,171,72,28,125,13,175,245,226,231,217,125,193,4,99,161,126,212,42,227,242,232,151,246,34,130,
102,60,216,9,0,231,252,57,255,0,121,246,15,191,252,67,169,183,150,91,251,49,209,54,221,45,235,144,155,145,114,63,23,253,92,91,216,98,110,58,105,199,169,183,105,161,11,143,46,131,74,175,169,23,252,92,216,
255,0,173,253,127,199,217,123,145,147,229,208,190,223,10,0,225,210,126,169,64,255,0,122,255,0,110,127,63,235,219,218,126,53,232,214,18,1,32,244,149,173,91,249,62,156,130,69,237,248,227,233,237,51,3,209,
197,179,210,131,164,14,90,32,84,184,23,253,86,3,252,110,57,252,130,61,161,184,167,3,199,161,93,139,83,77,58,11,51,113,240,202,1,228,31,175,211,253,143,231,217,60,160,82,164,244,56,219,159,225,4,244,24,
100,80,235,126,0,184,181,238,72,231,147,249,250,220,123,47,115,170,190,135,161,181,147,246,15,78,136,119,204,47,150,187,91,227,30,209,117,133,241,249,206,210,206,83,72,187,71,104,203,39,144,64,25,188,
103,113,110,8,161,111,37,54,34,140,130,81,24,171,85,72,2,39,26,217,71,92,143,200,183,92,221,124,178,76,175,30,203,17,253,73,56,106,243,240,211,212,159,50,62,17,243,167,88,233,247,155,251,205,236,254,195,
242,251,109,251,76,144,93,123,159,121,31,248,181,177,163,173,178,156,125,85,210,131,218,0,204,48,177,6,86,21,32,32,36,214,167,242,255,0,235,13,193,242,27,187,55,87,201,190,216,172,168,220,67,104,102,99,
171,164,168,200,141,107,153,223,213,177,25,104,2,196,195,197,22,55,108,80,40,150,40,150,201,19,120,84,0,22,222,229,127,115,55,171,110,86,229,219,78,86,217,144,66,247,17,233,162,227,68,11,135,35,250,78,
78,154,241,248,143,88,27,247,53,246,211,113,247,191,221,221,239,221,255,0,112,46,30,251,111,217,238,22,234,86,148,234,55,91,140,164,181,186,53,106,10,71,164,204,203,74,0,145,160,0,17,213,231,59,18,89,
216,155,150,58,129,177,189,253,68,220,19,171,159,120,227,18,224,26,118,245,217,103,98,197,157,137,44,77,73,245,39,172,60,114,120,230,247,252,255,0,66,127,55,252,123,94,139,64,58,67,115,192,83,133,122,
142,236,108,120,39,131,248,226,198,222,214,197,66,69,7,65,251,130,40,231,202,189,99,126,20,143,234,86,246,231,139,0,63,214,246,101,14,105,79,159,65,59,204,150,234,44,191,70,23,228,218,227,241,97,254,243,
127,102,49,169,210,7,207,162,9,143,120,249,14,141,103,194,160,163,188,182,115,106,23,254,242,227,74,223,254,160,171,244,143,207,246,189,196,158,248,26,114,78,226,15,252,163,201,254,21,235,26,126,240,76,
89,121,57,124,188,89,191,109,23,252,253,93,191,200,26,184,247,5,23,199,77,136,223,185,75,147,236,237,205,189,178,16,63,49,203,69,215,248,72,226,163,89,16,240,202,185,28,129,34,247,23,247,135,252,164,231,
103,228,46,121,223,16,82,230,101,88,84,249,254,161,11,199,236,39,172,106,181,181,19,243,90,169,248,99,137,79,237,36,159,240,14,141,31,77,208,167,237,206,84,107,158,86,98,72,3,128,65,28,129,197,143,30,
224,77,213,244,143,12,112,29,40,230,137,235,173,107,128,58,57,216,128,53,41,252,139,95,147,248,181,205,248,60,127,135,177,15,38,195,170,242,34,56,84,117,17,222,154,171,215,204,158,171,139,229,150,205,
220,125,89,218,240,124,152,233,74,19,81,148,200,99,211,11,222,125,125,142,38,63,244,135,183,96,101,88,247,13,21,42,234,73,183,54,37,5,236,163,201,38,144,194,231,80,51,141,238,245,177,111,182,175,237,247,
49,92,139,117,148,106,181,185,63,12,19,254,20,144,249,71,39,12,246,143,62,132,188,173,12,210,218,120,82,167,137,20,109,84,243,42,60,192,249,15,78,153,118,149,74,246,197,94,38,175,109,84,53,126,59,54,171,
86,149,42,47,246,240,183,170,104,235,35,45,122,90,170,70,5,37,141,244,180,110,164,31,112,181,222,221,117,179,221,207,183,110,16,148,188,137,244,145,235,232,203,252,72,220,85,133,67,3,142,165,87,188,181,
219,246,243,118,24,21,211,143,182,156,62,218,244,18,102,242,187,187,189,251,169,122,19,227,78,203,61,157,67,215,245,16,84,238,172,149,117,67,209,117,180,251,182,9,194,197,145,223,89,200,172,36,217,187,
74,161,11,173,12,108,100,202,86,168,80,25,18,199,37,189,162,246,27,152,249,165,4,240,70,241,238,119,105,67,39,3,105,108,195,185,131,16,86,57,166,6,129,232,93,22,186,6,163,212,121,190,115,101,166,217,100,
251,158,245,114,34,86,174,133,25,118,62,65,87,137,63,241,145,248,136,234,217,58,123,249,113,236,44,118,91,17,217,63,37,51,50,124,135,237,202,101,142,162,47,227,240,125,183,85,237,10,133,208,209,210,108,
126,187,95,247,17,77,77,68,84,34,77,82,146,203,32,245,16,62,131,162,190,218,253,223,121,23,219,205,190,218,24,54,232,231,189,81,220,204,42,133,189,104,213,46,127,165,33,98,125,7,14,177,215,152,189,206,
222,183,99,45,190,216,198,211,111,56,193,172,172,63,167,39,28,250,45,0,234,200,160,167,167,165,130,26,106,104,33,167,166,167,141,33,167,167,130,36,134,8,33,141,66,71,20,49,70,171,28,113,162,128,2,168,
0,1,199,185,217,85,81,85,81,64,80,48,6,0,251,58,140,217,153,152,179,49,44,120,147,196,253,189,102,247,110,181,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,
126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,95,255,214,223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,
238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,194,73,18,36,105,36,101,68,69,103,102,118,84,85,85,5,153,153,152,133,85,85,4,146,120,0,123,209,33,65,36,208,
14,182,1,36,1,199,170,100,249,121,242,43,11,242,37,50,253,59,178,229,21,221,21,130,207,81,69,217,187,226,142,69,120,59,95,112,96,107,34,175,139,171,250,254,101,186,214,237,252,126,78,150,54,207,101,208,
152,87,199,246,208,179,49,99,239,7,190,242,254,255,0,89,109,214,87,124,131,202,115,164,219,156,194,147,202,164,21,137,70,104,41,90,154,240,174,9,30,157,100,15,182,30,223,94,37,196,59,222,225,25,75,141,
36,198,164,83,195,86,4,23,122,240,114,166,145,167,28,212,208,117,86,223,60,177,217,202,191,135,95,38,119,141,108,107,2,14,189,170,19,72,84,175,162,106,154,44,125,53,37,58,88,20,130,8,164,72,208,125,21,
0,30,240,203,217,146,46,61,210,228,187,114,229,152,93,23,251,72,86,98,126,211,199,172,161,218,103,181,182,220,54,141,182,220,118,248,138,160,15,47,50,79,207,25,62,189,84,191,81,213,154,46,177,235,248,
213,180,178,109,76,74,129,199,167,246,11,92,15,207,234,231,223,65,238,101,63,83,61,127,139,172,174,218,172,196,155,85,131,211,140,64,254,218,244,28,118,174,66,90,188,156,0,200,72,85,111,169,252,126,7,
244,250,251,93,106,67,33,167,250,184,245,233,162,88,29,64,227,254,94,144,216,249,14,165,228,11,88,147,111,207,224,1,254,63,215,219,51,168,161,207,71,246,68,48,90,241,167,66,222,220,126,66,241,207,28,144,
15,36,30,47,248,246,30,187,92,212,112,232,69,108,194,128,158,140,86,206,154,210,69,194,220,0,15,63,75,253,44,79,23,191,178,234,81,193,174,58,245,234,150,137,199,71,99,172,170,202,26,113,125,37,74,233,
32,128,117,6,4,127,189,123,55,178,96,36,30,149,234,21,230,200,170,30,159,62,143,215,86,195,135,197,203,53,86,43,13,133,196,214,100,189,121,26,172,86,35,25,141,171,200,200,228,51,189,125,85,13,44,21,21,
174,236,57,50,51,18,125,200,91,116,238,234,138,236,204,7,169,39,172,101,230,59,56,99,121,222,56,17,89,184,149,80,181,251,104,5,127,62,138,71,243,108,254,88,27,75,249,159,124,109,27,119,19,252,51,1,242,
71,171,105,242,25,190,133,222,245,196,83,83,212,86,207,26,203,147,235,93,207,88,1,117,218,251,183,194,171,28,140,25,104,171,132,115,1,167,88,35,205,159,112,107,86,0,159,210,110,35,252,163,172,126,231,
110,91,77,234,220,148,0,94,198,9,67,254,21,63,35,252,142,122,212,115,249,98,255,0,59,127,149,95,202,79,179,50,95,21,126,75,109,253,207,216,159,31,118,110,242,201,237,13,243,212,59,150,162,79,244,129,210,
121,124,126,74,74,12,237,103,89,101,43,93,197,60,116,53,49,180,146,98,37,115,142,171,94,97,104,153,132,132,87,115,101,5,226,120,177,144,28,138,131,235,212,51,181,239,183,187,44,205,105,116,172,214,234,
104,84,241,82,14,105,254,110,29,125,14,190,38,124,213,248,203,243,119,173,105,251,87,227,23,107,109,254,204,219,5,96,76,205,29,28,141,67,186,246,133,108,202,174,216,173,231,180,171,132,89,189,191,144,
83,117,6,88,252,18,144,76,82,56,231,216,114,107,103,183,98,37,82,58,145,237,47,237,119,20,241,45,36,12,60,253,127,49,199,163,61,37,82,16,108,215,250,143,192,55,255,0,92,159,160,183,251,207,182,213,84,
16,71,75,2,176,35,29,39,43,234,0,70,98,192,31,175,214,252,126,62,190,233,43,96,170,241,233,125,186,53,64,167,159,64,214,235,157,124,114,155,131,123,142,79,214,231,250,159,101,147,124,35,161,102,214,157,
195,237,29,19,110,197,148,49,158,246,227,201,249,183,34,231,155,159,97,45,192,211,80,234,105,229,160,127,79,30,93,19,93,206,65,145,197,141,174,214,228,114,111,199,176,196,166,175,212,219,180,41,10,62,
99,160,226,168,242,127,54,36,3,254,63,83,249,246,94,254,67,212,244,48,132,118,215,207,166,42,150,184,55,181,201,31,236,71,231,158,62,158,218,243,61,24,70,163,82,215,128,233,55,90,44,79,250,155,91,159,
192,55,31,79,168,39,218,121,113,209,180,31,16,251,122,66,101,83,208,215,189,185,252,253,120,255,0,15,160,246,142,96,8,249,244,40,178,63,7,175,65,118,94,50,236,84,2,120,62,144,46,71,4,220,240,8,254,167,
252,61,147,77,193,170,64,53,232,113,182,235,118,80,162,167,203,252,39,246,121,147,192,113,234,160,190,103,255,0,49,13,133,209,75,152,216,61,107,61,14,250,237,232,132,148,149,62,22,21,91,91,101,84,200,
132,121,179,53,176,183,143,37,149,165,190,161,67,9,33,90,194,102,79,210,100,110,78,246,202,247,126,104,119,45,229,90,13,156,228,46,68,146,138,249,12,20,83,234,114,124,135,159,88,167,239,255,0,223,47,151,
253,179,135,115,229,15,110,164,139,115,247,0,3,27,207,135,179,177,98,40,72,96,72,184,185,67,248,23,244,163,111,141,152,141,61,107,153,93,146,223,157,207,191,214,163,39,95,149,222,123,243,124,103,41,169,
86,162,178,87,170,200,101,50,217,58,164,167,165,129,89,174,176,192,178,74,21,17,66,197,12,98,202,21,87,140,145,142,43,13,158,195,68,81,164,22,16,33,52,0,5,85,81,82,113,242,21,39,39,243,235,144,247,87,
124,195,206,156,196,215,55,183,55,27,143,50,110,55,32,23,118,50,77,52,210,176,2,164,146,75,51,16,0,224,48,5,7,91,84,116,31,79,98,250,31,169,54,127,89,227,82,38,168,196,227,214,175,113,215,198,138,14,91,
116,100,2,207,156,173,145,133,203,143,185,62,40,137,38,209,68,160,123,195,190,103,223,100,230,109,242,255,0,118,115,250,69,180,196,43,240,196,184,80,62,223,136,211,204,245,244,57,236,55,181,118,126,204,
123,89,203,124,147,28,99,247,192,79,30,249,199,227,188,148,3,40,39,204,68,41,10,122,4,62,189,11,174,108,7,228,159,235,107,218,223,95,249,23,178,40,208,176,160,234,90,110,227,65,229,214,38,54,82,47,98,
183,23,183,228,220,27,127,82,63,30,213,168,167,69,243,185,171,15,46,163,191,55,4,159,212,20,115,253,7,228,15,207,62,215,196,9,92,113,232,130,229,192,4,87,215,172,18,16,109,254,44,56,224,112,45,244,255,
0,31,102,17,41,224,56,244,20,187,122,215,166,247,123,19,248,191,212,145,123,40,63,83,111,165,237,236,218,49,149,232,61,51,16,114,113,209,163,248,111,87,224,239,13,158,11,42,15,239,54,8,221,143,246,89,
234,96,62,163,248,180,159,239,62,226,143,123,33,215,201,59,147,82,191,226,243,15,228,167,252,157,99,143,191,64,61,183,41,78,50,22,230,85,251,53,42,159,242,117,115,91,230,168,84,246,63,64,60,142,74,195,
130,238,170,72,111,244,51,127,17,198,59,40,7,251,98,52,231,243,111,120,99,2,159,245,168,230,8,199,225,220,160,39,236,60,58,128,45,35,17,115,92,226,148,213,106,135,254,50,127,216,232,237,244,228,225,150,
154,63,174,150,176,191,224,125,127,31,212,143,247,143,112,54,235,241,147,233,209,111,51,161,172,135,200,244,114,113,163,211,117,189,202,240,0,252,1,127,232,110,125,141,185,45,116,201,27,211,128,175,81,
37,225,227,78,21,232,166,119,149,99,46,64,71,173,135,55,244,177,15,201,254,159,91,159,104,55,185,13,198,241,115,81,80,49,67,212,155,201,113,1,108,24,10,14,139,230,252,160,202,237,13,147,181,58,123,171,
224,135,23,223,63,45,119,42,237,125,187,61,2,71,79,38,221,218,243,60,75,188,55,197,94,128,162,148,210,226,89,144,74,0,102,149,239,126,61,204,190,200,114,70,225,238,47,55,109,81,92,7,154,202,218,68,69,
215,82,43,90,170,230,181,68,248,168,112,0,167,69,60,207,189,219,45,197,245,204,164,13,170,198,50,242,1,248,223,136,80,7,18,79,249,58,187,95,142,191,29,122,215,227,39,89,225,122,207,173,112,208,80,80,80,
65,12,153,172,187,198,173,153,221,121,211,24,21,249,252,245,113,188,245,181,181,147,234,96,25,138,196,164,34,0,163,223,104,185,111,151,54,206,88,218,224,219,54,200,2,162,142,230,252,78,222,108,199,137,
36,240,244,24,29,98,38,255,0,191,110,28,197,184,205,184,110,19,22,98,78,149,252,40,190,74,163,128,160,253,188,79,67,199,179,254,137,122,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,
247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,191,255,215,223,227,223,186,247,94,247,238,189,215,
189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,93,92,125,46,47,239,221,123,164,134,244,236,29,143,215,88,106,157,195,191,55,118,219,
217,248,74,56,218,74,156,158,227,204,208,98,41,35,85,82,228,9,43,103,139,203,41,81,233,68,212,237,244,0,159,105,47,47,236,182,248,90,226,250,238,56,97,28,75,176,81,252,250,85,105,99,121,127,42,193,101,
107,36,179,30,1,20,177,254,67,170,171,239,46,240,222,95,49,113,181,253,125,209,181,155,139,101,252,120,146,161,232,183,231,109,181,53,94,3,113,119,5,34,157,51,108,190,167,142,181,41,235,232,118,197,96,
5,50,57,185,82,49,36,45,227,167,4,22,39,7,253,255,0,251,207,109,155,109,181,199,42,114,61,200,158,254,64,86,73,151,225,80,71,10,140,133,62,120,171,12,10,10,245,53,242,103,36,67,179,220,69,185,115,2,169,
220,5,10,69,134,17,127,78,90,96,184,252,41,154,28,159,46,155,246,95,65,237,172,21,30,30,130,186,44,126,51,23,133,161,131,25,129,219,88,198,209,65,137,198,211,139,69,71,77,24,187,61,239,170,89,13,222,89,
89,157,137,36,159,124,225,188,190,188,189,185,158,238,230,99,37,204,172,89,152,241,36,255,0,147,208,121,14,165,171,142,99,120,98,107,125,182,35,163,137,99,196,147,196,147,254,170,116,5,127,51,141,157,
134,163,254,94,31,43,162,199,209,170,21,235,9,38,87,81,169,149,41,51,24,154,166,183,214,215,138,156,223,252,15,185,59,216,135,11,238,223,39,51,31,244,119,254,113,176,233,158,82,220,238,238,121,191,151,
252,89,42,62,165,127,192,71,249,122,214,79,171,42,12,253,101,176,37,31,70,218,120,149,36,15,237,71,76,177,181,201,250,130,203,239,161,87,96,45,213,192,175,227,61,116,159,97,80,219,46,214,107,143,5,127,
150,58,13,187,18,170,249,133,95,174,155,94,228,113,254,181,191,0,251,54,176,4,194,15,69,91,165,22,231,79,76,88,247,4,171,18,5,173,113,205,237,107,126,56,224,31,246,30,235,55,194,113,209,133,139,97,7,159,
66,182,220,159,75,199,207,248,41,35,234,5,133,236,126,190,200,110,151,25,29,8,237,206,105,229,209,134,218,85,26,94,59,88,145,162,195,241,114,7,168,158,109,254,183,178,162,49,94,159,185,90,161,206,58,56,
29,123,92,98,52,247,107,217,135,63,130,13,135,212,113,254,223,217,133,179,5,101,61,69,28,207,111,169,100,20,242,61,31,158,189,202,91,237,238,192,13,43,115,254,195,235,197,253,141,246,217,78,51,214,57,
243,37,174,100,199,70,207,108,229,6,136,192,97,123,169,23,60,2,7,227,145,111,167,30,197,246,210,224,103,61,67,123,165,173,25,168,51,158,181,107,255,0,133,30,127,40,188,103,113,236,157,211,252,196,126,
61,225,133,63,107,236,60,53,53,95,200,189,147,137,164,244,118,22,203,197,198,148,191,233,55,25,77,2,235,109,221,181,41,2,38,77,84,19,89,143,65,47,249,200,78,161,142,205,185,80,173,164,167,180,158,223,
243,127,155,249,117,6,243,215,43,151,89,55,139,68,253,85,3,196,81,248,135,241,1,234,56,159,81,214,151,255,0,23,62,92,252,136,248,95,218,56,206,225,248,217,218,27,143,172,183,189,7,138,42,138,172,53,81,
108,94,127,26,178,164,210,224,247,70,18,160,73,139,220,56,74,157,37,100,167,169,141,214,204,116,233,110,125,137,101,138,57,144,164,139,85,234,44,180,188,185,178,148,77,109,41,87,254,71,237,30,125,110,
253,240,27,254,21,121,209,221,163,22,220,235,239,157,155,34,78,143,223,83,199,79,142,169,238,93,143,5,70,107,169,242,245,204,241,211,165,126,123,109,47,155,63,178,214,165,152,203,60,145,53,85,20,60,159,
74,143,100,87,59,67,128,205,110,218,190,71,143,229,254,161,212,135,180,243,149,188,154,34,220,147,195,127,226,31,15,218,124,199,243,31,103,91,69,236,238,216,235,222,220,218,84,59,235,170,119,222,211,236,
173,151,151,167,142,175,27,185,246,70,127,27,185,49,21,48,76,161,162,115,62,58,121,77,62,165,60,172,129,28,126,71,176,244,203,36,108,86,85,42,223,62,164,187,19,13,212,98,91,89,22,72,207,152,53,255,0,7,
73,61,205,144,26,31,212,62,133,141,254,162,224,89,109,244,189,201,246,89,114,244,7,61,12,54,184,8,100,20,243,232,162,118,5,80,111,63,55,253,100,139,144,188,155,91,143,167,176,150,224,213,213,212,203,203,
145,105,49,227,162,135,185,38,6,86,181,190,164,253,79,245,253,54,55,28,123,14,200,106,199,169,155,106,4,34,154,116,31,78,215,39,233,203,31,199,3,158,56,227,218,22,243,232,86,152,76,116,207,81,201,254,
182,224,255,0,173,107,219,219,62,181,233,124,88,167,73,234,149,214,197,84,23,99,112,21,5,203,30,62,128,2,120,191,250,254,210,190,53,18,40,7,70,214,192,179,133,81,83,95,47,94,138,39,200,143,148,221,15,
241,203,7,89,151,237,110,194,194,97,234,98,71,251,77,173,143,171,167,203,111,44,180,234,27,77,46,55,111,81,204,245,174,228,139,51,202,35,138,63,171,186,143,102,91,95,46,111,59,244,171,22,221,98,229,15,
25,24,21,140,15,155,127,144,84,244,27,231,47,119,61,190,246,206,202,75,158,105,230,40,86,237,71,109,180,44,37,185,115,232,177,41,170,250,22,144,170,143,51,214,180,255,0,44,255,0,154,247,108,119,103,241,
77,161,212,116,213,61,69,215,53,75,61,28,181,84,117,66,93,251,184,168,156,20,39,35,155,131,74,225,32,158,59,134,130,138,207,99,99,41,228,123,153,121,107,219,77,163,103,104,175,55,42,93,238,74,65,5,135,
233,161,31,194,158,116,254,38,169,235,159,62,238,125,239,57,239,159,225,188,216,121,91,86,199,202,50,2,172,145,49,250,169,211,254,31,56,161,80,70,12,113,105,95,34,88,19,213,76,73,36,146,187,201,35,188,
143,35,180,142,238,197,221,221,201,102,119,118,187,59,179,27,146,121,39,220,151,192,1,229,214,35,146,78,73,207,86,209,252,172,58,16,110,141,245,154,239,61,195,64,95,7,215,192,226,54,147,79,31,236,213,
239,76,132,4,212,85,196,27,245,156,14,42,107,223,144,37,169,95,202,251,135,253,221,230,63,160,218,162,216,109,165,165,213,222,94,156,68,74,69,127,222,207,104,251,15,89,253,247,5,246,132,115,111,184,23,
158,230,111,22,122,249,127,151,128,240,53,14,217,119,9,1,240,135,244,188,4,172,172,56,3,225,158,175,138,69,212,77,237,126,47,245,55,55,36,223,146,73,183,188,109,65,167,83,31,63,242,99,174,203,179,208,
212,228,147,95,207,253,158,163,48,211,115,170,229,133,128,231,244,254,127,219,255,0,143,183,226,169,63,159,73,164,146,138,212,235,11,48,254,167,158,73,28,158,111,245,189,197,239,237,82,138,249,244,89,
112,225,170,60,250,141,33,253,35,158,5,207,244,189,248,4,131,237,124,8,112,107,142,136,111,30,149,234,44,207,244,31,211,250,125,46,69,238,62,183,30,206,45,151,36,211,61,4,174,228,253,189,54,179,223,128,
47,113,254,192,90,255,0,80,79,30,204,82,48,105,254,30,131,87,146,210,185,243,232,92,248,247,156,24,62,215,219,21,166,79,26,195,147,196,212,234,250,89,105,178,212,166,82,127,193,99,148,255,0,175,111,96,
207,115,108,62,179,147,239,226,9,82,67,45,63,211,35,127,134,131,168,39,222,168,252,110,87,178,184,2,166,11,232,207,216,24,21,234,244,187,147,94,23,49,209,251,180,16,152,204,103,109,110,61,179,93,80,77,
163,166,131,127,109,248,167,160,71,107,16,145,203,85,73,41,255,0,18,190,240,87,150,45,223,114,228,142,127,218,232,76,203,12,115,40,245,240,179,95,248,207,88,233,44,235,14,255,0,181,74,72,253,72,52,159,
201,169,252,129,29,28,46,163,175,52,249,84,167,102,33,75,128,22,247,177,83,107,139,125,47,253,63,175,184,11,117,77,81,135,3,56,61,57,204,176,214,7,96,61,122,63,216,59,75,10,31,175,166,255,0,224,64,23,
185,252,126,109,236,107,201,43,170,29,94,84,234,15,191,236,144,143,159,69,51,181,40,36,205,246,54,35,8,130,226,182,178,146,19,199,26,94,101,212,108,45,205,184,246,29,221,36,31,188,55,57,20,212,6,63,183,
169,55,150,166,22,155,12,247,103,138,171,31,229,142,152,62,25,225,7,125,252,248,238,254,238,169,86,159,102,124,111,193,83,116,175,91,168,80,104,147,55,87,11,38,126,177,84,221,62,224,211,9,73,101,231,83,
3,248,30,250,153,247,65,228,133,219,182,152,183,137,99,253,72,224,173,125,101,156,26,215,253,44,116,167,250,99,212,31,238,78,226,214,28,185,97,181,134,255,0,25,190,144,205,39,174,144,113,243,248,191,151,
87,134,5,189,231,39,80,55,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,
235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,255,208,223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,
221,7,189,163,218,27,55,167,118,94,87,126,111,172,153,198,224,177,98,24,128,130,9,43,50,89,76,149,100,130,159,25,131,194,99,96,13,83,148,205,229,170,221,97,166,167,136,23,146,70,252,0,72,41,223,55,205,
175,150,246,171,221,239,122,188,72,54,219,116,44,238,198,128,1,254,18,120,1,210,253,183,109,188,221,239,97,176,176,132,189,203,156,122,1,230,196,249,40,25,39,170,136,236,238,231,249,101,220,249,39,157,
115,59,179,227,238,194,168,102,24,126,189,235,234,12,76,221,155,95,66,215,88,231,223,93,129,152,19,98,240,85,181,176,181,205,6,46,41,94,154,250,90,70,96,125,243,155,220,127,190,94,225,184,94,221,88,242,
52,177,91,109,168,74,137,88,213,155,250,88,4,254,88,31,62,178,43,150,189,179,229,219,8,18,93,214,104,46,46,72,4,180,132,232,7,209,35,92,144,61,95,143,26,1,210,3,1,241,110,163,33,152,164,221,89,205,168,
50,121,232,25,102,135,115,118,238,225,206,118,134,120,79,193,251,184,169,179,245,53,88,122,122,145,245,82,148,232,22,220,1,239,20,121,139,221,254,103,230,102,155,247,151,52,221,222,22,57,88,201,11,251,
107,90,124,171,208,235,197,229,173,178,51,5,177,46,163,240,196,22,37,255,0,140,208,244,101,104,250,175,41,80,201,38,225,222,123,139,38,209,42,199,20,20,38,44,101,21,60,74,163,76,52,212,240,42,199,4,11,
107,4,80,2,143,113,187,238,247,140,91,192,219,2,159,50,213,53,249,212,230,189,35,125,250,214,53,49,217,109,112,198,135,215,184,159,180,244,37,97,182,229,62,26,53,90,88,158,73,21,120,168,172,168,106,138,
147,107,125,94,77,70,196,255,0,79,105,150,77,214,98,92,198,170,61,58,33,185,190,250,146,76,142,40,79,5,20,29,0,127,56,246,227,111,15,134,95,40,246,211,83,180,178,100,250,59,126,36,73,24,18,58,203,75,135,
154,173,37,69,181,139,70,96,44,56,227,220,165,237,13,228,182,94,229,114,77,220,180,66,47,209,79,216,213,31,207,167,121,126,81,107,204,91,21,202,190,22,238,50,127,222,169,254,94,180,254,248,251,92,217,
62,150,235,202,167,224,140,26,192,192,55,230,9,221,108,121,252,2,7,251,15,125,43,221,87,195,220,110,212,127,23,249,58,233,247,44,19,38,193,96,79,21,212,191,177,143,72,142,195,99,252,118,64,57,210,160,
216,222,246,6,228,95,217,214,221,95,167,90,240,232,155,117,122,95,16,120,30,153,177,207,253,65,39,131,123,158,77,135,4,127,83,238,179,129,74,244,97,98,220,61,49,208,161,128,152,234,138,224,11,112,71,245,
22,23,181,249,252,251,33,187,24,199,66,139,118,93,70,131,161,243,107,79,102,67,127,162,169,36,88,30,109,254,63,95,167,250,222,201,216,113,29,47,155,41,158,141,46,201,201,4,49,11,144,73,95,207,7,250,92,
92,159,106,99,52,208,122,143,183,235,109,106,230,158,189,29,125,133,158,85,17,15,40,176,3,139,130,126,130,231,243,245,39,216,163,111,158,133,115,142,160,94,98,176,53,147,183,29,27,13,179,184,98,241,199,
121,5,248,191,63,94,56,252,143,160,30,197,182,183,67,25,234,32,221,118,214,44,195,78,122,21,233,51,84,117,84,210,210,86,195,75,93,67,89,75,81,69,91,69,89,18,85,208,215,208,213,195,37,61,93,21,109,36,193,
225,170,163,171,167,145,163,146,55,5,89,24,130,15,179,152,167,0,2,31,61,3,46,182,194,117,171,70,8,34,158,191,145,249,122,245,243,195,254,126,191,202,138,143,225,55,112,195,242,3,161,112,21,17,252,90,238,
236,197,92,240,226,104,105,231,158,139,166,59,6,119,53,57,29,139,85,80,3,173,46,219,204,51,181,78,17,228,107,44,122,233,175,120,211,80,243,101,220,197,236,94,20,140,62,161,7,251,208,245,255,0,63,88,231,
207,124,162,251,5,216,189,181,136,254,235,152,227,24,70,254,19,232,15,225,253,157,107,181,236,243,168,251,163,25,241,227,229,207,201,111,137,251,158,45,221,241,223,186,119,239,84,229,210,81,44,241,237,
140,229,76,24,108,145,5,78,156,198,220,168,53,24,12,196,100,40,22,169,166,150,195,233,111,108,205,111,5,194,148,154,32,195,231,210,235,29,202,255,0,108,148,77,99,118,241,56,244,56,252,199,3,249,142,175,
151,166,191,225,82,31,52,54,204,116,152,206,245,235,142,165,238,252,100,106,145,213,229,233,241,181,189,125,187,231,10,2,180,230,183,3,60,216,73,102,112,46,192,208,160,45,207,3,143,100,55,124,177,101,
56,99,20,175,27,126,209,251,63,217,234,72,217,253,219,223,54,230,65,119,103,5,204,99,141,65,70,253,171,138,255,0,181,232,250,237,239,248,82,135,196,205,245,79,163,127,245,15,113,117,173,100,138,4,173,
67,54,15,122,227,22,75,46,179,20,148,141,143,175,104,203,19,109,81,6,183,215,216,66,255,0,145,183,39,171,91,222,68,223,104,43,254,113,212,213,203,191,120,78,85,135,64,221,54,59,184,72,226,81,146,65,249,
124,39,167,233,127,157,175,242,249,205,254,240,236,109,235,142,102,28,211,228,122,223,114,198,235,171,241,174,26,105,161,37,127,62,171,127,79,97,201,57,11,153,117,16,33,132,143,244,227,252,189,76,27,111,
222,83,218,116,140,120,183,215,168,254,134,221,143,248,9,29,32,179,255,0,206,207,224,126,46,57,90,135,114,118,62,226,157,85,204,84,248,173,131,91,10,202,87,149,95,185,200,212,82,199,30,163,249,35,219,
73,237,223,49,177,5,132,10,9,243,122,255,0,128,116,190,227,239,87,237,69,186,55,130,219,148,236,56,5,128,37,127,54,126,138,110,253,255,0,133,0,117,61,53,45,100,125,113,208,123,227,55,145,82,241,209,212,
239,29,197,135,194,99,36,4,16,181,18,71,136,92,173,102,155,128,124,122,84,159,245,67,217,189,191,181,183,44,192,222,238,232,19,204,34,18,127,107,17,251,105,208,39,116,251,229,237,49,70,227,97,228,121,
222,127,194,215,19,170,175,218,86,53,36,253,149,31,104,234,174,187,215,249,193,124,194,238,72,171,113,120,77,205,139,233,237,183,86,175,27,98,186,218,132,208,228,222,9,21,210,72,170,119,69,116,149,89,
167,242,35,13,70,39,132,92,92,1,244,246,49,219,121,11,151,118,226,178,53,169,158,112,107,170,83,170,135,212,46,23,249,117,3,243,119,222,99,221,94,107,73,173,98,222,87,108,219,158,163,195,179,95,8,144,
124,154,90,180,173,254,246,58,171,252,158,91,41,155,175,170,202,102,114,53,217,108,157,116,207,81,91,145,201,213,207,95,95,87,60,132,180,147,84,214,85,73,45,68,242,200,198,229,153,137,39,216,197,85,81,
66,34,128,131,128,24,3,242,234,2,150,89,103,149,231,158,70,121,152,213,153,137,102,99,234,73,169,39,230,122,111,247,110,155,232,74,234,30,173,220,253,207,216,155,95,173,246,133,51,84,102,119,54,74,42,
53,152,163,61,62,50,137,79,147,35,151,175,42,15,142,131,25,70,175,52,140,72,225,108,57,32,123,46,221,183,75,77,151,110,187,221,47,94,150,208,161,99,234,105,193,71,169,99,64,7,153,61,10,121,39,147,183,
222,127,230,189,135,147,121,110,212,205,189,110,23,11,20,96,3,65,168,247,59,211,132,113,168,47,35,112,84,82,122,219,95,171,250,191,108,116,191,94,237,110,182,218,20,201,14,23,107,227,162,164,51,180,97,
42,50,185,23,188,153,76,213,115,46,159,37,102,82,177,154,87,63,139,133,28,0,61,225,182,249,188,221,239,251,173,222,237,122,107,44,172,104,60,145,7,194,131,228,7,237,53,39,175,162,63,106,253,186,216,189,
167,228,77,139,144,249,121,65,180,178,143,245,101,165,26,230,229,179,61,195,211,206,71,248,71,225,64,23,128,233,95,35,5,36,159,245,129,177,3,232,120,254,188,15,101,138,154,128,207,159,82,9,34,135,61,67,
36,254,163,192,31,236,65,183,208,143,245,253,170,2,152,3,164,146,200,40,71,81,152,139,243,111,175,36,127,79,175,251,127,106,17,105,229,158,138,230,147,12,221,70,36,125,79,26,185,28,241,164,126,63,222,
61,152,64,188,0,57,232,59,123,54,14,122,129,57,96,73,184,39,234,45,244,177,227,253,107,251,56,133,123,69,62,46,130,87,178,138,158,154,229,144,130,196,126,46,53,125,111,253,72,31,155,92,251,52,137,106,
188,50,122,10,221,205,86,98,79,79,27,34,184,210,111,12,44,218,128,242,73,44,1,137,182,135,150,38,104,180,255,0,67,229,65,111,241,246,93,204,214,223,81,203,251,132,99,240,168,111,216,69,127,151,81,111,
185,16,27,238,77,223,34,21,46,168,178,15,246,140,9,254,93,108,113,184,113,114,246,239,198,125,221,6,46,243,103,219,100,109,206,207,219,58,67,60,141,185,54,4,112,230,106,96,167,183,171,205,83,141,90,168,
248,254,202,183,188,3,228,103,77,159,159,119,77,146,235,16,92,9,161,207,12,19,65,249,169,199,88,161,190,85,45,246,141,201,120,71,34,215,253,44,131,79,236,12,1,232,78,232,237,233,6,229,195,236,253,217,
78,224,197,156,196,227,114,46,67,92,172,211,192,159,115,27,219,244,186,78,175,117,252,31,112,79,54,236,207,179,110,187,174,208,235,136,39,116,24,35,182,181,94,62,170,71,66,91,241,245,91,124,114,12,150,
74,255,0,42,31,231,213,165,108,106,196,173,161,141,212,130,68,87,38,246,32,15,175,228,220,159,103,30,223,21,104,231,132,140,173,122,130,119,184,140,87,4,124,250,2,247,141,59,227,55,252,187,162,85,34,28,
46,27,59,149,141,141,184,151,25,139,170,173,140,145,255,0,6,139,216,110,246,220,205,204,50,88,50,226,75,184,197,62,76,192,26,244,44,178,186,31,213,137,109,212,247,49,0,253,132,231,165,95,242,134,218,63,
194,62,37,82,239,154,128,91,41,219,189,133,191,183,246,66,102,31,185,42,84,110,26,220,101,7,145,200,14,246,166,161,5,111,112,1,227,223,116,125,145,218,147,109,228,45,189,213,64,105,153,155,135,146,254,
154,255,0,37,199,219,214,60,123,169,118,110,57,170,75,106,246,91,67,28,99,253,231,81,254,103,171,74,247,46,245,27,245,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,
123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,95,255,209,223,227,223,186,247,94,247,238,189,215,
189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,82,135,243,104,237,205,247,214,149,61,127,89,179,163,166,108,134,7,111,101,179,219,82,163,33,74,181,152,
236,46,239,204,100,78,219,59,189,168,165,189,53,110,83,106,227,36,38,132,202,25,105,234,106,196,128,106,183,188,74,251,207,198,251,204,156,145,202,119,207,34,242,221,204,179,77,112,20,233,241,124,5,5,
33,98,50,20,147,83,234,5,58,158,125,146,217,108,183,123,187,216,167,106,73,35,172,103,212,166,146,229,71,166,178,40,222,160,83,173,90,119,174,224,238,140,254,98,175,112,110,110,200,223,89,220,181,68,207,
83,61,125,94,228,203,137,26,86,58,137,141,98,169,142,40,148,49,225,85,64,30,226,253,167,110,229,59,59,104,236,246,253,134,210,43,112,180,10,34,78,31,50,65,38,190,117,61,101,170,236,59,125,180,98,36,176,
136,32,199,194,9,253,167,61,40,182,103,207,95,147,255,0,28,234,113,114,237,142,195,220,123,157,171,43,98,162,160,217,59,146,182,76,254,51,44,84,137,42,68,209,100,140,243,83,81,210,211,169,121,101,71,77,
2,220,253,61,161,220,253,161,228,78,112,241,133,206,207,21,179,168,212,103,132,120,110,190,153,74,86,167,0,122,241,233,36,126,223,88,115,53,228,59,117,173,162,199,119,35,80,21,192,21,224,79,203,215,229,
94,175,47,227,39,243,98,234,142,226,92,126,211,237,72,32,234,158,192,171,104,233,83,37,44,173,46,198,201,85,186,170,169,251,246,115,62,24,203,51,105,188,161,160,28,94,65,127,120,207,206,158,198,115,87,
45,9,111,54,71,27,142,214,185,3,2,96,191,96,160,99,76,226,132,250,116,20,231,191,100,121,187,144,217,175,110,32,250,189,144,127,163,193,86,10,125,28,124,74,71,204,80,241,4,245,100,85,59,169,169,154,154,
26,208,180,230,170,53,154,134,186,158,69,168,199,215,69,40,15,12,212,245,113,51,196,240,204,140,10,144,197,72,55,7,220,32,171,168,200,99,4,72,134,142,167,12,164,122,142,35,168,234,43,20,158,51,44,13,170,
49,196,112,35,242,61,74,202,10,61,235,181,55,102,206,172,100,3,116,109,93,197,182,229,87,245,172,144,231,48,213,184,214,93,55,179,134,21,54,246,107,179,223,253,6,235,180,238,10,104,246,247,81,73,254,240,
234,79,72,103,183,146,209,227,185,65,132,101,111,247,150,7,173,32,62,60,210,212,225,246,94,115,101,215,198,208,228,58,251,176,119,166,208,173,165,146,225,233,36,199,102,234,149,97,101,252,104,11,164,113,
111,79,190,170,238,206,147,220,67,119,25,172,115,194,142,15,168,101,6,191,207,174,155,251,121,123,29,255,0,45,67,34,181,123,129,252,157,67,143,240,159,217,210,123,178,19,199,159,144,89,133,213,72,255,
0,19,207,31,91,145,236,227,108,109,86,171,210,45,251,183,112,175,73,140,116,129,110,47,164,22,210,71,36,220,27,127,174,7,183,110,65,167,14,150,216,181,84,10,116,36,225,37,210,241,129,200,227,242,46,9,
0,133,231,250,251,34,185,24,62,189,10,45,158,161,72,227,208,225,182,234,180,148,26,141,136,3,232,45,107,216,175,31,79,248,160,246,70,226,140,122,56,52,100,30,125,24,157,171,145,208,98,245,126,85,65,183,
248,220,1,207,183,65,28,71,14,131,91,156,1,131,208,96,244,103,118,142,227,48,52,127,185,111,165,249,54,22,250,143,173,254,131,143,207,179,27,73,180,144,7,30,162,173,247,106,18,6,33,115,209,143,219,187,
205,124,104,124,131,234,47,115,114,13,185,7,159,199,250,254,196,54,247,100,1,83,212,93,185,108,100,147,217,94,133,140,110,247,210,171,105,72,63,139,55,3,235,110,9,60,115,236,218,43,209,74,215,29,3,174,
118,38,53,236,233,45,220,91,75,173,254,66,245,70,250,233,62,224,192,210,238,238,184,236,108,29,70,7,115,97,106,180,7,48,206,183,165,202,227,102,32,154,12,238,22,177,82,166,138,165,8,120,39,141,72,54,184,
38,22,251,156,150,210,197,113,11,210,85,53,31,229,31,97,224,122,15,238,156,165,107,186,217,92,237,247,214,250,173,101,82,8,255,0,1,7,200,131,66,15,168,235,230,183,252,197,126,3,246,63,192,46,250,204,245,
190,229,74,188,247,94,102,167,171,204,117,23,100,45,43,38,55,123,109,7,156,154,81,52,168,62,222,155,114,225,209,214,12,149,40,58,163,153,117,168,241,186,19,45,237,59,173,190,237,106,179,194,195,196,24,
101,243,83,254,111,67,214,23,115,175,39,110,60,151,188,75,183,94,161,54,205,221,12,148,237,145,61,71,204,96,48,226,15,200,142,136,15,179,78,130,29,123,223,186,247,94,247,238,189,215,189,251,175,117,239,
126,169,245,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,46,134,134,175,37,89,75,143,160,166,168,173,174,174,168,134,142,138,142,146,23,168,170,171,171,169,145,97,167,166,167,130,48,210,
77,60,242,184,84,85,4,179,27,15,122,98,170,172,236,192,32,21,36,224,1,213,227,142,73,100,72,162,70,105,89,130,133,2,164,147,128,0,25,36,156,0,56,240,235,103,223,130,191,14,104,190,53,108,111,239,86,236,
167,134,171,184,183,198,46,150,92,228,206,128,255,0,115,240,243,44,117,81,109,28,123,155,218,167,89,15,95,48,255,0,59,50,132,30,136,193,56,185,238,31,57,191,50,94,157,190,201,233,179,64,231,79,252,53,
198,60,67,253,17,157,31,35,95,62,187,91,247,70,251,186,195,237,23,47,142,113,230,104,3,123,143,186,91,141,74,70,108,45,156,106,22,235,233,113,47,105,184,111,194,0,136,112,98,78,213,100,156,155,41,36,142,
79,212,113,248,35,143,175,184,228,70,56,117,154,113,16,162,152,227,211,75,90,196,155,159,85,207,245,2,223,235,242,5,189,220,71,65,74,244,219,49,36,158,161,72,247,60,142,62,128,15,201,191,3,143,246,254,
212,42,157,66,189,35,146,77,88,34,157,70,123,11,143,165,249,230,255,0,75,255,0,182,231,218,200,145,181,1,79,46,61,21,220,206,20,26,112,235,12,164,1,111,207,250,255,0,69,31,65,197,249,62,204,161,78,20,
225,208,94,242,110,36,116,211,59,242,127,28,253,71,245,111,233,254,28,123,53,133,50,7,151,65,59,233,176,115,211,60,238,62,183,250,223,253,123,255,0,95,245,239,236,218,32,0,52,232,45,119,49,36,138,99,143,
80,226,172,52,53,116,149,202,199,93,45,85,61,86,161,201,11,12,161,155,145,207,49,6,227,219,242,91,173,204,19,91,183,195,36,108,167,243,4,116,65,123,110,183,182,183,150,111,240,77,19,161,255,0,108,164,
15,231,78,182,64,248,95,190,62,239,175,118,165,82,186,84,182,14,162,162,129,225,151,215,29,69,28,114,59,189,19,131,250,224,171,198,214,60,108,63,40,228,123,230,191,185,118,247,28,191,206,179,110,86,202,
86,120,228,73,133,61,70,24,126,122,105,254,30,177,34,91,37,155,105,151,111,185,7,180,201,11,124,168,104,15,173,65,207,229,214,94,178,142,94,169,237,14,204,233,74,175,216,161,219,185,243,188,58,255,0,200,
196,173,95,95,111,9,27,45,138,106,89,63,221,177,209,26,143,19,91,244,200,25,127,179,237,55,187,251,84,91,132,59,55,57,237,226,182,183,176,40,144,142,26,194,138,31,204,99,253,175,175,77,242,205,193,188,
219,30,202,118,173,204,36,169,251,84,233,111,231,159,176,245,107,221,69,187,18,124,114,160,125,78,170,46,164,220,129,244,60,114,127,30,225,254,88,188,59,109,228,138,13,11,30,128,124,213,182,50,205,171,
79,153,233,235,177,104,227,203,237,173,229,44,1,13,91,109,13,210,176,40,253,69,230,192,87,71,164,1,205,136,98,61,234,243,183,154,246,155,255,0,192,110,98,175,251,216,232,154,213,218,222,1,11,124,4,138,
254,222,133,111,229,148,244,175,240,91,227,191,218,149,178,236,250,200,231,85,34,241,213,71,184,179,41,81,28,128,126,153,3,142,65,231,159,125,229,246,196,169,228,78,91,41,195,192,63,241,230,235,31,253,
194,215,253,114,223,117,143,244,81,79,179,74,211,163,223,236,121,208,51,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,
123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,255,210,223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,
94,247,238,189,215,189,251,175,117,239,126,235,221,18,159,156,63,26,211,228,47,86,200,152,154,4,175,222,123,78,28,157,86,23,30,206,176,157,195,137,200,195,16,220,27,88,78,222,154,122,172,146,82,67,81,
69,41,226,44,133,44,12,125,58,189,198,62,235,114,43,115,199,45,152,108,72,93,250,209,252,107,102,60,53,129,70,141,143,240,72,189,173,233,131,229,208,219,145,57,161,249,95,120,142,115,33,91,87,35,83,1,
82,133,77,81,199,250,83,196,121,169,35,173,65,251,75,23,69,213,107,185,91,125,121,232,177,219,114,42,201,229,173,172,163,146,150,170,182,154,154,70,138,58,120,168,164,30,97,158,146,160,10,105,40,185,154,
58,187,166,155,105,39,8,108,96,220,46,55,1,182,195,111,34,110,130,95,13,226,96,67,68,224,209,149,199,26,46,115,192,173,8,227,215,66,121,123,123,179,230,61,190,27,152,93,124,122,13,106,8,193,167,196,167,
205,91,136,111,203,143,69,114,187,103,100,177,184,133,221,187,171,30,49,221,157,216,212,200,152,253,165,40,15,39,86,245,141,67,173,86,55,11,44,96,18,155,207,115,174,154,156,156,166,205,2,20,128,114,27,
220,219,60,17,109,27,116,91,76,50,23,156,26,204,245,248,155,229,242,30,157,79,62,216,242,224,250,166,222,36,140,253,58,130,16,211,139,112,45,246,83,0,126,125,59,225,250,43,47,147,199,253,253,44,51,172,
138,186,213,144,17,227,176,184,210,87,144,111,249,30,202,204,216,34,184,35,129,21,7,237,30,125,76,119,23,54,16,171,195,43,161,87,82,25,90,148,96,120,134,7,12,8,242,61,29,95,139,255,0,60,247,215,199,220,
150,59,168,187,191,239,183,167,78,79,81,29,20,51,212,187,205,184,118,66,59,24,197,86,2,162,102,4,210,196,196,51,82,51,120,152,3,163,67,114,96,239,114,61,156,219,185,162,41,183,221,129,86,215,153,16,19,
128,52,76,56,233,113,231,254,152,100,113,207,88,173,238,103,177,86,206,151,156,215,237,226,20,189,90,188,150,99,40,227,139,24,184,26,249,232,207,244,125,58,190,76,22,234,160,159,29,183,119,78,214,220,
20,187,155,105,103,224,131,43,181,55,38,54,77,116,245,244,154,131,154,105,141,245,67,89,78,70,137,97,123,60,110,10,176,7,222,26,110,22,23,86,83,220,218,94,219,60,55,177,146,178,35,96,171,127,149,79,21,
62,99,35,172,98,141,98,190,138,101,104,138,78,184,116,34,132,31,60,30,29,106,179,217,120,39,235,175,157,95,47,186,234,104,5,21,46,127,121,69,218,56,40,71,162,41,104,183,60,49,228,170,103,167,75,40,41,
52,245,82,177,35,232,125,244,171,144,247,81,191,251,103,200,219,184,125,82,11,65,11,159,48,209,118,16,126,125,162,189,102,71,177,187,136,151,100,138,197,164,171,8,7,251,212,68,169,31,239,37,122,3,59,98,
19,30,102,9,77,173,36,92,55,210,199,159,114,46,210,199,233,233,92,3,208,227,153,86,151,74,212,227,254,110,131,202,70,176,191,26,139,127,177,255,0,15,241,231,217,140,148,101,173,49,78,154,219,228,224,61,
41,208,129,137,158,218,77,172,120,36,19,199,31,155,240,63,62,201,39,94,227,94,133,150,143,249,158,134,44,5,95,165,121,38,197,126,166,227,144,15,0,95,131,236,134,117,42,249,20,232,250,34,8,35,229,208,225,
183,242,11,120,198,171,11,174,147,127,161,255,0,97,111,207,186,199,195,231,94,145,93,66,89,15,67,118,11,50,87,64,46,84,254,121,60,155,125,110,45,253,61,188,191,35,158,130,55,214,34,64,106,189,11,56,157,
197,36,65,64,152,233,191,211,81,250,216,127,196,123,95,13,193,225,231,208,46,251,106,82,79,103,75,250,45,221,34,133,253,242,13,173,201,23,3,241,253,79,7,218,244,185,60,43,208,102,227,101,4,252,56,233,
254,29,225,56,183,239,220,88,125,74,159,173,175,201,226,254,212,11,159,94,139,155,101,21,248,58,0,190,78,244,135,80,124,190,234,124,207,77,247,118,223,139,59,182,178,39,239,49,57,90,111,20,91,147,102,
231,213,10,82,238,93,169,148,100,121,49,249,58,107,217,215,152,106,98,38,57,85,148,251,95,183,111,119,91,93,202,221,218,73,71,28,65,248,88,127,9,31,234,161,207,65,158,104,246,239,103,231,13,166,93,155,
122,182,45,110,198,168,235,253,164,79,228,241,147,192,250,142,12,48,71,90,55,124,249,254,90,157,201,240,123,114,61,125,106,201,216,29,45,153,175,158,45,165,218,216,106,41,133,38,130,218,169,241,27,198,
142,53,144,109,189,193,26,48,82,174,126,222,160,141,81,57,190,145,54,108,28,203,99,191,68,68,71,69,226,142,232,207,17,243,31,196,62,127,183,172,5,247,43,218,78,100,246,222,240,155,200,141,198,197,35,17,
21,202,14,198,244,89,56,248,114,12,2,173,130,126,18,71,85,183,236,71,212,87,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,116,239,130,192,230,119,62,99,27,128,219,
216,186,252,222,111,47,89,13,6,47,17,139,165,154,183,35,144,172,157,130,69,77,73,75,78,143,52,210,185,63,64,63,199,233,237,185,101,138,8,222,105,164,84,137,69,73,38,128,15,82,79,74,45,45,46,175,238,96,
178,177,182,146,107,201,88,42,34,41,119,118,38,129,85,84,18,204,78,0,0,147,214,200,95,2,127,151,245,31,68,208,209,246,199,114,226,104,171,187,138,181,76,155,127,1,80,96,200,80,117,189,28,139,196,250,144,
203,77,62,238,169,66,117,202,165,214,141,78,136,206,178,204,113,211,220,31,112,27,121,47,179,108,147,145,180,131,71,144,96,204,127,132,127,194,199,228,91,207,24,61,101,251,171,125,213,163,228,81,111,238,
15,185,123,106,63,59,26,53,165,155,133,117,177,92,17,52,163,42,110,154,189,138,106,32,25,203,156,89,61,116,218,153,174,214,189,239,245,102,212,111,125,71,252,79,184,164,40,80,7,93,1,70,98,42,73,44,79,
219,210,86,174,91,155,15,246,38,215,252,223,250,240,120,255,0,31,118,2,131,61,40,18,129,228,122,105,149,205,216,92,129,200,231,234,111,254,195,252,125,190,20,121,175,90,121,129,168,7,172,46,197,64,35,
150,252,40,224,255,0,77,76,1,250,251,81,26,156,154,99,162,233,165,0,105,235,1,244,130,77,191,218,141,190,167,142,7,245,191,181,177,199,192,1,209,21,220,245,36,215,168,82,191,248,27,146,110,77,254,183,
253,35,240,109,236,206,40,169,142,131,23,115,228,130,122,105,157,254,163,233,248,39,241,168,90,237,253,45,127,102,144,198,1,29,4,239,39,4,147,92,116,205,51,130,109,244,177,177,252,127,75,127,82,71,179,
20,81,129,229,208,122,105,106,105,212,54,55,185,181,238,56,31,139,17,98,111,123,11,123,124,98,158,157,36,53,52,21,160,234,225,63,151,222,250,242,109,154,204,36,146,183,220,99,167,167,172,141,53,114,86,
3,252,58,168,254,125,90,22,34,127,222,125,225,63,222,31,98,48,111,171,124,139,250,82,131,145,234,192,56,254,117,29,99,207,50,216,45,159,50,243,21,144,29,178,149,184,79,178,65,221,79,177,171,213,140,124,
143,219,94,109,151,176,190,66,224,160,121,114,221,47,81,252,47,121,165,40,255,0,41,202,117,78,229,171,142,10,182,43,26,179,76,118,166,102,160,77,102,253,52,242,155,16,1,247,20,242,29,226,115,23,46,239,
222,221,94,184,23,168,134,91,98,220,8,7,86,145,233,165,177,249,245,20,71,63,238,78,101,138,226,74,139,107,131,70,207,227,24,175,251,117,251,50,180,232,98,233,109,239,8,154,148,197,82,178,83,87,69,4,244,
211,163,222,41,162,158,36,150,57,80,131,98,146,196,192,143,245,253,194,27,165,156,219,109,219,182,130,178,35,16,192,241,4,18,8,252,141,71,66,142,100,219,150,230,31,18,60,173,42,15,200,244,107,106,178,
111,79,85,75,91,37,228,198,85,161,166,173,75,221,26,158,161,76,83,35,11,242,26,39,97,236,182,119,154,127,212,169,214,50,191,34,50,63,159,81,212,118,145,203,12,182,164,126,170,215,249,117,155,249,92,111,
8,118,254,219,238,159,140,121,105,132,59,143,163,187,63,63,93,134,162,144,145,37,103,92,239,186,217,51,187,99,41,70,15,18,80,71,44,210,194,8,253,62,155,254,161,239,181,31,118,46,115,182,230,175,110,54,
216,214,112,215,48,162,146,60,232,194,135,253,229,195,41,244,61,65,62,236,237,114,65,187,217,239,10,135,193,185,132,41,62,94,36,120,32,252,200,161,249,249,117,107,131,253,123,251,200,254,162,126,189,239,
221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,
221,123,175,123,247,94,235,255,211,223,227,223,186,247,94,247,238,189,208,75,222,93,225,214,127,28,122,175,121,119,63,111,238,106,93,165,215,219,19,19,46,95,61,151,170,87,150,77,8,86,58,92,126,54,142,
32,106,50,121,140,165,91,164,20,148,176,134,150,121,228,85,81,207,180,183,151,144,88,219,201,117,115,38,152,144,84,250,252,128,30,100,249,116,107,178,108,187,151,49,110,182,91,46,207,106,211,110,23,14,
21,20,122,159,50,124,148,12,146,112,0,175,84,163,7,243,220,146,147,56,153,77,209,240,119,190,240,157,79,91,4,117,212,27,138,143,57,178,179,125,141,6,6,102,242,83,238,76,215,82,210,100,19,113,99,232,106,
104,136,155,237,149,164,172,141,79,40,79,30,193,3,159,237,62,164,196,246,132,39,160,96,95,237,35,135,229,94,178,66,95,186,199,52,174,210,151,240,111,182,175,114,127,14,137,22,34,222,106,179,17,164,154,
227,81,1,122,185,111,143,127,36,122,91,229,63,91,226,187,95,162,247,222,35,125,236,220,160,241,61,86,61,222,44,142,27,37,24,255,0,43,193,110,76,53,74,197,148,219,217,236,124,151,73,233,42,162,142,88,216,
30,8,231,216,214,202,254,215,113,132,79,105,48,100,243,245,7,208,143,35,214,59,115,15,46,111,92,173,185,207,180,239,182,15,111,122,135,131,12,48,242,100,110,14,167,201,148,144,122,28,189,172,232,143,175,
123,247,94,235,222,253,215,186,97,221,27,155,111,108,221,189,155,221,123,179,53,141,219,155,103,110,98,171,115,89,236,246,102,174,42,12,78,35,19,142,129,234,171,178,57,10,217,217,33,166,165,165,167,137,
153,157,152,0,7,182,229,150,56,99,121,37,112,177,168,169,39,128,30,189,63,109,111,61,229,196,22,182,176,180,151,50,48,85,85,4,179,49,52,0,1,146,73,192,167,90,89,252,200,249,23,179,254,83,247,200,249,19,
142,217,148,248,46,160,196,86,189,95,199,29,131,53,35,83,229,59,211,122,98,228,147,26,62,78,246,118,42,68,11,141,219,20,136,154,54,245,35,42,201,145,72,227,169,153,88,128,199,29,249,178,255,0,101,77,234,
247,126,179,219,99,77,218,104,196,97,194,128,238,138,77,29,254,121,199,153,20,235,167,63,119,191,101,247,91,13,174,24,183,137,153,166,168,55,14,73,43,2,96,253,44,38,189,205,196,202,124,137,42,40,7,65,
215,77,116,190,231,236,221,209,54,226,220,34,124,158,71,41,84,213,181,213,115,106,115,44,243,201,173,216,106,253,10,15,233,31,64,61,199,52,154,242,98,7,116,140,114,122,203,14,101,230,29,175,148,246,193,
111,3,42,42,10,0,63,203,213,174,65,211,187,71,173,182,67,214,101,224,164,141,214,144,190,153,209,53,95,199,253,77,253,136,27,106,134,202,208,203,113,77,84,235,24,255,0,174,219,199,51,239,201,109,96,238,
99,215,76,125,189,81,255,0,201,12,118,43,63,147,201,214,226,96,137,22,57,164,100,241,139,106,64,90,226,192,114,44,1,246,27,137,200,125,64,208,87,172,193,216,118,235,136,54,123,99,59,31,28,40,53,243,232,
108,254,93,95,41,42,246,54,229,155,161,183,222,106,69,216,155,218,177,6,2,163,33,49,241,109,61,218,196,71,141,202,210,201,43,90,158,150,182,96,180,213,138,8,86,70,73,15,42,72,132,189,232,246,254,45,231,
111,254,177,237,150,163,247,172,11,221,164,102,68,25,42,105,196,249,161,226,14,7,26,117,138,222,251,114,12,123,101,228,28,253,177,217,4,183,118,209,120,136,59,117,49,196,180,24,1,178,15,1,171,237,234,
31,243,77,217,146,236,127,145,159,28,254,66,69,79,246,116,187,178,151,33,210,253,135,82,17,188,67,41,66,26,109,191,45,107,219,198,5,85,4,172,177,18,121,20,252,125,125,219,238,207,189,139,206,91,230,206,
76,153,201,150,214,69,186,128,127,194,228,237,112,43,252,47,66,222,132,244,79,236,246,238,187,118,241,28,6,81,244,230,85,117,206,52,72,52,48,242,160,7,73,63,103,68,111,184,232,172,148,53,33,64,17,179,
163,27,15,193,184,4,130,56,39,222,75,236,142,89,101,140,253,191,228,235,36,57,170,26,120,50,17,195,7,160,54,150,86,31,224,75,2,62,182,3,243,111,169,30,207,153,64,94,61,16,216,189,40,1,207,75,76,100,228,
21,228,144,64,224,253,7,63,208,123,42,185,143,211,203,161,125,139,130,7,217,208,157,131,174,208,84,19,249,183,245,255,0,31,205,237,115,236,142,230,48,79,14,143,33,98,0,232,102,193,228,8,241,221,128,42,
117,113,111,167,230,192,125,125,161,80,43,67,196,116,243,10,130,15,14,133,204,38,80,54,145,171,233,107,255,0,75,145,253,45,237,206,7,207,162,123,168,0,173,58,18,113,153,75,42,139,146,15,39,155,114,9,250,
147,99,193,252,251,112,26,244,65,115,107,170,180,29,43,233,178,87,181,220,19,254,28,255,0,190,227,218,132,148,240,166,122,35,158,204,112,211,211,180,121,19,253,79,250,215,177,252,125,13,253,169,73,138,
140,244,129,173,5,41,76,117,148,100,108,57,102,210,79,224,255,0,176,255,0,95,221,132,245,249,30,155,22,139,198,153,233,155,61,69,132,221,56,108,142,221,220,184,140,102,227,219,185,122,119,164,203,224,
179,216,250,124,174,35,39,76,223,170,10,218,10,200,229,166,158,63,200,212,164,130,46,57,247,100,186,150,9,22,88,102,100,153,77,85,148,208,143,176,140,244,221,214,211,101,184,90,207,99,184,89,199,61,140,
162,143,28,138,25,24,127,73,72,32,252,188,199,151,84,17,243,23,249,30,245,230,255,0,170,203,111,159,138,185,186,62,179,220,149,77,45,108,221,95,184,30,121,118,21,117,65,83,35,197,183,50,168,179,228,54,
195,76,194,203,4,171,61,48,99,193,141,125,201,27,23,185,19,67,162,219,124,136,201,29,63,181,90,106,31,233,215,129,199,152,161,249,117,137,190,227,125,212,54,253,204,220,110,190,221,222,45,165,217,171,
27,57,137,240,73,227,72,101,201,79,64,174,10,250,48,235,93,238,234,248,125,242,83,227,230,70,174,135,181,122,127,121,109,218,122,70,96,115,208,226,231,204,109,105,209,127,221,212,219,151,16,181,184,121,
98,63,227,48,97,249,3,220,165,183,239,91,86,235,26,201,97,125,28,149,242,4,106,252,212,228,126,206,176,215,153,253,191,231,62,77,184,146,223,153,57,110,238,215,73,248,218,54,49,159,154,202,181,70,7,200,
134,232,181,216,142,15,6,246,32,216,16,127,196,126,61,154,116,14,235,175,126,235,221,115,72,228,145,210,40,209,164,146,70,84,142,56,193,119,119,99,101,68,69,187,51,49,54,0,114,79,191,117,238,61,30,239,
143,31,203,167,228,159,200,26,154,10,232,54,133,95,94,236,106,135,141,234,247,214,251,166,168,195,80,45,25,36,201,54,39,19,58,197,151,206,204,17,78,133,134,49,27,27,3,34,142,125,132,55,238,120,229,253,
129,28,77,118,37,187,3,17,70,67,49,62,132,140,47,231,251,58,157,61,180,251,186,251,161,238,124,246,242,109,91,19,217,236,76,70,171,219,165,104,160,85,243,43,168,6,152,211,33,98,86,39,212,86,189,108,33,
241,131,224,255,0,76,124,77,166,151,39,182,163,168,222,93,137,85,76,105,178,61,137,185,41,169,255,0,136,195,76,223,231,232,118,221,4,97,233,240,20,50,183,235,40,77,68,170,0,121,8,227,220,3,205,60,241,
187,243,48,16,72,4,27,109,106,34,66,123,189,11,183,226,63,47,132,122,117,212,143,100,126,237,188,143,236,223,251,180,180,102,220,249,197,151,73,189,153,0,240,129,226,182,177,100,66,15,3,33,38,86,24,212,
162,163,163,49,95,91,235,118,189,255,0,216,158,45,107,113,244,252,255,0,188,123,4,105,225,214,78,192,7,231,235,210,66,174,77,90,201,102,189,137,185,55,184,252,127,175,238,244,205,7,70,10,222,131,29,49,
84,49,107,17,200,210,111,99,254,242,77,248,3,253,239,219,200,15,3,142,189,226,113,7,135,77,166,66,111,96,196,143,173,237,167,240,111,249,183,7,219,233,27,26,31,46,147,73,112,22,170,58,194,125,55,36,147,
123,2,223,155,31,210,23,252,45,237,106,32,28,58,39,184,186,57,234,44,146,131,127,199,28,47,6,194,228,95,250,6,246,186,40,56,19,199,160,253,205,201,206,122,109,149,248,231,142,45,99,193,0,243,244,31,155,
123,50,137,50,49,208,114,242,231,20,7,166,106,137,47,244,31,235,88,127,183,191,31,67,236,198,37,160,39,207,160,205,212,162,191,46,155,29,245,6,7,250,139,125,127,28,251,88,128,129,145,209,81,53,53,39,174,
32,107,183,22,107,90,194,199,211,201,191,28,127,176,247,110,171,76,244,111,190,28,111,175,238,143,99,83,208,212,203,166,143,35,40,129,195,29,43,226,175,181,36,198,247,23,241,212,248,154,255,0,139,159,
112,119,190,91,7,239,110,92,23,112,173,101,136,31,47,53,238,31,202,163,168,175,220,139,1,13,222,195,191,40,253,50,198,218,95,146,190,99,39,228,13,71,236,235,100,78,149,220,116,57,24,43,118,182,106,150,
159,43,135,204,99,234,241,89,108,85,90,135,167,201,226,114,84,210,81,100,232,37,141,174,165,106,105,101,112,63,42,214,35,233,239,159,215,55,183,156,173,189,216,115,45,144,172,246,238,9,3,241,33,248,211,
243,28,62,99,168,47,155,118,145,44,82,234,36,30,32,142,42,192,213,91,242,61,22,236,102,214,203,116,15,98,230,250,107,37,89,37,101,14,2,58,125,203,214,25,169,152,153,55,55,87,229,230,145,177,18,153,15,
166,76,134,219,169,213,65,86,163,244,180,96,155,2,61,141,253,200,218,172,119,24,246,254,111,217,192,109,171,114,140,49,35,130,200,69,72,52,199,112,63,180,17,210,206,82,221,255,0,127,109,18,90,220,45,47,
160,37,28,30,32,143,242,121,143,145,234,192,54,118,114,155,115,237,209,78,206,60,230,27,45,254,169,42,129,253,127,171,15,245,253,194,140,140,130,180,4,15,46,131,91,165,171,109,247,222,32,94,202,244,80,
251,175,117,111,223,141,189,165,177,62,94,245,197,35,86,85,236,132,139,100,119,46,219,141,217,19,119,245,221,101,74,125,183,223,160,4,55,217,185,49,199,57,4,193,55,137,174,2,251,201,239,187,47,185,247,
92,151,204,71,105,19,19,28,172,210,196,132,246,186,255,0,163,65,254,152,129,226,70,0,248,133,125,122,36,230,46,95,180,230,29,174,125,182,230,130,57,70,168,223,248,36,28,24,127,148,121,131,214,194,157,
77,217,219,87,185,250,227,103,246,142,201,173,21,251,99,122,225,40,243,120,185,120,18,197,29,76,99,205,71,84,128,159,21,101,13,66,188,50,175,246,100,67,239,175,251,70,233,105,189,109,182,91,173,139,234,
181,158,48,202,126,222,32,252,193,168,35,200,142,177,7,115,219,174,118,155,251,189,186,241,52,220,66,229,79,229,230,62,68,100,124,186,17,61,152,244,135,175,123,247,94,235,222,253,215,186,247,191,117,238,
189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,255,212,223,227,223,186,247,94,
247,238,189,213,22,127,57,44,216,220,251,195,225,111,68,212,167,220,237,236,255,0,102,239,14,231,221,184,233,212,53,14,82,151,165,182,194,101,54,213,13,84,108,74,84,66,55,70,86,25,154,54,5,127,104,31,
113,255,0,62,222,24,45,173,98,95,32,242,31,246,171,65,252,207,89,63,247,97,217,226,187,230,45,239,116,148,102,40,99,137,79,152,241,158,143,79,67,161,72,198,115,213,50,247,215,198,77,249,135,194,210,246,
146,86,228,83,45,151,150,76,191,241,186,42,153,162,171,138,166,118,53,4,137,163,96,254,52,45,96,47,96,56,181,189,227,156,246,215,214,202,151,179,131,73,77,107,90,210,185,235,168,28,177,238,31,43,243,61,
220,252,171,225,70,162,221,124,53,66,5,8,92,125,149,232,180,116,71,200,190,240,248,203,220,148,29,195,211,147,67,134,237,8,101,72,119,214,195,158,102,196,245,183,201,61,183,1,180,248,13,231,65,1,74,12,
102,250,90,117,39,25,156,142,49,81,20,246,89,11,33,62,197,188,183,205,119,91,101,212,111,226,226,160,26,240,35,209,189,65,245,226,56,142,163,111,121,125,138,217,185,179,103,185,130,123,126,213,82,98,149,
69,100,129,178,67,33,165,74,87,226,67,218,69,105,67,214,218,255,0,27,63,155,7,195,159,144,212,88,156,85,111,100,99,250,87,181,170,41,169,151,55,211,189,217,60,93,127,188,49,25,137,17,69,78,55,31,54,121,
168,176,251,166,158,58,139,172,53,56,233,231,142,116,179,11,18,84,79,187,119,52,109,59,132,113,145,114,177,204,70,85,141,63,99,124,39,246,245,203,142,109,246,127,158,249,66,226,101,186,217,101,184,176,
82,116,205,10,153,17,151,200,157,53,101,168,201,12,5,58,177,196,203,226,158,142,44,138,100,241,237,65,52,107,44,53,203,91,76,212,114,196,227,82,73,29,72,147,194,241,186,155,130,24,130,61,159,248,145,208,
54,177,167,237,29,70,126,28,154,204,102,54,241,43,194,134,191,179,143,73,61,239,218,61,115,214,219,51,61,216,155,243,123,237,125,167,177,118,197,12,249,44,254,235,206,102,168,104,112,152,170,58,116,50,
73,45,85,116,179,120,131,21,22,84,23,119,107,42,130,72,30,218,154,234,218,222,39,158,105,213,98,81,146,72,167,250,190,92,122,87,103,182,110,59,141,228,27,125,141,148,178,223,74,193,81,21,73,102,39,20,
2,159,207,128,243,235,84,79,156,159,57,51,31,58,167,146,142,150,29,203,182,126,18,227,107,149,118,39,90,213,193,89,183,119,143,203,189,201,137,171,105,97,222,187,230,3,225,202,224,62,63,226,170,163,86,
165,199,200,35,151,57,34,7,144,8,236,4,53,206,92,228,36,83,20,70,150,223,133,13,65,114,63,19,249,133,244,95,62,61,116,43,238,251,247,121,147,111,150,61,223,121,141,78,244,63,180,151,138,90,41,31,217,198,
120,53,193,31,19,138,132,6,128,215,61,0,221,93,209,251,135,179,55,42,110,77,203,31,146,162,173,169,209,99,138,157,105,232,49,244,52,200,145,80,226,241,116,113,129,13,14,47,31,74,139,20,16,70,2,70,138,
0,247,14,143,170,220,110,89,216,150,102,57,61,102,62,255,0,205,91,71,38,237,11,182,109,90,82,40,146,128,15,95,50,79,153,39,36,156,245,109,27,39,102,236,206,156,219,103,33,92,105,227,158,24,67,1,32,69,
44,200,53,31,173,137,231,139,123,23,89,218,90,237,16,25,166,63,169,214,36,239,219,230,251,207,59,161,182,182,12,98,45,229,254,30,171,151,228,247,201,122,189,213,93,89,136,198,84,8,177,208,179,196,170,
142,84,50,129,166,237,107,0,63,167,176,182,229,184,75,185,76,79,8,135,14,178,123,218,191,107,173,246,11,88,111,175,35,213,116,115,158,63,111,85,171,158,220,112,185,153,106,100,215,229,212,9,39,146,77,
255,0,31,94,65,227,218,30,24,167,83,235,205,26,70,99,167,217,209,111,200,203,45,30,122,42,218,57,140,50,195,80,147,197,42,177,83,27,171,234,12,89,109,199,54,60,253,61,170,208,146,219,52,82,45,81,133,15,
207,160,134,237,97,101,185,218,95,109,151,209,120,150,55,17,178,58,159,53,96,65,167,204,96,131,228,64,61,94,63,101,99,162,254,96,63,203,171,176,113,59,126,56,43,123,171,171,54,230,35,51,89,140,242,23,
175,168,220,123,18,63,226,56,29,207,142,34,243,200,185,204,93,28,144,72,71,63,114,165,15,235,30,241,95,106,133,253,165,247,155,102,220,110,9,94,93,191,153,162,44,7,104,75,142,214,70,166,59,31,75,15,145,
249,117,128,23,86,23,254,218,115,194,236,27,200,43,110,36,62,12,135,225,146,7,52,86,7,134,42,43,232,65,243,234,156,49,27,142,62,209,233,188,38,228,64,195,35,21,24,161,204,83,189,132,212,217,156,90,173,
37,116,51,41,245,36,158,72,238,111,249,39,222,100,164,127,67,186,201,11,17,161,178,190,132,28,143,246,62,93,102,100,119,95,191,121,106,214,241,72,105,148,105,127,244,202,40,79,230,40,126,117,232,19,134,
241,179,198,120,210,196,125,65,55,28,114,63,199,250,251,17,183,117,0,225,208,86,213,138,73,79,83,210,158,134,125,58,69,192,54,191,208,155,255,0,190,183,180,51,173,71,12,116,47,219,228,200,175,75,156,101,
88,70,191,34,230,196,114,71,211,241,254,210,125,146,203,29,106,60,199,66,104,88,176,0,250,116,40,225,178,64,24,200,123,90,215,6,228,146,126,128,125,109,236,174,84,163,83,207,165,106,65,20,166,122,20,177,
25,111,210,85,249,254,210,221,64,255,0,92,11,254,111,237,189,68,98,157,55,44,97,134,71,66,78,51,47,112,165,88,2,120,34,247,189,173,114,1,28,112,125,236,53,14,146,122,42,158,219,38,131,165,173,38,84,16,
6,190,8,3,147,245,63,239,99,219,186,133,122,43,146,216,121,142,148,17,100,9,80,67,253,126,188,243,97,254,60,125,79,187,171,145,80,56,116,95,37,158,77,23,29,74,251,255,0,167,35,250,127,80,127,31,79,119,
241,60,233,142,147,27,58,126,28,245,197,171,143,245,13,249,185,253,60,139,240,7,62,246,92,84,31,46,189,244,166,180,165,58,194,245,167,159,80,38,215,60,129,254,241,253,61,232,189,64,167,87,22,132,212,1,
143,159,80,106,170,163,169,133,233,106,163,130,170,150,69,34,90,106,200,163,170,164,117,96,3,6,130,161,101,129,131,15,168,42,125,182,28,163,6,70,33,189,65,161,253,163,165,70,213,38,143,194,157,21,224,
60,81,148,58,159,181,88,17,252,186,42,157,131,240,251,226,95,101,213,205,144,222,223,30,186,191,49,146,148,31,38,74,45,189,14,39,32,73,185,44,106,241,45,69,35,49,250,220,251,59,183,230,174,98,179,80,32,
222,39,9,232,78,161,255,0,26,7,160,22,233,236,143,181,124,193,35,77,186,242,14,222,211,183,23,141,26,22,53,226,127,77,148,87,242,252,186,2,165,254,91,159,4,233,170,69,98,124,123,219,111,34,144,194,57,
114,251,146,74,69,35,155,53,17,203,248,28,31,232,65,30,213,73,207,220,213,166,159,189,136,31,233,18,191,241,222,138,161,251,175,251,35,226,137,27,146,181,31,67,113,62,159,216,28,116,40,237,78,128,248,
249,214,95,243,47,250,87,172,246,196,171,165,254,242,131,105,98,165,173,215,24,178,72,213,213,116,243,212,25,35,7,210,218,174,61,144,223,243,30,251,184,15,241,173,226,225,212,255,0,76,168,253,139,65,212,
159,203,126,209,123,103,203,108,143,177,242,6,215,12,160,225,204,11,43,253,186,165,212,126,206,150,185,44,155,50,176,105,25,184,176,23,244,170,129,96,177,142,21,82,223,128,7,176,249,32,84,211,39,143,207,
169,114,40,137,8,60,150,128,15,32,7,0,7,1,242,3,135,72,122,250,223,168,213,255,0,6,228,242,71,209,109,249,176,62,217,36,185,160,232,210,20,160,207,30,145,149,117,101,217,189,92,126,14,175,207,55,63,224,
63,216,91,219,170,2,128,124,250,48,77,40,181,233,61,81,54,161,115,207,215,139,216,15,205,207,224,220,251,186,199,158,29,88,204,180,227,211,92,146,253,127,0,254,63,36,255,0,79,246,254,212,199,7,6,39,29,
36,154,124,154,30,162,200,196,2,90,195,157,65,111,205,207,211,253,115,237,82,71,76,47,14,139,166,185,60,107,195,168,111,33,190,163,248,22,231,232,62,159,75,126,175,167,181,176,197,140,12,116,75,61,205,
42,60,250,129,36,167,235,127,167,3,233,115,248,185,255,0,111,236,194,56,206,7,203,162,27,171,170,106,161,233,170,121,133,207,35,159,171,127,177,252,123,48,137,0,160,167,14,131,183,83,113,30,103,166,169,
94,228,253,7,244,55,227,129,255,0,27,246,181,7,168,199,68,178,190,162,125,58,136,109,115,249,55,254,188,31,79,251,215,31,235,159,110,244,206,107,242,234,68,81,220,142,57,254,191,94,15,63,67,110,125,182,
236,2,241,234,234,165,142,58,87,109,76,140,152,92,254,39,41,19,152,254,210,178,61,110,56,30,41,88,35,147,249,178,220,31,240,181,253,145,239,150,145,238,27,93,245,139,138,235,140,211,237,25,29,36,230,61,
139,247,231,45,238,219,96,4,203,36,68,199,235,226,167,114,83,253,176,3,236,52,235,96,238,146,236,49,144,197,109,205,199,77,56,215,61,60,45,61,155,129,85,2,172,21,145,155,19,200,144,95,253,102,30,249,193,
205,219,11,89,222,95,237,239,29,2,57,167,204,28,130,63,193,246,131,214,55,204,163,118,219,98,184,211,71,101,163,131,197,93,123,88,31,204,30,61,30,110,202,216,41,242,15,173,49,149,219,81,169,97,238,46,
187,53,27,131,172,178,50,184,143,248,194,180,126,77,199,214,185,41,254,191,194,119,109,52,103,237,195,221,98,173,8,195,234,110,155,219,93,230,197,87,114,246,219,152,228,209,182,222,177,107,87,110,17,204,
127,208,235,76,84,209,147,203,85,87,129,234,32,188,123,190,85,222,227,222,237,197,109,106,22,225,7,154,215,18,127,181,173,27,250,60,120,14,129,46,154,236,132,153,104,234,227,51,210,172,141,37,61,109,5,
80,49,213,227,114,52,146,26,124,142,34,190,23,245,83,100,113,117,81,52,51,35,0,193,215,250,31,96,190,98,216,238,118,77,202,238,198,242,34,178,198,197,79,149,71,147,15,232,176,161,31,179,169,51,115,182,
183,222,54,248,174,237,136,120,221,117,2,62,125,25,189,229,75,134,220,88,57,103,172,166,135,43,133,203,209,79,136,220,184,215,10,241,87,226,242,17,152,42,227,149,127,178,66,182,165,111,170,184,4,114,61,
133,99,154,231,111,187,130,107,73,10,93,198,194,72,159,248,93,77,65,31,111,2,60,197,107,199,160,101,156,45,89,108,167,199,240,159,78,179,255,0,42,173,211,153,235,13,249,223,63,14,179,245,117,53,56,125,
143,85,75,217,253,79,53,108,154,221,246,70,234,168,209,89,4,14,199,247,33,74,153,160,147,74,220,44,173,47,211,223,95,190,234,222,224,142,112,229,65,110,242,13,94,24,148,40,252,18,87,68,232,62,66,65,168,
15,45,94,157,64,158,240,236,200,146,109,251,236,73,73,28,152,101,62,172,162,170,127,96,35,242,29,93,143,188,175,234,16,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,
186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,255,213,223,227,223,186,247,94,247,238,189,213,38,127,58,13,139,
158,194,108,158,140,249,113,128,194,87,238,28,119,198,45,245,154,29,177,141,197,195,37,78,74,62,142,237,44,60,123,95,125,238,42,74,104,85,165,169,109,157,83,13,22,69,208,14,41,225,149,191,7,216,39,157,
236,13,197,132,87,64,85,99,212,27,253,43,138,87,236,4,15,245,14,178,35,238,227,204,182,251,63,55,93,109,23,50,132,23,241,168,136,177,160,51,196,218,145,63,219,130,202,62,116,232,0,233,190,234,235,94,203,
217,148,157,91,191,171,241,85,212,115,99,169,235,118,174,228,166,158,41,177,123,147,109,228,161,89,240,185,188,109,80,99,28,244,245,84,174,167,210,78,150,186,155,17,111,112,197,181,213,177,141,182,45,
228,0,80,246,183,145,30,70,189,101,127,53,114,159,48,108,187,154,115,247,37,151,120,101,238,116,94,40,227,226,82,7,3,95,81,209,98,249,23,240,79,106,197,71,81,154,218,57,186,90,186,121,152,207,12,104,233,
229,140,146,74,24,157,24,178,50,143,161,22,63,227,236,143,114,216,77,128,241,173,110,132,144,113,0,113,234,90,246,251,223,123,205,220,199,180,243,46,212,194,65,218,73,24,35,134,69,58,173,45,227,213,219,
247,17,75,252,31,116,96,118,151,104,109,168,53,172,24,174,194,192,211,231,30,141,7,0,99,178,204,169,149,199,218,220,52,82,169,91,113,237,5,174,241,119,107,85,12,79,200,228,117,45,75,203,220,167,204,164,
201,104,230,9,91,142,134,167,237,25,7,160,23,49,181,37,122,115,71,137,216,117,88,10,88,207,166,131,31,218,157,162,49,80,32,184,48,210,226,155,114,253,189,60,55,181,145,64,3,241,236,204,243,37,233,20,82,
1,255,0,87,169,255,0,39,72,163,246,83,98,73,60,105,99,89,73,206,99,139,252,58,43,210,105,54,213,94,66,42,28,116,180,91,163,29,149,219,185,188,102,236,219,116,89,29,239,186,247,159,94,100,243,216,58,129,
81,71,71,186,246,14,236,201,100,112,185,10,42,129,169,22,85,95,36,44,218,133,253,187,15,49,220,80,44,231,84,100,230,152,167,206,149,35,29,33,188,246,127,110,138,70,185,218,96,138,43,208,14,76,104,11,14,
37,53,170,171,128,220,56,245,105,221,79,183,159,177,50,177,111,61,231,52,179,100,114,48,210,212,77,29,113,82,216,248,196,72,201,141,167,140,4,138,158,150,136,157,17,162,42,160,81,244,246,29,44,247,119,
82,52,211,22,207,18,120,138,244,175,153,247,69,216,118,171,109,183,103,179,16,70,35,29,138,41,70,63,21,79,18,107,196,158,142,197,71,102,108,142,177,198,105,166,146,146,57,162,132,42,170,4,22,58,108,47,
111,161,184,246,110,183,182,246,106,22,53,5,253,122,131,87,149,55,238,106,187,38,96,254,25,111,58,244,64,59,211,229,46,71,116,77,53,37,54,73,225,162,140,50,132,73,152,2,164,128,77,148,242,109,249,250,
123,42,185,186,184,189,146,178,183,111,144,234,124,228,143,109,118,190,94,133,39,158,4,107,143,50,71,85,235,186,123,15,207,44,198,57,218,89,29,152,151,50,18,204,110,111,123,251,162,199,90,227,29,74,18,
93,71,12,126,28,116,192,233,19,134,163,206,111,28,156,116,184,248,39,169,150,87,5,86,48,239,195,16,1,99,111,72,228,251,244,207,28,10,90,70,20,232,182,75,157,63,169,52,154,80,122,158,140,198,103,165,54,
23,95,108,41,55,143,109,103,6,5,39,241,197,69,10,6,168,205,102,50,19,29,20,152,61,183,133,135,93,126,111,51,93,49,17,197,12,40,196,179,115,96,61,148,67,121,123,123,119,244,251,114,87,72,171,30,10,170,
50,93,216,225,84,14,36,145,212,123,189,243,132,54,115,19,19,143,5,1,169,168,205,56,241,225,208,179,241,70,131,190,190,46,111,69,238,188,222,63,33,181,51,121,122,72,105,112,221,59,157,153,191,133,175,95,
212,201,231,124,102,251,138,43,163,238,93,193,76,202,228,171,127,184,247,208,44,72,97,238,58,231,203,254,86,231,107,33,203,118,146,37,197,148,44,117,93,47,197,227,12,106,132,255,0,2,48,199,241,249,30,
177,167,220,157,210,223,221,48,160,74,131,233,148,173,187,40,202,249,241,193,53,63,149,120,116,91,187,75,17,176,122,239,228,206,248,192,117,208,150,143,167,254,69,211,207,219,61,123,135,174,95,29,102,
198,222,117,14,233,191,250,199,32,186,68,81,212,97,242,197,218,155,73,43,53,44,144,178,18,9,247,42,242,126,225,184,238,220,165,182,220,110,68,62,241,183,145,111,43,142,18,170,226,41,135,201,210,149,174,
67,6,7,135,67,223,100,121,150,226,231,111,155,150,247,158,221,193,63,73,171,141,78,139,216,217,242,145,49,95,226,92,244,86,119,14,53,177,57,154,202,103,93,3,204,225,5,173,117,46,77,255,0,160,227,220,153,
111,40,154,37,97,233,208,222,234,22,182,187,116,225,70,235,29,20,218,8,31,210,224,3,244,176,54,254,158,233,34,154,100,103,163,91,41,123,129,7,29,43,104,231,32,41,12,47,201,227,240,63,168,255,0,1,236,166,
100,205,71,14,133,86,183,24,29,45,241,121,6,93,37,72,32,21,244,171,27,131,197,207,34,223,78,125,150,75,24,169,206,58,54,141,131,103,241,127,147,161,15,29,148,209,160,234,60,16,47,254,28,155,253,64,191,
22,62,208,16,220,71,30,148,2,24,21,167,75,204,118,105,172,160,61,139,115,249,0,155,220,144,215,184,247,78,211,150,25,233,166,138,160,212,116,180,162,205,173,133,201,185,252,221,173,197,255,0,10,79,3,221,
146,148,233,51,218,131,210,158,155,52,44,44,255,0,78,111,168,255,0,188,15,119,31,203,164,77,100,196,145,229,211,180,89,165,111,172,141,253,57,0,14,120,252,222,223,95,122,173,49,210,115,102,87,240,245,
35,248,168,183,14,0,191,34,247,184,252,250,175,254,30,247,170,184,7,173,125,33,242,31,203,174,15,149,254,174,5,135,224,253,57,231,250,251,245,79,86,91,70,53,1,113,211,124,249,96,127,221,151,181,137,255,
0,95,235,249,183,227,222,139,5,203,26,116,165,44,184,106,29,50,85,229,193,186,171,30,121,250,145,123,31,165,254,150,7,219,38,65,90,171,126,222,151,69,107,145,219,210,106,175,40,89,78,167,80,13,207,215,
139,254,127,175,214,223,79,105,157,137,174,113,209,148,54,99,56,207,73,74,236,153,32,243,114,111,97,200,250,113,99,205,184,255,0,97,237,173,99,135,70,177,65,166,157,35,171,114,37,131,0,215,177,181,239,
207,250,195,252,61,236,41,39,83,113,232,194,56,192,26,143,175,73,42,202,235,234,0,218,215,212,65,60,126,62,135,155,131,238,197,69,71,111,74,197,1,161,233,57,60,252,241,112,121,36,242,75,14,120,2,198,192,
123,125,34,45,229,214,154,85,21,167,77,146,204,72,176,250,127,137,255,0,122,252,155,31,106,22,63,94,146,73,54,147,93,89,234,11,201,193,0,15,241,115,99,253,57,23,191,212,255,0,79,106,150,34,105,167,143,
72,37,184,249,231,168,82,73,197,238,57,32,147,249,231,139,127,177,30,213,164,64,21,175,69,115,92,100,208,245,10,73,110,109,115,164,126,127,223,127,95,107,18,58,10,249,244,79,115,62,154,138,231,166,249,
165,55,111,241,34,220,126,145,207,210,252,243,97,237,108,81,140,99,162,27,137,184,154,244,215,44,159,69,185,176,7,253,183,248,241,192,31,159,107,20,10,142,137,103,145,189,114,122,134,236,88,145,107,94,
192,127,81,244,255,0,111,237,71,14,146,117,197,99,36,130,126,128,139,92,90,196,88,240,62,156,91,253,183,189,54,20,158,189,211,148,73,205,205,238,120,7,243,254,31,208,88,251,76,204,0,200,233,117,188,85,
167,169,233,218,40,129,1,79,209,150,228,125,47,197,136,31,66,57,246,134,73,2,130,124,235,209,229,188,100,21,42,50,58,179,15,135,59,242,76,165,13,126,202,158,97,252,66,4,147,37,140,87,147,215,81,85,65,
2,253,245,44,75,123,151,173,199,1,42,143,203,196,214,185,247,138,30,244,242,234,217,93,195,190,66,159,160,212,87,198,2,177,193,63,233,31,31,99,10,245,141,252,231,179,14,83,231,43,203,125,20,217,183,64,
103,132,211,181,100,53,241,99,244,195,84,253,132,117,110,157,33,217,71,25,81,21,20,242,178,71,44,136,98,113,38,153,32,144,56,208,193,174,8,100,113,193,252,123,197,46,104,217,157,199,212,65,85,145,114,
25,112,67,12,130,8,224,65,243,29,70,252,201,179,120,138,242,170,87,6,162,156,65,20,63,151,78,191,35,250,249,118,245,102,75,228,158,198,166,145,176,181,130,142,126,247,218,184,202,102,154,74,26,211,162,
146,147,184,240,84,112,131,122,71,82,177,103,162,81,112,10,212,0,125,71,220,161,183,95,65,238,231,46,125,59,162,39,63,109,144,129,34,240,23,49,112,18,47,153,173,40,127,133,198,112,71,64,30,86,221,228,
229,139,227,176,238,46,78,203,59,31,5,207,250,27,113,49,154,252,171,167,212,3,230,58,235,100,118,37,35,208,83,106,169,138,179,25,148,166,142,88,100,130,85,158,154,166,9,208,52,53,52,242,2,86,72,165,66,
10,144,127,60,243,238,14,220,246,217,211,198,183,145,25,110,34,36,16,69,10,145,196,26,249,255,0,47,78,135,183,251,80,145,196,240,17,94,32,142,4,121,30,135,175,142,184,244,173,254,97,219,70,167,18,186,
228,219,95,21,50,47,187,222,53,230,157,51,187,150,31,238,189,61,99,47,38,89,33,18,58,43,255,0,103,145,239,60,190,226,22,151,171,38,249,59,43,125,30,185,72,57,166,116,131,242,203,15,207,172,121,247,106,
104,215,151,101,141,136,214,247,195,79,204,168,37,136,255,0,1,234,237,61,244,175,172,107,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,
221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,255,214,223,227,223,186,247,94,247,238,189,212,12,166,51,31,153,199,87,226,114,180,20,121,
76,102,82,142,167,31,145,198,228,41,161,172,161,200,80,86,68,208,85,209,86,210,206,146,67,83,75,85,3,178,73,27,130,172,164,130,45,238,172,170,234,200,234,10,17,66,15,152,234,241,201,36,50,36,177,57,89,
85,129,4,26,16,70,65,7,200,131,192,245,173,119,203,159,228,253,220,189,111,149,203,239,127,128,149,91,127,55,215,21,85,21,57,151,248,183,188,115,51,237,231,216,153,90,134,150,179,39,63,68,111,153,60,209,
96,241,25,9,239,35,96,107,181,210,44,205,104,25,1,176,138,249,159,219,212,190,215,46,220,162,156,66,240,101,249,2,112,87,208,28,252,250,205,63,103,126,245,15,203,209,197,181,115,212,79,60,31,11,79,77,
98,69,224,60,100,227,172,112,241,83,36,83,80,61,84,54,236,238,255,0,150,61,77,87,54,209,238,78,160,239,254,184,201,227,219,197,81,67,185,58,251,63,151,199,122,7,15,73,158,192,83,100,177,117,212,242,1,
117,145,30,204,182,62,226,75,238,86,223,172,221,162,146,55,32,125,163,249,31,243,245,154,219,23,63,251,17,204,209,166,227,101,185,217,197,51,129,130,192,16,79,150,51,251,71,77,216,79,147,146,111,44,92,
211,187,195,150,162,74,153,104,42,39,88,101,134,106,42,232,150,242,208,228,41,170,35,138,166,134,181,20,220,197,42,163,219,241,236,57,115,105,113,4,154,46,17,149,233,231,233,246,240,234,87,218,54,109,
138,236,71,127,177,223,36,144,26,101,24,17,78,154,228,173,139,33,35,84,194,182,142,82,92,1,244,23,230,223,225,97,193,246,200,20,0,117,40,65,85,133,0,106,154,14,163,107,163,167,47,89,84,96,134,58,85,18,
203,83,51,71,12,112,198,183,37,165,150,70,72,227,81,110,75,17,111,123,238,52,69,226,122,212,218,4,111,36,172,2,0,106,196,128,7,204,147,195,169,88,207,150,29,99,128,115,132,135,178,182,149,62,65,73,79,
19,229,80,39,144,139,42,253,192,83,79,123,139,126,162,47,237,241,181,110,129,117,173,140,165,61,64,255,0,37,107,212,85,187,94,114,109,205,233,91,157,234,220,201,94,21,175,159,168,199,243,232,63,236,30,
227,200,229,16,202,153,20,172,134,117,242,67,61,61,74,84,210,200,134,228,73,12,177,51,199,42,145,253,15,182,82,38,212,80,169,14,56,215,136,251,122,18,218,90,237,214,118,233,45,166,134,136,140,50,208,131,
233,66,58,44,121,93,209,146,202,79,37,157,203,63,244,44,120,185,60,91,139,159,107,22,32,160,19,215,164,186,146,78,223,195,208,139,214,125,41,188,251,34,190,21,161,161,153,40,203,94,166,182,117,100,130,
24,185,47,35,72,193,84,34,128,73,55,183,248,251,69,121,184,219,218,43,13,85,111,33,209,62,225,185,90,109,200,100,186,152,6,244,243,61,31,238,129,235,221,199,188,119,85,127,78,252,58,235,104,254,65,246,
238,46,52,167,222,155,201,235,6,43,164,250,170,105,13,188,155,247,176,204,114,209,201,89,11,11,174,51,31,247,21,146,145,164,133,189,253,172,216,185,55,152,57,190,101,99,19,67,101,199,56,98,61,69,104,20,
122,19,249,3,214,60,251,153,239,30,195,202,214,191,83,190,110,30,12,38,190,28,75,221,44,148,254,4,6,167,253,51,81,71,175,71,73,126,22,231,254,25,239,236,79,97,252,198,192,127,179,9,217,125,143,147,254,
7,214,157,219,213,213,135,42,253,103,95,30,42,76,173,86,213,216,61,27,154,142,47,225,216,236,109,52,18,153,178,81,121,107,42,17,46,93,75,1,236,19,239,215,35,115,191,46,109,54,226,195,121,177,180,228,205,
65,94,34,229,62,161,233,90,207,49,163,252,128,167,134,60,199,88,162,125,222,151,220,91,137,211,105,121,32,183,136,85,237,165,24,117,173,3,52,171,138,156,118,240,31,62,167,238,60,78,7,189,40,42,105,182,
15,101,236,93,229,153,129,157,163,196,230,50,195,99,239,53,96,218,76,53,88,29,220,49,211,249,239,125,94,55,145,111,244,54,247,141,214,83,92,114,219,199,38,227,180,220,65,108,104,53,34,248,209,125,170,
241,106,31,103,14,132,91,118,255,0,105,182,72,13,228,19,67,234,52,150,31,145,95,243,116,64,190,73,124,23,239,93,239,176,107,178,116,219,38,45,161,188,122,218,74,141,241,182,119,118,227,221,123,95,7,137,
168,56,122,103,170,171,193,209,79,38,85,159,43,93,155,134,17,21,50,194,164,188,150,83,193,247,44,242,95,185,220,189,181,111,16,196,219,153,155,111,187,164,82,198,145,200,236,165,141,4,132,105,162,132,
63,21,124,190,206,132,214,92,255,0,177,218,239,22,87,214,50,73,173,138,171,176,70,168,21,237,99,231,216,115,95,74,245,92,153,12,189,15,99,108,252,62,254,197,199,162,162,88,254,203,61,68,120,168,197,231,
105,45,22,78,134,170,48,7,142,88,234,21,136,191,213,77,199,188,154,181,13,107,60,150,110,216,173,84,250,169,224,71,218,51,214,88,93,77,22,245,183,90,110,246,204,11,178,210,79,147,83,63,183,136,249,30,
131,232,152,171,126,121,250,223,250,253,72,28,216,243,236,216,40,210,115,210,91,89,40,6,174,35,165,29,45,79,2,236,110,0,2,199,240,126,159,143,169,246,130,88,137,173,70,58,17,90,205,192,3,210,150,150,164,
198,202,71,244,191,31,129,248,231,253,113,236,174,84,4,144,87,29,31,65,54,172,215,184,116,173,161,201,105,208,117,221,72,228,17,127,80,250,223,155,220,145,236,190,88,233,192,103,163,56,216,16,13,5,122,
88,81,101,69,208,51,14,0,26,128,54,22,231,250,255,0,143,180,142,166,134,156,122,82,152,24,94,149,116,185,91,88,234,93,43,97,253,56,111,201,252,219,253,143,182,1,35,135,30,158,40,24,100,119,116,255,0,6,
96,0,182,123,126,110,15,211,234,52,216,126,13,189,251,91,19,156,14,169,244,245,200,21,233,226,28,209,2,222,80,215,176,23,111,248,142,63,63,239,126,239,175,212,116,219,91,231,135,82,255,0,140,250,65,214,
57,255,0,106,191,251,16,47,207,189,107,226,72,20,235,95,79,95,44,117,196,230,133,136,212,220,27,88,91,147,244,22,181,129,246,201,149,136,198,58,112,90,138,208,103,168,146,230,56,63,91,2,110,56,184,35,
131,245,62,232,237,228,199,253,71,165,41,106,1,225,142,154,106,50,160,94,205,98,47,254,181,173,245,250,254,9,246,214,163,196,103,165,113,219,143,62,152,42,242,162,215,18,30,46,9,252,31,246,55,252,31,122,
1,139,2,87,29,42,72,233,196,116,154,171,201,134,4,234,31,235,222,195,243,245,185,63,215,253,127,119,11,66,79,175,74,162,65,90,215,61,39,42,107,139,41,80,126,183,185,230,195,235,248,184,32,216,251,112,
2,105,211,172,194,129,129,6,157,49,205,83,168,242,120,252,15,233,248,185,7,243,253,125,186,145,16,106,56,244,204,146,128,61,15,77,115,206,121,23,250,88,254,63,195,131,254,62,214,164,70,128,1,81,210,22,
184,165,64,225,211,115,201,203,94,246,255,0,137,189,192,183,212,127,79,107,18,26,3,168,228,244,130,91,131,67,83,199,168,210,63,212,127,137,244,243,207,252,83,143,106,21,105,133,29,32,150,122,173,107,78,
162,59,223,234,64,95,169,227,250,130,71,248,146,71,181,10,163,37,120,244,93,52,218,77,43,159,78,162,51,139,106,252,1,96,47,244,54,30,162,63,199,218,148,82,106,91,162,121,92,215,143,77,242,63,4,144,127,
169,255,0,138,1,254,62,213,70,48,77,58,43,157,129,122,14,160,48,189,184,55,255,0,91,243,253,47,253,63,167,183,208,84,227,135,69,178,147,168,212,245,139,69,207,208,30,79,211,142,127,175,228,145,207,183,
89,169,211,93,102,137,13,237,244,252,155,254,15,32,255,0,78,109,237,166,122,231,128,233,232,163,44,120,99,167,88,162,252,91,233,244,32,147,207,227,235,245,62,210,59,249,249,116,117,109,17,192,166,122,
119,137,52,219,243,97,98,120,230,252,31,245,254,190,203,100,112,204,91,203,163,219,104,232,50,61,58,73,226,62,77,213,245,63,200,158,151,235,157,141,132,201,238,237,233,189,119,134,223,196,229,41,182,236,
114,87,228,118,148,185,234,135,163,217,47,246,16,43,189,118,95,114,102,16,194,148,32,9,30,132,77,53,180,173,206,239,189,179,186,231,206,84,230,9,218,220,155,104,34,33,1,192,149,216,119,71,156,228,14,210,
63,24,30,157,98,111,222,139,221,78,85,229,221,199,147,57,12,152,230,230,83,49,184,157,148,247,89,64,203,165,67,83,26,229,36,49,70,248,80,3,196,142,182,50,162,201,182,75,111,226,59,51,110,82,203,77,141,
200,212,84,99,247,30,33,53,121,246,166,239,196,202,212,185,252,29,108,32,121,41,90,10,232,217,163,14,1,104,216,123,231,61,245,132,187,102,235,127,203,91,165,126,178,31,128,145,79,18,35,240,54,124,192,
237,127,70,29,7,118,77,210,13,222,219,233,110,24,27,160,191,42,48,60,24,116,118,58,75,184,5,66,197,71,85,37,52,226,74,89,105,36,167,175,72,234,40,235,232,42,162,48,85,227,178,20,242,234,138,170,142,182,
23,100,146,54,4,16,125,128,229,77,215,148,247,155,93,255,0,98,155,195,191,133,170,15,21,101,63,18,48,243,70,24,97,249,140,142,129,124,213,203,49,73,28,209,203,29,97,99,229,197,72,224,202,124,136,226,58,
9,119,175,72,214,116,78,117,59,55,170,246,190,95,127,124,120,122,230,203,239,174,171,194,187,228,119,223,82,75,44,134,163,35,144,217,148,174,68,185,253,134,238,75,138,85,188,180,107,113,194,128,222,229,
137,34,217,61,227,218,166,187,218,39,75,30,119,141,41,36,77,240,200,87,206,148,169,13,248,93,126,31,196,15,65,189,179,154,55,29,162,54,217,55,89,129,39,16,204,195,181,188,128,99,248,95,212,28,19,145,78,
29,88,23,242,186,192,109,124,246,199,236,15,144,147,111,61,189,188,59,67,188,119,60,217,29,205,75,136,201,82,213,85,236,13,169,131,158,166,131,100,245,253,118,62,57,77,86,30,167,23,140,95,52,240,72,138,
86,105,72,231,77,253,244,151,238,233,201,219,55,40,242,29,132,91,124,241,61,228,136,190,32,86,12,82,149,237,111,61,69,137,102,175,153,235,30,61,214,220,175,110,119,152,182,217,109,164,142,202,216,118,
22,4,9,29,178,242,3,192,130,112,8,60,7,86,165,244,247,144,61,69,157,113,103,68,86,102,96,168,128,179,59,27,34,170,141,69,153,141,148,0,57,39,222,137,0,18,78,58,240,206,7,30,161,227,178,120,236,189,28,
89,12,85,125,30,78,130,160,201,246,245,184,250,152,106,233,38,17,72,208,201,226,168,129,228,134,79,28,177,178,157,36,217,129,31,81,238,177,201,28,168,30,41,21,144,249,130,8,253,163,171,188,111,19,20,145,
10,184,226,8,161,253,157,78,247,126,169,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,
235,221,127,255,215,223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,98,150,56,93,116,205,26,72,132,219,76,138,174,191,67,114,67,130,45,97,239,77,166,157,195,29,108,18,13,65,207,
90,91,252,219,222,125,91,220,31,44,254,82,118,159,85,226,240,176,117,236,213,59,35,163,233,114,216,154,42,106,90,46,194,237,14,175,159,37,81,216,219,230,138,58,100,72,171,105,240,141,144,135,13,247,224,
106,169,146,6,26,153,86,254,241,215,220,91,203,57,239,37,250,104,214,133,192,4,98,186,112,205,246,19,231,231,74,249,245,214,191,185,183,44,243,14,215,203,246,111,187,203,32,132,198,243,20,98,78,136,230,
3,194,67,156,18,7,137,167,200,31,203,162,113,144,174,196,237,156,54,71,53,151,169,135,29,134,195,209,205,93,144,173,148,129,29,61,52,43,119,114,163,151,118,184,8,131,150,98,0,250,251,141,35,142,73,228,
72,163,93,82,177,160,29,103,13,245,237,174,217,103,113,123,119,40,75,72,151,83,19,232,63,202,78,0,245,232,191,229,54,150,123,178,169,33,223,93,153,137,205,211,108,122,196,90,174,190,234,26,58,249,240,
245,57,172,75,29,81,110,190,200,171,166,43,85,4,57,1,102,167,160,77,50,24,205,201,81,245,49,123,181,219,235,107,183,50,27,161,137,103,35,80,83,252,17,142,4,143,51,235,212,43,118,55,94,126,184,123,155,
233,164,180,229,197,63,165,8,36,52,159,210,146,156,73,227,79,46,147,80,110,74,13,179,93,77,77,31,85,245,166,51,7,77,52,104,248,138,109,159,143,147,203,76,26,210,199,81,89,89,28,245,83,146,159,82,205,114,
121,246,138,85,186,157,25,198,233,112,211,122,151,35,63,96,167,229,210,151,228,189,142,40,30,40,172,151,93,48,72,28,126,206,140,143,100,245,111,93,82,237,141,139,184,118,253,21,14,202,161,236,12,189,22,
35,23,143,199,82,206,49,149,123,155,45,79,44,180,84,20,212,209,25,33,161,106,179,3,40,96,22,61,64,3,201,246,85,99,127,127,115,45,202,201,33,149,162,66,73,60,66,3,147,243,165,122,43,216,55,139,93,145,164,
218,238,70,136,90,80,170,5,105,168,146,43,76,208,31,246,122,151,182,58,159,100,108,156,182,47,110,238,12,14,237,237,62,225,205,8,229,219,125,21,213,184,122,173,217,216,153,85,118,211,5,70,67,21,142,73,
34,219,152,183,144,250,171,50,15,4,17,173,201,110,15,181,150,118,187,215,48,202,32,217,237,201,134,191,25,7,79,251,95,226,251,7,231,78,145,243,143,184,251,87,47,67,60,175,184,65,5,170,96,203,35,5,80,71,
16,9,226,71,160,201,242,29,94,15,199,31,229,7,221,157,207,142,161,203,124,202,220,180,221,33,212,117,113,193,81,75,241,87,164,50,173,22,231,202,227,153,18,72,104,59,135,183,169,130,85,187,205,25,2,175,
29,134,17,199,114,209,153,248,191,185,179,149,189,163,179,179,120,175,183,150,50,92,140,208,228,215,228,56,40,253,172,61,65,235,1,125,201,251,211,77,119,36,246,60,151,17,121,9,32,221,76,49,199,140,81,
31,228,207,254,243,214,193,61,63,210,157,81,241,255,0,98,98,58,207,165,246,6,216,235,125,139,130,137,98,198,237,221,169,138,167,198,209,33,224,73,87,84,97,79,62,71,35,80,125,82,212,212,60,179,202,220,
187,147,207,185,154,218,210,218,202,17,13,172,65,34,30,67,252,167,137,251,79,88,129,187,239,59,174,253,125,54,229,188,223,203,115,125,33,169,121,24,177,251,5,120,1,228,5,0,242,29,85,7,201,125,231,55,113,
252,217,27,123,25,48,147,106,124,81,235,234,227,85,58,107,49,75,219,253,167,76,180,84,180,154,255,0,73,169,192,237,208,178,241,202,249,27,223,62,126,250,92,232,151,31,187,121,42,218,64,73,97,172,3,232,
67,189,71,200,5,95,246,221,79,62,213,109,2,199,103,27,140,201,250,151,114,131,159,247,204,71,252,12,213,251,105,209,113,236,206,134,218,77,79,5,78,239,219,152,92,236,147,169,117,168,172,199,195,247,145,
147,234,186,213,166,138,148,97,248,245,143,120,69,183,111,91,206,208,64,219,119,89,225,90,124,42,199,79,251,201,168,254,93,100,37,150,235,107,188,179,198,214,200,218,113,144,15,68,211,182,250,171,175,
241,216,60,102,11,107,109,88,166,222,27,227,115,96,54,78,211,90,154,204,150,77,169,43,179,89,8,34,168,171,161,165,172,170,158,24,164,163,161,14,224,133,58,109,238,70,228,222,100,230,77,211,120,47,184,
110,206,118,187,88,94,121,128,85,77,74,162,138,172,192,84,134,98,7,207,167,55,155,109,187,108,219,39,184,91,88,214,74,96,211,229,209,77,254,99,95,17,113,127,14,251,123,253,42,236,42,84,143,227,119,111,
203,130,218,157,141,139,164,70,52,157,97,219,144,227,162,163,135,114,120,201,101,131,110,111,73,224,105,25,199,17,84,180,128,240,71,188,137,246,87,220,229,231,59,57,185,95,115,148,158,106,219,193,146,
22,63,241,34,222,188,7,153,120,107,66,60,214,148,225,208,223,217,14,126,115,110,54,77,242,78,215,83,67,252,72,13,84,255,0,166,143,131,31,52,251,58,173,125,209,183,230,194,214,200,156,61,60,132,188,50,
163,106,71,141,253,81,178,48,4,20,101,96,65,28,16,125,228,85,172,235,60,107,78,62,125,79,215,86,178,91,79,218,65,141,168,65,28,8,60,8,249,17,195,166,42,121,172,162,228,126,45,244,39,233,199,3,139,123,
114,68,249,227,167,225,151,65,249,116,247,77,83,248,32,2,164,90,255,0,159,245,173,245,250,123,65,52,85,38,135,163,219,121,235,221,211,229,53,80,189,193,23,255,0,94,223,79,173,255,0,199,218,7,139,20,35,
163,152,46,0,21,233,254,154,184,11,106,107,130,1,31,94,13,254,191,215,218,25,33,53,199,14,140,226,148,30,7,61,63,65,146,43,99,174,226,246,83,248,250,14,56,184,176,3,139,251,72,241,249,210,135,165,241,
184,57,60,122,124,167,203,176,3,213,125,36,90,196,126,69,201,227,241,237,59,70,72,166,122,124,16,124,233,211,156,89,115,127,214,9,38,230,228,11,127,183,250,251,96,135,78,28,58,125,98,168,161,165,122,150,
185,133,183,63,95,175,208,91,254,41,244,255,0,31,117,214,222,189,88,67,154,154,117,203,248,194,220,0,205,207,3,233,107,254,77,175,192,183,189,84,144,65,233,209,24,166,105,212,105,115,26,129,80,127,7,234,
88,128,57,231,253,191,186,233,20,207,30,157,88,169,147,211,108,217,70,32,221,184,60,27,31,213,253,65,181,173,127,123,10,160,212,14,157,10,41,129,211,84,217,43,130,110,63,32,222,246,23,250,30,72,184,255,
0,120,247,117,82,196,129,229,213,134,154,138,240,233,150,122,219,155,147,96,56,185,250,31,233,199,212,146,7,227,219,137,29,77,56,158,182,89,84,85,56,244,219,37,77,239,206,160,79,0,127,143,23,250,255,0,
200,189,171,72,8,21,34,132,116,141,230,209,229,158,155,101,168,55,176,228,220,250,110,71,39,235,118,183,227,218,196,134,160,26,227,164,82,77,81,82,216,234,35,73,114,215,177,22,224,240,126,188,243,245,
255,0,123,246,161,99,85,24,29,32,121,177,81,212,119,102,189,192,176,252,223,253,226,223,159,197,253,190,0,20,212,42,122,64,243,143,226,169,235,1,32,16,111,244,191,63,235,91,241,113,253,125,186,170,88,
129,78,144,75,62,162,115,214,9,77,248,250,243,126,7,251,11,223,219,139,219,219,78,238,145,74,224,154,3,159,94,162,74,120,0,88,127,177,230,195,234,0,252,250,189,168,24,29,37,99,83,78,161,191,170,228,3,
111,207,248,127,175,127,241,246,165,105,65,78,29,22,183,196,223,111,81,27,85,248,250,127,75,95,143,161,247,117,109,53,233,59,197,82,72,235,164,70,63,79,175,210,255,0,95,247,142,127,63,235,123,209,36,156,
244,218,70,77,61,58,157,12,118,183,248,253,127,215,250,11,126,109,207,182,164,108,17,209,132,49,106,63,209,233,214,24,173,115,107,253,0,191,211,233,201,55,252,255,0,189,123,67,51,147,218,56,116,117,4,
99,29,5,29,189,218,146,245,245,22,35,1,182,40,105,247,31,107,111,153,167,198,117,246,210,146,111,28,83,212,197,30,170,237,211,184,29,110,216,253,161,182,97,253,250,201,216,0,229,86,36,187,184,30,196,252,
141,201,59,159,62,111,214,187,54,217,9,49,51,128,237,192,40,226,106,78,6,50,73,194,168,36,252,226,15,127,253,246,216,61,131,228,139,157,242,238,104,229,230,139,132,97,99,108,114,75,124,63,81,34,10,159,
10,54,160,81,131,44,128,34,212,6,61,89,143,252,38,127,225,46,218,249,9,242,223,125,124,167,220,217,89,55,198,214,248,113,184,102,251,125,223,87,76,207,23,110,252,182,223,216,137,162,205,111,52,159,81,
134,29,185,212,91,69,141,14,22,153,111,225,146,176,58,128,16,19,147,27,220,123,78,215,21,135,43,114,254,134,218,236,1,215,34,240,158,126,12,235,255,0,11,95,134,58,241,161,99,147,215,25,63,121,239,252,
195,127,187,115,135,53,93,73,47,48,110,114,153,27,89,171,34,158,237,44,77,106,230,181,106,97,79,104,194,245,177,63,204,190,130,202,124,92,237,45,219,242,95,104,96,37,220,223,27,123,106,166,156,124,141,
216,88,186,111,45,102,195,220,21,44,180,201,218,187,122,138,36,177,166,105,164,242,86,104,0,171,179,234,244,200,8,231,255,0,222,127,216,169,185,130,222,78,111,229,160,35,220,161,99,34,145,128,146,31,136,
61,63,208,38,198,175,224,126,238,178,35,219,62,119,107,152,109,118,59,171,141,27,180,31,216,57,63,218,40,207,134,73,252,67,202,167,35,29,21,253,197,215,213,123,74,12,86,255,0,235,188,156,27,175,175,183,
12,9,150,193,231,113,18,137,233,170,104,103,81,34,54,164,39,199,34,134,211,34,53,158,55,4,48,184,247,207,235,45,221,47,100,184,217,183,187,99,109,188,194,74,201,27,138,16,195,210,190,71,200,138,130,50,
15,89,61,180,243,13,150,249,11,90,94,168,142,245,112,65,245,232,125,234,94,238,46,105,161,150,178,108,126,78,158,193,39,89,12,82,40,181,180,57,191,169,91,232,65,4,17,193,246,27,220,182,91,237,170,234,
45,199,107,158,72,110,80,213,100,140,149,101,53,173,65,28,126,195,131,208,127,126,229,148,117,148,60,33,237,91,200,208,143,245,124,250,17,51,125,109,211,187,175,51,253,242,167,194,238,14,167,236,89,72,
45,217,221,21,157,168,235,189,201,88,229,139,153,179,52,120,203,96,179,175,35,155,179,84,83,177,99,249,247,42,114,167,222,23,155,121,122,68,109,210,217,165,153,84,3,61,180,134,25,88,127,77,62,7,62,164,
80,159,78,163,59,174,92,184,72,218,8,103,73,172,235,253,141,202,9,80,127,164,99,222,159,182,157,42,168,101,239,124,28,43,77,128,249,205,216,178,99,21,72,3,127,117,54,201,221,89,136,208,11,40,254,47,78,
244,63,114,235,254,173,192,45,249,247,58,216,253,244,26,24,2,203,184,110,126,45,56,61,172,114,159,247,160,217,232,45,47,34,218,76,218,164,229,75,82,223,240,185,228,65,254,242,71,242,232,183,247,230,79,
123,110,188,94,51,167,227,249,25,222,61,217,219,93,211,148,139,98,236,141,175,21,118,43,174,246,134,63,248,139,172,121,221,225,151,219,187,26,154,44,141,86,223,219,24,191,44,242,45,85,97,167,103,10,174,
27,233,236,211,149,189,238,231,255,0,121,185,146,215,149,182,40,47,211,107,149,169,52,210,178,196,2,147,240,172,81,10,146,70,78,183,26,86,164,131,209,156,60,181,183,242,221,187,239,119,187,93,141,181,
173,186,151,52,6,71,106,112,80,242,26,6,39,2,138,78,113,235,213,240,117,39,92,226,58,139,172,182,39,89,96,185,197,108,125,175,135,219,180,178,250,181,84,156,117,28,112,212,214,190,162,91,201,93,84,30,
102,228,250,156,251,232,222,209,182,195,179,237,150,27,92,31,216,193,18,160,249,208,100,254,102,167,172,106,220,239,230,221,55,11,205,198,115,89,102,144,177,252,248,15,200,80,116,34,251,49,233,15,94,247,
238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,255,208,223,227,223,186,247,94,247,238,
189,215,189,251,175,117,239,126,235,221,85,87,243,104,249,57,187,186,75,162,48,125,73,212,89,15,225,189,241,242,151,113,203,212,93,123,151,75,51,236,140,13,70,58,106,238,200,236,185,134,160,97,139,102,
108,244,168,146,25,15,11,89,36,60,220,123,11,243,86,235,251,187,111,49,163,210,105,170,181,244,90,119,183,236,192,249,158,166,47,100,249,25,121,215,155,226,55,112,235,218,172,66,205,34,231,245,27,80,17,
69,254,221,232,15,244,65,235,86,204,181,46,217,193,65,133,216,251,30,39,166,216,221,127,139,143,108,109,133,144,235,169,200,71,79,35,190,83,113,100,230,55,106,172,190,229,202,73,45,93,76,204,75,187,201,
201,224,123,197,253,210,244,223,93,188,170,79,132,6,149,31,33,254,126,187,141,200,220,182,188,179,203,214,182,142,23,235,102,253,73,72,254,34,5,20,122,42,128,0,29,58,96,186,158,151,181,234,240,120,44,
170,180,248,122,109,197,139,206,100,49,74,138,208,103,23,19,35,84,209,227,43,152,139,138,3,144,241,203,34,243,228,17,5,60,19,237,37,188,239,4,173,225,127,106,202,84,31,225,175,18,62,116,192,244,175,69,
94,225,79,111,251,168,197,115,41,22,234,234,236,190,79,167,33,79,202,180,63,151,86,29,186,126,43,86,182,209,155,114,85,210,106,242,69,229,50,52,54,82,186,70,148,69,181,150,52,80,21,64,224,40,3,218,243,
177,220,195,106,46,63,7,88,245,99,238,221,164,155,210,237,145,184,193,160,2,152,166,58,166,206,244,217,144,225,43,43,66,34,43,197,51,143,211,110,67,30,56,28,88,125,125,150,196,72,96,8,201,235,34,108,231,
23,182,81,204,56,21,175,66,79,98,209,214,231,190,25,236,42,138,108,188,216,76,190,43,178,250,192,226,119,5,52,81,212,213,224,106,42,119,158,63,10,185,122,72,38,62,41,170,232,33,175,105,17,31,208,204,0,
60,123,71,203,168,191,214,179,106,224,52,50,163,161,7,204,17,90,31,217,94,160,190,111,115,102,251,189,212,75,89,33,86,148,10,211,40,11,1,81,90,86,148,173,58,221,23,225,183,193,238,136,248,97,176,215,3,
213,152,105,50,219,183,112,44,89,62,194,238,13,214,98,204,246,111,102,231,170,35,89,107,51,27,159,115,77,25,172,106,105,102,98,105,232,98,100,163,163,140,132,141,56,44,115,39,102,217,54,253,150,214,56,
44,161,81,140,159,51,254,97,242,24,235,146,28,239,207,188,199,207,155,172,187,150,251,120,197,106,116,68,164,136,162,21,52,8,181,165,125,88,141,71,204,249,3,151,107,125,56,246,115,208,47,160,243,182,187,
27,7,212,93,103,190,251,59,114,74,176,225,54,46,215,203,110,74,230,107,254,226,227,169,100,154,26,101,211,207,146,174,165,82,37,255,0,106,113,236,191,117,220,32,218,118,219,237,202,229,128,134,8,153,207,
228,49,251,77,7,75,182,203,9,183,77,194,207,110,183,21,154,105,21,7,230,127,200,51,213,42,252,106,219,217,105,182,124,27,211,118,33,109,233,219,217,252,191,117,239,233,165,7,204,153,61,223,59,84,225,113,
51,23,245,120,240,88,15,12,8,62,139,207,190,36,251,155,205,23,60,231,207,123,246,245,60,132,198,38,104,227,224,64,0,247,17,79,83,79,217,214,93,36,80,237,187,122,90,218,128,18,52,88,163,167,240,168,161,
63,107,26,158,179,119,38,227,139,33,84,244,177,56,49,83,222,52,2,196,92,112,87,243,249,246,6,31,111,67,174,82,219,218,40,132,142,59,154,135,162,219,241,223,0,189,147,242,131,37,188,242,49,137,182,55,198,
157,191,45,84,83,77,115,71,87,218,27,142,23,142,129,17,173,227,150,171,13,72,90,75,125,86,254,228,100,11,203,220,132,89,134,157,203,120,144,31,233,45,188,103,3,236,115,233,246,244,79,207,219,131,92,75,
14,211,3,124,76,23,30,156,91,252,221,43,62,80,141,185,218,27,79,113,245,182,244,198,211,110,29,169,189,41,167,160,220,24,154,128,167,238,105,165,114,209,212,65,33,5,169,242,20,82,5,150,9,87,214,146,40,
35,217,79,38,92,95,236,219,173,190,255,0,182,92,24,119,43,121,3,70,227,200,249,130,63,18,176,237,97,194,157,28,114,197,151,211,188,119,41,85,104,143,105,28,71,251,7,249,140,117,171,163,180,221,121,222,
93,141,240,211,179,179,84,181,219,227,98,67,6,228,233,221,200,236,176,55,99,244,254,90,156,84,225,146,79,39,234,222,27,68,6,164,175,132,18,100,68,89,20,90,246,232,246,197,185,199,204,156,165,179,115,214,
213,110,201,103,114,165,46,99,255,0,124,220,161,43,37,63,225,108,69,84,140,0,115,212,219,237,87,185,107,204,27,214,241,237,167,53,77,20,124,203,108,76,182,15,133,91,171,70,21,240,133,79,246,240,26,209,
56,180,127,13,74,211,166,60,182,30,163,15,86,241,72,135,198,24,128,196,27,159,81,255,0,110,23,216,134,41,82,116,20,61,75,210,68,240,57,141,197,51,212,104,164,228,2,117,88,15,245,191,219,255,0,78,125,213,
144,30,34,135,165,48,202,86,180,110,156,98,152,169,184,31,235,243,112,63,215,3,235,254,191,180,50,161,254,30,141,225,158,160,10,244,233,21,83,43,92,241,244,250,127,94,45,234,28,31,104,222,50,1,52,199,
70,176,220,142,30,93,59,67,90,120,55,32,255,0,81,201,255,0,98,61,166,146,32,212,32,142,140,162,152,208,84,249,116,229,21,113,2,250,141,255,0,36,88,159,245,173,249,227,218,71,136,250,99,231,210,248,164,
6,128,121,117,45,50,54,254,164,139,95,129,254,244,77,238,79,182,12,68,16,71,75,163,148,208,3,212,165,200,177,30,150,184,252,3,199,63,144,47,207,244,246,203,67,169,170,71,74,85,235,231,215,35,145,60,92,
216,254,121,55,255,0,123,184,246,219,64,43,219,90,116,229,71,151,88,141,121,32,130,205,254,242,71,224,128,62,188,113,238,222,17,0,13,61,58,94,148,0,212,245,30,74,182,97,112,79,245,187,88,142,110,57,22,
183,227,221,214,49,157,67,29,120,77,79,62,162,73,82,73,36,48,184,191,248,241,244,252,88,88,123,113,33,4,140,99,166,154,225,70,7,30,155,228,168,102,63,170,214,227,159,161,55,250,142,56,35,250,123,85,28,
39,225,2,128,116,157,238,60,193,234,51,75,113,109,68,11,95,250,115,201,228,219,250,143,106,149,7,19,147,210,25,39,206,191,62,176,25,72,54,6,237,254,54,54,191,212,220,254,61,188,169,80,126,206,144,75,49,
166,79,111,88,75,115,207,55,252,125,0,189,174,108,61,221,86,156,120,244,130,73,205,13,91,183,174,12,109,109,70,246,39,253,230,255,0,214,247,3,221,252,34,194,172,105,210,51,41,169,211,195,172,46,255,0,
211,253,128,252,223,232,56,254,128,123,116,57,29,160,112,233,43,54,126,125,96,99,245,228,88,131,127,207,55,184,255,0,109,237,212,77,57,60,122,104,154,125,189,70,114,53,106,39,235,125,63,239,32,159,110,
14,152,99,165,73,235,1,231,235,115,245,189,253,168,94,2,189,33,60,122,193,162,247,230,203,245,7,242,45,244,255,0,122,191,189,245,174,179,164,96,159,167,212,223,129,245,63,143,169,183,208,251,171,154,12,
30,156,141,53,158,24,234,116,113,128,0,255,0,120,255,0,82,7,248,159,169,246,150,70,226,15,159,70,48,173,8,0,116,26,246,175,109,226,58,186,131,31,65,75,142,168,221,253,137,186,25,232,246,31,92,225,228,
13,155,220,181,231,210,42,234,244,234,24,125,181,143,114,36,173,200,78,22,24,99,4,2,206,66,251,58,229,94,82,222,121,207,118,183,218,182,139,103,118,118,10,88,2,105,95,33,140,159,151,230,113,212,103,239,
31,189,220,157,236,127,44,92,111,156,195,117,28,187,203,196,77,173,158,160,30,67,154,73,47,156,86,235,248,156,138,190,81,1,38,189,19,124,126,222,205,238,172,254,254,163,159,115,77,159,222,135,110,228,
43,254,73,247,94,36,248,177,123,35,109,227,40,42,50,116,221,25,213,83,155,195,141,146,85,79,21,84,144,159,36,16,235,158,118,243,200,129,115,171,151,57,46,195,150,182,77,215,150,121,89,198,171,91,73,37,
221,111,147,34,52,85,212,109,32,110,6,73,91,182,70,7,34,162,186,65,235,133,94,228,251,179,204,28,241,205,150,60,253,238,45,219,220,110,251,157,252,112,109,182,111,141,78,236,85,38,120,241,225,193,4,117,
104,163,160,85,0,19,222,65,235,123,191,248,74,175,77,82,245,119,242,135,234,173,213,22,59,236,42,187,207,176,123,59,182,103,44,167,205,81,69,91,185,38,219,24,102,150,86,1,230,16,227,54,202,34,177,189,
192,184,250,251,133,17,116,151,35,129,56,251,6,58,29,78,218,140,116,225,167,252,36,158,182,46,203,226,49,153,252,94,67,7,155,160,164,202,225,242,244,85,56,236,166,54,186,4,169,163,175,160,172,133,160,
170,164,170,130,80,209,203,4,240,187,43,41,22,32,251,212,208,197,113,20,176,79,24,120,93,74,178,145,80,65,20,32,143,66,58,164,82,201,4,145,205,12,133,101,70,4,17,130,8,200,32,245,71,253,177,241,11,183,
126,27,213,110,13,225,241,139,111,87,119,95,199,109,193,89,85,150,222,159,29,114,85,47,54,225,216,114,72,237,53,70,95,171,170,155,201,37,85,24,140,157,116,132,23,85,22,33,128,213,239,5,189,249,251,170,
89,243,45,121,131,149,60,72,183,8,193,161,140,3,34,47,16,133,106,60,104,133,77,1,58,227,3,182,160,117,62,242,159,184,246,219,155,65,107,190,220,11,109,213,0,11,113,193,36,167,148,156,52,183,244,184,31,
62,139,38,19,112,116,71,112,78,245,253,115,188,224,217,251,198,23,255,0,114,189,109,189,52,109,125,223,137,175,86,34,122,41,49,249,25,41,214,177,162,145,116,234,132,176,54,247,129,27,174,205,207,28,159,
44,150,28,199,178,73,53,170,154,120,241,43,58,83,213,133,53,33,254,139,129,79,83,212,251,183,243,45,212,113,8,47,227,18,64,70,28,119,41,30,181,24,232,120,219,82,238,236,32,20,185,42,38,158,146,21,211,
247,47,34,44,33,7,246,141,67,184,137,80,142,121,107,91,216,34,245,182,235,163,88,102,1,206,104,6,106,62,92,122,173,225,177,156,25,35,125,53,21,167,89,114,157,137,67,184,178,73,176,58,211,13,148,237,190,
203,175,43,28,59,39,175,154,44,132,88,179,35,42,253,230,242,221,106,95,111,109,28,60,13,204,210,212,77,229,211,125,8,205,97,236,109,237,207,179,252,255,0,238,46,233,21,182,193,177,202,45,11,119,92,72,
172,177,129,234,42,5,105,246,128,14,9,232,49,127,187,237,251,20,77,121,185,93,164,86,227,129,99,66,223,37,94,44,79,144,0,252,250,63,191,16,190,27,195,210,21,153,126,215,236,186,250,13,225,223,155,202,
140,82,101,115,84,136,239,129,216,91,121,152,75,14,196,216,105,82,162,104,49,148,220,10,186,194,22,106,249,65,102,178,217,125,245,255,0,217,223,103,118,95,106,182,40,109,96,211,54,242,200,4,178,211,206,
153,11,231,147,196,241,60,56,0,58,198,254,125,231,235,190,111,186,240,97,213,30,207,25,236,79,54,167,7,127,157,56,15,46,143,159,185,159,168,235,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,
221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,191,255,209,223,227,223,186,247,94,247,238,189,215,189,251,175,117,209,54,
31,227,248,255,0,99,199,231,143,207,191,117,238,181,11,254,96,125,219,91,218,223,54,62,73,238,72,231,146,77,189,241,235,3,129,248,173,215,32,202,207,21,22,239,220,16,193,188,187,143,45,69,24,178,67,89,
45,59,210,80,188,171,103,17,161,66,125,192,158,227,238,174,247,55,49,43,16,3,120,75,249,101,207,230,113,215,81,62,230,156,135,12,91,78,217,185,92,67,89,39,45,121,33,167,20,21,72,7,217,134,111,183,170,
242,137,64,96,188,216,91,252,127,228,95,159,246,254,226,30,186,40,236,73,39,163,199,241,47,19,5,118,233,160,242,162,48,89,20,155,175,211,213,201,231,235,123,251,87,182,32,147,112,136,17,141,67,172,120,
247,178,250,75,125,158,235,75,16,116,245,120,29,189,14,62,139,169,86,154,56,225,81,246,10,44,2,139,90,35,202,158,108,15,185,111,120,88,147,103,68,80,62,30,185,233,201,143,115,63,57,180,172,196,254,167,
249,122,213,95,229,41,129,114,57,134,26,66,249,167,183,63,83,173,192,191,211,241,238,28,76,200,52,240,7,174,160,242,208,97,178,90,234,254,15,242,116,239,155,197,84,214,124,81,234,221,165,78,134,92,190,
248,238,62,152,219,152,122,85,26,165,168,174,203,118,78,8,195,20,73,107,150,49,196,198,194,252,15,233,237,55,44,198,215,28,233,8,136,96,22,254,98,159,225,61,66,62,224,93,69,109,99,205,55,82,61,34,75,105,
137,63,100,109,254,94,183,226,197,211,61,30,51,29,73,39,47,75,67,73,76,231,250,188,20,241,196,223,239,43,239,55,80,105,69,95,64,58,227,76,141,170,71,97,192,146,127,159,83,189,219,170,116,65,63,153,210,
85,55,194,190,221,120,132,143,65,1,217,181,59,134,40,148,179,75,182,105,247,190,223,151,58,140,23,253,215,246,10,204,255,0,141,10,111,238,54,247,121,46,159,219,174,104,91,58,248,255,0,79,143,247,161,208,
223,219,147,24,231,45,159,95,197,169,244,255,0,166,40,212,254,125,23,124,230,91,25,183,118,216,173,198,207,12,144,101,241,152,250,140,83,194,84,70,113,211,227,224,106,6,134,192,94,47,181,101,210,69,133,
189,241,29,21,227,82,178,215,197,12,218,171,252,85,58,171,249,215,172,152,219,45,228,220,110,109,212,173,35,143,7,237,28,127,159,85,211,222,157,164,187,43,111,85,101,99,137,242,25,252,149,66,98,118,166,
30,31,221,173,203,238,10,243,224,162,134,24,64,47,32,138,105,21,154,192,243,97,249,246,39,229,94,94,147,152,247,136,172,207,109,146,15,18,105,15,194,145,174,90,167,213,134,0,252,250,148,222,88,182,141,
189,166,36,107,34,139,95,90,121,252,128,207,70,99,171,246,76,157,13,209,155,111,174,114,76,167,123,230,77,70,251,237,106,244,114,210,213,111,13,193,254,89,61,12,243,131,121,6,30,149,210,156,11,250,116,
17,237,71,55,239,9,190,239,146,189,152,166,223,21,34,133,124,132,105,218,41,246,241,249,241,234,44,177,141,247,61,198,125,210,76,171,29,49,253,149,203,127,182,63,203,162,237,151,172,254,242,238,161,121,
63,201,34,152,201,60,142,125,16,209,82,169,154,166,119,39,232,145,193,25,98,109,192,7,217,141,172,127,71,101,145,223,167,31,105,224,62,218,145,212,163,18,174,223,183,179,182,14,158,171,83,249,166,255,
0,44,252,167,200,63,229,189,178,191,152,174,194,199,102,49,157,207,241,203,178,59,35,183,50,85,187,97,219,31,189,51,223,26,50,185,133,130,166,183,9,80,160,53,78,111,175,147,22,153,234,10,119,6,42,154,
81,83,11,93,89,71,190,171,251,7,203,209,236,254,217,108,22,123,157,189,96,159,83,200,190,101,100,52,175,249,127,62,176,211,220,157,242,240,243,180,215,59,85,235,67,184,90,42,120,82,41,33,163,149,59,170,
8,200,32,159,46,169,211,165,254,73,225,187,70,131,107,236,158,212,168,196,98,59,23,113,99,82,125,145,188,232,45,30,195,238,220,100,80,3,30,111,105,228,73,16,226,119,91,196,160,228,48,85,12,181,48,84,7,
241,135,79,162,142,116,246,235,117,228,217,19,114,177,86,184,229,153,234,241,74,185,1,107,192,211,248,120,48,61,200,65,12,58,206,191,97,190,243,92,183,238,197,180,28,165,205,247,49,216,123,151,8,17,144,
212,72,174,200,92,58,49,194,74,244,174,147,219,41,58,163,53,36,1,103,49,131,171,196,78,241,201,28,158,48,199,146,165,89,127,162,145,112,84,95,216,54,57,150,101,13,92,245,146,115,91,75,108,236,178,33,4,
30,154,16,128,56,54,39,143,200,35,252,79,31,227,238,228,3,196,117,104,229,34,158,189,77,142,99,127,169,31,79,234,65,63,67,201,22,23,30,211,60,70,159,46,140,98,159,200,241,234,108,115,16,77,255,0,31,239,
28,14,63,199,145,237,33,132,0,77,51,209,140,87,36,82,167,169,203,80,88,11,27,255,0,79,245,192,252,143,205,239,254,30,211,50,211,136,199,70,113,221,96,209,179,212,132,168,97,193,60,18,44,0,189,254,164,
223,159,167,30,217,120,195,228,140,244,97,28,252,59,171,214,115,80,79,209,135,250,194,247,63,128,121,36,251,103,192,34,180,53,62,93,42,142,226,152,39,174,254,224,220,122,135,250,230,227,253,228,251,111,
194,106,112,233,79,143,243,207,93,249,254,190,161,96,126,129,191,31,139,115,200,247,239,0,211,43,215,188,102,226,15,92,90,114,24,115,200,254,134,231,159,160,63,239,62,236,145,48,60,49,213,26,110,57,235,
19,76,223,129,254,60,254,71,3,233,199,62,222,88,133,65,61,50,103,4,252,250,192,100,0,94,228,243,200,230,228,241,99,127,241,246,161,82,184,3,29,38,146,98,9,169,235,11,73,123,3,244,254,188,125,127,167,187,
132,42,64,35,143,73,30,96,181,212,105,214,54,112,151,83,199,208,241,245,250,255,0,196,223,221,130,53,120,227,164,50,207,82,8,235,25,148,158,69,254,182,23,31,81,198,175,167,251,11,123,116,13,4,212,84,244,
149,228,169,193,175,88,222,75,92,222,203,254,31,236,126,191,237,189,186,84,177,30,75,210,114,245,243,235,9,144,125,1,36,216,254,71,63,235,106,250,242,125,220,42,138,99,61,84,184,244,235,19,200,63,169,
54,63,79,197,255,0,192,216,92,123,112,41,62,93,37,121,64,248,78,122,192,88,158,79,211,146,79,63,158,125,186,16,14,60,122,97,164,102,226,113,214,50,227,144,62,163,243,248,247,110,155,235,146,175,251,193,
22,231,253,226,223,211,241,239,221,111,169,176,198,9,176,5,185,23,31,83,207,0,1,253,79,180,238,114,73,233,116,49,177,8,138,42,231,203,215,160,67,126,247,60,248,221,195,39,90,245,86,30,147,127,246,179,
65,228,200,82,189,87,135,103,245,197,28,195,246,179,125,139,152,128,73,246,130,254,168,113,176,222,182,174,214,1,22,237,238,64,246,255,0,219,14,97,247,19,113,75,107,27,118,75,16,65,121,14,6,154,228,146,
112,171,78,44,127,42,245,140,254,255,0,253,234,121,47,216,235,9,236,44,229,135,113,231,114,164,8,85,131,71,108,196,118,153,180,147,226,73,82,8,183,92,227,189,128,193,38,43,184,164,109,233,156,216,187,
51,119,212,110,94,218,222,84,117,147,118,231,200,202,154,21,16,195,138,196,77,13,62,75,98,245,45,61,229,162,162,139,20,106,214,158,36,128,154,122,35,170,73,12,181,3,140,192,229,157,175,102,229,193,23,
32,242,36,168,183,146,43,139,173,196,12,232,65,250,177,218,215,36,228,134,146,181,99,215,33,249,195,152,121,167,220,13,222,247,220,191,115,46,38,185,184,146,68,120,173,92,254,38,32,70,211,143,132,5,20,
240,225,3,74,40,165,42,7,67,214,238,168,193,117,71,195,78,244,162,219,244,145,98,104,33,216,25,76,6,45,34,185,152,228,55,35,46,51,238,106,103,118,51,213,100,107,39,171,105,37,153,203,73,36,140,88,155,
159,114,142,252,182,28,181,237,119,51,89,237,241,8,237,140,113,194,163,205,140,175,70,102,60,89,136,6,172,115,147,229,212,15,53,189,239,48,123,195,200,211,222,49,146,72,158,107,130,124,148,67,17,208,160,
112,10,25,133,7,174,120,245,244,159,254,82,189,71,91,209,63,203,75,225,47,85,100,168,205,6,71,106,252,123,216,63,127,72,84,171,67,91,155,198,255,0,120,234,149,129,228,59,79,151,98,215,230,231,222,34,70,
59,23,61,101,52,228,25,158,130,128,26,126,204,117,98,30,239,211,61,122,195,223,186,247,69,175,182,190,31,124,103,239,42,211,149,236,238,156,217,187,143,52,215,45,159,24,243,137,207,200,230,223,185,54,
107,13,37,6,70,162,65,110,26,73,24,143,199,176,206,241,201,188,177,191,51,62,235,178,193,44,172,50,197,104,199,237,34,132,254,125,8,54,190,105,230,29,153,68,123,118,237,52,113,15,195,90,175,228,173,80,
63,46,129,58,63,229,135,240,218,142,104,152,117,190,98,170,150,41,86,79,225,85,253,129,190,171,177,82,4,32,136,165,162,169,207,200,146,64,64,177,67,197,189,133,35,246,99,219,72,231,23,11,202,182,230,64,
124,193,63,225,39,163,183,247,43,156,89,116,254,245,167,204,34,3,251,116,244,113,58,247,171,186,235,169,240,81,237,158,181,217,91,111,100,96,162,33,191,134,237,204,85,38,50,25,164,23,30,106,183,130,53,
154,182,160,131,99,36,205,35,145,249,247,33,216,109,155,126,213,2,219,109,182,81,65,110,63,10,40,81,252,134,127,62,130,23,187,133,254,229,49,184,220,47,36,154,111,86,98,127,101,120,125,131,29,47,61,174,
233,31,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,
186,247,95,255,210,223,227,223,186,247,94,247,238,189,215,189,251,175,116,215,155,204,99,182,246,31,45,158,203,213,67,67,138,194,99,43,242,249,58,218,135,17,211,210,99,241,180,210,86,86,85,79,43,89,99,
138,10,120,153,152,159,160,30,233,36,139,20,111,35,154,34,130,79,216,58,114,24,164,158,104,160,133,75,74,236,21,64,226,73,52,3,243,61,104,93,151,222,146,111,13,171,187,59,155,34,39,255,0,140,251,221,189,
219,242,10,26,112,135,204,155,91,39,184,39,195,237,169,244,19,169,218,179,13,136,19,39,227,67,11,113,239,22,57,178,224,221,223,196,53,119,59,51,127,189,53,7,93,197,251,187,236,171,203,156,165,56,145,78,
155,59,56,32,106,12,214,52,47,32,31,97,39,31,46,147,52,21,212,249,42,58,44,141,12,169,81,71,95,77,5,101,29,76,103,84,117,20,149,81,172,145,72,167,232,3,41,255,0,111,113,248,246,18,101,49,187,35,138,50,
154,30,178,34,9,225,186,183,130,230,221,195,65,42,6,82,60,213,133,65,253,157,31,31,138,57,56,168,183,13,59,59,1,167,69,143,208,219,88,254,188,115,237,253,165,196,87,177,177,225,94,177,247,222,155,54,185,
218,229,80,9,168,61,90,167,110,239,200,42,54,17,167,242,2,22,141,135,234,254,145,145,244,60,11,251,144,55,123,245,123,5,64,222,93,97,159,36,242,244,177,243,31,140,87,58,253,62,125,107,69,242,74,160,229,
247,16,198,64,117,77,146,202,36,8,1,4,159,36,224,114,163,242,65,247,27,171,248,106,242,122,2,122,232,54,222,223,69,178,68,91,130,167,249,58,177,191,132,253,19,85,223,255,0,50,190,51,117,146,67,228,216,
63,21,176,148,255,0,35,187,94,64,11,83,157,202,96,155,9,212,123,109,142,146,134,178,171,51,36,217,18,141,200,130,151,80,252,31,99,31,104,54,54,220,119,139,157,218,84,253,20,108,125,128,215,249,146,7,229,
214,16,253,229,57,206,62,95,228,205,194,198,57,63,221,142,230,230,36,0,228,33,204,141,246,105,237,251,79,91,132,123,202,126,185,169,215,189,251,175,116,151,222,187,59,111,118,22,209,220,155,31,118,99,
161,203,109,173,217,133,200,109,252,238,54,160,94,42,204,102,82,154,74,74,184,79,250,150,49,200,74,159,168,96,15,227,218,107,219,59,125,194,210,230,202,234,48,246,210,161,70,83,230,172,40,71,243,233,69,
165,212,246,55,86,247,150,178,20,184,137,195,41,244,42,106,15,90,230,238,169,51,191,30,104,183,247,71,119,54,116,173,71,66,61,37,94,203,221,213,210,159,247,253,116,126,126,106,136,246,77,116,58,200,122,
220,214,222,158,19,139,157,22,239,174,48,27,128,61,242,15,222,223,105,55,94,78,247,20,109,187,93,155,73,107,184,179,52,97,70,3,113,215,253,21,101,169,115,92,48,62,189,102,151,183,252,197,183,238,214,169,
185,173,22,57,80,151,95,52,153,71,234,40,249,53,117,47,219,210,35,227,30,197,175,236,237,214,223,43,59,83,15,53,14,206,218,115,79,75,241,247,102,229,99,49,140,206,88,27,73,190,42,233,164,0,212,210,227,
136,13,11,144,82,74,147,117,184,140,123,14,239,211,89,242,78,201,253,84,218,110,67,238,247,0,27,201,84,228,99,251,32,125,61,124,233,246,245,125,255,0,116,155,123,189,27,109,171,82,17,241,208,252,9,95,
132,255,0,73,188,253,6,58,25,59,79,121,206,99,174,121,170,76,153,12,156,146,201,59,220,23,62,102,37,137,99,205,238,126,190,192,251,53,139,77,50,205,32,237,95,203,161,38,197,183,166,168,85,82,145,39,1,
246,116,4,80,109,92,238,239,77,189,215,91,93,38,59,223,189,55,12,29,109,183,102,68,103,108,70,6,167,252,167,127,238,214,210,53,37,54,3,108,172,196,191,211,201,34,143,175,185,115,219,206,85,186,231,174,
121,216,249,126,221,107,110,178,44,178,154,84,5,6,162,163,242,213,159,225,233,174,120,223,173,246,125,182,234,230,71,253,40,99,46,69,120,158,8,163,230,205,65,214,202,11,212,27,57,58,102,78,139,76,116,
35,98,203,215,147,117,163,99,228,134,41,162,109,189,83,128,147,111,77,28,144,202,26,57,153,233,37,102,33,133,153,143,190,188,89,217,65,99,99,109,97,108,129,109,226,140,34,143,64,162,131,172,13,186,188,
154,242,246,123,233,216,153,228,144,185,63,50,107,215,202,115,126,252,66,201,244,70,27,187,122,184,109,186,189,239,75,208,63,32,59,31,164,59,167,165,218,164,193,147,108,166,206,206,77,144,217,125,203,
212,89,67,42,85,109,125,237,148,217,53,244,53,146,209,197,42,65,92,232,90,38,73,71,174,116,229,13,164,223,114,37,198,227,109,107,251,195,109,75,134,138,251,111,111,140,29,58,146,238,205,243,166,64,154,
131,199,64,27,79,152,38,144,151,49,115,76,182,30,231,142,87,220,27,232,110,37,178,75,173,183,113,76,47,197,166,91,59,165,197,81,94,141,20,128,146,3,154,148,101,5,158,122,235,228,6,236,218,187,66,142,183,
43,62,99,228,95,76,82,200,104,78,250,196,210,105,238,238,180,134,153,188,83,97,123,31,103,188,113,84,238,167,194,33,11,53,68,43,22,73,21,73,146,25,56,99,6,243,143,177,11,113,105,55,53,123,115,122,46,182,
154,159,18,45,52,146,22,254,25,99,4,180,100,100,18,42,190,120,235,160,158,205,125,247,247,78,93,123,46,68,247,183,110,146,117,80,169,13,226,176,50,248,120,0,171,183,109,204,99,136,86,101,148,12,85,168,
42,104,240,25,109,161,216,56,8,55,143,92,238,92,86,237,219,149,96,180,121,12,61,74,206,33,147,141,116,121,26,99,106,172,101,116,22,180,144,206,145,202,140,8,43,127,120,241,113,29,205,148,237,109,127,110,
209,78,56,134,20,253,158,70,191,46,186,59,177,111,123,7,54,109,81,239,220,169,188,193,127,180,56,7,92,77,82,181,252,50,39,199,27,15,48,192,124,170,51,215,101,29,46,140,172,164,112,111,113,96,63,160,39,
144,109,239,84,7,62,93,27,44,154,40,173,215,37,44,57,31,225,127,169,35,250,127,135,186,21,82,78,51,210,136,229,34,153,37,122,144,179,219,240,110,79,214,252,255,0,176,63,83,111,105,154,47,150,58,93,29,
197,105,221,67,212,180,154,214,26,129,91,142,15,4,112,62,159,81,245,246,157,227,52,249,116,186,43,157,38,189,101,18,133,23,212,84,131,249,231,143,192,226,255,0,143,109,24,152,154,40,7,165,169,121,82,61,
58,230,38,97,233,244,158,110,47,110,127,167,63,145,237,189,36,26,83,165,11,116,180,249,245,217,152,158,8,23,31,225,192,63,128,13,207,191,21,62,157,56,46,87,248,250,239,204,252,128,45,107,125,127,199,155,
131,245,255,0,91,223,130,3,74,245,83,114,61,122,226,206,79,213,172,191,94,126,191,239,124,143,119,85,24,162,231,166,30,230,153,7,29,98,50,47,245,213,244,22,250,127,128,36,88,219,235,237,208,131,128,193,
233,137,46,141,5,56,117,192,200,220,216,133,31,225,102,224,127,143,7,235,237,245,69,197,56,244,145,166,12,13,79,88,11,173,201,36,147,248,55,252,31,193,28,125,61,220,41,245,233,134,148,147,215,19,49,177,
28,95,253,224,253,109,244,31,95,118,11,156,12,244,195,76,163,207,246,117,131,200,77,255,0,39,250,255,0,173,97,244,252,123,112,71,234,122,97,167,38,186,70,58,198,101,31,234,175,207,227,155,159,233,127,
197,253,184,21,71,151,73,218,90,241,110,176,153,127,192,159,245,255,0,22,31,235,255,0,135,187,116,193,154,163,2,157,113,212,110,65,34,192,92,0,111,126,71,54,31,212,31,126,167,77,248,140,107,83,142,187,
91,94,255,0,226,8,63,142,63,28,126,61,248,130,60,186,186,57,175,115,99,166,61,213,188,182,150,194,196,73,159,222,187,147,19,182,112,241,141,2,183,45,84,148,226,166,114,125,52,212,48,22,53,89,10,201,15,
165,97,133,29,220,144,0,39,219,182,246,183,119,178,172,22,118,239,44,167,20,81,83,254,97,249,244,91,191,243,55,46,242,150,220,219,199,52,111,118,246,27,96,4,235,153,130,234,167,146,47,197,35,124,148,30,
139,54,233,236,205,243,191,113,53,153,85,173,172,248,237,209,144,6,254,41,216,123,159,197,139,237,29,229,68,70,149,164,217,248,74,165,144,236,234,44,146,217,82,170,161,31,37,42,176,240,194,140,65,247,
145,220,141,236,62,155,104,185,151,220,59,165,177,216,148,131,165,240,210,121,128,136,123,157,143,236,30,90,186,230,207,189,223,126,45,219,124,146,239,146,189,147,178,154,54,122,163,221,10,125,67,41,193,
37,199,109,172,68,87,0,153,8,193,97,195,160,23,60,185,108,159,89,111,12,39,79,96,179,61,69,213,116,184,28,246,69,107,100,134,162,155,179,187,115,50,40,38,151,248,150,82,182,188,203,154,196,97,234,228,
67,228,158,165,142,70,180,57,3,195,31,214,124,186,183,186,186,229,157,210,215,149,108,95,105,229,24,109,157,133,86,151,55,172,6,11,249,172,94,96,84,84,98,157,96,221,146,195,14,253,103,119,204,247,195,
115,230,153,166,21,37,171,13,182,162,73,210,73,238,148,215,44,106,107,154,143,52,158,58,178,147,22,191,25,119,198,42,150,155,31,182,107,112,114,236,122,245,162,141,33,160,199,212,238,252,85,45,78,58,70,
84,5,35,74,156,214,53,162,214,220,188,210,114,110,125,166,130,104,44,207,182,91,228,17,44,118,47,3,91,62,145,64,26,64,69,77,60,217,171,90,249,244,109,42,189,200,231,29,174,71,213,116,37,19,37,73,53,8,
1,0,124,148,0,40,56,126,222,142,143,250,57,147,186,178,223,24,126,58,164,111,83,39,200,111,151,125,33,215,181,148,118,45,247,24,63,239,60,57,61,192,39,67,250,169,97,198,211,59,200,8,176,11,207,179,175,
119,110,90,215,146,237,44,131,81,174,47,64,252,163,67,95,216,92,126,125,2,57,14,222,59,207,112,174,175,72,4,90,237,255,0,179,198,144,127,132,70,107,242,235,234,237,132,196,209,224,48,184,140,22,62,53,
138,131,11,139,160,196,208,196,170,21,98,163,198,210,69,71,77,26,170,240,170,144,194,160,1,192,183,188,111,24,0,117,54,19,82,73,227,211,167,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,
247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,
247,191,117,238,189,239,221,123,175,255,211,223,227,223,186,247,94,247,238,189,215,189,251,175,117,83,159,206,75,182,179,27,51,226,29,127,81,108,172,155,99,187,31,229,54,239,192,244,14,214,146,158,111,
21,109,54,27,117,77,231,236,108,204,37,74,186,69,134,216,52,149,239,35,130,2,107,23,35,143,97,126,109,189,250,77,169,226,86,163,204,116,255,0,181,226,223,200,83,243,234,99,246,43,150,7,49,243,254,220,
243,67,174,202,200,25,223,211,82,226,37,63,233,164,43,251,58,213,235,180,55,6,223,195,215,10,12,68,80,195,180,54,86,31,27,178,54,181,24,0,83,140,6,219,163,76,93,58,172,99,211,166,172,66,93,172,61,69,207,
245,247,139,187,133,201,187,189,154,101,52,0,209,126,193,195,174,227,242,142,213,31,45,114,189,149,172,233,250,206,190,36,159,54,124,144,125,112,105,158,137,223,84,246,28,123,87,119,85,245,86,225,155,
236,240,249,106,186,156,207,86,228,42,223,68,115,98,171,170,36,157,246,201,119,62,129,77,84,238,41,175,199,246,7,227,218,235,187,111,173,180,143,113,128,86,85,20,148,121,212,99,87,249,250,14,114,214,248,
187,22,247,115,201,251,163,233,180,145,140,150,46,120,104,114,91,193,169,225,67,93,31,154,245,98,93,93,187,164,219,153,56,101,14,209,233,113,125,68,43,41,67,205,239,192,228,253,61,144,2,99,113,40,110,
141,121,207,99,27,173,164,136,82,164,15,216,122,52,219,207,187,219,33,183,154,155,238,111,251,4,31,88,176,244,31,246,43,254,199,218,185,183,9,37,65,29,49,212,49,178,123,125,244,187,137,159,193,167,117,
122,173,122,74,156,38,107,176,115,123,223,118,85,71,77,180,122,235,19,95,186,243,117,82,21,17,197,14,61,26,113,168,176,177,98,170,66,143,237,49,31,215,217,77,241,151,68,86,150,224,248,211,56,85,3,206,
189,72,124,205,112,44,118,196,183,67,66,216,252,135,30,182,128,254,74,61,17,185,118,79,199,189,219,242,55,177,49,213,24,158,195,249,123,186,233,251,67,248,45,92,126,58,141,179,214,24,202,22,195,117,70,
223,146,57,17,102,130,113,183,75,86,74,132,219,85,88,54,6,254,242,167,219,205,129,118,29,130,222,61,61,238,7,230,7,153,255,0,76,73,63,101,58,228,23,222,31,157,34,230,190,122,150,206,202,64,219,126,220,
166,21,34,180,105,43,89,8,249,84,0,62,195,213,194,83,238,28,21,94,74,175,13,77,153,197,84,102,104,12,98,191,19,14,70,142,76,157,23,150,49,44,95,119,64,147,26,186,127,36,44,25,117,160,212,166,227,143,99,
117,184,129,228,120,86,100,51,47,21,168,168,251,71,17,212,18,208,78,177,172,205,11,8,155,131,80,208,253,135,129,233,194,166,174,150,142,51,53,93,76,20,209,40,36,201,81,52,112,70,2,242,196,188,172,138,
2,143,175,62,220,103,84,21,118,0,124,241,213,21,89,141,21,73,63,46,136,31,200,47,230,81,241,187,163,38,155,109,98,243,243,119,15,104,200,255,0,109,141,235,78,171,11,185,115,19,215,185,11,21,54,71,35,68,
42,49,184,165,46,108,218,157,229,67,245,143,220,115,205,94,233,242,159,43,67,55,141,126,179,221,160,63,167,27,3,74,127,27,147,161,7,173,77,126,93,13,246,31,111,185,135,124,11,59,91,253,54,223,196,203,
47,104,167,168,7,39,249,15,159,85,123,185,186,163,179,126,86,246,174,43,228,79,205,74,12,54,202,219,24,108,120,161,216,159,30,176,51,153,51,178,96,162,173,147,39,143,160,222,185,20,96,209,81,203,89,57,
158,169,100,62,121,77,212,36,73,239,158,94,238,123,247,55,52,223,200,251,112,67,112,168,99,71,81,217,18,18,73,8,78,93,235,197,206,61,49,212,233,203,219,85,182,197,183,182,207,203,140,242,22,109,82,92,
56,198,170,0,74,142,21,166,7,151,169,39,161,71,178,123,42,145,76,99,69,61,13,21,5,36,116,24,92,38,62,56,233,232,177,212,20,200,177,210,81,82,82,196,22,40,41,97,137,64,10,160,112,61,227,93,181,165,206,
227,49,150,66,77,90,165,137,201,175,19,95,94,164,13,151,100,49,70,176,194,164,154,213,152,228,146,120,146,124,207,69,91,204,119,78,70,191,45,153,174,131,15,183,240,244,181,89,124,246,110,190,79,29,6,19,
11,68,141,53,101,109,68,132,133,33,34,75,42,143,83,177,10,46,79,177,122,197,244,209,37,181,180,69,174,28,133,69,28,89,206,0,31,225,39,133,7,67,89,230,131,102,178,45,74,191,0,60,201,60,5,62,222,172,239,
249,118,116,246,67,63,146,203,252,166,221,91,117,246,254,43,63,183,41,118,79,64,109,236,148,114,46,83,25,214,144,204,106,114,219,231,35,77,61,219,29,154,236,140,130,36,250,5,157,40,163,69,62,150,30,250,
67,247,114,246,201,121,71,97,28,197,184,109,201,14,245,123,10,106,32,179,22,199,116,135,85,74,235,192,10,40,2,140,14,238,177,7,221,126,106,59,141,231,238,56,46,140,139,28,133,230,62,90,248,44,96,142,34,
33,94,63,136,252,186,182,34,46,45,239,38,122,134,250,209,155,249,210,244,100,253,67,252,205,123,67,53,137,162,52,91,63,230,79,199,29,175,220,148,162,20,88,105,100,238,62,128,202,199,178,55,163,211,71,
24,10,249,60,166,199,203,99,170,106,27,245,201,227,212,111,107,251,153,253,145,220,158,29,235,124,217,11,82,59,155,111,21,69,127,209,33,32,212,124,244,150,234,20,247,190,194,33,101,201,252,203,225,254,
165,165,247,211,57,60,60,43,161,166,135,254,110,44,116,31,111,90,231,119,229,4,155,58,44,38,254,234,233,223,106,119,6,232,223,219,55,102,83,84,99,80,156,86,244,25,204,138,81,205,77,188,182,234,1,79,159,
74,26,45,114,253,194,170,86,68,136,116,203,107,143,99,110,121,128,108,159,67,204,60,187,43,90,115,53,197,220,112,214,51,68,156,55,196,38,143,225,114,49,154,3,147,92,154,244,199,40,220,201,186,11,205,155,
126,84,186,229,184,109,30,82,36,21,120,74,252,38,57,43,169,1,26,187,107,65,65,67,65,78,146,230,187,107,97,187,34,179,17,185,167,172,248,201,242,1,224,166,173,125,241,176,50,17,201,176,55,221,45,68,210,
82,210,101,50,148,181,48,157,183,146,165,201,85,68,201,246,185,170,120,106,196,128,162,74,77,155,216,67,153,118,14,72,230,155,171,142,95,247,3,102,139,105,230,154,3,227,198,71,211,200,79,194,245,24,77,
94,117,211,156,106,232,121,200,92,241,238,39,32,53,183,56,251,75,205,119,55,59,72,44,60,60,172,234,23,226,141,212,138,76,23,133,10,177,167,225,166,122,30,163,237,46,221,216,241,42,118,223,95,199,217,155,
109,0,120,251,75,164,232,205,70,69,105,116,143,242,205,203,214,85,19,201,144,140,216,234,121,49,83,85,68,121,33,7,211,220,13,206,95,119,78,103,216,21,239,185,125,197,238,215,66,65,67,172,17,242,165,72,
199,218,62,125,103,95,181,223,222,7,177,238,77,22,209,238,174,204,214,251,133,66,181,204,42,34,122,129,147,36,38,136,217,254,3,25,62,157,10,91,55,176,250,243,178,105,205,78,192,222,152,93,198,200,47,83,
139,130,163,236,247,6,61,215,245,195,147,219,217,1,77,152,160,158,38,225,210,72,65,7,220,9,121,97,127,182,204,208,110,54,82,67,32,245,6,159,145,235,60,185,79,158,185,51,158,44,226,189,228,222,103,180,
190,133,151,86,133,117,89,148,127,78,39,33,129,251,53,116,175,117,120,152,135,12,172,63,213,169,95,169,3,128,69,249,246,142,138,223,103,67,2,89,14,153,16,171,124,199,94,242,88,91,244,146,127,216,255,0,
172,8,231,235,239,66,58,3,94,29,58,179,21,52,168,235,40,148,254,111,244,177,23,227,234,127,222,239,237,150,133,64,170,241,233,74,220,10,240,167,93,172,163,250,125,63,34,192,253,47,207,231,221,10,116,250,
220,10,225,186,201,229,4,127,182,227,85,172,71,244,184,252,219,221,12,90,136,167,78,137,207,30,35,174,245,165,191,180,62,182,26,190,191,237,249,31,79,126,16,149,57,225,214,188,115,229,215,31,40,0,16,8,
2,223,210,231,241,127,201,252,123,184,138,167,34,167,166,154,122,26,22,235,137,155,253,185,252,125,79,215,234,69,128,31,235,254,61,184,35,63,194,58,104,220,169,243,61,98,50,175,215,142,47,249,254,191,
211,241,237,193,29,14,79,76,153,205,58,193,229,7,243,245,63,208,159,245,254,156,241,254,183,187,5,3,128,207,73,222,110,21,106,245,196,202,223,217,244,243,115,200,31,224,15,63,91,31,247,159,119,210,222,
157,48,102,52,199,88,28,216,144,91,253,107,115,254,195,139,0,65,247,189,6,157,54,100,99,231,215,29,66,224,129,249,250,31,201,250,15,241,247,113,31,175,84,36,129,94,189,118,39,72,6,230,222,149,227,254,
77,23,99,244,247,188,40,168,29,84,18,72,10,42,79,231,210,63,122,246,30,199,235,154,31,226,27,227,116,225,246,221,59,16,41,161,173,169,86,201,215,202,72,9,79,139,195,193,229,202,100,234,229,115,165,34,
134,39,118,39,218,155,75,27,205,202,84,130,202,217,228,148,158,0,127,151,135,65,206,103,231,30,85,228,171,25,55,14,107,223,173,172,109,148,86,142,227,196,111,146,68,9,145,137,242,162,211,231,208,83,55,
100,246,158,241,199,85,100,54,62,199,131,171,182,116,112,53,67,118,191,123,134,194,66,104,237,168,215,97,58,238,41,224,205,86,122,61,81,190,70,90,24,5,174,215,28,123,157,249,79,238,249,204,219,188,9,186,
115,20,233,183,108,131,38,73,142,133,167,28,19,150,252,135,231,214,6,251,149,253,224,124,185,183,79,62,195,237,86,193,38,229,190,84,170,202,234,36,43,253,33,10,246,143,42,25,92,211,205,79,64,38,10,92,
94,75,112,190,233,217,244,57,79,145,29,135,75,174,31,244,233,217,236,184,174,175,219,85,55,101,104,54,14,26,24,154,9,96,165,99,233,76,69,51,22,250,61,93,249,247,61,114,127,47,114,223,47,33,183,228,30,
94,27,149,250,97,175,238,71,135,105,27,87,38,53,61,210,48,245,205,79,15,94,176,103,159,57,211,157,253,194,220,155,121,247,79,155,102,133,164,225,105,19,248,151,5,120,133,37,72,72,87,128,210,138,0,31,60,
116,44,237,78,147,203,238,76,236,27,215,177,115,149,221,137,186,233,75,79,65,91,150,132,82,237,157,182,239,115,227,218,59,86,54,147,29,140,42,56,21,50,121,171,24,11,180,190,228,125,191,148,100,184,189,
77,231,152,47,159,114,222,69,52,180,131,244,98,249,69,23,0,7,145,97,94,24,234,49,221,57,202,203,108,179,109,171,100,181,75,29,189,184,162,127,104,254,166,71,226,73,243,161,252,205,122,20,179,84,84,24,
152,94,58,173,50,187,35,35,163,128,222,69,112,85,209,129,225,131,43,16,127,22,246,41,157,81,42,178,128,192,138,16,124,193,20,32,252,136,199,65,237,186,226,230,249,196,144,213,64,32,131,232,65,173,127,
104,232,153,226,49,180,93,89,22,226,218,27,235,13,252,107,161,115,249,26,165,196,230,81,223,195,180,105,179,117,63,117,38,219,207,84,70,26,163,110,12,118,77,252,248,108,176,2,24,36,10,140,200,84,106,136,
77,173,183,46,69,125,203,156,195,11,55,39,93,72,76,19,140,136,25,137,58,36,60,99,42,217,71,165,1,206,65,35,169,114,89,230,223,62,151,113,218,174,68,92,209,2,2,200,105,250,154,124,212,112,144,30,14,156,
74,154,113,80,122,185,31,228,159,210,217,14,224,254,111,255,0,19,182,172,251,146,46,195,235,175,141,61,107,216,191,36,198,118,92,113,164,206,82,214,87,226,164,217,251,22,159,121,52,50,205,135,175,203,
65,151,157,90,42,202,81,26,84,166,167,42,172,125,128,189,201,186,220,86,231,102,216,111,119,104,175,109,109,226,241,34,149,69,28,172,148,167,140,65,42,206,2,129,169,120,140,156,244,107,201,22,246,239,
30,251,189,141,158,75,45,198,121,124,41,163,102,213,25,104,170,11,67,80,25,99,109,68,233,106,80,215,175,164,207,184,235,161,143,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,
238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,
238,189,215,189,251,175,117,255,212,223,227,223,186,247,94,247,238,189,215,189,251,175,117,171,103,243,59,237,44,191,104,252,233,207,237,172,52,130,171,108,252,54,232,104,194,36,68,188,71,183,59,249,254,
221,234,88,220,162,87,96,54,77,1,81,198,164,21,7,250,251,133,253,202,220,216,60,209,35,118,68,129,120,254,39,227,249,129,142,186,17,247,61,229,75,52,138,215,118,220,40,173,127,120,105,81,159,10,220,2,
0,249,51,159,63,78,168,87,178,114,241,212,229,232,240,213,51,120,113,244,145,205,145,203,206,88,40,142,134,134,39,170,172,150,67,244,7,199,17,183,230,231,220,43,10,51,97,62,50,64,31,50,127,213,94,186,
99,187,221,69,226,1,43,105,181,69,46,199,209,20,18,126,93,117,71,209,24,77,231,214,51,103,55,229,43,210,239,78,206,106,93,215,183,50,81,6,76,143,93,109,58,37,145,54,86,63,26,46,166,25,106,233,109,87,86,
183,30,79,42,223,145,236,242,107,246,219,37,183,181,183,161,72,199,120,254,50,120,215,168,183,101,229,184,185,234,223,120,223,119,103,100,146,225,233,110,192,230,20,143,251,61,60,48,56,154,113,233,45,
182,59,143,115,117,108,209,109,94,217,138,163,112,209,83,84,199,139,194,118,14,217,134,76,132,149,182,87,241,211,103,49,72,62,245,171,18,20,185,120,213,152,128,111,123,95,219,50,88,218,238,122,165,219,
95,68,148,171,70,216,167,169,7,135,70,246,156,207,186,114,186,195,181,243,164,77,113,107,93,17,93,196,53,234,198,22,68,248,181,1,230,51,235,209,130,29,167,182,55,14,6,174,179,5,185,113,217,120,163,165,
105,94,42,74,145,247,113,38,147,168,84,81,202,35,169,167,208,215,12,29,65,7,217,60,182,83,219,185,18,196,84,121,31,47,219,195,161,173,158,225,177,110,49,60,219,101,244,50,157,53,162,158,225,246,169,0,
143,207,165,159,196,206,147,143,228,199,106,116,39,71,101,230,158,29,181,223,29,197,38,111,125,120,192,13,91,213,157,61,75,22,236,207,225,152,177,1,147,112,228,69,53,51,131,195,68,204,57,30,196,28,147,
181,166,241,205,176,197,37,60,56,16,126,214,201,35,242,4,117,138,255,0,120,254,119,151,149,249,67,120,220,45,7,248,202,69,225,199,242,146,78,208,127,33,83,246,129,214,252,216,234,10,60,93,5,22,55,29,75,
5,14,63,31,73,77,67,65,69,75,26,195,75,71,69,73,10,83,210,210,211,66,128,36,80,83,193,26,162,40,0,42,128,61,229,154,170,162,170,32,162,129,64,61,0,235,142,206,239,35,180,146,49,50,49,36,147,146,73,201,
39,237,61,86,95,243,7,248,109,23,110,208,227,59,203,173,240,89,10,238,221,235,216,67,230,54,246,222,205,228,118,214,67,182,54,60,34,245,251,89,242,88,170,186,41,83,113,227,161,213,54,38,118,36,137,65,
136,157,46,0,134,189,220,228,11,238,101,218,46,119,94,88,186,146,215,154,161,74,163,198,72,50,168,175,99,0,69,72,252,63,179,169,43,219,222,111,139,102,186,27,70,237,165,182,89,207,227,1,132,78,120,56,
168,56,39,226,28,60,250,171,12,33,248,227,188,40,203,84,236,206,203,205,209,83,74,244,25,44,22,244,238,62,198,170,168,196,228,225,38,58,204,46,224,192,212,101,169,229,199,228,40,230,66,178,65,32,28,139,
216,139,123,231,14,251,205,62,233,216,207,113,182,110,156,201,116,179,161,42,200,193,135,3,78,12,127,201,214,73,219,242,223,139,10,93,217,93,219,233,97,80,209,197,24,193,200,238,0,159,217,208,207,179,
247,23,88,245,165,43,197,213,29,105,179,186,253,165,70,215,93,132,196,69,38,106,77,102,231,201,154,173,21,25,71,123,146,65,242,95,252,125,198,155,140,252,193,186,177,27,166,233,52,169,232,73,211,251,5,
7,74,199,44,180,140,13,237,195,76,127,164,113,249,1,142,147,27,151,180,50,53,126,99,77,229,158,166,86,98,243,204,204,238,196,253,111,168,159,81,60,255,0,175,237,139,77,149,42,173,59,118,244,37,178,217,
160,77,58,200,8,49,228,58,64,227,246,206,107,116,138,220,214,94,182,28,94,15,25,20,181,185,156,246,94,116,161,197,98,232,33,95,44,245,53,149,147,149,138,40,210,53,38,215,212,223,64,9,246,110,243,67,108,
98,180,182,136,189,211,225,17,6,166,99,192,96,127,62,151,93,238,150,59,84,90,86,134,74,96,14,36,254,93,14,95,23,58,2,167,229,254,110,142,168,97,178,56,47,135,155,75,59,75,146,201,230,50,244,211,99,243,
191,36,247,70,18,160,73,71,141,164,130,64,147,81,245,110,50,186,33,44,191,154,214,80,164,155,157,57,123,236,7,177,55,91,157,253,183,57,115,116,3,233,163,254,205,63,9,63,194,188,117,83,253,17,248,126,21,
60,122,129,61,200,247,13,182,228,123,75,121,193,223,36,90,42,131,81,110,132,124,71,254,24,69,64,30,92,122,216,78,146,150,158,138,154,158,146,146,8,105,105,105,96,138,154,150,150,154,52,134,158,154,154,
158,53,138,8,32,133,2,199,20,48,196,161,85,84,5,85,22,3,223,64,17,21,20,34,40,10,5,0,24,0,15,65,214,47,51,51,179,59,177,44,77,73,60,73,61,72,247,110,181,214,180,127,240,165,141,149,83,183,250,79,226,119,
203,60,118,18,108,200,248,243,242,75,25,181,183,173,54,58,36,254,47,87,214,221,255,0,130,173,235,76,213,44,117,19,24,233,34,162,143,59,83,142,145,205,67,164,43,38,134,39,216,143,147,247,163,203,188,213,
177,239,34,50,233,28,218,89,5,42,232,224,171,40,169,2,166,180,21,52,175,30,130,252,243,203,227,154,185,43,153,118,1,50,197,52,182,250,163,145,129,34,57,34,33,210,66,20,22,237,43,157,32,154,86,153,235,
78,108,246,222,125,155,218,227,184,59,206,171,13,178,246,231,83,127,23,151,96,108,74,156,157,61,108,120,60,206,78,25,168,234,55,166,242,205,194,127,134,229,55,12,88,201,140,56,236,125,1,168,72,158,75,
249,29,200,30,242,58,242,198,232,111,144,243,79,58,248,91,126,211,183,84,219,219,52,138,236,28,138,137,37,34,168,210,26,2,168,149,60,5,69,13,96,235,29,198,223,122,229,79,234,247,34,204,247,247,91,138,
40,158,237,17,163,73,20,97,163,132,55,122,69,170,170,207,37,40,181,52,37,176,182,233,62,184,94,213,175,237,46,220,223,219,97,177,208,119,1,194,225,54,150,206,221,24,232,218,178,139,171,118,205,36,209,
97,165,220,88,154,196,113,79,95,186,235,234,231,200,61,60,139,174,40,228,140,55,171,232,97,202,123,40,230,75,142,99,230,173,235,111,81,14,233,161,32,134,85,4,139,88,240,172,234,120,25,8,12,41,67,230,40,
40,122,7,243,231,54,203,201,112,114,175,41,236,23,238,231,105,15,37,196,240,177,80,110,164,57,84,35,138,198,11,41,173,70,66,154,144,122,101,207,252,96,223,125,89,52,153,110,132,221,83,237,218,0,237,60,
221,123,185,254,251,113,245,228,238,73,98,184,176,103,254,55,179,157,192,183,249,28,205,0,184,253,147,111,122,151,145,183,174,91,145,174,121,43,116,54,209,18,73,182,155,84,150,204,127,163,90,188,85,225,
130,126,218,116,99,179,123,185,203,92,219,18,89,115,149,138,220,76,0,31,81,29,34,184,95,155,1,69,146,156,105,129,242,61,4,187,167,63,180,107,227,137,62,75,244,124,155,75,33,76,116,71,216,24,168,106,50,
88,250,105,69,215,238,177,221,147,179,19,31,186,240,33,136,212,191,125,26,42,143,213,123,123,14,110,247,155,13,252,70,211,220,158,70,250,82,213,31,80,136,36,132,159,50,37,141,117,37,127,166,166,158,103,
161,222,211,181,110,118,215,41,186,123,97,207,76,110,23,184,70,37,48,204,61,53,70,196,43,252,244,24,254,89,233,91,181,54,190,98,167,27,22,83,161,254,77,205,154,196,120,215,193,182,251,126,42,30,215,218,
142,156,120,233,224,222,152,7,198,111,60,65,11,97,121,254,224,168,250,130,71,184,239,116,251,187,242,15,53,194,111,57,47,152,81,36,34,160,84,50,143,181,147,184,127,182,136,117,59,242,183,223,75,239,23,
237,116,201,103,204,182,207,186,109,171,74,164,171,173,216,14,58,86,99,228,43,77,23,21,233,87,38,226,239,205,182,165,183,119,65,54,242,199,162,6,147,115,116,22,241,197,111,106,82,188,6,150,77,165,159,
56,13,213,76,8,231,66,164,196,125,62,190,225,222,96,251,181,115,254,209,170,75,8,5,237,184,224,99,43,37,71,216,167,80,252,208,124,250,202,190,71,254,243,47,108,119,70,134,215,158,185,114,227,106,189,60,
88,107,140,15,157,38,82,135,253,164,167,168,81,252,131,235,26,121,86,155,115,87,238,46,186,175,118,8,104,59,51,103,238,93,143,32,147,254,57,138,172,190,62,60,107,243,249,73,152,127,143,184,143,116,228,
110,110,217,137,27,142,193,115,24,30,101,27,252,221,101,159,41,125,233,125,133,231,85,81,178,251,141,102,179,31,193,49,8,127,222,149,157,127,159,66,86,35,119,237,77,193,26,205,129,221,59,107,52,141,250,
27,25,157,198,214,135,191,214,194,10,151,107,139,143,199,176,204,144,79,30,37,183,117,251,84,143,240,142,166,125,191,152,249,123,117,85,125,179,152,118,251,132,60,60,59,136,152,254,205,64,255,0,46,148,
128,74,69,196,110,84,129,235,81,173,57,254,140,160,131,107,251,98,139,95,42,244,126,137,51,138,198,140,87,228,42,63,151,94,212,64,179,7,189,191,227,155,3,99,110,56,28,241,239,116,95,50,58,171,9,23,44,
140,63,34,58,225,173,120,250,255,0,200,67,159,240,254,158,246,122,101,156,113,53,235,19,74,64,60,219,252,66,159,175,250,196,243,239,97,75,28,116,223,138,77,72,29,112,212,79,250,175,205,236,44,1,254,159,
239,63,239,30,247,64,26,135,135,76,22,60,51,95,207,174,213,36,123,233,138,66,62,183,10,228,91,243,234,224,115,239,193,148,87,175,104,149,190,24,152,143,90,99,168,25,28,150,55,19,19,79,150,200,227,49,16,
170,150,105,178,153,10,74,8,81,64,245,22,146,174,120,150,202,57,38,252,123,122,52,154,70,162,35,55,216,13,127,96,233,5,230,225,99,182,174,189,203,113,182,183,90,127,162,203,28,127,241,230,29,3,57,79,146,
29,37,140,171,56,232,55,246,59,115,101,129,9,252,31,98,209,229,55,206,81,164,98,2,68,180,187,94,143,34,12,172,194,192,18,46,127,62,206,236,185,107,152,55,39,84,177,218,166,114,127,162,122,139,57,139,223,
191,103,121,81,100,59,191,63,89,235,94,43,17,50,159,178,171,219,251,24,142,156,127,191,29,167,184,226,83,215,157,3,189,106,18,107,8,51,125,171,95,137,234,140,10,43,46,161,59,82,101,38,174,221,51,194,188,
27,37,8,36,125,15,185,99,151,254,239,30,229,111,133,29,246,131,111,110,127,20,148,76,122,247,145,143,152,175,88,185,206,223,222,47,236,151,46,172,176,114,220,119,27,181,250,215,229,24,35,200,136,132,140,
127,54,79,78,144,27,201,51,56,150,129,59,251,229,22,212,235,72,43,108,171,215,157,17,64,87,115,215,163,220,26,21,221,251,134,44,150,229,168,121,126,154,232,49,177,19,248,97,238,89,178,246,11,144,249,84,
197,55,62,243,172,6,226,163,244,33,253,89,9,244,160,20,21,225,192,159,65,214,38,115,79,223,139,239,17,238,106,207,103,237,215,40,201,182,108,205,81,227,48,22,201,67,128,75,146,102,106,15,233,160,206,72,
233,143,21,143,135,17,86,43,186,71,227,253,54,218,173,101,18,14,243,249,3,61,117,118,227,100,117,11,252,75,31,71,156,169,201,239,220,181,68,170,117,34,91,27,9,39,130,171,199,185,87,104,177,181,178,142,
40,189,190,246,242,59,72,7,195,125,184,45,15,15,141,34,35,83,31,76,83,212,117,141,187,156,247,187,189,220,183,94,228,123,147,115,187,238,236,79,137,103,102,236,202,73,206,135,144,49,10,63,211,61,105,128,
199,174,114,117,231,247,170,185,42,59,27,113,103,251,167,54,103,21,17,67,184,225,142,139,100,227,106,67,92,54,35,100,227,200,199,149,141,255,0,67,215,53,100,160,126,111,236,228,114,162,238,87,11,119,204,
219,156,251,197,248,53,2,74,165,186,31,232,66,184,62,128,189,113,138,116,224,223,87,106,179,120,118,93,190,219,103,219,180,231,195,210,102,97,255,0,12,153,129,32,249,157,35,36,214,181,232,211,237,78,176,
97,13,53,126,225,209,75,75,79,20,107,77,143,138,53,130,158,158,24,191,205,197,21,60,94,56,97,137,64,176,85,80,45,248,247,33,216,236,225,34,79,25,86,56,23,130,0,20,1,232,170,0,3,246,117,18,239,124,235,
25,154,75,93,168,52,183,44,104,94,165,137,62,100,147,146,127,62,157,119,78,232,199,225,233,154,131,11,26,70,6,164,214,138,183,91,113,207,227,81,191,7,241,237,203,171,152,226,30,29,186,128,0,227,213,118,
61,134,230,250,69,188,220,164,36,241,0,215,246,116,90,179,181,245,21,213,13,36,242,51,27,242,1,252,127,173,244,3,216,110,118,37,243,212,183,183,90,164,48,170,170,0,163,29,52,35,184,148,68,171,20,145,213,
70,105,42,105,170,96,138,170,142,178,150,127,219,158,146,186,146,96,212,245,148,179,163,16,209,186,178,144,125,176,208,165,194,181,188,209,171,193,39,107,43,0,85,129,242,32,224,244,190,85,85,140,184,36,
58,10,169,6,140,164,112,42,220,65,245,245,243,175,70,151,249,17,252,165,220,31,13,191,153,134,3,115,236,77,153,182,165,248,253,242,203,185,168,190,18,238,188,73,90,202,140,174,217,200,71,71,30,231,219,
217,253,151,95,81,52,167,27,141,135,119,150,142,90,27,253,188,145,235,85,210,81,125,226,143,48,109,137,28,251,150,243,182,91,232,216,69,251,219,198,42,77,10,168,98,1,62,84,32,143,150,60,186,150,182,173,
201,88,216,242,245,253,223,137,191,11,5,185,114,64,4,161,102,64,196,10,10,234,5,79,169,206,43,215,212,47,216,127,163,62,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,
175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,
175,123,247,94,235,255,213,223,227,223,186,247,94,247,238,189,215,189,251,175,117,168,140,116,211,118,55,100,127,51,29,251,35,51,100,179,63,46,119,238,222,142,102,245,72,48,93,97,132,160,219,152,138,59,
216,178,211,211,104,114,171,123,92,223,222,56,243,185,107,153,55,22,255,0,151,134,63,146,245,211,191,101,230,135,96,217,125,182,66,189,166,202,34,127,211,74,89,201,252,241,213,30,238,92,61,86,242,222,
212,123,54,39,127,188,236,45,247,128,235,225,34,3,228,139,19,87,91,247,187,141,208,47,32,127,9,162,117,36,125,3,123,7,236,177,135,185,71,35,244,226,82,231,237,224,58,203,239,112,119,23,183,216,46,4,77,
73,110,221,32,95,93,45,66,255,0,180,98,189,28,30,217,201,166,52,231,42,105,147,237,232,49,80,12,78,34,48,24,44,116,24,168,211,31,65,20,95,213,82,158,157,71,178,185,164,241,231,145,245,119,51,19,252,250,
26,236,176,67,181,114,237,165,172,31,130,33,251,72,232,14,248,235,177,91,123,239,141,223,189,42,96,90,229,235,92,21,37,14,14,41,64,146,158,77,253,216,38,120,146,169,162,109,65,229,193,237,170,57,157,120,
186,60,192,253,125,156,175,248,174,205,115,112,126,41,91,72,251,7,31,203,168,202,250,246,59,190,122,217,237,167,144,139,43,8,204,242,127,167,110,3,231,128,58,118,237,92,117,6,221,197,101,85,49,216,234,
108,156,197,169,106,42,169,168,104,233,234,166,37,180,178,201,81,4,73,52,128,145,249,39,217,36,114,187,128,12,172,80,26,208,154,129,212,183,117,244,95,72,215,150,182,177,164,146,45,117,4,80,196,113,201,
0,19,213,161,127,41,125,130,51,127,55,62,54,99,161,36,71,212,31,30,59,107,180,242,196,0,74,213,239,108,174,223,217,184,184,36,11,194,180,193,229,117,191,212,33,246,61,246,122,217,174,119,253,214,248,252,
42,105,254,242,41,254,22,29,115,163,239,119,188,172,60,156,246,131,226,186,190,69,31,98,6,98,127,144,253,189,110,17,239,37,250,230,215,93,16,13,174,62,156,143,240,63,212,123,247,94,234,185,190,88,124,
3,194,247,70,106,167,181,58,143,61,71,213,93,215,37,58,197,149,201,28,106,214,108,206,198,138,16,12,20,187,255,0,5,0,140,212,213,198,23,76,121,24,109,84,128,217,139,128,0,133,253,207,246,95,151,253,196,
137,174,138,173,190,244,6,36,3,13,233,174,148,53,244,96,107,235,94,164,222,71,247,43,115,229,58,89,206,26,125,160,159,130,189,201,243,66,124,191,163,195,211,170,199,220,93,73,242,79,169,170,36,162,236,
223,139,251,223,116,195,72,161,78,237,232,252,133,6,242,219,153,5,176,34,117,199,214,61,46,95,27,228,83,254,109,210,234,110,47,239,9,249,163,238,211,238,62,213,59,141,189,22,226,218,166,140,20,184,167,
150,82,135,246,138,250,245,62,109,222,232,242,238,231,26,52,91,172,112,203,76,172,189,135,249,138,31,200,158,162,225,224,238,157,211,58,80,117,119,194,46,231,203,229,157,9,167,200,246,111,216,108,125,
177,78,86,231,201,87,83,81,52,127,112,168,77,202,36,202,231,253,227,217,22,207,247,112,247,59,117,157,98,187,137,226,128,241,211,25,95,248,212,133,84,127,63,179,173,95,115,238,203,111,27,53,199,49,219,
170,215,130,19,35,126,65,71,70,215,168,255,0,150,255,0,101,246,166,87,15,188,190,108,110,236,117,70,221,198,84,195,95,135,248,223,214,178,203,143,235,232,101,137,214,104,14,244,201,211,180,51,110,71,73,
20,23,132,93,92,139,51,145,123,229,119,182,31,118,93,147,149,204,87,251,250,137,110,234,9,74,235,102,35,63,169,47,167,244,35,160,249,245,18,243,47,186,170,203,53,175,45,35,137,24,16,110,36,248,232,127,
223,107,248,126,68,231,229,213,203,226,113,56,188,22,54,135,13,133,199,209,98,113,56,202,88,104,177,216,204,117,52,52,84,20,20,116,232,35,130,150,146,146,157,35,130,158,8,144,0,170,170,0,3,222,85,197,
12,80,70,144,195,24,72,148,80,40,0,0,7,144,3,135,80,164,146,201,52,143,44,210,22,149,141,73,38,164,159,82,79,78,30,220,234,157,123,223,186,247,90,168,255,0,194,146,119,206,227,237,157,175,141,248,99,129,
221,185,252,6,213,110,159,221,189,227,217,88,125,189,82,152,249,55,142,226,162,204,208,97,250,47,111,229,235,85,30,165,240,24,221,223,143,172,203,84,210,169,69,169,154,142,159,81,33,45,236,117,200,92,
158,188,227,117,204,81,200,238,18,199,108,150,116,211,197,167,20,16,131,253,29,70,167,236,234,50,247,63,220,41,125,190,139,145,133,188,49,188,187,190,251,5,163,151,224,150,180,47,114,227,250,90,0,85,242,
5,186,213,215,110,96,246,86,234,235,238,157,239,58,157,167,79,187,55,150,238,216,248,28,205,110,233,236,26,220,134,242,173,195,110,186,42,127,225,153,182,196,226,178,211,62,3,17,87,69,150,161,153,81,227,
164,89,99,42,44,65,30,231,238,95,229,253,139,116,216,185,103,154,174,173,164,188,220,46,45,195,51,220,200,211,232,149,24,163,232,86,58,22,140,181,29,164,129,76,245,9,191,48,111,182,188,197,206,220,130,
47,227,178,219,118,251,246,72,225,179,133,45,149,237,228,85,150,34,236,149,145,142,151,210,196,50,135,33,142,145,208,237,178,183,20,211,18,245,53,45,61,97,118,146,89,101,123,203,43,49,187,187,49,55,98,
127,222,189,200,182,147,55,22,39,86,58,0,243,78,208,133,63,74,47,210,167,1,192,116,97,113,57,8,107,98,82,234,146,46,149,89,21,185,5,126,134,224,216,155,143,98,203,73,163,148,0,249,95,159,88,245,191,109,
183,22,142,239,108,236,174,60,193,249,241,234,110,75,96,109,172,229,44,129,233,160,67,80,173,175,76,33,149,181,114,81,226,33,146,65,164,114,8,181,189,155,255,0,86,172,119,40,152,68,160,19,197,78,84,253,
160,212,31,204,116,5,62,241,243,47,39,220,32,190,149,164,183,13,134,5,131,175,159,16,107,129,233,209,57,236,79,132,93,125,95,95,46,224,219,116,117,187,35,113,59,106,59,159,174,107,231,218,89,57,165,107,
145,247,209,227,52,99,242,32,19,125,53,16,74,15,184,191,125,246,107,102,107,131,117,111,109,37,134,225,196,77,106,237,11,127,182,85,236,63,60,10,245,146,220,139,247,175,151,112,181,22,247,23,208,223,217,
80,126,149,200,18,138,159,32,223,26,159,182,191,96,232,27,61,83,242,99,175,167,213,182,251,15,5,216,56,184,79,162,143,127,97,103,195,238,21,85,253,49,141,211,180,154,8,106,9,31,71,150,136,159,235,126,
125,134,207,44,251,151,177,189,118,174,98,183,220,45,135,5,187,67,28,163,254,110,199,82,79,204,158,166,91,95,113,125,167,230,152,130,238,251,12,214,51,176,201,183,43,36,68,250,232,144,80,15,58,5,199,82,
170,123,207,185,246,253,27,99,187,7,168,119,142,71,30,160,135,27,122,76,31,102,224,228,81,193,45,143,200,45,14,77,99,32,112,166,153,143,186,220,115,151,53,89,70,98,230,94,72,186,120,71,19,17,142,238,63,
201,28,23,31,179,243,233,216,253,180,246,211,122,115,115,203,156,207,99,20,196,249,248,150,82,215,230,240,178,41,232,43,200,118,63,194,173,217,43,47,103,117,63,95,237,204,171,177,243,73,184,250,195,39,
214,249,96,255,0,219,38,191,29,142,198,161,125,95,219,73,127,198,254,195,210,243,23,179,187,177,101,230,46,94,130,25,248,31,22,214,91,118,7,207,49,209,127,62,151,63,183,30,237,108,193,101,228,190,118,
191,88,70,71,133,119,21,202,159,79,237,131,53,62,90,171,233,210,179,111,245,119,194,13,199,24,155,100,239,125,203,181,230,144,146,169,215,223,33,247,29,28,16,130,63,76,120,170,252,222,70,8,130,155,88,
120,192,31,211,221,63,214,243,238,241,204,0,24,158,8,137,255,0,125,221,33,57,254,140,162,191,180,245,168,253,200,251,228,242,99,22,219,249,142,234,101,78,2,75,105,148,127,189,219,189,43,95,58,83,207,165,
188,95,29,246,90,175,147,109,252,159,249,17,65,17,245,68,143,188,118,174,230,138,49,107,143,94,83,107,213,60,138,63,197,175,111,108,75,247,108,246,94,240,107,182,222,110,20,31,65,3,143,229,32,255,0,7,
71,86,31,125,63,190,246,204,222,28,134,57,2,249,53,205,228,117,252,158,217,233,251,122,228,223,31,115,154,53,81,252,193,238,8,192,54,85,169,218,221,111,90,127,218,67,183,247,118,2,255,0,239,23,255,0,15,
101,146,125,213,61,179,96,90,46,100,156,127,205,145,254,17,41,29,9,237,191,188,43,239,141,20,158,29,198,211,25,81,230,47,65,31,177,173,84,211,237,234,60,157,1,186,44,166,163,230,71,104,24,193,4,136,118,
23,91,81,106,226,246,51,190,38,107,220,112,125,62,218,79,186,175,182,209,128,102,230,153,199,167,233,40,255,0,143,74,58,48,155,251,195,126,247,151,24,183,217,162,32,1,90,220,87,243,26,109,31,207,212,15,
183,174,45,211,216,58,16,87,112,124,184,238,74,169,62,172,176,85,245,150,13,26,192,240,222,45,170,38,141,79,245,86,7,252,71,183,23,238,217,236,189,153,31,93,204,247,15,79,42,193,31,243,105,95,164,111,
247,225,251,239,110,200,226,198,222,11,113,243,123,137,1,175,159,233,193,21,41,249,244,131,220,91,95,226,118,42,23,135,122,119,143,101,110,58,165,12,37,131,51,242,2,190,155,95,170,224,156,94,214,150,134,
117,23,254,200,95,240,247,118,246,215,238,225,176,130,183,23,171,35,143,226,185,136,159,247,152,145,255,0,213,235,209,84,158,242,253,248,121,200,137,47,249,158,104,149,171,85,142,11,141,63,104,105,102,
132,224,113,242,61,7,244,51,252,50,138,169,155,99,252,127,204,247,30,68,105,65,88,219,63,176,187,64,52,200,78,144,217,141,239,84,216,88,174,121,39,90,165,249,39,218,139,25,61,155,176,34,62,91,228,89,247,
57,135,240,65,52,163,228,9,109,9,159,90,83,229,209,70,229,178,123,213,187,143,31,156,189,212,107,40,200,171,106,158,24,79,204,138,7,147,242,50,116,54,225,119,31,200,90,248,33,199,245,167,68,108,78,153,
219,229,86,56,106,183,78,91,11,134,169,142,152,220,35,255,0,117,186,251,31,85,56,112,188,232,122,197,63,130,65,246,50,180,190,231,201,130,167,46,114,5,134,211,102,112,30,225,145,24,15,244,145,13,127,237,
73,39,160,124,187,55,181,123,115,25,57,143,158,47,247,187,225,241,44,94,36,170,199,230,206,76,103,237,29,60,84,116,39,100,111,34,175,217,61,227,187,36,163,146,239,87,128,235,92,124,27,15,31,58,216,159,
12,153,217,159,45,185,230,132,139,130,203,81,78,228,31,107,31,146,121,155,120,0,243,71,61,220,52,39,226,138,205,62,157,62,195,35,18,231,210,186,114,58,104,123,143,203,59,32,49,242,151,33,218,69,32,248,
101,186,127,25,235,229,250,105,69,175,251,97,67,199,29,58,98,246,7,84,116,218,203,30,194,217,24,120,55,37,69,254,231,112,85,197,46,119,116,85,72,126,178,214,238,76,195,215,102,103,152,177,191,51,15,169,
224,123,89,103,203,156,169,203,70,155,54,205,15,214,121,203,39,234,204,79,175,136,245,165,126,64,124,143,76,29,231,156,57,204,253,70,255,0,191,79,251,187,202,20,62,12,52,255,0,72,148,175,251,98,107,231,
212,188,118,194,221,155,230,179,239,50,6,88,105,164,33,153,166,50,18,65,35,232,24,146,110,7,179,136,54,203,253,214,64,237,171,79,169,233,54,231,206,28,189,202,86,198,27,98,134,64,62,21,160,175,228,63,
216,232,99,198,108,204,6,200,132,72,241,199,45,72,81,251,174,160,146,192,122,128,7,128,110,125,159,199,183,218,237,105,169,168,210,245,27,220,115,54,239,205,211,8,226,5,45,73,199,30,21,225,79,246,58,14,
247,126,241,121,252,180,212,174,85,57,91,167,3,142,44,7,30,171,31,100,151,183,205,51,21,82,105,233,212,135,203,124,180,150,161,100,153,71,138,124,250,4,171,165,50,150,98,75,27,242,79,214,231,233,253,121,
231,217,67,154,212,145,212,147,10,44,42,170,131,135,72,220,138,129,40,60,220,130,127,63,83,111,193,2,255,0,95,246,30,208,79,93,92,58,60,179,166,128,197,186,65,239,61,196,187,79,107,110,29,201,161,165,
155,15,138,170,158,138,157,1,105,106,178,82,39,219,226,168,162,81,115,36,213,121,9,163,141,84,92,150,97,111,100,28,193,185,141,167,101,221,55,10,247,199,9,211,254,157,187,20,15,157,88,116,115,182,218,
157,195,113,179,179,211,134,148,87,253,42,247,53,126,84,29,13,221,9,179,171,62,62,237,175,130,153,106,197,255,0,127,78,43,231,95,198,61,231,145,156,141,82,203,186,51,123,237,166,206,178,223,153,85,102,
201,201,9,252,20,142,222,192,188,227,203,143,203,254,202,108,145,220,160,23,210,110,177,200,254,186,222,23,44,63,218,141,32,252,199,65,30,86,230,245,230,79,188,166,239,105,105,41,107,11,110,92,149,6,113,
69,186,136,41,167,169,58,216,122,6,61,125,91,253,192,93,100,87,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,93,
92,127,95,126,235,221,123,82,139,220,142,62,188,142,63,215,247,238,189,215,65,209,141,149,149,143,214,193,129,54,254,182,7,223,186,247,92,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,
215,189,251,175,117,239,126,235,221,123,223,186,247,95,255,214,223,227,223,186,247,94,247,238,189,215,71,254,36,127,189,251,247,94,235,86,143,141,187,86,74,205,243,252,200,58,246,178,51,22,225,195,252,
182,239,138,185,162,155,211,44,145,110,154,60,118,229,197,182,146,1,34,90,74,158,15,228,91,220,13,189,217,180,243,238,144,145,250,154,229,253,181,39,252,29,116,19,100,222,86,199,149,61,176,220,208,159,
167,250,107,80,72,225,219,84,63,241,160,122,163,238,172,198,179,124,204,216,59,118,173,25,31,111,230,59,71,54,202,235,113,252,71,31,183,170,162,166,113,171,232,209,164,205,111,96,29,158,130,215,113,122,
100,70,7,248,71,89,157,206,215,171,116,156,155,225,102,23,147,95,200,224,83,249,116,102,254,94,236,89,118,166,211,219,181,209,146,176,103,22,153,155,251,58,222,82,36,102,31,130,65,62,200,76,45,11,169,
99,134,21,29,31,242,151,52,13,227,247,141,142,60,72,164,167,228,15,74,255,0,229,171,176,27,114,236,12,158,93,163,18,190,238,223,59,255,0,116,76,72,212,126,199,108,36,27,95,16,164,243,233,2,25,74,254,7,
63,227,236,79,121,108,210,174,219,99,26,246,172,69,207,248,122,134,249,131,125,22,41,204,123,211,181,26,123,244,133,127,210,169,232,169,247,202,61,94,250,147,110,170,159,36,251,176,210,21,2,252,125,230,
155,11,88,17,253,71,176,157,124,24,102,127,69,63,229,235,36,166,186,3,150,54,249,23,32,219,41,255,0,140,131,213,243,127,34,205,143,252,115,188,126,102,247,36,151,52,91,66,155,170,254,61,109,182,181,227,
241,224,241,21,27,179,115,172,45,200,2,44,173,116,42,192,125,88,255,0,135,185,199,217,173,191,192,217,229,188,35,190,76,255,0,189,26,255,0,129,71,92,172,251,222,111,126,54,233,203,123,34,159,133,100,153,
135,161,36,42,254,209,94,182,85,247,52,245,134,125,123,223,186,247,94,247,238,189,215,189,251,175,117,235,123,213,7,94,235,222,247,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,79,207,230,
251,13,78,75,249,146,238,236,45,92,141,79,28,255,0,23,58,102,179,30,38,98,180,243,227,87,127,239,172,125,84,188,240,98,139,49,90,161,254,162,235,239,36,62,237,126,28,155,199,57,219,53,60,87,180,134,159,
96,148,87,252,52,61,97,191,223,46,89,236,246,79,108,55,72,235,224,65,184,93,234,167,241,125,43,21,252,197,53,3,234,189,107,233,214,20,173,180,119,87,108,124,80,221,80,138,12,174,7,55,184,59,55,167,154,
83,104,115,123,11,114,228,90,183,63,140,198,202,255,0,231,42,118,126,234,168,157,100,129,121,74,90,168,164,253,38,226,72,229,52,253,207,184,115,55,182,215,203,162,120,174,36,190,176,174,4,150,242,208,
205,18,30,5,163,110,237,35,52,12,63,9,232,9,205,219,162,222,158,66,247,219,103,147,197,217,183,11,75,125,179,118,211,159,6,238,44,90,206,254,137,32,99,9,110,26,154,50,79,117,6,72,86,171,11,90,240,186,
188,51,83,57,14,166,226,234,8,250,143,201,35,217,210,22,141,168,199,184,116,62,152,195,184,219,134,74,24,152,84,83,231,208,217,181,183,58,147,16,50,27,122,68,145,220,112,7,28,139,129,205,253,155,90,220,
149,53,7,168,187,152,246,1,34,181,83,20,63,111,70,23,7,88,146,198,154,88,186,144,53,2,110,26,223,75,218,224,19,171,253,227,220,133,178,221,48,40,193,136,29,98,55,184,59,10,50,93,71,36,64,190,107,95,58,
98,159,157,127,144,233,84,21,165,14,65,89,98,80,162,56,198,145,96,64,186,177,35,253,215,253,62,183,255,0,95,216,248,53,189,196,43,226,175,113,227,92,255,0,170,189,99,76,22,251,174,213,184,79,37,165,195,
44,74,64,64,184,160,63,133,143,14,223,157,14,124,250,78,85,98,41,107,22,79,36,107,25,46,25,74,132,8,86,252,31,29,172,166,252,88,155,251,37,188,218,109,88,130,139,254,175,183,207,169,83,151,57,235,125,
133,52,221,74,72,12,40,216,161,83,231,65,240,210,148,245,243,233,27,144,218,52,115,234,50,193,11,48,38,225,64,18,92,223,78,174,44,53,91,241,236,134,125,149,87,34,42,143,95,63,219,212,189,178,123,151,123,
64,175,123,225,204,56,169,62,188,43,83,78,144,89,78,185,194,85,18,149,52,113,78,15,5,103,130,9,80,159,169,1,101,71,82,52,254,62,190,202,46,121,110,202,236,31,26,217,92,83,131,168,113,255,0,26,7,169,27,
109,247,99,120,178,40,159,92,195,60,81,218,60,253,170,192,16,58,7,183,31,198,142,166,206,23,151,39,214,219,23,41,49,107,253,197,78,216,196,253,197,239,127,84,203,74,147,6,177,250,234,250,251,8,223,251,
101,202,119,132,181,207,45,89,59,31,248,74,169,253,170,7,82,78,215,239,199,53,91,170,36,92,203,118,160,127,195,153,128,30,132,61,71,249,58,12,230,248,103,209,146,72,92,117,198,43,30,231,81,7,21,145,207,
98,44,111,107,40,198,229,41,213,121,63,128,61,135,36,246,115,146,25,170,57,120,38,127,4,146,167,242,13,78,134,209,125,224,57,208,34,50,243,16,113,253,56,163,111,240,142,189,31,195,62,154,78,6,11,113,70,
8,229,96,236,29,251,26,1,254,210,139,184,108,45,238,131,217,110,76,197,44,46,128,244,250,153,105,254,17,213,219,239,21,206,73,219,251,194,208,211,207,233,227,175,249,71,89,7,195,62,143,60,212,109,44,157,
113,189,199,241,13,233,188,235,127,175,211,238,51,174,20,91,139,127,143,183,23,217,110,71,83,223,181,78,231,250,87,51,17,254,30,147,191,222,43,157,100,166,141,230,4,31,209,182,135,252,223,230,233,246,
131,226,87,67,99,217,94,30,166,217,242,184,33,188,185,42,25,114,242,145,207,234,147,43,81,88,207,111,245,253,172,131,218,46,68,183,32,175,42,219,51,122,187,59,159,248,211,154,244,130,235,223,126,122,159,
13,205,215,40,132,112,69,141,0,252,194,84,126,222,132,252,63,80,236,156,8,88,240,155,55,105,226,99,22,10,184,237,187,138,165,54,230,214,104,105,85,148,241,107,220,251,18,89,242,110,197,183,138,88,242,
253,148,95,53,133,43,252,193,232,47,123,238,134,247,126,199,235,121,150,250,97,129,71,157,233,249,80,138,116,34,226,246,98,206,68,106,166,24,163,177,8,170,99,69,230,228,105,91,42,129,254,31,143,98,43,
109,162,74,42,70,161,99,244,80,7,242,0,116,7,222,61,195,180,182,13,35,214,73,128,226,229,152,255,0,189,49,38,159,97,232,74,161,218,88,76,109,32,150,120,81,220,6,37,220,94,231,245,105,23,60,147,110,61,
154,254,233,182,182,67,36,153,106,121,245,19,93,123,143,190,111,87,49,219,218,74,99,132,189,59,124,253,0,251,124,177,246,244,18,110,170,172,142,86,169,241,59,110,145,137,44,81,230,142,63,68,64,241,109,
86,176,32,31,246,30,192,215,242,205,115,43,91,217,198,72,173,13,7,89,5,203,73,107,181,216,69,185,243,13,218,131,74,209,136,20,251,126,125,115,218,221,71,69,67,34,228,51,163,239,43,164,253,198,89,77,194,
185,55,177,6,228,242,71,179,93,163,148,255,0,226,69,250,154,241,167,65,14,115,247,184,179,29,175,151,101,1,41,77,67,236,253,189,45,178,114,210,99,32,113,10,197,20,81,169,80,170,17,17,89,125,32,41,22,45,
166,220,251,16,95,61,181,132,5,33,140,32,29,2,121,110,219,115,223,247,5,158,242,229,229,103,53,3,200,127,151,246,244,86,55,206,235,146,174,169,224,167,146,225,110,9,83,112,45,127,232,64,247,25,238,87,
198,121,30,135,207,172,188,229,46,91,91,43,104,218,72,232,104,62,222,130,164,167,168,200,72,86,59,144,73,105,31,155,129,193,110,79,231,252,125,148,40,46,221,72,18,76,150,145,134,36,3,243,243,233,175,45,
77,29,59,199,78,135,158,11,155,115,253,63,199,233,111,117,112,1,210,58,114,201,222,77,114,51,96,244,131,202,133,51,178,139,27,46,149,211,249,36,126,45,253,111,237,4,255,0,22,7,159,66,107,74,104,82,126,
26,103,166,222,188,218,53,29,189,217,24,173,175,73,2,207,183,118,238,78,159,41,184,114,18,175,150,146,124,174,49,133,77,38,58,33,98,178,174,30,96,149,19,183,233,19,8,227,228,235,0,155,109,219,37,231,110,
100,179,216,237,35,15,182,91,78,173,51,241,87,153,114,145,15,34,34,195,202,70,43,69,62,125,20,251,141,206,251,111,181,28,131,190,243,150,241,47,135,114,109,88,68,149,1,244,48,165,105,199,84,167,178,49,
198,166,185,29,88,22,63,172,234,123,211,231,15,242,221,248,205,180,209,229,124,223,202,29,179,216,121,168,213,90,68,162,216,253,37,69,54,235,207,102,107,140,106,68,52,113,84,170,41,145,189,62,86,11,245,
35,217,127,222,94,246,218,210,199,150,185,98,214,64,193,102,121,127,211,4,2,45,71,237,96,255,0,101,41,212,73,247,44,181,221,55,187,238,115,247,31,123,182,104,239,110,160,137,8,63,128,74,90,225,81,113,
193,99,104,193,224,43,215,210,13,183,134,28,49,2,101,112,9,1,149,214,204,1,182,175,240,7,222,40,128,73,167,89,213,164,210,180,235,146,238,220,75,95,247,8,255,0,98,167,147,244,28,31,207,191,105,53,167,
159,94,161,165,122,144,187,159,14,223,74,145,248,255,0,83,255,0,71,95,241,239,218,91,211,175,80,250,117,33,51,216,183,250,85,39,251,31,122,161,30,93,122,135,211,169,177,215,82,74,1,74,136,205,254,151,
96,15,251,205,189,251,173,117,40,16,69,193,4,125,110,13,197,143,211,233,239,221,123,174,253,251,175,117,140,203,16,36,25,35,4,125,65,117,22,255,0,95,158,61,251,175,116,223,144,201,197,73,78,210,164,145,
179,0,72,26,129,225,121,111,161,247,176,43,215,186,3,243,29,154,212,181,46,158,91,4,102,26,126,138,79,210,252,126,47,254,243,238,254,27,30,29,57,164,116,193,81,218,114,50,16,28,144,215,250,49,31,129,127,
161,39,235,238,234,132,121,117,176,170,104,58,234,143,180,101,95,81,111,168,34,250,136,36,112,120,63,81,239,204,134,181,3,173,105,83,208,139,182,119,209,201,74,170,88,157,76,56,212,91,131,245,184,35,250,
255,0,143,231,219,76,164,103,173,20,227,78,29,11,202,117,40,97,244,32,17,254,196,95,221,122,167,93,251,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,255,215,223,227,223,
186,247,94,247,238,189,215,189,251,175,117,171,175,206,44,238,71,224,23,207,126,199,236,201,160,106,110,174,249,163,183,118,238,236,192,101,234,67,38,10,155,185,118,46,49,182,182,244,218,185,28,132,170,
180,148,57,77,203,183,30,146,182,140,72,234,38,40,200,183,101,247,11,243,244,55,123,93,227,223,217,199,168,73,221,79,180,105,113,254,94,28,15,89,235,247,113,135,106,247,63,149,35,228,109,202,241,98,220,
236,29,130,84,128,76,108,222,36,100,102,184,109,72,127,217,234,137,118,198,255,0,196,71,243,147,172,119,85,69,109,5,26,239,29,237,186,48,114,80,53,92,18,75,29,62,238,193,87,80,199,47,141,29,217,19,238,
72,80,230,203,114,0,247,26,236,218,164,143,113,86,140,133,100,38,180,160,7,56,235,52,57,215,109,93,155,106,229,91,86,185,86,184,181,125,7,187,37,123,123,169,90,129,142,61,89,39,243,17,198,22,234,30,160,
201,82,130,176,93,233,170,108,57,19,64,173,31,35,242,202,86,214,246,146,254,53,17,109,238,56,20,35,243,7,160,215,180,147,72,220,213,206,86,83,127,104,173,168,125,132,255,0,170,157,9,159,201,255,0,27,73,
144,233,12,51,0,141,37,38,206,222,168,214,30,181,170,254,249,102,210,167,80,63,71,114,128,159,207,177,53,164,98,77,209,235,193,108,177,251,51,254,78,162,47,115,238,218,211,151,118,144,9,253,77,225,139,
126,222,171,127,177,169,13,111,201,196,199,186,106,88,247,189,92,165,8,252,65,81,36,164,219,144,0,211,249,247,27,238,20,142,210,238,135,53,35,249,158,178,227,234,53,114,62,217,40,63,241,21,7,252,100,87,
173,153,127,144,166,214,134,131,225,14,83,176,30,45,57,94,222,239,206,233,222,185,25,136,245,205,12,27,194,175,110,98,213,141,134,175,21,22,24,1,248,231,222,83,251,123,104,150,156,183,104,170,40,77,63,
227,42,171,254,78,184,253,247,144,220,228,220,61,206,220,34,102,172,118,240,67,24,249,118,6,63,204,245,117,254,199,29,64,189,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,
186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,106,143,255,0,10,22,216,25,222,191,249,11,240,207,229,68,73,32,235,189,237,134,222,31,14,251,43,36,177,145,6,221,207,238,172,156,93,135,210,185,
74,234,129,254,102,155,39,187,177,245,216,213,118,178,172,245,49,45,193,113,121,79,217,110,96,139,151,189,194,219,13,212,186,44,111,227,107,87,39,1,76,159,217,177,62,84,144,46,124,133,122,131,254,241,
188,171,63,52,251,77,188,75,99,108,102,220,246,137,227,220,35,140,100,200,144,226,226,53,20,53,47,1,144,42,254,39,8,58,163,222,254,233,248,251,215,110,237,173,243,180,114,131,103,119,135,89,228,6,99,103,
110,88,163,89,36,165,207,80,66,105,43,40,242,112,161,86,200,97,51,180,224,210,228,168,220,233,169,129,201,22,112,140,51,35,157,57,42,78,108,179,178,221,54,171,159,165,230,237,189,252,72,37,3,186,57,144,
229,27,204,163,17,70,83,138,31,183,174,117,251,111,238,141,183,181,155,238,233,201,156,217,101,245,222,215,239,113,4,104,216,213,100,181,148,2,179,70,71,194,232,27,4,16,124,193,20,29,21,157,189,217,244,
125,137,149,168,216,251,255,0,111,255,0,162,190,252,193,211,203,38,99,100,215,72,207,134,221,148,180,228,199,38,230,235,108,213,64,141,119,46,14,118,245,60,35,252,182,143,86,137,144,91,81,142,182,238,
105,77,226,246,77,163,125,176,253,221,206,113,215,92,7,17,207,78,50,91,49,61,202,220,124,49,145,229,81,129,149,86,252,183,113,202,123,117,174,231,203,219,191,239,159,110,102,3,192,187,13,170,88,1,248,
98,187,3,32,168,192,154,128,54,3,133,108,149,13,44,181,56,218,182,82,74,186,57,244,220,143,165,174,63,173,185,246,120,143,161,180,181,106,58,91,60,48,221,193,174,149,4,127,147,163,45,176,119,52,85,49,
67,4,132,0,0,26,73,6,224,88,90,231,158,15,245,250,251,24,236,183,254,28,138,164,245,142,126,228,114,151,143,111,35,162,10,116,57,195,48,144,38,130,192,18,158,180,176,4,169,80,53,22,54,96,7,31,226,61,202,
22,23,8,200,24,208,130,58,194,190,103,218,167,182,185,10,170,232,234,227,35,0,208,138,106,173,49,76,30,185,202,39,12,205,227,214,167,81,26,66,128,121,43,160,139,171,106,191,211,139,17,237,99,196,148,26,
100,167,69,54,155,148,169,35,248,182,186,240,114,0,242,36,105,167,26,215,42,105,66,49,198,157,53,203,24,43,234,188,75,97,118,229,138,150,23,245,14,24,22,31,79,167,182,200,201,168,175,70,171,112,166,132,
57,65,65,159,66,114,43,246,249,117,22,74,117,146,193,163,18,93,77,138,128,203,112,56,4,88,115,126,69,255,0,175,180,207,8,203,46,58,18,217,110,210,46,132,126,254,223,44,254,84,166,79,161,226,58,99,169,
161,88,192,97,30,171,220,19,233,185,23,254,188,143,199,231,155,123,76,240,199,66,9,161,227,208,154,207,114,156,152,221,1,101,56,57,25,31,111,15,203,164,189,93,53,131,20,2,224,122,150,252,220,183,213,79,
211,232,61,150,77,18,234,168,57,255,0,87,30,134,118,23,242,148,30,47,194,41,199,230,124,189,122,104,53,81,69,32,73,172,132,144,9,123,0,63,228,45,68,3,199,182,22,120,163,52,155,31,111,71,50,218,222,92,
168,107,46,234,241,161,169,31,225,233,194,53,134,66,45,167,87,39,80,96,80,139,18,44,64,54,107,255,0,95,175,179,4,72,100,64,84,130,167,211,162,9,229,220,45,100,49,188,110,178,15,90,143,242,117,144,164,
74,0,118,0,158,15,43,112,8,176,230,215,39,159,123,22,240,130,78,156,14,181,251,206,241,138,43,62,79,250,184,250,245,18,174,182,158,137,88,198,170,73,36,106,228,219,235,248,231,95,35,243,237,13,213,205,
189,178,31,54,244,29,29,109,219,110,227,185,206,145,229,97,39,44,113,79,159,207,165,102,207,106,170,216,166,169,158,59,69,114,168,63,73,113,254,210,0,177,26,185,254,135,221,182,57,37,185,154,70,42,68,
126,93,5,61,210,22,219,61,148,80,69,38,187,134,248,128,193,252,169,195,236,225,74,244,179,171,163,21,112,248,154,69,72,201,187,136,255,0,83,218,224,160,184,178,241,249,62,207,229,217,238,183,39,17,43,
21,132,241,62,157,67,150,190,224,108,252,167,109,245,210,133,150,249,126,21,28,75,83,230,49,78,187,164,199,99,232,163,241,210,82,172,64,139,188,139,233,153,133,185,34,79,236,185,231,158,125,157,216,242,
181,141,140,116,142,53,51,122,145,231,212,115,204,94,244,115,47,50,92,147,52,239,29,157,77,17,88,131,167,228,69,40,120,249,17,79,46,160,228,154,24,161,144,161,60,112,128,144,218,64,187,107,36,155,153,
2,144,15,227,234,61,160,220,148,91,146,40,0,0,212,255,0,171,246,244,63,228,11,150,221,180,204,242,179,18,192,42,147,90,102,181,169,53,102,161,31,102,71,151,69,107,180,55,21,66,1,142,163,212,166,67,244,
143,150,245,41,190,159,207,252,79,184,103,152,47,154,73,90,48,79,207,174,133,251,91,203,208,65,108,151,115,32,10,0,60,41,229,208,107,130,235,76,246,122,51,93,60,79,79,72,88,179,75,40,210,89,64,189,207,
251,15,100,86,219,85,205,221,100,2,145,142,36,245,36,111,124,253,177,236,178,69,96,179,171,94,55,5,4,87,243,234,86,103,31,143,219,180,143,5,58,168,145,84,135,113,109,78,121,189,207,250,227,219,211,197,
29,154,20,28,122,103,106,191,188,222,231,89,100,175,134,120,14,128,186,233,132,179,73,41,38,236,72,3,235,197,190,159,95,100,108,106,213,175,19,212,159,109,23,135,18,34,227,166,44,94,212,201,246,29,84,
248,237,177,146,199,180,20,89,56,49,91,166,190,139,35,73,81,144,218,255,0,115,164,136,235,177,233,33,170,199,207,83,11,122,38,145,2,40,55,82,77,189,147,42,203,204,19,220,237,219,53,236,117,137,194,220,
186,176,47,8,99,77,33,120,130,220,60,66,52,167,174,163,78,158,221,185,155,104,228,216,34,186,223,162,144,93,73,19,73,107,11,35,5,185,100,82,221,143,240,185,3,184,68,15,136,195,128,160,39,163,237,179,186,
231,105,244,198,213,146,29,185,71,27,84,173,32,138,122,212,70,150,67,31,50,202,81,80,60,182,119,102,115,245,105,95,234,73,62,231,189,191,150,182,175,111,54,29,91,112,213,114,99,166,180,4,132,67,150,41,
196,179,183,241,19,168,147,82,71,92,204,222,125,207,230,159,188,191,184,54,251,86,247,1,181,229,43,75,141,127,75,43,132,105,167,70,164,66,122,211,74,175,240,83,74,128,126,35,78,141,199,242,73,206,209,
103,190,125,124,187,222,91,175,111,227,211,124,117,183,199,174,175,195,244,238,66,86,105,242,91,83,96,239,205,209,154,155,125,202,165,215,195,6,111,118,101,41,41,190,229,227,212,97,130,36,132,57,245,95,
2,125,217,220,183,29,219,158,239,95,113,181,240,35,138,8,214,24,235,82,145,17,169,75,159,247,227,212,188,148,192,102,35,203,174,183,251,23,203,219,95,47,251,117,97,109,182,110,2,234,121,110,37,123,137,
148,105,71,156,49,87,88,135,17,12,90,68,81,3,157,8,164,241,235,105,1,216,89,21,23,21,46,5,248,4,145,97,254,22,227,143,113,230,129,212,187,225,183,203,172,203,216,185,37,31,231,249,54,254,209,31,91,254,
73,250,31,126,208,190,157,107,193,106,214,163,169,73,217,153,17,164,253,195,147,197,198,182,31,79,245,137,252,123,246,133,235,126,27,103,35,167,56,59,79,34,135,153,94,223,226,237,253,45,245,7,222,188,
53,244,235,65,28,244,172,196,246,205,113,145,20,185,98,72,250,177,191,60,216,14,121,23,231,252,61,211,193,3,53,234,172,180,237,232,209,236,61,215,38,98,56,252,188,121,16,30,77,238,63,34,252,157,64,158,
61,167,101,160,234,140,41,67,229,208,135,150,150,104,169,88,193,123,155,134,96,186,180,139,126,127,215,247,78,169,208,33,150,201,230,34,154,98,137,39,234,255,0,82,110,84,126,65,245,95,145,238,235,233,
213,232,0,6,185,232,61,205,111,44,173,60,18,69,55,148,6,22,177,45,114,5,237,164,255,0,81,127,110,170,10,227,143,86,249,138,116,0,102,55,12,149,53,82,59,57,82,73,254,209,185,250,218,255,0,91,16,61,168,
81,65,78,172,20,183,195,195,166,133,204,185,97,251,135,254,74,35,252,45,197,239,254,191,189,245,191,13,189,58,122,197,85,203,89,50,199,19,147,205,172,73,181,239,192,22,60,243,254,30,244,77,5,122,167,157,
58,53,253,113,182,234,148,67,51,220,94,196,19,112,57,177,189,192,250,220,255,0,182,246,150,71,201,0,117,166,52,29,25,4,93,42,171,254,165,66,255,0,182,0,123,103,166,250,229,239,221,123,175,123,247,94,235,
222,253,215,186,247,191,117,238,189,239,221,123,175,255,208,223,227,223,186,247,94,247,238,189,215,189,251,175,116,24,246,215,76,117,87,124,108,172,159,92,247,30,193,219,29,143,178,50,229,26,187,110,110,
188,85,62,82,129,166,136,150,130,174,156,76,190,90,26,250,114,127,110,162,6,142,100,254,203,11,159,105,174,173,45,175,98,48,93,66,175,17,242,63,225,30,96,252,199,70,59,86,239,186,108,119,177,110,59,61,
252,182,215,201,193,227,98,167,230,49,196,124,142,58,171,63,149,127,202,135,227,142,43,225,239,115,109,15,137,157,15,178,122,255,0,183,168,233,177,189,155,215,153,140,37,11,79,185,242,155,247,173,242,
16,238,173,187,131,151,113,229,165,175,205,73,65,152,122,9,40,133,55,220,8,127,202,126,158,195,123,167,45,88,13,170,238,43,11,69,89,192,212,190,100,149,206,154,154,154,17,81,79,94,165,126,80,247,119,154,
147,158,121,127,120,230,142,96,184,186,176,73,60,57,4,140,74,136,228,236,102,210,40,181,90,134,173,43,142,181,225,239,47,145,24,190,232,232,189,148,180,180,237,13,45,68,210,228,170,41,106,81,160,200,237,
205,205,70,239,71,187,54,134,82,146,93,51,80,229,118,254,118,41,224,146,39,10,64,80,71,4,31,120,213,186,248,208,206,109,31,8,164,178,255,0,182,255,0,47,175,93,101,246,235,97,180,107,137,249,190,214,224,
31,30,32,140,1,168,52,21,14,15,152,101,163,3,243,233,99,252,173,254,75,108,206,139,168,221,219,7,123,234,84,195,229,51,245,169,7,214,74,141,161,190,74,228,241,153,88,35,55,103,166,164,202,172,208,75,96,
116,177,31,75,251,62,183,221,35,177,123,13,202,84,45,3,198,98,122,113,168,199,81,199,184,190,218,110,156,221,6,247,203,187,51,129,186,91,221,173,212,35,134,184,220,249,124,135,15,248,190,129,141,203,145,
192,238,127,150,114,229,118,227,60,152,124,166,103,51,83,68,88,18,215,154,154,165,227,101,0,3,250,155,216,11,119,100,54,215,50,32,34,54,146,185,244,39,169,128,89,238,91,103,32,216,88,238,96,11,232,162,
85,111,180,99,173,160,191,145,213,68,19,127,45,94,136,142,32,130,106,60,143,103,208,215,4,189,254,246,155,179,247,106,202,210,3,114,36,116,42,196,127,143,188,185,228,210,15,47,88,208,121,31,240,215,174,
59,123,236,140,158,233,115,56,53,161,120,200,251,60,36,255,0,45,122,182,207,98,142,162,46,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,
215,186,247,191,117,238,170,55,249,238,96,182,78,127,249,78,124,205,166,223,120,197,201,227,233,250,231,31,89,130,17,157,25,28,110,245,77,223,183,32,217,121,188,29,72,82,244,121,220,86,228,168,167,154,
150,85,229,37,80,126,151,247,234,22,120,85,107,168,200,128,83,142,88,12,124,243,213,209,130,248,133,136,9,225,189,107,194,129,73,53,249,83,143,203,173,61,250,91,119,214,193,135,167,197,111,106,189,123,
139,23,69,79,65,147,204,76,146,66,219,145,233,41,163,138,60,181,100,65,116,197,155,153,20,45,80,80,82,73,129,117,176,109,35,163,220,145,188,221,217,90,195,101,204,19,3,125,4,97,60,96,15,235,162,168,8,
238,167,43,58,138,44,148,168,114,53,10,84,215,145,158,248,123,108,155,131,75,119,202,40,37,217,110,103,105,162,183,52,173,148,142,237,226,69,27,214,143,104,95,84,145,46,12,32,148,161,80,161,67,95,148,
178,116,125,95,88,238,189,213,219,123,118,90,188,157,53,53,67,245,71,218,86,54,7,114,80,110,108,125,59,79,46,235,199,102,233,12,121,156,55,240,138,117,106,137,36,165,26,218,40,194,176,33,172,66,158,238,
63,45,127,85,238,247,158,96,218,212,220,204,229,108,1,102,138,101,117,82,94,226,54,90,56,72,240,95,240,183,15,159,66,207,187,188,60,243,15,61,114,255,0,34,242,87,51,147,99,101,8,159,123,149,85,46,45,66,
59,105,138,193,195,18,134,105,69,66,83,190,60,177,52,20,37,135,169,114,59,250,126,178,216,117,189,149,60,213,91,202,175,9,79,85,149,169,172,138,40,50,21,80,206,239,46,42,167,37,4,5,161,139,39,62,41,161,
106,128,9,253,214,55,230,254,194,60,165,62,241,47,46,236,243,111,204,199,115,120,234,75,124,69,9,62,25,127,233,20,165,124,248,87,172,167,230,91,109,158,45,251,119,135,97,85,93,177,36,160,9,240,135,0,9,
2,127,68,63,10,96,102,157,25,29,185,81,83,74,208,213,210,179,104,62,166,179,18,65,36,18,45,254,184,246,54,180,153,198,150,24,234,47,223,45,224,185,89,109,229,65,90,98,189,26,13,169,157,21,180,169,228,
112,36,22,227,243,168,0,1,0,17,111,167,185,27,98,221,3,81,91,143,88,137,238,95,37,133,105,102,141,70,156,144,127,111,66,52,111,35,161,18,22,49,3,105,11,90,236,146,45,213,78,155,53,209,128,35,243,236,118,
172,146,70,52,30,250,84,127,148,245,140,207,105,113,103,119,42,92,41,54,225,168,245,25,101,97,129,76,26,134,224,120,224,121,245,2,161,100,140,49,113,233,185,179,139,50,144,1,179,19,113,111,104,229,119,
143,35,35,161,37,173,189,181,204,108,30,145,200,8,166,106,15,207,253,88,29,64,53,9,114,117,232,189,181,30,20,175,211,155,14,62,159,79,235,237,55,213,166,3,28,215,163,68,217,166,25,70,32,145,196,99,243,
167,165,63,111,80,42,150,9,163,44,147,105,43,113,233,91,33,190,145,169,144,145,98,223,215,233,207,187,61,212,99,226,29,24,88,88,220,7,1,93,129,6,156,40,27,0,84,173,120,147,230,49,210,27,46,147,70,166,
74,123,94,48,88,171,63,165,130,254,5,215,233,97,127,100,87,142,65,50,33,199,82,199,47,164,115,36,118,211,68,75,15,83,131,76,116,17,238,109,209,80,41,37,90,58,74,122,234,216,100,212,216,201,165,74,55,200,
70,188,75,5,37,99,233,142,154,186,222,168,140,159,182,236,52,177,80,117,0,86,247,186,94,199,0,54,17,36,183,17,158,232,152,233,241,84,241,8,255,0,130,65,248,42,52,177,193,167,30,166,206,85,229,91,81,59,
181,244,210,67,107,32,26,110,16,23,16,48,173,12,177,15,237,33,99,64,250,72,116,29,203,208,97,179,123,83,15,187,171,114,56,221,163,156,97,184,49,19,26,124,222,199,207,161,194,239,12,44,160,147,162,175,
9,90,82,166,106,89,20,94,58,152,60,212,211,47,169,36,96,125,134,182,78,114,219,247,105,37,131,107,190,49,238,8,196,61,180,255,0,165,113,27,122,20,99,221,242,100,44,15,28,116,62,223,249,18,93,170,8,166,
230,93,157,91,111,117,5,47,45,235,53,172,138,127,16,145,69,82,158,107,42,161,21,166,122,18,63,136,238,145,28,149,57,24,159,31,73,76,143,45,77,101,99,37,53,37,52,49,46,169,37,158,162,102,72,96,141,20,92,
179,16,0,250,251,23,181,214,230,136,211,93,86,43,117,21,103,115,161,20,12,146,89,136,20,3,60,122,0,13,183,148,60,65,14,219,44,119,23,108,116,172,113,15,18,70,99,193,85,22,164,147,233,65,158,145,59,11,
178,63,210,198,230,100,216,112,255,0,23,216,24,86,154,28,183,99,75,27,255,0,3,220,89,152,154,74,118,193,108,102,114,141,152,165,199,72,165,235,50,104,166,140,50,136,97,105,27,89,64,230,207,204,83,243,
110,234,177,242,250,235,229,171,114,194,107,182,83,162,121,7,8,45,53,101,130,214,178,76,123,104,40,162,164,84,203,153,185,114,211,144,182,41,166,230,103,17,243,117,208,6,222,193,24,107,182,135,241,93,
223,21,168,77,64,21,138,222,181,36,213,190,26,41,219,194,64,40,168,34,136,1,112,52,176,69,213,164,48,229,216,88,40,40,5,254,164,251,157,246,77,191,195,133,19,21,57,244,207,167,92,249,247,51,154,94,125,
194,234,234,140,232,149,81,74,145,231,83,194,130,131,35,39,143,78,228,131,244,0,126,63,215,183,23,231,155,155,115,236,121,4,43,10,42,47,30,177,127,113,190,158,250,226,73,102,110,39,3,203,254,47,215,174,
60,217,172,108,64,63,145,254,219,147,245,62,220,110,24,233,36,98,173,211,22,69,68,145,206,131,213,233,42,164,217,156,147,114,71,43,116,181,193,30,193,123,255,0,246,44,51,168,249,117,146,94,212,206,169,
123,14,167,95,1,78,9,227,140,154,250,98,132,15,183,231,208,123,143,235,154,57,242,13,148,204,217,200,144,60,80,202,67,21,177,22,244,253,127,63,235,123,142,44,57,101,175,238,218,105,208,248,67,61,101,103,
52,123,209,23,45,236,177,109,219,92,232,47,27,183,141,79,151,167,249,122,203,191,51,212,152,28,107,209,83,37,60,78,16,168,72,207,1,44,64,102,22,22,176,246,238,253,113,14,220,130,210,220,0,131,29,123,218,
173,163,114,230,155,214,223,119,102,45,57,106,156,146,8,174,56,211,63,151,68,115,117,103,218,178,89,87,88,241,150,55,34,252,146,220,216,114,8,191,184,202,238,228,200,199,56,175,89,189,176,237,9,105,12,
102,148,199,65,205,67,59,3,38,159,74,130,7,231,234,57,54,226,192,19,236,181,216,128,8,232,99,18,170,182,151,243,29,39,122,163,13,151,175,236,189,235,46,204,142,10,109,219,179,27,29,185,162,148,126,204,
91,143,15,185,49,200,217,221,151,159,240,11,228,177,25,53,161,188,98,64,242,81,207,162,104,136,42,67,3,246,109,170,234,126,107,230,41,121,120,44,92,197,99,36,119,17,181,59,101,142,120,193,154,218,96,50,
241,73,78,7,40,78,165,233,15,185,155,151,47,65,201,155,5,191,57,76,127,171,123,139,27,82,216,213,111,113,20,159,226,215,182,236,127,178,158,22,166,150,248,92,2,173,142,142,183,91,246,30,246,236,141,239,
181,250,151,99,244,167,106,110,93,241,186,100,203,199,131,217,184,202,173,177,83,52,144,224,49,117,89,108,205,69,86,94,179,39,65,71,71,135,199,81,83,48,251,154,131,26,235,100,78,25,128,246,53,221,61,225,
183,229,171,91,68,223,185,83,116,134,213,220,164,104,147,219,200,9,3,83,133,170,134,208,190,173,79,66,43,214,62,219,125,216,119,238,100,220,111,247,46,89,231,46,88,184,221,217,17,229,184,54,183,113,177,
254,7,117,73,25,4,143,74,209,77,43,90,80,16,5,211,255,0,45,63,134,221,161,209,59,239,189,126,70,247,118,223,199,108,61,245,220,251,107,100,245,190,212,234,234,28,245,6,232,203,108,222,189,217,21,245,217,
166,202,239,124,222,29,230,193,182,236,220,217,170,251,253,165,28,179,197,69,77,16,83,35,57,32,98,175,59,243,58,115,143,52,95,243,4,91,121,181,183,145,17,35,136,182,182,17,160,160,46,192,0,88,241,52,192,
224,56,117,156,254,215,242,101,231,32,114,78,209,202,251,142,240,187,134,231,11,59,205,58,198,98,70,146,66,73,17,161,44,85,22,180,21,36,154,84,231,171,111,251,174,73,187,139,243,192,224,159,233,249,246,
21,234,64,34,180,207,92,141,85,255,0,180,195,254,35,250,219,131,239,221,111,169,84,210,60,242,172,96,254,182,2,255,0,236,79,212,91,129,97,239,221,85,190,19,208,131,77,180,107,39,128,204,138,204,150,213,
117,39,77,128,252,223,252,127,214,247,82,104,105,92,244,211,72,41,69,174,58,100,105,100,194,213,233,148,21,241,183,170,223,75,220,125,13,137,255,0,141,123,183,86,43,168,106,30,156,58,50,157,87,216,26,
106,225,166,214,5,192,0,221,109,99,205,197,143,245,246,196,177,138,106,175,76,48,57,7,20,232,238,99,106,146,190,134,41,248,125,107,102,184,250,159,248,165,143,30,210,244,223,92,39,195,208,79,114,241,5,
189,199,22,183,63,235,131,239,117,35,135,94,232,20,236,61,187,136,130,146,89,129,12,60,103,73,26,120,58,79,23,181,143,63,159,110,70,205,80,122,186,146,65,29,16,77,209,52,113,100,38,17,155,4,102,4,127,
79,89,4,255,0,66,72,31,237,189,172,233,68,99,183,133,15,73,165,172,32,95,87,212,126,15,214,255,0,129,98,72,247,238,175,66,120,183,236,233,91,182,179,203,69,85,27,61,180,134,6,228,128,5,173,126,8,212,110,
62,190,244,69,69,58,164,138,41,168,113,232,255,0,117,102,236,163,174,164,134,21,0,51,40,82,110,46,9,34,220,125,79,211,218,73,16,130,122,76,192,241,232,116,246,215,85,235,222,253,215,186,247,191,117,238,
189,239,221,123,175,123,247,94,235,222,253,215,186,255,209,223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,120,139,255,0,189,251,247,94,235,95,223,155,223,200,211,111,119,191,105,
238,62,234,248,221,218,148,157,19,186,183,246,75,248,231,101,108,12,214,218,147,114,117,110,238,221,18,20,74,173,235,67,141,161,175,198,215,109,125,203,144,137,111,90,105,139,193,90,227,83,162,177,44,
99,222,99,228,11,45,234,111,169,129,196,115,19,83,140,84,241,34,156,43,198,158,181,235,42,61,161,251,210,243,63,182,155,106,236,119,246,35,112,218,145,104,154,155,75,170,143,133,73,161,14,171,248,107,
66,6,50,40,58,14,211,254,19,211,180,104,250,70,47,225,221,239,148,131,230,29,54,227,151,113,197,223,105,183,254,223,104,84,98,90,149,104,99,234,170,190,188,90,233,226,61,108,148,177,171,1,230,106,213,
170,38,96,228,157,62,217,62,220,216,126,231,59,120,148,120,245,174,170,118,253,148,227,243,175,26,244,105,31,222,251,157,19,220,79,235,144,179,81,181,232,9,244,186,188,135,226,213,164,13,68,96,138,105,
167,207,61,22,125,161,252,138,254,113,228,247,237,55,247,191,189,122,43,174,54,186,212,154,60,190,251,235,122,13,213,154,223,82,96,167,188,57,25,118,110,27,63,67,14,35,15,152,171,165,37,35,154,170,86,
20,236,250,128,98,45,236,43,23,180,133,231,85,187,184,70,181,12,13,9,173,105,242,0,87,243,234,93,230,191,191,22,219,189,108,146,218,216,242,140,171,184,58,254,38,80,154,169,230,65,39,77,120,133,25,249,
113,235,102,191,141,191,30,186,231,226,183,74,236,94,135,234,154,26,218,45,147,176,113,109,143,198,201,149,172,57,28,206,82,170,166,166,122,252,174,111,55,145,100,70,174,204,102,50,85,82,207,60,164,0,
93,236,0,80,0,153,118,251,8,54,219,72,172,237,150,145,32,253,190,167,172,2,230,78,97,220,185,175,123,220,57,131,119,148,53,253,203,234,106,10,1,138,5,81,228,0,0,15,179,161,207,218,222,136,250,247,191,
117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,4,126,72,252,127,235,223,149,29,23,217,223,30,187,90,142,182,183,175,251,95,
107,86,237,109,196,184,186,198,199,101,168,227,157,225,170,160,203,225,178,8,29,168,115,56,60,165,44,21,148,146,233,97,29,76,8,74,176,4,29,17,81,131,67,196,31,66,50,8,249,131,158,172,173,164,214,128,138,
16,65,224,65,20,32,252,136,193,235,76,223,230,109,252,170,59,191,249,120,244,62,213,249,3,182,126,97,239,206,226,234,140,6,250,197,236,222,232,109,207,214,29,101,129,220,187,35,104,110,250,186,124,14,
203,236,24,115,155,127,14,26,190,151,1,184,39,166,167,206,203,58,93,225,169,251,145,167,198,224,203,187,39,187,188,239,54,233,182,90,111,124,225,115,22,216,197,98,105,98,88,150,68,20,210,174,91,69,88,
46,53,19,83,76,214,189,65,123,175,221,243,218,72,118,173,226,125,159,219,155,89,175,180,201,48,130,89,174,94,25,24,182,183,69,140,202,85,11,84,233,84,1,107,65,79,46,169,167,183,62,42,230,114,93,81,218,
91,211,37,190,183,63,99,118,29,118,200,206,225,113,149,251,183,42,50,179,98,40,228,131,239,23,21,183,41,41,33,162,195,225,232,242,117,20,209,44,205,79,7,150,160,21,14,229,64,30,231,78,103,246,206,238,
235,149,185,155,126,190,222,238,183,77,249,173,30,53,150,226,67,43,162,208,72,4,64,118,42,200,171,74,129,220,164,14,177,255,0,144,189,240,229,109,171,220,46,84,246,235,151,185,54,207,99,229,231,157,102,
209,107,18,193,12,178,106,49,31,20,127,104,242,196,237,220,13,116,16,117,30,166,225,178,52,251,175,174,122,235,127,99,174,248,237,213,179,246,246,65,69,185,165,168,147,27,78,181,20,179,105,39,76,148,245,
8,200,71,225,148,143,107,54,185,215,112,229,206,92,221,225,254,198,226,206,51,246,50,40,70,95,200,175,14,134,2,99,107,204,220,221,203,151,64,173,229,157,236,131,253,50,57,241,17,191,53,97,208,151,177,
242,81,71,34,83,84,0,81,143,60,130,121,39,139,30,108,160,251,54,179,148,35,128,114,189,6,249,155,111,146,88,139,70,72,106,241,243,232,202,225,40,169,165,69,154,151,208,90,225,130,253,5,133,190,159,212,
255,0,173,236,107,183,64,178,233,123,121,40,254,158,189,99,135,52,238,183,22,190,37,182,235,22,187,126,26,169,192,125,157,8,212,82,54,136,210,69,245,2,14,171,13,101,129,58,8,4,130,125,142,246,249,103,
10,81,234,8,235,29,185,134,203,110,185,149,39,180,144,16,77,124,181,84,26,140,86,191,103,217,211,147,74,36,30,177,205,136,36,122,207,251,207,22,252,255,0,177,246,98,78,56,116,30,140,188,141,164,141,46,
167,203,137,255,0,81,227,210,91,38,212,183,1,36,68,144,29,86,4,88,255,0,77,87,10,1,212,56,250,251,35,188,146,0,204,15,107,117,33,108,86,91,156,208,68,222,25,146,32,106,105,156,116,25,230,183,11,226,165,
211,44,161,99,32,133,148,18,84,3,114,86,255,0,224,127,222,253,134,46,111,222,22,239,99,164,158,61,76,219,39,43,219,238,48,131,12,32,200,23,56,207,173,41,210,82,183,118,222,50,241,201,27,41,22,244,149,
177,191,60,2,45,254,195,218,57,119,74,41,2,64,69,58,22,237,252,163,20,108,3,68,85,193,224,7,69,239,121,102,150,106,135,104,38,9,33,37,155,75,89,175,245,36,243,201,30,193,27,142,227,11,72,192,63,127,83,
183,45,109,50,195,110,138,241,126,135,14,25,232,185,101,250,247,110,119,111,103,236,172,62,237,162,105,191,135,137,203,102,241,149,117,88,93,205,65,65,24,242,72,40,183,6,46,106,108,165,52,74,19,86,145,
33,64,69,237,238,53,222,118,109,191,155,57,151,101,181,191,79,196,3,72,157,178,170,3,82,67,138,28,10,145,83,65,212,153,115,190,94,242,15,36,115,6,235,180,40,51,36,108,201,19,247,68,210,83,180,20,53,29,
205,64,116,228,130,79,16,58,59,88,207,229,201,179,7,242,228,216,255,0,54,55,215,99,119,23,99,76,157,231,252,115,59,177,55,207,96,101,242,157,99,85,241,123,37,216,185,62,183,194,165,110,220,73,32,92,158,
71,23,28,212,153,137,106,234,90,65,56,128,198,202,85,143,184,63,110,220,226,60,201,183,71,189,94,220,222,114,162,110,74,175,12,178,200,85,237,252,93,25,163,113,211,146,107,229,142,165,61,255,0,99,191,
28,139,190,220,242,205,149,173,135,63,201,179,73,36,87,16,195,24,104,239,12,26,192,93,72,112,31,180,84,19,78,32,244,43,237,172,69,38,219,152,225,233,40,233,104,169,49,23,160,161,161,165,167,134,142,130,
142,146,155,246,169,160,165,166,167,84,167,167,129,34,210,21,17,66,129,244,30,250,51,183,109,214,246,19,11,40,98,72,237,96,237,68,64,2,42,15,135,64,24,0,138,16,71,30,38,167,174,74,239,219,245,207,49,108,
177,111,30,51,203,119,124,130,73,100,149,153,157,156,138,63,136,198,172,89,88,21,32,252,37,116,208,1,78,133,106,10,223,42,233,45,24,146,51,113,169,67,45,237,98,139,107,114,223,130,125,140,173,38,208,235,
79,132,245,142,60,221,179,139,152,38,12,83,234,80,84,84,3,159,49,229,199,200,241,3,135,79,241,201,172,157,64,43,91,244,233,215,228,32,220,176,177,185,36,27,255,0,128,255,0,120,19,199,112,116,171,86,163,
207,229,142,177,222,231,108,164,243,64,35,10,227,135,19,92,230,158,181,30,157,96,50,23,109,8,127,54,213,245,81,254,38,227,218,192,250,128,35,135,69,2,47,9,133,105,80,122,231,26,36,30,69,11,170,73,13,139,
1,112,214,28,129,114,72,63,211,253,111,246,30,208,93,90,36,244,105,84,105,30,93,9,182,125,246,243,110,105,96,178,149,150,70,32,84,121,249,31,246,63,62,154,43,166,43,27,73,46,149,88,175,123,240,73,177,
109,36,0,90,205,254,243,236,170,238,88,44,237,228,41,65,80,122,30,242,198,219,185,243,22,237,106,110,84,176,12,166,135,137,3,52,62,121,198,105,158,137,215,107,238,31,37,85,74,35,146,46,202,171,171,159,
246,194,220,155,127,182,247,0,115,13,225,154,230,82,90,163,61,117,99,218,157,134,59,45,158,202,31,8,41,10,43,140,215,142,122,45,194,41,171,102,47,37,196,106,73,31,91,112,108,120,60,115,236,37,150,207,
1,212,248,26,59,116,84,4,22,234,29,125,68,40,90,32,233,28,49,41,146,105,100,33,81,35,140,22,121,29,191,74,162,40,36,147,244,183,182,221,208,2,210,58,172,106,9,98,120,0,50,73,249,1,147,210,136,99,149,142,
188,151,98,2,129,196,147,64,0,28,114,113,208,177,241,11,109,154,106,61,241,219,153,132,134,146,13,229,145,150,179,23,87,83,34,69,18,109,172,92,11,142,194,84,51,202,84,71,12,216,202,65,80,73,250,121,239,
236,79,236,134,217,227,75,191,115,189,250,132,182,187,149,157,89,168,0,129,63,78,42,147,128,10,130,230,180,20,61,98,119,223,115,154,154,93,171,149,253,165,229,231,51,239,132,170,60,104,11,16,237,223,45,
2,138,235,212,85,20,0,77,106,7,14,175,19,249,83,245,125,102,224,170,237,31,152,25,250,41,105,113,251,225,102,234,94,135,138,162,151,237,205,87,91,96,114,17,213,239,126,195,165,73,163,73,133,54,250,221,
84,177,82,209,202,0,18,208,227,217,148,178,73,115,139,62,238,115,172,124,241,206,251,149,253,129,3,99,181,38,11,96,0,1,149,79,124,180,20,204,141,231,252,32,122,245,154,223,119,15,107,110,61,167,246,163,
151,121,127,118,149,228,230,105,227,19,222,51,185,118,18,58,141,16,130,220,22,20,162,129,228,213,61,92,112,151,250,31,246,231,252,111,200,39,253,235,220,101,212,238,113,156,245,200,76,214,181,193,254,
156,219,158,108,0,185,224,30,125,251,175,84,226,131,174,66,87,250,223,254,36,127,95,200,250,123,247,91,234,93,37,111,130,84,146,226,232,202,69,191,181,111,175,211,143,126,235,68,84,17,78,133,204,87,98,
253,165,23,219,58,130,116,105,32,253,45,107,254,62,167,159,117,211,86,169,233,159,13,134,7,72,44,246,109,50,117,45,50,144,46,121,3,241,123,127,94,63,30,237,211,136,165,64,21,232,66,235,74,218,58,76,132,
115,84,202,160,41,4,250,185,224,254,63,2,254,234,194,170,71,77,201,241,116,116,168,251,131,11,138,161,142,20,153,0,88,237,207,212,16,182,252,222,222,211,120,68,156,14,152,32,3,65,210,11,112,119,229,56,
86,88,103,60,177,252,222,247,255,0,88,243,248,227,241,238,226,16,64,234,193,71,0,13,122,2,119,47,112,86,229,145,226,21,14,83,145,109,76,5,172,127,214,36,127,135,183,22,48,184,242,233,197,70,53,197,58,
2,235,178,82,85,212,60,146,49,103,115,168,127,78,79,245,32,147,199,183,58,127,53,165,113,78,162,172,231,242,72,255,0,99,199,250,194,194,252,251,247,91,234,100,18,75,173,76,122,143,168,16,63,63,67,126,
63,23,30,253,214,141,41,158,29,26,158,151,174,200,10,218,84,38,85,82,80,125,8,63,169,84,0,108,56,32,251,102,106,1,81,199,164,198,149,96,56,117,96,235,250,87,254,10,63,222,189,164,233,158,185,123,247,94,
235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,255,210,223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,
239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,116,
27,119,23,82,108,14,250,234,190,193,233,126,212,219,180,91,179,174,59,67,105,102,246,78,244,219,185,4,87,166,202,237,252,253,12,212,21,244,228,149,111,20,233,28,218,225,145,108,241,74,170,234,67,40,62,
244,202,25,74,158,7,171,35,180,110,174,167,184,30,180,121,222,223,203,199,230,15,195,157,203,184,186,19,114,245,135,103,119,159,90,96,106,107,113,253,57,222,91,11,106,228,119,189,30,255,0,234,247,144,
199,179,168,119,189,46,21,43,50,91,91,179,118,142,57,211,27,146,74,168,197,53,119,219,165,84,83,48,145,130,229,55,182,30,245,108,219,111,46,54,195,206,87,210,197,115,10,120,105,39,134,101,73,161,25,69,
125,61,203,36,103,180,18,40,203,74,156,117,132,62,246,253,220,185,139,123,231,123,14,113,246,247,104,130,123,118,159,199,40,39,91,121,173,46,91,182,102,80,227,68,150,247,11,220,234,173,173,100,171,5,32,
226,155,112,219,139,19,241,239,181,187,151,227,47,113,54,79,175,49,120,109,201,79,157,218,212,59,227,111,229,182,197,86,196,201,111,113,83,151,203,236,12,228,245,244,203,143,198,10,124,140,130,187,25,
36,146,37,60,180,213,186,17,216,199,96,223,37,243,199,41,109,247,123,231,45,190,246,131,149,37,151,198,178,149,209,213,33,146,82,76,150,210,49,31,166,20,157,75,92,124,251,176,54,231,174,68,231,171,184,
185,95,158,108,182,6,60,237,12,30,6,225,110,146,198,237,113,20,43,250,119,17,45,64,149,141,52,181,8,106,86,163,180,116,38,197,228,197,213,35,69,81,79,91,70,250,100,163,200,208,207,21,85,21,101,59,217,
163,154,26,170,119,146,25,80,173,185,4,143,114,54,144,132,52,50,164,176,156,171,163,7,82,61,65,82,71,68,41,50,110,54,212,146,9,34,156,225,163,149,90,57,17,188,213,149,128,53,31,176,244,97,54,46,236,183,
138,41,29,53,18,47,168,216,3,192,191,245,34,220,123,16,237,91,129,138,69,171,83,168,119,158,57,77,111,45,238,52,168,213,66,65,244,160,232,196,81,207,29,72,87,37,88,58,220,183,62,153,2,220,132,31,83,117,
23,227,220,181,183,93,165,204,40,7,196,7,242,249,245,132,60,207,181,92,236,219,140,206,255,0,217,19,251,26,156,20,121,227,246,30,156,100,12,22,95,193,11,113,165,57,0,159,237,6,184,246,100,203,64,61,58,
14,193,62,169,88,37,3,129,80,60,199,173,124,186,15,183,101,59,26,57,42,35,98,10,198,75,88,0,223,218,34,224,31,192,62,194,123,228,93,140,235,196,86,157,78,254,222,93,25,39,130,23,56,122,15,246,63,46,138,
182,127,122,136,90,106,42,244,53,52,218,138,217,172,29,77,205,153,77,175,199,184,194,235,114,100,45,28,213,43,214,90,237,124,170,172,35,186,180,162,73,79,219,231,208,47,150,221,15,75,44,162,130,73,62,
221,249,88,217,142,160,15,0,11,158,71,63,235,251,11,93,238,50,247,44,76,116,158,164,219,13,142,9,81,90,226,53,50,40,227,210,24,201,152,206,212,52,88,234,121,234,167,145,93,217,16,42,136,144,11,188,179,
202,229,98,166,129,126,172,238,85,84,11,147,236,140,199,119,49,121,0,192,25,36,208,15,180,154,1,79,50,72,232,78,62,135,109,132,53,196,129,35,197,43,196,215,128,85,0,150,39,200,40,36,156,1,208,93,155,220,
91,250,175,29,77,181,62,53,97,134,249,237,62,214,221,248,190,144,199,118,78,61,150,179,109,98,183,62,233,170,92,124,251,35,172,88,134,77,233,189,105,104,164,150,163,33,93,76,175,65,138,167,137,217,229,
46,2,251,143,57,139,154,166,218,246,235,219,190,95,79,22,226,82,109,222,242,159,164,133,135,116,22,196,255,0,105,41,67,250,146,40,34,48,216,201,175,71,59,103,45,219,115,94,249,99,182,243,28,130,29,190,
216,37,220,91,121,52,184,155,67,86,43,171,197,83,88,160,18,3,224,194,244,50,178,146,213,10,87,173,227,224,248,193,179,170,62,26,208,252,44,206,71,68,118,139,252,115,160,232,92,155,161,6,150,42,248,54,
124,24,137,115,112,200,7,15,77,187,34,21,130,101,245,51,169,112,110,125,195,98,32,97,16,17,248,105,249,211,143,237,207,83,239,140,67,153,107,157,85,31,103,252,87,90,135,245,119,112,246,87,84,82,100,58,
207,229,198,58,92,38,229,235,13,215,156,234,92,183,110,83,193,89,87,139,135,63,179,43,159,27,14,19,185,233,98,130,74,189,141,185,43,240,235,77,93,71,148,157,14,47,45,69,81,28,203,50,185,107,229,215,181,
190,241,72,155,13,149,191,61,163,173,132,36,67,30,226,170,210,34,21,194,195,124,20,19,25,11,253,156,196,119,45,3,86,149,28,237,247,159,238,250,214,188,215,187,75,237,73,142,107,219,157,119,83,236,142,
235,12,141,226,29,114,93,109,12,228,36,136,210,106,107,139,90,233,73,88,178,52,122,168,199,171,110,102,40,107,233,233,50,120,204,134,63,51,137,174,84,154,155,39,136,174,166,201,227,42,227,145,67,44,180,
217,10,25,106,41,106,16,173,191,67,146,7,188,165,218,239,45,183,59,88,239,182,203,216,110,108,216,98,72,93,100,66,62,213,39,79,216,193,79,203,172,17,230,203,89,182,139,217,246,205,235,110,184,177,220,
133,67,65,115,19,65,48,245,236,144,0,227,231,25,112,71,3,208,134,36,210,200,209,146,100,116,44,151,36,42,131,192,96,24,0,138,20,88,243,127,240,246,39,182,144,52,37,89,129,64,115,254,111,153,235,28,183,
221,189,161,221,85,237,227,62,43,10,168,63,10,134,173,26,140,163,72,0,80,230,160,241,29,71,106,159,19,232,23,47,168,92,145,99,174,192,242,205,110,44,127,194,254,205,99,153,52,10,154,14,129,179,237,183,
45,33,79,15,131,241,165,51,74,241,56,252,207,88,94,172,179,128,92,93,135,233,6,252,125,9,0,125,111,127,168,184,247,73,238,85,99,99,242,233,126,209,177,79,119,125,18,17,74,144,113,156,122,227,4,126,218,
252,186,67,110,172,160,90,102,88,45,172,35,171,126,147,117,54,58,75,0,46,108,47,249,2,254,227,190,96,189,102,141,162,215,216,127,195,214,98,123,77,202,118,240,201,111,184,53,176,19,174,60,143,111,30,52,
243,252,233,209,67,221,212,233,83,81,45,69,68,161,80,22,96,165,185,34,231,143,175,244,247,12,238,32,52,142,204,124,207,89,243,202,242,180,54,208,36,17,230,131,242,232,28,204,101,233,105,41,234,31,203,
5,29,29,50,52,149,21,149,50,199,79,77,4,72,164,180,146,207,43,36,80,162,47,36,146,5,189,145,92,79,28,17,60,178,72,169,2,138,179,49,1,84,122,146,112,63,195,233,212,151,183,217,77,52,138,100,70,146,225,
142,20,10,177,252,134,127,58,83,160,8,84,102,123,222,12,198,214,235,154,202,108,71,94,165,45,79,250,65,238,220,217,20,155,99,21,183,41,65,151,63,30,214,122,191,20,121,57,18,146,54,19,228,100,181,4,10,
72,13,43,250,125,128,110,239,46,57,214,222,251,107,216,164,88,57,117,84,253,94,225,47,108,73,16,32,186,195,90,23,56,161,110,7,225,25,61,11,47,175,172,57,17,44,183,109,249,94,125,241,156,45,157,132,52,
105,166,153,170,177,169,165,104,79,16,50,22,133,142,1,234,247,255,0,150,167,192,204,63,123,237,106,158,242,239,154,93,251,149,248,239,94,184,154,31,143,189,77,186,114,146,224,105,187,82,139,5,49,92,175,
112,239,188,22,58,147,29,93,23,93,110,57,224,88,112,24,38,146,40,170,232,211,238,102,5,28,39,184,151,152,185,199,115,220,126,167,101,218,121,131,112,110,78,1,81,35,145,194,248,161,5,53,178,32,1,16,254,
8,198,2,208,28,244,51,229,78,67,219,45,164,178,230,190,100,229,77,165,125,193,37,217,230,134,45,70,1,33,175,134,146,201,87,119,0,254,164,166,149,122,149,160,167,91,22,211,83,83,81,82,210,80,80,82,82,99,
177,216,250,90,124,126,59,27,143,164,166,160,199,99,104,40,226,72,40,232,113,244,52,145,195,77,71,67,71,2,4,142,40,213,81,84,88,15,96,175,144,225,212,147,159,51,83,214,80,8,97,98,64,31,227,254,31,235,
223,223,186,246,107,242,235,149,255,0,167,63,235,123,247,94,235,137,39,252,86,223,237,191,214,231,79,251,193,62,253,215,186,242,146,63,175,211,234,111,244,252,255,0,135,251,215,191,117,238,178,9,27,232,
27,158,63,199,143,168,227,253,143,191,117,238,189,229,111,237,115,244,255,0,92,142,69,135,211,250,123,247,94,234,109,54,70,122,119,213,27,178,144,0,252,143,235,99,253,111,239,221,106,153,39,207,167,6,
207,214,200,0,51,55,63,209,136,22,191,55,185,185,247,238,181,165,75,86,153,233,190,74,233,228,190,166,102,212,111,98,90,246,60,155,114,120,247,238,173,214,45,82,59,18,67,141,92,216,106,250,94,214,63,236,
71,191,117,238,185,172,83,181,236,173,114,127,55,252,253,121,4,147,207,248,123,247,94,192,207,82,226,160,171,144,174,148,98,9,31,80,126,159,215,232,120,35,223,186,214,161,235,208,213,215,219,10,124,204,
241,121,96,109,37,130,253,47,195,90,215,191,245,255,0,122,247,70,112,191,111,76,59,6,34,135,29,30,189,143,214,148,216,65,12,205,18,41,77,15,114,162,231,233,116,2,223,81,254,219,218,71,125,71,166,75,87,
3,161,168,113,199,186,117,94,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,255,211,223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,
186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,
186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,117,107,30,63,55,191,39,235,254,30,253,215,186,169,255,0,230,91,252,168,58,139,249,130,224,41,247,69,46,94,14,160,249,37,180,241,85,56,253,137,
221,20,27,127,29,184,105,50,24,201,0,119,216,189,177,179,171,194,99,123,35,174,235,228,80,30,146,164,138,154,50,124,180,147,68,226,204,183,111,220,111,118,155,165,188,219,229,85,148,96,171,40,120,221,
124,214,68,96,85,212,140,16,71,217,78,145,110,59,109,134,241,100,251,126,227,19,180,4,212,50,59,71,44,109,228,241,72,132,58,58,156,130,15,17,145,214,145,31,42,63,149,119,202,31,135,181,217,106,254,224,
232,110,194,235,12,6,46,162,65,79,242,27,225,222,75,53,190,122,7,61,5,229,104,178,57,237,129,81,73,150,173,216,45,58,70,94,74,58,220,118,152,206,160,39,112,47,238,76,218,57,159,147,111,25,90,225,110,185,
119,118,255,0,126,217,187,181,163,147,235,3,87,195,245,32,29,3,208,117,31,222,242,215,59,109,232,86,210,254,215,153,54,126,30,14,224,138,183,138,60,130,220,160,2,64,61,93,11,159,226,61,20,141,153,184,
59,158,52,74,205,129,216,189,71,222,24,152,77,212,101,226,174,216,123,165,60,127,72,43,170,112,159,198,177,73,86,109,102,242,210,83,16,223,80,62,158,228,221,182,239,157,60,53,159,101,223,54,173,242,200,
112,173,97,150,158,64,232,58,107,246,245,31,239,54,60,157,41,120,57,135,151,183,77,146,236,143,193,73,161,249,144,28,84,129,242,29,25,189,175,242,103,177,176,49,199,6,243,248,215,218,122,162,0,62,71,96,
86,109,174,198,199,48,22,12,208,197,71,149,197,229,130,242,126,180,250,172,62,158,199,219,55,185,155,254,206,85,119,191,109,247,77,35,139,90,186,76,191,178,149,167,88,221,238,15,176,124,189,205,113,188,
188,181,238,198,201,20,173,90,45,244,82,64,71,200,48,101,0,249,84,14,132,202,111,152,253,95,26,147,156,219,93,219,183,42,189,66,104,115,189,29,217,136,97,255,0,105,50,226,176,121,74,82,171,127,168,118,
7,216,229,61,250,228,95,11,195,220,118,189,242,209,199,16,246,46,105,249,173,127,192,58,198,201,254,231,30,244,197,119,245,27,23,50,114,166,231,11,18,117,71,186,36,120,173,64,10,235,192,124,235,246,244,
138,221,31,50,122,66,104,229,130,147,41,189,100,150,64,67,64,157,81,217,234,236,199,130,21,38,218,49,122,135,244,191,176,214,233,239,87,32,92,235,75,107,187,246,30,67,232,230,174,126,223,243,117,57,242,
39,221,163,221,125,163,192,151,118,218,246,148,124,22,43,184,66,202,72,226,65,10,124,186,43,155,143,185,241,27,158,169,155,106,245,247,117,110,105,89,152,40,198,245,110,224,199,66,73,184,26,234,179,241,
226,105,163,86,39,234,88,1,249,246,2,187,231,189,171,112,114,187,102,193,188,93,63,150,139,87,90,254,109,65,254,30,178,139,106,228,173,195,101,183,95,223,27,254,205,106,163,137,123,181,106,15,78,209,79,
179,207,164,229,45,31,122,238,25,67,226,250,143,27,179,49,215,37,179,29,169,186,233,163,149,33,63,170,65,183,54,144,201,85,59,42,242,85,234,162,227,242,61,164,81,207,27,135,125,135,38,165,157,175,251,
246,250,80,40,61,124,52,206,62,127,229,232,205,183,62,70,219,232,147,243,123,94,221,28,120,118,49,106,36,249,13,109,81,199,204,30,187,192,245,236,253,185,189,41,58,183,3,46,250,249,99,216,245,110,170,
58,15,163,49,81,97,182,13,60,218,198,154,174,196,201,98,171,29,40,240,52,110,47,52,155,131,47,13,61,185,104,95,244,251,6,239,247,251,5,137,9,205,188,208,251,205,218,240,177,179,30,21,176,97,254,252,101,
36,176,30,117,111,179,211,161,14,207,182,243,46,234,117,242,215,47,71,180,91,176,205,237,217,241,238,232,120,248,104,227,66,49,242,52,198,56,245,179,247,192,63,229,192,221,1,151,219,61,239,223,163,105,
101,123,223,111,109,154,173,185,214,29,109,177,146,57,186,151,227,38,11,50,138,185,216,54,124,201,79,77,14,230,236,204,245,56,74,124,142,117,96,138,24,32,79,5,26,132,212,239,24,243,15,49,223,115,28,246,
141,113,4,86,251,117,178,20,182,182,136,105,134,4,38,167,72,224,93,205,11,185,26,152,129,83,142,164,142,83,228,221,171,148,147,114,154,210,73,46,55,139,233,68,151,151,115,18,247,23,46,171,68,12,199,34,
40,199,108,81,14,212,4,208,100,214,217,239,193,31,80,69,185,230,223,237,201,246,65,208,188,82,131,24,234,171,126,119,255,0,47,173,195,222,251,161,187,243,227,150,111,103,237,14,251,159,5,73,182,59,47,
102,239,200,166,143,171,126,71,109,60,66,58,224,41,55,141,109,13,60,245,91,107,177,118,189,60,141,79,138,206,136,167,86,165,127,182,171,142,72,64,210,43,228,254,115,223,57,35,113,150,255,0,102,104,228,
183,157,2,92,91,76,3,91,220,198,43,219,42,156,84,126,23,165,84,240,61,71,190,226,251,101,203,62,230,237,182,118,123,244,114,195,185,89,72,100,178,189,183,99,29,221,156,164,105,47,4,171,66,3,12,60,102,
168,227,14,166,131,173,116,55,183,82,99,58,31,123,85,96,247,222,11,185,62,0,118,125,69,91,36,211,120,77,23,77,238,218,242,222,186,220,101,115,211,230,250,79,121,208,84,57,212,37,7,27,83,34,176,212,168,
198,194,108,216,121,131,218,77,234,237,111,118,13,255,0,113,228,126,105,114,9,8,197,172,217,207,244,126,2,181,245,10,40,122,197,254,117,229,15,126,182,29,186,77,167,155,57,55,102,247,67,145,144,21,95,
26,53,143,114,72,248,87,81,4,150,2,149,40,75,84,2,56,83,161,155,7,150,249,107,138,160,74,188,6,127,161,62,65,224,125,45,13,124,85,89,94,180,207,204,150,178,74,107,112,111,189,246,141,76,205,25,229,144,
64,46,126,150,247,55,109,247,126,248,216,194,146,236,219,191,46,243,86,223,74,134,71,16,206,87,230,81,130,215,246,231,215,172,55,230,77,155,238,145,187,223,77,111,205,156,189,206,254,222,111,10,217,89,
35,121,236,213,242,59,117,164,164,113,165,70,154,140,14,157,38,238,190,232,160,46,187,163,227,54,244,89,137,95,35,109,13,237,176,119,101,33,208,161,47,11,207,95,183,171,14,174,44,12,32,251,52,30,224,123,
145,102,170,55,95,100,119,33,32,173,90,214,234,41,86,158,180,52,61,20,199,236,143,177,155,153,150,78,95,251,214,236,146,66,228,16,183,246,19,64,226,152,248,149,130,228,0,42,20,103,237,233,186,79,145,89,
180,93,53,61,1,223,49,202,20,198,33,77,165,136,158,252,2,195,238,169,183,20,180,214,107,253,117,1,237,137,253,214,220,194,149,159,218,126,105,89,61,4,8,195,246,214,135,161,6,217,247,119,229,133,100,54,
94,255,0,242,28,209,129,64,126,165,227,106,121,212,28,228,208,159,62,29,7,217,206,254,223,149,168,244,248,111,141,29,209,85,40,26,75,101,151,100,237,234,56,238,44,190,90,202,221,217,80,218,45,207,249,
178,71,244,191,176,174,233,238,46,251,122,89,44,253,167,223,188,83,195,198,240,225,31,157,65,3,246,245,52,242,135,180,92,181,180,44,66,239,223,46,87,120,20,124,54,186,231,62,130,132,56,39,243,76,241,232,
5,205,85,252,155,222,242,203,14,47,98,108,222,190,164,98,218,234,178,217,140,142,252,204,82,70,79,46,113,248,42,92,118,26,41,20,115,251,149,126,59,142,120,246,3,185,155,220,189,225,159,192,216,172,182,
216,188,218,87,105,221,126,116,94,208,71,207,29,100,70,216,125,171,229,203,120,205,199,50,207,127,32,24,10,171,2,55,165,53,81,136,255,0,75,83,210,84,244,126,6,162,178,134,155,182,247,126,230,238,173,211,
43,26,172,79,87,237,12,106,110,124,141,109,77,58,188,236,105,186,247,104,20,194,80,194,130,51,122,172,229,87,219,199,110,95,250,129,57,170,235,145,57,58,204,238,222,232,243,218,222,52,96,176,131,196,64,
149,249,65,27,105,30,95,218,183,14,10,78,58,29,242,173,247,61,123,129,122,118,63,102,189,185,185,96,236,17,174,76,50,36,66,188,9,184,149,53,61,61,33,82,60,139,173,107,213,234,124,66,254,86,82,246,214,
220,218,29,141,242,198,146,131,108,244,181,84,120,125,209,176,126,34,108,220,180,21,177,238,184,41,157,42,240,121,223,146,27,235,22,145,65,157,165,18,196,178,71,180,113,154,49,176,50,129,83,36,196,123,
143,121,139,220,11,206,113,178,182,130,193,22,211,148,88,43,197,111,17,160,112,62,7,149,128,26,177,144,180,10,15,0,15,67,173,131,219,8,249,63,120,186,189,230,89,141,255,0,63,68,94,41,174,36,90,8,26,189,
241,219,199,86,9,78,5,234,100,113,241,49,24,235,96,200,227,138,24,169,233,169,160,167,164,165,164,166,167,162,164,163,164,130,58,90,58,42,42,56,82,154,138,138,134,146,5,88,41,104,168,233,162,88,226,141,
0,84,69,0,15,97,15,202,157,14,133,50,58,236,19,98,13,175,244,252,143,246,62,253,214,250,232,18,72,252,143,207,31,225,253,127,228,94,253,215,186,238,227,144,62,191,79,168,255,0,91,252,126,158,253,215,186,
232,130,220,19,244,255,0,1,239,221,123,174,67,250,30,73,255,0,15,168,255,0,122,191,191,117,238,189,199,234,31,95,235,126,63,226,158,253,215,186,224,110,77,175,245,31,145,111,175,63,143,245,189,251,175,
117,229,227,143,197,200,63,227,192,22,247,238,189,211,173,6,54,162,181,130,71,27,59,27,112,171,114,65,60,17,244,22,252,123,247,90,108,2,107,78,133,60,39,87,229,242,33,116,210,205,102,185,226,54,181,184,
60,253,9,30,234,89,71,19,211,94,33,205,56,116,39,227,58,42,182,81,121,97,123,146,160,217,91,131,107,143,241,255,0,99,238,134,101,30,93,87,91,215,142,58,94,99,190,61,147,167,201,11,18,77,193,34,255,0,146,
7,228,255,0,190,30,235,227,215,208,117,66,227,53,110,151,120,222,128,162,139,70,184,237,96,57,63,129,197,238,15,211,221,90,98,56,30,168,72,35,29,12,155,91,174,241,219,123,198,200,168,197,5,244,232,28,
155,242,73,181,175,199,182,75,177,243,235,68,215,161,32,11,0,63,160,183,186,245,174,187,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,255,212,223,227,
223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,
223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,116,217,147,202,83,98,224,105,167,112,44,9,11,127,173,135,55,254,158,246,5,77,7,91,0,158,29,
1,155,135,186,41,49,207,36,49,203,23,164,27,90,215,184,252,95,155,251,112,66,198,157,88,47,175,30,130,250,222,254,145,75,233,147,143,193,214,110,5,245,89,108,73,30,191,110,8,72,197,122,182,128,64,58,113,
210,74,175,191,242,42,29,105,230,42,178,43,7,66,250,227,145,28,16,201,44,76,26,57,80,131,98,172,8,247,115,8,36,18,120,117,178,165,134,6,71,90,226,255,0,58,79,135,253,37,217,189,75,31,201,93,147,212,155,
67,99,118,119,89,238,170,12,159,98,238,158,177,196,175,95,110,29,227,176,179,238,184,172,141,94,114,175,103,28,66,100,234,182,214,65,225,172,89,165,141,156,32,125,68,223,216,107,153,223,115,218,182,245,
221,182,43,201,45,174,96,122,177,67,74,169,243,52,226,65,167,229,212,197,236,190,219,201,188,199,206,17,242,143,62,109,73,121,180,238,81,24,227,44,72,104,230,21,43,161,171,141,98,170,65,168,39,203,170,
19,235,174,180,236,8,228,95,238,95,125,111,76,47,139,132,162,221,88,157,185,190,241,193,22,193,16,205,148,161,131,42,232,203,245,45,80,205,111,101,59,71,222,99,221,62,87,40,97,221,188,112,191,198,42,127,
105,7,252,157,100,15,50,127,118,167,176,94,228,195,45,184,146,230,201,90,189,165,86,69,175,203,79,134,212,232,212,236,221,135,243,11,47,147,166,194,224,247,135,74,110,105,42,100,17,197,46,95,108,238,205,
191,87,49,115,109,76,152,154,250,250,84,55,63,69,75,91,220,175,182,125,254,253,193,183,72,160,189,216,236,167,110,25,141,107,251,65,29,98,7,63,255,0,113,63,180,150,98,239,122,178,247,18,238,222,223,36,
232,121,210,149,53,248,89,92,126,93,8,29,159,210,95,50,250,218,132,213,238,211,210,120,205,81,43,9,169,177,91,211,44,10,176,12,174,145,201,85,135,179,127,200,71,252,125,152,238,127,127,14,110,100,250,
118,228,77,189,38,111,196,87,254,135,63,230,232,19,237,199,247,50,251,123,184,93,155,173,187,223,141,212,195,31,24,139,179,112,62,158,26,15,216,71,64,151,86,245,127,104,119,6,241,217,184,61,231,222,81,
236,188,30,228,236,140,6,199,206,62,192,235,156,91,228,168,104,183,7,220,69,6,66,135,35,186,50,53,198,58,129,88,137,26,169,5,125,119,230,222,192,167,239,133,238,102,251,204,91,102,193,26,91,89,91,92,17,
87,137,6,161,149,20,21,7,57,175,83,94,235,253,217,222,212,123,121,203,188,203,189,221,111,151,187,182,229,97,103,36,241,164,218,180,57,74,18,164,150,170,174,154,154,140,226,157,93,54,205,254,79,159,14,
182,229,104,200,118,47,250,96,249,9,149,133,154,57,127,210,239,101,101,23,108,212,52,110,192,249,182,54,204,143,109,237,217,32,114,57,138,116,168,82,56,36,251,20,110,91,238,253,187,60,135,117,223,175,
46,73,38,161,228,96,191,62,213,160,167,202,157,66,155,86,193,203,219,52,81,174,207,177,89,218,198,0,161,72,215,87,203,184,130,73,30,189,88,95,92,245,127,87,116,206,223,109,169,212,61,109,176,250,175,108,
202,218,167,194,117,246,216,197,109,138,42,182,31,219,175,56,218,120,170,114,18,127,203,121,36,231,250,31,100,232,136,130,145,168,81,242,232,245,157,152,213,220,154,250,244,182,51,115,244,244,159,169,
31,212,223,145,197,189,219,170,18,117,1,76,117,203,200,44,13,207,211,232,44,73,255,0,120,247,238,173,215,69,139,47,60,127,175,254,22,227,253,141,253,250,185,167,159,85,248,148,22,199,77,153,204,78,23,
116,225,170,118,214,235,193,224,247,102,220,173,141,160,173,192,110,156,62,55,112,225,42,162,113,165,146,108,102,94,150,178,148,161,83,205,148,123,243,0,203,71,0,175,161,207,91,6,143,138,134,245,29,17,
109,235,252,174,254,8,111,26,185,178,148,189,21,15,87,230,39,102,121,115,29,21,188,119,119,81,84,60,204,117,9,36,199,237,172,170,225,36,10,252,219,237,52,147,245,227,219,150,83,220,109,210,120,219,109,
228,246,210,255,0,20,50,60,103,254,50,195,164,91,150,221,183,238,240,27,109,235,108,181,189,182,63,134,226,40,230,95,216,234,71,64,142,99,249,70,236,65,81,75,15,94,124,159,249,61,182,170,50,25,26,44,94,
43,9,156,159,174,251,50,158,163,35,149,158,58,28,109,28,18,110,29,155,22,97,195,84,74,46,76,236,193,65,55,227,216,243,105,247,67,220,173,185,210,59,46,121,191,17,3,90,72,194,80,0,227,135,7,0,117,20,239,
159,119,255,0,100,55,223,18,93,203,218,189,160,202,195,45,20,94,3,19,229,70,135,65,7,230,41,213,62,118,15,80,252,132,233,222,242,236,206,136,222,157,213,72,115,93,105,190,178,155,63,33,94,58,187,108,223,
33,73,4,145,203,141,204,192,177,213,81,160,139,39,140,169,138,81,96,20,146,109,199,184,239,125,251,232,123,217,203,247,87,86,45,121,107,40,73,10,134,120,99,12,64,38,135,11,74,145,156,122,245,150,62,218,
127,115,255,0,221,55,220,206,85,217,249,198,210,231,112,179,91,171,127,17,162,141,229,101,87,173,36,140,86,94,1,129,21,52,199,151,86,207,214,31,202,121,123,27,173,169,55,222,99,229,87,100,79,53,118,48,
213,46,39,109,245,239,95,224,98,242,136,3,152,141,94,70,45,196,214,44,45,117,69,107,126,125,175,63,121,223,119,249,135,100,55,167,123,137,36,43,90,8,99,255,0,14,154,245,29,143,184,71,221,219,144,57,198,
77,153,118,75,183,182,73,66,150,241,229,4,142,31,15,136,84,126,195,213,124,238,191,139,59,23,109,110,12,174,27,118,102,55,222,247,135,21,89,52,70,159,117,110,252,148,120,137,22,7,101,50,75,135,194,182,
42,128,141,35,149,183,140,253,52,145,199,188,105,230,95,124,189,214,230,35,61,174,233,205,247,62,13,74,148,66,80,82,185,20,95,46,186,181,237,39,220,71,238,163,203,150,59,78,251,181,123,93,5,230,226,200,
174,30,233,154,106,49,81,74,12,82,159,111,67,150,217,248,255,0,180,122,15,23,181,59,163,180,251,11,167,254,31,116,254,85,90,109,171,253,241,138,74,45,217,217,84,241,27,79,46,199,235,109,181,71,62,233,
220,20,15,244,106,201,99,88,28,255,0,108,155,251,174,205,236,191,57,123,157,97,52,115,163,164,83,45,67,201,89,30,135,131,105,39,0,241,26,136,175,30,136,253,227,251,196,251,49,237,140,178,114,119,34,237,
177,222,238,150,207,162,88,118,248,227,130,214,7,92,20,146,226,129,100,145,78,24,38,178,60,201,234,208,254,36,124,139,248,219,218,123,46,143,99,116,167,124,236,254,217,168,217,141,83,140,111,176,163,203,
109,140,196,116,85,85,85,85,216,202,121,182,246,231,165,160,200,163,195,3,178,94,49,36,100,169,179,126,61,228,70,215,201,60,193,200,252,187,178,108,155,236,134,107,139,104,124,63,20,46,144,225,79,105,
165,77,48,115,158,185,177,205,252,199,101,205,124,217,190,115,13,134,222,214,144,94,203,226,120,76,193,202,49,3,87,112,0,53,78,65,167,14,142,27,41,212,65,22,32,88,131,112,126,191,145,245,183,252,79,183,
122,15,245,198,194,246,35,253,127,175,63,208,14,127,175,231,223,186,247,93,139,14,126,132,30,127,195,241,254,199,143,126,235,221,119,110,77,237,110,77,199,215,235,126,111,239,221,123,175,112,64,254,128,
223,253,183,245,227,129,239,221,123,175,125,77,199,251,197,184,191,228,95,143,245,253,251,175,117,200,127,79,233,254,251,253,111,126,235,221,112,250,240,198,255,0,239,31,225,248,31,94,126,158,253,215,
186,228,166,228,1,192,184,81,197,238,127,214,231,139,123,247,94,232,115,234,213,197,154,250,117,173,9,111,34,43,106,228,0,72,189,174,120,185,247,86,169,4,1,158,152,151,141,124,186,178,13,161,140,192,203,
73,19,82,195,19,148,64,195,79,208,139,105,245,115,245,246,136,134,25,61,48,75,100,126,30,151,201,77,78,128,4,134,53,177,184,178,40,183,251,27,95,221,107,231,213,122,204,21,71,208,1,245,252,127,95,175,
191,117,170,14,187,247,238,183,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,255,213,223,227,223,186,247,94,
247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,81,
234,170,18,150,9,39,127,210,138,79,250,231,240,63,216,251,247,94,243,167,64,150,230,237,88,241,140,209,198,234,15,32,129,97,113,171,232,79,212,17,237,197,140,176,199,87,209,156,158,131,86,239,25,22,123,
180,132,114,9,26,201,32,127,177,250,16,63,226,190,221,17,184,82,190,93,108,133,62,93,43,177,189,231,69,34,143,52,136,79,245,118,31,78,77,197,237,127,116,240,88,113,234,172,160,14,158,255,0,211,110,30,
222,163,17,189,254,140,7,251,99,127,175,189,248,39,202,189,123,79,207,166,60,151,124,98,225,141,132,83,5,63,65,96,186,184,3,128,127,171,127,95,122,240,91,173,233,249,244,8,111,14,240,25,24,100,134,9,26,
204,24,112,73,63,77,54,22,250,158,125,188,177,230,173,213,214,54,24,166,122,44,57,157,195,81,93,60,146,180,142,117,179,115,200,23,60,223,131,249,246,239,160,233,245,93,35,60,122,77,181,92,172,13,153,152,
253,126,140,1,35,240,13,237,113,239,124,58,177,169,24,235,137,158,70,181,245,220,241,96,108,47,244,189,143,250,252,123,214,122,240,53,21,232,183,124,193,202,98,118,175,193,239,148,125,229,216,181,233,
141,233,221,181,181,50,155,6,58,10,106,19,145,204,246,14,232,207,84,209,109,245,130,2,218,142,51,109,225,114,153,40,228,154,72,81,234,170,76,12,177,149,250,251,54,177,217,32,222,230,77,146,101,46,215,
72,67,102,129,16,140,53,124,219,204,87,30,189,94,199,120,186,217,119,61,187,120,178,32,93,218,206,146,167,204,163,3,79,207,32,159,32,107,214,160,123,91,229,15,199,142,188,163,161,167,92,79,202,158,197,
169,167,163,165,167,174,220,88,45,181,181,186,251,110,150,134,36,87,168,197,208,102,40,183,6,86,170,11,126,147,87,226,118,2,228,243,237,85,183,221,203,147,132,90,47,230,51,201,78,47,41,6,191,32,148,3,
236,169,29,100,92,191,124,207,120,224,156,205,177,71,181,88,67,252,62,7,142,79,201,158,66,56,252,148,83,203,171,56,248,113,242,39,171,251,39,59,79,188,58,175,122,215,239,26,61,154,240,229,187,15,174,183,
126,18,147,108,119,134,195,219,144,78,163,33,188,162,192,99,106,171,176,61,157,178,48,215,215,145,170,195,200,153,12,117,61,230,154,139,196,172,226,42,231,239,187,108,187,58,141,207,148,231,118,208,117,
120,14,117,43,211,52,142,67,66,26,131,10,245,12,112,13,105,212,203,202,159,125,215,230,237,178,126,79,247,91,101,130,214,230,225,116,69,127,107,81,14,178,59,69,196,44,88,199,83,129,34,29,35,205,71,30,
182,3,249,201,179,177,59,175,165,54,254,232,198,165,37,109,45,126,22,130,178,146,190,136,199,61,53,117,45,77,36,115,210,213,82,212,68,76,83,83,212,66,225,209,212,217,148,251,132,121,190,212,165,157,157,
200,66,178,46,8,34,132,17,130,8,242,32,130,15,66,15,187,246,250,214,188,235,123,183,201,40,48,180,134,153,168,32,159,243,83,173,115,169,39,168,218,13,185,50,52,20,241,79,93,181,183,6,209,222,20,180,179,
161,104,170,37,192,238,26,74,151,134,72,208,171,24,229,136,50,27,16,108,110,15,30,193,123,108,239,31,54,242,133,192,248,205,210,160,167,169,56,254,99,172,152,247,75,111,134,125,187,126,183,144,233,130,
227,108,185,86,62,129,161,124,245,179,14,34,181,231,162,12,202,234,141,79,138,175,167,141,228,105,30,158,151,55,133,199,230,224,160,150,86,37,165,147,29,247,205,6,166,58,138,34,234,230,231,222,115,238,
113,164,119,146,20,20,86,205,61,13,77,122,226,85,153,102,182,64,90,172,5,43,235,76,87,167,51,39,23,7,143,241,250,95,129,197,143,178,254,149,83,133,122,236,74,126,160,158,77,135,38,192,255,0,173,245,2,
222,253,214,250,239,88,254,167,235,127,165,205,185,255,0,91,243,239,221,123,174,66,81,107,92,129,253,62,188,125,15,248,251,247,94,235,177,39,22,212,45,110,120,230,255,0,159,168,189,189,251,175,122,245,
192,61,248,44,47,244,181,207,212,218,194,255,0,94,127,195,223,186,213,7,10,99,167,29,181,155,166,193,118,103,81,229,42,200,251,42,13,255,0,73,93,88,88,112,176,209,209,202,124,174,13,239,224,103,214,15,
248,95,217,166,215,106,215,111,119,10,142,227,3,83,237,60,63,111,14,146,222,200,34,133,88,156,106,29,81,175,243,118,234,92,207,87,124,244,222,59,246,69,168,159,106,247,149,6,39,125,109,188,206,135,106,
58,154,138,90,88,168,114,84,48,212,216,196,239,74,234,24,40,36,136,217,77,128,247,4,123,237,178,194,144,114,206,255,0,107,14,149,154,220,193,53,60,166,135,129,62,140,200,65,249,231,211,174,149,125,192,
185,208,238,92,185,205,156,139,119,113,91,221,174,240,203,26,147,147,109,117,220,8,21,202,137,1,24,225,90,117,114,31,4,115,63,222,15,143,59,115,91,137,60,113,73,3,155,129,254,235,11,99,254,183,178,126,
67,151,199,216,21,8,200,36,116,8,247,230,208,109,254,226,110,58,84,229,131,127,63,248,190,171,167,121,236,237,181,77,242,27,179,183,14,230,193,29,227,139,234,157,135,216,125,201,7,90,65,82,148,213,157,
169,152,216,88,201,51,24,109,133,73,35,178,235,76,173,108,106,245,17,33,242,205,79,27,164,96,185,3,217,127,183,188,175,97,204,62,227,141,186,254,85,91,104,228,50,105,63,136,134,2,159,96,39,81,167,167,
165,122,154,125,210,247,83,153,185,23,238,189,6,229,203,41,32,221,47,228,138,192,220,165,107,105,28,200,117,202,15,225,118,0,198,141,248,75,87,141,58,171,94,132,248,43,243,107,249,179,246,70,253,249,75,
221,25,125,189,212,91,110,90,198,27,231,182,59,150,162,60,38,19,171,182,221,28,11,45,22,192,235,14,191,172,154,158,109,191,183,54,190,19,68,113,153,86,142,144,1,174,73,24,147,239,161,91,143,51,108,92,
145,103,22,211,183,89,180,247,26,123,85,69,21,136,252,78,250,123,205,124,151,128,198,58,228,204,67,7,66,247,103,39,45,154,147,251,120,146,114,78,79,71,119,227,94,119,249,83,252,84,249,11,214,63,20,122,
22,183,127,124,156,147,185,59,42,143,172,126,67,252,181,204,81,209,208,244,126,50,170,178,10,136,40,112,219,95,112,36,34,145,55,5,46,225,241,45,29,118,21,216,83,206,108,213,78,141,98,19,220,151,154,183,
235,11,157,251,115,181,142,37,130,45,81,69,74,54,154,241,209,196,173,50,117,100,210,189,89,161,104,192,96,77,56,212,122,252,207,217,192,117,114,149,56,156,207,93,238,188,199,81,239,70,203,197,185,246,
214,91,51,69,182,242,57,218,42,184,14,255,0,217,84,85,30,93,191,185,112,249,89,99,20,89,250,177,136,150,56,235,86,41,94,162,57,34,38,69,4,147,238,51,149,67,82,120,233,225,54,113,228,124,193,30,93,46,138,
80,234,42,123,252,199,78,63,95,197,143,248,243,199,252,72,231,233,237,142,157,235,161,245,255,0,121,224,253,73,252,19,197,255,0,195,223,186,247,93,129,114,110,63,196,95,146,47,254,220,91,143,126,235,221,
120,240,56,252,216,91,253,191,211,250,19,239,221,123,174,192,183,250,223,239,175,254,30,253,215,186,233,77,128,38,247,63,241,95,126,235,221,119,107,115,110,63,38,223,95,240,254,164,251,247,94,235,214,
39,144,13,197,237,245,191,31,225,239,221,123,167,236,53,117,69,45,76,46,140,80,163,35,112,126,182,63,159,175,208,159,126,234,172,161,129,29,29,254,178,236,209,142,164,141,42,103,4,136,213,110,196,31,160,
231,253,129,183,62,211,203,25,57,28,58,76,64,53,95,49,208,227,75,218,244,213,44,170,141,31,54,91,122,79,36,253,126,159,211,219,98,63,94,171,163,231,208,159,133,203,166,86,29,118,210,246,6,195,232,87,242,
126,182,184,39,155,123,108,210,184,234,164,80,211,167,191,122,235,93,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,
127,255,214,223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,
239,126,235,221,123,223,186,247,76,59,130,88,62,198,88,100,149,84,176,55,5,128,227,73,6,231,139,125,125,237,120,245,239,48,122,38,27,254,134,141,103,149,197,64,36,107,224,56,181,238,77,173,168,95,243,
111,106,162,36,26,30,157,57,24,232,179,230,170,4,82,200,176,203,250,91,139,53,239,193,224,255,0,67,111,241,246,247,78,198,160,138,158,35,164,183,241,138,184,135,19,200,5,244,250,88,95,235,192,60,254,7,
191,116,238,145,93,84,207,92,91,61,93,114,4,206,120,224,22,54,255,0,99,102,22,63,237,253,251,170,148,81,144,181,61,96,25,10,234,162,1,145,217,201,210,64,99,123,88,255,0,79,193,183,251,127,126,235,97,70,
14,154,30,148,56,221,169,154,202,133,49,197,43,43,17,253,147,253,171,114,45,248,22,255,0,99,239,196,129,196,245,163,34,142,25,233,97,75,212,185,105,83,92,209,178,165,181,95,75,88,129,254,55,250,223,221,
117,175,175,85,50,159,37,233,139,49,182,232,240,193,146,121,84,200,53,90,231,73,4,127,197,72,255,0,111,238,195,173,163,23,213,94,131,12,254,107,17,130,160,200,103,114,213,212,184,204,46,14,134,175,45,
151,201,214,76,144,81,227,177,184,248,205,69,85,101,92,236,85,34,134,24,16,146,127,39,129,114,64,247,100,70,145,210,56,193,50,49,160,3,137,63,46,174,112,43,92,14,131,31,149,219,195,109,244,31,242,219,
221,253,159,217,153,125,181,247,24,61,183,71,216,125,119,215,217,250,140,93,94,79,59,216,25,157,199,75,184,250,215,19,146,218,57,69,159,238,41,178,149,50,83,203,89,4,240,89,233,25,199,215,216,187,106,
2,243,117,183,176,183,70,214,221,142,194,180,85,2,140,218,135,166,120,30,61,20,72,172,36,105,107,216,9,160,255,0,7,237,234,177,113,255,0,207,31,179,49,59,38,139,116,246,23,242,233,248,189,85,180,229,199,
83,62,74,131,5,93,138,161,201,152,94,21,53,2,154,147,35,129,150,143,83,11,232,79,160,60,123,63,126,73,132,201,72,119,217,195,215,4,214,159,47,58,244,233,18,232,12,80,105,35,215,252,253,2,125,131,212,95,
31,255,0,153,166,203,193,252,217,254,94,61,13,221,95,26,126,84,236,125,232,41,177,57,13,157,214,149,67,169,115,219,227,10,244,242,228,54,174,240,220,56,134,131,108,83,81,53,60,186,106,107,149,22,153,169,
157,227,168,82,11,15,102,54,151,151,220,185,115,251,159,120,189,138,123,39,80,74,150,238,210,120,50,3,154,215,128,245,233,35,70,146,198,204,232,52,48,166,113,249,99,252,35,61,92,246,215,233,222,246,192,
252,124,172,234,189,199,31,90,111,136,154,170,12,238,19,1,178,55,69,70,54,163,173,107,51,24,200,106,119,150,199,197,209,111,10,106,37,202,108,202,61,218,245,51,225,68,53,36,210,82,78,41,192,41,26,31,112,
39,185,156,139,39,52,180,211,108,145,44,19,55,16,248,87,97,80,26,171,93,36,138,87,28,106,124,250,156,61,154,247,83,110,228,77,226,202,231,127,154,121,109,163,193,116,80,204,20,112,168,212,43,65,143,152,
227,209,48,234,47,229,209,216,121,238,207,147,119,247,5,61,46,209,235,122,122,184,30,187,101,211,87,82,101,55,174,248,138,150,169,42,163,197,195,21,12,181,24,252,38,38,178,104,149,103,171,154,66,194,45,
65,20,177,30,193,28,145,236,205,222,223,187,88,111,60,205,44,77,37,164,158,36,81,165,89,124,74,81,93,216,210,186,114,66,211,39,143,14,178,3,223,159,189,175,46,115,119,45,183,45,251,125,103,122,38,184,
132,36,247,83,1,22,148,63,18,68,128,150,37,198,11,49,160,4,211,171,30,220,144,193,136,236,12,229,5,45,45,46,63,31,147,130,154,169,40,105,101,146,88,41,51,148,148,240,12,149,37,48,145,152,199,79,75,64,
208,71,164,88,6,136,240,15,179,243,205,178,221,251,165,204,28,174,110,21,246,180,177,136,193,145,95,30,44,220,140,113,26,100,66,115,134,13,233,214,32,195,181,8,249,79,110,221,74,17,114,103,96,248,255,
0,67,127,236,191,154,183,228,71,92,111,254,35,250,254,110,120,181,248,22,82,63,216,251,25,244,87,215,129,23,250,254,62,166,195,159,240,185,252,251,247,94,235,190,63,168,228,222,225,191,63,225,253,63,227,
126,253,215,186,247,31,134,98,127,215,252,255,0,175,111,126,235,221,122,255,0,80,77,190,128,90,215,63,236,0,36,123,247,94,235,176,7,4,127,102,228,127,177,255,0,97,127,126,235,221,64,208,175,184,240,14,
241,137,214,8,51,19,173,51,42,179,212,51,83,199,4,235,76,24,139,86,45,43,179,69,253,89,109,249,247,30,115,143,53,110,28,161,204,156,135,186,90,204,255,0,66,37,184,19,196,56,76,133,82,171,243,101,21,100,
30,163,231,209,238,213,181,193,187,109,155,245,179,160,51,21,140,163,127,1,5,141,126,194,104,15,200,245,51,191,190,63,237,143,153,29,47,75,210,219,215,53,79,131,222,27,90,127,239,47,70,118,125,66,153,
169,168,107,154,35,23,240,76,193,80,103,124,46,66,59,69,50,11,180,76,47,107,173,189,203,124,195,179,108,60,233,203,210,4,62,54,203,127,26,200,25,0,45,20,148,172,115,198,56,106,90,144,234,105,81,80,104,
122,247,181,158,228,115,55,179,124,255,0,183,115,126,200,128,238,118,133,162,184,183,144,149,142,234,217,136,241,109,229,244,173,3,68,224,18,140,3,12,87,160,127,226,158,192,239,175,142,27,79,39,212,221,
141,213,123,238,175,55,141,172,168,139,9,146,217,91,118,183,117,109,141,203,4,154,133,62,67,15,184,168,67,98,97,165,149,72,44,106,165,135,195,253,178,45,238,12,229,239,111,121,175,97,107,157,184,53,172,
214,101,142,137,132,170,138,65,254,36,106,58,183,168,161,207,10,245,149,222,232,251,207,237,63,184,251,133,175,54,109,155,132,246,178,200,139,226,218,207,27,120,209,56,20,101,212,181,73,86,181,210,234,
104,194,149,3,161,167,168,190,34,214,98,123,42,163,228,31,102,225,168,235,183,234,215,84,54,201,194,100,218,44,158,210,235,152,228,82,167,113,101,70,131,14,238,222,197,27,246,98,64,104,104,15,58,164,113,
127,114,55,40,114,6,215,203,151,19,110,83,206,46,119,249,171,170,69,168,8,167,140,112,230,160,31,198,231,44,48,0,29,66,158,232,253,225,55,222,118,229,203,62,64,216,212,217,114,4,12,172,209,208,120,183,
114,41,236,121,206,116,198,135,41,18,154,106,163,49,36,116,182,249,139,252,184,250,19,231,87,198,237,241,212,155,147,55,156,219,59,190,166,151,35,186,176,221,171,134,204,86,109,233,232,247,69,13,36,213,
148,223,223,90,108,93,69,45,22,226,217,47,50,90,166,142,180,74,145,196,204,201,102,30,228,139,93,254,251,104,220,45,175,76,73,37,178,144,166,34,42,41,194,168,72,37,92,121,17,74,240,235,31,173,100,32,148,
4,247,18,107,243,255,0,55,90,192,244,231,242,170,254,103,27,207,170,176,125,101,93,213,189,79,178,58,107,41,95,73,73,65,216,79,191,182,190,23,41,77,181,40,242,209,188,123,199,106,97,98,175,73,197,108,
180,244,191,115,143,242,120,165,46,200,77,190,190,228,171,238,116,229,203,9,110,99,142,238,89,39,226,99,240,201,26,233,240,51,122,102,141,242,249,244,189,110,46,228,183,54,238,171,225,154,10,249,227,207,
171,196,239,140,111,204,61,143,159,234,126,180,216,175,212,221,135,241,59,102,226,182,253,62,239,198,119,199,117,96,55,39,201,236,142,127,29,70,184,218,253,211,212,155,159,109,85,85,102,246,174,230,137,
52,203,65,76,69,83,84,214,187,69,34,253,188,133,61,198,246,144,236,215,246,215,183,55,43,44,91,147,84,175,134,133,97,3,136,86,13,196,122,159,78,168,88,197,34,133,173,15,219,94,135,109,201,135,222,93,97,
84,184,158,198,195,231,164,196,136,233,39,195,246,146,96,229,109,185,151,199,215,82,195,89,67,22,244,143,21,247,103,98,111,74,72,38,88,114,80,85,36,116,70,169,25,225,151,75,105,1,54,128,176,18,68,48,107,
143,60,96,211,212,122,124,186,92,151,17,181,84,176,12,58,203,12,176,84,211,211,86,82,212,83,213,209,212,167,146,150,178,142,104,170,168,234,162,252,75,79,85,78,242,211,212,33,191,5,24,143,105,200,35,4,
80,244,240,243,235,157,205,255,0,160,255,0,90,231,253,99,253,47,239,93,111,174,141,143,6,246,189,254,134,255,0,239,95,78,125,251,175,117,158,10,118,157,244,199,234,36,218,195,146,73,250,240,63,7,252,61,
251,175,19,78,61,8,88,110,188,202,100,209,76,112,189,155,144,116,158,63,173,201,6,254,244,72,28,79,84,241,23,215,165,245,15,74,229,231,11,170,38,96,57,31,182,192,139,255,0,75,14,61,215,88,173,58,161,148,
249,47,79,145,116,70,93,137,253,179,254,23,86,185,39,233,99,107,253,125,232,202,163,203,170,248,166,188,5,58,153,31,68,101,210,69,253,143,161,4,21,13,123,253,79,54,250,159,241,227,221,124,101,244,235,
222,35,252,169,210,183,21,211,153,184,202,222,54,80,8,245,6,54,54,54,181,191,62,253,227,47,77,234,169,36,211,161,131,109,245,85,108,18,70,106,81,198,150,62,166,34,214,28,143,173,190,167,219,109,32,36,
245,237,64,112,232,193,97,112,235,138,133,80,17,125,36,16,9,63,91,95,243,167,241,254,62,217,99,82,79,84,38,185,167,79,158,245,214,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,
247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,255,215,223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,
126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,134,121,226,167,140,201,43,132,81,253,79,212,255,0,65,239,221,123,143,14,131,109,197,216,116,88,181,117,73,16,48,63,91,130,194,223,239,28,
159,246,62,236,20,146,5,58,184,67,92,240,232,177,111,62,225,169,155,204,144,73,193,36,254,178,72,177,231,155,147,115,237,80,136,0,58,218,138,87,162,219,157,221,245,249,39,102,146,71,55,45,244,107,155,
22,39,143,193,22,246,224,0,96,116,242,198,8,169,233,3,81,83,36,172,196,220,146,78,162,110,63,167,244,191,215,222,250,118,148,224,58,136,176,203,59,4,10,108,126,160,127,94,15,226,246,227,241,239,221,111,
165,62,31,103,229,178,108,190,26,119,42,199,240,166,194,223,155,88,95,254,39,223,190,222,29,54,206,7,14,61,11,88,174,190,92,63,138,163,39,14,160,57,58,214,192,255,0,80,71,251,11,219,221,117,143,46,61,
53,173,141,123,186,20,113,187,179,109,96,97,17,45,52,69,134,147,254,108,1,113,248,183,244,184,252,31,109,178,51,86,189,104,124,186,133,155,237,250,17,73,52,20,241,198,164,163,34,216,2,1,189,191,196,218,
222,244,176,208,130,79,91,21,53,20,232,169,110,188,244,153,9,170,171,42,167,88,41,33,87,169,154,121,229,88,169,233,226,0,151,146,105,31,74,198,138,63,39,253,239,218,128,9,33,84,103,133,58,125,64,69,249,
116,12,111,94,178,236,62,230,234,14,205,155,96,109,220,102,225,220,255,0,221,28,180,253,17,178,55,98,73,71,183,183,255,0,104,99,149,106,182,214,79,121,199,80,169,4,219,82,134,182,47,45,13,5,65,88,43,106,
227,137,170,63,107,210,68,246,22,11,99,224,93,222,57,69,12,60,66,191,18,197,248,180,255,0,72,143,62,32,112,232,174,109,193,76,194,8,248,122,249,87,203,170,242,248,157,144,197,244,111,71,110,78,188,254,
100,191,52,190,23,246,22,63,116,101,51,146,111,126,173,238,78,163,207,103,190,72,236,205,243,81,80,149,121,140,94,229,150,161,162,221,82,86,98,167,148,125,136,10,148,137,14,131,75,47,136,130,78,247,36,
55,183,177,220,114,238,207,119,30,144,52,178,61,34,43,228,71,150,124,252,235,199,171,14,193,166,87,31,234,255,0,86,58,147,176,254,56,127,41,207,152,210,239,45,159,211,125,139,219,189,238,219,74,73,38,
201,117,214,213,220,187,59,167,97,164,141,163,103,166,163,196,227,183,206,66,131,113,229,241,210,27,36,77,79,36,182,212,170,199,219,151,27,151,52,237,98,25,47,96,138,5,35,12,202,206,126,117,42,8,7,171,
25,4,171,164,62,7,219,255,0,23,211,135,242,221,249,179,179,58,147,230,30,23,249,84,244,159,199,239,144,61,105,212,251,145,123,2,190,179,97,247,84,52,95,197,250,135,114,237,220,125,110,123,37,190,54,206,
90,151,93,110,99,101,238,202,168,127,220,133,61,68,147,83,197,44,162,122,105,23,83,41,222,249,181,205,46,222,121,166,230,246,25,46,1,69,37,13,124,64,212,26,72,252,44,60,142,48,51,210,114,22,69,120,88,
112,90,143,245,127,151,171,130,236,111,145,95,20,58,167,180,240,221,53,219,93,235,214,61,105,218,155,135,101,201,216,184,173,179,190,178,18,96,224,169,217,177,213,203,70,114,239,157,169,132,226,32,168,
146,72,29,163,166,103,19,60,107,169,65,250,123,43,137,47,229,134,75,139,123,57,164,182,70,210,89,6,174,227,248,105,199,237,60,58,66,150,178,186,44,139,76,255,0,170,189,53,117,175,202,110,135,238,110,164,
175,238,30,128,221,176,118,78,210,61,129,184,186,175,107,100,40,241,53,248,58,93,209,190,182,193,137,51,51,98,151,39,12,51,213,109,92,72,153,103,108,137,81,20,176,139,160,228,2,2,247,39,156,143,183,187,
124,105,119,104,205,204,151,84,75,91,122,138,187,184,61,206,70,22,56,197,94,67,248,84,122,145,209,246,193,203,55,27,213,247,130,206,22,194,49,174,89,56,133,81,228,61,89,190,21,30,191,103,69,218,155,39,
62,225,236,202,165,142,161,234,168,182,142,38,174,10,234,210,88,138,220,254,102,82,245,213,4,253,15,150,66,228,2,110,22,222,241,63,218,41,46,249,151,222,29,215,114,89,90,93,187,102,219,228,73,37,242,146,
238,233,187,254,68,156,154,121,45,58,152,121,173,98,219,185,78,218,215,64,73,174,231,93,11,252,49,68,49,251,6,62,222,132,126,127,216,255,0,143,251,227,239,46,122,138,58,245,191,28,95,131,253,126,188,159,
126,235,92,77,8,235,222,253,214,250,247,191,117,238,188,79,228,159,246,39,223,186,247,94,187,126,9,31,215,253,247,248,123,247,94,233,135,113,197,88,212,113,100,113,205,34,228,176,213,43,95,72,35,226,71,
10,10,84,70,188,13,69,162,228,15,234,61,198,94,237,114,237,238,255,0,202,79,113,181,33,109,227,110,147,234,98,3,226,112,160,137,16,122,150,74,211,230,58,18,114,173,252,54,59,170,197,118,71,209,220,47,
134,245,224,43,240,159,200,241,62,157,9,27,39,115,166,238,198,234,161,167,129,235,98,111,37,94,39,206,180,109,45,67,15,85,118,18,115,232,161,173,119,91,201,19,129,20,172,111,233,110,125,128,125,168,247,
98,247,111,182,16,67,2,205,101,170,178,91,147,164,134,175,115,194,78,17,201,174,168,207,107,30,26,91,61,26,115,111,41,65,44,158,35,72,82,96,59,101,165,69,60,149,192,226,163,201,134,64,245,233,9,243,39,
231,71,123,252,50,248,127,187,59,175,168,122,191,15,220,153,13,131,186,49,56,253,243,133,222,53,249,90,8,246,94,203,201,153,104,234,247,85,101,14,43,203,87,94,113,121,87,167,142,120,238,177,71,4,166,82,
218,71,57,125,203,144,236,28,241,45,149,213,165,251,199,105,58,144,8,80,28,74,188,98,117,63,3,140,227,53,197,43,94,162,75,139,75,141,190,233,237,238,208,120,170,43,131,80,65,224,202,124,193,28,63,216,
234,135,183,79,243,161,254,99,121,173,197,210,159,32,55,78,87,172,241,223,28,48,251,143,15,147,223,157,75,212,59,92,199,75,187,54,77,108,171,75,185,40,243,249,156,173,70,75,51,91,83,73,139,158,73,96,142,
57,97,141,42,35,82,20,31,99,251,110,75,229,245,75,219,24,76,199,117,42,116,73,43,112,113,194,128,0,0,39,4,241,207,167,79,24,79,134,179,5,83,15,203,231,254,111,179,171,236,249,159,180,123,223,228,175,192,
222,218,216,159,5,187,55,9,139,223,221,215,181,54,142,235,235,29,211,54,90,44,68,29,143,211,249,216,206,71,51,182,54,238,232,145,214,155,1,184,51,152,217,150,23,145,202,217,162,150,18,65,111,96,221,186,
226,206,211,121,219,239,247,139,86,54,208,51,172,139,74,248,83,12,6,101,226,64,62,149,226,15,76,219,129,19,203,9,97,226,16,40,125,65,244,61,18,31,229,247,252,161,59,90,131,225,127,97,245,39,203,29,253,
95,176,126,68,246,230,55,55,65,89,185,198,231,135,182,183,214,194,196,83,193,227,218,241,98,243,121,42,250,172,46,196,219,212,48,171,201,87,79,141,211,144,169,45,119,168,137,81,80,172,230,46,103,182,109,
210,11,237,174,220,73,183,195,242,240,212,147,241,98,154,157,189,11,118,142,20,61,42,73,16,126,141,78,182,199,30,31,241,93,86,103,199,143,229,123,243,139,31,191,127,136,117,103,92,111,12,254,231,235,77,
253,84,253,81,242,227,21,191,105,241,27,11,63,83,183,242,47,79,71,188,112,176,110,218,250,154,169,49,178,75,1,14,36,165,100,117,214,46,69,143,177,62,227,191,242,180,59,120,134,254,224,248,178,198,11,194,
202,117,168,97,93,45,164,1,90,122,28,116,170,31,166,240,138,178,19,32,63,16,62,99,237,234,239,190,66,229,127,152,77,63,65,109,232,234,62,82,124,126,233,79,150,85,89,122,73,55,110,239,171,237,13,169,31,
74,82,225,113,115,76,149,152,154,46,180,92,86,74,163,37,93,155,162,88,219,35,81,146,214,159,113,229,241,4,77,35,216,23,108,131,96,184,220,100,255,0,117,151,19,108,202,167,66,149,62,41,39,133,94,180,0,
31,132,47,151,19,94,147,56,72,181,21,174,179,199,21,233,247,227,175,78,124,158,237,62,167,162,221,57,173,149,213,27,31,183,63,139,75,28,221,171,214,121,218,140,95,198,46,250,219,196,9,33,222,244,189,95,
145,199,174,103,25,144,174,145,157,37,170,198,195,67,28,142,4,208,23,140,251,45,221,160,218,33,188,150,59,105,166,107,111,224,101,6,88,201,252,37,198,13,60,188,192,227,211,130,229,225,208,36,113,74,112,
232,72,222,216,77,243,212,207,74,123,119,107,211,237,92,85,125,109,62,51,25,190,48,217,65,184,58,254,187,33,81,117,167,165,172,203,36,73,85,181,234,171,38,82,176,166,69,85,94,224,107,212,125,134,47,37,
182,179,134,75,169,231,211,108,159,17,96,65,81,252,77,74,227,212,140,14,60,58,95,107,39,214,191,133,110,165,165,242,30,103,228,61,79,203,172,60,220,11,216,217,71,36,16,110,47,168,17,193,7,253,114,15,191,
2,8,86,82,10,176,4,17,144,65,21,4,17,130,8,224,70,15,78,249,145,230,13,63,103,75,205,143,140,251,236,172,40,99,50,1,42,18,45,123,27,159,241,226,195,222,137,160,175,77,187,10,83,86,122,179,238,190,217,
184,168,176,180,210,205,75,27,49,141,56,209,107,177,0,146,215,184,35,241,237,27,179,87,226,199,73,152,154,208,116,38,69,135,198,195,254,110,146,32,127,173,143,251,111,168,22,247,74,159,35,213,42,79,19,
212,133,161,164,95,164,17,255,0,177,80,79,251,115,207,191,84,158,61,123,174,127,107,79,255,0,28,99,255,0,95,66,131,254,220,1,239,93,123,172,139,12,75,109,49,160,183,210,202,183,31,236,109,127,126,235,
221,100,183,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,255,208,
223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,214,25,229,240,195,36,182,190,133,
45,249,63,65,249,183,227,223,186,247,69,219,125,239,58,152,68,177,35,29,94,160,8,214,109,171,250,15,160,96,109,237,212,7,30,135,167,20,83,61,21,77,201,159,200,86,75,38,185,100,229,141,129,36,219,142,120,
255,0,31,106,194,133,192,29,120,19,231,208,85,94,210,185,98,88,144,1,176,58,174,78,174,69,255,0,216,123,183,151,79,128,148,6,157,160,127,62,147,242,169,191,209,175,113,126,13,133,255,0,55,181,207,211,
159,122,233,208,65,224,122,157,138,219,181,185,89,209,33,134,67,173,180,155,3,110,127,178,77,185,63,239,30,252,72,28,122,109,164,3,0,103,163,43,176,122,62,106,230,73,106,227,40,140,84,242,182,252,216,
115,99,110,71,250,254,218,105,84,28,113,233,134,126,36,244,109,54,223,85,225,176,240,70,30,36,103,0,92,20,4,241,107,92,223,250,255,0,177,246,157,164,175,14,169,169,186,193,186,186,222,12,172,44,148,170,
44,111,96,20,92,31,233,199,248,251,242,190,147,94,182,27,142,174,128,60,175,71,86,187,185,140,146,62,151,33,184,0,216,129,253,57,191,183,68,248,207,86,86,10,106,167,61,38,42,58,30,106,120,42,107,107,231,
167,162,161,164,130,106,170,218,218,185,86,158,146,142,142,158,54,154,166,170,170,162,82,34,134,8,34,140,179,177,54,0,123,186,205,82,21,69,79,167,94,213,154,130,42,122,40,88,58,109,189,221,27,247,19,128,
192,44,185,61,161,14,65,164,197,82,195,79,52,163,113,10,9,219,238,55,110,225,133,84,69,30,18,21,136,182,50,133,206,170,151,180,146,47,42,61,139,172,172,191,118,91,189,237,232,81,62,138,129,252,53,224,
62,211,138,154,127,46,139,174,174,29,255,0,70,34,64,174,79,249,186,33,253,77,243,191,231,175,200,15,148,253,141,177,241,159,26,126,67,245,71,195,94,188,220,121,61,139,178,183,167,199,122,30,187,203,246,
142,35,33,135,169,150,130,61,229,221,24,61,225,65,155,204,84,81,102,254,201,170,226,198,65,73,72,5,59,133,87,110,79,179,27,253,175,107,138,194,27,153,55,56,101,222,37,80,204,146,235,9,67,248,99,43,64,
10,240,36,147,195,167,99,81,24,85,88,251,71,250,171,209,32,249,11,252,169,187,67,175,187,3,180,62,84,245,222,243,168,249,107,141,237,252,254,71,57,153,236,109,221,71,65,140,236,221,189,188,178,143,122,
252,95,100,98,171,160,137,112,137,69,80,22,17,42,71,20,20,208,34,169,84,81,236,79,178,243,101,155,91,219,237,151,182,223,72,208,45,2,173,74,145,234,180,175,31,62,158,136,36,76,238,115,33,24,232,69,254,
86,223,20,50,223,16,179,189,247,223,255,0,58,254,43,237,189,215,71,190,113,88,220,126,222,237,138,109,203,215,29,133,31,87,108,154,88,107,242,91,166,122,205,147,46,90,155,40,40,114,53,13,77,41,175,199,
180,149,17,211,211,149,65,205,138,46,115,222,33,222,95,109,177,217,111,217,97,143,140,116,100,50,61,69,40,220,62,67,86,58,77,108,175,166,102,102,30,35,53,107,254,127,179,171,240,235,110,178,248,241,178,
107,232,187,147,167,122,235,100,211,229,59,51,103,81,166,223,238,140,125,126,115,116,229,114,61,117,157,9,91,77,143,218,121,205,205,93,146,173,219,251,103,36,164,52,148,148,207,20,119,93,37,120,183,176,
144,89,174,21,98,154,238,70,72,156,214,35,64,21,199,155,0,5,88,122,254,206,147,207,115,48,213,20,136,20,145,196,122,117,170,239,243,207,217,253,135,133,254,99,145,119,71,98,117,237,125,23,198,220,183,
76,236,78,172,234,14,214,154,134,60,190,202,220,217,236,78,33,178,25,92,86,67,35,18,207,79,130,220,145,102,100,154,56,233,106,196,82,72,177,134,143,80,35,220,131,201,178,67,251,154,75,52,159,253,217,120,
207,36,145,240,96,164,208,17,252,66,158,98,180,232,219,110,146,4,146,34,228,24,188,58,87,231,243,252,250,61,31,203,83,31,95,180,63,148,183,196,236,214,38,141,159,39,187,187,167,191,242,84,144,66,186,94,
163,251,193,149,122,42,57,66,160,4,198,191,100,46,126,129,71,244,30,240,171,239,147,113,188,71,204,60,163,38,193,104,243,238,210,93,53,172,72,160,146,210,77,1,10,49,144,43,147,232,1,39,3,169,43,219,65,
106,239,190,165,228,170,150,171,2,200,196,154,0,17,243,254,26,15,159,86,21,179,118,202,109,108,60,116,111,40,169,201,214,76,107,243,53,150,185,170,200,204,9,147,214,121,240,64,14,132,31,208,123,20,251,
93,237,253,183,183,28,169,6,205,226,9,119,153,156,207,121,55,251,246,225,199,117,63,161,24,236,65,232,43,231,209,7,50,239,207,204,91,163,222,5,211,100,131,68,43,252,40,14,9,249,183,196,127,103,74,175,
247,191,235,254,63,215,220,137,209,7,93,255,0,190,255,0,124,126,190,253,215,186,235,223,186,247,94,60,127,172,5,255,0,222,57,31,236,61,251,175,117,239,126,235,221,123,254,39,223,186,247,89,2,191,234,10,
220,125,8,254,183,250,255,0,95,123,4,130,8,57,235,68,2,8,35,29,37,159,21,89,139,203,140,254,222,43,29,65,117,122,252,103,144,67,13,96,191,50,211,55,17,197,59,233,245,41,244,185,254,135,220,25,207,62,211,
205,121,186,158,105,228,159,14,29,221,142,169,237,201,209,28,231,142,180,35,182,57,125,107,218,199,38,135,161,182,203,205,41,29,167,238,205,243,83,218,1,68,147,226,100,30,141,230,202,7,230,58,31,250,249,
182,183,106,85,118,14,214,220,152,138,12,254,223,221,219,84,109,189,245,215,249,93,49,215,110,61,175,146,196,84,227,55,51,67,142,170,93,57,33,29,60,227,81,139,92,144,178,36,150,178,131,236,121,236,213,
229,233,181,230,181,188,183,158,207,112,138,242,15,141,74,233,153,99,201,169,198,104,181,96,72,96,6,122,12,115,173,186,198,251,44,176,74,146,196,99,144,134,82,8,210,95,3,28,60,240,126,125,107,67,159,254,
80,127,204,75,162,183,239,107,245,55,198,238,176,219,255,0,34,126,49,110,44,142,67,41,213,59,171,41,189,112,56,87,195,96,114,175,36,212,152,92,221,22,106,166,41,168,51,120,88,101,251,106,136,200,241,200,
209,137,21,172,222,242,169,57,179,151,174,146,206,235,115,185,123,109,209,64,14,2,147,82,60,193,28,65,227,235,158,130,86,243,201,28,110,17,67,69,232,78,71,87,3,252,160,126,59,255,0,48,47,143,29,103,186,
190,57,252,204,234,77,187,183,122,163,108,84,87,238,222,138,222,84,157,157,183,119,94,111,105,79,152,172,19,102,122,179,248,62,30,166,186,103,218,117,83,200,245,180,114,107,141,104,102,50,40,5,100,224,
51,205,59,158,199,127,184,69,184,236,119,108,211,200,0,153,10,21,13,65,137,42,69,53,121,31,81,210,121,89,100,137,181,80,56,61,180,244,62,93,88,23,113,237,221,243,95,215,253,201,176,186,187,113,67,180,
247,223,97,117,150,236,217,187,43,116,213,23,122,125,191,185,51,216,217,41,177,181,149,79,105,30,40,12,231,194,238,1,241,172,165,172,109,111,101,145,60,38,91,41,238,163,213,109,20,170,236,61,64,57,255,
0,56,251,58,106,220,170,73,90,231,61,80,71,192,175,141,223,205,55,117,124,149,135,175,190,122,30,254,220,221,89,208,184,25,170,40,250,183,11,216,148,187,123,169,123,11,114,196,194,151,106,99,242,185,141,
187,85,71,133,163,217,74,24,213,214,7,13,81,36,43,160,68,236,218,72,179,153,119,94,80,93,164,222,108,11,109,251,206,230,74,25,10,22,145,20,124,68,3,83,171,201,124,188,250,52,140,58,225,142,152,199,236,
255,0,87,219,231,209,31,254,98,191,29,187,199,170,254,112,111,122,143,150,29,27,22,224,235,94,224,137,42,58,41,250,61,115,59,183,103,108,157,159,73,20,84,84,251,114,159,25,137,165,57,154,122,170,25,221,
150,166,166,178,158,54,171,168,187,163,16,108,15,185,67,119,218,174,118,56,146,206,240,139,168,106,37,241,8,70,102,254,42,146,23,236,0,224,116,162,33,111,226,55,212,71,173,15,3,233,249,117,112,63,201,
183,111,255,0,48,14,181,234,222,219,219,253,165,189,115,189,79,240,103,104,209,182,224,233,206,196,238,204,10,77,219,27,114,10,113,37,102,123,9,179,169,55,124,137,22,55,173,232,113,240,73,43,85,228,225,
41,4,136,35,167,75,177,176,27,156,164,229,203,155,219,89,44,227,19,111,13,81,42,196,212,140,230,128,177,81,82,228,249,47,151,76,74,161,25,180,208,165,123,107,147,79,245,112,233,55,252,179,191,154,159,
201,143,159,127,51,254,64,252,110,174,217,91,59,188,126,17,98,113,251,218,187,33,190,55,182,50,139,21,188,54,215,89,82,180,248,173,167,147,200,75,143,142,10,93,216,119,230,74,152,201,21,59,65,174,158,
57,149,163,116,241,131,238,188,209,202,27,102,203,177,237,183,134,71,139,120,148,133,240,129,44,140,91,226,4,30,20,83,67,156,240,32,142,180,174,202,204,195,12,162,161,134,13,71,249,61,61,58,61,141,177,
43,250,144,227,168,215,53,83,159,234,236,214,98,167,15,179,50,121,105,124,155,135,103,213,168,105,233,182,78,228,168,229,107,233,32,167,37,49,245,164,134,154,20,210,254,181,62,241,231,115,153,189,183,
230,173,183,97,187,127,249,7,238,206,203,108,236,78,155,59,174,34,220,49,31,216,79,147,24,39,244,222,170,59,72,160,182,198,85,230,157,170,234,254,20,255,0,119,150,138,12,170,180,253,120,255,0,223,148,
254,52,167,113,243,25,227,209,200,233,29,189,67,83,85,20,211,4,14,178,15,73,183,4,115,254,4,158,125,142,39,170,130,15,68,44,213,36,142,29,88,198,54,154,42,74,40,32,135,148,68,28,255,0,82,64,191,248,123,
69,199,166,9,174,79,83,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,
247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,95,255,209,223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,
117,239,126,235,221,123,223,186,247,94,247,238,189,214,57,99,89,163,120,218,246,117,42,72,255,0,31,249,23,191,117,238,130,125,201,176,6,65,100,112,170,218,137,229,125,68,19,244,1,44,13,143,231,221,213,
200,160,174,58,216,52,232,189,231,250,182,176,204,226,56,152,199,112,9,2,192,254,7,211,253,127,111,36,180,25,29,92,26,249,244,131,171,234,140,147,134,180,7,145,127,167,31,143,207,250,163,253,125,184,101,
92,30,189,145,192,87,172,56,238,155,200,212,76,3,211,146,165,135,226,255,0,242,8,22,191,251,15,126,241,86,189,92,177,57,225,209,154,216,157,71,71,139,88,37,170,167,1,208,169,125,72,7,54,230,215,228,143,
167,182,90,90,249,244,217,52,225,208,249,71,67,75,67,18,197,79,18,32,0,92,170,128,73,31,147,237,142,169,199,169,158,253,215,186,247,191,117,238,186,32,30,8,4,94,254,253,215,186,32,253,239,185,242,157,
183,81,184,246,62,17,137,235,13,177,150,165,218,187,161,32,105,34,147,178,55,204,237,4,223,221,24,234,162,101,120,54,174,218,89,35,124,147,33,189,85,75,8,63,74,189,196,219,53,164,113,201,20,243,15,213,
35,80,244,85,206,79,204,249,122,113,233,45,212,254,26,16,191,29,122,163,109,229,252,235,186,135,169,62,106,96,254,0,244,246,75,98,245,238,75,29,155,151,99,246,95,201,173,249,181,23,45,215,123,83,177,196,
73,246,61,127,138,192,208,229,48,47,37,50,84,184,130,124,157,69,80,138,41,108,161,72,246,47,60,171,119,127,181,62,249,115,226,24,72,212,145,43,119,178,249,185,52,63,179,243,235,209,246,0,88,85,143,248,
122,14,255,0,154,151,73,127,55,204,103,110,117,255,0,200,126,157,221,171,152,234,138,238,189,166,218,125,155,185,62,14,227,43,118,126,246,221,180,49,230,38,207,80,229,55,190,222,174,205,103,170,55,36,
112,26,166,20,149,116,83,176,138,54,42,5,141,189,219,149,238,57,64,193,61,133,250,176,156,61,83,199,163,5,197,8,82,0,167,206,189,58,218,234,167,240,249,211,162,79,240,27,120,255,0,50,25,62,118,108,172,
126,209,222,61,249,182,122,227,121,81,212,83,247,238,83,230,14,205,204,212,245,108,219,99,30,5,146,89,235,105,104,138,111,58,185,24,67,65,50,202,26,237,165,206,143,103,91,252,124,176,187,68,242,70,145,
53,194,17,225,136,88,106,169,249,2,123,125,122,219,233,46,158,30,170,121,215,171,187,249,161,252,139,62,47,252,177,221,109,190,55,174,249,237,158,189,220,53,244,9,77,92,221,29,85,46,222,217,121,88,27,
247,35,170,174,219,21,25,122,204,92,243,105,99,251,208,164,66,64,110,65,62,194,123,39,53,110,150,49,148,182,75,118,64,107,250,130,172,62,64,210,163,246,116,154,87,69,35,82,182,161,230,58,61,219,39,172,
119,167,82,117,142,200,235,77,151,87,180,251,31,97,117,166,210,194,108,173,191,178,170,161,159,107,110,200,182,230,222,161,138,130,133,40,43,107,100,146,142,191,44,97,139,91,2,234,210,72,77,190,190,208,
60,227,199,146,121,97,104,165,145,139,23,83,173,117,19,90,145,198,157,54,207,29,199,22,238,244,56,253,135,162,201,242,179,168,182,7,202,111,140,125,181,209,251,169,114,109,215,221,147,139,155,110,231,
105,107,104,75,238,238,162,236,44,100,162,187,106,238,200,177,117,38,50,153,173,175,151,69,144,50,20,251,202,54,145,3,122,129,7,54,23,82,67,123,103,127,9,95,172,132,234,82,15,108,137,193,148,156,225,135,
31,67,211,40,13,171,209,179,19,96,142,128,14,132,234,90,110,129,233,174,148,248,191,133,221,35,120,237,79,140,123,38,151,109,203,187,6,44,225,198,247,236,93,195,175,53,184,55,4,88,185,102,169,155,21,67,
69,79,145,68,72,90,71,127,35,182,166,54,30,195,188,217,21,150,231,185,217,238,119,118,41,251,206,57,154,120,201,58,140,69,144,199,218,113,82,86,162,190,135,163,205,186,105,150,59,211,20,172,32,153,66,
17,234,170,107,67,254,219,61,14,28,255,0,95,246,36,115,254,199,233,207,178,62,149,140,10,87,175,113,245,252,243,244,255,0,97,254,243,199,191,117,238,188,120,6,195,250,216,123,247,94,235,214,98,108,162,
252,126,1,63,237,237,244,250,251,247,94,235,56,166,168,107,218,54,63,91,16,167,250,95,235,99,127,126,235,221,75,135,19,93,61,180,67,33,185,0,157,7,234,127,214,191,191,117,170,143,94,150,88,62,190,204,
100,229,140,10,105,128,45,245,208,121,230,194,218,133,128,247,162,64,243,234,134,65,156,116,52,203,209,149,145,226,126,228,195,33,147,199,171,78,139,92,176,55,231,235,113,238,134,84,173,43,211,101,216,
147,158,128,204,198,200,202,99,234,36,141,233,229,225,191,0,142,7,208,143,169,252,127,175,127,110,3,92,131,211,130,64,105,94,61,38,102,193,215,172,180,181,49,26,202,44,134,62,161,43,49,153,58,23,122,124,
142,46,190,19,170,26,218,10,164,26,225,154,59,125,57,86,91,171,2,164,143,110,164,210,70,218,193,251,71,145,30,135,212,117,226,177,176,32,129,78,135,141,155,218,187,136,228,214,139,51,12,20,187,142,74,
86,168,251,218,56,254,219,27,187,227,165,255,0,129,213,84,244,43,100,198,103,233,144,137,42,105,144,152,166,82,100,136,0,10,251,18,88,203,13,236,94,27,124,75,228,114,71,231,230,63,159,68,87,182,190,9,
50,199,253,153,57,232,111,154,179,115,230,18,156,209,178,248,234,105,222,170,122,169,37,72,41,168,169,34,67,37,69,101,101,84,134,56,41,41,41,162,5,164,145,200,10,160,146,125,218,176,64,9,144,210,152,167,
19,95,64,60,207,165,58,66,168,236,64,85,201,233,9,180,242,19,246,115,212,197,214,153,10,186,109,157,21,124,152,252,223,120,181,42,121,247,52,212,206,209,228,112,61,27,141,175,137,190,242,40,165,6,26,157,
201,58,138,104,57,251,81,35,141,65,53,196,210,169,11,42,209,180,212,69,252,32,240,105,79,145,167,8,198,125,122,48,72,99,183,93,114,26,183,151,70,87,27,131,196,236,93,179,38,59,1,142,74,12,109,14,186,175,
178,134,105,106,106,103,168,125,45,87,147,201,228,38,102,171,204,102,170,72,45,61,76,236,239,33,54,4,45,128,64,160,201,42,150,109,82,159,63,240,1,228,7,160,0,116,196,179,52,181,169,162,250,117,173,191,
243,115,239,239,230,241,241,159,229,45,47,101,252,26,234,23,222,189,23,216,189,93,177,177,43,188,176,157,79,69,220,181,244,155,175,6,42,82,174,130,182,133,226,173,175,218,211,193,81,55,237,167,141,97,
158,250,245,22,189,134,156,175,183,242,158,231,183,189,158,255,0,127,224,221,199,59,182,146,254,24,33,169,66,15,226,192,233,120,212,170,141,10,87,182,159,103,90,252,252,229,237,255,0,231,67,216,29,127,
182,183,159,243,18,155,191,118,119,199,173,203,151,134,21,196,75,180,98,235,158,180,201,87,73,254,103,27,187,48,187,91,237,222,142,154,177,70,149,135,34,22,41,191,73,82,125,200,124,189,101,200,144,221,
201,6,197,44,15,126,163,137,109,77,246,169,56,63,151,90,171,246,180,162,139,254,175,217,213,131,255,0,33,125,185,151,223,63,62,230,239,30,170,196,101,112,29,49,214,95,28,119,62,216,238,109,201,142,166,
150,135,98,110,61,193,154,74,74,45,155,178,204,168,169,140,203,228,225,156,26,136,162,82,239,18,198,91,143,101,62,225,24,97,218,32,219,165,112,215,242,221,43,70,181,171,170,143,137,189,64,234,243,203,
13,29,208,254,152,66,15,165,107,142,182,80,237,156,32,201,245,199,104,98,102,4,174,62,130,151,116,210,216,133,20,121,44,62,70,39,130,104,152,88,164,162,9,222,63,241,12,71,188,101,251,195,237,80,110,254,
211,239,115,21,164,214,165,38,141,171,149,100,97,66,190,135,61,25,123,107,116,246,92,221,98,138,123,102,86,141,133,42,40,202,120,254,125,39,186,23,178,43,142,31,25,85,85,59,138,202,121,26,130,181,201,
23,146,162,141,196,70,70,184,253,83,70,3,31,241,246,65,237,95,51,79,205,252,139,180,110,119,142,91,113,143,84,19,19,197,158,35,167,81,245,212,180,53,243,227,209,239,54,109,105,181,111,151,118,240,40,22,
207,222,128,121,43,121,126,68,30,173,87,175,55,90,103,168,34,13,40,118,49,33,94,65,55,10,11,95,243,244,252,251,28,72,180,63,62,131,12,60,199,66,111,182,250,167,94,247,238,189,215,189,251,175,117,239,126,
235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,255,210,
223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,
221,70,146,146,158,83,119,137,9,254,182,23,255,0,122,228,143,199,189,212,208,143,46,189,212,118,196,227,220,89,169,162,107,125,9,91,219,223,170,113,158,189,215,56,177,212,80,144,99,166,137,72,250,89,71,
31,239,30,245,215,186,154,0,31,65,111,126,235,221,119,239,221,123,175,123,247,94,235,222,253,215,186,79,238,188,221,46,218,219,27,135,112,214,206,41,169,48,152,76,158,86,162,118,228,69,29,5,28,213,44,
246,252,145,227,224,126,79,180,215,151,150,251,125,172,247,183,114,4,181,137,75,49,244,3,137,233,232,32,150,230,104,173,225,93,82,187,0,7,169,61,18,142,131,198,83,238,142,142,219,2,38,41,144,201,137,247,
120,172,144,145,60,153,76,238,94,179,54,245,147,31,168,150,89,42,125,68,242,15,250,222,199,82,202,35,150,27,132,204,15,18,145,243,82,160,143,228,122,15,206,196,205,113,27,10,50,185,7,237,83,79,229,214,
169,63,240,165,191,129,61,51,211,19,117,23,205,109,131,214,111,182,115,61,185,189,50,91,51,228,109,126,25,36,155,100,215,229,234,113,209,84,237,205,213,152,162,69,48,97,243,249,58,248,36,70,171,83,26,
74,246,189,155,147,32,251,111,190,79,45,213,222,205,113,113,174,221,16,52,65,135,117,43,66,163,212,0,120,116,101,25,26,99,102,161,7,7,170,253,248,141,252,192,126,88,252,116,234,25,223,99,124,159,223,212,
59,59,109,206,148,248,221,153,186,39,199,246,14,222,142,137,214,212,212,212,20,89,233,91,51,67,75,16,107,40,142,82,129,126,150,246,44,222,121,83,102,220,111,99,63,64,129,220,84,149,58,77,124,206,5,63,
151,79,248,116,66,74,227,229,208,217,179,255,0,157,119,243,101,249,7,157,201,245,135,70,108,61,163,222,187,138,154,134,106,220,166,27,101,245,70,83,114,77,77,139,26,214,42,221,195,71,247,115,226,104,86,
167,77,128,149,148,51,92,47,178,123,238,76,229,109,161,86,123,237,200,194,167,133,89,71,236,60,79,77,233,70,0,163,84,250,103,171,166,254,68,255,0,63,127,152,103,200,44,191,125,244,215,205,94,131,220,155,
71,7,214,116,79,159,217,157,155,151,216,57,93,133,139,193,229,77,122,81,77,213,114,209,101,85,83,41,168,22,146,141,169,221,204,106,10,254,155,123,3,115,110,203,177,89,73,183,220,108,183,225,222,99,71,
64,193,137,20,168,147,28,62,117,233,183,248,29,155,20,28,79,248,62,125,108,59,216,184,252,74,96,159,38,212,235,77,82,97,136,177,67,163,213,34,134,8,109,164,234,86,63,239,30,195,27,116,146,248,226,48,213,
21,61,34,153,71,134,199,207,162,13,216,217,202,108,91,13,245,95,93,16,134,154,108,118,217,222,137,51,34,46,119,110,85,75,225,199,213,74,44,30,171,53,183,170,27,84,76,117,74,244,250,147,232,5,151,111,251,
214,193,202,27,100,251,223,48,110,118,246,27,52,121,105,37,96,170,164,224,1,234,88,240,85,4,158,52,234,251,93,173,246,241,114,155,101,141,179,207,120,192,233,85,21,52,30,103,200,1,234,79,69,223,110,181,
4,255,0,222,106,188,85,100,57,12,117,118,245,220,149,116,57,8,31,203,13,109,33,169,138,42,89,162,144,139,186,120,99,80,63,165,173,248,246,73,62,229,105,188,139,109,215,111,185,73,182,251,136,82,72,164,
67,85,116,97,85,101,62,96,142,143,162,181,154,201,77,157,196,69,46,35,36,50,145,66,27,204,30,148,126,211,244,239,93,123,247,94,235,223,225,254,251,241,255,0,21,247,238,189,210,143,109,209,165,109,116,
113,56,36,59,128,215,185,95,192,35,243,245,191,189,253,189,85,170,20,211,163,195,180,122,59,29,151,160,134,175,198,167,82,35,53,237,198,165,36,254,13,248,62,211,180,212,36,83,164,196,249,147,208,179,140,
232,172,53,35,41,150,24,108,25,126,154,88,217,126,151,227,252,61,180,101,39,237,234,165,189,58,18,113,59,11,9,139,182,138,120,137,82,8,180,98,220,27,243,113,253,171,114,61,208,177,61,84,177,61,42,228,
198,209,201,17,128,193,24,143,78,155,5,31,67,113,99,199,226,254,235,214,186,68,228,250,215,111,228,89,157,233,163,187,90,247,141,127,216,146,108,73,247,96,236,13,71,86,212,122,70,84,244,134,6,93,71,237,
225,60,146,162,195,243,254,219,241,238,226,86,235,218,254,93,34,183,143,199,170,74,221,185,149,254,11,28,113,238,44,116,45,153,218,245,0,133,104,183,22,52,26,156,112,18,13,37,98,172,100,106,121,71,208,
195,51,3,239,103,112,185,178,18,93,90,67,226,220,34,49,88,203,105,14,104,104,165,179,74,154,10,249,113,234,234,176,204,201,12,236,86,22,32,49,226,64,39,36,15,81,213,95,101,59,126,93,247,133,201,236,190,
222,204,238,77,185,183,103,201,181,54,71,106,109,100,76,102,62,142,74,26,150,73,104,51,210,18,50,89,154,90,106,180,62,90,89,100,16,202,163,75,2,166,222,241,61,61,247,230,43,221,214,107,142,97,221,238,
54,185,214,82,139,21,172,105,166,29,38,132,49,145,89,157,198,117,87,143,149,7,82,224,228,61,190,210,218,49,182,89,69,119,85,169,121,152,146,245,206,52,208,40,60,7,167,30,142,231,77,118,253,52,179,80,237,
93,195,62,223,169,149,233,96,164,216,123,187,111,83,193,138,218,155,151,13,71,16,90,108,13,62,38,31,29,54,213,220,120,234,112,3,80,168,72,166,81,170,50,79,30,231,94,75,247,1,239,164,131,104,223,239,32,
151,198,36,219,95,68,41,13,221,114,86,81,83,224,221,15,197,27,97,248,167,167,81,231,48,114,201,128,75,184,109,240,202,170,159,218,192,249,120,127,164,166,131,196,136,249,48,21,95,49,231,209,157,135,57,
142,169,47,4,132,43,157,81,203,20,183,213,207,212,58,144,8,189,254,158,229,182,130,85,206,122,4,13,39,32,138,244,213,75,133,169,161,121,159,110,238,90,252,85,61,68,154,222,142,7,215,78,172,73,185,141,
13,192,189,248,250,123,179,178,200,7,143,108,172,195,204,142,189,169,227,248,92,129,211,86,251,235,141,187,217,59,39,113,245,247,98,225,176,125,153,178,247,109,15,216,110,109,161,216,84,17,238,29,185,
157,132,186,200,169,89,69,82,222,130,146,42,178,148,42,202,192,16,69,189,214,41,68,83,69,52,58,162,149,13,85,163,237,97,249,142,182,179,79,30,166,12,9,62,185,29,4,152,110,179,217,157,39,177,177,219,67,
102,109,221,155,176,54,38,223,102,151,3,215,125,121,128,161,219,27,90,150,168,40,11,85,45,29,18,171,87,213,220,93,166,168,105,101,111,245,86,227,217,180,51,125,77,195,72,60,71,184,108,52,146,18,207,79,
145,60,63,46,153,157,229,112,166,70,170,121,40,20,3,242,232,190,246,206,103,248,103,95,229,90,82,78,71,176,170,95,31,16,44,3,69,128,197,73,29,126,94,176,165,245,120,101,156,69,2,27,89,152,159,233,238,
27,251,193,115,4,86,60,165,31,46,198,195,197,188,36,191,244,98,142,140,196,253,173,164,15,90,244,59,246,223,107,121,183,150,220,138,157,16,140,124,221,176,0,251,5,79,203,162,241,212,204,233,65,148,153,
125,49,190,100,178,47,208,106,106,88,75,50,159,161,185,32,253,61,199,63,119,64,255,0,212,253,233,205,68,77,185,62,145,228,41,26,86,157,11,189,195,210,55,139,21,31,18,219,10,254,108,105,94,172,151,163,
51,82,9,161,136,179,29,58,79,36,217,129,0,91,253,183,215,220,237,56,243,245,234,58,96,78,161,92,244,118,209,181,162,184,250,50,171,11,127,136,7,254,39,218,126,153,235,151,191,117,238,189,239,221,123,175,
123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,
255,211,223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,
126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,116,2,124,163,153,233,254,60,119,12,145,177,71,254,226,230,163,12,9,6,211,
65,226,112,8,228,93,28,143,113,255,0,186,204,201,237,183,59,50,53,31,247,116,212,60,40,74,145,94,132,124,162,1,230,109,143,80,168,250,132,255,0,15,68,243,226,102,247,164,61,109,177,35,243,143,182,24,10,
108,76,201,168,15,13,110,44,253,181,76,13,111,210,241,184,4,15,174,146,15,231,216,215,218,126,101,139,159,61,170,228,190,97,142,64,215,127,70,144,205,230,86,88,0,137,193,252,215,246,83,160,231,58,109,
175,177,243,118,249,98,202,66,25,204,139,142,41,39,114,145,234,50,115,209,167,236,254,189,216,221,203,215,187,143,173,123,35,99,237,190,210,235,77,227,65,38,59,114,236,157,207,73,14,67,27,148,162,153,
72,183,142,85,111,21,76,69,175,28,177,149,146,55,0,169,7,159,98,216,203,219,92,71,60,82,180,55,8,213,87,24,161,255,0,55,219,209,92,83,16,189,160,31,81,214,180,61,145,255,0,9,141,248,81,159,222,21,153,
77,145,222,223,37,186,119,100,213,214,73,83,63,86,227,19,17,185,113,212,48,75,41,121,49,88,77,193,146,101,175,164,160,66,229,34,215,168,198,150,181,237,236,127,109,207,124,193,28,2,55,142,214,103,165,
53,154,169,251,72,24,39,167,126,166,135,241,129,254,175,151,87,215,240,47,224,191,198,63,130,93,69,254,143,126,53,108,25,246,165,38,94,100,171,221,155,183,59,55,241,45,255,0,190,50,49,166,149,201,110,
109,194,232,181,85,26,110,76,112,33,88,97,7,210,47,207,176,54,247,185,110,59,181,239,143,185,220,137,28,112,3,8,163,208,14,182,101,170,174,144,71,175,169,232,229,212,227,113,243,205,21,69,107,84,86,181,
44,130,104,98,171,169,121,105,226,149,121,243,253,185,113,27,74,160,31,91,220,255,0,143,178,228,103,64,85,0,80,120,208,10,254,222,170,106,212,213,158,139,31,117,246,4,83,201,22,222,198,200,179,206,242,
176,54,117,84,46,170,67,75,43,159,209,4,8,46,236,120,10,9,39,216,139,104,180,17,43,93,206,66,198,1,36,156,0,6,73,39,128,20,201,39,135,72,110,92,14,208,79,249,73,244,3,204,250,15,62,170,135,228,47,101,
211,125,158,59,31,130,168,106,185,42,218,170,147,108,163,160,240,228,102,105,26,159,112,111,118,141,133,222,144,42,181,30,57,152,114,190,73,23,234,15,190,121,253,228,253,214,181,231,27,216,237,118,169,
204,156,191,106,94,59,97,78,217,165,202,205,119,67,197,20,126,148,12,120,247,58,249,30,178,47,219,30,82,151,101,181,146,230,254,32,187,165,198,147,38,115,28,116,5,33,175,147,31,142,65,228,116,169,243,
233,65,214,84,114,80,108,61,187,79,44,98,57,13,44,149,12,182,181,254,230,103,145,92,240,57,113,207,188,144,246,58,214,246,203,218,30,65,183,220,3,11,145,101,90,30,33,25,217,163,25,244,83,208,39,157,36,
138,110,108,223,30,26,120,126,40,31,152,80,9,253,189,46,143,60,123,149,58,12,117,205,81,228,54,64,9,176,181,128,255,0,136,250,251,247,94,233,75,138,218,185,44,163,133,138,158,86,4,139,105,83,205,205,175,
244,60,1,239,221,85,156,40,245,61,24,238,187,233,170,249,42,41,234,106,97,145,0,117,127,88,55,178,233,3,240,63,7,219,79,42,168,198,79,76,179,234,227,129,213,130,237,156,32,194,227,225,167,54,44,35,79,
165,184,244,131,207,31,171,218,82,213,242,233,130,106,107,94,148,158,235,214,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,170,139,230,79,199,216,240,89,236,175,
108,98,232,76,187,27,116,188,71,176,82,154,6,154,163,105,102,206,138,104,119,108,52,241,169,121,176,213,192,170,214,133,31,180,227,201,244,39,222,46,251,191,200,17,218,222,221,115,84,48,215,102,185,167,
213,16,42,214,242,112,23,0,121,198,216,18,83,225,248,186,150,185,47,153,26,107,120,182,137,36,165,236,85,240,171,194,69,226,99,255,0,76,56,175,175,14,136,44,39,117,245,14,76,172,180,233,155,218,153,69,
138,162,52,18,26,172,86,70,149,237,45,61,117,12,241,185,88,228,0,131,28,177,148,146,51,244,32,251,132,108,174,183,239,111,239,8,49,173,206,201,53,9,66,117,195,42,249,58,30,1,128,224,235,70,31,111,67,201,
18,195,126,132,105,38,59,200,241,95,198,141,192,169,30,127,48,112,122,55,29,123,242,26,143,37,77,79,142,53,209,229,146,52,84,135,29,184,114,45,140,220,148,43,101,2,12,126,230,41,37,62,74,8,207,9,29,106,
7,176,177,148,251,201,78,67,247,178,22,142,43,59,107,248,229,81,143,166,187,114,178,47,202,41,205,67,1,248,68,148,62,173,212,103,204,28,134,172,210,78,208,20,98,79,234,66,181,83,243,120,252,137,226,74,
254,206,135,186,30,214,134,153,12,159,125,147,197,1,118,16,110,60,77,92,17,88,142,60,89,140,90,228,113,51,32,252,55,145,67,90,246,30,231,171,63,113,185,110,228,3,186,90,221,88,183,172,145,151,140,252,
196,177,107,74,124,201,207,81,221,199,42,238,112,147,244,178,69,56,254,131,0,223,154,53,26,189,79,126,233,168,154,34,148,249,173,190,132,174,159,39,241,90,91,40,55,245,105,98,173,254,241,127,98,72,57,
135,147,46,84,75,7,49,217,178,255,0,205,69,31,180,19,94,138,165,218,247,136,127,77,246,185,235,90,124,7,252,157,7,123,131,178,232,25,139,215,86,84,239,26,244,12,241,225,176,172,235,69,123,93,70,83,55,
42,174,63,21,69,126,94,70,98,193,111,165,73,246,31,230,31,115,57,99,98,182,153,54,118,250,253,208,47,106,67,240,3,235,44,198,145,198,163,137,36,214,159,10,183,14,140,246,206,84,221,183,9,35,55,81,253,
53,153,57,121,62,34,60,194,32,171,51,122,96,15,82,58,39,157,147,189,171,55,70,74,122,140,134,66,154,183,34,208,37,61,91,227,84,197,183,240,120,138,38,105,105,176,24,8,88,107,52,52,205,118,150,118,253,
202,169,73,115,248,247,130,222,224,243,149,214,253,123,119,61,238,224,183,27,156,152,153,210,162,24,145,73,97,4,0,254,5,36,234,114,53,72,217,62,67,172,128,229,221,150,29,186,222,40,173,237,252,59,117,
202,134,248,217,136,21,119,63,196,105,129,193,70,7,159,66,31,91,97,103,131,107,227,90,72,30,57,242,6,108,132,136,202,117,5,169,96,32,4,30,67,120,35,83,254,199,222,86,123,61,178,73,177,123,123,177,195,
60,101,46,110,3,92,56,34,132,120,167,182,191,237,2,245,22,243,125,234,222,243,13,233,87,172,113,210,49,233,218,51,249,86,189,30,110,154,196,214,67,85,3,232,96,131,77,184,231,143,233,192,183,62,228,89,
88,145,65,195,160,143,10,158,143,101,50,149,167,133,79,212,68,128,255,0,201,35,250,123,74,114,107,211,125,103,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,
175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,255,212,223,227,223,186,247,94,247,238,189,215,189,251,175,
117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,
117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,116,31,246,182,215,151,122,245,174,251,218,52,232,146,84,238,61,169,157,196,210,172,163,246,205,93,102,62,120,169,67,31,193,251,134,91,
31,193,246,31,230,205,165,183,222,88,230,13,153,0,50,93,89,205,18,215,248,157,24,47,243,35,62,93,24,236,247,107,97,186,237,215,175,93,17,76,140,126,192,65,63,203,170,25,233,94,194,143,174,114,181,155,
119,114,125,238,39,25,52,239,6,98,15,183,146,89,246,198,229,197,147,67,62,81,169,17,76,207,65,229,133,169,171,86,53,44,161,99,150,196,2,125,225,207,221,231,221,200,189,173,222,239,249,123,153,252,72,185,
106,229,244,206,186,75,27,91,152,251,12,197,70,124,51,79,14,109,32,210,136,244,226,122,153,125,199,228,249,121,174,202,223,115,218,2,190,235,8,170,100,1,52,45,221,162,167,241,10,234,140,147,234,189,89,
14,214,237,115,73,71,77,81,247,34,179,25,58,35,210,229,241,242,138,236,101,76,102,214,150,10,200,11,160,7,242,26,204,164,88,129,239,163,246,175,181,239,246,48,110,155,53,236,55,91,124,203,169,100,137,
149,227,96,124,195,45,71,249,142,14,122,198,121,35,184,177,158,75,91,184,94,43,164,52,100,112,85,129,244,32,208,255,0,144,250,244,48,208,118,206,223,158,32,211,189,21,64,33,65,213,227,44,0,0,92,222,230,
254,211,73,180,75,94,202,142,158,91,131,141,93,57,85,119,54,216,163,131,91,213,211,67,26,161,11,24,116,82,71,251,74,220,253,79,244,30,217,93,162,118,60,42,122,115,199,74,102,189,2,187,223,190,107,106,
113,181,178,224,226,139,29,138,129,37,106,220,254,82,68,199,226,169,161,81,235,150,74,202,163,26,190,149,230,203,169,141,184,28,251,81,115,14,211,177,88,205,187,239,219,148,54,219,124,74,89,228,149,194,
34,128,42,73,45,143,242,250,117,168,218,226,238,120,237,45,33,121,46,92,209,81,1,102,39,208,1,195,237,56,232,132,246,55,98,227,191,187,213,219,167,57,83,147,135,100,85,9,105,161,200,204,102,198,103,59,
83,33,123,140,22,213,199,202,22,187,27,179,117,129,247,117,236,22,74,164,26,35,178,146,125,225,215,188,94,252,199,204,187,61,214,217,203,173,53,167,183,230,170,243,154,197,113,185,145,254,131,110,166,
143,29,153,255,0,68,152,209,165,29,168,2,212,153,175,147,57,5,246,203,200,175,55,84,73,119,193,148,136,16,209,219,127,78,82,59,90,110,58,82,180,67,147,83,209,76,192,226,243,221,153,187,134,227,206,195,
29,54,67,49,12,112,208,99,96,139,199,71,182,54,165,24,88,35,240,192,61,52,209,67,8,17,64,156,106,115,126,121,62,241,223,147,57,43,114,247,15,153,182,200,46,35,17,189,200,212,168,5,22,214,201,59,90,98,
56,40,11,250,80,47,6,115,90,96,245,38,110,251,189,183,47,237,215,18,234,44,177,227,60,101,148,228,37,124,201,57,115,228,163,163,145,13,52,116,208,195,79,12,100,67,79,20,112,66,191,210,56,80,34,3,110,47,
101,247,210,123,123,120,109,45,173,172,237,147,77,180,49,172,104,61,21,0,85,254,67,172,115,146,71,154,73,102,149,171,43,177,102,62,164,154,158,166,67,69,44,238,22,52,98,77,133,172,79,215,233,96,44,79,
251,127,110,245,94,29,13,29,127,214,213,153,218,200,26,72,89,163,44,44,10,27,21,31,215,72,227,143,199,211,221,93,194,215,166,157,234,40,173,209,250,217,221,77,139,196,211,64,243,67,14,176,170,199,74,27,
177,39,144,110,7,54,94,127,215,246,145,164,102,243,233,49,99,86,207,67,21,38,58,142,137,66,211,192,136,0,181,244,139,240,73,31,142,45,127,109,245,94,61,77,247,238,189,215,189,251,175,117,239,126,235,221,
123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,67,175,199,208,229,104,170,241,185,42,72,43,168,43,233,166,163,173,163,170,137,102,166,170,165,168,140,197,60,19,194,224,164,145,75,27,
16,65,22,35,219,83,67,13,204,50,219,207,26,188,14,165,89,72,168,32,138,16,71,152,35,171,35,188,78,146,70,197,100,83,80,71,16,71,2,58,171,254,227,248,175,185,58,218,154,191,33,213,216,90,142,196,235,10,
185,230,172,201,245,157,68,161,247,22,206,105,88,201,53,94,197,173,123,201,87,66,110,127,200,216,51,40,2,218,190,163,28,57,179,219,77,195,151,161,185,147,150,236,155,113,229,103,98,207,102,198,179,91,
147,197,173,24,252,75,159,236,154,180,3,29,73,251,63,52,219,238,82,68,187,149,192,181,221,128,0,76,7,100,180,224,37,28,3,127,75,129,243,232,130,215,245,254,220,220,82,84,205,178,179,47,79,144,137,152,
85,109,220,188,103,17,184,241,149,8,125,116,213,56,218,131,28,141,36,77,113,116,212,15,184,6,243,150,54,205,201,165,151,99,189,34,117,61,208,200,12,115,33,243,12,140,1,168,60,72,168,234,69,135,115,184,
183,84,91,248,59,15,7,78,228,111,66,15,77,116,21,157,209,179,9,167,161,200,228,154,157,44,139,12,166,89,98,28,253,60,50,134,94,0,254,150,247,187,29,223,220,46,92,30,21,142,227,112,177,127,11,119,2,62,
198,168,254,93,90,123,93,139,113,253,73,224,141,155,212,113,253,163,165,4,125,137,220,115,254,188,110,54,73,173,254,122,108,61,3,62,175,168,109,77,76,108,79,251,223,179,165,231,223,112,159,6,24,75,159,
196,97,142,191,183,79,30,146,29,139,96,25,12,225,107,195,196,111,240,87,166,76,190,71,177,50,241,179,238,188,251,81,227,35,58,165,129,230,20,212,145,168,181,209,97,79,20,127,67,192,0,155,241,236,147,116,
222,57,191,116,93,59,206,234,194,207,204,18,17,71,200,5,167,159,151,159,75,45,108,246,155,102,13,103,106,12,199,204,10,147,249,158,133,238,166,232,236,247,96,205,71,146,170,197,86,208,108,186,89,99,156,
75,91,12,180,181,187,170,116,112,208,199,75,79,34,137,97,194,198,224,22,145,128,242,253,0,247,41,123,89,237,85,199,48,93,218,111,123,229,171,195,203,16,184,117,87,26,94,237,215,42,2,145,85,128,26,22,99,
77,124,6,58,10,243,87,54,195,182,195,45,149,148,193,247,71,82,42,50,34,7,6,167,129,106,96,15,46,61,88,254,211,233,151,102,132,205,74,20,88,21,85,65,101,10,84,233,85,2,193,84,112,63,167,188,201,105,64,
20,64,0,2,128,14,0,12,0,61,0,24,29,66,164,241,36,214,191,180,244,103,54,190,204,162,194,70,15,129,81,148,122,84,88,31,160,228,233,63,159,233,237,130,204,79,30,155,39,211,135,75,207,117,235,93,123,223,
186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,
186,247,94,247,238,189,215,255,213,223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,
189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,85,223,204,95,137,213,57,76,
150,79,183,122,235,31,91,45,85,83,174,67,118,225,176,112,249,114,180,153,8,35,241,190,239,193,209,166,151,201,52,244,232,171,144,163,79,92,161,60,169,118,212,61,226,119,189,222,206,75,127,117,115,206,
124,179,106,237,112,196,61,196,81,1,226,7,92,125,76,74,63,180,52,0,77,16,203,0,29,106,69,58,151,121,23,156,227,134,40,182,61,214,80,168,49,19,177,237,167,251,237,137,248,115,240,55,1,192,227,61,87,190,
31,55,151,218,234,43,106,234,183,70,18,25,139,232,222,125,115,86,78,42,178,69,37,92,230,246,221,84,111,64,42,209,148,137,163,146,40,230,12,8,60,251,199,221,131,154,57,135,148,24,93,217,238,219,142,222,
172,107,245,91,115,159,5,200,226,102,183,106,199,171,201,131,42,183,16,115,212,141,184,237,27,102,242,130,43,187,27,107,156,83,195,157,106,192,113,236,144,119,83,208,134,35,161,2,139,184,243,82,42,44,
61,157,214,217,132,0,89,183,110,201,201,98,114,86,255,0,166,137,176,211,44,78,215,250,250,126,190,230,13,175,239,55,238,69,162,42,71,207,187,45,220,84,193,188,179,120,228,255,0,108,209,48,207,229,208,
42,239,218,206,88,152,179,13,154,250,6,243,16,206,10,254,65,193,233,205,251,111,47,40,103,169,236,254,150,219,81,196,183,53,56,45,149,154,220,57,77,32,240,212,240,229,164,20,254,96,62,159,139,251,48,188,
251,205,123,139,121,19,43,243,231,47,88,165,50,214,246,179,74,244,249,44,140,86,189,49,15,181,124,179,3,130,118,157,202,224,255,0,12,147,4,95,207,69,15,65,214,87,182,118,196,217,8,231,198,209,110,254,
238,222,80,181,241,121,29,244,99,167,218,152,154,149,253,53,88,173,147,142,211,140,95,19,114,141,80,36,35,243,238,30,221,61,194,159,153,247,36,145,231,220,185,155,124,13,84,123,195,166,214,38,242,104,
173,19,244,133,63,9,96,72,232,105,99,203,150,251,84,26,45,173,237,182,219,35,241,8,64,241,92,121,234,153,187,207,228,69,125,58,11,36,198,111,110,200,222,103,39,188,36,171,221,219,189,150,248,236,10,127,
197,187,3,75,172,4,146,120,214,244,152,154,24,62,159,65,199,10,9,246,171,102,229,93,255,0,153,185,130,36,221,225,125,211,154,88,6,142,205,8,17,196,163,253,18,118,29,144,66,158,100,208,181,40,160,154,117,
123,205,203,111,218,172,26,72,165,91,125,184,96,202,126,38,62,136,56,187,159,204,15,58,116,110,182,71,91,85,96,40,26,51,16,173,203,215,178,203,149,175,142,18,139,44,139,97,21,29,40,111,92,88,250,37,244,
198,191,158,88,242,125,231,119,183,220,141,111,201,59,76,145,75,44,115,243,5,209,13,117,112,171,164,49,3,182,24,135,21,183,132,118,198,184,36,213,205,75,30,160,190,97,223,219,124,188,14,21,163,176,140,
82,40,201,173,1,226,237,234,239,197,143,150,0,192,232,109,192,245,110,83,37,36,127,228,210,232,54,184,210,218,109,99,125,70,199,253,227,216,241,152,12,147,208,121,164,56,210,41,209,133,218,29,12,11,35,
212,211,147,200,55,42,109,99,198,174,110,44,61,178,211,10,99,166,217,205,115,209,164,218,219,11,25,183,162,139,199,10,107,64,188,88,113,107,94,255,0,235,251,78,88,183,30,155,44,79,217,208,131,238,189,
107,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,214,247,238,189,208,51,216,63,31,122,127,180,
37,122,189,227,178,49,21,217,87,22,25,202,88,155,25,156,91,13,42,195,43,143,106,122,178,200,0,177,102,54,183,176,150,253,200,188,169,204,174,102,221,246,88,100,186,255,0,126,1,162,65,78,20,145,104,216,
242,207,71,59,127,48,111,27,90,132,179,191,117,139,248,73,212,159,239,38,163,249,116,94,235,254,10,109,69,146,70,219,29,155,216,187,122,38,36,173,45,69,109,22,224,130,53,191,8,14,78,15,51,42,142,5,216,
251,2,205,236,182,212,24,157,191,152,119,24,19,248,75,137,71,253,84,4,211,243,232,67,31,62,94,211,252,99,109,182,145,189,66,148,63,241,147,254,78,155,227,248,53,1,101,254,33,219,251,214,182,45,94,168,
233,49,152,12,124,140,191,211,206,41,167,49,159,241,30,219,143,217,123,50,195,234,185,170,249,227,244,85,137,15,237,8,105,213,143,61,74,160,136,118,120,20,252,203,31,242,244,32,109,79,134,189,69,182,242,
16,101,229,196,214,238,76,165,59,135,130,187,119,228,166,206,53,60,139,244,150,42,9,64,199,172,161,185,7,65,3,250,123,20,108,222,213,242,70,203,115,29,234,237,109,117,122,166,161,238,29,166,161,245,10,
221,128,252,233,209,85,247,56,111,215,209,52,13,116,177,64,220,86,53,209,81,232,79,196,127,111,70,54,139,103,98,104,138,148,136,16,170,161,84,34,38,144,162,218,87,72,210,16,15,160,3,143,114,43,49,110,
60,63,193,242,31,46,131,7,36,146,114,122,84,69,4,48,13,49,70,136,62,158,149,0,255,0,183,250,251,175,28,245,238,178,251,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,
253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,255,214,223,227,223,
186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,
186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,69,147,180,62,43,117,215,97,79,147,205,227,13,118,196,221,
217,66,100,172,207,237,131,12,112,101,42,52,217,100,207,96,106,99,155,13,151,187,0,93,218,36,157,191,227,167,184,179,155,61,165,229,174,101,123,171,251,127,19,111,222,165,203,79,111,65,173,188,140,177,
16,98,151,230,74,234,63,197,208,183,103,231,45,215,106,88,109,228,43,113,98,152,9,37,78,145,253,6,20,101,253,180,249,116,70,247,103,193,14,201,138,105,218,159,9,214,125,131,13,136,134,186,154,187,41,176,
179,15,197,181,207,72,99,202,98,204,164,30,116,186,130,125,192,91,191,221,235,153,21,221,146,203,105,220,146,184,96,210,89,200,126,108,0,146,50,125,104,69,122,144,237,61,199,218,93,71,136,247,86,205,233,
69,153,127,35,218,221,5,75,240,135,185,132,229,105,58,103,109,193,165,129,53,57,78,200,163,150,145,111,249,241,67,2,207,34,11,126,0,62,195,113,123,11,205,254,40,17,251,125,98,41,248,164,220,1,81,243,162,
166,163,209,155,251,129,177,105,238,223,37,63,37,128,215,246,147,65,208,165,182,126,16,246,31,168,110,221,211,183,182,157,44,128,37,70,31,174,49,239,38,70,84,210,63,102,109,199,147,75,198,63,4,197,29,
207,224,251,148,249,107,216,45,249,20,54,251,204,150,251,117,153,29,209,109,145,254,169,7,240,155,153,133,71,161,40,149,175,3,208,103,114,247,26,192,159,247,93,183,73,60,160,225,238,26,139,246,248,104,
115,249,159,203,163,49,177,190,46,237,237,159,70,113,248,28,95,218,71,43,44,149,181,51,179,84,228,114,83,15,247,126,71,33,45,234,42,164,185,39,147,164,126,0,247,144,124,173,202,156,185,201,91,115,237,
188,183,182,44,17,72,107,43,146,94,105,154,148,215,52,173,87,145,190,211,65,248,64,234,57,221,119,205,203,122,156,92,110,119,38,70,24,85,3,74,32,173,104,138,48,163,249,159,51,208,221,137,233,140,125,40,
136,201,28,67,142,67,88,149,2,252,144,46,110,79,177,17,149,137,175,69,122,243,208,165,138,218,56,172,90,143,28,40,204,5,129,40,45,244,181,200,255,0,138,123,161,53,243,234,165,137,243,199,74,116,141,35,
26,81,85,87,240,20,0,7,3,241,239,93,107,174,126,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,
117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,
117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,
117,238,191,255,215,223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,
175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,
175,117,239,126,235,221,99,240,197,199,237,161,181,135,42,15,211,233,245,254,158,253,235,215,186,230,0,28,0,0,250,88,11,125,62,159,79,126,235,221,119,239,221,123,175,123,247,94,235,222,253,215,186,247,
191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,
191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,
191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,123,247,94,235,222,253,215,186,247,191,117,238,189,239,221,123,175,255,208,223,227,223,186,247,94,247,
238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,
238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,
238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,
238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,
238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,
238,189,215,189,251,175,117,255,209,223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,
189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,
189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,
189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,
189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,
189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,255,210,223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,
215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,
215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,
215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,
215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,
215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,255,211,223,227,223,186,247,94,247,238,189,215,
189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,
189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,
189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,
189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,
189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,
189,251,175,117,255,212,223,227,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,
251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,
251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,
251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,
251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,
251,175,117,239,126,235,221,123,223,186,247,94,247,238,189,215,189,251,175,117,255,217,0,0};

const char* JucePitcherComponent::kool_aid_man_waving_jpg = (const char*) resource_JucePitcherComponent_kool_aid_man_waving_jpg;
const int JucePitcherComponent::kool_aid_man_waving_jpgSize = 188220;
