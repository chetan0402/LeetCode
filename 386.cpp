#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;

        auto backtrack=[&](auto&self,int num)->void{
            for(int i=0;i<=9;i++){
                num*=10;
                num+=i;
                if(num>n) break;
                ans.emplace_back(num);
                self(self,num);
                num/=10;
            }
        };

        for(int i=1;i<=min(n,9);i++){
            ans.emplace_back(i);
            backtrack(backtrack,i);
        }

        return ans;
    }
};