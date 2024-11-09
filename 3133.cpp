class Solution {
public:
    long long minEnd(int n, int x) {
        long long last=x;
        n--;
        while(n--) last=(last+1)|x;
        return last;
    }
};