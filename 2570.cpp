#include<vector>
using namespace std;

class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            int ptr1=0;
            int ptr2=0;
            auto n=nums1.size();
            auto m=nums2.size();
            vector<vector<int>> ans;
            while(ptr1<n && ptr2<m){
                auto num1=nums1[ptr1];
                auto num2=nums2[ptr2];
                if(num1[0]==num2[0]){
                    ans.push_back({num1[0],num1[1]+num2[1]});
                    ptr1++;
                    ptr2++;
                }
                else if(num1[0]<num2[0]){
                    ans.push_back(num1);
                    ptr1++;
                }
                else{
                    ans.push_back(num2);
                    ptr2++;
                }
            }
            while(ptr1<n) ans.push_back(nums1[ptr1++]);
            while(ptr2<m) ans.push_back(nums2[ptr2++]);
            return ans;
        }
    };