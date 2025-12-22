#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int w=strs[0].size();

        vector<int> dp(w,1);

        for(int i=0;i<w;i++){
            for(int j=0;j<i;j++){
                bool valid=true;
                for(auto&str:strs) if(str[j]>str[i]){
                    valid=false;
                    break;
                }
                if(valid) dp[i]=max(dp[i],dp[j]+1);
            }
        }

        return w-*max_element(dp.begin(),dp.end());
    }
};
