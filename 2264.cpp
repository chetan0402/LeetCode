#include<string>
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        string ans="";
        for(int i=0;i+2<=num.size();i++){
            string temp=num.substr(i,3);
            if(temp[0]==temp[1] && temp[1]==temp[2]) ans=max(ans,temp);
        }
        return ans;
    }
};