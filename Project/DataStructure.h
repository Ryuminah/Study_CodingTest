#pragma once
#include "STLHeader.h"

#pragma region  Stack/Queue
// 22.1.3 화 백준 1655번 가운데를 말해요
void TalkMiddle();

vector<int> DoublePriorityQueue(vector<string> operations);
vector<int> DoublePriorityQueue2(vector<string> operations);

#pragma endregion

#pragma region Hash
bool Compare(pair<int, int>& a, pair<int, int>& b);
vector<int> BestAlbum(vector<string> genres, vector<int> plays);

// 프로그래머스 : 불량 사용자
bool CheckIdMatch(string a, string b);
int BannedUser(vector<string> user_id, vector<string> banned_id);
#pragma endregion


