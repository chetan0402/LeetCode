#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        int m=p.size();
        if(m>n) return vector<int>();
        vector<int> ans;

        vector<int> targetFreq(26,0);
        for(auto c:p) targetFreq[c-'a']++;

        vector<int> curFreq(26,0);
        int left=0;
        int right=0;
        for(;right<m-1;right++) curFreq[s[right]-'a']++;

        auto valid=[&]()->bool{
            for(int i=0;i<26;i++) if(targetFreq[i]!=curFreq[i]) return false;
            return true;
        };

        while(right<n){
            int toAdd=s[right]-'a';
            curFreq[toAdd]++;
            if(valid()) ans.push_back(left);
            int toRemove=s[left]-'a';
            curFreq[toRemove]--;
            left++;
            right++;
        }

        return ans;
    }
};