#pragma once
#include "MidiMessage.h"
class SharedData
{
public:
	//ofApp��Midi�R���C�x���g���AStateMachine���addListner���邽�߂Ɏg��
	ofEvent<MidiMessage>*eventReceiveMessage;

	//StateMachine��ő��삵���l��Midi�R���ɔ��f�����邽�߂ɁAofApp�֑���C�x���g
	ofEvent<MidiMessage>eventSendMessage;
private:

};