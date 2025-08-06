#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        int m=sqrt(n);

        int section=(n+m-1)/m;

        int ans=0;

        vector<int> maxV(section);

        for(int i=0;i<n;i++) maxV[i/m]=max(maxV[i/m],baskets[i]);

        for(auto fruit:fruits){
            bool placed=false;
            for(int sec=0;sec<section;sec++){
                if(maxV[sec]<fruit) continue;
                maxV[sec]=0;

                bool found=false;

                for (int i=0;i<m;i++) {
                    int pos=sec*m+i;
                    if (pos<n && baskets[pos]>=fruit && !found) {
                        baskets[pos]=0;
                        found=true;
                    }
                    if (pos<n) {
                        maxV[sec] = max(maxV[sec], baskets[pos]);
                    }
                }

                placed=true;
                break;
            }
            if(!placed) ans++;
        }

        return ans;
    }
};