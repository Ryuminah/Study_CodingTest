#pragma once
#include "STLheader.h"

// 선택 정렬
void SelectionSort();

// 삽입 정렬
void InsertionSort();

// 퀵 정렬
void QuickSort(int* arrData, int startIndex, int endIndex);

// 계수 정렬
void CountSort(int* arrData, int arrSize, int minValue, int maxValue);


////////////////////////////////////// 문제 //////////////////////////////////////
// 실전문제 2번 위에서 아래로
void UpToDown();

// 실전문제 3번 위에서 아래로
void PrintStudent();

// 백준 2309번 일곱난쟁이
void SevenDwarfs();

// 프로그래머스 최솟값 만들기
int MakeMinimumValue(std::vector<int> A, std::vector<int> B);