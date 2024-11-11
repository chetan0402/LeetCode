#include<vector>
using namespace std;

vector<int> table(1001,-1);

class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int i=0;
        int valToReach=1;
        while(i<nums.size()){
            int diff=nums[i]-valToReach;
            if(diff<0) return false;
            if(prime(diff) || diff==0){
                i++;
                valToReach++;
            }else valToReach++;
        }
        return true;
    }

    bool prime(int num){
        if(table[0]==-1){
            table[0]=table[1]=0;
            for(int i=2;i*i<table.size();i++){
                if(table[i]!=-1) continue;
                table[i]=1;
                for(int j=i+i;j<table.size();j+=i) table[j]=0;
            }
            return prime(num);
        }else return table[num];
    }
};