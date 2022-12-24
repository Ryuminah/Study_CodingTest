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
