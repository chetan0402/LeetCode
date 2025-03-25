#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    bool directionalCheck(vector<vector<int>>&rects,int dimensionIdx){
        sort(rects.begin(),rects.end(),
        [dimensionIdx](vector<int>&a,vector<int>&b){
            return a[dimensionIdx]<b[dimensionIdx];
            });
        int end=rects[0][dimensionIdx+2];
        int gaps=0;
        for(int i=1;i<rects.size();i++){
            if(rects[i][dimensionIdx]>=end){
                if(++gaps==2) return true;
            }
            end=max(end,rects[i][dimensionIdx+2]);
        }
        return false;
    }
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return directionalCheck(rectangles,0) || directionalCheck(rectangles,1);
    }
};