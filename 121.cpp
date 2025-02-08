#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int minPrice=prices[0];
            int profit=0;
            for(auto p:prices){
                minPrice=min(minPrice,p);
                profit=max(profit,p-minPrice);
            }
            return profit;
        }
    };