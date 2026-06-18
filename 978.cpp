#include<vector>
using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return 1;

        bool prevSign=arr[0]<arr[1];
        int ans,prev;
        ans=prev=(arr[0]==arr[1])?1:2;

        for(int i=1;i+1<n;i++){
            if(arr[i]==arr[i+1]){
                prev=1;
                continue;
            }
            if(prevSign){
                if(arr[i]>arr[i+1]){
                    prev++;
                    prevSign=false;
                }else prev=2;
            }else{
                if(arr[i]<arr[i+1]){
                    prev++;
                    prevSign=true;
                }else prev=2;
            }
            ans=max(ans,prev);
        }

        return ans;
    }
};
