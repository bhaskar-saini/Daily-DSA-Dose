//Leetcode Link - https://leetcode.com/problems/rank-transform-of-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        unordered_map<int,int>mp;
        int n = arr.size();
        
        for(int i=0;i<n;i++){
            pq.push({arr[i],i});
        }
        int rank = 1;
        while(!pq.empty()){
            pair<int,int>p = pq.top();
            pq.pop();
            int val = p.first;
            int idx = p.second;
            
            if(mp.find(val) == mp.end()){
                mp[val] = rank++;
            }
        }
        for(int i=0;i<n;i++){
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};