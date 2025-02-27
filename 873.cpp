#include<unordered_set>
#include<vector>
#include<unordered_map>
using namespace std;

class SolutionBrute {
    int getLen(unordered_set<int>&exist,int a,int b){
        if(exist.find(a+b)!=exist.end()){
            return 1+getLen(exist,b,a+b);
        }else return 0;
    }
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        auto n=arr.size();
        unordered_set<int> exist(arr.begin(),arr.end());
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans=max(ans,getLen(exist,arr[i],arr[j]));
            }
        }
        if(ans==0) return 0;
        return ans+2;
    }
};

class SolutionDP {
    int getLen(unordered_map<int,int>&numToI,int i,int j,vector<vector<int>>&memo,vector<int>&arr){
        if(memo[i][j]!=-1) return memo[i][j];
        if(numToI.find(arr[i]+arr[j])!=numToI.end()){
            memo[i][j]=getLen(numToI,j,numToI[arr[i]+arr[j]],memo,arr);
            return 1+memo[i][j];
        }else return 0;
    }
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        auto n=arr.size();
        unordered_map<int,int> numToI;
        for(int i=0;i<n;i++) numToI[arr[i]]=i;
        int ans=0;
        vector<vector<int>> memo(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans=max(ans,getLen(numToI,i,j,memo,arr));
            }
        }
        if(ans==0) return 0;
        return ans+2;
    }
};