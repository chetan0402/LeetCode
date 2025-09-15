#include<string>
#include<sstream>
#include<vector>
using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        stringstream ss(text);
        string word;
        int ans=0;
        vector<bool> broken(26,false);
        for(auto c:brokenLetters) broken[c-'a']=true;
        while(ss>>word){
            bool valid=true;
            for(auto c:word) if(broken[c-'a']){
                valid=false;
                break;
            }
            if(valid) ans++;
        }
        return ans;
    }
};