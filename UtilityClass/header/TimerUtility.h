#pragma once

#include <iostream>
#include <Windows.h>


// Ÿ�̸� Ŭ����

class TimerClass {
public:
	TimerClass(); // ������
	~TimerClass();

	TimerClass(float _prevTime, float _currTime, float _deltaTime);
public:


private :
	float prevTime;
	float currTime;
	float deltaTime;

public:

	void initTimer()
	{
		prevTime = (float)(GetTickCount() / 1000.0);
		currTime = 0;  // GetTickCount = 1�ʿ� 1000
		deltaTime = 0;
	}

	void updateTimer()
	{
		currTime = (float)(GetTickCount() / 1000.0);  //���� �ð��� �����Ѵ�.
		deltaTime = currTime - prevTime;             //���� �����Ӱ��� �ð� ���̸� �����Ѵ�. 
		prevTime = currTime;                          //���� ������ �ð��� ���� �����Ӱ����� ����ȴ�.
	}

	float getDeltaTime()
	{
		return deltaTime;
	}
	float getCurrTime()
	{
		return currTime;
	}
	float getPrevTime()
	{
		return prevTime;
	}
};
