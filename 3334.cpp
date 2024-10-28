#include<vector>
#include<algorithm>

using namespace std;

int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

class Solution {
public:
    long long maxScore(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0]*nums[0];
        vector<long long>prefixLCM(n);
        vector<long long>prefixGCD(n);
        prefixLCM[0]=nums[0];
        prefixGCD[0]=nums[0];
        for(int i=1;i<n;i++){
            prefixLCM[i]=lcm(prefixLCM[i-1],nums[i]);
            prefixGCD[i]=gcd(prefixGCD[i-1],nums[i]);
        }

        vector<long long> suffixLCM(n);
        vector<long long> suffixGCD(n);

        suffixLCM[n-1]=nums[n-1];
        suffixGCD[n-1]=nums[n-1];

        for(int i=n-2;i>=0;i--){
            suffixLCM[i]=lcm(suffixLCM[i+1],nums[i]);
            suffixGCD[i]=gcd(suffixGCD[i+1],nums[i]);
        }

        long long highest = suffixLCM[0]*suffixGCD[0];
        highest=max(highest,prefixLCM[n-2] * prefixGCD[n-2]);
        highest=max(highest,suffixLCM[1] * suffixGCD[1]);
        for(int i = 1; i < n-1; i++) {
            highest=max(highest,(long long)
                lcm(prefixLCM[i-1], suffixLCM[i+1])*
                gcd(prefixGCD[i-1], suffixGCD[i+1])
            );
        }
        return highest;
    }
};