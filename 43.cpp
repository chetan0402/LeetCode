#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int n=num1.size();
        int m=num2.size();
        
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());

        int offset=0;

        vector<int> ans(n*m+1,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int place=offset+j;
                ans[place]+=(num1[i]-'0')*(num2[j]-'0');
                int cur=place;
                while(ans[cur]>=10){
                    ans[cur+1]+=(ans[cur]/10);
                    ans[cur]%=10;
                    cur++;
                }
            }
            offset++;
        }

        string ansstr;

        for(int i=0;i<=n*m;i++) ansstr.push_back(ans[i]+'0');

        while(ansstr.size() && ansstr.back()=='0') ansstr.pop_back();

        reverse(ansstr.begin(),ansstr.end());

        if(ansstr.empty()) ansstr="0";

        return ansstr;
    }
};