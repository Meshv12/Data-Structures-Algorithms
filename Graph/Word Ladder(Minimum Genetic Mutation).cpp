#include <bits/stdc++.h>
using namespace std;

int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
{
    set<string> st(wordList.begin(), wordList.end());
    queue<pair<string, int>> q;
    q.push({startWord, 1});
    st.erase(startWord);

    while (!q.empty())
    {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();
        if (word == targetWord)
            return steps;

        for (int i = 0; i < word.size(); i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (st.find(word) != st.end())
                { // find in wordlist
                    q.push({word, steps + 1});
                    st.erase(word);
                }
            }
            word[i] = original;
        }
    }

    return 0;
}

///  Minimum Genetic Mutation - (Asked by Twitter)  --> concept like Word Ladder

class Solution
{
public:
    string str = "ACGT";
    int minMutation(string startGene, string endGene, vector<string> &bank)
    {

        unordered_set<string> st(bank.begin(), bank.end());
        queue<pair<string, int>> q;
        q.push({startGene, 0});
        st.erase(startGene);

        while (!q.empty())
        {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (word == endGene)
                return steps;

            for (int i = 0; i < word.size(); i++)
            {
                char ch = word[i];
                for (auto it : str)
                {
                    word[i] = it;
                    if (st.find(word) != st.end())
                    {
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = ch;
            }
        }

        return -1;
    }
};

// Open the lock (leetcode-752)


int openLock(vector<string> &deadends, string target)
{
    unordered_set<string> st(deadends.begin(), deadends.end());

    if (st.find("0000") != st.end())
        return -1;

    queue<string> q;
    q.push("0000");
    st.insert("0000");
    int level = 0;

    while (!q.empty())
    {

        int size = q.size();

        while (size--)
        {

            string str = q.front();
            q.pop();

            if (str == target)
                return level;

            for (int i = 0; i < 4; i++)
            {
                char ch = str[i];
                char dec, inc;

                ch == '0' ? dec = '9' : dec = ch - 1;
                ch == '9' ? inc = '0' : inc = ch + 1;

                str[i] = inc; /// ek vaar increse karvu
                if (st.find(str) == st.end())
                {
                    q.push(str);
                    st.insert(str);
                }

                str[i] = dec; /// ek vaar decrese karvu
                if (st.find(str) == st.end())
                {
                    q.push(str);
                    st.insert(str);
                }

                str[i] = ch;
            }
        }
        level++;
    }

    return -1;
}