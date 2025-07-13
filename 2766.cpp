#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_map<int,int> freq;

        for(auto num:nums) freq[num]++;

        int n=moveFrom.size();

        for(int i=0;i<n;i++){
            auto marbles=freq[moveFrom[i]];
            freq.erase(moveFrom[i]);
            freq[moveTo[i]]+=marbles;
        }

        vector<int> ans;

        for(auto [pos, _]:freq) ans.push_back(pos);

        sort(ans.begin(),ans.end());

        return ans;
    }
};