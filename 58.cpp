#include<string>
using namespace std;

class Solution {
    public:
        int lengthOfLastWord(string s) {
            int end=s.size()-1;
            while(s[end]==' ') end--;
            int i=end;
            while(i>=0 && s[i]!=' ') i--;
            return end-i;
        }
    };