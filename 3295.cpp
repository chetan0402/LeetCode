#include<string>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> banned(bannedWords.begin(),bannedWords.end());

        int count=0;
        for(auto&s:message) if(banned.count(s)){
            count++;
            if(count==2) return true;
        }

        return false;
    }
};