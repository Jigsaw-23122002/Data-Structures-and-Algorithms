#include<iostream>
using namespace std;

void BubbleSort(int *array,int n){
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n-1-i;j++){
            if(array[j]>array[j+1]){
                int temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
                count++;
            }
        }
        if(count==0){
            break;
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
    BubbleSort(array,n);
    cout<<"\n The sorted array obtained after the Bubble Sort:";
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}