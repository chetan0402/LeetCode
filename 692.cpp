#include<vector>
#include<unordered_map>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freq;
        for(auto&word:words) freq[word]++;

        auto comp=[](auto a,auto b)->bool{
            if(a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        };

        priority_queue<pair<int,string>,vector<pair<int,string>>,decltype(comp)> minHeap(comp);

        for(auto [word, count]:freq){
            minHeap.push({count,word});
            if(minHeap.size()>k) minHeap.pop();
        }

        vector<string> ans;
        while(minHeap.size()){
            auto [_, word]=minHeap.top();minHeap.pop();
            ans.push_back(word);
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};