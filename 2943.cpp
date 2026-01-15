#include<vector>
using namespace std;

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());

        int curH=1;
        int maxH=1;
        for(int i=1;i<hBars.size();i++)
        if(hBars[i-1]+1==hBars[i]) maxH=max(maxH,++curH);
        else curH=1;

        int curV=1;
        int maxV=1;
        for(int i=1;i<vBars.size();i++)
        if(vBars[i-1]+1==vBars[i]) maxV=max(maxV,++curV);
        else curV=1;

        auto side=1+min(maxH,maxV);
        return side*side;
    }
};
