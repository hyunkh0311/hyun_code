#include "header.h"
//테스트 해보자
//예제 선택
#define EXAM_COLOR_PRINT 1
#define EXAM_VECTOR 0


#if EXAM_VECTOR

struct Object
{
	Vector2Class pos;
	float speed;
};

Vector2Class normal(Vector2Class v)
{
	Vector2Class nor;
	float length = sqrt(v.x * v.x + v.y * v.y);

	nor.x = v.x / length;
	nor.y = v.y / length;

	return nor;
}

Vector2Class mul(Vector2Class v, float s)
{
	Vector2Class m;
	m.x = v.x * s;
	m.y = v.y * s;

	return m;
}

Vector2Class add(Vector2Class v1, Vector2Class v2)
{
	Vector2Class v;
	v.x = v1.x + v2.x;
	v.y = v1.y + v2.y;

	return v;
}

Vector2Class sub(Vector2Class v1, Vector2Class v2)
{
	Vector2Class v;
	v.x = v1.x - v2.x;
	v.y = v1.y - v2.y;

	return v;
}
int main(void)
{
	KeybdClass keybd1;
	TimerClass timer1;
	ConsoleClass console1;


	Object star = { {10, 10, 0, 0}, 10 };
	Object rect = { {10, 50, 0, 0}, 5 };
	
	keybd1.initKey();
	timer1.initTimer();

	while (true)
	{
		keybd1.updateKey();
		timer1.updateTimer();

		console1.clear(star.pos.x, star.pos.y);
		console1.clear(rect.pos.x, rect.pos.y);

		float dist = timer1.getDeltaTime() * star.speed;

		if(keybd1.getKey('W') == true)
		{
			star.pos.y -= dist;
		}
		if (keybd1.getKey('S') == true)
		{
			star.pos.y += dist;
		}
		if (keybd1.getKey('A') == true)
		{
			star.pos.x -= dist;
		}
		if (keybd1.getKey('D') == true)
		{
			star.pos.x += dist;
		}

		if (star.pos.x != rect.pos.x || star.pos.y != rect.pos.y)
		{

			//사각형 이동 시키기
			/*float dx = star.pos.x - rect.pos.x;
			float dy = star.pos.y - rect.pos.y;*/

			Vector2Class d = sub(star.pos, rect.pos);
			Vector2Class n = normal(d);
			Vector2Class m = mul(n, timer1.getDeltaTime() * rect.speed);
			
			rect.pos = add(rect.pos, m);
		}
		
		// 화면 출력하기 - 렌더링
		console1.draw(star.pos.x, star.pos.y, "☆");
		console1.draw(rect.pos.x, rect.pos.y, "■");

		Sleep(10);
	}

}

#endif


#if EXAM_COLOR_PRINT
int main(void)
{
	FONT_COLOR_RED;
	printf("Color Test \n");
	FONT_COLOR_BLUE;
	printf("Color Test \n");
	FONT_COLOR_GREEN;
	printf("Color Test \n");
	FONT_COLOR_YELLOW;
	printf("Color Test \n");
	FONT_COLOR_PINK;
	printf("Color Test \n");

}
#endif