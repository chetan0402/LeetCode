#include<string>
#include<vector>
using namespace std;

bool isVowel(char c){
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}

class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        auto n=word.size();
        long long ans=0;
        int start=0;
        int end=0;
        vector<int> cnt(128,0);

        auto allVowel=[&]()->bool{
            return (cnt['a']>0 && cnt['e']>0 && cnt['i']>0 && cnt['o']>0 && cnt['u']>0);
        };

        int nonVowel=0;
        vector<int> suffixNonVowel(n,0);
        int pos=n;
        for(int i=n-1;i>=0;i--){
            suffixNonVowel[i]=pos;
            if(!isVowel(word[i])) pos=i;
        }
        while(end<n){
            cnt[word[end]]++;
            if(!isVowel(word[end])) nonVowel++;
            
            while(nonVowel>k){
                cnt[word[start]]--;
                if(!isVowel(word[start])) nonVowel--;
                start++;
            }
            
            while(start<n && nonVowel==k && allVowel()){
                ans+=suffixNonVowel[end]-end;
                cnt[word[start]]--;
                if(!isVowel(word[start])) nonVowel--;
                start++;
            }
            end++;
        }
        return ans;
    }
};