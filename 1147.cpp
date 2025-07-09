#include<string>
using namespace std;

class Solution {
    int solve(string text,int start,int end){
        if(start==end) return 1;
        if(start>end) return 0;

        int chunkStart=end;
        while(true){
            while(start<=chunkStart && text[start]!=text[chunkStart]) chunkStart--;
            int ptr1=start;
            int ptr2=chunkStart;
            bool found=true;
            while(ptr2<=end){
                if(text[ptr1]!=text[ptr2]){
                    chunkStart--;
                    found=false;
                    break;
                }else{
                    ptr1++;
                    ptr2++;
                }
            }
            if(start==chunkStart) return 1;
            if(found) return 2+solve(text,ptr1,chunkStart-1);
        }

        return 0;
    }
public:
    int longestDecomposition(string text) {
        return solve(text,0,text.size()-1);
    }
};