#include<string>
#include<vector>
using namespace std;

class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            string ans="";
            if(strs.size()==0) return "";
            int index=0;
            for(int i=0;i<strs[0].size();i++){
                auto c=strs[0][index];
                for(auto&str:strs) if(index==str.size() || str[index]!=c) return ans;
                index++;
                ans.push_back(c);
            }
            return ans;
        }
    };