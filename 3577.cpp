#include<vector>
using namespace std;

const int MOD=1e9+7;

class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        for(int i=1;i<complexity.size();i++) if(complexity[i]<=complexity[0]) return 0;

        int n=complexity.size()-1;
        long long ans=1;
        for(int i=n;i>=2;i--) ans=(ans*(i%MOD))%MOD;
        return ans%MOD;
    }
};
