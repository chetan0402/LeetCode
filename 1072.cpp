#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> info;
        for(const auto&row:matrix){
            string key="";
            for(int i=0;i<row.size();i++){
                if(row[0]==row[i]) key+='0';
                else key+='1';
            }
            info[key]++;
        }
        int maxF=0;
        for(auto&i:info){
            maxF=max(maxF,i.second);
        }
        return maxF;
    }
};