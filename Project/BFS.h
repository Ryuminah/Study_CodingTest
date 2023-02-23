#pragma once
#include "STLHeader.h"
using namespace std;

// 21. 8.24 BFS example
void BFS();

// 21.8.31 실전 4번 미로 탈출
void EscapeTheMaze();

// 21.12.3 14248번 점프 점프
void JumpJump();

// 22.12.14 프로그래머스 게임 맵 최단거리;
int ShortestDistanceInGameMap(vector<vector<int> > maps);

// 22.12.17 프로그래머스 단어 변환
bool CanChange(string src, string dest);
int ChangeWords(string begin, string target, vector<string> words);

// 22.12.27 백준 14502번 연구소
struct Pos
{
	int x, y;

	Pos() : x(0),y(0) {}
	Pos(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
};

// 배열은 선언만 값형으로 할 뿐, 참조형으로 전달된다.
void Virus(int mapCopy[][8]);
void MakeWall(int count);

void Virus();
void Laboratory();

// 23.1.26 백준 2993번 : 미네랄
void Mineral();
void CheckCluster(Pos pos);
