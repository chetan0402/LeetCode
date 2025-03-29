#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;

const int MOD=1e9+7;

class Solution {
    vector<bool> isPrime;
    vector<int> sieve(int n){
        isPrime=vector<bool>(n+1,true);
        isPrime[0]=isPrime[1]=false;
        vector<int> primes;
        int i=2;
        for(;i*i<=n;i++) if(isPrime[i]){
            primes.push_back(i);
            for(int j=i*i;j<=n;j+=i) isPrime[j]=false;
        }
        return primes;
    }
    long long pow(long long base,long long expo){
        long long result=1;
        base%=MOD;
        while(expo){
            if(expo&1) result=(result*base)%MOD;
            base=(base*base)%MOD;
            expo>>=1;
        }
        return result;
    }
public:
    int maximumScore(vector<int>& nums, int k) {
        auto n=nums.size();
        vector<int> primes=sieve(*max_element(nums.begin(),nums.end()));
        vector<int> primeScore(n,0);
        for(int i=0;i<n;i++){
            auto num=nums[i];
            for(auto prime:primes){
                if(prime*prime>num) break;
                if(num%prime==0) primeScore[i]++;
                while(num%prime==0) num/=prime;
            }
            if(num>1) primeScore[i]++;
        }
        vector<pair<int,int>> numWithI(n);
        for(int i=0;i<n;i++) numWithI[i]={nums[i],i};
        priority_queue<pair<int,int>> pq(numWithI.begin(),numWithI.end());
        long long ans=1;
        stack<int> s;
        s.push(0);
        vector<int> left(n,-1);
        vector<int> right(n,n);
        for(int i=1;i<n;i++){
            while(!s.empty() && primeScore[s.top()]<primeScore[i]){
                right[s.top()]=i;
                s.pop();
            }
            if(!s.empty() && primeScore[s.top()]>=primeScore[i]) left[i]=s.top();
            s.push(i);
        }
        while(k){
            auto [value, index]=pq.top();
            pq.pop();
            long long usesPossible=1LL*(index-left[index])*(right[index]-index);
            if(usesPossible>k){
                ans*=pow(value,k);
                k=0;
            }else{
                ans*=pow(value,usesPossible);
                k-=usesPossible;
            }
            ans%=MOD;
        }
        return ans;
    }
};