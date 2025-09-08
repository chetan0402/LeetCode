#include<vector>
using namespace std;

class Solution {
    bool containsZero(int num){
        while(num){
            if(num%10==0) return true;
            num/=10;
        }
        return false;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<n;i++){
            if(containsZero(i)) continue;
            if(containsZero(n-i)) continue;
            return {i,n-i};
        }
        return {-1,-1};
    }
};