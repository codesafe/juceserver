/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.2.3

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_ADBA7C90E028EAEC__
#define __JUCE_HEADER_ADBA7C90E028EAEC__

//[Headers]     -- You can add your own extra header files here --
#include <deque>
#define MAX_MESSAGE	25
#define MAX_CLIENTMESSAGE	25
#include "../JuceLibraryCode/JuceHeader.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MainGui  : public Component,
                 public Timer,
                 public ButtonListener,
                 public LabelListener,
                 public SliderListener
{
public:
    //==============================================================================
    MainGui ();
    ~MainGui();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void timerCallback() override;
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    void labelTextChanged (Label* labelThatHasChanged) override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	double rspeed;
	double lspeed;
	double speed;
	juce::String packetstr;
	juce::String displaystr;
	std::deque<juce::String> messagelist;
	void addMessage(juce::String str);

	std::deque<juce::String> clientmessagelist;
	void addClientMessage(juce::String str);
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Label> label;
    ScopedPointer<TextButton> playButton;
    ScopedPointer<TextButton> upButton;
    ScopedPointer<TextButton> downButton;
    ScopedPointer<TextButton> rightButton;
    ScopedPointer<Label> motionLabel;
    ScopedPointer<Slider> slider;
    ScopedPointer<TextButton> leftButton;
    ScopedPointer<TextButton> displayButton;
    ScopedPointer<Slider> slider2;
    ScopedPointer<TextButton> stopButton;
    ScopedPointer<Slider> slider3;
    ScopedPointer<Label> label2;
    ScopedPointer<Label> label3;
    ScopedPointer<Label> label4;
    ScopedPointer<Label> label5;
    ScopedPointer<Label> clientlog;
    ScopedPointer<Label> displayLabel;
    ScopedPointer<TextButton> resetButton;
    ScopedPointer<Label> label6;
    ScopedPointer<Label> label7;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainGui)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_ADBA7C90E028EAEC__
