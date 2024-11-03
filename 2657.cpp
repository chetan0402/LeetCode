#include<vector>
#include<set>

using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        set<int> a;
        set<int> b;
        int n=A.size();
        vector<int> ans(n);
        a.insert(A[0]);
        b.insert(B[0]);
        ans[0]=(A[0]==B[0]);
        for(int i=1;i<n;i++){
            a.insert(A[i]);
            b.insert(B[i]);
            if(A[i]==B[i]) ans[i]=ans[i-1]+1;
            else ans[i]=ans[i-1]+(a.find(B[i]) != a.end())+(b.find(A[i]) != b.end());
        }
        return ans;
    }
};