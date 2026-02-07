#include<string>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        int a=0;
        int b=0;
        for(int i=1;i<=n;i++){
            if(s[i-1]=='a') b++;
            else{
                b=min(a,b);
                a++;
            }
        }
        return min(a,b);
    }
};
