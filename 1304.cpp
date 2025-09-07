#include<vector>
using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        ans.reserve(n);
        if(n%2) ans.push_back(0);
        int num=1;
        while(ans.size()!=n){
            ans.push_back(num);
            ans.push_back(-num);
            num++;
        }
        return ans;
    }
};