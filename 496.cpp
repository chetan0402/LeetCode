#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            auto q=nums1.size();
            auto n=nums2.size();
            stack<int> s;
            unordered_map<int,int> numToAns;
            for(int i=0;i<n;i++){
                while(s.size() && s.top()<nums2[i]){
                    numToAns[s.top()]=nums2[i];
                    s.pop();
                }
                s.push(nums2[i]);
            }
            vector<int> ans(q);
            for(int i=0;i<q;i++){
                if(numToAns.count(nums1[i])) ans[i]=numToAns[nums1[i]];
                else ans[i]=-1;
            }
            return ans;
        }
    };