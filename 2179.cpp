#include<vector>
using namespace std;

class Fen{
    vector<int> tree;
    public:
    Fen(int s): tree(s+1,0){}
    void update(int idx,int diff){
        idx++;
        while(idx<tree.size()){
            tree[idx]+=diff;
            idx+=(idx)&(-idx);
        }
    }
    int query(int idx){
        idx++;
        int res=0;
        while(idx>0){
            res+=tree[idx];
            idx-=(idx)&(-idx);
        }
        return res;
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        auto n=nums1.size();
        vector<int> numToI2(n);
        vector<int> i2Toi1(n);
        for(int i=0;i<n;i++) numToI2[nums2[i]]=i;
        for(int i=0;i<n;i++) i2Toi1[numToI2[nums1[i]]]=i;
        Fen tree(n);
        auto res=0LL;
        for(int value=0;value<n;value++){
            int pos=i2Toi1[value];
            int left=tree.query(pos);
            tree.update(pos,1);
            int right=(n-1-pos)-(value-left);
            res+=1LL*left*right;
        }
        return res;
    }
};