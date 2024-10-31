#include<vector>
#include<unordered_set>
#include<string>

using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> unique;
        for(auto&email:emails){
            string true_mail;
            bool afterAt = false;
            bool ignorePlus = false;
            for(int i=0;i<email.size();i++){
                char c = email[i];
                
                if (c == '@') {
                    afterAt = true;
                    true_mail += c;
                }
                else if (afterAt) {
                    true_mail += c;
                }
                else if (c == '+') {
                    ignorePlus = true;
                }
                else if (c == '.') {
                    continue;
                }
                else if (!ignorePlus) {
                    true_mail += c;
                }
            }
            unique.insert(true_mail);
        }
        return unique.size();
    }
};