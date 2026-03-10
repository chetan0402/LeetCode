#include<vector>
using namespace std;

class Solution {
public:
    bool isItPossible(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();

        vector<int> w1(26,0);
        vector<int> w2(26,0);

        for(auto c:word1) w1[c-'a']++;
        for(auto c:word2) w2[c-'a']++;

        int u1=0;
        int u2=0;
        for(int i=0;i<26;i++) if(w1[i]) u1++;
        for(int i=0;i<26;i++) if(w2[i]) u2++;

        for(int i=0;i<26;i++) for(int j=0;j<26;j++) if(w1[i]>0 & w2[j]>0){
            if(++w1[j]==1) u1++;
            if(++w2[i]==1) u2++;
            if(--w1[i]==0) u1--;
            if(--w2[j]==0) u2--;

            if(u1==u2) return true;

            if(++w1[i]==1) u1++;
            if(++w2[j]==1) u2++;
            if(--w1[j]==0) u1--;
            if(--w2[i]==0) u2--;
        }

        return false;
    }
};
