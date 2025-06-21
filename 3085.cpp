#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26,0);
        for(auto c:word) freq[c-'a']++;

        int smallVal=INT_MAX;
        for(int i=0;i<26;i++) if(freq[i]!=0) smallVal=min(smallVal,freq[i]);

        int ans=INT_MAX;
        for(int i=0;i<26;i++) if(freq[i]!=0){
            int deletions=0;
            for(int j=0;j<26;j++){
                if(freq[j]<freq[i]) deletions+=freq[j];
                else deletions+=max(0,freq[j]-freq[i]-k);
            }
            ans=min(ans,deletions);
        }
        return ans;
    }
};