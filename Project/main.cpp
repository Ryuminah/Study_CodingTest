#include <crtdbg.h>
#include "GreedyAlgorithm.h"
#include "Implementation.h"
#include "DFS.h"
#include "BFS.h"
#include "Sorting.h"



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	std::string s = "{{2},{2,1},{2,1,3},{2,1,3,4}}";

	std::vector<int> v = Tuple(s);

	for (int i = 0; i < v.size(); ++i)
	{
		std::cout << v[i] << ' ';
	}
}