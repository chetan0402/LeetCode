#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        vector<int> findSubstring(string s, vector<string>& words) {
            auto n=s.size();
            auto wLen=words[0].size();
            unordered_map<string,int> cnt;
            for(auto word:words) cnt[word]++;
            vector<int> ans;
            for(int offset=0;offset<wLen;offset++){
                int ptr1=offset;
                int ptr2=ptr1;
                unordered_map<string,int> found;
                int totalFound=0;
                while(ptr1<=ptr2 && ptr2+wLen<=n){
                    auto tmpStr=s.substr(ptr2,wLen);
                    if(cnt.count(tmpStr)){
                        found[tmpStr]++;
                        totalFound++;
                        if(totalFound==words.size()){
                            bool fail=false;
                            for(auto [key,value]:cnt){
                                if(found[key]!=value){
                                    auto removeStr=s.substr(ptr1,wLen);
                                    found[removeStr]--;
                                    totalFound--;
                                    ptr1+=wLen;
                                    fail=true;
                                    break;
                                }
                            }
                            if(!fail){
                                ans.push_back(ptr1);
                                auto removeStr=s.substr(ptr1,wLen);
                                found[removeStr]--;
                                totalFound--;
                                ptr1+=wLen;
                            }
                        }
                        ptr2+=wLen;
                    }else{
                        ptr1=ptr2+wLen;
                        ptr2=ptr1;
                        found.clear();
                        totalFound=0;
                    }
                }
            }
            return ans;
        }
    };