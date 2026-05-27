#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();

        vector<int> firstUpper(26,-1);
        vector<int> lastLower(26,n);

        for(int i=0;i<n;i++)
        if('a'<=word[i] & word[i]<='z')
        lastLower[word[i]-'a']=i;
        else if(firstUpper[word[i]-'A']==-1) firstUpper[word[i]-'A']=i;

        int ans=0;
        for(int i=0;i<26;i++) if(lastLower[i]<firstUpper[i]) ans++;
        return ans;
    }
};
