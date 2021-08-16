#include "Implementation.h"
#include <algorithm>
#include <vector>
#include <iostream>

//21. 8.13 예제 4-1 상하좌우
void UpDownLeftRight()
{
	std::vector<char> plans;

	struct Pos
	{
		int x;
		int y;

		Pos& operator+= (const Pos& _other)
		{
			this->x += _other.x;
			this->y += _other.y;

			return *this;
		}
	};

	
	Pos currentPos = {1, 1};
	int N;
	char Dir;
	std::cin >> N;
	
	// 입력을 받는 동안
	while (std::cin >> Dir)
	{
		plans.push_back(Dir);
		if (std::cin.get() == '\n')
		{
			break;
		}

	}

	for (size_t i = 0; i < plans.size(); ++i)
	{
		Pos nextPos = currentPos;

		switch (plans[i])
		{
		case 'L':
			nextPos += {0, -1};
			break;

		case 'R':
			nextPos += {0, +1};
			break;

		case 'D':
			nextPos += {+1, 0};
			break;

		case 'U':
			nextPos += {-1, 0};;
			break;

		default:
			break;
		}

		if (nextPos.x <1 || nextPos.y < 1 || nextPos.x > N || nextPos.y > N)
		{
			continue;
		}

		else
		{
			currentPos = nextPos;
		}
	}

	std::cout << currentPos.x << " " << currentPos.y;
	
}

void Time()
{
	int N = 0;
	int Count = 0;

	// 시간을 입력받기
	std::cin >> N;


	for (int h = 0; h <= N; ++h)
	{
		for (int m = 0; m < 60; ++m)
		{
			for (int s = 0; s < 60; ++s)
			{
				if (h % 10 == 3 || m / 10 == 3 || m % 10 == 3 || s / 10 == 3 || s % 10 == 3)
				{
					++Count;
				}
			}
		}
	}
	
	std::cout << Count;
}

void RoyalNight()
{
	enum Pos {X, Y};

	int CurrentPos[2] = { 0, 0 };
	int Count = 0;

	char KnightPos[] = "a1";
	std::cin >> KnightPos;

	// 위치를 담기
	for (int i = 0; i < sizeof(KnightPos); ++i)
	{
		if (0 == KnightPos[i])
		{
			break;
		}

		CurrentPos[i] = KnightPos[i];
	}
	
	// 8가지 선택지 체크
	for (int i = 0; i < 8; ++i)
	{
		int NextPos[2] = { 0,0 };
		NextPos[X] = CurrentPos[X];
		NextPos[Y] = CurrentPos[Y];

		switch (i)
		{
		case 0:
			NextPos[X] += 2;
			NextPos[Y] += 1;
			break;
		case 1:
			NextPos[X] += 2;
			NextPos[Y] -= 1;
			break;

		case 2:
			NextPos[X] -= 2;
			NextPos[Y] += 1;
			break;

		case 3:
			NextPos[X] -= 2;
			NextPos[Y] += 1;
			break;

		case 4:
			NextPos[X] += 1;
			NextPos[Y] -= 2;
			break;

		case 5:
			NextPos[X] -= 1;
			NextPos[Y] -= 2;
			break;

		case 6:
			NextPos[X] += 1;
			NextPos[Y] += 2;
			break;

		case 7:
			NextPos[X] -= 1;
			NextPos[Y] += 2;
			break;

		}

		// 벽을 넘었다면 Count를 세지 않음
		if (NextPos[X] <'a' || NextPos[X] > 'h'||
			NextPos[Y] < '1' || NextPos[Y] > '8')
		{
			continue;
		}

		else
		{
			++Count;
		}
	}
	
	std::cout << Count;

}
