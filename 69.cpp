class Solution {
public:
    int mySqrt(int x) {
        if(x==1) return 1;
        int left=0;
        int right=x/2;

        while(left<right){
            double mid=left+(right-left+1)/2;
            if(mid*mid>x){
                right=mid-1;
            }else{
                left=mid;
            }
        }

        return left;
    }
};