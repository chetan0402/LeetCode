#include<vector>
#include<unordered_map>
using namespace std;

const int MOD=1e9+7;

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int> _cnt;
        for(auto&point:points) _cnt[point[1]]++;

        vector<long long> cnt;
        cnt.reserve(_cnt.size());
        for(auto [_, count]:_cnt) cnt.push_back(count);

        int ans=0;
        int n=cnt.size();

        vector<long long> chooses;
        chooses.reserve(cnt.size());
        for(auto count:cnt){
            long long choosen=count*(count-1);
            choosen>>=1;
            choosen%=MOD;
            chooses.push_back(choosen);
        }

        vector<long long> suffix(n);
        suffix[n-1]=chooses[n-1];
        for(int i=n-2;i>=0;i--) suffix[i]=(suffix[i+1]+chooses[i])%MOD;

        for(int i=0;i<n-1;i++){
            ans=(ans+chooses[i]*suffix[i+1])%MOD;
        }

        return ans;
    }
};
