#include<string>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    string clearStars(string s) {
        int n=s.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        vector<bool> valid(n,true);
        for(int i=0;i<n;i++){
            char c=s[i];
            if(c=='*'){
                valid[-pq.top().second]=false;
                pq.pop();
            }
            else pq.push({c,-i});
        }
        string result="";
        for(int i=0;i<n;i++) if(s[i]!='*' && valid[i]) result+=s[i];
        return result;
    }
};