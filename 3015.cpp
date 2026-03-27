#include<vector>
#include<queue>

class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        x--;y--;
        vector<vector<int>> cost(n,vector<int>(n,1e5));
        for(int i=0;i<n;i++) cost[i][i]=0;

        for(int i=0;i<n;i++){
            queue<int> q;
            q.push(i);

            while(q.size()){
                int u=q.front();q.pop();
                if(u!=n-1 && cost[i][u+1]>=1e5){
                    cost[i][u+1]=cost[i][u]+1;
                    q.push(u+1);
                }
                if(u!=0 && cost[i][u-1]>=1e5){
                    cost[i][u-1]=cost[i][u]+1;
                    q.push(u-1);
                }
                if(u==x && cost[i][y]>=1e5){
                    cost[i][y]=cost[i][u]+1;
                    q.push(y);
                }
                if(u==y && cost[i][x]>=1e5){
                    cost[i][x]=cost[i][u]+1;
                    q.push(x);
                }
            }
        }

        vector<int> ans(n,0);
        for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        ans[cost[i][j]-1]+=2;

        return ans;
    }
};
