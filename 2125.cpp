#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank_raw) {
        vector<int> bank;
        bank.reserve(bank_raw.size());

        for(auto&b:bank_raw){
            int device=0;
            for(auto c:b) if(c=='1') device++;
            if(device) bank.push_back(device);
        }

        int ans=0;

        for(int i=0;i+1<bank.size();i++) ans+=bank[i]*bank[i+1];

        return ans;
    }
};

class Solution2 {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans=0;
        int prev=0;

        for(int i=0;i<bank.size();i++){
            int cur=0;
            for(int j=0;j<bank[i].size();j++) if(bank[i][j]=='1') cur++;
            if(cur==0) continue;
            ans+=prev*cur;
            prev=cur;
        }

        return ans;
    }
};