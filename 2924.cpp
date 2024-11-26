#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        unordered_map<int,int> visited;
        for(int i=0;i<edges.size();i++) visited[edges[i][1]]=1;
        int winner=-1;
        for(int i=0;i<n;i++){
            if(!visited.count(i)){
                if(winner==-1) winner=i;
                else return -1;
            }
        }
        return winner;
    }
};