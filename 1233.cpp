#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        sort(folder.begin(),folder.end());
        int index1=0;
        int index2=0;
        while(index1<folder.size()){
            index2=index1+1;
            ans.push_back(folder[index1]);
            while(index2<folder.size()){
                if(
                    folder[index1]==folder[index2].substr(0,folder[index1].size()) &&
                    folder[index2].size()>folder[index1].size() &&
                    folder[index2][folder[index1].size()] == '/'
                ) index2++;
                else{
                    index1=index2-1;
                    break;
                }
            }
            if(index2==folder.size()) break;
            index1++;
        }
        return ans;
    }
};