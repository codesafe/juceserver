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
                                          String()));
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
    upButton->setButtonText (TRANS("Forward"));
    upButton->addListener (this);

    addAndMakeVisible (downButton = new TextButton ("Down"));
    downButton->setButtonText (TRANS("Backward"));
    downButton->addListener (this);

    addAndMakeVisible (rightButton = new TextButton ("Right"));
    rightButton->addListener (this);

    addAndMakeVisible (motionLabel = new Label ("motionLabel",
                                                String()));
    motionLabel->setFont (Font (15.00f, Font::plain));
    motionLabel->setJustificationType (Justification::centredLeft);
    motionLabel->setEditable (true, true, false);
    motionLabel->setColour (Label::backgroundColourId, Colours::white);
    motionLabel->setColour (Label::textColourId, Colours::black);
    motionLabel->setColour (Label::outlineColourId, Colours::black);
    motionLabel->setColour (TextEditor::textColourId, Colours::black);
    motionLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    motionLabel->addListener (this);

    addAndMakeVisible (slider = new Slider ("new slider"));
    slider->setRange (0, 1023, 1);
    slider->setSliderStyle (Slider::LinearVertical);
    slider->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    slider->addListener (this);

    addAndMakeVisible (leftButton = new TextButton ("Left"));
    leftButton->addListener (this);

    addAndMakeVisible (displayButton = new TextButton ("displayButton"));
    displayButton->setButtonText (TRANS("display"));
    displayButton->addListener (this);

    addAndMakeVisible (slider2 = new Slider ("new slider"));
    slider2->setRange (0, 1023, 1);
    slider2->setSliderStyle (Slider::LinearVertical);
    slider2->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    slider2->addListener (this);

    addAndMakeVisible (stopButton = new TextButton ("Stop"));
    stopButton->addListener (this);

    addAndMakeVisible (slider3 = new Slider ("new slider"));
    slider3->setRange (1, 1024, 1);
    slider3->setSliderStyle (Slider::LinearHorizontal);
    slider3->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    slider3->addListener (this);

    addAndMakeVisible (patchButton = new TextButton ("patchButton"));
    patchButton->setButtonText (TRANS("patch"));
    patchButton->addListener (this);
    patchButton->setColour (TextButton::buttonColourId, Colour (0xff650000));
    patchButton->setColour (TextButton::textColourOffId, Colours::white);

    addAndMakeVisible (label2 = new Label ("new label",
                                           TRANS("Server log")));
    label2->setFont (Font (15.00f, Font::plain));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label3 = new Label ("new label",
                                           TRANS("Client log")));
    label3->setFont (Font (15.00f, Font::plain));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label4 = new Label ("new label",
                                           TRANS("L-Speed")));
    label4->setFont (Font (15.00f, Font::plain));
    label4->setJustificationType (Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label5 = new Label ("new label",
                                           TRANS("R-Speed")));
    label5->setFont (Font (15.00f, Font::plain));
    label5->setJustificationType (Justification::centredLeft);
    label5->setEditable (false, false, false);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (clientlog = new Label ("clientlog",
                                              String()));
    clientlog->setFont (Font (15.00f, Font::plain));
    clientlog->setJustificationType (Justification::topLeft);
    clientlog->setEditable (false, false, false);
    clientlog->setColour (Label::backgroundColourId, Colours::black);
    clientlog->setColour (Label::textColourId, Colours::white);
    clientlog->setColour (TextEditor::textColourId, Colours::black);
    clientlog->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (1000, 700);


    //[Constructor] You can add your own custom stuff here..
	HANDLE hand;
	int xxx = 120;
	unsigned int id;
	hand = (HANDLE)_beginthreadex(NULL, 0, NetThread, (void *)xxx, 0, &id);
	label->setText("", juce::NotificationType::dontSendNotification);

	speed = 1;
	lspeed = 1;
	rspeed = 1;

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
    stopButton = nullptr;
    slider3 = nullptr;
    patchButton = nullptr;
    label2 = nullptr;
    label3 = nullptr;
    label4 = nullptr;
    label5 = nullptr;
    clientlog = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MainGui::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainGui::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    label->setBounds (8, 32, 408, 400);
    playButton->setBounds (48, 544, 150, 32);
    upButton->setBounds (664, 528, 64, 32);
    downButton->setBounds (664, 640, 64, 29);
    rightButton->setBounds (744, 584, 64, 32);
    motionLabel->setBounds (48, 496, 152, 32);
    slider->setBounds (816, 504, 40, 176);
    leftButton->setBounds (584, 584, 64, 32);
    displayButton->setBounds (48, 592, 150, 32);
    slider2->setBounds (528, 504, 48, 176);
    stopButton->setBounds (664, 584, 64, 29);
    slider3->setBounds (624, 488, 150, 24);
    patchButton->setBounds (48, 640, 150, 32);
    label2->setBounds (8, 5, 150, 24);
    label3->setBounds (432, 8, 150, 24);
    label4->setBounds (520, 456, 150, 24);
    label5->setBounds (808, 456, 150, 24);
    clientlog->setBounds (432, 32, 552, 400);
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

		std::string str = packetstr.toStdString();
		if(str.size() > 0)
			network.sendpacket(PLAYMOTION, (char*)str.c_str(), str.size());

        //[/UserButtonCode_playButton]
    }
    else if (buttonThatWasClicked == upButton)
    {
        //[UserButtonCode_upButton] -- add your button handler code here..

		int ispeed = (int)speed;
		addMessage(juce::String::formatted("Move forward : %d", ispeed));
		network.sendpacket(WHEEL_FORWARD, (char*)&ispeed, sizeof(int));

        //[/UserButtonCode_upButton]
    }
    else if (buttonThatWasClicked == downButton)
    {
        //[UserButtonCode_downButton] -- add your button handler code here..
		int ispeed = (int)speed;
		addMessage(juce::String::formatted("Move backward : %d", ispeed));
		network.sendpacket(WHEEL_BACKWARD, (char*)&ispeed, sizeof(int));

        //[/UserButtonCode_downButton]
    }
    else if (buttonThatWasClicked == rightButton)
    {
        //[UserButtonCode_rightButton] -- add your button handler code here..
		int _rspeed = (int)rspeed;
		int _lspeed = (int)lspeed;

		addMessage(juce::String::formatted("Turn right : rspeed(%d)  lspeed(%d)", _rspeed, _lspeed));

		char data[8];
		memcpy(data, &_lspeed, sizeof(int));
		memcpy(data+sizeof(int), &_rspeed, sizeof(int));
		network.sendpacket(WHEEL_TURNRIGHT, data, sizeof(int) + sizeof(int));

        //[/UserButtonCode_rightButton]
    }
    else if (buttonThatWasClicked == leftButton)
    {
        //[UserButtonCode_leftButton] -- add your button handler code here..
		int _rspeed = (int)rspeed;
		int _lspeed = (int)lspeed;

		addMessage(juce::String::formatted("Turn left : rspeed(%d)  lspeed(%d)", _rspeed, _lspeed));

		char data[8];
		memcpy(data, &_lspeed, sizeof(int));
		memcpy(data+sizeof(int), &_rspeed, sizeof(int));
		network.sendpacket(WHEEL_TURNLEFT, data, sizeof(int) + sizeof(int));

        //[/UserButtonCode_leftButton]
    }
    else if (buttonThatWasClicked == displayButton)
    {
        //[UserButtonCode_displayButton] -- add your button handler code here..
		addMessage("Pushed display");

		std::string str = packetstr.toStdString();
		if(str.size() > 0)
			network.sendpacket(DISPLAY_PIC, (char*)str.c_str(), str.size());


        //[/UserButtonCode_displayButton]
    }
    else if (buttonThatWasClicked == stopButton)
    {
        //[UserButtonCode_stopButton] -- add your button handler code here..
		addMessage("Move Stopped");
		int ispeed = 0;
		network.sendpacket(WHEEL_STOP, (char*)&ispeed, sizeof(int));
        //[/UserButtonCode_stopButton]
    }
    else if (buttonThatWasClicked == patchButton)
    {
        //[UserButtonCode_patchButton] -- add your button handler code here..
		addClientMessage("asdASD");
        //[/UserButtonCode_patchButton]
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
		packetstr = motionLabel->getText();
		addMessage(packetstr);
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
		rspeed = slider->getValue();
        //[/UserSliderCode_slider]
    }
    else if (sliderThatWasMoved == slider2)
    {
        //[UserSliderCode_slider2] -- add your slider handling code here..
		lspeed = slider2->getValue();
        //[/UserSliderCode_slider2]
    }
    else if (sliderThatWasMoved == slider3)
    {
        //[UserSliderCode_slider3] -- add your slider handling code here..
		speed = slider3->getValue();
        //[/UserSliderCode_slider3]
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

void MainGui::addClientMessage(juce::String str)
{
	if (clientmessagelist.size() > MAX_CLIENTMESSAGE)
		clientmessagelist.pop_front();
	clientmessagelist.push_back(str);

	juce::String msg;
	for (size_t i = 0; i < clientmessagelist.size(); i++)
	{
		//if (i > 0) msg += "\n";
		msg += clientmessagelist[i];
	}

	clientlog->setText(msg, juce::NotificationType::dontSendNotification);
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

	if (!Log::getInstance()->clientloglist.empty())
	{
		for (size_t i = 0; i < Log::getInstance()->clientloglist.size(); i++)
		{
			addClientMessage(Log::getInstance()->clientloglist[i]);
		}

		Log::getInstance()->clientloglist.clear();
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
                 parentClasses="public Component, public Timer" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="1000" initialHeight="700">
  <BACKGROUND backgroundColour="ffffffff"/>
  <LABEL name="new label" id="a468f7d6183fa770" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="8 32 408 400" bkgCol="ff000000" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="9"/>
  <TEXTBUTTON name="PlayMotion" id="45a4cb1f3a68127f" memberName="playButton"
              virtualName="" explicitFocusOrder="0" pos="48 544 150 32" buttonText="Play"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="Up" id="aebc4158a6eb6b7f" memberName="upButton" virtualName=""
              explicitFocusOrder="0" pos="664 528 64 32" buttonText="Forward"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="Down" id="4acf33de38e1f39c" memberName="downButton" virtualName=""
              explicitFocusOrder="0" pos="664 640 64 29" buttonText="Backward"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="Right" id="e21e3e353ac7518c" memberName="rightButton" virtualName=""
              explicitFocusOrder="0" pos="744 584 64 32" buttonText="Right"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="motionLabel" id="996f53ca37638546" memberName="motionLabel"
         virtualName="" explicitFocusOrder="0" pos="48 496 152 32" bkgCol="ffffffff"
         textCol="ff000000" outlineCol="ff000000" edTextCol="ff000000"
         edBkgCol="0" labelText="" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="205c96fe532e179a" memberName="slider" virtualName=""
          explicitFocusOrder="0" pos="816 504 40 176" min="0" max="1023"
          int="1" style="LinearVertical" textBoxPos="TextBoxAbove" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <TEXTBUTTON name="Left" id="b1bebbabb70704e8" memberName="leftButton" virtualName=""
              explicitFocusOrder="0" pos="584 584 64 32" buttonText="Left"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="displayButton" id="dcc6371a83dc37f0" memberName="displayButton"
              virtualName="" explicitFocusOrder="0" pos="48 592 150 32" buttonText="display"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="new slider" id="f9cf708c27ef3f2a" memberName="slider2"
          virtualName="" explicitFocusOrder="0" pos="528 504 48 176" min="0"
          max="1023" int="1" style="LinearVertical" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <TEXTBUTTON name="Stop" id="3b9eb620d887ad06" memberName="stopButton" virtualName=""
              explicitFocusOrder="0" pos="664 584 64 29" buttonText="Stop"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="new slider" id="a24977e8b1e23e79" memberName="slider3"
          virtualName="" explicitFocusOrder="0" pos="624 488 150 24" min="1"
          max="1024" int="1" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <TEXTBUTTON name="patchButton" id="477807e8719116cc" memberName="patchButton"
              virtualName="" explicitFocusOrder="0" pos="48 640 150 32" bgColOff="ff650000"
              textCol="ffffffff" buttonText="patch" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <LABEL name="new label" id="3c57c14b243b3d89" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="8 5 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Server log" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="372ca961f8280819" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="432 8 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Client log" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="8572e96c683f304c" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="520 456 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="L-Speed" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="a043201367a4d58f" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="808 456 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="R-Speed" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="clientlog" id="8a981e270187e18b" memberName="clientlog"
         virtualName="" explicitFocusOrder="0" pos="432 32 552 400" bkgCol="ff000000"
         textCol="ffffffff" edTextCol="ff000000" edBkgCol="0" labelText=""
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="0" italic="0" justification="9"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
