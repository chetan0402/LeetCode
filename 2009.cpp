#include<algorithm>
#include<vector>
#include<set>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        set<int> unique;
        for(auto&num:nums) unique.insert(num);
        vector<int> arr;
        for(auto&uni:unique) arr.push_back(uni);

        int i=0;
        int j=0;

        int maxRange=0;

        while(i<arr.size()){
            while(j<arr.size() && arr[j]<arr[i]+nums.size()){
                j++;
            }
            maxRange=max(maxRange,j-i);
            i++;
        }

        return nums.size()-maxRange;
    }
};