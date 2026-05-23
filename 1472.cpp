#include<string>

class DLL{
    public:
    DLL*prev=nullptr;
    DLL*next=nullptr;
    string val;
    DLL(string val){
        this->val=val;
    }
};

class BrowserHistory {
    DLL*cur;
public:
    BrowserHistory(string homepage) {
        this->cur=new DLL(homepage);
    }

    void visit(string url) {
        DLL*next=new DLL(url);
        next->prev=this->cur;
        this->cur->next=next;
        this->cur=next;
    }

    string back(int steps) {
        while(steps--){
            if(this->cur->prev==nullptr) return this->cur->val;
            this->cur=this->cur->prev;
        }
        return this->cur->val;
    }

    string forward(int steps) {
        while(steps--){
            if(this->cur->next==nullptr) return this->cur->val;
            this->cur=this->cur->next;
        }
        return this->cur->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
