#include<iostream>
using namespace std;

void SelectionSort(int *array,int n){
    for(int i=0;i<n;i++){
        int temp=array[0];
        int index=0;
        for(int j=1;j<n-i;j++){
            if(temp<array[j]){
                temp=array[j];
                index=j;
            }
        }
        int swap=array[n-1-i];
        array[n-1-i]=array[index];
        array[index]=swap;
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
    SelectionSort(array,n);
    cout<<"\n The sorted array obtained after the Selection Sort:";
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}