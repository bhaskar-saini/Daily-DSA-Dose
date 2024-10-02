//leetcode link - https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {

        unordered_map<int,int>mp;
        for(auto &it: arr){
            int rem = (it%k+k)%k;
            mp[rem]++;
        }
        if(mp[0] % 2 != 0)return false;

        for(int i=1;i<=k/2;i++){
            int partner = k - i;
            if(mp[partner] != mp[i]){
                return false;
            }
        }
        return true;
    }
};