#include<vector>
#include<string>
using namespace std;

class Solution {
    public:
        string minWindow(string s, string t) {
            auto n=s.size();
            int charFound=0;
            vector<int> cnt(128,0);
            for(auto c:t) cnt[c]++;
            int left=0;
            int right=0;
            int start=-1;
            int len=INT_MAX;
            while(right<n){
                if(cnt[s[right]]>0) charFound++;
                cnt[s[right]]--;
                right++;
    
                while(charFound==t.size()){
                    if(len>right-left){
                        start=left;
                        len=right-left;
                    }
                    cnt[s[left]]++;
                    if(cnt[s[left]]>0) charFound--;
                    left++;
                }
            }
            return len==INT_MAX ? "" : s.substr(start,len);
        }
    };