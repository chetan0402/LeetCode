#include<vector>
using namespace std;

class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
            auto n=board.size();
            auto m=board[0].size();
            vector<bool> exists;
            for(int i=0;i<n;i++){
                exists.assign(9,false);
                for(int j=0;j<m;j++){
                    if(board[i][j]=='.') continue;
                    auto num=board[i][j]-'1';
                    if(exists[num]) return false;
                    exists[num]=true;
                }
            }
            for(int j=0;j<m;j++){
                exists.assign(9,false);
                for(int i=0;i<n;i++){
                    if(board[i][j]=='.') continue;
                    auto num=board[i][j]-'1';
                    if(exists[num]) return false;
                    exists[num]=true;
                }
            }
            for(int offsetI=0;offsetI<n;offsetI+=3) for(int offsetJ=0;offsetJ<m;offsetJ+=3){
                exists.assign(9,false);
                for(int i=0;i<3;i++) for(int j=0;j<3;j++){
                    if(board[offsetI+i][offsetJ+j]=='.') continue;
                    auto num=board[offsetI+i][offsetJ+j]-'1';
                    if(exists[num]) return false;
                    exists[num]=true;
                }
            }
            return true;
        }
    };