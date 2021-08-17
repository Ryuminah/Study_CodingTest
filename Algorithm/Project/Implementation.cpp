#include "Implementation.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>

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

void GameDevelopment()
{
	enum Direction {NORTH, EAST, SOUTH, WEST};
	enum Pos { X, Y, Dir };

	int N = 0;		// 세로
	int M = 0;		// 가로
	

	// 맵의 크기 입력
	std::cin >> N >> M;

	// X, Y, 방향
	int player[3] = { 1,1,NORTH };

	// 캐릭터의 위치
	std::cout << '1' << ' ' << '1' << ' ' << '0' << std::endl;
	std::vector<char> Width;
	std::vector<std::vector<char>> Map(M, std::vector<char>(N, '1'));

	Map[1][1] = '0';
	Map[1][2] = '0';
	Map[2][2] = '0';

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			std::cout << Map[i][j] << ' ';
		}
		std::cout << '\n';
	}


	int canMoveCheck = 0;
	int Count = 1;

	while (true)
	{
		// 현재 좌표는 이미 가본 곳
		Map[1][1] = '1';

		// 값 복사
		int playerNextPos[3];

		for (int i = 0; i < 3; ++i)
		{
			playerNextPos[i] = player[i];

		}

		if (player[Dir] == WEST)
		{
			player[Dir] = NORTH;
		}

		// 1단계 수행 (방향 변경)
		++player[Dir];

		// 2단계 수행 (방향에 따른 인덱스 확인)
		switch (player[Dir])
		{
			
		case NORTH:
			playerNextPos[Y] -= 1;
			playerNextPos[Dir] = NORTH;
			break;
		case EAST:
			playerNextPos[X] += 1;
			playerNextPos[Dir] = EAST;
			break;

		case SOUTH:
			playerNextPos[Y] += 1;
			playerNextPos[Dir] = SOUTH;
			break;

		case WEST:
			playerNextPos[X] -= 1;
			playerNextPos[Dir] = WEST;
			break;

		default:
			break;
		}

		// 다음 방향이 갈 수 있는 곳이라면
		if (Map[playerNextPos[X]][playerNextPos[Y]] == '0')
		{
			// 갔다고 표시
			Map[playerNextPos[X]][playerNextPos[Y]] = '1';
			canMoveCheck = 0;
		}

		// 갈 수 없는 곳이라면
		else
		{
			// 왼쪽 방향이 이미 가본 칸이라면 회전만 수행
			++canMoveCheck;
			player[Dir] = playerNextPos[Dir];

			// 네 방향 다 막힌 상황일 경우 뒤쪽으로 이동
			if (canMoveCheck == 4)
			{
				switch (player[Dir])
				{

				case NORTH:
					playerNextPos[Y] += 1;
					break;
				case EAST:
					playerNextPos[X] -= 1;
					break;

				case SOUTH:
					playerNextPos[Y] -= 1;
					break;

				case WEST:
					playerNextPos[X] += 1;
					break;

				default:
					break;
				}

				// 이때 이동해야할 곳이 바다일 경우
				if (Map[playerNextPos[X]][playerNextPos[Y]] == '1')
				{
					break;
				}
			}

			// 모두 막힌 경우가 아니라면 회전만 수행
			else
			{
				continue;
			}
		}

		// 이동
		player[X] = playerNextPos[X];
		player[Y] = playerNextPos[Y];
		player[Dir] = playerNextPos[Dir];
		++Count;

	}

	std::cout << Count;
}
