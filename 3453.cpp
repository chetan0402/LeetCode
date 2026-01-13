#include<vector>
using namespace std;

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        auto fn=[&](double y)->bool{
            double above=0;
            double below=0;

            for(auto&s:squares){
                above+=max(0.0,s[2]*min(1.0*s[2],s[1]+s[2]-y));
                below+=max(0.0,s[2]*min(1.0*s[2],y-s[1]));
            }

            return (above>below);
        };

        double left=0;
        double right=1e9;

        while(right-left>1e-5){
            double mid=left+(right-left)/2;
            if(fn(mid)) left=mid;
            else right=mid;
        }

        return left;
    }
};