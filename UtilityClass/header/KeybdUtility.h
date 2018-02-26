#pragma once

#include <iostream>
#include <Windows.h>

/**************************************************
#define KEY_UP_REP   0   //Ű�� ������ ����
#define KEY_DOWN     1   //Ű�� ����(�ѹ�)
#define KEY_DOWN_REP 2   //Ű�� ������ ����
#define KEY_UP       3   //Ű�� ����(�ѹ�)
****************************************************/


class KeybdClass{
public:
	KeybdClass();
	~KeybdClass();

public:
	enum KeyState { KEY_UP_REP = 0, KEY_DOWN = 1, KEY_DOWN_REP = 2, KEY_UP = 3 };

	KeyState keyState[255];
	
	void initKey();  //ó�� �ѹ� ����Ǿ..��� Ű�� ���¸� KEY_UP_REP�� ����
	void updateKey();  //�ݺ� ������ �Ǿ..Ű���� ���¸� ����

	///////////����Ƽ ���� Ű�Է� �Լ� ����� ����////////////
	bool getKey(int keycode);  //�����ؼ� �����ִ��� �˻�

	bool getKeyDown(int keycode); // ������ ���� Ű �˻�

	bool getKeyUp(int keycode); // Ű���带 �����ٰ� �ö���� ����
};