#include "Queue.h"

std::vector<int> DevelopFeature(std::vector<int> progresses, std::vector<int> speeds)
{
    std::queue<int> qDurations;
    std::vector<int> answer;

    // 각각의 기능이 얼만큼 걸리는지 계산.
    for (int i = 0; i < progresses.size(); ++i)
    {
        int remainAmount = 100 - progresses[i];
        int duration = remainAmount / speeds[i];

        // 나눠떨어지지 않으면 하루 더
        if ((remainAmount % speeds[i]) != 0)
        {
            duration += 1;
        }

        qDurations.push(duration);
    }

    int day = 1;

    // while 한번 당 하루
    int loopCount = 0;
    while (qDurations.size() != 0)
    {
        int endCount = 0;
        --qDurations.front();

        Work(loopCount, endCount, day, qDurations);

        if (endCount > 0)
        {
            answer.push_back(endCount);
        }

        ++loopCount;
        ++day;
    }

    std::cout << "Logic 1 LoopCount : " << loopCount<<std::endl;
    return answer;
}


void CheckProgress(int& loopCount, int& endCount, int day, std::queue<int>& q)
{
    ++loopCount;

    // 예외 처리
    if (q.size() == 0)
    {
        return;
    }

    // 일이 끝났다면, 해당 날짜에 종료된 다른 일은 없는지 점검
    if (q.front() <= 0)
    {
        q.pop();
        q.front() -= day;
        ++endCount;

        Work(loopCount, endCount, day, q);
    }
}

std::vector<int> DevelopFeature_2(std::vector<int> progresses, std::vector<int> speeds)
{
	std::queue<int> qDurations;
	std::vector<int> answer;

	// 각각의 기능이 얼만큼 걸리는지 계산.
	for (int i = 0; i < progresses.size(); ++i)
	{
		int remainAmount = 100 - progresses[i];
		int duration = remainAmount / speeds[i];

		// 나눠떨어지지 않으면 하루 더
		if ((remainAmount % speeds[i]) != 0)
		{
			duration += 1;
		}

		qDurations.push(duration);
	}

	int day = 0;
	int endCount = 0;

    int loopCount = 0;
	while (qDurations.size() > 0)
	{
		day += qDurations.front();
		Work(loopCount, endCount, day, qDurations);

		answer.push_back(endCount);
		endCount = 0;

        ++loopCount;
	}

    std::cout << "Logic 2 LoopCount : " << loopCount << std::endl;
	return answer;
}

void Work(int& loopCount, int& endCount, int day, std::queue<int>& q)
{
	q.front() -= day;
    ++loopCount;

	// 앞의 날짜 이후 일이 끝난 경우
	if (q.front() <= 0)
	{
		++endCount;
		q.pop();

		if (q.size() != 0)
		{
            Work(loopCount, endCount, day, q);
		}
	}
}

