#include "etc.h"

string MaxMin(string s)
{
    vector<int> numbers;
    string answer = "";

    string number = "";
    for (int i = 0; i < s.length(); ++i)
    {
        number += s[i];

        if (s[i] == ' ' || i == (s.length() - 1))
        {
            numbers.push_back(stoi(number));
            number.clear();
        }
    }

    sort(numbers.begin(), numbers.end());

    answer += to_string(numbers[0]);
    answer += ' ';
    answer += to_string(numbers[numbers.size() - 1]);

    return answer;
}

bool CheckLine(bool* arr, int findCount, string currentWord)
{
    bool result = false;
    int checkCount = 0;
    for (int i = 0; i < 3; ++i)
    {
        if (arr[i])
        {
            ++checkCount;
        }
    }

    // 각 줄에서 하나씩 찾고, 단어를 전부 찾았다면
    if (checkCount == 3 &&
        findCount == currentWord.length())
    {
        result = true;
    }

    return result;
}

vector<string> CardGame(vector<string> card, vector<string> word)
{
    vector<string> answer = {};

    // 한 단어당 vector를 전부 탐색해야함.
    for (int i = 0; i < word.size(); ++i)
    {
        string strCard;
        // 카드를 하나의 문자열로 변환
        for (int i = 0; i < card.size(); ++i)
        {
            strCard += card[i];
        }

        string currentWord = word[i];
        int findCount = 0;
        bool checkLine[3] = { false };

        for (int j = 0; j < currentWord.length(); ++j)
        {
            char findChar = currentWord[j];
            int pos = strCard.find(findChar);

            // 문자가 존재하지 않을 경우
            if (pos == -1)
            {
                cout << findChar;
                break;
            }
            else
            {
                // 찾았을 경우 해당 문자를 소문자로 바꿔줌(찾음 처리)
                strCard[pos] += 32;

                int line = pos / 8;
                checkLine[line] = true;
                ++findCount;
            }
        }

        if (CheckLine(checkLine, findCount, currentWord))
        {
            answer.push_back(currentWord);
        }
    }

    if (answer.size() == 0)
    {
        answer.push_back("-1");
    }

    return answer;

}

int MakeBtoA(string before, string after)
{
    int answer = 1;
    unordered_map<char, int> beforeTable;
    unordered_map<char, int> afterTable;

    // 단어를 등록
    for (int i = 0; i < before.length(); ++i)
    {
        // table에 없을 경우
        if (beforeTable.find(before[i]) == beforeTable.end())
            beforeTable[before[i]] = 1;
        else
            ++beforeTable[before[i]];

        if (afterTable.find(after[i]) == afterTable.end())
            afterTable[after[i]] = 1;
        else
            ++afterTable[after[i]];
    }


    //문자열의 글자가 같은지, 글자 갯수가 같은지 확인
    auto iter = afterTable.begin();
    auto iterEnd = afterTable.end();

    for (; iter != iterEnd; ++iter)
    {
        // 알파벳이 존재하지 않을 경우
        if (beforeTable.find(iter->first) == beforeTable.end())
            return 0;

        // 알파벳이 존재하는 경우 철자 수까지 확인함
        else
        {
            if (beforeTable[iter->first] != iter->second)
                return 0;
        }
    }

    return answer;
}

string MorseSign(string letter)
{
    string answer = "";
    string morse = "'.-':'a','-...':'b','-.-.':'c','-..':'d','.':'e','..-.':'f','--.':'g','....':'h','..':'i','.---':'j','-.-':'k','.-..':'l','--':'m','-.':'n','---':'o','.--.':'p','--.-':'q','.-.':'r','...':'s','-':'t','..-':'u','...-':'v','.--':'w','-..-':'x','-.--':'y','--..':'z'";

    // Map을 만들어서 table제작
    map<string, char> morseTable;
    string morseSign = "";
    for (int i = 0; i < morse.length(); ++i)
    {
        if (morse[i] == '.' || morse[i] == '-')
        {
            morseSign += morse[i];
        }

        // 문자 일 경우
        else if (morse[i] >= 'a' && morse[i] <= 'z')
        {
            morseTable[morseSign] = morse[i];
            morseSign.clear();
        }
    }

    string morseLetter = "";
    for (int i = 0; i < letter.length(); ++i)
    {
        if (letter[i] != ' ')
        {
            morseLetter += letter[i];
        }

        else
        {
            answer += morseTable[morseLetter];
            morseLetter.clear();
        }
    }

    // 마지막 철자는 저장
    answer += morseTable[morseLetter];

    return answer;
}
