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

class SolutionTry2 {
public:
    int calculate(string s) {
        stack<pair<int,int>> st;
        int result=0;
        int sign=1;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(c==' ') continue;
            if(isdigit(c)){
                long long num=0;
                while(i<s.size() && isdigit(s[i])){
                    num*=10;
                    num+=(s[i]-'0');
                    i++;
                }
                i--;
                result+=(sign*num);
                sign=1;
            }else if(c=='-'){
                sign=-sign;
            }else if(c=='('){
                st.push({result,sign});
                result=0;
                sign=1;
            }else if(c==')'){
                auto [oldNum, oldSign]=st.top();
                st.pop();
                result=(oldNum+(oldSign*result));
            }
        }
        return result;
    }
};