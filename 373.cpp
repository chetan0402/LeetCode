#include<vector>
#include<queue>
#include<set>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> minHeap;

        set<pair<int,int>> visited;

        minHeap.push({nums1[0]+nums2[0],{0,0}});
        visited.insert({0,0});

        while(k--){
            auto [_, position]=minHeap.top();
            auto [i, j]=position;
            minHeap.pop();

            ans.push_back({nums1[i],nums2[j]});

            if(i+1<nums1.size() && !visited.count({i+1,j})){
                minHeap.push({nums1[i+1]+nums2[j],{i+1,j}});
                visited.insert({i+1,j});
            }
            if(j+1<nums2.size() && !visited.count({i,j+1})){
                minHeap.push({nums1[i]+nums2[j+1],{i,j+1}});
                visited.insert({i,j+1});
            }
        }

        return ans;
    }
};