#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        auto cmp=[](pair<int,int> a,pair<int,int> b)->bool{
            if(a.first!=b.first) return a.first>b.first;
            return a.second<b.second;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> q(cmp);
        q.push({0,1});

        auto numToIndex=[&](int num)->pair<int,int>{
            int row=(num-1)/n;
            int col=(num-1)%n;
            int rowParity=row%2;
            // 0 means left to right, 1 means right to left;
            if(rowParity){
                return {n-1-row,n-1-col};
            }else{
                return {n-1-row,col};
            }
        };

        vector<bool> vis(n*n+1,false);
        vis[1]=true;

        while(q.size()){
            auto [turns, pos]=q.top();
            q.pop();
            if(pos==n*n) return turns;
            int maxReach=min(pos+6,n*n);
            for(int i=pos+1;i<=maxReach;i++){
                auto [x,y]=numToIndex(i);
                int nextPos=(board[x][y]==-1)?i:board[x][y];
                if(!vis[nextPos]){
                    q.push({turns+1,nextPos});
                    vis[nextPos]=true;
                }
            }
        }

        return -1;
    }
};