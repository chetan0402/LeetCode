#include<string>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        int numberOfSubstrings(string s) {
            auto n=s.size();
            unordered_map<char,int> cnt;
            int start=0;
            int end=0;
            auto allFound=[&]()->bool{
                return (cnt['a']>0 && cnt['b']>0 && cnt['c']>0);
            };
            int ans=0;
            while(end<n){
                while(end<n && !allFound()){
                    cnt[s[end]]++;
                    end++;
                }
                while(start<n && allFound()){
                    ans+=n-end+1;
                    cnt[s[start]]--;
                    start++;
                }
            }
            return ans;
        }
    };