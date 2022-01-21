#include<iostream>
#include<limits.h>
using namespace std;

void QuickSort(int *array,int low,int high){
    if(low<high){
        int pivot=array[low];
        int i=low+1;
        int j=high-1;
        while(i<j){
            while(array[i]<=pivot){
                i++;
            }
            while(array[j]>pivot){
                j--;
            }
            if(i<j){
                int swap=array[i];
                array[i]=array[j];
                array[j]=swap;
            }
        }
        if(array[j]<=pivot){
            int swap=array[j];
            array[j]=array[low];
            array[low]=swap;
        }
        QuickSort(array,low,j);
        QuickSort(array,j+1,high);
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
    QuickSort(array,0,n);
    cout<<"\n The sorted array obtained after the Quick Sort:";
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}