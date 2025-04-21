#include<vector>
using namespace std;
class Solution {
    public:
        int numberOfArrays(vector<int>& differences, int lower, int upper) {
            long long cur=0;
            long long lowerBound=0;
            long long upperBound=0;
            for(int i=0;i<differences.size();i++){
                cur+=differences[i];
                lowerBound=min(lowerBound,cur);
                upperBound=max(upperBound,cur);
            }
            int ans=(upper-lower)-(upperBound-lowerBound)+1;
            return ((ans<=0)?0:ans);
        }
    };