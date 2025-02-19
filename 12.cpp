#include<string>
#include<cmath>
using namespace std;

string romPlace(int n,int place){
    if(n==0) return "";
    string to_return;
    char increment;
    char mid;
    char large;
    if(place==1){
        increment='I';
        mid='V';
        large='X';
    }
    if(place==2){
        increment='X';
        mid='L';
        large='C';
    }
    if(place==3){
        increment='C';
        mid='D';
        large='M';
    }
    if(place==4){
        increment='M';
    }
    if(n<=3) for(int i=0;i<n;i++) to_return.push_back(increment);
    if(n==4){
        to_return.push_back(increment);
        to_return.push_back(mid);
    }
    if(n<=8 && n>=5){
        to_return.push_back(mid);
        for(int i=0;i<(n-5);i++) to_return.push_back(increment);
    }
    if(n==9){
        to_return.push_back(increment);
        to_return.push_back(large);
    }
    return to_return;
}

class Solution {
public:
    string intToRoman(int num) {
        string ans;
        for(int i=4;i>0;i--){
            ans+=(romPlace(num/pow(10,i-1),i));
            num=num%(int)pow(10,i-1);
        }
        return ans;
    }
};