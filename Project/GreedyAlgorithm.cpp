#include "GreedyAlgorithm.h"

using namespace std;
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

void ATM()
{
    // Input
    int N = 0;
    std::cin >> N;

    std::vector<int> P;
    P.reserve(N);

    for (int i = 0; i < N; ++i)
    {
        int time = 0;
        std::cin >> time;
        P.push_back(time);
    }

    // 배열을 오름차순으로 정렬
    std::sort(P.begin(), P.end());

    int result = 0;
    int finalResult = 0;

    for (int i = 0; i < N; ++i)
    {
        int currentTime = P[i] + result;
        result = currentTime;

        finalResult += result;
    }

    // Output
    std::cout << finalResult;
}

std::string MakeBigNumber(std::string number, int k)
{
    string answer = "";

    int index = -1;
    for (int i = 0; i < number.size() - k; ++i)
    {
        char maxValue = ' ';
        for (int j = index + 1; j <= k + i; j++)
        {
            if (maxValue < number[j])
            {
                maxValue = number[j];
                index = j;
            }
        }
        answer += maxValue;
    }

    return answer;
}

int JoyStick(std::string name)
{
    int answer = 0;
    int n = name.length();

    // 조이스틱을 한 방향으로만 움직였을 때
    int moveOneDirection = n - 1;

    for (int i = 0; i < n; i++)
    {
        if (name[i] - 'A' < 14)
        {
            answer += name[i] - 'A';
        }

        else
        {
            answer += 'Z' - name[i] + 1;
        }


        int index = i + 1;

        while (index < n &&
            name[index] == 'A')
        {
            ++index;
        }

        moveOneDirection = min(moveOneDirection, (i + n - index) + min(i, n - index));
    }

    answer += moveOneDirection;
    return answer;
}

int SweatSuit(int n, vector<int> lost, vector<int> reserve)
{
    int answer = n;

    // 확실하게 빌려줄 수 있는 사람만 table에 등록.

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    unordered_map<int, bool> reserveTable;

    for (int i = 0; i < reserve.size(); ++i)
    {
        reserveTable[reserve[i]] = true;
    }

    for (int i = 0; i < lost.size(); ++i)
    {
        auto iter = reserveTable.find(lost[i]);

        // 여유분을 도난 맞은 상황이라면
        if (iter != reserveTable.end())
        {
            reserveTable.erase(iter->first);
            lost[i] = -1;
        }
    }


    for (int i = 0; i < lost.size(); ++i)
    {
        // 잃어버렸지만 여분이 있어서 안빌려도 되는 애
        if (lost[i] == -1)
        {
            continue;
        }

        // 왼쪽을 찾아본 뒤 
        auto iter = reserveTable.find(lost[i] - 1);

        // 못빌렸다면 오른쪽을 확인
        if (iter == reserveTable.end())
        {
            iter = reserveTable.find(lost[i] + 1);
        }

        // 결국 못빌린 애
        if (iter == reserveTable.end())
        {
            --answer;
        }

        // 빌렸다면 빌려줄 수 있는 Table에서 삭제해즌다
        else
        {
            reserveTable.erase(iter->first);
        }
    }

    return answer;
}

bool Compare(vector<int>& a, vector<int>& b)
{
    return a[1] < b[1];
}

int SpeedCamera(vector<vector<int>> routes)
{
    // 오름차순 정렬이 핵심인 문제
    int answer = 0;
    int camera = -300001;

    sort(routes.begin(), routes.end(), Compare);

    for (int i = 0; i < routes.size(); ++i)
    {
        if (routes[i][0] > camera)
        {
            ++answer;
            camera = routes[i][1];
        }
    }


    return answer;
}


int island[101] = { 0 };
bool Comp(vector<int>& v1, vector<int>& v2)
{
    return v1[2] < v2[2];
}

int FindParent(int index)
{
    if (island[index] == index) { return index; }
    return island[index] = FindParent(island[index]);
}

int LinkIsland(int n, vector<vector<int>> costs)
{
    int answer = 0;
    int bridge = 0;

    for (int i = 0; i < n; ++i)
    {
        island[i] = i;
    }

    // 오름차순 정렬
    sort(costs.begin(), costs.end(), Comp);

    for (int i = 0; i < costs.size(); ++i)
    {
        int startParent = FindParent(costs[i][0]);
        int endParent = FindParent(costs[i][1]);
        int cost = costs[i][2];

        // 부모가 다르면 건설
        if (startParent != endParent)
        {
            island[endParent] = startParent;
            answer += cost;
            ++bridge;
        }

        if (bridge == n - 1)
        {
            break;
        }
    }

    return answer;
}

void MissingParentheses()
{
    int answer = 0;
    string expression;
    cin >> expression;

    string number;
    int currentNumber;
    bool isMinus = false;

    // 부호와 숫자를 분리해서 저장
    for (int i = 0; i <= expression.size(); ++i)
    {
        // 부호 일 경우
        if (expression[i] == '-' || expression[i] == '+' ||
            i == expression.size())
        {
            currentNumber = stoi(number);
            number.clear();

            // 마지막 부호에 따라 계산을 달리함
            if (isMinus)
            {
                answer -= currentNumber;
            }

            else
            {
                answer += currentNumber;
            }


            isMinus = expression[i] == '-' ? true : isMinus;
        }

        // 숫자일 경우
        else
        {
            number += expression[i];
        }

    }

    cout << answer;
}

void Sensor()
{
    int answer = 0;
    int N, K;
    cin >> N >> K;

    vector<int> vSensor;
    for (int i = 0; i < N; ++i)
    {
        int pos;
        cin >> pos;
        vSensor.push_back(pos);
    }

    sort(vSensor.begin(), vSensor.end());


    vector<int> vDistance;
    for (int i = 1; i < N; ++i)
    {
        vDistance.push_back(vSensor[i] - vSensor[i - 1]);
    }

    sort(vDistance.begin(), vDistance.end());

    if (N >= K)
    {
        answer = accumulate(vDistance.begin(), vDistance.begin() + (N - K), 0);
    }

    cout << answer;
}

void Sensor1()
{
    int N, K, answer = { 0 };
	int sensor[10001] = { 0 };

	cin >> N >> K;

	for (int i = 0; i < N; ++i)
	{
		cin >> sensor[i];
	}

	sort(sensor, sensor + N);

	vector<int> vDistance;
	// 마지막 센서는 거리를 잴 센서가 없으므로
	for (int i = 1; i < N; ++i)
	{
		vDistance.push_back(sensor[i] - sensor[i - 1]);
	}

	// |--집중국--| 빈공간 |----집중국----| 빈 공간이 가장 큰 부분을 제외하고 더하면 된다.
	// 따라서 내림차순으로 정렬을 한 뒤 k-1개부터 빈공간을 더한다
	sort(vDistance.begin(), vDistance.end(), greater<int>());

	// K-1개 만큼 빈공간이 생기기 때문에 K-1로 순회
	for (int i = K-1; i < vDistance.size(); ++i)
	{
		answer += vDistance[i];
	}

	cout << answer;

}

int InstallBaseStation(int n, vector<int> stations, int w)
{
    int answer = 0;
    int index = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (index < stations.size() && i >= stations[index] - w)
        {
            i = stations[index] + w;
            ++index;
        }
        else
        {
            ++answer;
            i += w * 2;
        }
    }

    return answer;
}



