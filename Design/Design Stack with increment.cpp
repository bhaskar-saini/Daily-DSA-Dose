//Leetcode Link - https://leetcode.com/problems/design-a-stack-with-increment-operation/

#include <bits/stdc++.h>
using namespace std;

class CustomStack {
public:
    vector<int>st;
    int n;
    int cnt;
    int top;
    CustomStack(int maxSize) {
        n = maxSize;
        st = vector<int>(n,0);
        cnt = 0;
        top = -1;
    }
    
    void push(int x) {
        if(cnt < n){
            st[++top] = x;
            cnt++;
        }
    }
    
    int pop() {
        if(cnt == 0)return -1;
        int topval = st[top--];
        cnt--;
        return topval;
    }
    
    void increment(int k, int val) {
        int i=0;
        while(i<k && i<=top){
            st[i] += val;
            i++;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */