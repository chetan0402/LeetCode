#include<string>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int sign=1;
        long long num=0;
        int i=0;
        while(i<n && s[i]==' ') i++;
        if(i<n && (s[i]=='-' || s[i]=='+')){
            if(s[i]=='-') sign=-1;
            i++;
        }
        while(i<n && isdigit(s[i])){
            num*=10;
            num+=(s[i]-'0');
            if(num>1LL+INT_MAX){
                num=1LL+INT_MAX;
                break;
            }
            i++;
        }
        long long result=sign*num;
        if(result<INT_MIN) result=INT_MIN;
        if(result>INT_MAX) result=INT_MAX;
        return result;
    }
};