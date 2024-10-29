#include<vector>

using namespace std;

class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        for(int i=2;i<=n-2;i++){
            if(!padlinBase(n,i)) return false;
        }
        return true;
    }

    bool padlinBase(int num,int base){
        vector<int> baseNum;
        while(num){
            baseNum.push_back(num%base);
            num/=base;
        }
        int n=baseNum.size();
        for(int i=0;i<n/2;i++){
            if(baseNum[i]!=baseNum[n-i-1]) return false;
        }
        return true;
    }
};