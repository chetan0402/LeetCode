#include<string>
#include<vector>
using namespace std;

class Solution {
    public:
        string simplifyPath(string path) {
            if(path.back()!='/') path.push_back('/');
            auto n=path.size();
            vector<string> truePath;
            string temp;
            for(int i=0;i<n;i++){
                if(path[i]!='/') temp+=path[i];
                else{
                    if(temp==".") {}
                    else if(temp=="..") {
                        if(truePath.size()) truePath.pop_back();
                    }else if(temp.size()) truePath.push_back(temp);
                    temp.clear();
                }
            }
            string build="";
            for(auto s:truePath) build+=("/"+s);
            return build.size()?build:"/";
        }
    };