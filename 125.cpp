#include<string>
using namespace std;

class Solution {
    bool smallalpha(char c){
        return (c>='a' && c<='z');
    }
    bool largealpha(char c){
        return (c>='A' && c<='Z');
    }
    bool numeric(char c){
        return (c>='0' && c<='9');
    }
public:
    bool isPalindrome(string s) {
        auto n=s.size();
        for(int i=0;i<n;i++) if(largealpha(s[i])) s[i]+='a'-'A';
        int start=0;
        int end=n-1;
        while(start<end){
            while(start<n && !smallalpha(s[start]) && !largealpha(s[start]) && !numeric(s[start])) start++;
            while(end>=0 && !smallalpha(s[end]) && !largealpha(s[end]) && !numeric(s[end])) end--;
            if(start==n || end==-1) break;
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
};