#include "헤더.h";

void gotoxy(int x, int y);
void gotoxyDelete(void);
void snakeDraw(int x, int y);
void starDraw(void);
int gameLifeDraw(void);
void gameLogPrint(void);
void gameEndDraw(void);
int updateGamePoint(void);

int main(void)
{
	bool toggleKey = true;
	int playerX = PLAYER_START_POSITION_X, playerY= PLAYER_START_POSITION_Y; // 현재 뱀의 좌표
	int playerNextX = playerX, playerNextY = playerY; // 다음 이동할 뱀의 좌표
	int bodyX[BODY_MAX_LENGTH] = { playerX, }, bodyY[BODY_MAX_LENGTH] = { playerY, }; // 뱀의 몸통 좌표

	char moveKey;

	gotoxyDelete();
	
	while (1)
	{
		if (toggleKey == true) // w,s,a,d 키가 눌렸을때 루틴 진입
		{
			for (int heightMap = 0; heightMap < WIDTH_MAP_SIZE; heightMap++)
			{
				for (int widthMap = 0; widthMap < HEIGHT_MAP_SIZE; widthMap++)
				{
					gotoxy(widthMap * 2, heightMap);
					if (GameMap[heightMap][widthMap] == 1)
					{
						printf("■");
					}
					else if (GameMap[heightMap][widthMap] == 0)
					{
						printf("  ");
					}
					else if (GameMap[heightMap][widthMap] == 2)
					{
						printf("☆");
					}
					else if (GameMap[heightMap][widthMap] == 3)
					{
						
					}
				}
				printf("\n");
			}
			
			//몸통 그리기.
			for (int i = 0; i < BODY_MAX_LENGTH; i++)
			{
				gotoxy(bodyX[i] * 2, bodyY[i]);
				printf("▦");
				GameMap[bodyY[i]][bodyX[i]] = 3;
			}

			//----------- Draw Function-----------
			snakeDraw(playerX, playerY);
//			DEBUG_FUNCTION;
			starDraw();
			gameLifeDraw();
			gameLogPrint();
			toggleKey = false;
		}

		// 키보드 입력 받기
		moveKey = _getch();

		if (moveKey == 'w')
		{
			playerNextY = playerY - 1;
		}
		else if (moveKey == 's')
		{
			playerNextY = playerY + 1;
		}
		else if (moveKey == 'a')
		{
			playerNextX = playerX - 1;
		}
		else if (moveKey == 'd')
		{
			playerNextX = playerX + 1;
		}
		if (moveKey == 'q' || gameLife==0)
		{
			gameEndDraw();
			// 게임 종료
			return 0;
		}
		else
		{
			// 다른 키 조작
		}
		
		//몸통에 대한 이전 머리 좌표 저장
		bodyX[0] = playerX;
		bodyY[0] = playerY;

		//마지막 몸통 자리 빈칸으로 지우기
		GameMap[bodyY[BODY_MAX_LENGTH - 1]][bodyX[BODY_MAX_LENGTH - 1]] = 0;

		//몸통 자리 한칸씩 앞으로 시프트
		for (int i = BODY_MAX_LENGTH -1; i > 0; i--)
		{
			bodyX[i] = bodyX[i-1];
			bodyY[i] = bodyY[i-1];
		}


		// 다음좌표 이동 가능 여부 확인
		if(GameMap[playerNextY][playerNextX]==0) // 빈칸 이동 가능
		{
			playerX = playerNextX;
			playerY = playerNextY;
			toggleKey = true;
		}
		else if(GameMap[playerNextY][playerNextX] == 1 || GameMap[playerNextY][playerNextX] == 3) // 벽이나 몸통에 부딪쳤을때
		{
			gameLife -= 1;// 라이프 감소
			playerNextX = playerX;
			playerNextY = playerY;
			toggleKey = true;
		}
		else if (GameMap[playerNextY][playerNextX] == 2) // 아이템 획득
		{
			playerX = playerNextX;
			playerY = playerNextY;
			itemNumber = 0;  // 필드에 아이템 숫자 0
			GameMap[playerY][playerX] = 0; // 아이템 위치를 빈공간으로
			updateGamePoint(); // 점수 증가
			toggleKey = true;
		}
	}
	return 0;
}

void gotoxy(int x, int y)
{
	COORD Pos;

	Pos.X = x;
	Pos.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void gotoxyDelete(void)
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void snakeDraw(int x, int y)
{
	gotoxy(x * 2, y);
	printf("◐");
}

void starDraw(void)
{
	int randX, randY;

	srand(time(NULL));

	randX = rand() % 20; // 난수 좌표 생성
	randY = rand() % 20;

	if ((!(GameMap[randY][randX] == 1))) // 벽이 아닌 곳에 아이템 생성
	{
		if (itemNumber == 0)
		{
			gotoxy(randX *2, randY);
			printf("☆");
			GameMap[randY][randX] = 2;
			itemNumber = 1;		
		}
	}

}

int gameLifeDraw(void)
{
	gotoxy(42, 2);

	printf("Snake Life : ");

	if(gameLife == LIFE_MAX)
	{
		for (int i = 0; i < LIFE_MAX; i++)
		{
			printf("♥ ");
		}
	}
	else if (gameLife < LIFE_MAX)
	{
		for (int i = gameLife; i < LIFE_MAX; i++)
		{
			printf("♡ ");
		}
	}
	//DEBUG_FUNCTION;
	return gameLife;

}

void gameLogPrint(void)
{
	gotoxy(0, 20);
	printf("game Life = %d\n", gameLife);
	printf("game Point = %d\n",gamePoint);
	DEBUG_FUNCTION;
}

void gameEndDraw(void)
{
	system("cls");
	for (int heightMap = 0; heightMap < HEIGHT_MAP_SIZE + 4; heightMap++)
	{
		for (int widthMap = 0; widthMap < WIDTH_MAP_SIZE - 2; widthMap++)
		{
			gotoxy(widthMap * 2, heightMap);
			if (GameOver[heightMap][widthMap] == 4)
			{
				printf("■");
			}
		}
		printf("\n");
	}
	gotoxy(40, 15);
}

int updateGamePoint(void)
{
	gamePoint += 10;

	return gamePoint;
}