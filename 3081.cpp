#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string minimizeStringValue(string s) {
        int questionMarks=0;
        vector<int> cnt(26,0);
        for(auto c:s)
        if(c=='?') questionMarks++;
        else cnt[c-'a']++;

        vector<int> extra(26,0);

        while(questionMarks--){
            int minIndex=0;
            for(int i=0;i<26;i++) if(cnt[i]+extra[i]<cnt[minIndex]+extra[minIndex]) minIndex=i;
            extra[minIndex]++;
        }

        string ans="";

        for(auto c:s){
            if(c=='?'){
                for(int i=0;i<26;i++) if(extra[i]){
                    extra[i]--;
                    ans.push_back(i+'a');
                    break;
                }
            }else ans.push_back(c);
        }

        return ans;
    }
};