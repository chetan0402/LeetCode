#include<vector>
#include<algorithm>
using namespace std;

class SolutionBinarySearch {
    public:
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            auto n=nums.size();
    
            auto fn=[&](int k)->bool{
                vector<int> diff(n+1,0);
                for(int i=0;i<k;i++){
                    diff[queries[i][0]]+=queries[i][2];
                    diff[queries[i][1]+1]-=queries[i][2];
                }
                vector<int> toSubtract(n,0);
                int running=0;
                for(int i=0;i<n;i++){
                    running+=diff[i];
                    toSubtract[i]=running;
                }
                for(int j=0;j<n;j++) if(nums[j]-toSubtract[j]>0) return false;
                return true;
            };
    
            int l=(*max_element(nums.begin(),nums.end()))/5;
            int r=queries.size();
            while(l<r){
                auto mid=l+(r-l)/2;
                if(fn(mid)) r=mid;
                else l=mid+1;
            }
            return (fn(r))?r:-1;
        }
    };