#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int metal=0;
        int paper=0;
        int glass=0;

        for(int i=0;i<garbage.size();i++){
            for(auto c:garbage[i]){
                if(c=='M') metal=i;
                if(c=='P') paper=i;
                if(c=='G') glass=i;
            }
        }

        int ans=0;

        for(int i=0;i<=max({metal,paper,glass});i++) ans+=garbage[i].size();

        vector<int> prefixTravel(travel.size());
        prefixTravel[0]=travel[0];
        for(int i=1;i<travel.size();i++) prefixTravel[i]=prefixTravel[i-1]+travel[i];

        if(metal>0) ans+=prefixTravel[metal-1];
        if(paper>0) ans+=prefixTravel[paper-1];
        if(glass>0) ans+=prefixTravel[glass-1];

        return ans;
    }
};