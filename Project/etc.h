#pragma once
#include "STLHeader.h"
using namespace std;

// 22.12.21 프로그래머스 : 최댓값과 최솟값
string MaxMin(string s);

bool CheckLine(bool* arr, int findCount, string currentWord);
vector<string> CardGame(vector<string> card, vector<string> word);


#pragma region 문자열
// 23.1.8 프로그래머스 : A로 B만들기
int MakeBtoA(string before, string after);

// 23.1.9 프로그래머스 : 모스부호(1)
string MorseSign(string letter);
#pragma endregion

