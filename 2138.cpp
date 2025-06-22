#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n=s.size();
        vector<string> ans;
        for(int i=0;i<n;i+=k){
            string toAdd=s.substr(i,k);
            toAdd.resize(k,fill);
            ans.push_back(toAdd);
        }
        return ans;
    }
};