#include<vector>
using namespace std;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ans=0;

        vector<bool> occupied(baskets.size(),false);

        int start=0;

        for(auto fruit:fruits){
            bool placed=false;
            while(start<baskets.size() && occupied[start]) start++;
            for(int i=start;i<baskets.size();i++) if(!occupied[i] && baskets[i]>=fruit){
                occupied[i]=true;
                placed=true;
                break;
            }
            if(!placed) ans++;
        }

        return ans;
    }
};