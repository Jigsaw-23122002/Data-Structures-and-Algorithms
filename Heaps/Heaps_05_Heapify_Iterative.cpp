#include<iostream>
using namespace std;

void Heapify(int *array,int n){
    for(int i=n-1;i>=0;i--){
        int leftChild=2*i+1;
        int rightChild=2*i+2;
        int index=i;
        while(leftChild<n && rightChild<n && array[index]<max(array[leftChild],array[rightChild])){
            if(array[leftChild]<array[rightChild]){
                int temp=array[index];
                array[index]=array[rightChild];
                array[rightChild]=temp;
                index=rightChild;
                leftChild=2*index+1;
                rightChild=2*index+2;
            }
            else{
                int temp=array[index];
                array[index]=array[leftChild];
                array[leftChild]=temp;
                index=leftChild;
                leftChild=2*index+1;
                rightChild=2*index+2;
            }
        }
        while(leftChild<n && rightChild==n && array[index]<array[leftChild]){
            int temp=array[leftChild];
            array[leftChild]=array[index];
            array[index]=temp;
            index=leftChild;
            leftChild=2*index+1;
            rightChild=2*index+2;
        }
    }
}

int main(){
    int n;
    cout<<"\n Enter the number of elements in the array to be Heapified:";
    cin>>n;
    int *array=new int[n];
    cout<<"\n Enter the elements in the array:";
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    Heapify(array,n);
    cout<<"\n The Heapified Array:";
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}