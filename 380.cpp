#include<unordered_map>
#include<vector>
using namespace std;

class RandomizedSet {
    unordered_map<int,int> numToI;
    vector<int> arr;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        auto it=numToI.find(val);
        if(it==numToI.end()){
            arr.push_back(val);
            numToI[val]=arr.size()-1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        auto it=numToI.find(val);
        if(it==numToI.end()) return false;
        swap(arr[it->second],arr[arr.size()-1]);
        numToI[arr[it->second]]=it->second;
        numToI.erase(it);
        arr.pop_back();
        return true;
    }
    
    int getRandom() {
        return arr[(rand()+arr.size())%arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */