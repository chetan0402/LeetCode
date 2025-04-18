#include<string>
using namespace std;

class Solution {
    public:
        string countAndSay(int n) {
            if(n==1) return "1";
            auto num=countAndSay(n-1);
            auto prev=num[0];
            int count=1;
            string result;
            for(int i=1;i<num.size();i++){
                if(prev==num[i]) count++;
                else{
                    result+=to_string(count)+prev;
                    count=1;
                }
                prev=num[i];
            }
            return result+to_string(count)+prev;
        }
    };