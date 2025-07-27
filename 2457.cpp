#include<vector>
using namespace std;

class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        int sum=0;
        vector<int> num;
        long long temp=n;
        while(temp){
            sum+=temp%10;
            num.push_back(temp%10);
            temp/=10;
        }

        num.push_back(0);

        vector<int> ans(num.size(),0);

        auto add=[&](int value,int place)->void{
            num[place]+=value;
            sum+=value;
            while(num[place]>=10){
                sum-=num[place];
                num[place+1]+=num[place]/10;
                sum+=num[place]/10;
                num[place]%=10;
                sum+=num[place];
                place++;
            }
        };

        int place=0;

        while(sum>target){
            int toAdd=10-(num[place]%10);
            add(toAdd,place);
            ans[place]=toAdd;
            place++;
        }

        long long numAns=0;

        for(int i=ans.size()-1;i>=0;i--){
            numAns*=10;
            numAns+=ans[i];
        }

        return numAns;
    }
};