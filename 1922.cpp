const int MOD=1e9+7;

class Solution {
    long long expoMod(long long base,long long expo){
        int result=1;
        while(expo>0){
            if(expo%2==1) result=(result*base)%MOD;
            base=(base*base)%MOD;
            expo/=2;
        }
        return result;
    }
public:
    int countGoodNumbers(long long n) {
        return (expoMod(5,(n+1)/2)*expoMod(4,n/2))%MOD;
    }
};