#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return arr[0];
        if(n==2) return max({arr[0]+arr[1],arr[0],arr[1]});

        vector<int> left(n);
        left[0]=arr[0];

        for(int i=1;i<n;i++) left[i]=arr[i]+max(0,left[i-1]);

        vector<int> right(n);
        right[n-1]=arr[n-1];

        for(int i=n-2;i>=0;i--) right[i]=arr[i]+max(0,right[i+1]);

        int ans=INT_MIN;

        for(int i=0;i<n;i++){
            ans=max(ans,left[i]);
            ans=max(ans,right[i]);
        }

        for(int i=1;i<n-1;i++){
            ans=max(ans,left[i-1]+right[i+1]);
            ans=max(ans,left[i-1]+arr[i]+right[i+1]);
        }

        return ans;
    }
};