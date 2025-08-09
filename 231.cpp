#include<cmath>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        double log_=log2(n);
        return (int(log_)==log_);
    }
};