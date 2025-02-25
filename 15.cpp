#include<vector>
#include<algorithm>
using namespace std;
// space of sort recusion not considered

// logn space and n*logn+n*n*logn time
class Solution1 {
    int search(vector<int>&arr,int left,int right,int find){
        if(left>right) return -1;
        if(left==right){
            if(arr[left]==find) return left;
            else return -1;
        }
        auto mid=(left+right)/2;
        if(arr[mid]==find) return mid;
        if(arr[mid]<find) return search(arr,mid+1,right,find);
        else return search(arr,left,mid-1,find);
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        auto n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i!=0 && nums[i-1]==nums[i]) continue;
            for(int j=i+1;j<n;j++){
                if(j!=i+1 && nums[j-1]==nums[j]) continue;
                int index=search(nums,j+1,n-1,-(nums[i]+nums[j]));
                if(index!=-1){
                    ans.push_back({nums[i],nums[j],nums[index]});
                }
            }
        }
        return ans;
    }
};

// 1 space and n*logn+n*n time
class Solution2 {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            auto n=nums.size();
            vector<vector<int>> ans;
            sort(nums.begin(),nums.end());
            for(int i=0;i<n;i++){
                if(i!=0 && nums[i-1]==nums[i]) continue;
                int j=i+1;
                int k=n-1;
                while(j<k){
                    auto sum=nums[i]+nums[j]+nums[k];
                    if(sum<0) j++;
                    else if(sum>0) k--;
                    else{
                        ans.push_back({nums[i],nums[j],nums[k]});
                        j++;
                        k--;
                        while(j<n && nums[j-1]==nums[j]) j++;
                        while(k>j && nums[k+1]==nums[k]) k--;
                    }
                }
            }
            return ans;
        }
    };