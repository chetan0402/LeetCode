#include<string>

using namespace std;

class Solution {
public:
    string compressedString(string word) {
        string ans;
        char letter=word[0];
        int count=0;
        for(auto c:word){
            if(letter==c){
                if(count==9){
                    ans+='0'+count;
                    ans+=letter;
                    count=1;
                }else count++;
            }else{
                ans+='0'+count;
                ans+=letter;
                count=1;
                letter=c;
            }
        }
        ans+='0'+count;
        ans+=letter;
        return ans;
    }
};