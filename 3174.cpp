#include<string>
using namespace std;

class Solution {
    public:
        string clearDigits(string s) {
            string ans;
            int n=s.size();
            auto skip=0;
            for(int i=n-1;i>=0;i--){
                if(s[i]>='0' && s[i]<='9'){
                    skip++;
                }else if(skip){
                    skip--;
                }else{
                    ans=s[i]+ans;
                }
            }
            return ans;
        }
    };