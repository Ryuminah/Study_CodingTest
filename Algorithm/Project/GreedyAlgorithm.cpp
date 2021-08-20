#include "GreedyAlgorithm.h"
#include <algorithm>
#include <vector>

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

void RulesOfBigNumber2()    // 수열을 이용한 풀이 방식
{
    int N = 0;
    int M = 0;
    int K = 0;
    int Result = 0;

    std::cin >> N;
    std::cin >> M;
    std::cin >> K;

    // 입력값 만큼 배열의 크기를 예약
    std::vector<int> arr;
    arr.reserve(N);

    for (int i = 0; i < N; ++i)
    {
        int input = 0;
        std::cin >> input;
        arr.push_back(input);
    }

    // stl을 이용한 정렬
    std::sort(arr.begin(), arr.end(), std::greater<int>());

    // 가장 큰 값과 두번째로 큰 값
    int first = arr[0];
    int second = arr[1];

    // 수열이 반복되는 횟수를 구한 뒤, 이를 통하여 가장 큰 수가 등장하는 수를 구함.
    int firstCount = (M / (K + 1)) * K;

    // 나머지가 존재한다면, 나머지 만큼 큰 수가 반복될 것.
    firstCount += M % (K + 1);
    int secondCount = M - firstCount;

    Result = (first * firstCount) + (second * secondCount);

    std::cout << Result;
}

//21.8.10 3번 숫자 카드 게임
void NumberCardGame1()
{
    int N = 0;
    int M = 0;
    int Result = 0;

    std::cin >> N;
    std::cin >> M;

    // 2차원 배열 선언 (N개만큼 행, 0으로 초기화된 M개 만큼의 열을 가진 vector를 생성하겠다)
    std::vector<std::vector<int>> Card(N, std::vector<int>(M,0));
    
    // 카드 입력받기
    for (int y = 0; y < M; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            int Number = 0;
            std::cin >> Card[x][y];
        }
    }

    std::vector<int> MinNumbers;

    for (int y = 0; y < M; ++y)
    {
        int min = 10001;

        for (int x = 0; x < N; ++x)
        {
            // 현재 숫자가 행의 최솟값보다 작다면 교체
            if (Card[x][y] < min)
            {
                min = Card[x][y];
            }
        }
        
        if (min > Result)
        {
            Result = min;
        }
    }

    std::cout << Result << std::endl;
}

void NumberCardGame2()
{
    int N = 0;
    int M = 0;
    int Result = 0;

    std::cin >> N;
    std::cin >> M;
 
    // 카드 입력받기
    for (int y = 0; y < M; ++y)
    {
        int min = 10001;

        for (int x = 0; x < N; ++x)
        {
            int Number = 0;
            std::cin >> Number;

            // 한 줄에서 가장 큰 숫자 구하기.
            if (min > Number)
            {
                min = Number;
            }
        }

        // 작은 수 중에서 큰 수 찾기
        if (min > Result)
        {
            Result = min;
        }
    }

    std::cout << Result << std::endl;

}

//21.8.11 4번 1이 될때까지
void MakeOne()
{
    int N = 0;
    int K = 0;
    int Count = 0;

    std::cin >> N >> K;

    // N이 1이 될 때 까지 while 문
    while (N != 1)
    {
        // 나눠 떨어지지 않을 경우에만 1을 빼고
        if (N % K != 0)
        {
            N -= 1;
        }

        // 나머지 경우에는 항상 나눗셈을 한다.
        else
        {
            N /= K;
        }

        ++Count;
    }

    std::cout << Count << std::endl;
}

//21.8.12 백준 4796번 캠핑
void Camping()
{
    int InputCheck = 0;

    while (true)
    {
        int L, P, V;

        std::cin >> L >> P >> V;
        ++InputCheck;

        if (L == 0 && P == 0 && V == 0)
        {
            break;
        }

        int Result = L * (V / P);
        int  remainder = V % P;

        if (L > remainder)
        {
            Result += remainder;
        }

        else
        {
            Result += L;
        }

        std::cout << "Case " << InputCheck << ": " << Result << std::endl;
    }
}



