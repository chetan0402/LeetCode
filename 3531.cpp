#include<vector>
using namespace std;

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> firstInRow(n,n);
        vector<int> lastInRow(n,-1);
        vector<int> firstInCol(n,n);
        vector<int> lastInCol(n,-1);
        
        for(auto&building:buildings){
            auto x=building[0]-1;
            auto y=building[1]-1;
            firstInRow[y]=min(firstInRow[y],x);
            lastInRow[y]=max(lastInRow[y],x);
            firstInCol[x]=min(firstInCol[x],y);
            lastInCol[x]=max(lastInCol[x],y);
        }

        int ans=0;

        for(auto&building:buildings){
            auto x=building[0]-1;
            auto y=building[1]-1;

            int left=firstInRow[y];
            int right=lastInRow[y];
            int top=firstInCol[x];
            int bottom=lastInCol[x];

            if(left<x && x<right && top<y && y<bottom) ans++;
        }

        return ans;
    }
};
