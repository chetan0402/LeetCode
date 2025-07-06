#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n);

        stack<int> s;

        for(int i=0;i<n;i++){
            while(s.size() && temperatures[s.top()]<temperatures[i]){
                auto set=s.top();s.pop();
                ans[set]=i-set;
            }
            s.push(i);
        }

        return ans;
    }
};