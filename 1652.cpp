#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        if(k==0) return vector<int>(n,0);
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            for(int j=abs(k);j>=1;j--){
                if(k>0) ans[i]+=code[(i+j)%n];
                else ans[i]+=code[((i-j)%n + n)%n];
            }
        }
        return ans;
    }
};