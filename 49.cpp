#include<vector>
#include<string>
#include<cmath>
#include<unordered_map>
#include<algorithm>
using namespace std;

const int MOD=1e9+7;

class SolutionNotAccepeted {
    // Leetcode won't accept this because it doens't return in a specific order, which leetcode wants, but doesn't mention in the question
    long long hash(string s){
        long long result=1;
        int cnt[26];
        for(auto c:s) cnt[c-'a']++;
        for(int i=0;i<26;i++) if(cnt[i]!=0) result=(long long)(result*pow(i+1,cnt[i]))%MOD;
        return result;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<long long,vector<string>> hashedGroups;
        for(auto str:strs) hashedGroups[hash(str)].push_back(str);
        vector<vector<string>> ans;
        ans.reserve(hashedGroups.size());
        for(auto [_, value]:hashedGroups) ans.push_back(value);
        return ans;
    }
};

// Below instead of using a custom hash function, this uses the built-in hash function and the output of this, matches the order leetcode wants

class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string,vector<string>> hashed;
            for(auto str:strs){
                string key=str;
                sort(key.begin(),key.end());
                hashed[key].push_back(str);
            }
            vector<vector<string>> ans;
            ans.reserve(hashed.size());
            for(auto [_, value]:hashed) ans.push_back(value);
            return ans;
        }
    };

class SolutionTRy2 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> ans;
        for(auto&str:strs){
            string key=str;
            sort(key.begin(),key.end());
            ans[key].push_back(str);
        }

        vector<vector<string>> actualAns;
        for(auto [_, value]:ans) actualAns.push_back(value);

        return actualAns;
    }
};