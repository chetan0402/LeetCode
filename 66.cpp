#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        vector<int> ans;
        ans.reserve(n);

        bool carry=true;
        for(int i=n-1;i>=0;i--){
            int sum=digits[i]+carry;
            carry=false;
            if(sum>9) carry=true;
            ans.push_back(sum%10);
        }

        if(carry) ans.push_back(1);

        reverse(ans.begin(),ans.end());

        return ans;
    }
};