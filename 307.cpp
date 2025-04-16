#include<vector>
using namespace std;

class NumArray {
    vector<int> tree;
    vector<int> nums;
    int construct(int i,int l,int r){
        if(l==r){
            tree[i]=nums[l];
            return tree[i];
        }
        int mid=l+(r-l)/2;
        tree[i]=construct(2*i+1,l,mid)+construct(2*i+2,mid+1,r);
        return tree[i];
    }
    int sum(int i,int curL,int curR,int targetL,int targetR){
        if(targetL>curR || targetR<curL) return 0;
        if(curL>=targetL && curR<=targetR) return tree[i];
        int mid=curL+(curR-curL)/2;
        return sum(2*i+1,curL,mid,targetL,targetR)+sum(2*i+2,mid+1,curR,targetL,targetR);
    }
    void rangeUpdate(int i,int curL,int curR,int target,int diff){
        if(curL>target || curR<target) return;
        tree[i]+=diff;
        if(curL==curR) return;
        int mid=curL+(curR-curL)/2;
        rangeUpdate(2*i+1,curL,mid,target,diff);
        rangeUpdate(2*i+2,mid+1,curR,target,diff);
    }
public:
    NumArray(vector<int>& nums) {
        this->nums=nums;
        tree.resize(4*nums.size());
        construct(0,0,nums.size()-1);
    }
    
    void update(int index, int val) {
        int diff=val-nums[index];
        nums[index]=val;
        rangeUpdate(0,0,nums.size()-1,index,diff);
    }
    
    int sumRange(int left, int right) {
        return sum(0,0,nums.size()-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */