#include<vector>
using namespace std;

class MyCircularQueue {
    int size;
    vector<int> arr;
    int front=-1;
    int rear=-1;
public:
    MyCircularQueue(int k) {
        arr=vector<int>(k);
        size=k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        if(isEmpty()){
            front=0;
            rear=0;
            arr[rear]=value;
        }else{
            rear=(rear+1)%size;
            arr[rear]=value;
        }
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        front=(front+1)%size;
        if((front==0 && rear==size-1)||(rear+1==front)){
            rear=-1;
            front=-1;
        }
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return arr[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        return (front==-1 && rear==-1);
    }
    
    bool isFull() {
        return ((front==0 && rear==size-1)|| (rear+1==front) );
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */