#include<string>
using namespace std;

class Solution {
    public:
        bool isAnagram(string s, string t) {
            int cntS[26];
            int cntT[26];
            for(auto c:s) cntS[c-'a']++;
            for(auto c:t) cntT[c-'a']++;
            for(int i=0;i<26;i++) if(cntS[i]!=cntT[i]) return false;
            return true;
        }
    };