 #include <bits/stdc++.h>
 using namespace std;
 
 void longest_pre_suf(string pattern, vector<int> &LPS){
        int m = pattern.size();
        int i = 1;
        int length = 0;
        LPS[0] = 0;

        while(i < m){
            if(pattern[i] == pattern[length]){
                length++;
                LPS[i] = length;
                i++;
            }
            else{
                if(length != 0){
                    length = LPS[length-1];   
                }
                else{ 
                    LPS[i] = 0;
                    i++;
                }
            }
        }
    }

    vector<int> KMP(string pattern, string txt){
        vector<int> res;

        int n = txt.size();
        int m = pattern.size();
        vector<int> LPS(m, 0);

        longest_pre_suf(pattern, LPS);

        int i = 0, j = 0;

        while(i < n){
            if(txt[i] == pattern[j]){
                i++;
                j++;
            }

            if(j == m){
                res.push_back(i-j);
                j = LPS[j-1];         // no need to go first ind that's is the beauty of KMP
            }
            else if(i < n && txt[i] != pattern[j]){
                if (j != 0) {
                    j = LPS[j - 1];
                } else {
                    i++;
                }
            }
        }

        return res;
    }

    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> res;

        vector<int> i_ind = KMP(a, s);
        vector<int> j_ind = KMP(b, s);

        int n = s.size();

        for(auto i : i_ind){

            int left_limit = max(0, i - k);
            int right_limit = min(n-1, i + k);

            auto it = lower_bound(j_ind.begin(), j_ind.end(), left_limit);

            if(it != j_ind.end() && *it <= right_limit){
                res.push_back(i);
            }
        }

        return res;
    }