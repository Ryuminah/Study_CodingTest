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

void InsertionSort()
{
	int arr[10] = { 7,5,9,0,3,1,6,2,4,8 };

	int arrSize = 10;				// 배열의 총 사이즈
	int minIndex = 0;				// 가장 작은 값을 가지고 있는 인덱스

	std::cout << "정렬 전 : ";

	for (int i = 0; i < arrSize; ++i)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << '\n';

	// 삽입 정렬은 두번째 인덱스 부터 시작함 (첫번째 데이터는 그 자체로 정렬되어 있다고 판단하기 때문) 
	for (int currentIndex = 1; currentIndex < arrSize; ++currentIndex)
	{
		// 현재 인덱스의 값
		int currentValue = arr[currentIndex];

		// 자신보다 작은 인덱스를 순회하며 현재 데이터의 자리를 찾는다.
		for (int compareIndex = currentIndex-1 ; compareIndex >= 0; --compareIndex)
		{
			int compareValue = arr[compareIndex];

			// currentValue가 비교할 값보다 더 작다면 위치를 옮긴다
			if (currentValue < compareValue)
			{
				arr[compareIndex + 1] = compareValue;
				arr[compareIndex] = currentValue;
			}
			
			// currentValue가 더 크다면 그대로 멈춘다.
			else
			{
				break;
			}

		}
	}

	std::cout << "정렬 후 : ";


	for (int i = 0; i < arrSize; ++i)
	{
		std::cout << arr[i] << " ";
	}
}

void QuickSort(int* arrData, int startIndex, int endIndex)
{
	if (startIndex >= endIndex)
	{
		return;
	}


	// 피봇을 지정
	int pivotValue = arrData[startIndex];
	int leftIndex = startIndex+1;
	int rightIndex = endIndex;
	
	// 왼쪽에부터 피봇보다 큰 데이터를 고르고, 오른쪽에서부터 피봇보다 작은 데이터를 선택한다.

	while (leftIndex <= rightIndex)
	{
		while (leftIndex <= endIndex && (arrData[leftIndex] <= pivotValue))
		{
			++leftIndex;
		}

		while (rightIndex > startIndex && (arrData[rightIndex] >= pivotValue))
		{
			--rightIndex;

		}

		int leftValue = arrData[leftIndex];
		int rightValue = arrData[rightIndex];

		// 인덱스가 엇갈렸을 경우 작은쪽의 데이터를 pivot으로 바꿔준다
		if (leftIndex > rightIndex)
		{
			arrData[startIndex] = rightValue;
			arrData[rightIndex] = pivotValue;
		}

		else
		{
			arrData[leftIndex] = rightValue;
			arrData[rightIndex] = leftValue;
		}
	}

	// 위의 정렬 과정을 좌, 우로 나눠서 반복한다.

	QuickSort(arrData, startIndex, rightIndex -1);
	QuickSort(arrData, leftIndex+1, endIndex);

}

void CountSort(int* arrData, int arrSize, int minValue, int maxValue)
{
	int sortSize = (maxValue - minValue) + 1;
	int* arrSort = new int[sortSize]{ 0 };

	for (int i = 0; i < arrSize; ++i)
	{
		int currentValue = arrData[i];
		++arrSort[currentValue];
	}

	std::cout << "정렬 후 : ";

	for (int i = 0; i < sortSize; ++i)
	{
		int valueCount = arrSort[i];
		
		if (valueCount == 0)
		{
			continue;
		}

		else
		{
			while (valueCount > 0)
			{
				std::cout << i << " ";
				--valueCount;
			}
		}
	}
	
	delete[] arrSort;
}


void CountSort()
{
	int arr[] = { 7,5,9,0,3,1,6,2,9,1,4, 8,0,5,2 };

	int arrSize = 10;				// 배열의 총 사이즈
	int minIndex = 0;				// 가장 작은 값을 가지고 있는 인덱스

	std::cout << "정렬 전 : ";

	for (int i = 0; i < arrSize; ++i)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << '\n';
}


int HIndex(vector<int> citations)
{
	int answer = 0;

	sort(citations.begin(), citations.end(), greater<int>());

	for (int i = 0; i < citations.size(); ++i)
	{
		if (citations[i] > i)
			++answer;
		else
			break;
	}

	return answer;
}


long long WorkOverTime(int n, vector<int> works)
{
	long long answer = 0;
	priority_queue<int> q;

	int totalTime = 0;
	for (int i = 0; i < works.size(); ++i)
	{
		totalTime += works[i];
		q.push(works[i]);
	}

	if (totalTime <= n)
	{
		return 0;
	}

	while (n != 0)
	{
		int maxTime = q.top();
		q.pop();

		if (maxTime != 0) --maxTime;

		q.push(maxTime);
		--n;
	}

	while (!q.empty())
	{
		answer += q.top() * q.top();
		q.pop();
	}

	return answer;
}

int NumberGame(vector<int> A, vector<int> B)
{
	int answer = 0;
	priority_queue<int> aQ;
	priority_queue<int> bQ;

	for (int i = 0; i < A.size(); ++i)
	{
		aQ.push(A[i]);
		bQ.push(B[i]);
	}

	while (!aQ.empty())
	{
		int aNumber = aQ.top();
		aQ.pop();

		int bNumber = bQ.top();

		if (bNumber > aNumber)
		{
			++answer;
			bQ.pop();
		}
	}

	return answer;
}

