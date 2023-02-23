#include "Math.h"

// 유클리드 호제법
vector<int> AdditionOfFractions(int denum1, int num1, int denum2, int num2)
{
    vector<int> answer;

    // 1. 공통 분모를 구함 (최소 공배수)
    int Min = min(num1, num2);
    int Max = max(num1, num2);

    int denominator = Max;
    while (denominator % Min != 0)
    {
        denominator += Max;
    }
    int molecule = denum1 * (denominator / num1) + denum2 * (denominator / num2);

    // 2. 최대 공약수를 구해서 나눔
    Min = min(denominator, molecule);
    Max = max(denominator, molecule);

    int remain = 0;
    while (Min != 0)
    {
        remain = Max % Min;
        Max = Min;
        Min = remain;
    }

    answer.push_back(molecule / Max);
    answer.push_back(denominator / Max);

    return answer;
}

long long N, K, A, B, half;
long long mod = 1000000007;

long long solve(int x)
{
    if (x == 0) return 1;

    if (x % 2 == 1) return B * solve(x - 1) % mod;
    else
    {
        half = solve(x / 2);
        return half * half % mod;
    }
}

void BinomialCoefficient()
{
    cin >> N >> K;
	A = 1;
	// A = N*(N-1)* .... *(N-K+1)
	for (int i = N; i >= N - K + 1; i--) A = (A * i) % mod;

	// B = K!
	B = 1;
	for (int i = 1; i <= K; i++) B = (B * i) % mod;

	// B = (K!)^(p-2)
	B = solve(mod - 2);

	cout << A * B % mod;
}

void DistributedProcessing()
{
    int T,a,b,answer;
    cin >> T;

    for (int i = 0; i < T; ++i)
    {
        answer = 1;
        cin >> a >> b;

        for (int j = 0; i < b; ++j)
        {
            answer = (answer * a) % 10;
        }

        answer = answer == 0 ? 10 : answer;
        cout << answer << '\n';
    }
}
