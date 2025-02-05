#include<string>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2) return true;
        int n=s1.size();
        int cnt1[26]={0};
        int cnt2[26]={0};
        int diff=0;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
            diff++;
            if(diff>2) return false;
        }
        cnt1[s1[i]-'a']++;
        cnt2[s2[i]-'a']++;
        }
        for(int i=0;i<26;i++) if(cnt1[i]!=cnt2[i]) return false;
        return true;
    }
};