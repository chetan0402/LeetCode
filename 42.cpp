#include<vector>
using namespace std;

class Solution {
    public:
        int trap(vector<int>& height) {
            auto n=height.size();
            vector<int> water(n);
            water[0]=height[0];
            for(int i=1;i<n;i++) water[i]=max(height[i],water[i-1]);
            water[n-1]=height[n-1];
            for(int i=n-2;i>=0;i--){
                if(height[i]>height[i+1]) water[i]=max(height[i],water[i+1]);
                if(height[i]<=height[i+1] && water[i]>water[i+1]) water[i]=water[i+1];
            }
            int ans=0;
            for(int i=0;i<n;i++) ans+=(water[i]-height[i]);
            return ans;
        }
    };