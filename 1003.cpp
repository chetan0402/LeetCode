#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool isValid(string str) {
        vector<char> s;

        for(auto c:str){
            if(c=='c'){
                if(s.size()>=2 && (s[s.size()-1]=='b' & s[s.size()-2]=='a')){
                    s.pop_back();
                    s.pop_back();
                }else s.push_back(c);
            }else s.push_back(c);
        }

        return (s.size()==0);
    }
};
