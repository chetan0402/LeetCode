const int MOD=1e9+7;
const int MX=1e5;

long long fact[MX];
long long inv_fact[MX];

class Solution {
    long long nCr(int n, int r) {
        return fact[n]*inv_fact[r]%MOD * inv_fact[n-r]%MOD;
    }

    long long modpow(long long base,long long expo){
        base%=MOD;
        long long result=1;
        while(expo>0){
            if(expo&1) result=(result*base)%MOD;
            base=(base*base)%MOD;
            expo>>=1;
        }
        return result;
    }

    void init(){
        if(fact[0]) return;
        fact[0]=1;
        for(int i=1;i<MX;i++) fact[i]=fact[i-1]*i%MOD;
        inv_fact[MX-1]=modpow(fact[MX-1],MOD-2);
        for(int i=MX-1;i;i--){
            inv_fact[i-1]=inv_fact[i]*i%MOD;
        }
    }
public:
    int countGoodArrays(int n, int m, int k) {
        init();
        long long ans=nCr(n-1,k);
        ans%=MOD;

        ans*=m;
        ans%=MOD;

        ans*=modpow(m-1,n-k-1);
        ans%=MOD;

        return ans;
    }
};