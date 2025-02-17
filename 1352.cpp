#include<vector>
using namespace std;

class ProductOfNumbers {
    vector<int> suffix={1};
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num==0) suffix={1};
        else suffix.push_back(suffix.back()*num);
    }
    
    int getProduct(int k) {
        if(k>suffix.size()-1) return 0;
        else return suffix.back()/suffix[suffix.size()-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */