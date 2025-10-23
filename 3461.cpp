#include<string>
using namespace std;

class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size()!=2){
            for(int i=0;i+1<s.size();i++){
                s[i]=((s[i]-'0')+(s[i+1]-'0'))%10+'0';
            }
            s.pop_back();
        }
        return s[0]==s[1];
    }
};