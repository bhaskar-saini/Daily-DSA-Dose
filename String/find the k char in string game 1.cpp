//leetcode link - https://leetcode.com/contest/weekly-contest-417/problems/find-the-k-th-character-in-string-game-i/description/


#include <iostream>
using namespace std;

class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while (s.size() < k) {
            string t;
            for (char c : s) t.push_back((c - 'a' + 1) % 26 + 'a');
            s += t;
        }
        return s[k - 1];
    }
};