#include "mathFunction.h"

//���� ���ϴ� �Լ�
float dotProduct(float x0, float y0, float x1, float y1)
{
	return (x0 * x1) + (y0 * y1);
}

//�������� �������� �Ÿ� ���Ͱ��� ���ϴ� �Լ�
float vectorLength(float x, float y)
{
	return sqrt((x * x) + (y * y));
}

//������ �Ÿ��� ���ϴ� �Լ�
float distanceBetweenTwoPoint(float x0, float y0, float x1, float y1)
{
	return sqrt((x0 - x1)*(x0 - x1) + (y0 - y1)*(y0 - y1));
	//return sqrt(pow(x0 - x1, 2) + pow(y0 - y1, 2));
}

//�ΰ��� ���� �浹 �˻�
bool checkCircleCollision(float _distance, float _radius1, float _radius2)
{
	if (_distance < (_radius1 + _radius2)) // ������ �浹
	{
		return true;
	}
	else if (_distance >= (_radius1 + _radius2)) // ���ų� ũ�� �浹���� ����
	{
		return false;
	}
}

// �κ����� ���հ��� ���ϴ� �Լ� (���� = ���� * ���� * cos)  (cos = (���� * ����) / ����)
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

	printf("���� = %f \n", dotProduct(x0, y0, x1, y1));
	printf("1�� ���� ���� ���� = %f \n", vectorLength(x0, y0));
	printf("2�� ���� ���� ���� = %f \n", vectorLength(x1, y1));
	printf("cosO = %f\n", angleBetweenTwoPointResult);
	printf("acos -> radian = %lf\n", acos(angleBetweenTwoPointResult));
	printf("���� ��ȯ  %f \n", acos(angleBetweenTwoPointResult) *(180 / 3.141592));
}

*/