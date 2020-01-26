#pragma once

#include "ofMain.h"
#include "ofxStateMachine.h"
#include "MidiMessage.h"
#include "SharedData.h"
#include "TestState.h"
class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void sendMidi(MidiMessage &message);

	//midiコンから値を受け取る
	ofEvent<MidiMessage>eventReceiveMessage;
	//midiコンへ値を送る
	ofEvent<MidiMessage>*eventSendMessage;
private:
	//stateMachine
	itg::ofxStateMachine<SharedData>stateMachine;
};