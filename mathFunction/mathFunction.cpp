#include "mathFunction.h"

//내적 구하는 함수
float dotProduct(float x0, float y0, float x1, float y1)
{
	return (x0 * x1) + (y0 * y1);
}

//원점에서 점까지의 거리 백터값을 구하는 함수
float vectorLength(float x, float y)
{
	return sqrt((x * x) + (y * y));
}

//두점의 거리를 구하는 함수
float distanceBetweenTwoPoint(float x0, float y0, float x1, float y1)
{
	return sqrt((x0 - x1)*(x0 - x1) + (y0 - y1)*(y0 - y1));
	//return sqrt(pow(x0 - x1, 2) + pow(y0 - y1, 2));
}

//두개의 원의 충돌 검사
bool checkCircleCollision(float _distance, float _radius1, float _radius2)
{
	if (_distance < (_radius1 + _radius2)) // 작으면 충돌
	{
		return true;
	}
	else if (_distance >= (_radius1 + _radius2)) // 같거나 크면 충돌하지 않음
	{
		return false;
	}
}

// 두벡터의 사잇각을 구하는 함수 (내적 = 길이 * 길이 * cos)  (cos = (길이 * 길이) / 내적)
float angleBetweenTwoPoint(float dot, float vectorLength1,float vectorLength2)
{
	return (dot/(vectorLength1 * vectorLength2));
}
/*
int main(void)
{
	float dotProductResult;
	float vectorLengthResult1;
	float vectorLengthResult2;
	float angleBetweenTwoPointResult;
	int x0 = 0;
	int y0 = 1;
	int x1 = -5;
	int y1 = -5;

	dotProductResult = dotProduct(x0, y0, x1, y1);
	vectorLengthResult1 = vectorLength(x0, y0);
	vectorLengthResult2 = vectorLength(x1, y1);
	angleBetweenTwoPointResult = angleBetweenTwoPoint(dotProductResult, vectorLengthResult1, vectorLengthResult2);

	printf("내적 = %f \n", dotProduct(x0, y0, x1, y1));
	printf("1번 점의 단위 백터 = %f \n", vectorLength(x0, y0));
	printf("2번 점의 단위 백터 = %f \n", vectorLength(x1, y1));
	printf("cosO = %f\n", angleBetweenTwoPointResult);
	printf("acos -> radian = %lf\n", acos(angleBetweenTwoPointResult));
	printf("각도 변환  %f \n", acos(angleBetweenTwoPointResult) *(180 / 3.141592));
}

*/