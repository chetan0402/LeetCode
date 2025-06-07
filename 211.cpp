#include<vector>
#include<string>
using namespace std;

class Node{
    public:
    bool leaf;
    vector<Node*> child;
    Node(){
        leaf=false;
        child=vector<Node*>(26,nullptr);
    }
};

class WordDictionary {
    Node* root;
public:
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        Node*cur=root;
        for(auto c:word){
            if(cur->child[c-'a']==nullptr) cur->child[c-'a']=new Node();
            cur=cur->child[c-'a'];
        }
        cur->leaf=true;
    }
    
    bool search(string word) {
        return _search(root,word,0);
    }

    bool _search(Node*myroot,string&word,int start){
        if(myroot==nullptr) return false;
        if(start==word.size()) return myroot->leaf;
        char chr=word[start];
        if(chr=='.'){
            for(auto&node:myroot->child) if(_search(node,word,start+1)) return true;
            return false;
        }
        return (myroot->child[chr-'a'] && _search(myroot->child[chr-'a'],word,start+1));
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */