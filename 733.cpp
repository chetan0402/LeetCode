#include<vector>
#include<queue>
using namespace std;

const vector<pair<int,int>> dirs={{1,0},{0,1},{-1,0},{0,-1}};

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int fromColor=image[sr][sc];
        if(fromColor==color) return image;

        queue<pair<int,int>> q;
        q.push({sr,sc});

        while(q.size()){
            auto [x, y]=q.front();
            q.pop();
            image[x][y]=color;
            for(auto [dx,dy]:dirs){
                int nx=x+dx,ny=y+dy;
                if(nx<0 || nx>=image.size() || ny<0 || ny>=image[0].size()) continue;
                if(image[nx][ny]!=fromColor) continue;
                q.push({nx,ny});
            }
        }

        return image;
    }
};