#include<vector>
using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> r(k,0);
        for(int i=0;i<arr.size();i++) r[(k+(arr[i]%k))%k]++;
        for(int i=1;i<=k/2;i++) if(r[i]!=r[k-i]) return false;
        if(r[0]%2) return false;

        return true;
    }
};
