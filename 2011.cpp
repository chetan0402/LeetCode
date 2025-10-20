class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x=0;
        for(auto&op:operations){
            if(op[0]=='+' || op.back()=='+') x++;
            if(op[0]=='-' || op.back()=='-') x--;
        }
        return x;
    }
};