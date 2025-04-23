#include<vector>
using namespace std;
class Solution {
    public:
        int countLargestGroup(int n) {
            vector<int> sumToSize(36+1,0);
            for(int i=1;i<=n;i++){
                int num=i;
                int sum=0;
                while(num){
                    sum+=(num%10);
                    num/=10;
                }
                sumToSize[sum]++;
            }
            int maxSize=0;
            int count=0;
            for(auto size:sumToSize){
                if(size>maxSize){
                    maxSize=size;
                    count=1;
                }else if(size==maxSize) count++;
            }
            return count;
        }
    };