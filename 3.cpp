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