class Solution {
public:
    int smallestNumber(int n) {
        int tmp=n;
        int power=0;
        while(tmp){
            if((n&(1<<power))==0) n|=(1<<power);
            tmp>>=1;
            power++;
        }
        return n;
    }
};