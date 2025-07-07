#include<queue>
#include<unordered_map>
using namespace std;

class FreqStack {
    priority_queue<tuple<int,int,int>> pq;
    unordered_map<int,int> freq;
    int c=0;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        pq.push({freq[val],c++,val});
    }
    
    int pop() {
        auto [__,_,val]=pq.top();
        pq.pop();
        freq[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */