#include "Sorting.h"
#include <vector>
#include <iostream>

void SelectionSort()
{
	std::vector<int> arr{ 7,5,9,0,3,1,6,2,4,8 };

	int arrSize = (int)arr.size();				// 배열의 총 사이즈
	int minIndex = 0;							// 가장 작은 값을 가지고 있는 인덱스
	
	std::cout << "정렬 전 : ";

	for (int i = 0; i < arrSize; ++i)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << '\n';

	// 배열 탐색
	for (int frontIndex = 0; frontIndex < arrSize; ++frontIndex)
	{
		minIndex = frontIndex;

		// 현재 제일 작은 인덱스의 값보다 더 작은 값을 발견하면 교체
		for (int compareIndex = frontIndex + 1; compareIndex < arrSize; compareIndex++)
		{
			if (arr[minIndex] > arr[compareIndex])
				minIndex = compareIndex;
		}
		
		// 값 순서 변경
		int smallestValue = arr[minIndex];		
		arr[minIndex] = arr[frontIndex];
		arr[frontIndex] = smallestValue;
	}

	std::cout << "정렬 후 : ";

	for (int i = 0; i < arrSize; ++i)
	{
		std::cout  << arr[i] << " " ;
	}
}
