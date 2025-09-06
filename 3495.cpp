#include<vector>
using namespace std;

vector<long long> logcost;
vector<long long> prefix;

class Solution {
    void start(){
        if(prefix.size()) return;
        for(int i=0;i<=14;i++){
            long long len=pow4(i+1)-pow4(i);
            logcost.push_back((i+1)*len);
        }
        prefix.push_back(0);
        for(auto l:logcost) prefix.push_back(l+prefix.back());
    }

    int fastfloorlog4(int num){
        return (__builtin_clzll(1) - __builtin_clzll(num)) / 2;
    }

    long long pow4(int num){
        return 1LL << (num << 1);
    }
public:
    long long minOperations(vector<vector<int>>& queries) {
        start();
        long long ans=0;
        for(const auto&q:queries){
            const long long l=q[0];
            const long long r=q[1];

            const int startlog=fastfloorlog4(l);
            const int endlog=fastfloorlog4(r);

            if(startlog==endlog){
                long long times=(r-l+1)*(startlog+1);
                ans+=(times+1)/2;
            }else{
                long long times=0;
                long long len1=pow4(startlog+1)-l;
                times+=(startlog+1)*(len1);

                times+=prefix[endlog]-prefix[startlog+1];

                long long len2=r-pow4(endlog)+1;
                times+=(endlog+1)*(len2);

                ans+=(times+1)/2;
            }
        }
        return ans;
    }
};