#pragma once

#include <iostream>
#include <Windows.h>

/**************************************************
#define KEY_UP_REP   0   //키가 놓여서 지속
#define KEY_DOWN     1   //키가 눌림(한번)
#define KEY_DOWN_REP 2   //키가 눌려서 지속
#define KEY_UP       3   //키가 놓임(한번)
****************************************************/


class KeybdClass{
public:
	KeybdClass();
	~KeybdClass();

public:
	enum KeyState { KEY_UP_REP = 0, KEY_DOWN = 1, KEY_DOWN_REP = 2, KEY_UP = 3 };

	KeyState keyState[255];
	
	void initKey();  //처음 한번 실행되어서..모든 키의 상태를 KEY_UP_REP로 만듬
	void updateKey();  //반복 실행이 되어서..키들의 상태를 변경

	///////////유니티 유사 키입력 함수 만들어 보기////////////
	bool getKey(int keycode);  //지속해서 눌려있는지 검사

	bool getKeyDown(int keycode); // 눌리는 순간 키 검사

	bool getKeyUp(int keycode); // 키보드를 눌렀다가 올라오는 순간
};