#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int takeCharacters(string s, int k) {
        if(k==0) return 0;
        int n=s.size();
        if(n<3*k) return -1;
        vector<int> count(3,0);
        for(int i=0;i<n;i++) count[s[i]-'a']++;
        for(int i=0;i<3;i++) if(count[i]<k) return -1;
        vector<int> window(3,0);
        int left=0;
        int maxWindow=0;
        for(int right=0;right<n;right++){
            window[s[right]-'a']++;
            while(left<=right && (count[0] - window[0] < k || count[1] - window[1] < k || count[2] - window[2] < k)){
                window[s[left]-'a']--;
                left++;
                }
                maxWindow=max(maxWindow,right-left+1);
        }
        return n-maxWindow;
    }
};