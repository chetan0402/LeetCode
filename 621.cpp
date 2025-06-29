#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0) return tasks.size();
        vector<int> freq(26,0);
        for(auto task:tasks) freq[task-'A']++;

        sort(freq.begin(),freq.end());

        int maxFreq=freq[25]-1;

        int idleSlots=maxFreq*n;

        for(int i=24;i>=0 and freq[i]>0;i--){
            idleSlots-=min(maxFreq,freq[i]);
        }

        return tasks.size()+max(0,idleSlots);
    }
};