#include<vector>
using namespace std;

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        auto side=0;
        int n=bottomLeft.size();
        for(int i=0;i<n;i++) for(int j=i+1;j<n;j++){
            int w=min(topRight[i][0],topRight[j][0])-max(bottomLeft[i][0],bottomLeft[j][0]);
            int h=min(topRight[i][1],topRight[j][1])-max(bottomLeft[i][1],bottomLeft[j][1]);
            side=max(side,min(w,h));
        }

        return 1LL*side*side;
    }
};
