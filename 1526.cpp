#include<vector>
using namespace std;

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans=target[0];
        for(int i=0;i+1<target.size();i++) ans+=max(target[i+1]-target[i],0);
        return ans;
    }
};