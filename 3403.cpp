#include<string>
using namespace std;

class Solution {
public:
    string answerString(string word, int numFriends) {
        int n=word.size();
        if(numFriends==1) return word;
        int len=n-numFriends+1;
        string ans="";
        for(int i=0;i<n;i++){
            string temp=word.substr(i,min(len,n-i));
            ans=max(ans,temp);
        }
        return ans;
    }
};