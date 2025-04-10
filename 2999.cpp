#include<string>
#include<cmath>
using namespace std;

class Solution {
    public:
        long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
            return calculate(to_string(finish),s,limit)-calculate(to_string(start-1),s,limit);
        }
        long long calculate(string x,string s,int limit){
            if(x.size()<s.size()) return 0;
            if(x.size()==s.size()) return (x>=s)?1:0;
            int prefixLength=x.size()-s.size();
            string xStart=x.substr(prefixLength,s.size());
            auto count=0LL;
            for(int i=0;i<prefixLength;i++){
                if(limit<(x[i]-'0')){
                    count+=(long long)pow(limit+1,prefixLength-i);
                    return count;
                }
                count+=(long long)(x[i]-'0')*pow(limit+1,prefixLength-1-i);
            }
            if(xStart>=s) count++;
            return count;
        }
    };