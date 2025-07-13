#include<string>
using namespace std;

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long decodedLength=0;
        for(auto c:s){
            if(isdigit(c)){
                decodedLength*=(c-'0');
            }else decodedLength++;
        }

        for(int i=s.size()-1;i>=0;i--){
            if(isdigit(s[i])){
                decodedLength/=(s[i]-'0');
                k%=decodedLength;
            }else{
                if(k==0 || decodedLength==k) return string(1,s[i]);
                decodedLength--;
            }
        }

        return "~";
    }
};