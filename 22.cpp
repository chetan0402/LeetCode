#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp(2*n,'*');
        auto backtrack=[&](auto&self,int pos,int opened)->void{
            if(pos==temp.size() && opened==0){
                ans.push_back(temp);
                return;
            }
            if(opened>temp.size()-pos) return;
            temp[pos]='(';
            self(self,pos+1,opened+1);
            if(opened){
                temp[pos]=')';
                self(self,pos+1,opened-1);
            }
        };

        backtrack(backtrack,0,0);

        return ans;
    }
};