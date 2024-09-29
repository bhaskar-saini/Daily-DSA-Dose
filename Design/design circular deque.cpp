//Leetcode Problem Link - https://leetcode.com/problems/design-circular-deque/description/

//code
#include <bits/stdc++.h>
using namespace std;

class MyCircularDeque {
public:
    vector<int>deq;
    int n;
    int front;
    int rear;
    int count;
    MyCircularDeque(int k) {
        n = k;
        deq = vector<int>(n,0);
        front = 0;
        rear = n-1;
        count = 0;
    }
    
    bool insertFront(int value) {
        if(isFull())return false;
        front = (front-1+n)%n;
        deq[front] = value;
        count++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull())return false;
        rear = (rear+1)%n;
        deq[rear] = value;
        count++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty())return false;
        front = (front+1)%n;
        count--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty())return false;
        rear = (rear-1+n)%n;
        count--;
        return true;
    }
    
    int getFront() {
        if(count == 0)return -1;
        return deq[front];
    }
    
    int getRear() {
        if(count == 0)return -1;
        return deq[rear];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == n;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */