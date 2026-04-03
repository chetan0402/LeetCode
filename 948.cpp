#include<vector>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());

        int ans=0;
        int left=0;
        int right=tokens.size()-1;
        int cur=0;
        while(left<=right){
            if(power>=tokens[left]){
                ans=max(ans,++cur);
                power-=tokens[left++];
            }else if(cur>0){
                power+=tokens[right--];
                cur--;
            }else break;
        }

        return ans;
    }
};
