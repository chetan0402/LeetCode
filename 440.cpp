#include<algorithm>
using namespace std;

class Solution {
    int steps(int n,long p1,long p2){
        int steps=0;
        while(p1<=n){
            steps+=min((long)(n+1),p2)-p1;
            p1*=10;
            p2*=10;
        }
        return steps;
    }
public:
    int findKthNumber(int n, int k) {
        int cur=1;
        k--;

        while(k>0){
            int step=steps(n,cur,cur+1);
            if(step<=k){
                cur++;
                k-=step;
            }else{
                cur*=10;
                k--;
            }
        }

        return cur;
    }
};