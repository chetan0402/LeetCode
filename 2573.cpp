#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        long long countGood(vector<int>& nums, int k) {
            long long ans=0;
            unordered_map<int,int> cnt;
            int pairs=0;
            int left=0;
            int right=0;
            while(left<=right && right<nums.size()){
                while(pairs<k && right<nums.size()){
                    auto numAdded=nums[right];
                    pairs+=cnt[numAdded];
                    cnt[numAdded]++;
                    right++;
                }
                while(pairs>=k && left<right){
                    ans+=nums.size()-right+1;
                    auto numRemove=nums[left];
                    cnt[numRemove]--;
                    pairs-=cnt[numRemove];
                    left++;
                }
            }
            return ans;
        }
    };