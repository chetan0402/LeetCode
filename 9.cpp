#include<string>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string temp=to_string(x);
        int n=temp.size();
        for(int i=0;i<=n/2;i++) if(temp[i]!=temp[n-i-1]) return false;
        return true;
    }
};