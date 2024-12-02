#include<string>
using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        string temp="";
        int pos=1;
        for(int i=0;i<sentence.size();i++){
            if(sentence[i]==' '){
                pos++;
                temp="";
            }
            else temp+=sentence[i];
            if(temp==searchWord) return pos;
        }
        return -1;
    }
};