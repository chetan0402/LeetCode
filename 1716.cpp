class Solution {
public:
    int totalMoney(int n) {
        int ans=(n/7)*(28+28+(n/7 - 1)*7)/2;
        for(int i=0;i<n%7;i++) ans+=1+(n/7)+i;
        return ans;
    }
};