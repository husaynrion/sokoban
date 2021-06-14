#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//use NUMPAD for direction;
int main()
{
	char a[9][10] =
		{" #####   ", " #OOO####", " # $S# A#", " #    $ #", " #   # ##", " #$#   # ", " #   ### ", " #####   ", "         "};
	int sizx = 9;
	int sizy = 9;
	int x, y, gameOn = 1, oldX, oldY, newBoxX, newBoxY, testX, testY, cWall = 0, cGoal = 0, hitsWall, boxWall, boxBox, boxGoal, hitsBox;
	for (int i = 0; i < sizx; i++)
	{
		for (int j = 0; j < sizy; j++)
		{
			if (a[i][j] == 'A')
			{
				x = i;
				y = j;
			}
		}
	}

	int wallX[sizx * sizy];
	int wallY[sizx * sizy];
	int goalX[sizx];
	int goalY[sizy];
	for (int i = 0; i < sizx; i++)
	{
		for (int j = 0; j < sizy; j++)
		{
			if (a[i][j] == '#')
			{
				wallX[cWall] = i;
				wallY[cWall] = j;
				cWall++;
			}
		}
	}
	for (int i = 0; i < sizx; i++)
	{
		for (int j = 0; j < sizy; j++)
		{
			if (a[i][j] == 'O')
			{
				goalX[cGoal] = i;
				goalY[cGoal] = j;
				cGoal++;
			}
		}
	}

	while (gameOn == 1)
	{
		printf("A = Man,\n");
		printf("$ = Box,\n");
		printf("O = Goal,\n");
		printf("# = Wall.\n");
		printf("\n");
		printf("+-----------------------------------+\n");
		printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", a[0][8], a[1][8], a[2][8], a[3][8], a[4][8], a[5][8], a[6][8], a[7][8], a[8][8]);
		printf("|-----------------------------------|\n");
		printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", a[0][7], a[1][7], a[2][7], a[3][7], a[4][7], a[5][7], a[6][7], a[7][7], a[8][7]);
		printf("|-----------------------------------|\n");
		printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", a[0][6], a[1][6], a[2][6], a[3][6], a[4][6], a[5][6], a[6][6], a[7][6], a[8][6]);
		printf("|-----------------------------------|\n");
		printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", a[0][5], a[1][5], a[2][5], a[3][5], a[4][5], a[5][5], a[6][5], a[7][5], a[8][5]);
		printf("|-----------------------------------|\n");
		printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", a[0][4], a[1][4], a[2][4], a[3][4], a[4][4], a[5][4], a[6][4], a[7][4], a[8][4]);
		printf("|-----------------------------------|\n");
		printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", a[0][3], a[1][3], a[2][3], a[3][3], a[4][3], a[5][3], a[6][3], a[7][3], a[8][3]);
		printf("|-----------------------------------|\n");
		printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", a[0][2], a[1][2], a[2][2], a[3][2], a[4][2], a[5][2], a[6][2], a[7][2], a[8][2]);
		printf("|-----------------------------------|\n");
		printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", a[0][1], a[1][1], a[2][1], a[3][1], a[4][1], a[5][1], a[6][1], a[7][1], a[8][1]);
		printf("|-----------------------------------|\n");
		printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", a[0][0], a[1][0], a[2][0], a[3][0], a[4][0], a[5][0], a[6][0], a[7][0], a[8][0]);
		printf("+-----------------------------------+\n");
		oldX = x;
		oldY = y;

		/*where is B*/
		int cBox = 0;
		int boxX[sizy];
		int boxY[sizy];
		for (int i = 0; i < sizx; i++)
		{
			for (int j = 0; j < sizy; j++)
			{
				if ((a[i][j] == '$') || (a[i][j] == 'S'))
				{
					boxX[cBox] = i;
					boxY[cBox] = j;
					cBox++;
				}
			}
		}

		boxGoal = 0;
		for (int i = 0; i < cGoal; i++)
		{
			if (a[goalX[i]][goalY[i]] != 'S')
			{
				boxGoal = 1;
			}
		}
		if (boxGoal == 0)
		{
			printf(".\n");
			printf(".\n");
			printf(".\n");
			printf(".\n");
			printf("You Win...!congrats.");
			printf(".\n");
			printf(".\n");
			printf(".\n");
			printf(".\n");
			break;
		}
		char key = getch();
		system("clear");
		switch (key)
		{
		case 'w':
			testY = y + 1;
			testX = x;
			break;
		case 's':
			testY = y - 1;
			testX = x;
			break;
		case 'd':
			testX = x + 1;
			testY = y;
			break;
		case 'a':
			testX = x - 1;
			testY = y;
			break;
		}
		hitsBox = 0;
		int oldBoxX, oldBoxY;
		int testBoxX, testBoxY;
		for (int i = 0; i < cBox; i++)
		{
			if ((testX == boxX[i]) && (testY == boxY[i]))
			{
				oldBoxX = boxX[i];
				oldBoxY = boxY[i];
				hitsBox = 1;
			}
		}
		if (hitsBox == 1)
		{
			switch (key)
			{
			case 'w':
				testBoxY = oldBoxY + (oldBoxY - oldY);
				testBoxX = oldBoxX;
				break;
			case 's':
				testBoxY = oldBoxY + (oldBoxY - oldY);
				testBoxX = oldBoxX;
				break;
			case 'd':
				testBoxX = oldBoxX + (oldBoxX - oldX);
				testBoxY = oldBoxY;
				break;
			case 'a':
				testBoxX = oldBoxX + (oldBoxX - oldX);
				testBoxY = oldBoxY;
				break;
			}
		}
		hitsWall = 0;
		for (int i = 0; i < cWall; i++)
		{
			if ((wallX[i] == testX) && (wallY[i] == testY))
			{
				hitsWall = 1;
			}
		}
		boxWall = 0;
		for (int i = 0; i < cWall; i++)
		{
			if (((wallX[i] == testBoxX) && (wallY[i] == testBoxY)) && ((testX == oldBoxX) && (testY == oldBoxY)))
			{
				boxWall = 1;
			}
		}
		boxBox = 0;
		for (int i = 0; i < cBox; i++)
		{
			if (((boxX[i] == testBoxX) && (boxY[i] == testBoxY)) && ((testX == oldBoxX) && (testY == oldBoxY)))
			{
				boxBox = 1;
			}
		}

		if ((hitsWall == 1) || (boxWall == 1) || (boxBox == 1))
		{
			printf("Ouch...!\n");
		}
		else
		{
			printf("Carry on...\n");
			switch (key)
			{
			case 'w':
				y += 1;
				break;
			case 's':
				y -= 1;
				break;
			case 'd':
				x += 1;
				break;
			case 'a':
				x -= 1;
				break;
			}
			a[x][y] += 33;
			if ((x == oldBoxX) && (y == oldBoxY))
			{
				newBoxX = oldBoxX;
				newBoxY = oldBoxY;
				switch (key)
				{
				case 'w':
					oldBoxY = oldBoxY + (oldBoxY - oldY);
					break;
				case 's':
					oldBoxY = oldBoxY + (oldBoxY - oldY);
					break;
				case 'd':
					oldBoxX = oldBoxX + (oldBoxX - oldX);
					break;
				case 'a':
					oldBoxX = oldBoxX + (oldBoxX - oldX);
					break;
				}
				a[oldBoxX][oldBoxY] += 4;
				a[newBoxX][newBoxY] -= 4;
			}
			a[oldX][oldY] -= 33;
		}

		if (key == 'l')
		{
			gameOn = 0;
		}
	}
	return 0;
}