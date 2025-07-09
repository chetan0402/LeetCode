#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res;
        unordered_set<int> cur,next;

        for(auto num:arr){
            next={num};
            for(auto num2:cur) next.insert(num|num2);
            cur=next;
            for(auto num2:cur) res.insert(num2);
        }

        return res.size();
    }
};