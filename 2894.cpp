class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sumDiv=0;
        for(int i=m;i<=n;i++) if(i%m==0) sumDiv+=i;
        int sumTotal=n*(n+1)/2;
        return sumTotal-(2*sumDiv);
    }
};