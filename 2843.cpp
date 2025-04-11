#include<string>
using namespace std;

class Solution {
    bool valid(string s){
        auto n=s.size();
        if(n%2) return false;
        return hash(s.substr(0,n/2))==hash(s.substr(n/2,n/2));
    }
    int hash(string s){
        int ans=0;
        for(auto c:s) ans+=c;
        return ans;
    }
public:
    int countSymmetricIntegers(int low, int high) {
        int ans=0;
        for(int i=low;i<=high;i++) if(valid(to_string(i))) ans++;
        return ans;
    }
};