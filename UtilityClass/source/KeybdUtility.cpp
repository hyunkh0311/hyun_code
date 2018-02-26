#include "../header/KeybdUtility.h"

KeybdClass::KeybdClass()
{

}

KeybdClass::~KeybdClass()
{

}

void KeybdClass::initKey() 
{
	for (int i = 0; i <255; i++)
	{
		keyState[i] = KEY_UP_REP;  //키들의 초기 상태 - 놓여져 있음
	}
}

void KeybdClass::updateKey()  //반복 실행이 되어서..키들의 상태를 변경
{
	for (int i = 1; i < 255; i++)  //모든 키보드의 현재 키 값을 검사함
	{
		int key = GetAsyncKeyState(i); //i 번째 키를 읽어옴

		if (keyState[i] == KEY_UP_REP)  //키가 놓여진 상태 지속
		{
			if ((key & 0x8000) == 0x8000) //키가 눌림
			{
				keyState[i] = KEY_DOWN;  //키가 눌림(한번)
			}
			else {
				keyState[i] = KEY_UP_REP; //놓여진 상태 지속
			}
		}
		else if (keyState[i] == KEY_DOWN) { //키가 한번 눌림

			if ((key & 0x8000) == 0x8000) //키가 눌림
			{
				keyState[i] = KEY_DOWN_REP;  //키가 눌림 지속
			}
			else {
				keyState[i] = KEY_UP;        //키가 눌렸다가 놓여진 상태 
			}
		}
		else if (keyState[i] == KEY_DOWN_REP) {  //키가 눌려서 지속

			if ((key & 0x8000) == 0x8000) //키가 눌림
			{
				keyState[i] = KEY_DOWN_REP;  //키가 눌림 지속
			}
			else {
				keyState[i] = KEY_UP;        //키가 눌렸다가 놓여진 상태 
			}
		}
		else if (keyState[i] == KEY_UP) {  //키가 눌렸다 놓여짐 (한번)

			if ((key & 0x8000) == 0x8000) //키가 눌림
			{
				keyState[i] = KEY_DOWN;  //키가 눌림 한번
			}
			else {
				keyState[i] = KEY_UP_REP;  //키가 눌렸다가 놓여진 상태 
			}
		}

	}
}

bool KeybdClass::getKey(int keycode)  //지속해서 눌려있는지 검사
{
	if (keyState[keycode] == KEY_DOWN || keyState[keycode] == KEY_DOWN_REP)
	{
		return true;
	}
	else {
		return false;
	}
}

bool KeybdClass::getKeyDown(int keycode)
{
	if (keyState[keycode] == KEY_DOWN)
	{
		return true;
	}
	else {
		return false;
	}
}

bool KeybdClass::getKeyUp(int keycode)
{
	if (keyState[keycode] == KEY_UP)
	{
		return true;
	}
	else {
		return false;
	}
}
//
//int main(void)
//{
//	KeybdClass keybd;
//	keybd.initKey();
//
//	while (1)
//	{
//		keybd.updateKey();
//	}
//}
