#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string,string> top;
        for(auto&a:allowed) top[a.substr(0,2)].push_back(a[2]);

        unordered_map<string,bool> memo;

        auto dfs=[&](auto&self,string&cur)->bool{
            if(cur.size()==1) return true;
            if(memo.count(cur)) return memo[cur];

            auto build=[&](auto&buildself,int i,string&next)->bool{
                if(i+1>=cur.size()) return self(self,next);
                for(auto c:top[cur.substr(i,2)]){
                    next.push_back(c);
                    if(buildself(buildself,i+1,next)) return true;
                    next.pop_back();
                }
                return false;
            };

            string next;
            return memo[cur]=build(build,0,next);
        };

        return dfs(dfs,bottom);
    }
};
