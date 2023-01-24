#include "etc.h"

int Camouflage(vector<vector<string>> clothes)
{
    unordered_map<string, int> clothesMap;
    int answer = 1;

    for (auto& clothInfo : clothes)
    {
        ++clothesMap[clothInfo[1]];
    }

    for (auto& iter : clothesMap)
    {
        answer *= (iter.second + 1);
    }

    return --answer;
}

string answer;
char quad[65][65] = {' '};
void Quad(int x, int y, int size)
{
    bool canZip = true;
    // 압축이 가능한 경우
    for (int i = y; i < y + size; ++i)
    {
        for (int j = x; j < x + size; ++j)
        {
            // 이미 압축이 된 경우 종료
            if (quad[y][x] != quad[i][j])
            {
                canZip = false;
                break;
            }
        }
    }
    
    if (!canZip)
    {
        int half = size / 2;
        answer += '(';
        Quad(x, y, half);   //왼쪽 위
        Quad(x + half, y, half);    //오른쪽 위
        Quad(x, y + half, half);    // 왼쪽 아래
        Quad(x + half, y + half, half);
        answer += ')';
    }
    else
        answer += quad[y][x];
}

void QuadTree()
{
    string input;
    int N;
    cin >> N;
    
    for (int i = 0; i < N; ++i)
    {
        cin >> input;
        for (int j = 0; j < N; ++j)
        {
            quad[i][j] = input[j];
        }
    }

    Quad(0, 0, N);

    cout << answer << endl;

}
