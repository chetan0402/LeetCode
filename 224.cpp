#include<stack>
#include<string>
using namespace std;

class Solution {
    public:
        int calculate(string s) {
            stack<int> st;
            int ans=0;
            int num=0;
            int sign=1;
            for(auto c:s){
                if(isdigit(c)) num=10*num+(c-'0');
                else if(c=='+'){
                    ans+=sign*num;
                    num=0;
                    sign=1;
                }else if(c=='-'){
                    ans+=sign*num;
                    num=0;
                    sign=-1;
                }else if(c=='('){
                    st.push(ans);
                    st.push(sign);
                    ans=0;
                    num=0;
                    sign=1;
                }else if(c==')'){
                    ans+=sign*num;
                    num=0;
                    auto stSign=st.top(); st.pop();
                    ans*=stSign;
                    auto prevAns=st.top(); st.pop();
                    ans+=prevAns;
                }
            }
            ans+=sign*num;
            return ans;
        }
    };