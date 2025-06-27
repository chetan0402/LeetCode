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


class SolutionTry2 {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(m>n) return "";

        vector<int> target(128,0);
        for(auto c:t) target[c]++;
        vector<int> freq(128,0);

        auto valid=[&]()->bool{
            for(char chr='a';chr<='z';chr++){
                if(target[chr]>freq[chr]) return false;
            }
            for(char chr='A';chr<='Z';chr++){
                if(target[chr]>freq[chr]) return false;
            }
            return true;
        };

        int left=0;
        int ansStart=0;
        int ansLen=INT_MAX;
        for(int right=0;right<n;right++){
            freq[s[right]]++;
            while(valid() && left<n){
                int curLen=right-left+1;
                if(curLen<ansLen){
                    ansStart=left;
                    ansLen=curLen;
                }
                freq[s[left]]--;
                left++;
            }
        }

        return (ansLen==INT_MAX)?"":s.substr(ansStart,ansLen);
    }
};