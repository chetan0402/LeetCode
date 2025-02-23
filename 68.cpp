#include<vector>
#include<string>
using namespace std;

class Solution {
    public:
        vector<string> fullJustify(vector<string>& words, int maxWidth) {
            vector<string> ans;
            int start=0;
            int end=0;
            int cur_len=words[0].size();
            while(start<=end && end<words.size()){
                while(end+1<words.size() && cur_len+words[end+1].size()+1<=maxWidth){
                    end++;
                    cur_len+=words[end].size()+1;
                }
                if(cur_len==maxWidth || end==words.size()-1){
                    string cur;
                    for(int i=start;i<=end;i++){
                        cur+=words[i];
                        cur.push_back(' ');
                    }
                    cur.resize(maxWidth,' ');
                    ans.push_back(cur);
                }else{
                    string cur;
                    if(start==end){
                        cur+=words[start];
                        cur.resize(maxWidth,' ');
                    }else{
                        auto padding=(maxWidth-cur_len)/(end-start);
                        int extra=maxWidth-padding*(end-start)-cur_len;
                        for(int i=start;i<=end;i++){
                            cur+=words[i];
                            if(i==end) continue;
                            if(extra){
                                cur+=string(padding+2,' ');
                                extra--;
                            }else cur+=string(padding+1,' ');
                        }
                    }
                    ans.push_back(cur);
                }
                start=end+1;
                end=start;
                if(end<words.size()) cur_len=words[end].size();
            }
            return ans;
        }
    };