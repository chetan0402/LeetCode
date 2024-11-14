#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        return bs(0,*max_element(quantities.begin(),quantities.end()),n,quantities);
    }

    int bs(int low,int high,int n,vector<int>&quantities){
        while(low<high){
            int mid=low+(high-low)/2;
            if(can(mid,n,quantities)){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        return low;
    }

    bool can(int k,int n,vector<int> quantities){
        int quan=0;
        for(int i=0;i<n;i++){
            if(quantities[quan]<=k){
                quan++;
            }else quantities[quan]-=k;
            if(quan==quantities.size()) return true;
        }
        return false;
    }
};