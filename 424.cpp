#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        vector<int> freq(26,0);
        int left=0;
        int ans=0;

        auto valid=[&](int length)->bool{
            int maxChar=0;
            for(int i=1;i<26;i++) if(freq[i]>freq[maxChar]) maxChar=i;
            int numberOfchances=length-freq[maxChar];
            return (numberOfchances<=k);
        };

        for(int right=0;right<n;right++){
            int toAdd=s[right]-'A';
            freq[toAdd]++;
            while(!valid(right-left+1)){
                int toRemove=s[left]-'A';
                freq[toRemove]--;
                left++;
            }
            ans=max(ans,right-left+1);
        }

        return ans;
    }
};