#include<iostream>
using namespace std;

void Heapify(int *array,int index,int n){
    int left=2*index+1;
    int right=2*index+2;
    int current=index;
    if(left<n && array[index]<array[left]){
        int temp=array[index];
        array[index]=array[left];
        array[left]=temp;
        current=left;
        Heapify(array,current,n);
    }
    if(right<n && array[index]<array[right]){
        int temp=array[index];
        array[index]=array[right];
        array[right]=temp;
        current=right;
        Heapify(array,current,n);
    }
}

int Delete(int *array,int n){
    int temp=array[0];
    array[0]=array[n-1];
    Heapify(array,0,n-1);
    return temp;
}

void HeapSort(int *array,int n){
    for(int i=n-1;i>=0;i--){
        Heapify(array,i,n);
    }
    for(int i=0;i<n;i++){
        int temp=Delete(array,n-i);
        array[n-1-i]=temp;
    }
}

int main(){
    int n;
    cout<<"\n Enter the number of elements present in the array:";
    cin>>n;
    int *array=new int[n];
    cout<<"\n Enter the elements of the array:";
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    HeapSort(array,n);
    cout<<"\n The elements of the array after sorting:";
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}
