//leetcode link - https://leetcode.com/problems/permutation-in-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.size() > s2.size())return false;

        vector<int>temp1(26,0),temp2(26,0);

        for(int i=0;i<s1.size();i++){
            int idx1 = s1[i] - 'a';
            int idx2 = s2[i] - 'a';
            temp1[idx1]++;
            temp2[idx2]++;
        }

        for(int i=s1.size();i<s2.size();i++){
            if(temp1 == temp2)return true;

            temp2[s2[i]-'a']++;
            temp2[s2[i-s1.size()]-'a']--;                
        }
        return temp1 == temp2;
    }
};