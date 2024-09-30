//letcode link - https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char kthCharacter(long long k, vector<int>& op) {
        if(k == 1)return 'a';
        int n = op.size();
        long long len = 1;
        long long newK = -1;
        int optype = -1;

        for(int i=0;i<n;i++){
            len *= 2;
            if(len >= k){
                optype = op[i];
                newK = k - len/2;
                break;
            }
        }

        char ch = kthCharacter(newK,op);
        if(optype == 0){
            return ch;
        }
        else{
            if(ch == 'z')return 'a';
            return ch + 1;
        }
    }
};