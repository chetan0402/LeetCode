#include<vector>
#include<unordered_set>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> freq(10,0);
        auto tempN=n;
        while(tempN){
            freq[tempN%10]++;
            tempN/=10;
        }
        auto backtrack=[&](auto&self,int num)->bool{
            bool finalNum=true;

            for(int i=0;i<10;i++) if(freq[i]){
                finalNum=false;
                if(num==0 && i==0) continue;
                num*=10;
                num+=i;
                freq[i]--;
                if(self(self,num)) return true;
                freq[i]++;
                num-=i;
                num/=10;
            }

            if(finalNum) return ((num&(num-1))==0);
            return false;
        };

        return backtrack(backtrack,0);
    }
};

unordered_set<string> target;
bool filled=false;

class Solution {
    void init(){
        if(filled) return;
        
        for(int i=1;i<=1e9;i*=2){
            string temp=to_string(i);
            sort(temp.begin(),temp.end());
            target.insert(temp);
        }
        filled=true;
    }
public:
    bool reorderedPowerOf2(int n) {
        init();
        string temp=to_string(n);
        sort(temp.begin(),temp.end());
        return (target.count(temp));
    }
};