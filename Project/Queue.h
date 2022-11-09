#pragma once
#include "STLheader.h"

// 22.11.10 프로그래머스 기능개발
std::vector<int> DevelopFeature(std::vector<int> progresses, std::vector<int> speeds);
void CheckProgress(int& loopCount, int& endCount, int day, std::queue<int>& q);

std::vector<int> DevelopFeature_2(std::vector<int> progresses, std::vector<int> speeds);
void Work(int& loopCount, int& endCount, int day, std::queue<int>& q);
