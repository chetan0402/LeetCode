#include<set>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    int maxUniqueSplit(string s) {
        set<string> answer;
        for(int i=0;i<s.size();i++){
            for(int j=1;j<=s.size()-i;j++){
                cout << s.substr(i,j) << endl;
                if(answer.find(s.substr(i,j))==answer.end()){
                    answer.insert(s.substr(i,j));
                    i+=j-1;
                    break;
                }
            }
        }
        return answer.size();
    }
};

int main(){
    Solution sol;
    sol.maxUniqueSplit("wwwzfvedwfvhsww");
}