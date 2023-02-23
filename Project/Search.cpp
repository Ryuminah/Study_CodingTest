#include "Search.h"

int BinarySearch(vector<int> data, int dest)
{
	int answer = -1;

	int start = 0;
	int end = data.size()-1;
	int pivot = 0;

	// start가 end보다 커지면 탐색 마무리
	while (start <= end)
	{
		pivot = (start + end) / 2;

		if (data[pivot] == dest)
		{
			answer = pivot;
			break;
		}
		
		// pivot > dest인 경우 큰 값은 볼 필요가 없음
		else if(data[pivot] > dest)
		{
			end = pivot - 1;
		}

		// pivot < dest인 경우 작은 값은 볼 필요가 없음
		else
		{
			start = pivot + 1;
		}
	}

	return answer;
}
 