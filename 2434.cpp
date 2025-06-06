#include<vector>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    string robotWithString(string s) {
        vector<int> cnt(128,0);
        for(auto c:s) cnt[c]++;

        stack<char> st;
        string result;
        char minChar='a';
        for(auto c:s){
            st.emplace(c);
            cnt[c]--;
            while(minChar!='z' && cnt[minChar]==0) minChar++;
            while(!st.empty() && st.top()<=minChar){
                result+=st.top();
                st.pop();
            }
        }

        return result;
    }
};