#include<vector>
using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n=apple.size();
        int m=capacity.size();

        int sum=0;
        for(auto a:apple) sum+=a;

        sort(capacity.begin(),capacity.end());

        int ans=0;
        for(int i=m-1;i>=0;i--){
            if(sum<=0) break;
            sum-=capacity[i];
            ans++;
        }

        return ans;
    }
};
