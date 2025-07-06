#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class FindSumPairs {
    vector<int> nums1;
    unordered_map<int,int> iToNum;
    unordered_map<int,int> freq;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        this->nums1=nums1;
        for(int i=0;i<nums2.size();i++){
            iToNum[i]=nums2[i];
            freq[nums2[i]]++;
        }
    }
    
    void add(int index, int val) {
        int originalNumber=iToNum[index];
        int newNumber=originalNumber+val;
        iToNum[index]=newNumber;
        freq[originalNumber]--;
        freq[newNumber]++;
    }
    
    int count(int tot) {
        int ans=0;
        for(auto num1:nums1) {
            if(tot-num1<=0) break;
            ans+=freq[tot-num1];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */