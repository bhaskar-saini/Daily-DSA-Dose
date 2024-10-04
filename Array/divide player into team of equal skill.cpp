//leetcode - https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int i= 0;
        int j = skill.size()-1;
        long long ans = 0;
        long long teamskill = skill[i] + skill[j];
        while(i<j){
            if(skill[i]+skill[j] != teamskill)return -1;
            long long chemistry = skill[i++] * skill[j--];
            ans += chemistry;
        }
        return ans;
    }
};