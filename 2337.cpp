#include<string>

using namespace std;

class Solution {
public:
    bool canChange(string start, string target) {
        int n=start.size();
        int s_ptr=0;
        int t_ptr=0;
        while(s_ptr<n && t_ptr<n){
            if(target[t_ptr]=='_'){
                t_ptr++;
            }else if(start[s_ptr]=='_'){
                s_ptr++;
            }else if(start[s_ptr]!=target[t_ptr]) return false;
            else{
                if(start[s_ptr]=='L') if(t_ptr>s_ptr) return false;
                if(start[s_ptr]=='R') if(s_ptr>t_ptr) return false;
                t_ptr++;
                s_ptr++;
            }
        }
        while(s_ptr<n){
            if(start[s_ptr]=='_') s_ptr++;
            else return false;
        }
        while(t_ptr<n){
            if(target[t_ptr]=='_') t_ptr++;
            else return false;
        }
        return (s_ptr==n && t_ptr==n);
    }
};