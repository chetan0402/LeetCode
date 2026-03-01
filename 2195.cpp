#include<vector>
using namespace std;

class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        long long sum=0;
        sort(nums.begin(),nums.end());
        vector<int> unique;
        for(auto num:nums)
        if(unique.size()==0 || (unique.back()!=num)) unique.push_back(num);

        long long num=1;
        auto i=0;
        while(k--){
            while(i<unique.size() && unique[i]==num){
                num++;
                i++;
            }
            if(i==unique.size()){
                sum+=(1LL*(num+k)*(num+k+1)/2)-(1LL*(num-1)*num/2);
                break;
            }
            sum+=num;
            num++;

        }
        return sum;
    }
};
