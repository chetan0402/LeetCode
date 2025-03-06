#include<vector>
using namespace std;

class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            auto n=grid.size();
            vector<int> cnt(n*n+1,0);
            vector<int> ans(2);
            for(auto v:grid) for(auto num:v){
                cnt[num]++;
                if(cnt[num]==2) ans[0]=num;
            }
            for(int i=1;i<=n*n;i++) if(cnt[i]==0) ans[1]=i;
            return ans;
        }
    };