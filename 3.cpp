#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            auto n=s.size();
            if(n==0) return 0;
            unordered_set<char> unique;
            int ans=0;
            int left=0;
            int right=0;
            while(left<=right && right<n){
                while(right<n && unique.find(s[right])==unique.end()){
                    unique.insert(s[right]);
                    right++;
                }
                ans=max(ans,(int)unique.size());
                while(right<n && unique.find(s[right])!=unique.end()){
                    unique.erase(s[left]);
                    left++;
                }
            }
            return ans;
        }
    };

class SolutionTry2 {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        vector<int> freq(128,0);
        int left=0;
        int ans=0;

        for(int right=0;right<n;right++){
            char toAdd=s[right];
            while(freq[toAdd]==1){
                char toRemove=s[left];
                freq[toRemove]--;
                left++;
            }
            freq[toAdd]++;
            ans=max(ans,right-left+1);
        }

        return ans;
    }
};