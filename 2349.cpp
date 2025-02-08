#include<unordered_map>
#include<set>
using namespace std;

class NumberContainers {
    unordered_map<int,int> num;
    unordered_map<int,set<int>> numToi;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        numToi[num[index]].erase(index);
        if(numToi[num[index]].empty()) numToi.erase(num[index]);
        num[index]=number;
        numToi[number].insert(index);
    }
    
    int find(int number) {
        auto it=numToi.find(number);
        if(it!=numToi.end()) return (*it->second.begin());
        else return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */