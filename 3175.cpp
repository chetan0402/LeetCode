#include<vector>
using namespace std;

class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int wins=0;
        int winner=0;
        for(int i=1;i<skills.size();i++){
            if(skills[i]<skills[winner]) wins++;
            else{
                wins=1;
                winner=i;
            }
            if(wins==k) return winner;
        }

        return winner;
    }
};
