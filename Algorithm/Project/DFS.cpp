#include "DFS.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <list>
#include <stack>

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
		pNode->value = i + 1;
		pNode->check = false;
		Graph.push_back(pNode);
	}

	//1번 노드
	Graph[0]->link.push_back(Graph[1]);
	Graph[0]->link.push_back(Graph[2]);
	Graph[0]->link.push_back(Graph[7]);

	//2번 노드
	Graph[1]->link.push_back(Graph[0]);
	Graph[1]->link.push_back(Graph[6]);

	//3번 노드
	Graph[2]->link.push_back(Graph[0]);
	Graph[2]->link.push_back(Graph[3]);
	Graph[2]->link.push_back(Graph[4]);

	//4번 노드
	Graph[3]->link.push_back(Graph[2]);
	Graph[3]->link.push_back(Graph[4]);

	//5번 노드
	Graph[4]->link.push_back(Graph[2]);
	Graph[4]->link.push_back(Graph[3]);

	//6번 노드
	Graph[5]->link.push_back(Graph[6]);

	//7번 노드
	Graph[6]->link.push_back(Graph[1]);
	Graph[6]->link.push_back(Graph[5]);
	Graph[6]->link.push_back(Graph[7]);

	//8번 노드
	Graph[7]->link.push_back(Graph[0]);
	Graph[7]->link.push_back(Graph[6]);


	//2. DFS
	int i = 0;
	while (true)
	{
		// 한번도 방문하지 않은 노드일 경우
		if (!Graph[i]->check)
		{
			// 방문 처리
			Graph[i]->check = true;
			Visit.push(Graph[i]);
			std::cout << i + 1 << "->";
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
					i = Graph[i]->link[j]->value - 1;
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
					i = Visit.top()->value - 1;

				}

				else
				{
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

