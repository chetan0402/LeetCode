#include <cstdint>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result=0;
        for(int i=0;i<31;i++){
            result=(result|(n&(1<<31)));
            n<<=1;
            result>>=1;
        }
        result=(result|(n&(1<<31)));
        return result;
    }
};