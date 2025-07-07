#include<vector>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for(auto asteroid:asteroids){
            if(asteroid>0) ans.push_back(asteroid);
            else{
                bool insert=true;
                while(insert && ans.size() && ans.back()>0){
                    if(ans.back()<-asteroid) ans.pop_back();
                    else if(ans.back()==-asteroid){
                        ans.pop_back();
                        insert=false;
                    }else{
                        insert=false;
                    }
                }
                if(insert) ans.push_back(asteroid);
            }
        }

        return ans;
    }
};