#include<vector>
using namespace std;

class Solution {
    bool valid(int num){
        vector<int> cnt(10,0);
        while(num){
            cnt[num%10]++;
            num/=10;
        }
        for(int i=0;i<10;i++) if(cnt[i]>0 && cnt[i]!=i) return false;
        return true;
    }
public:
    int nextBeautifulNumber(int n) {
        n++;
        while(!valid(n)) n++;
        return n;
    }
};