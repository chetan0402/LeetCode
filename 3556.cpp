#include<vector>
#include<set>

class Solution {
    bool isPrime(long long num){
        if(num==0 | num==1) return false;
        for(long long i=2;i*i<=num;i++) if(num%i==0) return false;
        return true;
    }
public:
    long long sumOfLargestPrimes(string s) {
        set<long long> nums;
        for(int i=0;i<s.size();i++)
        for(int len=1;len+i<=s.size();len++){
            auto num=stoll(s.substr(i,len));
            if(isPrime(num)) nums.insert(num);
            while(nums.size()>3) nums.erase(nums.begin());
        }

        long long sum=0;
        for(auto num:nums) sum+=num;
        return sum;
    }
};
