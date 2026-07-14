#include<string>
using namespace std;

class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        int n=num.size();
        bool started=false;
        for(int i=0;i<n;i++) if(change[num[i]-'0']>=num[i]-'0'){
            if(change[num[i]-'0']==num[i]-'0' && !started) continue;
            started=true;
            num[i]=change[num[i]-'0']+'0';
        }else if(started) break;
        return num;
    }
};
