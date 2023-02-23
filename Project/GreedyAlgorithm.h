#pragma once
#include <iostream>
#include "STLHeader.h"
using namespace std;
//21. 8.8 예제 1
void Change();

//21.8.9 2번 큰 수의 법칙
void RulesOfBigNumber1();
void RulesOfBigNumber2();

//21.8.10 3번 숫자 카드 게임
void NumberCardGame1();
void NumberCardGame2();

//21.8.11 4번 1이 될때까지
void MakeOne();

//21.8.12 백준 4796번 캠핑
void Camping();

//22.7.22 백준 11399번 ATM
void ATM();

// 프로그래머스 큰 수 만들기
std::string MakeBigNumber(std::string number, int k);

// 프로그래머스 조이스틱
int JoyStick(std::string name);

// 프로그래머스 체육복
int SweatSuit(int n, vector<int> lost, vector<int> reserve);

// 22.12.21 프로그래머스 단속 카메라
bool Compare(vector<int>& a, vector<int>& b);
int SpeedCamera(vector<vector<int>> routes);

// 22.12.22 프로그래머스 섬 연결하기
bool Comp(vector<int>& a, vector<int>& b);
int FindParent(int index);
int LinkIsland(int n,vector<vector<int>> costs);

// 22.12.26 백준 1541번 잃어버린 괄호
void MissingParentheses();

// 22.12.30 백준 2212번 센서
void Sensor();
void Sensor1();

// 23.2.12 프로그래머스 : 기지국 설치
int InstallBaseStation(int n, vector<int> stations, int w);