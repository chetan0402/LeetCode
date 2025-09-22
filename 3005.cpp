#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> freq;
        int maxFreq=0;
        for(auto num:nums) maxFreq=max(maxFreq,++freq[num]);
        int cnt=0;
        for(auto [_,v]:freq) if(v==maxFreq) cnt++;
        return maxFreq*cnt;
    }
};