#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        int maximumCandies(vector<int>& candies, long long k) {
            auto n=candies.size();
    
            auto fn=[&](int each)->bool{
                if(each==0) return true;
                long long child=k;
                for(auto candie:candies){
                    child-=(candie/each);
                    if(child<0) break;
                }
                return (child<=0);
            };
    
            int l=0;
            int r=*max_element(candies.begin(),candies.end());
            while(l<r){
                auto mid=l+(r-l+1)/2;
                if(fn(mid)) l=mid;
                else r=mid-1;
            }
            return l;
        }
    };