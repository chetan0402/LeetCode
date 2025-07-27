#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int n=arr.size();

        int left=0;
        int right=*max_element(arr.begin(),arr.end());

        auto sumCeil=[&](int value)->int{
            int sum=0;
            for(auto num:arr) sum+=min(value,num);
            return sum;
        };

        int ans=INT_MAX;
        int diff=INT_MAX;

        while(left<=right){
            int mid=left+(right-left)/2;
            int sum=sumCeil(mid);

            if(abs(target-sum)<diff){
                diff=abs(target-sum);
                ans=mid;
            }else if(abs(target-sum)==diff){
                ans=min(ans,mid);
            }

            if(sum<target) left=mid+1;
            else right=mid-1;
        }

        return ans;
    }
};