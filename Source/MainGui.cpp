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
#include <process.h>
#include "Network.h"
//[/Headers]

#include "MainGui.h"


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
MainGui::MainGui ()
{
    //[Constructor_pre] You can add your own custom stuff here..
	startTimerHz(30);
    //[/Constructor_pre]

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("label text")));
    label->setFont (Font (15.00f, Font::plain));
    label->setJustificationType (Justification::topLeft);
    label->setEditable (false, false, false);
    label->setColour (Label::backgroundColourId, Colours::black);
    label->setColour (Label::textColourId, Colours::white);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (playButton = new TextButton ("PlayMotion"));
    playButton->setButtonText (TRANS("Play"));
    playButton->addListener (this);

    addAndMakeVisible (upButton = new TextButton ("Up"));
    upButton->addListener (this);

    addAndMakeVisible (downButton = new TextButton ("Down"));
    downButton->addListener (this);

    addAndMakeVisible (rightButton = new TextButton ("Right"));
    rightButton->addListener (this);

    addAndMakeVisible (motionLabel = new Label ("motionLabel",
                                                String()));
    motionLabel->setFont (Font (15.00f, Font::plain));
    motionLabel->setJustificationType (Justification::centredLeft);
    motionLabel->setEditable (true, true, false);
    motionLabel->setColour (Label::backgroundColourId, Colour (0xff5e5e5e));
    motionLabel->setColour (Label::textColourId, Colour (0xffbee900));
    motionLabel->setColour (TextEditor::textColourId, Colour (0xffdded06));
    motionLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    motionLabel->addListener (this);

    addAndMakeVisible (slider = new Slider ("new slider"));
    slider->setRange (1, 1024, 1);
    slider->setSliderStyle (Slider::LinearHorizontal);
    slider->setTextBoxStyle (Slider::TextBoxLeft, true, 80, 20);
    slider->addListener (this);

    addAndMakeVisible (leftButton = new TextButton ("Left"));
    leftButton->addListener (this);

    addAndMakeVisible (displayButton = new TextButton ("displayButton"));
    displayButton->setButtonText (TRANS("display"));
    displayButton->addListener (this);

    addAndMakeVisible (slider2 = new Slider ("new slider"));
    slider2->setRange (1, 1000, 1);
    slider2->setSliderStyle (Slider::LinearHorizontal);
    slider2->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    slider2->addListener (this);


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

MainGui::~MainGui()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    label = nullptr;
    playButton = nullptr;
    upButton = nullptr;
    downButton = nullptr;
    rightButton = nullptr;
    motionLabel = nullptr;
    slider = nullptr;
    leftButton = nullptr;
    displayButton = nullptr;
    slider2 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MainGui::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    g.setColour (Colours::black);
    g.setFont (Font (15.00f, Font::plain));
    g.drawText (TRANS("Speed"),
                301, 399, 75, 30,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (15.00f, Font::plain));
    g.drawText (TRANS("Degree"),
                301, 431, 75, 30,
                Justification::centred, true);

    g.setColour (Colours::brown);
    g.fillEllipse (13.0f, 7.0f, 25.0f, 25.0f);

    g.setColour (Colour (0xff0072bd));
    g.drawEllipse (13.0f, 7.0f, 25.0f, 25.0f, 2.100f);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainGui::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    label->setBounds (8, 40, 584, 344);
    playButton->setBounds (32, 496, 150, 32);
    upButton->setBounds (440, 480, 64, 32);
    downButton->setBounds (440, 560, 64, 29);
    rightButton->setBounds (512, 520, 64, 32);
    motionLabel->setBounds (32, 448, 152, 32);
    slider->setBounds (368, 400, 216, 24);
    leftButton->setBounds (368, 520, 64, 32);
    displayButton->setBounds (32, 544, 150, 32);
    slider2->setBounds (368, 432, 216, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MainGui::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == playButton)
    {
        //[UserButtonCode_playButton] -- add your button handler code here..
		addMessage("Pushed playButton");

		char buf[1024] = { "0123" };
		network.sendpacket(4, buf);

        //[/UserButtonCode_playButton]
    }
    else if (buttonThatWasClicked == upButton)
    {
        //[UserButtonCode_upButton] -- add your button handler code here..
		addMessage("Pushed up");

        //[/UserButtonCode_upButton]
    }
    else if (buttonThatWasClicked == downButton)
    {
        //[UserButtonCode_downButton] -- add your button handler code here..
		addMessage("Pushed down");

        //[/UserButtonCode_downButton]
    }
    else if (buttonThatWasClicked == rightButton)
    {
        //[UserButtonCode_rightButton] -- add your button handler code here..

		addMessage("Pushed right");

        //[/UserButtonCode_rightButton]
    }
    else if (buttonThatWasClicked == leftButton)
    {
        //[UserButtonCode_leftButton] -- add your button handler code here..
		addMessage("Pushed left");

        //[/UserButtonCode_leftButton]
    }
    else if (buttonThatWasClicked == displayButton)
    {
        //[UserButtonCode_displayButton] -- add your button handler code here..
		addMessage("Pushed display");

        //[/UserButtonCode_displayButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void MainGui::labelTextChanged (Label* labelThatHasChanged)
{
    //[UserlabelTextChanged_Pre]
    //[/UserlabelTextChanged_Pre]

    if (labelThatHasChanged == motionLabel)
    {
        //[UserLabelCode_motionLabel] -- add your label text handling code here..
		addMessage(motionLabel->getText());

        //[/UserLabelCode_motionLabel]
    }

    //[UserlabelTextChanged_Post]
    //[/UserlabelTextChanged_Post]
}

void MainGui::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == slider)
    {
        //[UserSliderCode_slider] -- add your slider handling code here..
        //[/UserSliderCode_slider]
    }
    else if (sliderThatWasMoved == slider2)
    {
        //[UserSliderCode_slider2] -- add your slider handling code here..
        //[/UserSliderCode_slider2]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void MainGui::addMessage(juce::String str)
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

void MainGui::timerCallback()
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

<JUCER_COMPONENT documentType="Component" className="MainGui" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="600" initialHeight="600">
  <BACKGROUND backgroundColour="ffffffff">
    <TEXT pos="301 399 75 30" fill="solid: ff000000" hasStroke="0" text="Speed"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
    <TEXT pos="301 431 75 30" fill="solid: ff000000" hasStroke="0" text="Degree"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
    <ELLIPSE pos="13 7 25 25" fill="solid: ffa52a2a" hasStroke="1" stroke="2.1, mitered, butt"
             strokeColour="solid: ff0072bd"/>
  </BACKGROUND>
  <LABEL name="new label" id="a468f7d6183fa770" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="8 40 584 344" bkgCol="ff000000" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="label text" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="9"/>
  <TEXTBUTTON name="PlayMotion" id="45a4cb1f3a68127f" memberName="playButton"
              virtualName="" explicitFocusOrder="0" pos="32 496 150 32" buttonText="Play"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="Up" id="aebc4158a6eb6b7f" memberName="upButton" virtualName=""
              explicitFocusOrder="0" pos="440 480 64 32" buttonText="Up" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="Down" id="4acf33de38e1f39c" memberName="downButton" virtualName=""
              explicitFocusOrder="0" pos="440 560 64 29" buttonText="Down"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="Right" id="e21e3e353ac7518c" memberName="rightButton" virtualName=""
              explicitFocusOrder="0" pos="512 520 64 32" buttonText="Right"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="motionLabel" id="996f53ca37638546" memberName="motionLabel"
         virtualName="" explicitFocusOrder="0" pos="32 448 152 32" bkgCol="ff5e5e5e"
         textCol="ffbee900" edTextCol="ffdded06" edBkgCol="0" labelText=""
         editableSingleClick="1" editableDoubleClick="1" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="205c96fe532e179a" memberName="slider" virtualName=""
          explicitFocusOrder="0" pos="368 400 216 24" min="1" max="1024"
          int="1" style="LinearHorizontal" textBoxPos="TextBoxLeft" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <TEXTBUTTON name="Left" id="b1bebbabb70704e8" memberName="leftButton" virtualName=""
              explicitFocusOrder="0" pos="368 520 64 32" buttonText="Left"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="displayButton" id="dcc6371a83dc37f0" memberName="displayButton"
              virtualName="" explicitFocusOrder="0" pos="32 544 150 32" buttonText="display"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="new slider" id="f9cf708c27ef3f2a" memberName="slider2"
          virtualName="" explicitFocusOrder="0" pos="368 432 216 24" min="1"
          max="1000" int="1" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
