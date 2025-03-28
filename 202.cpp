class Solution {
    public:
        bool isHappy(int n) {
            while(n!=1 && n!=7){
                if(n<=9) return false;
                int num=n;
                int sq=0;
                while(num){
                    sq+=(num%10)*(num%10);
                    num/=10;
                }
                n=sq;
            }
            return true;
        }
    };

// This is mathematical solution, needs to know the conditions first
// To attempt in other ways, we basically need to detect when the output have looped and exit
// Use hashmap to exit
// Use slow and fast pointer exit