#pragma once
#include "MidiMessage.h"
class SharedData
{
public:
	//ofAppのMidiコンイベントを、StateMachine上でaddListnerするために使う
	ofEvent<MidiMessage>*eventReceiveMessage;

	//StateMachine上で操作した値をMidiコンに反映させるために、ofAppへ送るイベント
	ofEvent<MidiMessage>eventSendMessage;
private:

};