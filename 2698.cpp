class Solution {
    bool partition(int num,int target){
        if(target<0 || num<target) return false;
        if(num==target) return true;
        return partition(num/10,target- num%10) || partition(num/100,target-num%100) || partition(num/1000,target-num%1000);
    }
public:
    int punishmentNumber(int n) {
        int ans=0;
        for(int i=1;i<=n;i++) if(partition(i*i,i)) ans+=i*i;
        return ans;
    }
};