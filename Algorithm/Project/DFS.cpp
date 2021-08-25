#include "DFS.h"
#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <iostream>

void DFS()
{
	// 인접 List 방식을 사용한 구현.

	//1. Graph 제작
	struct Node
	{
		int value;
		std::vector<Node*> link;
		bool check;
	};

	std::vector<Node*> Graph;
	std::stack<Node*> Visit;

	for (int i = 0; i < 8; ++i)
	{
		Node* pNode = new Node;
		pNode->value = i;
		pNode->check = false;
		Graph.push_back(pNode);
	}

	//0번 노드
	Graph[0]->link.push_back(Graph[1]);

	//1번 노드
	Graph[1]->link.push_back(Graph[0]);
	Graph[1]->link.push_back(Graph[2]);

	//2번 노드
	Graph[2]->link.push_back(Graph[1]);
	Graph[2]->link.push_back(Graph[3]);
	Graph[2]->link.push_back(Graph[4]);

	//3번 노드
	Graph[3]->link.push_back(Graph[2]);

	//4번 노드
	Graph[4]->link.push_back(Graph[2]);
	Graph[4]->link.push_back(Graph[5]);
	Graph[4]->link.push_back(Graph[6]);
	Graph[4]->link.push_back(Graph[7]);

	//5번 노드
	Graph[5]->link.push_back(Graph[4]);

	//6번 노드
	Graph[6]->link.push_back(Graph[4]);

	//7번 노드
	Graph[7]->link.push_back(Graph[4]);


	//2. DFS
	int i = 4;
	while (true)
	{
		// 한번도 방문하지 않은 노드일 경우
		if (!Graph[i]->check)
		{
			// 방문 처리
			Graph[i]->check = true;
			Visit.push(Graph[i]);
			std::cout << i << "->";
		}


		// 방문 했던 노드라면
		else
		{
			// 방문하지 않은 연결된 노드가 있는지 체크.
			for (size_t j = 0; j < Graph[i]->link.size(); ++j)
			{
				// 연결된 노드가 방문된 적 없는 노드라면
				if (!Graph[i]->link[j]->check)
				{
					// 다음 방문할 노드 번호로 정해준다.
					i = Graph[i]->link[j]->value;
					break;
				}
			}

			// 방문하지 않은 연결 노드가 없다면
			// 스택에서 꺼낸 후 다음 최상단 노드를 다음 탐색할 노드로 설정해준다.
			if (Graph[i] == Visit.top())
			{
				Visit.pop();

				if (0 != Visit.size())
				{
					i = Visit.top()->value;

				}

				else
				{
					std::cout <<'\n';
					break;
				}
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
}

void FreezingDrinks()
{
	enum Position {X,Y};
	enum Direction { R, L, U, D};

	struct Ice
	{
		bool m_Check = false;
		int m_Ice;
		int pos[2];
	};

	int N, M;
	int result = 0;
	std::cin >> N >> M;
	std::cin.ignore();

	std::vector<Ice*> IceBox;

	// 맵 채우기
	for (int y = 0; y < M; ++y)
	{
		for (int x = 0; x  < N; ++x)
		{
			Ice* pIce = new Ice;
			pIce->pos[X] = x;
			pIce->pos[Y] = y;
			pIce->m_Ice = (int)std::cin.get() - '0';

			IceBox.push_back(pIce);
			
		}
			std::cin.ignore();
	}

	// Logic
	for (size_t i = 0; i < IceBox.size(); ++i)
	{
		Ice* CheckIce;

		// 아직 탐색하지 않은 얼음의 상하좌우를 탐색.
		if (0 == IceBox[i]->m_Ice && !IceBox[i]->m_Check)
		{
			CheckIce = IceBox[i];
			CheckIce->m_Check = true;

			// 얼음 모양 구하는 로직
			while (true)
			{
				int block = 0;

				// 네 방향을 체크
				for (int dir = 0; dir < 4; ++dir)
				{
					// 다음 조사할 위치를 정함
					int nextPos[2] = { CheckIce->pos[X], CheckIce->pos[Y] };
					switch (dir)
					{
					case R:
						nextPos[X] += 1;
						break;
					case L:
						nextPos[X] -= 1;
						break;
					case U:
						nextPos[Y] -= 1;
						break;
					case D:
						nextPos[Y] += 1;
						break;
					}

					// 얼음틀의 위치에서 벗어났을 경우
					if (nextPos[X] < 0 || nextPos[X] >= N || nextPos[Y] < 0 || nextPos[Y] >= N)
					{
						++block;
						continue;
					}

					// 존재하는 얼음일 경우
					else
					{
						// 컨테이너 안에서 얼음 찾기
						for (size_t k = 0; k < IceBox.size(); ++k)
						{
							// 얼음을 찾았다면
							if (IceBox[k]->pos[X] == nextPos[X] && IceBox[k]->pos[Y] == nextPos[Y])
							{
								// 막혀야 하는 곳인지 확인
								if (!IceBox[k]->m_Check && IceBox[k]->m_Ice == 0)
								{
									// 해당 얼음을 방문한 곳으로 바꿔주고 다음 탐색할 얼음으로 설정
									CheckIce = IceBox[k];
									CheckIce->m_Check = true;
									dir = -1;
								}

								// 이미 방문한 얼음이라면 못가는 곳으로 표시
								else
								{
									++block;
								}

								break;
							}
						}
					}
				}

				// 사방이 조사할 수 없는 곳이라면 얼음 생성 끝
				if (block == 4)
				{
					++result;
					break;
				}
			}
		}

		// 얼음이 아니거나 탐색을 이미 했다면.
		else
		{
			continue;
		}

		// 방문할 곳이 없으면 다시 이전으로 돌아가서 탐색하는 로직이 엄슴 , ,, 
	}

	std::cout << result;

	std::vector<Ice*>::iterator iter = IceBox.begin();
	std::vector<Ice*>::iterator iterEnd = IceBox.end();

	// 메모리 해제
	for (; iter != iterEnd; ++iter)
	{
		delete (*iter);
	}


	int a = 0;
}

