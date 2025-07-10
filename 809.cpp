#include<string>
#include<vector>
using namespace std;

class Solution {
    bool stretchy(string&s,string&original){
        if(s.size()<original.size()) return false;
        int ptr1=0;
        int ptr2=0;
        int n=s.size();
        int m=original.size();

        while(ptr1<n && ptr2<m){
            if(s[ptr1]!=original[ptr2]) return false;
            int oldChar=0;
            int len=0;
            while(ptr1<n && ptr2<m && s[ptr1]==original[ptr2]){
                if(oldChar==original[ptr2]) len++;
                else{
                    oldChar=original[ptr2];
                    len=1;
                }
                ptr1++;
                ptr2++;
            }
            int streech=0;
            while(ptr1<n && s[ptr1]==oldChar){
                ptr1++;
                streech++;
            }
            if(streech!=0 && len+streech<3) return false;
        }
        
        return (ptr1==n && ptr2==m);
    }
public:
    int expressiveWords(string s, vector<string>& words) {
        int ans=0;
        for(auto&word:words) ans+=(stretchy(s,word));
        return ans;
    }
};