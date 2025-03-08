#include<string>
using namespace std;

class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            auto n=blocks.size();
            int start=0;
            int end=0;
            int current=0;
            while(end<k) if(blocks[end++]=='W') current++;
            int ans=current;
            while(end<n){
                if(blocks[start]=='W') current--;
                if(blocks[end]=='W') current++;
                ans=min(ans,current);
                start++;
                end++;
            }
            return ans;
        }
    };