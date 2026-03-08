#include<string>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        if(n==1) return 0;
        if(n==2){
            if(s[0]<=s[1]) return 0;
            else return -1;
        }

        int minI=0;
        int maxI=0;
        bool sorted=true;
        for(int i=1;i<n;i++){
            if(s[minI]>s[i]) minI=i;
            if(s[maxI]<=s[i]) maxI=i;
            if(s[i-1]>s[i]) sorted=false;
        }

        if(sorted) return 0;

        if(minI==0 | maxI==n-1) return 1;
        if(minI==n-1 & maxI==0) return 3;
        return 2;
    }
};
