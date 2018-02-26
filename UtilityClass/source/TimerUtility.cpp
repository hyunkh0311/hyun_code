#include "../header/TimerUtility.h"

// 타이머 유틸
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


////타이머 유틸 사용법
//int main(void)
//{
//	TimerClass timer;
//	int sum = 0;
//	timer.velocity = 10;
//	float y = 0; // 초기 캐릭터의 y 좌표
//
//	timer.initTimer(); // 타이머 시작
//
//	//-------------------------------//
//	while (true)  // 게임 반복 -- 프레임이 생성
//	{
//		//Sleep(10);
//		timer.updateTimer(); // 타이머 종료
//		y = y * timer.characterDistance(); // 캐릭터 이동거리 계산
//	}
//}