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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "NewComponent.h"

#include <iostream>
#include <process.h>


//[MiscUserDefs] You can add your own user definitions and misc code here...
Network network;

unsigned int __stdcall NetThread(void* arg) 
{
	while (1)
	{
		Sleep(10);
		network.run();
	}

	//_endthreadex(result);
	return 0;
}

//[/MiscUserDefs]

//==============================================================================
NewComponent::NewComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
	startTimerHz(30);
    //[/Constructor_pre]

    addAndMakeVisible (textButton = new TextButton ("1"));
    textButton->addListener (this);

    addAndMakeVisible (textButton2 = new TextButton ("new button"));
    textButton2->addListener (this);

    addAndMakeVisible (textButton3 = new TextButton ("new button"));
    textButton3->addListener (this);

    addAndMakeVisible (textButton4 = new TextButton ("new button"));
    textButton4->addListener (this);

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("TEST")));
    label->setFont (Font (12.00f, Font::plain));
    label->setJustificationType (Justification::topLeft);
    label->setEditable (false, false, false);
    label->setColour (Label::backgroundColourId, Colours::black);
    label->setColour (Label::textColourId, Colours::yellow);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 600);


    //[Constructor] You can add your own custom stuff here..

	HANDLE hand;
	int xxx = 120;
	unsigned int id;
	hand = (HANDLE)_beginthreadex(NULL, 0, NetThread, (void *)xxx, 0, &id);


	label->setText("", juce::NotificationType::dontSendNotification);
    //[/Constructor]
}

NewComponent::~NewComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    textButton = nullptr;
    textButton2 = nullptr;
    textButton3 = nullptr;
    textButton4 = nullptr;
    label = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void NewComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void NewComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    textButton->setBounds (32, 472, 256, 48);
    textButton2->setBounds (32, 528, 256, 48);
    textButton3->setBounds (307, 475, 256, 48);
    textButton4->setBounds (307, 531, 256, 48);
    label->setBounds (24, 32, 544, 408);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void NewComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == textButton)
    {
        //[UserButtonCode_textButton] -- add your button handler code here..
		addMessage("Button 1");
		char buf[1024] = { "0123" };
		network.sendpacket(4, buf);

        //[/UserButtonCode_textButton]
    }
    else if (buttonThatWasClicked == textButton2)
    {
        //[UserButtonCode_textButton2] -- add your button handler code here..
		addMessage("22");
        //[/UserButtonCode_textButton2]
    }
    else if (buttonThatWasClicked == textButton3)
    {
        //[UserButtonCode_textButton3] -- add your button handler code here..
		addMessage("33");
        //[/UserButtonCode_textButton3]
    }
    else if (buttonThatWasClicked == textButton4)
    {
        //[UserButtonCode_textButton4] -- add your button handler code here..
		addMessage("44");
        //[/UserButtonCode_textButton4]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void NewComponent::addMessage(juce::String str)
{
	if (messagelist.size() > MAX_MESSAGE)
		messagelist.pop_front();
	messagelist.push_back(str);

	juce::String msg;
	for (size_t i = 0; i < messagelist.size(); i++)
	{
		if (i > 0) msg += "\n";
		msg += messagelist[i];
	}

	label->setText(msg, juce::NotificationType::dontSendNotification);

}

void NewComponent::timerCallback()
{
	if (!Log::getInstance()->loglist.empty())
	{
		for (size_t i = 0; i < Log::getInstance()->loglist.size(); i++)
		{
			addMessage(Log::getInstance()->loglist[i]);
		}

		Log::getInstance()->loglist.clear();
	}
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="NewComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="600" initialHeight="600">
  <BACKGROUND backgroundColour="ffffffff"/>
  <TEXTBUTTON name="new button" id="da370fd3154909e4" memberName="textButton"
              virtualName="" explicitFocusOrder="0" pos="32 472 256 48" buttonText="new button"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="a55db9e30edb2902" memberName="textButton2"
              virtualName="" explicitFocusOrder="0" pos="32 528 256 48" buttonText="new button"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="a7b4d1c10596675f" memberName="textButton3"
              virtualName="" explicitFocusOrder="0" pos="307 475 256 48" buttonText="new button"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="fbdd7cd0b354af5b" memberName="textButton4"
              virtualName="" explicitFocusOrder="0" pos="307 531 256 48" buttonText="new button"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="6cb8de568bd2e79e" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="24 32 544 408" bkgCol="ff000000"
         textCol="ffffff00" edTextCol="ff000000" edBkgCol="0" labelText="TEST"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12" bold="0" italic="0" justification="9"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
