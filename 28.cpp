#include<string>
using namespace std;

class Solution {
    public:
        int strStr(string haystack, string needle) {
            auto n=haystack.size();
            auto m=needle.size();
            for(int i=0;i<n;i++) for(int j=0;j<m;j++){
                if(haystack[i+j]!=needle[j]) break;
                if(j==m-1) return i;
            }
            return -1;
        }
    };