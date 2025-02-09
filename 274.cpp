#include<vector>
using namespace std;

class Solution {
    public:
        int hIndex(vector<int>& citations) {
            int n=citations.size();
            int l=0;
            int r=n;
            auto f=[&](int h)->bool{
                int count=0;
                for(int i=0;i<n;i++) if(citations[i]>=h) count++;
                return (count>=h);
            };
            while(l<r){
                auto mid=(r-l+1)/2+l;
                if(f(mid)) l=mid;
                else r=mid-1;
            }
            return l;
        }
    };