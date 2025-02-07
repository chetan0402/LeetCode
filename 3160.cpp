#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> num_to_color;
        unordered_map<int,int> freq;
        int distinct=0;
        vector<int> ans;
        for(auto q:queries){
            auto num=q[0];
            auto color=q[1];
            if(num_to_color[num]!=0){
                auto old_color=num_to_color[num];
                if(freq[old_color]==1) distinct--;
                freq[old_color]--;
            }
            num_to_color[num]=color;
            if(freq[color]==0) distinct++;
            freq[color]++;
            ans.push_back(distinct);
        }
        return ans;
    }
};