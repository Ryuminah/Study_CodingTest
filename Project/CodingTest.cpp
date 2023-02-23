#include "CodingTest.h"

int CircleDetect(vector<vector<double>> objectBallPosList, vector<double> hitVector)
{
    constexpr double BallDiameter = 2;

    int answer = 0;

    vector<double> normalized;
    double vectorLength = sqrt((hitVector[0] * hitVector[0]) + (hitVector[1] * hitVector[1]));
    for (int i = 0; i < hitVector.size(); ++i)
    {
        double normalize = hitVector[i] / abs(vectorLength);
        normalized.push_back(normalize);
    }


    vector<double> position = { 0.f, 0.f };
    double ballVelocity = 1.0f;
    int ballCount = objectBallPosList.size();

    vector<vector<double>> greater = objectBallPosList;
    sort(greater.begin(), greater.end());

    // 원의 반지름
    double radiusDistance = (BallDiameter + BallDiameter);
    radiusDistance *= radiusDistance;

    while (position[0] <= greater[ballCount - 1][0] ||
        position[1] <= greater[ballCount - 1][1])
    {
        for (int i = 0; i < ballCount; ++i)
        {
            double checkX = objectBallPosList[i][0];
            double checkY = objectBallPosList[i][1];

            double centerLength = pow((position[0] - checkX) + (position[1] - checkY), 2.0);
            if ((centerLength < radiusDistance))
            {
                ++answer;
            }

            if (answer == 1)
            {
                return i;
            }
        }

        // 조건을 만족시킬 때까지 공을 이동 벡터 방향으로 시켜줌
        position[0] += (ballVelocity * normalized[0]);
        position[1] += (ballVelocity * normalized[1]);
    }

    if (answer == 0)
    {
        answer = -1;
    }

    return answer;
}