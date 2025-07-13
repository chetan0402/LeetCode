#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        if(m<n) return false;
        
        vector<int> freq(26,0);
        for(auto c:s1) freq[c-'a']++;

        vector<int> freq2(26,0);
        for(int i=0;i<n;i++) freq2[s2[i]-'a']++;

        auto valid=[&]()->bool{
            for(int i=0;i<26;i++) if(freq[i]!=freq2[i]) return false;
            return true;
        };

        if(valid()) return true;

        for(int i=n;i<m;i++){
            freq2[s2[i]-'a']++;
            freq2[s2[i-n]-'a']--;
            if(valid()) return true;
        }

        return false;
    }
};