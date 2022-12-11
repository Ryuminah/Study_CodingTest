#pragma once
#include <vector>

// Depth First Search

//21. 8.22 DFS example
void DFS();

//21.8.25 실전 3 음료수 얼려먹기
bool CheckIceBox(int _x, int _y, int _n, int _m, int _Graph[][1000]);		// DFS
void FreezingDrinks();

// 22.11.6 프로그래머스 네트워크
void CheckNetwork(bool* visited,int currentDepth, std::vector<std::vector<int>>& computers);
int Network(int n, std::vector<std::vector<int>> computers);

// 22.12.8 프로그래머스 타겟넘버
void CalculateNumber(std::vector<int> numbers, int target, int index, int totalSum, int& answer);
int TargetNumber(std::vector<int> numbers, int target);

//22.12.10 백준 10026번 적록색약
void MakeArea(std::vector<std::vector<char>>& grid, int indexX, int indexY, char color, bool isRedGreen = false);
void RedGreenColorWeakness();

void MakeArea2(std::vector<std::vector<char>>& grid, int indexX, int indexY);
void RedGreenColorWeakness2();

//22.12.11 게임 맵 최단거리
int ShortestDistanceInGameMap(std::vector<std::vector<int>> maps);