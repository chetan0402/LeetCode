#include<vector>
#include<algorithm>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int maxKey=0;
        sort(items.begin(),items.end());
        map<int,int> apparant_best;
        apparant_best[0]=0;
        for(auto item:items){
            map<int,int>::iterator it=apparant_best.lower_bound(item[0]);
            --it;
            apparant_best[item[0]]=max({apparant_best[item[0]],item[1],it->second});
            maxKey=max(maxKey,item[0]);
        }
        vector<int> ans(queries.size());
        for(int i=0;i<queries.size();i++){
            ans[i]=(--apparant_best.upper_bound(queries[i]))->second;
        }
        return ans;
    }
};