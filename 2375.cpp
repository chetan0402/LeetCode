#include<string>
#include<algorithm>
using namespace std;

class Solution {
    bool valid(string&ans,string&rule){
        for(int i=0;i<rule.size();i++){
            if(rule[i]=='I'){
                if(ans[i]>ans[i+1]) return false;
            }else if(ans[i]<ans[i+1]) return false;
        }
        return true;
    }
public:
    string smallestNumber(string pattern) {
        string perm;
        for(int i=1;i<=pattern.size()+1;i++) perm.push_back(i+'0');
        while(!valid(perm,pattern)) next_permutation(perm.begin(),perm.end());
        return perm;
    }
};