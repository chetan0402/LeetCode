#include<string>

using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        for(int j=0;j<n;j++){
            if(s[0]==goal[j]){
                int count=0;
                int ptr1=0;
                int ptr2=j;
                while(s[ptr1]==goal[ptr2] && count<n){
                    ptr1=(ptr1+1)%n;
                    ptr2=(ptr2+1)%n;
                    count++;
                }
                if(count==n) return true;
            }
        }
    return false;
    }
};