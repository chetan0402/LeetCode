#include<string>
class Solution {
public:
    int addMinimum(string word) {
        int ans=0;
        int i=0;
        int n=word.size();
        int j=0;
        while(i<n){
            if(word[i]=='a'+j) i++;
            else ans++;
            j=(j+1)%3;
        }
        if(j==1) ans+=2;
        if(j==2) ans++;
        return ans;
    }
};
