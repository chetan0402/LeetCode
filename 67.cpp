#include<string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        bool carry=false;

        int ptrA=a.size()-1;
        int ptrB=b.size()-1;

        string ans;

        while(ptrA>=0 && ptrB>=0){
            int result=(a[ptrA]-'0')+(b[ptrB]-'0')+carry;
            carry=false;
            if(result==0) ans.push_back('0');
            if(result==1) ans.push_back('1');
            if(result==2){
                ans.push_back('0');
                carry=true;
            }
            if(result==3){
                ans.push_back('1');
                carry=true;
            }
            ptrA--;
            ptrB--;
        }
        while(ptrA>=0){
            int result=(a[ptrA]-'0')+carry;
            carry=false;
            if(result==0) ans.push_back('0');
            if(result==1) ans.push_back('1');
            if(result==2){
                ans.push_back('0');
                carry=true;
            }
            ptrA--;
        }
        while(ptrB>=0){
            int result=(b[ptrB]-'0')+carry;
            carry=false;
            if(result==0) ans.push_back('0');
            if(result==1) ans.push_back('1');
            if(result==2){
                ans.push_back('0');
                carry=true;
            }
            ptrB--;
        }
        if(carry) ans.push_back('1');

        reverse(ans.begin(),ans.end());

        return ans;
    }
};