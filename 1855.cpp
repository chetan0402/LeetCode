#include<vector>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;

        int j=0;
        for(int i=0;i<nums1.size();i++){
            while(j<nums2.size() && nums1[i]<=nums2[j]) j++;
            ans=max(ans,j-i-1);
        }

        return ans;
    }
};
