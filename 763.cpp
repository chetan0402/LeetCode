#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
    public:
        vector<int> partitionLabels(string s) {
            auto n=s.size();
            vector<int> cnt(26);
            for(auto c:s) cnt[c-'a']++;
            int start=0;
            int end=0;
            unordered_set<int> toCheck;
    
            auto valid=[&]()->bool{
                for(auto c:toCheck) if(cnt[c]!=0) return false;
                return true;
            };
    
            vector<int> ans;
    
            while(end<n){
                toCheck.insert(s[end]-'a');
                cnt[s[end]-'a']--;
                while(end<n && !valid()){
                    end++;
                    cnt[s[end]-'a']--;
                    toCheck.insert(s[end]-'a');
                }
                ans.push_back(end-start+1);
                toCheck.clear();
                start=end+1;
                end=start;
            }
            
            return ans;
        }
    };