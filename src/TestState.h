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

	//state切り替え時に1度だけ呼ばれる
	void stateEnter()
	{
		cout << "stateEnter" << endl;
		//このstateのactive開始時にAddListnerする
		ofAddListener(*getSharedData().eventReceiveMessage, this, &TestState::receiveMidi);
	}

	void stateExit()
	{
		cout << "exitEnter" << endl;
		//このstateのexit時にRemoveListnerする
		ofRemoveListener(*getSharedData().eventReceiveMessage, this, &TestState::receiveMidi);
	}

	void keyPressed(int key)
	{
		//midiコンを光らせる処理
		if (key == '2') {
			MidiMessage mm;
			mm.type = SEND_NOTE;
			mm.channel = 1;
			mm.pitch = 48;
			mm.color = 1;
			//channel:1,pitch:48のPadを1番のcolorにするイベントをofAppへ発火
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