#include<vector>
#include<stack>
#include<string>
using namespace std;

class Solution {
    public:
        int evalRPN(vector<string>& tokens) {
            stack<int> s;
            for(auto token:tokens){
                if(token=="+" || token=="-" || token=="*" || token=="/"){
                    int operand2=s.top();
                    s.pop();
                    int operand1=s.top();
                    s.pop();
                    int result;
                    if(token=="+") result=operand1+operand2;
                    if(token=="-") result=operand1-operand2;
                    if(token=="*") result=operand1*operand2;
                    if(token=="/") result=operand1/operand2;
                    s.push(result);
                }else s.push(stoi(token));
            }
            return s.top();
        }
    };