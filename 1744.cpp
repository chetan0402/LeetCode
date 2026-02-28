#include<vector>
using namespace std;

#define ll long long

class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        vector<pair<ll,ll>> prefix;
        prefix.reserve(candiesCount.size());
        prefix.push_back({1,candiesCount[0]});

        for(int i=1;i<candiesCount.size();i++)
        prefix.push_back(
            {prefix.back().second+1,
            prefix.back().second+candiesCount[i]}
        );

        vector<bool> ans;

        for(auto&q:queries){
            int favType=q[0];
            int favDay=q[1]+1;
            int dailyCap=q[2];

            ans.push_back(
                ((prefix[favType].first/(1.0*dailyCap)) <= favDay) &
                (prefix[favType].second/(1.0*favDay) >= 1)
            );
        }

        return ans;
    }
};
