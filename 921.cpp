#include<string>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0;
        int cur=0;
        for(auto c:s){
            if(c=='(') cur++;
            else{
                if(cur) cur--;
                else ans++;
            }
        }
        ans+=cur;
        return ans;
    }
};
