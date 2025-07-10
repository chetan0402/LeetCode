class Solution {
public:
    int integerReplacement(long long n) {
        int ans=0;
        while(n!=1){
            if(n%2){
                if(n!=3 && (n+1)%4==0) n++;
                else n--;
            }
            else n/=2;
            ans++;
        }

        return ans;
    }
};