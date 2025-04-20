#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            unordered_map<int,int> cnt;
            for(auto ans:answers) cnt[ans]++;
            int ans=0;
            for(auto [key,value]:cnt){
                int num=value/(key+1);
                if(value%(key+1)) num++;
                ans+=(num*(key+1));
            }
            return ans;
        }
    };