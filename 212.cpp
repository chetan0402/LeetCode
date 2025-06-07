#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

class Trie{
    public:
    bool leaf;
    string word;
    vector<Trie*> child;
    Trie(){
        leaf=false;
        child.assign(26,nullptr);
    }

    void add(string&word){
        Trie*cur=this;
        for(auto chr:word){
            int c=chr-'a';
            if(cur->child[c]==nullptr) cur->child[c]=new Trie();
            cur=cur->child[c];
        }
        cur->leaf=true;
        cur->word=word;
    }
};

const vector<pair<int,int>> dirs={{1,0},{0,1},{-1,0},{0,-1}};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n=board.size();
        int m=board[0].size();
        Trie*trie=new Trie();
        for(auto&word:words) trie->add(word);

        unordered_set<string> ans;
        vector<vector<bool>> vis(n,vector<bool>(m,false));

        auto backtrack=[&](auto&self,int i,int j,Trie*root)->void{
            if(i<0 || i>=n || j<0 || j>=m) return;
            if(vis[i][j]) return;
            vis[i][j]=true;
            root=root->child[board[i][j]-'a'];
            if(root==nullptr){
                vis[i][j]=false;
                return;
            };
            if(root->leaf) ans.emplace(root->word);
            for(auto [dx,dy]:dirs) self(self,i+dx,j+dy,root);
            vis[i][j]=false;
        };

        for(int i=0;i<n;i++) for(int j=0;j<m;j++) backtrack(backtrack,i,j,trie);

        return vector<string>(ans.begin(),ans.end());
    }
};