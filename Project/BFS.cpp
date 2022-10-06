#include "BFS.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <list>
#include <queue>

void BFS()
{
	//1. Graph 제작
	struct Node
	{
		int value;
		std::vector<Node*> link;
		bool check;
	};

	std::vector<Node*> Graph;
	std::queue<Node*> Visit;

	for (int i = 0; i < 8; ++i)
	{
		Node* pNode = new Node;
		pNode->value = i;
		pNode->check = false;
		Graph.push_back(pNode);
	}

	//0번 노드
	Graph[0]->link.push_back(Graph[1]);
	Graph[0]->link.push_back(Graph[2]);
	Graph[0]->link.push_back(Graph[7]);


	//1번 노드
	Graph[1]->link.push_back(Graph[0]);
	Graph[1]->link.push_back(Graph[6]);

	//2번 노드
	Graph[2]->link.push_back(Graph[0]);
	Graph[2]->link.push_back(Graph[3]);
	Graph[2]->link.push_back(Graph[4]);

	//3번 노드
	Graph[3]->link.push_back(Graph[2]);
	Graph[3]->link.push_back(Graph[4]);

	//4번 노드
	Graph[4]->link.push_back(Graph[2]);
	Graph[4]->link.push_back(Graph[3]);

	//5번 노드
	Graph[5]->link.push_back(Graph[6]);

	//6번 노드
	Graph[6]->link.push_back(Graph[1]);
	Graph[6]->link.push_back(Graph[5]);
	Graph[6]->link.push_back(Graph[7]);

	//7번 노드
	Graph[7]->link.push_back(Graph[0]);
	Graph[7]->link.push_back(Graph[6]);

	// BFS 구현 (거리가 가장 가까운 순으로 탐색)

	int i = 0;
	while (true)
	{
		// 한번도 방문하지 않은 노드일 경우
		if (!Graph[i]->check)
		{
			// 방문 처리
			Visit.push(Graph[i]);
			Graph[i]->check = true;
			std::cout << i << "->";
		}


		// 방문 했던 노드라면
		else
		{
			// 가장 처음에 있던 노드를 꺼낸 후
			Node& pNode = *Visit.front();
			Visit.pop();

			// 인접 노드 중 방문하지 않은 노드를 모두 큐에 삽입한 후 방문처리함.
			for (size_t j = 0; j < pNode.link.size(); ++j)
			{
				// 현재 체크하고 있는 연결된 노드가 방문한 적 없는 노드라면
				if (!pNode.link[j]->check)
				{
					// Queue에 Push 후 방문 처리함.
					Visit.push(pNode.link[j]);
					pNode.link[j]->check= true;
					std::cout << pNode.link[j]->value << "->";
				}
			}

			// Queue의 가장 처음 노드를 다음 탐색할 노드로 바꿔줌.
			if (!Visit.empty())
			{
				i = Visit.front()->value;
			}

			else
			{
				break;
			}
		}

		
	}

	std::vector<Node*>::iterator iter = Graph.begin();
	std::vector<Node*>::iterator iterEnd = Graph.end();

	// 메모리 해제
	for (; iter != iterEnd; ++iter)
	{
		delete (*iter);
	}

	// 벡터에 할당된 메모리 삭제

	Graph.clear();
	std::cout << '\n';

}

void EscapeTheMaze()
{
	enum Pos {X,Y};
	enum Direction {DOWN,UP,RIGHT,LEFT};
	int N, M;
	int result = 0;
	std::cin >> N >> M;

	int Maze[201][201];
	std::queue<std::pair<int, int>> Check;


	for (int y = 0; y < M; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			Maze[x][y] = (int)std::cin.get() - '0';
			Check.push({x,y});
		}
		std::cin.ignore();
	}

	int DirX[4] = { 0,0,1,-1 };
	int DirY[4] = { 1,-1,0,0 };

	// Queue가 빌 동안
	while (!Check.empty())
	{
		// 방문
		int currentPos[2] = { Check.front().first , Check.front().second};
		Check.pop();
		
		// 4방향을 탐색
		for (int i = 0; i < 4; ++i)
		{
			int checkPos[2] = { currentPos[X] + DirX[i],currentPos[Y] + DirX[i] };

			// 체크해야 할 위치가 벽을 넘어갔을 경우 무시
			if (checkPos[X] <0 || checkPos[X] >= N ||
				checkPos[Y] < 0 || checkPos[Y] >= M)
			{
				continue;
			}

			// 벽일 경우 무시
			if (Maze[checkPos[X]][checkPos[Y]] == 0)
			{
				continue;
			}

			// 해당 노드가 처음 방문하는 노드일 경우만 최단거리로 저장
			if (Maze[checkPos[X]][checkPos[Y]] == 1)
			{
				Maze[checkPos[X]][checkPos[Y]] = Maze[currentPos[X]][currentPos[Y]] + 1;
				Check.push({ checkPos[X] , checkPos[Y] });
				++result;
			}
		}
	}
	
	std::cout << result;
}


void JumpJump()
{
	struct CStone
	{
		bool bCanVisit;
		int Number;
	};

	std::vector<CStone> vecStoneBridge;

	// 돌다리의 갯수
	int StoneCount = 0;
	std::cin >> StoneCount;

	// 돌다리의 갯수만큼 돌 생성.
	for (int i = 0; i < StoneCount; ++i)
	{
		CStone stone;
		stone.bCanVisit = false;
		std::cin >> stone.Number;
		vecStoneBridge.push_back(stone);
	}

	// 시작점 입력받기.
	int StartPoint = 0;
	std::cin >> StartPoint;

	// 현재 위치 
	StartPoint -= 1;		// 인덱스를 맞추기 위함
	int Result = 0;

	std::queue<int> q;
	vecStoneBridge[StartPoint].bCanVisit = true;
	q.push(StartPoint);
	++Result;

	// 돌 건너기
	while (!q.empty())
	{
		// 다음 이동할 위치(양의 방향부터 탐색)
		int currentIndex = q.front();
		int distance = vecStoneBridge[currentIndex].Number;
		q.pop();

		for (int i = 0; i < 2; ++i)
		{
			distance *= -1;
			int nextIndex = currentIndex + distance;

			// 아직 방문하지 않은 곳이고 범위 내에 존재하는 곳이라면
			if (-1 < nextIndex && nextIndex < StoneCount && !vecStoneBridge[nextIndex].bCanVisit)
			{
				vecStoneBridge[nextIndex].bCanVisit = true;
				q.push(nextIndex);
				++Result;
			}
		}

	
	}

	std::cout << Result << std::endl;
}
