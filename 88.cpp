#include<vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> dup(nums1);
        int ptr1=0;
        int ptr2=0;
        int ptr3=0;
        while(ptr1<m && ptr2<n){
            if(dup[ptr1]<nums2[ptr2]) nums1[ptr3++]=dup[ptr1++];
            else nums1[ptr3++]=nums2[ptr2++];
        }
        while(ptr1<m) nums1[ptr3++]=dup[ptr1++];
        while(ptr2<n) nums1[ptr3++]=nums2[ptr2++];
    }
};

// Sort from backwards instead so you don't need to dup the array