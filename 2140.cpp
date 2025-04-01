#include<vector>
using namespace std;

class Solution {
    public:
        long long mostPoints(vector<vector<int>>& questions) {
            auto n=questions.size();
            vector<long long> memo(n,-1);
            auto dp=[&](auto&&self,int i)->long long{
                if(i>=n) return 0;
                if(memo[i]!=-1) return memo[i];
                long long doQuestion=questions[i][0]+self(self,i+questions[i][1]+1);
                long long skipQuestion=self(self,i+1);
                return memo[i]=max(doQuestion,skipQuestion);
            };
            long long maxPoints=0;
            for(int i=0;i<n;i++) maxPoints=max(maxPoints,dp(dp,i));
            return maxPoints;
        }
    };