#include <crtdbg.h>
#include "GreedyAlgorithm.h"
#include "Implementation.h"
#include "DFS.h"
#include "BFS.h"
#include "Sorting.h"
#include "Queue.h"
#include "DynamicPrograming.h"

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	vector<vector<int>> board; 

	board.resize(2);
	board[0].push_back(0);
	board[0].push_back(0);
	board[0].push_back(1);
	board[0].push_back(1);

	board[1].push_back(1);
	board[1].push_back(1);
	board[1].push_back(1);
	board[1].push_back(1);

	BiggestSquare(board);
}