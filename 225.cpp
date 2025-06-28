#include<queue>
using namespace std;

class MyStack {
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int last=q1.front();
        q1.pop();
        while(q1.size()){
            q2.push(last);
            last=q1.front();
            q1.pop();
        }
        swap(q1,q2);
        return last;
    }
    
    int top() {
        auto num=pop();
        push(num);
        return num;
    }
    
    bool empty() {
        return (q1.empty());
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */