#include<string>
using namespace std;

class Solution {
    void replace(string&s,char from,char to){
        for(auto&c:s) if(c==from) c=to;
    }
public:
    int maxDiff(int num) {
        string large=to_string(num);
        for(auto c:large) if(c!='9'){
            replace(large,c,'9');
            break;
        }

        string small=to_string(num);
        for(int i=0;i<small.size();i++){
            if(i==0){
                if(small[i]!='1'){
                    replace(small,small[i],'1');
                    break;
                }
            }else{
                if(small[i]!='0' && small[i]!=small[0]){
                    replace(small,small[i],'0');
                    break;
                }
            }
        }

        return stoi(large)-stoi(small);
    }
};