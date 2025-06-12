#include<vector>
#include<string>
using namespace std;

const vector<pair<int,int>> dirs={{1,0},{0,1},{-1,0},{0,-1}};

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));

        auto backtrack=[&](auto&self,int x,int y,int pos)->bool{
            if(pos==word.size()) return true;
            if(x<0 || x>=n || y<0 || y>=m) return false;
            if(vis[x][y]) return false;
            if(board[x][y]!=word[pos]) return false;
            vis[x][y]=true;
            for(auto [dx,dy]:dirs) if(self(self,x+dx,y+dy,pos+1)) return true;
            vis[x][y]=false;
            return false;
        };

        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(board[i][j]==word[0]){
            if(backtrack(backtrack,i,j,0)) return true;
        }

        return false;
    }
};