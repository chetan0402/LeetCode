#include<vector>
#include<string>
#include<cmath>
using namespace std;

class Solution {
    public:
        string getHappyString(int n, int k) {
            if(k>3*pow(2,n-1)) return "";
            string ans;
            switch((k-1)/(1<<(n-1))){
                case 0:
                    ans.push_back('a');
                    break;
                case 1:
                    ans.push_back('b');
                    break;
                case 2:
                    ans.push_back('c');
                    break;
            }
            k=(k-1)%(1<<(n-1));
            auto choices=[](char c)->vector<int>{
                if(c=='a') return vector<int>{1,2};
                if(c=='b') return vector<int>{0,2};
                if(c=='c') return vector<int>{0,1};
                return vector<int>();
            };
            for(int i=1;i<n;i++){
                auto mid=1<<(n-i-1);
                ans.push_back(choices(ans.back())[(k>=mid)]+'a');
                if(k>=mid) k-=mid;
            }
            return ans;
        }
    };