#include<vector>
using namespace std;

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        int k=k1+k2;
        vector<int> freq;
        for(int i=0;i<n;i++){
            int diff=abs(nums1[i]-nums2[i]);
            if(diff>=freq.size()) freq.resize(diff+1,0);
            freq[diff]++;
        }

        for(int i=freq.size()-1;i>0;i--) if(freq[i]){
            if(k<=freq[i]){
                freq[i]-=k;
                freq[i-1]+=k;
                break;
            }
            freq[i-1]+=freq[i];
            k-=freq[i];
            freq[i]=0;
        }

        auto ans=0LL;
        for(int i=0;i<freq.size();i++) ans+=1LL*i*i*freq[i];
        return ans;
    }
};
