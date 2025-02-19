#include<string>
#include<unordered_map>
using namespace std;

unordered_map<char,int> romToI = {
    {'I',1},
    {'V',5},
    {'X',10},
    {'L',50},
    {'C',100},
    {'D',500},
    {'M',1000}
};
unordered_map<char,char> backAllow = {
    {'V','I'},
    {'X','I'},
    {'L','X'},
    {'C','X'},
    {'D','C'},
    {'M','C'}
};

class Solution {
public:
int romanToInt(string s) {
    int ans=0;
    auto n=s.size();
    char prev=NULL;
    for(int i=0;i<n;i++){
        ans+=romToI[s[i]];
        if(prev==backAllow[s[i]]) ans-=2*romToI[prev];
        prev=s[i];
    }
    return ans;
}
};