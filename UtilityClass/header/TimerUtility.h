#pragma once

#include <iostream>
#include <Windows.h>


// 타이머 클래스

class TimerClass {
public:
	TimerClass(); // 생성자
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
		currTime = 0;  // GetTickCount = 1초에 1000
		deltaTime = 0;
	}

	void updateTimer()
	{
		currTime = (float)(GetTickCount() / 1000.0);  //현재 시간을 측정한다.
		deltaTime = currTime - prevTime;             //이전 프레임과의 시간 차이를 측정한다. 
		prevTime = currTime;                          //현재 측정된 시간은 이전 프레임값으로 저장된다.
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
