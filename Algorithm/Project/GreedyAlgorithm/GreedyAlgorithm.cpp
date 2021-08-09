#include "GreedyAlgorithm.h"
#include <vector>
#include <algorithm>

//21. 8.8 예제 1
void Change()
{
    int n = 0;
    int coinCount = 0;

    std::cin >> n;

    int coins[4] = { 500,100,50,10 };

    for (int i = 0; i < 4; ++i)
    {
        int coin = coins[i];
        coinCount += n / coin;
        n %= coin;
    }

    std::cout << coinCount;
}

//21.8.9 2번 큰 수의 법칙
void RulesOfBigNumber1()
{
    int N = 0;
    int M = 0;
    int K = 0;
    int Result = 0;

    std::cin >> N;
    std::cin >> M;
    std::cin >> K;

    // 입력값 만큼 배열의 크기를 
    std::vector<int> arr;
    arr.reserve(N);
    
    for (int i = 0; i < N; ++i)
    {
        int input = 0;
        std::cin >> input;
        arr.push_back(input);
    }
    
    // 숫자가 더해지는 횟수만큼 반복문 실행
    int CountCheck = K;

    for (int i = 0; i < M; ++i)
    {
        // 가장 큰 두 숫자를 담아놓을 변수
        int firstBigNum = 0;
        int secondBigNum = 0;

        // 가장 큰 두 수를 고르는 로직
        for (int j = 0; j < N; ++j)
        {
            // 배열의 현재 인덱스가 저장되어있는 값보다 크다면
            if (arr[j] >= firstBigNum)
            {
                // 그 값을 저장.
                secondBigNum = arr[j];

                // 만약 현재 최댓값보다 더 크다면,
                if (secondBigNum >= firstBigNum)
                {
                    // 가장 큰 값을 교체해준다.
                    secondBigNum = firstBigNum;
                    firstBigNum = arr[j];
                }
            }
        }
        
        // 반복할 수 있는 숫자의 횟수가 끝나면 차선을 고름
        if (CountCheck == 0)
        {
            Result += secondBigNum;
            CountCheck = 3;
        }

        else
        {
            Result += firstBigNum;
            --CountCheck;
        }
    }

    std::cout << Result;
}

// 같은 문제를 수열을 이용하여 풀이
void RulesOfBigNumber2()
{
    // 아직 정리 안함^^//
}
