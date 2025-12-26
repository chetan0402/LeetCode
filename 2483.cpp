#include<string>
using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int totalP=0;
        for(auto s:customers) if(s=='Y') totalP++;

        int ans=0;
        int minP=totalP;
        int curP=totalP;
        int curH=0;

        for(auto s:customers){
            curH++;
            if(s=='Y') curP--;
            if(s=='N') curP++;
            if(curP<minP){
                curP=minP;
                ans=curH;
            }
        }

        return ans;
    }
};
