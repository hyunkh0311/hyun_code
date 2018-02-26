#pragma once

#include <math.h>
#include <stdio.h>

//���� ���ϴ� �Լ�
float dotProduct(float x0, float y0, float x1, float y1);

//�������� �������� �Ÿ� ���Ͱ��� ���ϴ� �Լ�
float vectorLength(float x, float y);

//������ �Ÿ��� ���ϴ� �Լ�
float distanceBetweenTwoPoint(float x0, float y0, float x1, float y1);

//�ΰ��� �� �浹 �˻�
bool checkCircleCollision(float _distance, float _radius1, float _radius2);

// �κ����� ���հ��� ���ϴ� �Լ� (���� = ���� * ���� * cos)  (cos = (���� * ����) / ����)
float angleBetweenTwoPoint(float dot, float vectorLength1, float vectorLength2);