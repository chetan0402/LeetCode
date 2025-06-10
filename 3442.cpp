#include<vector>
#include<string>
#include<climits>
using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        vector<int> cnt(26,0);
        for(auto c:s) cnt[c-'a']++;

        int maxOdd=0;
        int minEven=INT_MAX;

        for(int i=0;i<26;i++) if(cnt[i]>0) {
        if(cnt[i]%2) maxOdd=max(maxOdd,cnt[i]);
        else minEven=min(minEven,cnt[i]);
        }

        return maxOdd-minEven;
    }
};