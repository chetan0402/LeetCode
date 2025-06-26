#include<string>
using namespace std;

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n=s.size();
        int len=0;
        long long value=0,pow=1;

        for(auto c:s) if(c=='0') len++;

        for(int i=n-1;i>=0;i--){
            if(s[i]=='1'){
                if(value+pow>k) continue;
                value+=pow;
                len++;
            }
            pow<<=1;
            if(pow>k) break;
        }

        return len;
    }
};