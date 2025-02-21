#include<string>
#include<algorithm>
using namespace std;

class Solution {
    public:
        string reverseWords(string s) {
            int j=0;
            for(int i=0;i<s.size();i++){
                if(s[i]==' '){
                    if(j==0 || s[j-1]==' ') continue;
                    s[j++]=s[i];
                }else s[j++]=s[i];
            }
            s.resize(j);
            if(s.back()==' ') s.pop_back();
            reverse(s.begin(),s.end());
            auto start=s.begin();
            auto end=s.begin();
            while(start!=s.end() && end!=s.end()){
                if(*end==' '){
                    reverse(start,end);
                    start=next(end);
                    end=start;
                }else end=next(end);
            }
            reverse(start,end);
            return s;
        }
    };