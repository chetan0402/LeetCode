#include<string>
using namespace std;

class Solution {
public:
    int countCollisions(string directions) {
        while(directions.size() && directions.back()=='R') directions.pop_back();

        int i=0;
        int n=directions.size();

        for(;i<n;i++) if(directions[i]!='L') break;

        int ans=0;

        for(;i<n;i++) if(directions[i]!='S') ans++;

        return ans;
    }
};
