#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>

using namespace std;

const vector<vector<int>> dirs={{1,3},{0,2,4},{1,5},{0,4},{3,5,1},{4,2}};

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string init;
        for(int i=0;i<2;i++) for(int j=0;j<3;j++) init+=('0'+board[i][j]);
        unordered_map<string,int> visited;
        dfs(init,visited,init.find('0'),0);
        return visited.count("123450") ? visited["123450"] : -1;
    }

    void dfs(string state,unordered_map<string,int>&visited,int zeroPos,int moves){
        if(visited.count(state) && visited[state]<=moves) return;
        visited[state]=moves;
        for(int dir:dirs[zeroPos]){
            swap(state[zeroPos],state[dir]);
            dfs(state,visited,dir,moves+1);
            swap(state[zeroPos],state[dir]);
        }
    }
};