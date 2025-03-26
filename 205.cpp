#include<string>
using namespace std;

class Solution {
    public:
        bool isIsomorphic(string s, string t) {
            char mapFromS[128];
            char mapFromT[128];
            for(int i=0;i<s.size();i++){
                if(mapFromS[s[i]]!=0 && mapFromS[s[i]]!=t[i]) return false;
                if(mapFromT[t[i]]!=0 && mapFromT[t[i]]!=s[i]) return false;
                mapFromS[s[i]]=t[i];
                mapFromT[t[i]]=s[i];
            }
            return true;
        }
    };