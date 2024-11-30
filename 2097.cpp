#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int n=pairs.size();
        unordered_map<int,deque<int>> adjMat;
        unordered_map<int,int> inDeg;
        unordered_map<int,int> outDeg;
        for(auto&p:pairs){
            adjMat[p[0]].push_back(p[1]);
            outDeg[p[0]]++;
            inDeg[p[1]]++;
        }
        vector<int> result;

        int start=-1;
        for(auto&entry:outDeg){
            int node=entry.first;
            if(outDeg[node]==inDeg[node]+1){
                start=node;
                break;
            }
        }

        if(start==-1) start=pairs[0][0];

        stack<int> nodes;
        nodes.push(start);

        while(!nodes.empty()){
            int node=nodes.top();
            if(!adjMat[node].empty()){
                int next=adjMat[node].front();
                adjMat[node].pop_front();
                nodes.push(next);
            }else{
                result.push_back(node);
                nodes.pop();
            }
        }

        reverse(result.begin(),result.end());

        vector<vector<int>> ans;
        for(int i=1;i<result.size();i++){
            ans.push_back({result[i-1],result[i]});
        }

        return ans;
    }
};