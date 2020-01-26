#include "ofApp.h"

void ofApp::setup()
{
	stateMachine.getSharedData().eventReceiveMessage = &eventReceiveMessage;
	eventSendMessage = &stateMachine.getSharedData().eventSendMessage;

	stateMachine.addState<TestState>();

	ofAddListener(*eventSendMessage, this, &ofApp::sendMidi);

	stateMachine.changeState("test");
}

void ofApp::update() {}
void ofApp::draw() {}

void ofApp::keyPressed(int key)
{
	//ここでは1keyを押すことで、仮にmidiコンが押された様子を再現する
	if (key == '1')
	{
		MidiMessage mm;
		mm.type = RECEIVE_NOTE_ON;//Midiコンが押された
		mm.channel = 1;
		mm.pitch = 48;
		//channel:48のpadが押されたことをstateMachineに知らせる
		ofNotifyEvent(eventReceiveMessage, mm);
	}

}

void ofApp::sendMidi(MidiMessage &message)
{
	//stateMachineからeventが飛んできた時の処理を書く
	cout << "ofApp massage.type:" << message.type << endl;
	switch (message.type)
	{
	case SEND_NOTE:
		break;
	case SEND_CONTROL:
		break;
	}
}