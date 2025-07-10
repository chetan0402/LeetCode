#include<vector>
using namespace std;

class SmallestInfiniteSet {
    vector<bool> exist;
    int start=1;
public:
    SmallestInfiniteSet() {
        exist.assign(1000+1,true);
    }
    
    int popSmallest() {
        for(int i=1;i<=1000;i++) if(exist[i]){
            exist[i]=false;
            return start=i;
        }
        return 0;
    }
    
    void addBack(int num) {
        exist[num]=true;
        start=min(start,num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */