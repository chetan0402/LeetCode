#include<string>

using namespace std;

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        if(str2.size()>str1.size()) return false;
        int ptr1=0;
        int ptr2=0;
        while(ptr1<str1.size() && ptr2<str2.size()){
            if(str1[ptr1]==str2[ptr2] || nextChar(str1[ptr1])==str2[ptr2]) ptr2++;
            ptr1++;
        }
        return ptr2==str2.size();
    }

    char nextChar(char c){
        return c == 'z' ? 'a' : c+1;
    }
};