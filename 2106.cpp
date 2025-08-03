#include<vector>
using namespace std;

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        vector<int> prefix(fruits.size()+1);
        prefix[0]=0;
        for(int i=1;i<prefix.size();i++) prefix[i]=prefix[i-1]+fruits[i-1][1];

        int ans=0;

        for(int leftThenReturn=k/2;leftThenReturn>=0;leftThenReturn--){
            int leftMost=startPos-leftThenReturn;
            int rightMost=startPos+(k-2*leftThenReturn);

            int left=0;
            int right=fruits.size()-1;
            int found=-1;

            while(left<=right){
                int mid=left+(right-left)/2;

                if(fruits[mid][0]>=leftMost){
                    right=mid-1;
                    found=mid;
                }else left=mid+1;
            }
            if(found==-1) continue;
            int start=found;

            left=0;
            right=fruits.size()-1;
            found=-1;

            while(left<=right){
                int mid=left+(right-left+1)/2;

                if(fruits[mid][0]<=rightMost){
                    left=mid+1;
                    found=mid;
                }else right=mid-1;
            }
            if(found==-1) continue;
            int end=found;

            ans=max(ans,prefix[end+1]-prefix[start]);
        }

        for(int rightThenReturn=k/2;rightThenReturn>=0;rightThenReturn--){
            int leftMost=startPos-(k-2*rightThenReturn);
            int rightMost=startPos+rightThenReturn;

            int left=0;
            int right=fruits.size()-1;
            int found=-1;

            while(left<=right){
                int mid=left+(right-left)/2;

                if(fruits[mid][0]>=leftMost){
                    right=mid-1;
                    found=mid;
                }else left=mid+1;
            }
            if(found==-1) continue;
            int start=found;

            left=0;
            right=fruits.size()-1;
            found=-1;

            while(left<=right){
                int mid=left+(right-left+1)/2;

                if(fruits[mid][0]<=rightMost){
                    left=mid+1;
                    found=mid;
                }else right=mid-1;
            }
            if(found==-1) continue;
            int end=found;

            ans=max(ans,prefix[end+1]-prefix[start]);
        }

        return ans;
    }
};