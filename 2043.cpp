#include<vector>
using namespace std;

class Bank {
    vector<long long> bal;
public:
    Bank(vector<long long>& balance) {
        this->bal=balance;
    }
    
    bool transfer(int acc1, int acc2, long long money) {
        if(acc1>bal.size() || acc2>bal.size()) return false;
        acc1--;
        acc2--;

        if(bal[acc1]<money) return false;

        bal[acc1]-=money;
        bal[acc2]+=money;
        return true;
    }
    
    bool deposit(int acc, long long money) {
        if(acc>bal.size()) return false;
        bal[acc-1]+=money;
        return true;
    }
    
    bool withdraw(int acc, long long money) {
        if(acc>bal.size()) return false;
        if(bal[acc-1]<money) return false;
        bal[acc-1]-=money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */