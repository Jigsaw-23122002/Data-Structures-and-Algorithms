#include<iostream>
#include<limits.h>
using namespace std;

void CountSort(int *array,int n){
    int maximum=INT_MIN;
    for(int i=0;i<n;i++){
        if(maximum<array[i]){
            maximum=array[i];
        }
    }
    int *hash=new int[maximum+1];
    for(int i=0;i<=maximum;i++){
        hash[i]=0;
    }
    for(int i=0;i<n;i++){
        hash[array[i]]++;
    }
    int k=0;
    for(int i=0;i<=maximum;i++){
        while(hash[i]!=0){
            array[k]=i;
            k++;
            hash[i]--;
        }
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
    CountSort(array,n);
    cout<<"\n The sorted array obtained after the Count Sort:";
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}