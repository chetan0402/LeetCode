#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) freq[nums[i]*nums[j]]++;
        int ans=0;
        for(auto [key, value]: freq) ans+=(value)*(value-1)*4;
        return ans;
    }
};