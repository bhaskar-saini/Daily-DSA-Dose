//Leetcode - https://leetcode.com/problems/make-sum-divisible-by-p/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>&nums,int k,int p){
        unordered_map<int,int>mp;
        int prefixSum = 0;
        int cnt = INT_MAX;
        mp[0] = -1;

        for(int i=0;i<nums.size();i++){
            prefixSum = (prefixSum + nums[i])%p;
            if(nums[i] == k)return 1;
            int prev = (prefixSum - k + p) % p;
            if(mp.find(prev) != mp.end()){
                int newCnt = i - mp[prev];
                if(newCnt < cnt){
                    cnt = newCnt;
                }
            }
            mp[prefixSum] = i;
        }
        return cnt == INT_MAX ? -1 : cnt;
    }
    int minSubarray(vector<int>& nums, int p) {
        int sum = 0;
        for(auto &it : nums){
            sum = (sum + it)%p;
        }
        int target = sum % p;
        int cnt = 0;
        if(target > 0)
            cnt = solve(nums,target,p);

        if(cnt == nums.size())return -1;
        return cnt;
    }
};