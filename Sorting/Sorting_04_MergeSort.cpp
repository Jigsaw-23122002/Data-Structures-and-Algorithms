#include<iostream>
using namespace std;

void Merge(int *array,int low,int mid,int high){
    int *copy=new int[high-low+1];
    int i=low,j=mid+1,k=0;
    while(i<=mid && j<=high){
        if(array[i]<=array[j]){
            copy[k]=array[i];
            i++;
            k++;
        }
        else{
            copy[k]=array[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        copy[k]=array[i];
        i++;
        k++;
    }
    while(j<=high){
        copy[k]=array[j];
        j++;
        k++;
    }
    for(int i=low;i<=high;i++){
        array[i]=copy[i-low];
    }
}

void MergeSort(int *array,int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        MergeSort(array,low,mid);
        MergeSort(array,mid+1,high);
        Merge(array,low,mid,high);
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
    MergeSort(array,0,n-1);
    cout<<"\n The sorted array obtained after the Merge Sort:";
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}