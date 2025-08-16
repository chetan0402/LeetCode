#include<string>
using namespace std;

class Solution {
public:
    int maximum69Number (int num) {
        string temp=to_string(num);
        for(auto&c:temp) if(c=='6'){
            c='9';
            break;
        }
        return stoi(temp);
    }
};