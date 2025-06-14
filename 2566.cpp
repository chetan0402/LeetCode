#include<string>
using namespace std;

class Solution {
public:
    int minMaxDifference(int num) {
        string large=to_string(num);
        char first=large[0];
        int i=0;
        while(first=='9' && i<large.size()) first=large[i++];
        for(int i=0;i<large.size();i++) if(large[i]==first) large[i]='9';

        string small=to_string(num);
        first=small[0];
        for(int i=0;i<small.size();i++) if(small[i]==first) small[i]='0';

        return stoi(large)-stoi(small);
    }
};