#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> beforeSmaller(n,-1);
        vector<int> afterSmaller(n,n);

        stack<int> s;

        for(int i=0;i<n;i++){
            while(s.size() && heights[s.top()]>heights[i]){
                auto index=s.top();s.pop();
                afterSmaller[index]=i;
            }
            s.push(i);
        }

        while(s.size()) s.pop();

        for(int i=n-1;i>=0;i--){
            while(s.size() && heights[s.top()]>heights[i]){
                auto index=s.top();s.pop();
                beforeSmaller[index]=i;
            }
            s.push(i);
        }

        int ans=0;

        for(int i=0;i<n;i++){
            int start=beforeSmaller[i]+1;
            int end=afterSmaller[i]-1;
            ans=max(ans,(end-start+1)*heights[i]);
        }

        return ans;
    }
};