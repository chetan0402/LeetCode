#include<vector>
using namespace std;

const int MOD=1e9+7;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int ans=0;
        int sum=0;
        int odd=0;
        int even=1;
        for(auto num:arr){
            sum+=num;
            if(sum%2){
                ans+=even;
                odd++;
            }else{
                ans+=odd;
                even++;
            }
            ans%=MOD;
        }
        return ans;
    }
};