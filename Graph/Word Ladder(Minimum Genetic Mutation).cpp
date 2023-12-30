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