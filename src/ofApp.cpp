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
	//�����ł�1key���������ƂŁA����midi�R���������ꂽ�l�q���Č�����
	if (key == '1')
	{
		MidiMessage mm;
		mm.type = RECEIVE_NOTE_ON;//Midi�R���������ꂽ
		mm.channel = 1;
		mm.pitch = 48;
		//channel:48��pad�������ꂽ���Ƃ�stateMachine�ɒm�点��
		ofNotifyEvent(eventReceiveMessage, mm);
	}

}

void ofApp::sendMidi(MidiMessage &message)
{
	//stateMachine����event�����ł������̏���������
	cout << "ofApp massage.type:" << message.type << endl;
	switch (message.type)
	{
	case SEND_NOTE:
		break;
	case SEND_CONTROL:
		break;
	}
}