#include<vector>
using namespace std;

class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            auto n=colors.size();
            int cur=0;
            int ans=0;
            for(int i=0;i<n+k-1;i++){
                if(colors[i%n]==colors[(i+1)%n]){
                    if(cur>=k-1) ans+=cur-k+2;
                    cur=0;
                    continue;
                }
                cur++;
            }
            if(cur>=k-1) ans+=cur-k+1;
            return ans;
        }
    };