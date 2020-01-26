#pragma once
#include "ofxState.h"
#pragma once
#include "SharedData.h"
#include "MidiMessage.h"
class TestState : public itg::ofxState<SharedData>
{
public:
	void setup() {}
	void update() {}
	void draw() {}

	//state�؂�ւ�����1�x�����Ă΂��
	void stateEnter()
	{
		cout << "stateEnter" << endl;
		//����state��active�J�n����AddListner����
		ofAddListener(*getSharedData().eventReceiveMessage, this, &TestState::receiveMidi);
	}

	void stateExit()
	{
		cout << "exitEnter" << endl;
		//����state��exit����RemoveListner����
		ofRemoveListener(*getSharedData().eventReceiveMessage, this, &TestState::receiveMidi);
	}

	void keyPressed(int key)
	{
		//midi�R�������点�鏈��
		if (key == '2') {
			MidiMessage mm;
			mm.type = SEND_NOTE;
			mm.channel = 1;
			mm.pitch = 48;
			mm.color = 1;
			//channel:1,pitch:48��Pad��1�Ԃ�color�ɂ���C�x���g��ofApp�֔���
			ofNotifyEvent(getSharedData().eventSendMessage, mm);
		}
	}
	string getName()
	{
		return "test";
	}
	void receiveMidi(MidiMessage &massage)
	{
		cout << "TestState massage.type:" << massage.type << endl;
		switch (massage.type)
		{
		case RECEIVE_NOTE_ON:
			break;
		case RECEIVE_NOTE_OFF:
			break;
		case RECEIVE_CONTROL:
			break;
		}
	}
};