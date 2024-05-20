#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;
    vector<ll> bitCount;

    void getBitsCnt(ll num){                // use recursion to get bits array

        if(num == 0) return;

        if(num == 1){   // 01
            bitCount[0] += 1;
            return;
        }
        if(num == 2){    // 01 10
            bitCount[0] += 1;
            bitCount[1] += 1;
            return;
        }


        ll bitlen = log2(num);
        ll nearPower2 = (1ll << bitlen);
        bitCount[bitlen] += num - nearPower2 + 1;

        for(int i = 0; i<bitlen; i++){
            bitCount[i] += (nearPower2)/2;
        }

        ll remaining = num - nearPower2;
        getBitsCnt(remaining);
    }

    long long findMaximumNumber(long long k, int x) {
        ll low = 0;
        ll high = 1e15;
        ll result = 0;

        while(low <= high){
            ll mid = low + (high-low)/2;

            bitCount = vector<ll>(65, 0);
            getBitsCnt(mid);
            // it will find the cnt of set bits at each position from numbers 0 to mid

            ll totalPrice = 0;
            for(ll i = 0; i < log2(mid)+1; i++){
                if((i+1) % x == 0){
                    totalPrice += bitCount[i];
                } 
            }

            if(totalPrice <= k){
                result = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return result;

    }
};