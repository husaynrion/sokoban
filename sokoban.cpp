#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define BLACK 0

#define BLUE 1

#define GREEN 2

#define CYAN 3

#define RED 4

#define MAGENTA 5

#define BROWN 6

#define LIGHTGRAY 7

#define DARKGRAY 8

#define LIGHTBLUE 9

#define LIGHTGREEN 10

#define LIGHTCYAN 11

#define LIGHTRED 12

#define LIGHTMAGENTA 13

#define YELLOW 14

#define WHITE 15


// Define textcolor function START
void textcolor (int color)
{
    static int __BACKGROUND;

    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;


    GetConsoleScreenBufferInfo(h, &csbiInfo);

    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
                             color + (__BACKGROUND << 4));
}
// Define textcolor function END


struct position {
    int x;
    int y;

    int lastX;
    int lastY;
};

int main()
{
	char cell[9][10] =
    // Paste the Maze Pattern in the below line
        {" ####    "," #  ###  "," #  $ ## "," #  $  # "," ## ##A# "," # OO# # "," #     # "," ####### ","         "};

	int _size = 9;

	struct position worker;
	// Finding position of the worker
	for (int x = 0; x < _size; x++)
	{
		for (int y = 0; y < _size; y++)
		{
			if (cell[x][y] == 'A')
			{
				worker.x = x;
				worker.y = y;
			}
		}
	}

	struct position wall[_size * _size];
	int wallCount = 0;

	struct position goal[_size * _size];
	int goalCount = 0;

	for (int x = 0; x < _size; x++)
	{
		for (int y = 0; y < _size; y++)
		{
			if (cell[x][y] == '#')
			{
				wall[wallCount].x = x;
				wall[wallCount].y = y;
				wallCount++;
			}
		}
	}


	for (int x = 0; x < _size; x++)
	{
		for (int y = 0; y < _size; y++)
		{
			if ((cell[x][y] == 'O') || (cell[x][y] == 'S'))
			{
				goal[goalCount].x = x;
				goal[goalCount].y = y;
				goalCount++;
			}
		}
	}

	int  gameOn = 1;
	while (gameOn == 1)
	{
		printf("A = Worker,\n");
		printf("$ = Box,\n");
		printf("O = Goal,\n");
		printf("# = Wall.\n");
		printf("\n");

		//edit
		printf("+-----------------------------------+\n");
		for (int y = 8; y >= 0; y--)
		{
			for (int x = 0; x <= 8; x++)
			{
				textcolor(WHITE);
				printf("|");
				if (cell[x][y] == 'S')
				{
					textcolor(LIGHTGREEN);
				}
				else if (cell[x][y] == '#')
				{
					textcolor(LIGHTBLUE);
				}
				else if (cell[x][y] == '$')
				{
					textcolor(YELLOW);
				}
				else if ((cell[x][y]== 'A') || (cell[x][y]== 'p'))
				{
					textcolor(LIGHTRED);
				}
				else
				{
					textcolor(WHITE);
				}
				printf(" %c ", cell[x][y]);
			}
			textcolor(WHITE);
			printf("|\n");
			if (y != 0)
			{
				printf("|-----------------------------------|\n");
			}
		}
		printf("+-----------------------------------+\n");
		//edit
		worker.lastX = worker.x;
		worker.lastY  = worker.y;

		/*where is B*/
		struct position box[_size * _size];
		int boxCount = 0;

		for (int x = 0; x < _size; x++)
		{
			for (int y = 0; y < _size; y++)
			{
				if ((cell[x][y] == '$') || (cell[x][y] == 'S'))
				{
					box[boxCount].x = x;
					box[boxCount].y = y;
					boxCount++;
				}
			}
		}

		bool allBoxInsideGoal = 1;

		for (int i = 0; i < goalCount; i++)
		{
            if (cell[goal[i].x][goal[i].y] != 'S')
            {
                allBoxInsideGoal = 0;
            }
		}

		if (allBoxInsideGoal == 1)
		{
			printf(".\n");
			printf(".\n");
			printf(".\n");
			printf("You Win...!congrats.");
			printf(".\n");
			printf(".\n");
			break;
		}
		char key = getch();

        if(key == 'q'){
            break;
        }
		system("cls");


        struct position testWorker;

		switch (key)
		{
		case 'H':
			testWorker.y = worker.y + 1;
			testWorker.x = worker.x;
			break;
		case 'P':
			testWorker.y = worker.y - 1;
			testWorker.x = worker.x;
			break;
		case 'M':
			testWorker.x = worker.x + 1;
			testWorker.y = worker.y;
			break;
		case 'K':
			testWorker.x = worker.x - 1;
			testWorker.y = worker.y;
			break;
		}

		bool workerPushesBox = 0;

		struct position testBox;

		int boxNumber;

		for (int i = 0; i < boxCount; i++)
		{
			if ((testWorker.x == box[i].x) && (testWorker.y == box[i].y))
			{
				box[i].lastX = box[i].x;
				box[i].lastY = box[i].y;
				boxNumber = i;
				workerPushesBox = 1;
			}
		}

		if (workerPushesBox == 1)
		{
			switch (key)
			{
			case 'H':
				testBox.y = box[boxNumber].y + 1;
				testBox.x = box[boxNumber].x;
				break;
			case 'P':
				testBox.y = box[boxNumber].y - 1;
				testBox.x = box[boxNumber].x;
				break;
			case 'M':
				testBox.x = box[boxNumber].x + 1;
				testBox.y = box[boxNumber].y;
				break;
			case 'K':
				testBox.x = box[boxNumber].x - 1;
				testBox.y = box[boxNumber].y;
				break;
			}
		}

		bool workerHitsWall = 0;

		for (int i = 0; i < wallCount; i++)
		{
			if ((wall[i].x == testWorker.x) && (wall[i].y == testWorker.y))
			{
				workerHitsWall = 1;
			}
		}

		bool boxHitsWall = 0;

		for (int i = 0; i < wallCount; i++)
		{
			if ( ( wall[i].x == testBox.x && wall[i].y == testBox.y )
                && /* Worker is trying to push the box */
                ( testWorker.x == box[boxNumber].x && testWorker.y == box[boxNumber].y ) )
			{
				boxHitsWall = 1;
			}
		}

		bool boxHitsBox = 0;

		for (int i = 0; i < boxCount; i++)
		{
			if ( ( box[i].x == testBox.x && box[i].y == testBox.y )
                && /* Worker is trying to push the box */
                ((testWorker.x == box[boxNumber].x) && (testWorker.y == box[boxNumber].y)))
			{
				boxHitsBox = 1;
			}
		}

		if ( (workerHitsWall == 0) && (boxHitsWall == 0) && (boxHitsBox == 0 ) )
		{

			switch (key)
			{
			case 'H':
				worker.y += 1;
				break;
			case 'P':
				worker.y -= 1;
				break;
			case 'M':
				worker.x += 1;
				break;
			case 'K':
				worker.x -= 1;
				break;
			}

			cell[worker.x][worker.y] += 33;

			if ((worker.x == box[boxNumber].x) && (worker.y == box[boxNumber].y))
			{
				switch (key)
				{
				case 'H':
					box[boxNumber].y = box[boxNumber].y + 1;
					break;
				case 'P':
					box[boxNumber].y = box[boxNumber].y - 1;
					break;
				case 'M':
					box[boxNumber].x = box[boxNumber].x + 1;
					break;
				case 'K':
					box[boxNumber].x = box[boxNumber].x - 1;
					break;
				}
				cell[box[boxNumber].x][box[boxNumber].y] += 4;
				cell[box[boxNumber].lastX][box[boxNumber].lastY] -= 4;
			}
			cell[worker.lastX][worker.lastY] -= 33;
		}

		if (key == 'q')
		{
			gameOn = 0;
		}
	}
	return 0;
}
