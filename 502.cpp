#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pair<int,int>> PnC;
        for(int i=0;i<n;i++) PnC.push_back({profits[i],capital[i]});

        sort(PnC.begin(),PnC.end(),[](auto a,auto b)->bool{
            if(a.second!=b.second) return a.second<b.second;
            return a.first<b.first;
        });

        int processedPnc=0;

        auto comp=[](auto a,auto b)->bool{
            if(a.first!=b.first) return a.first<b.first;
            return a.second>b.second;
        };

        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(comp)> eligibleProfits(comp);

        int doneProjects=0;

        bool processing=true;

        while(processedPnc<n && PnC[processedPnc].second<=w) eligibleProfits.push(PnC[processedPnc++]);

        while(doneProjects<k && processing && eligibleProfits.size()){
            processing=false;
            auto [potentialProfit, potentialCost]=eligibleProfits.top();
            if(potentialCost<=w){
                w+=potentialProfit;
                eligibleProfits.pop();
                processing=true;
                doneProjects++;
            }
            while(processedPnc<n && PnC[processedPnc].second<=w) eligibleProfits.push(PnC[processedPnc++]);
        }

        return w;
    }
};