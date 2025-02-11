#include<string>
using namespace std;

class Solution {
    public:
        string removeOccurrences(string s, string part) {
            int n=s.size();
            int m=part.size();
            string ans;
            for(int i=0;i<n;i++){
                ans.push_back(s[i]);
                bool changes=true;
                while(changes){
                    changes=false;
                    if(ans.size()>=m && ans[ans.size()-1]==part[m-1]){
                        bool matches=true;
                        int j=m-1;
                        int sptr=ans.size()-1;
                        while(j>=0 && sptr>=0){
                            if(ans[sptr]!=part[j]){
                                matches=false;
                                break;
                            }
                            j--;
                            sptr--;
                        }
                        if(matches){
                            for(int i=0;i<m;i++) ans.pop_back();
                            changes=true;
                        }
                    }
                }
            }
            return ans;
        }
    };