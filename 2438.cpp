#include<vector>
using namespace std;

const int MOD=1e9+7;

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> bits;

        for(int i=1;i<=1e9;i*=2){
            if(n&i) bits.push_back(i);
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for(auto&q:queries){
            long long result=1;
            for(int i=q[0];i<=q[1];i++){
                result*=bits[i];
                result%=MOD;
            }
            ans.push_back(result);
        }

        return ans;
    }
};