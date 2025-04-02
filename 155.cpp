#include<stack>
using namespace std;

class MinStack {
    stack<int> nums;
    stack<int> mins;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        nums.push(val);
        if(mins.size()) {if(mins.top()>=val) mins.push(val);}
        else mins.push(val);
    }
    
    void pop() {
        if(mins.size() && mins.top()==nums.top()) mins.pop();
        nums.pop();
    }
    
    int top() {
        return nums.top();
    }
    
    int getMin() {
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */