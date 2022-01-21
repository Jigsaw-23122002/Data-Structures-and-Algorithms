//This is same as the array representation of the queues.

#include<iostream>
using namespace std;

class queue{
    private:
    int queue_array[6];
    int queue_size=0;
    int front=0;
    int back=0;

    public:
    void push(int n){
        int index=(back+1)%6;
        if(index==front){
            cout<<"\n The queue space is exhausted (queue overflow).";
        }
        else{
            queue_size++;
            queue_array[index]=n;
            back=index;
        }
    }
    void pop(){
        if(front==back){
            cout<<"\n The queue is empty (no elements to pop).";
        }
        else{
            front=(front+1)%6;
            queue_size--;
            cout<<"\n The popped element : "<<queue_array[front];
        }
    }
    void display(){
        if(front==back){
            cout<<"\n Queue is Empty.";
        }
        else{
            cout<<"\n The queue : ";
            int index=front;
            while(index!=back){
                cout<<queue_array[(index+1)%6]<<" ";
                index=(index+1)%6;
            }
        }
    }
};

int main(){
    queue q;
    cout<<"\n Testing the Queue : ";
    q.pop();
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.display();
    q.pop();
    q.display();
    q.pop();
    q.push(60);
    q.display();
    q.pop();
    q.pop();
    q.pop();
    q.display();
    q.pop();
    q.pop();
    q.display();
    q.push(70);
    q.display();
    q.push(80);
    q.push(90);
    q.push(100);
    q.push(110);
    q.display();
    q.push(120);
    return 0;
}