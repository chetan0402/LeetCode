#include<vector>
#include<queue>
using namespace std;


class SeatManager {
    priority_queue<int,vector<int>,greater<int>> pq;
    int ans=1;
public:
    SeatManager(int n) {}
    
    int reserve() {
        if(pq.size()){
            auto cur=pq.top();pq.pop();
            return cur;
        }
        return ans++;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
