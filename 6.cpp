#include<string>
#include<vector>
using namespace std;

class SolutionMemory {
    public:
        string convert(string s, int numRows) {
            auto n=s.size();
            if(numRows==1) return s;
            string ans;
            for(int i=0;i<numRows;i++){
                for(int j=0;j<n;j++){
                    if(j%((numRows-1)*2)==i || (i+j)%((numRows-1)*2)==0) ans.push_back(s[j]);
                }
            }
            return ans;
        }
};

class Solution {
    public:
        string convert(string s, int numRows) {
            auto n=s.size();
            if(numRows==1) return s;
            vector<string> rows(n,"");
            int dir=1;
            int row=0;
            for(auto c:s){
                rows[row].push_back(c);
                row+=dir;
                if(row==numRows-1) dir=-1;
                if(row==0) dir=1;
            }
            string ans;
            ans.reserve(n);
            for(auto&row:rows) ans+=row;
            return ans;
        }
};