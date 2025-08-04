#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> freq;

        int left=0;

        auto valid=[&]()->bool{
            return (freq.size()<=2);
        };

        int ans=0;

        for(int right=0;right<fruits.size();right++){
            int fruit=fruits[right];
            freq[fruit]++;

            while(!valid()){
                int to_remove=fruits[left];
                left++;
                freq[to_remove]--;
                if(freq[to_remove]==0) freq.erase(to_remove);
            }

            ans=max(ans,right-left+1);
        }

        return ans;
    }
};