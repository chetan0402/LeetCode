#include<unordered_set>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

class Solution {
    public:
        long long countGoodIntegers(int n, int k) {
            unordered_set<string> vis;
            int base=pow(10,(n-1)/2);
            bool odd=n&1;
            for(int i=base;i<base*10;i++){
                string s=to_string(i);
                s+=string(s.rbegin()+odd,s.rend());
                long long palin=stoll(s);
                if(palin%k==0){
                    sort(s.begin(),s.end());
                    vis.insert(s);
                }
            }
    
            vector<int> fac(n+1,1);
            for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i;
            long long ans=0;
            for(auto s:vis){
                vector<int> cnt(10,0);
                for(auto c:s) cnt[c-'0']++;
                long long perm=(n-cnt[0])*fac[n-1];
                for(auto x:cnt) perm/=fac[x];
                ans+=perm;
            }
            return ans;
        }
    };