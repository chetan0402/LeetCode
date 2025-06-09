#include<vector>
#include<string>
using namespace std;

const vector<vector<char>> mapping={
    {'a','b','c'},
    {'d','e','f'},
    {'g','h','i'},
    {'j','k','l'},
    {'m','n','o'},
    {'p','q','r','s'},
    {'t','u','v'},
    {'w','x','y','z'}
};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0) return ans;
        
        auto backtrack=[&](auto&self,int pos,string temp){
            if(pos==digits.size()){
                ans.emplace_back(temp);
                return;
            };
            for(auto chr:mapping[digits[pos]-'2']){
                temp.push_back(chr);
                self(self,pos+1,temp);
                temp.pop_back();
            }
        };

        backtrack(backtrack,0,"");

        return ans;
    }
};