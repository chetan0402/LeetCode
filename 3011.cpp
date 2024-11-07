#include<unordered_map>
#include<vector>

using namespace std;

unordered_map<int,int> bit;

class Solution {
    int countBits(int num){
        int count=0;
        while(num){
            count+=num%2;
            num/=2;
        }
        return count;
    }
    bool bitMatch(int num1,int num2){
        unordered_map<int,int>::iterator it1=bit.find(num1);
        if(it1==bit.end()){
            bit[num1]=countBits(num1);
        }
        unordered_map<int,int>::iterator it2=bit.find(num2);
        if(it2==bit.end()){
            bit[num2]=countBits(num2);
        }
        return bit[num1]==bit[num2];
    }
public:
    bool canSortArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            bool swapped=false;
            for(int j=0;j<n-i-1;j++){
                if(nums[j]>nums[j+1]){
                    if(bitMatch(nums[j],nums[j+1])){
                        swap(nums[j],nums[j+1]);
                        swapped=true;
                    }else return false;
                }
            }
            if(!swapped) break;
        }
        return true;
    }
};