#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        vector<int> factoryFlat;
        for(auto&fac:factory){
            for(int i=0;i<fac[1];i++) factoryFlat.push_back(fac[0]);
        }
        vector<vector<long long>> memo(robot.size(),vector<long long>(factoryFlat.size(),-1));
        return cal(0,0,robot,factoryFlat,memo);
    }

    long long cal(int robot_i,int fac,vector<int>&robot,vector<int>&factory,vector<vector<long long>>&memo){
        if(robot_i==robot.size()) return 0;
        if(fac==factory.size()) return 1e12;
        if(memo[robot_i][fac]!=-1) return memo[robot_i][fac];
        long long take = abs(robot[robot_i] - factory[fac]) + cal(robot_i+1,fac+1,robot,factory,memo);
        long long skip = cal(robot_i,fac+1,robot,factory,memo);

        return memo[robot_i][fac]=min(take,skip);
    }
};