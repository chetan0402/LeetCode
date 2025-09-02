#include<vector>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n=points.size();

        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                auto x1=points[i][0],y1=points[i][1];
                auto x2=points[j][0],y2=points[j][1];

                if((x1<=x2 && y1>=y2) || (x2<=x1 && y2>=y1)){
                    int top=max(y1,y2);
                    int bottom=min(y1,y2);
                    int left=min(x1,x2);
                    int right=max(x1,x2);
                    bool valid=true;
                    for(int k=0;k<n and valid;k++){
                        if(k==i || k==j) continue;

                        auto x3=points[k][0],y3=points[k][1];

                        if(left<=x3 && x3<=right && bottom<=y3 && y3<=top) valid=false;
                    }
                    if(valid) ans++;
                }
            }
        }

        return ans;
    }
};