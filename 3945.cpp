#include<vector>
using namespace std;

class Solution {
public:
    int digitFrequencyScore(int n) {
        vector<int> freq(10,0);

        int temp_n=n;
        while(temp_n){
            freq[temp_n%10]++;
            temp_n/=10;
        }

        int ans=0;
        for(int i=1;i<=9;i++) ans+=(i*freq[i]);
        return ans;
    }
};
