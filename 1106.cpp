#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stack_eval;
        for(int i=0;i<expression.size();i++){
            if(expression[i]!=')'){
                stack_eval.push(expression[i]);
            }else{
                stack<char> temp;
                while(stack_eval.top()!='('){
                    temp.push(stack_eval.top());
                    stack_eval.pop();
                }
                stack_eval.pop();
                bool eval;
                switch(stack_eval.top()){
                    case '!':
                        stack_eval.pop();
                        if(temp.top()=='t') stack_eval.push('f');
                        else stack_eval.push('t');
                        break;
                    case '&':
                        stack_eval.pop();
                        eval = true;
                        while(!temp.empty()){
                            if(temp.top()==','){
                                temp.pop();
                                continue;
                            }
                            eval = eval && temp.top()=='t';
                            temp.pop();
                            if(eval==false) break;
                        }
                        if(eval) stack_eval.push('t');
                        else stack_eval.push('f');
                        break;
                    case '|':
                        stack_eval.pop();
                        eval = false;
                        while(!temp.empty()){
                            if(temp.top()==','){
                                temp.pop();
                                continue;
                            }
                            eval = eval || temp.top()=='t';
                            temp.pop();
                            if(eval==true) break;
                        }
                        if(eval) stack_eval.push('t');
                        else stack_eval.push('f');
                        break;
                }
            }
        }
        if(stack_eval.top()=='t') return true;
        else return false;
    }
};