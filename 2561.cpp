#include<vector>
#include<unordered_map>
#include<algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int m=INT_MAX;
        unordered_map<int,int> freq;
        for(auto num:basket1){
            freq[num]++;
            m=min(m,num);
        }
        for(auto num:basket2){
            freq[num]--;
            m=min(m,num);
        }

        vector<int> merge;
        for(auto [key, value]:freq){
            if(value%2) return -1;

            for(int i=0;i<abs(value)/2;i++) merge.push_back(key);
        }
        nth_element(merge.begin(),merge.begin()+merge.size()/2,merge.end());
        return accumulate(merge.begin(),merge.begin()+merge.size()/2,0ll,[&](auto res,auto x)->auto{
            return res+min(2*m,x);
        });
    }
};