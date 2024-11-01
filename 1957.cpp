#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        char prev='\0';
        char prevprev='\0';
        for(auto c:s){
            if(prev==prevprev && prev==c) continue;
            swap(prevprev,prev);
            prev=c;
            ans+=c;
        }
        return ans;
    }
};