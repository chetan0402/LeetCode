#include<vector>
#define INT_MAX __INT64_MAX__

using namespace std;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes;
        for(int i=left;i<=right;i++){
            if(isPrime(i)){
                primes.push_back(i);
            }
        }
        if (primes.size()<2) return vector<int>(2,-1);
        else{
            int diff=INT_MAX;
            int num1=-1;
            int num2=-1;
            for(int i=0;i<primes.size()-1;i++){
                if(primes[i+1]-primes[i] < diff){
                    diff=primes[i+1]-primes[i];
                    num1=primes[i];
                    num2=primes[i+1];
                }
            }
            return vector<int>{num1,num2};
        }
    }

    bool isPrime(int num) {
        if (num <= 1) return false;
        if (num == 2) return true;
        if (num % 2 == 0) return false;
        for (int i = 3; i * i <= num; i += 2) if (num % i == 0) return false;
        return true;
    }
};