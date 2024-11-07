#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        unordered_map<int,int> bit_pos;
        for(auto candidate:candidates){
            int pos=0;
            while(candidate){
                bit_pos[pos]+= candidate%2;
                candidate/=2;
                pos++;
            }
        }
        unordered_map<int,int>::iterator it=bit_pos.begin();
        int maxLen=0;
        while(it!=bit_pos.end()){
            maxLen=max(maxLen,it->second);
            it=next(it);
        }
        return maxLen;
    }
};