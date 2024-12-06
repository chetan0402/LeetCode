#include<unordered_set>
#include<vector>

using namespace std;

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> ban(banned.begin(),banned.end());
        int count=0;
        for(int i=1;i<=n;i++){
            if(ban.find(i)!=ban.end()) continue;
            maxSum-=i;
            if(maxSum<0) break;
            count++;
        }
        return count;
    }
};