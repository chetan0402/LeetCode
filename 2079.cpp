#include<vector>
using namespace std;

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int ans=plants.size();

        int cur=capacity;
        for(int i=0;i<plants.size();i++){
            if(plants[i]>cur){
                ans+=2*i;
                cur=capacity;
            }
            cur-=plants[i];
        }

        return ans;
    }
};