#include<string>
using namespace std;

class Solution {
    long long cost(string&s,char target){
        return costHalf(s,target,-1)+costHalf(s,target,1)-(s.size()%2==1 && s[s.size()/2]==('0'+'1'-target));
    }
    long long costHalf(string&s,char target,int step){
        char from='0'+'1'-target;
        char to=target;
        long long cost=0;
        int n=s.size();
        int ptr=n/2;

        while(ptr>=0 && ptr<n){
            while(ptr>=0 && ptr<n && s[ptr]==to) ptr+=step;
            if(ptr>=0 && ptr<n && s[ptr]==from){
                swap(from,to);
                cost+=min(ptr+1,n-ptr);
                ptr+=step;
            }
        }

        return cost;
    }
public:
    long long minimumCost(string s) {
        return min(cost(s,'1'),cost(s,'0'));
    }
};