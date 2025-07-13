#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());

        int n=players.size();
        int m=trainers.size();

        int ans=0;

        int ptr1=n-1;
        int ptr2=m-1;

        while(ptr1>=0 && ptr2>=0){
            if(trainers[ptr2]>=players[ptr1]){
                ans++;
                ptr1--;
                ptr2--;
            }else ptr1--;
        }

        return ans;
    }
};