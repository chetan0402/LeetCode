#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans={{1}};

        for(int i=1;i<numRows;i++){
            vector<int> temp(ans.back().size()+1,1);
            for(int j=1;j<temp.size()-1;j++){
                temp[j]=ans[i-1][j-1]+ans[i-1][j];
            }
            ans.push_back(temp);
        }

        return ans;
    }
};