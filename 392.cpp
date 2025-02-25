#include<string>
using namespace std;

class Solution {
    public:
        bool isSubsequence(string s, string t) {
            int ptrS=0;
            for(auto&c:t){
                if(ptrS>=s.size()) break;
                if(c==s[ptrS]) ptrS++;
            }
            return (ptrS==s.size());
        }
    };