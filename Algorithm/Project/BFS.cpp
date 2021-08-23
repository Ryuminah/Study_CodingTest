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
					std::cout << j << "->";
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
