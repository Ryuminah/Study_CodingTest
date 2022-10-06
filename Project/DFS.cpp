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

bool CheckIceBox(int _x, int _y, int _n, int _m, int _Graph[][1000])
{
	if (_x <= -1 || _x >= _n || _y <= -1 || _y >= _m)
	{
		return false;
	}
	// 현재 노드를 아직 방문하지 않았다면
	if (_Graph[_x][_y] == 0)
	{
		// 해당 노드 방문 처리
		_Graph[_x][_y] = 1;

		// 상, 하, 좌, 우의 위치들도 모두 재귀적으로 호출
		CheckIceBox(_x - 1, _y,_n,_m, _Graph);
		CheckIceBox(_x, _y - 1,_n,_m,_Graph);
		CheckIceBox(_x + 1, _y, _n, _m, _Graph);
		CheckIceBox(_x, _y + 1, _n, _m, _Graph);
		return true;
	}
	return false;
}

void FreezingDrinks()
{
	int N, M;
	int Graph[1000][1000];
	std::cin >> N >> M;

	// 2차원 리스트의 맵 정보 입력 받기
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf_s("%1d", &Graph[i][j]);
		}
	}

	// 모든 노드(위치)에 대하여 음료수 채우기
	int result = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++) 
		{
			// 현재 위치에서 DFS 수행
			if (CheckIceBox(i, j, N,M, Graph)) {
				result += 1;
			}
		}
	}
	std::cout << result << '\n'; // 정답 출력 
}

