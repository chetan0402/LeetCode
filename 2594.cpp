#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

class Solution {
    public:
        long long repairCars(vector<int>& ranks, int cars) {
            auto n=ranks.size();
            sort(ranks.begin(),ranks.end());
    
            auto fn=[&](long long checkTime)->bool{
                int carsToRepair=cars;
                for(int i=0;i<n;i++){
                    // time >= rank*car*car
                    // time/rank >= n*n
                    // sqrt(time/rank) >= n
                    carsToRepair-=floor(sqrt(1.0*checkTime/ranks[i]));
                    if(carsToRepair<=0) return true;
                }
                return false;
            };
            
            long long l=0;
            long long r=1ll*ranks[n-1]*cars*cars;
            while(l<r){
                auto mid=l+(r-l)/2;
                if(fn(mid)) r=mid;
                else l=mid+1;
            }
            return r;
        }
    };