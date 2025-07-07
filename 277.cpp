#include<string>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int n=s.size();
        vector<string> tokens;
        int ptr=0;
        while(ptr<n){
            while(ptr<n && s[ptr]==' ') ptr++;
            if(isdigit(s[ptr])){
                string num;
                while(ptr<n && isdigit(s[ptr])){
                    num.push_back(s[ptr]);
                    ptr++;
                }
                tokens.push_back(num);
            }else{
                if(ptr<n) tokens.push_back(string(1,s[ptr]));
                ptr++;
            }
        }

        vector<string> postfix;
        stack<string> st;

        for(auto&token:tokens){
            if(token=="+" || token=="*" || token=="-" || token=="/"){
                if(st.empty()) st.push(token);
                else{
                    while(st.size() && (st.top()=="*" || st.top()=="/")){
                        postfix.push_back(st.top());
                        st.pop();
                    }
                    while((token=="+" || token=="-") && st.size()){
                        postfix.push_back(st.top());
                        st.pop();
                    }
                    st.push(token);
                }
            }else postfix.push_back(token);
        }

        while(st.size()){
            postfix.push_back(st.top());
            st.pop();
        }

        stack<int> ops;

        for(auto&token:postfix){
            if(token=="+" || token=="-" || token=="*" || token=="/"){
                int op2=ops.top();
                ops.pop();
                int op1=ops.top();
                ops.pop();
                int result;
                if(token=="+") result=op1+op2;
                if(token=="-") result=op1-op2;
                if(token=="*") result=op1*op2;
                if(token=="/") result=op1/op2;
                ops.push(result);
            }else ops.push(stoi(token));
        }

        return ops.top();
    }
};