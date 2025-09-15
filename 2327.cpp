#include<vector>
using namespace std;

const int MOD=1e9+7;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> forgets(n+1,0);
        vector<int> spreads(n+1,0);

        int day=1;
        int people=1;
        if(1+forget<=n) forgets[1+forget]=1;
        for(int i=1+delay;i<1+forget and i<=n;i++) spreads[i]=1;
        while(day<=n){
            people-=forgets[day];
            if(day+forget<=n){
                forgets[day+forget]+=spreads[day];
                forgets[day+forget]%=MOD;
            }
            people+=spreads[day];
            people%=MOD;
            if(people<0) people+=MOD;
            for(int i=day+delay;i<day+forget and i<=n;i++){
                spreads[i]+=spreads[day];
                spreads[i]%=MOD;
            }
            day++;
        }

        return people;
    }
};