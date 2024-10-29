#include<vector>

using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int _xor=0;
        if(nums2.size()%2){
            for(int i=0;i<nums1.size();i++) _xor=_xor^nums1[i];
        }
        if(nums1.size()%2){
            for(int i=0;i<nums2.size();i++) _xor=_xor^nums2[i];
        }
        return _xor;
    }
};