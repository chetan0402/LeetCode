class Solution {
public:
    double myPow(double x, int n) {
        double result=1;
        long long N=n;
        if(N<0){
            x=1/x;
            N=-N;
        }
        
        while(N){
            if(N%2) result*=x;
            x*=x;
            N>>=1;
        }

        return result;
    }
};