#pragma once

#include <math.h>
#include <stdio.h>


class MathClass {

public:
	MathClass();
	~MathClass();

	//내적 구하는 함수
	float dotProduct(float x0, float y0, float x1, float y1);

	//원점에서 점까지의 거리 백터값을 구하는 함수
	float vectorLength(float x, float y);

	//두점의 거리를 구하는 함수
	float distanceBetweenTwoPoint(float x0, float y0, float x1, float y1);

	//두개의 원 충돌 검사
	bool checkCircleCollision(float _distance, float _radius1, float _radius2);

	// 두벡터의 사잇각을 구하는 함수 (내적 = 길이 * 길이 * cos)  (cos = (길이 * 길이) / 내적)
	float angleBetweenTwoPoint(float dot, float vectorLength1, float vectorLength2);

	//단위 백터 (x0,y0) (x1,y1)
	void unitVector(float x0, float y0, float x1, float y1, float *dx, float *dy)
	{
		
	}

	//방향 백터 (x0,y0) (x1,y1)
	void directVector(float *x0, float *y0, float *x1, float *y1)
	{

	}
};