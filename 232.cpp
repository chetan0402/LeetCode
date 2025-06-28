#include<stack>
using namespace std;

class MyQueue {
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.size()){
            auto num=s2.top();
            s2.pop();
            return num;
        }
        while(s1.size()){
            s2.push(s1.top());
            s1.pop();
        }
        return pop();
    }
    
    int peek() {
        if(s2.size()) return s2.top();
        while(s1.size()){
            s2.push(s1.top());
            s1.pop();
        }
        return peek();
    }
    
    bool empty() {
        return (s1.empty() && s2.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */