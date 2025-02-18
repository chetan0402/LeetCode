#include<vector>
using namespace std;

class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            auto n=gas.size();
            int start=0;
            int total=0;
            int cur=0;
            for(int i=0;i<n;i++){
                total+=gas[i]-cost[i];
                cur+=gas[i]-cost[i];
                if(cur<0){
                    cur=0;
                    start=i+1;
                }
            }
            if(total>=0) return start;
            return -1;
        }
    };