#include<vector>
using namespace std;

// neighbor = ni
// alive
// ni<2 => ded
// ni==2,3 => no chance
// ni>3 => ded
// dead
// ni==3, ded->liv

int DED_TO_LIV=2;
int LIV_TO_DED=3;

bool alive(int i){ return (i==1 || i==LIV_TO_DED); }
bool dead(int i){ return (i==0 || i==DED_TO_LIV); }

const vector<pair<int,int>> dirs={{1,0},{1,1},{0,1},{-1,0},{-1,-1},{0,-1},{1,-1},{-1,1}};

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        auto n=board.size();
        auto m=board[0].size();
        for(int i=0;i<n;i++) for(int j=0;j<m;j++){
            int ni=0;
            for(auto [dx,dy]:dirs)
            if(i+dx>=0 && i+dx<n && j+dy>=0 && j+dy<m && alive(board[i+dx][j+dy])) ni++;
            if(alive(board[i][j])){
                if(ni<2 || ni>3) board[i][j]=LIV_TO_DED;
            }else if(ni==3) board[i][j]=DED_TO_LIV;
        }
        for(int i=0;i<n;i++) for(int j=0;j<m;j++){
            if(board[i][j]==LIV_TO_DED) board[i][j]=0;
            if(board[i][j]==DED_TO_LIV) board[i][j]=1;
        }
    }
};