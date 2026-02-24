#include<vector>
using namespace std;

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int winner=0;
        int wins=0;
        for(int i=1;i<arr.size();i++){
            if(arr[i]<arr[winner]) wins++;
            else{
                winner=i;
                wins=1;
            }
            if(wins==k) return arr[winner];
        }

        return arr[winner];
    }
};
