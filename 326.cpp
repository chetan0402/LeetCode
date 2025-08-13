#include<cmath>

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        int log_=round(log(n)/log(3));
        return (round(pow(3,log_)) == n);
    }
};