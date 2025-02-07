#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            auto n=nums.size();
            k=k%n;
            reverse(nums.begin(),nums.end());
            reverse(nums.begin()+k,nums.end());
            reverse(nums.begin(),nums.begin()+k);
        }
    };