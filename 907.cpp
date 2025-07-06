#include<vector>
#include<stack>
using namespace std;

const int MOD=1e9+7;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        stack<int> s;
        vector<int> valueleft(n,1);
        for(int i=0;i<n;i++){
            while(s.size() && arr[s.top()]>arr[i]){
                auto index=s.top();s.pop();
                valueleft[i]+=valueleft[index];
            }
            s.push(i);
        }

        while(s.size()) s.pop();

        vector<int> valueright(n,1);
        for(int i=n-1;i>=0;i--){
            while(s.size() && arr[s.top()]>arr[i]){
                auto index=s.top();s.pop();
                valueright[i]+=valueright[index];
            }
            s.push(i);
        }
        
        long long sum=0;
        for(int i=0;i<n;i++){
            long long num=arr[i];
            long long actualValue=num*(valueleft[i]+valueright[i]-1);
            actualValue%=MOD;
            sum+=actualValue;
            sum%=MOD;
        }

        return sum;
    }
};

int main(){
    Solution s;
    vector<int> arr={3,1,2,4};
    s.sumSubarrayMins(arr);
}