#include<vector>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans=0;

        for(auto&g:grid){
            int found=-1;
            int left=0;
            int right=g.size()-1;
            while(left<=right){
                int mid=left+(right-left)/2;
                if(g[mid]<0){
                    found=mid;
                    right=mid-1;
                }else left=mid+1;
            }
            if(found==-1) continue;

            ans+=g.size()-found;
        }
        return ans;
    }
};
