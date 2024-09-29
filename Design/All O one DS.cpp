//leetcode link - https://leetcode.com/problems/all-oone-data-structure/description/


#include <bits/stdc++.h>
using namespace std;


class AllOne {
public:
    struct Node{
        int freq;
        Node* prev;
        Node* next;
        unordered_set<string>keys;
        //constructor
        Node(int f){
            freq = f;
            prev = NULL;
            next = NULL;
        }
    };

    unordered_map<string,Node*>mp;
    Node* head;
    Node* tail;

    AllOne() {
        head = new Node(0);
        tail = head;    
    }
    void addNode(Node* prevNode,int freq){
        Node* newNode = new Node(freq);
        newNode->next = prevNode->next;
        newNode->prev = prevNode;
        if(newNode->next != NULL){
            newNode->next->prev = newNode;
        }
        prevNode->next = newNode;
        if(prevNode == tail){
            tail = newNode;
        }
    }
    void removeNode(Node* curr){
        curr->prev->next = curr->next;
        if(curr->next != NULL){
            curr->next->prev = curr->prev;
        }
        if(tail == curr){
            tail = curr->prev;
        }
        delete curr;
    }

    void inc(string key) {
        if(mp.find(key) == mp.end()){
            if(head->next == NULL || head->next->freq != 1){
                addNode(head,1);
            }
            head->next->keys.insert(key);
            mp[key] = head->next;
        }
        else{
            Node* curr = mp[key];
            int freqcnt = curr->freq;
            if(curr->next == NULL || curr->next->freq != freqcnt+1){
                addNode(curr,freqcnt+1);
            }
            curr->next->keys.insert(key);
            mp[key] = curr->next;
            curr->keys.erase(key);
            if(curr->keys.empty()){
                removeNode(curr);
            }
        }
    }
    
    void dec(string key) {
        Node* curr = mp[key];
        int freqcnt = curr->freq;
        if(freqcnt == 1){
            mp.erase(key);
        }
        else{
            if(curr->prev->freq != freqcnt - 1 ){
                addNode(curr->prev,freqcnt-1);
            }
            curr->prev->keys.insert(key);
            mp[key] = curr->prev;
        }

        curr->keys.erase(key);
        if(curr->keys.empty()){
            removeNode(curr);
        }
    }
    
    string getMaxKey() {
        if(head == tail)return "";
        return *(tail->keys.begin());   
    }
    
    string getMinKey() {
        if(head->next == NULL)return "";
        return *(head->next->keys.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */