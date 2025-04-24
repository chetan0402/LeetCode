#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            int ans=0;
            unordered_map<int,int> cnt;
            auto n=nums.size();
            int right=0;
            unordered_set<int> unique(nums.begin(),nums.end());
            for(int left=0;left<n;left++){
                if(left>0){
                    int remove=nums[left-1];
                    cnt[remove]--;
                    if(cnt[remove]==0) cnt.erase(remove);
                }
                while(right<n && cnt.size()<unique.size()){
                    int add=nums[right];
                    cnt[add]++;
                    right++;
                }
                if(cnt.size()==unique.size()) ans+=(n-right+1);
            }
            return ans;
        }
    };