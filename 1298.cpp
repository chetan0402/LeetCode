#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n=status.size();
        int ans=0;
        vector<bool> canOpen(n,false), hasBox(n,false), used(n,false);
        
        for(int i=0;i<n;i++) canOpen[i]=status[i];

        queue<int> q;
        for(auto box:initialBoxes){
            hasBox[box]=true;
            if(canOpen[box]){
                q.push(box);
                used[box]=true;
                ans+=candies[box];
            }
        }

        while(q.size()){
            auto curBox=q.front();
            q.pop();

            for(auto key:keys[curBox]){
                canOpen[key]=true;
                if(!used[key]  && hasBox[key]){
                    q.push(key);
                    used[key]=true;
                    ans+=candies[key];
                }
            }

            for(auto box:containedBoxes[curBox]){
                hasBox[box]=true;
                if(!used[box] && canOpen[box]){
                    q.push(box);
                    used[box]=true;
                    ans+=candies[box];
                }
            }
        }

        return ans;
    }
};