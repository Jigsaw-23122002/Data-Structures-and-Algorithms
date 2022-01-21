//PRIORITY QUEUE IS ONE OF THE APPLICATION OF THE BINARY HEAPS.
//STL's Inbuilt priority queue uses the max-binary-heap from the queue as the header file/Library.

#include<iostream>
#include<queue>
using namespace std;

void PriorityQueueSorting(int *array,int n){
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        pq.push(array[i]);
    }
    for(int i=0;i<pq.size();i++){
        array[n-1-i]=pq.top();
        pq.pop();
    }
}

int main(){
    int n,*array;
    cout<<"\n Enter the number of elements needed in the array:";
    cin>>n;
    array=new int[n];
    cout<<"\n Enter the elements in the array:";
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    PriorityQueueSorting(array,n);
    cout<<"\n The elements of the array after sorting:";
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}