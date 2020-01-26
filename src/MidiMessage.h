#pragma once
#include "ofMain.h"
enum type_midiMessage {
	RECEIVE_NOTE_ON = 0,//Padを押した時
	RECEIVE_NOTE_OFF = 1,//押していたPadを離した時
	RECEIVE_CONTROL = 2,//Faderを操作した時
	SEND_NOTE = 3,//Padを指定の色で光らせる時
	SEND_CONTROL = 4//faderに値を送る時
};
class MidiMessage {
public:
	int type;//type_midiMassage
	int channel;//PadとFaderの両方で使う
	int pitch;//Padの持つ値(midiコン上のPadの位置)
	int control;//Faderの持つ値(midiコン上のフェーダの位置)
	int value;//Faderの持つ値(0~127の範囲)
	int color;//Padの色
private:
};