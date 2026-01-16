#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

const int MOD=1e9+7;

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        priority_queue<int> h;
        priority_queue<int> v;

        for(int i=0;i<hFences.size();i++)
        for(int j=i+1;j<hFences.size();j++)
        h.push(abs(hFences[i]-hFences[j]));

        for(int i=0;i<vFences.size();i++)
        for(int j=i+1;j<vFences.size();j++)
        v.push(abs(vFences[i]-vFences[j]));

        while(h.size()>0 & v.size()>0){
            auto hside=1LL*h.top();
            auto vside=1LL*v.top();

            if(hside==vside) return (hside*vside)%MOD;
            if(hside>vside) h.pop();
            else v.pop();
        }

        return -1;
    }
};