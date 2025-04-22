#include<string.h>
using namespace std;
const int MOD=1e9+7;

class Solution {
    long long count[15][10005];
    long long prefix[15][10005];
    long long options[15];
    void uniqueSeq(int cur,int idx,int&maxVal){
        options[idx]+=1;
        for(int j=2;cur*j<=maxVal;j++) uniqueSeq(cur*j,idx+1,maxVal);
    }
public:
    int idealArrays(int n, int maxValue) {
        memset(count,0,sizeof(count));
        memset(prefix,0,sizeof(prefix));
        memset(options,0,sizeof(options));

        for(int i=1;i<=10000;i++){
            count[1][i]=1;
            prefix[1][i]=i;
        }

        for(int i=2;i<=14;i++){
            for(int j=i;j<=10000;j++){
                count[i][j]=prefix[i-1][j-1];
                prefix[i][j]=prefix[i][j-1]+count[i][j];
                count[i][j]%=MOD;
                prefix[i][j]%=MOD;
            }
        }

        for(int i=1;i<=maxValue;i++) uniqueSeq(i,1,maxValue);

        long long ans=0;
        for(int i=1;i<=14;i++){
            long long option=count[i][n]*options[i];
            option%=MOD;
            ans+=option;
            ans%=MOD;
        }
        return ans;
    }
};