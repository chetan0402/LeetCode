#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

vector<char> dirs={'N','S','E','W'};
unordered_map<char,char> opposite={
    {'N','S'},
    {'S','N'},
    {'W','E'},
    {'E','W'}
};

class Solution {
public:
    int maxDistance(string s, int k) {
        int ans=0;

        unordered_map<char,int> freq;
        for(auto c:s){
            freq[c]++;
            for(auto vertical:{'N','S'}){
                for(auto horizontal:{'W','E'}){
                    int indirection=freq[vertical]+freq[horizontal];
                    int oppdirection=freq[opposite[vertical]]+freq[opposite[horizontal]];
                    ans=max(ans,indirection-oppdirection+2*min(k,oppdirection));
                }
            }
        }

        return ans;
    }
};