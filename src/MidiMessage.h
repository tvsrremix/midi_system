#pragma once
#include "ofMain.h"
enum type_midiMessage {
	RECEIVE_NOTE_ON = 0,//Pad����������
	RECEIVE_NOTE_OFF = 1,//�����Ă���Pad�𗣂�����
	RECEIVE_CONTROL = 2,//Fader�𑀍삵����
	SEND_NOTE = 3,//Pad���w��̐F�Ō��点�鎞
	SEND_CONTROL = 4//fader�ɒl�𑗂鎞
};
class MidiMessage {
public:
	int type;//type_midiMassage
	int channel;//Pad��Fader�̗����Ŏg��
	int pitch;//Pad�̎��l(midi�R�����Pad�̈ʒu)
	int control;//Fader�̎��l(midi�R����̃t�F�[�_�̈ʒu)
	int value;//Fader�̎��l(0~127�͈̔�)
	int color;//Pad�̐F
private:
};