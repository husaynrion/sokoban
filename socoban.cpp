#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//use NUMPAD for direction;
int main()
{
	char a[9][10] =
		{" #####   ", " #OOO####", " # $S#  #", " #    $A#", " #   # ##", " #$#   # ", " #   ### ", " #####   ", "         "};
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
			if ((a[i][j] == 'O') || (a[i][j] == 'S'))
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

		//edit
		printf("+-----------------------------------+\n");
		for (int j = 8; j >= 0; j--)
		{
			for (int i = 0; i <= 8; i++)
			{
				textcolor(WHITE);
				printf("|");
				if (a[i][j] == 'S')
				{
					textcolor(GREEN);
				}
				else if (a[i][j] == '#')
				{
					textcolor(BLUE);
				}
				else if (a[i][j] == '$')
				{
					textcolor(YELLOW);
				}
				else if ((a[i][j]== 'A') || (a[i][j]== 'p'))
				{
					textcolor(RED);
				}
				else
				{
					textcolor(WHITE);
				}
				printf(" %c ", a[i][j]);
			}
			textcolor(WHITE);
			printf("|\n");
			if (j != 0)
			{
				printf("|-----------------------------------|\n");
			}
		}
		printf("+-----------------------------------+\n");
		//edit
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