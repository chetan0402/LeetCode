class Solution {
public:
    int countTriples(int n) {
        int ans=0;
        for(int i=1;i<=n;i++) for(int j=i;j<=n;j++){
            int c2=i*i + j*j;
            if(c2>n*n) break;
            int c=sqrt(c2);
            if(c*c == c2) ans+=(1+(i!=j));
        }
        return ans;
    }
};
