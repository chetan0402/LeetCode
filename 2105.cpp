#include<vector>
using namespace std;

class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int ans=0;

        int curA=capacityA;
        int curB=capacityB;
        for(int offset=0;offset<(plants.size()+1)/2;offset++){
            int posA=offset;
            int posB=plants.size()-1-offset;
            if(posA==posB){
                if(curA<curB){
                    if(curB<plants[posB]){
                        ans++;
                        curB=capacityB;
                    }
                    curB-=plants[posB];
                }else{
                    if(curA<plants[posA]){
                        ans++;
                        curA=capacityA;
                    }
                    curA-=plants[posA];
                }
            }else{
                if(curA<plants[posA]){
                    ans++;
                    curA=capacityA;
                }
                curA-=plants[posA];
                if(curB<plants[posB]){
                    ans++;
                    curB=capacityB;
                }
                curB-=plants[posB];
            }
        }

        return ans;
    }
};
