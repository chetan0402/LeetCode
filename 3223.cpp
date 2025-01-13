#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        vector<int> arr(26,0);
        for(auto c:s) arr[c-'a']++;
        int result=0;
        for(int i=0;i<26;i++){
            if(arr[i]==0) continue;
            if(arr[i]%2) result++;
            else result+=2;
        }
        return result;
    }
};