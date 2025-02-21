#include<string>
#include<unordered_set>
#include<vector>
using namespace std;

class SolutionBacktrack {
    bool backtrack(int i,string&ans,unordered_set<string>&unique){
        if(i==ans.capacity()){
            if(unique.count(ans)==0) return true;
            return false;
        }
        ans[i]='0';
        if(unique.count(ans)==0) return true;
        if(backtrack(i+1,ans,unique)) return true;
        ans[i]='1';
        if(unique.count(ans)==0) return true;
        if(backtrack(i+1,ans,unique)) return true;
        return false;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        auto n=nums.size();
        unordered_set<string> unique(nums.begin(),nums.end());
        string ans(n,'0');
        backtrack(0,ans,unique);
        return ans;
    }
};

class SolutionSetTheory {
    public:
        string findDifferentBinaryString(vector<string>& nums) {
            string result="";
            for(int i=0;i<nums.size();i++) result.push_back('0'+'1'-nums[i][i]);
            return result;
        }
    };