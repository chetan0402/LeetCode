#include<vector>
using namespace std;

class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int n=flips.size();
        vector<bool> found(n+10,false);
        found[0]=true;
        int mex=1;
        int ans=0;
        for(int i=0;i<n;i++){
            found[flips[i]]=true;
            while(found[mex]) mex++;
            if(i+2==mex) ans++;
        }
        return ans;
    }
};
