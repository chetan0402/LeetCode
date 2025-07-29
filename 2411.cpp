#include<vector>
using namespace std;

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();

        vector<int> suffix(n,0);
        suffix[n-1]=nums[n-1];

        for(int i=n-2;i>=0;i--) suffix[i]=suffix[i+1]|nums[i];

        vector<vector<int>> prefix(n);
        prefix[0]=vector<int>(sizeof(int)*8,0);

        for(int i=0;i<n;i++){
            if(i>0) prefix[i]=prefix[i-1];
            int pos=0;
            int num=nums[i];
            while(num){
                prefix[i][pos]+=(num&1);
                num>>=1;
                pos++;
            }
        }

        vector<int> ans(n);

        for(int i=0;i<n;i++){
            int j=-1;

            int left=i;
            int right=n-1;

            while(left<=right){
                int mid=left+(right-left)/2;

                int current_value=0;
                for(int pos=8*sizeof(int)-1;pos>=0;pos--){
                    current_value<<=1;
                    if((prefix[mid][pos]-(i<=0?0:prefix[i-1][pos]))) current_value|=1;
                }

                if(current_value==suffix[i]) j=mid;

                if(current_value>=suffix[i]){
                    right=mid-1;
                }else left=mid+1;
            }

            ans[i]=(j-i+1);
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();

        vector<int> lastSeen(32,n-1);

        int target=0;

        vector<int> ans(n);

        for(int i=n-1;i>=0;i--){
            int pos=0;
            int num=nums[i];

            target|=num;

            while(num){
                if(num&1) lastSeen[pos]=i;
                num>>=1;
                pos++;
            }

            int smallestPossible=i;

            int temp=target;
            pos=0;

            while(temp){
                if(temp&1) smallestPossible=max(smallestPossible,lastSeen[pos]);
                temp>>=1;
                pos++;
            }

            ans[i]=(smallestPossible-i+1);
        }

        return ans;
    }
};