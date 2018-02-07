#include "���.h";

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
	int playerX = PLAYER_START_POSITION_X, playerY= PLAYER_START_POSITION_Y; // ���� ���� ��ǥ
	int playerNextX = playerX, playerNextY = playerY; // ���� �̵��� ���� ��ǥ
	int bodyX[BODY_MAX_LENGTH] = { playerX, }, bodyY[BODY_MAX_LENGTH] = { playerY, }; // ���� ���� ��ǥ

	char moveKey;

	gotoxyDelete();
	
	while (1)
	{
		if (toggleKey == true) // w,s,a,d Ű�� �������� ��ƾ ����
		{
			for (int heightMap = 0; heightMap < WIDTH_MAP_SIZE; heightMap++)
			{
				for (int widthMap = 0; widthMap < HEIGHT_MAP_SIZE; widthMap++)
				{
					gotoxy(widthMap * 2, heightMap);
					if (GameMap[heightMap][widthMap] == 1)
					{
						printf("��");
					}
					else if (GameMap[heightMap][widthMap] == 0)
					{
						printf("  ");
					}
					else if (GameMap[heightMap][widthMap] == 2)
					{
						printf("��");
					}
					else if (GameMap[heightMap][widthMap] == 3)
					{
						
					}
				}
				printf("\n");
			}
			
			//���� �׸���.
			for (int i = 0; i < BODY_MAX_LENGTH; i++)
			{
				gotoxy(bodyX[i] * 2, bodyY[i]);
				printf("��");
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

		// Ű���� �Է� �ޱ�
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
			// ���� ����
			return 0;
		}
		else
		{
			// �ٸ� Ű ����
		}
		
		//���뿡 ���� ���� �Ӹ� ��ǥ ����
		bodyX[0] = playerX;
		bodyY[0] = playerY;

		//������ ���� �ڸ� ��ĭ���� �����
		GameMap[bodyY[BODY_MAX_LENGTH - 1]][bodyX[BODY_MAX_LENGTH - 1]] = 0;

		//���� �ڸ� ��ĭ�� ������ ����Ʈ
		for (int i = BODY_MAX_LENGTH -1; i > 0; i--)
		{
			bodyX[i] = bodyX[i-1];
			bodyY[i] = bodyY[i-1];
		}


		// ������ǥ �̵� ���� ���� Ȯ��
		if(GameMap[playerNextY][playerNextX]==0) // ��ĭ �̵� ����
		{
			playerX = playerNextX;
			playerY = playerNextY;
			toggleKey = true;
		}
		else if(GameMap[playerNextY][playerNextX] == 1 || GameMap[playerNextY][playerNextX] == 3) // ���̳� ���뿡 �ε�������
		{
			gameLife -= 1;// ������ ����
			playerNextX = playerX;
			playerNextY = playerY;
			toggleKey = true;
		}
		else if (GameMap[playerNextY][playerNextX] == 2) // ������ ȹ��
		{
			playerX = playerNextX;
			playerY = playerNextY;
			itemNumber = 0;  // �ʵ忡 ������ ���� 0
			GameMap[playerY][playerX] = 0; // ������ ��ġ�� ���������
			updateGamePoint(); // ���� ����
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
	printf("��");
}

void starDraw(void)
{
	int randX, randY;

	srand(time(NULL));

	randX = rand() % 20; // ���� ��ǥ ����
	randY = rand() % 20;

	if ((!(GameMap[randY][randX] == 1))) // ���� �ƴ� ���� ������ ����
	{
		if (itemNumber == 0)
		{
			gotoxy(randX *2, randY);
			printf("��");
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
			printf("�� ");
		}
	}
	else if (gameLife < LIFE_MAX)
	{
		for (int i = gameLife; i < LIFE_MAX; i++)
		{
			printf("�� ");
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
				printf("��");
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