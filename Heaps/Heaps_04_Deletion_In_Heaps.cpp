//Deletion in the binary heap involves placing the last element on the first position and then heapifying the first position. 
#include<iostream>
#include<vector>
using namespace std;

void Heapify(vector<int> &dynamic,int i,int n){
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && dynamic[i]<dynamic[left]){
        int temp=dynamic[i];
        dynamic[i]=dynamic[left];
        dynamic[left]=temp;
        Heapify(dynamic,left,n);
    }
    if(right<n && dynamic[i]<dynamic[right]){
        int temp=dynamic[i];
        dynamic[i]=dynamic[right];
        dynamic[right]=temp;
        Heapify(dynamic,right,n);
    }
}

int Delete(vector<int> &dynamic,int n){
    int deleted_element=dynamic[0];
    dynamic[0]=dynamic[n-1];
    Heapify(dynamic,0,n);
    return deleted_element;
}

int main(){
    int n,inserting_element;
    cout<<"\n Enter the number of elements present in the max-heap:";
    cin>>n;
    vector<int> dynamic(n);
    cout<<"\n Enter the elements in the max-Heap:";
    for(int i=0;i<n;i++){
        cin>>dynamic[i];
    }
    Delete(dynamic,n);
    cout<<"\n The max-Heap obtained after Deleteing an element:";
    for(int i=0;i<n-1;i++){
        cout<<dynamic[i]<<" ";
    }
    return 0;
}