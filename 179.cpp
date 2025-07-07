#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n=nums.size();
        vector<string> strnums;
        strnums.reserve(n);
        for(auto num:nums) strnums.push_back(to_string(num));
        sort(strnums.begin(),strnums.end(),[](auto a,auto b)->bool{
            return a+b>b+a;
        });
        if(strnums[0]=="0") return "0";
        string ans;
        for(auto&str:strnums) ans+=str;
        return ans;
    }
};