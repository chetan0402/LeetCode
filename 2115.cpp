#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<string>
using namespace std;

class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            auto n=recipes.size();
            unordered_set<string> got(supplies.begin(),supplies.end());
            vector<int> indegree(n,0);
            unordered_map<string,vector<string>> dependency;
            for(int i=0;i<n;i++){
                for(auto ingredient:ingredients[i]){
                    if(got.find(ingredient)==got.end()){
                        indegree[i]++;
                        dependency[ingredient].push_back(recipes[i]);
                    }
                }
            }
    
            unordered_map<string,int> recipeToIdx;
            for(int i=0;i<n;i++) recipeToIdx[recipes[i]]=i;
            
            queue<int> q;
            for(int i=0;i<n;i++) if(indegree[i]==0) q.push(i);
    
            vector<string> ans;
            while(!q.empty()){
                auto i=q.front();
                q.pop();
                auto recipe=recipes[i];
                ans.push_back(recipe);
                if(!dependency.count(recipe)) continue;
                for(auto&dependingRecipe:dependency[recipe]){
                    indegree[recipeToIdx[dependingRecipe]]--;
                    if(indegree[recipeToIdx[dependingRecipe]]==0) q.push(recipeToIdx[dependingRecipe]);
                }
            }
            return ans;
        }
    };