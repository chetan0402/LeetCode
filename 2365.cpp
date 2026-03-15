#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int,long long> nextValid;
        long long day=0;
        for(auto task:tasks){
            day++;
            day=max(day,nextValid[task]);
            nextValid[task]=day+space+1;
        }
        return day;
    }
};
