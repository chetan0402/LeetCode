#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int minDiff=__INT32_MAX__;
        vector<vector<int>> ans;
        int n=arr.size();
        for(int i=0;i<n-1;i++){
            int j=i+1;
            int curDiff=abs(arr[i]-arr[j]);
            if(curDiff<minDiff){
                minDiff=curDiff;
                ans.clear();
                ans.push_back(vector<int>{min(arr[i],arr[j]),max(arr[i],arr[j])});
            }else if(curDiff==minDiff){
                ans.push_back(vector<int>{min(arr[i],arr[j]),max(arr[i],arr[j])});
            }
        }
        return ans;
    }
};