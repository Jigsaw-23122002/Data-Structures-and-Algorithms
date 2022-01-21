#include<iostream>
using namespace std;

void InsertionSort(int *array,int n){
    for(int i=1;i<n;i++){
        int j=i-1;
        int temp=array[i];
        while(j>=0 && array[j]>temp){
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=temp;
    }
}

int main(){
    int n,m;
    int *array;
    cout<<"\n Enter the number of elements present in the array:";
    cin>>n;
    array=new int[n];
    cout<<"\n Enter the elements in the array:";
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    InsertionSort(array,n);
    cout<<"\n The sorted array obtained after the Insertion Sort:";
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}