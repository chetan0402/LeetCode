#include<vector>
#include<string>
using namespace std;

class Trie {
    vector<pair<bool,Trie*>> nodes;
public:
    Trie() {
        nodes.assign(27,{false,nullptr});
    }
    
    void insert(string word) {
        _insert(word,0);
    }

    void _insert(string&word,int start){
        if(start==word.size()){
            nodes.back().first=true;
            return;
        }
        int chr=word[start]-'a';
        nodes[chr].first=true;
        if(nodes[chr].second==nullptr) nodes[chr].second=new Trie();
        nodes[chr].second->_insert(word,start+1);
    }
    
    bool search(string word) {
        return _search(word,0);
    }

    bool _search(string&word,int start){
        if(start==word.size()) return nodes.back().first;
        int chr=word[start]-'a';
        auto [exist, child]=nodes[chr];
        return (exist && child && child->_search(word,start+1));
    }
    
    bool startsWith(string prefix) {
        return _starts(prefix,0);
    }

    bool _starts(string&prefix,int start){
        int chr=prefix[start]-'a';
        auto [exist, child]=nodes[chr];
        if(start==prefix.size()-1) return exist;
        return (exist && child && child->_starts(prefix,start+1));
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */