#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int maxDifference(string s, int k) {
        auto getStatus=[](int a,int b)->int{
            return ((a&1)<<1) | (b&1);
        };

        int n=s.size();
        int ans=INT_MIN;

        for(auto a='0';a<='4';a++) for(auto b='0';b<='4';b++) if(a!=b){
            vector<int> score(4,INT_MAX);
            int cnt_a=0,cnt_b=0;
            int prev_a=0,prev_b=0;
            int left=-1;
            for(int right=0;right<n;right++){
                cnt_a+=(s[right]==a);
                cnt_b+=(s[right]==b);
                while(right-left>=k && cnt_b-prev_b>=2){
                    int leftStatus=getStatus(prev_a,prev_b);
                    score[leftStatus]=min(score[leftStatus],prev_a-prev_b);
                    left++;
                    prev_a+=(s[left]==a);
                    prev_b+=(s[left]==b);
                }
                int rightStatus=getStatus(cnt_a,cnt_b);
                if((score[rightStatus^2]) != INT_MAX) ans=max(ans,cnt_a-cnt_b-(score[rightStatus^2]));
            }
        }
        return ans;
    }
};