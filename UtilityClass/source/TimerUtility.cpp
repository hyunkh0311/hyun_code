#include "../header/TimerUtility.h"

// Ÿ�̸� ��ƿ
TimerClass::TimerClass()
{
	prevTime = 0;
	currTime = 0;
	deltaTime = 0;
}

TimerClass::~TimerClass()
{

}
TimerClass::TimerClass(float _prevTime, float _currTime, float _deltaTime)
{
	prevTime = _prevTime;
	currTime = _currTime;
	deltaTime = _deltaTime;
}


////Ÿ�̸� ��ƿ ����
//int main(void)
//{
//	TimerClass timer;
//	int sum = 0;
//	timer.velocity = 10;
//	float y = 0; // �ʱ� ĳ������ y ��ǥ
//
//	timer.initTimer(); // Ÿ�̸� ����
//
//	//-------------------------------//
//	while (true)  // ���� �ݺ� -- �������� ����
//	{
//		//Sleep(10);
//		timer.updateTimer(); // Ÿ�̸� ����
//		y = y * timer.characterDistance(); // ĳ���� �̵��Ÿ� ���
//	}
//}