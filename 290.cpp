#include<vector>
#include<string>
#include<unordered_map>
#include<sstream>
using namespace std;

class Solution {
    public:
        bool wordPattern(string pattern, string s) {
            vector<string> sToPattern(128,"");
            unordered_map<string,int> patternToS;
            vector<string> words;
            words.reserve(s.size());
            stringstream sWords(s);
            string word;
            while(sWords>>word) words.push_back(word);
            if(pattern.size()!=words.size()) return false;
            for(int i=0;i<pattern.size();i++){
                if(patternToS[words[i]]!=0 && patternToS[words[i]]!=pattern[i]) return false;
                if(sToPattern[pattern[i]]!="" && sToPattern[pattern[i]]!=words[i]) return false;
                sToPattern[pattern[i]]=words[i];
                patternToS[words[i]]=pattern[i];
            }
            return true;
        }
    };

int main(){
    Solution s;
    s.wordPattern("abba","dog cat cat dog");
    return 0;
}