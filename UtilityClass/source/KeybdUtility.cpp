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
		keyState[i] = KEY_UP_REP;  //Ű���� �ʱ� ���� - ������ ����
	}
}

void KeybdClass::updateKey()  //�ݺ� ������ �Ǿ..Ű���� ���¸� ����
{
	for (int i = 1; i < 255; i++)  //��� Ű������ ���� Ű ���� �˻���
	{
		int key = GetAsyncKeyState(i); //i ��° Ű�� �о��

		if (keyState[i] == KEY_UP_REP)  //Ű�� ������ ���� ����
		{
			if ((key & 0x8000) == 0x8000) //Ű�� ����
			{
				keyState[i] = KEY_DOWN;  //Ű�� ����(�ѹ�)
			}
			else {
				keyState[i] = KEY_UP_REP; //������ ���� ����
			}
		}
		else if (keyState[i] == KEY_DOWN) { //Ű�� �ѹ� ����

			if ((key & 0x8000) == 0x8000) //Ű�� ����
			{
				keyState[i] = KEY_DOWN_REP;  //Ű�� ���� ����
			}
			else {
				keyState[i] = KEY_UP;        //Ű�� ���ȴٰ� ������ ���� 
			}
		}
		else if (keyState[i] == KEY_DOWN_REP) {  //Ű�� ������ ����

			if ((key & 0x8000) == 0x8000) //Ű�� ����
			{
				keyState[i] = KEY_DOWN_REP;  //Ű�� ���� ����
			}
			else {
				keyState[i] = KEY_UP;        //Ű�� ���ȴٰ� ������ ���� 
			}
		}
		else if (keyState[i] == KEY_UP) {  //Ű�� ���ȴ� ������ (�ѹ�)

			if ((key & 0x8000) == 0x8000) //Ű�� ����
			{
				keyState[i] = KEY_DOWN;  //Ű�� ���� �ѹ�
			}
			else {
				keyState[i] = KEY_UP_REP;  //Ű�� ���ȴٰ� ������ ���� 
			}
		}

	}
}

bool KeybdClass::getKey(int keycode)  //�����ؼ� �����ִ��� �˻�
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
