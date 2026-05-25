#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        vector<bool> reach(n,false);
        reach[0]=true;
        int cnt=0;
        for(int i=1;i<n;i++){
            if(i-minJump>=0 && reach[i-minJump]) cnt++;
            if(i-maxJump-1>=0 && reach[i-maxJump-1]) cnt--;
            if(s[i]=='0') reach[i]=(cnt>0);
        }
        return reach[n-1];
    }
};
