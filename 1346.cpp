#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> visited;
        for(int i=0;i<arr.size();i++){
            if(exists(visited,2*arr[i])) return true;
            if(arr[i]%2==0 && exists(visited,arr[i]/2)) return true;
            visited.insert(arr[i]);
        }
        return false;
    }

    inline bool exists(unordered_set<int> s,int data){
        return s.find(data)!=s.end();
    }
};