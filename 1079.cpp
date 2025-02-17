#include<unordered_map>
#include<string>
using namespace std;

class Solution {
    void backtrack(int i,unordered_map<int,int>&freq,int&ans,int end){
        if(i==end) return;
        for(auto [key, value]:freq){
            if(value==0) continue;
            freq[key]--;
            ans++;
            backtrack(i+1,freq,ans,end);
            freq[key]++;
        }
    }
public:
    int numTilePossibilities(string tiles) {
        unordered_map<int,int> freq;
        for(auto c:tiles) freq[c-'a']++;
        int ans=0;
        backtrack(0,freq,ans,tiles.size());
        return ans;
    }
};