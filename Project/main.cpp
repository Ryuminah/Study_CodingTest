#include <crtdbg.h>
#include "GreedyAlgorithm.h"
#include "Implementation.h"
#include "DFS.h"
#include "BFS.h"
#include "Sorting.h"
#include "Queue.h"



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	std::vector<int> progress = { 95, 90, 99, 99, 80, 99 };
	std::vector<int> speed = { 1, 1, 1, 1, 1, 1 };

	std::vector<int> v = DevelopFeature(progress,speed);
	std::vector<int> v2 = DevelopFeature_2(progress, speed);

}