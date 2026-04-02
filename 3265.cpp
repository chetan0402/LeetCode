#include<vector>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums) {
        int ans=0;
        int n=nums.size();

        auto eq=[&](int i,int j)->bool{
            int num1=nums[i];
            int num2=nums[j];
            int diff=0;
            pair<int,int> first={-1,-1};
            pair<int,int> second={-1,-1};
            while(num1>0 | num2>0){
                if(num1%10 != num2%10){
                    diff++;
                    if(first.first==-1) first={num1%10,num2%10};
                    else if(second.first==-1) second={num2%10,num1%10};
                }
                num1/=10;
                num2/=10;
            }
            if(diff>2) return false;

            return first==second;
        };

        for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) if(eq(i,j)) ans++;

        return ans;
    }
};
