#include<iostream>
using namespace std;

int BinarySearch(int *array,int low,int high,int m){
    if(high<low){
        return -1;
    }
    else{
        int mid=(low+high)/2;
        if(array[mid]==m){
            return mid;
        }
        else if(array[mid]>m){
            return BinarySearch(array,low,mid-1,m);
        }
        else{
            return BinarySearch(array,mid+1,high,m);
        }
    }
}

int main(){
    int n,m;
    int *array;
    cout<<"\n Enter the number of elements present in the array:";
    cin>>n;
    array=new int[n];
    cout<<"\n Enter the elements in the array in the sorted way:";
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    cout<<"\n Enter the element to be searched in the array:";
    cin>>m;
    int answer=BinarySearch(array,0,n-1,m);
    if(answer==-1){
        cout<<"\n The element is not present in the given array.";
    }
    else{
        cout<<"\n The element is present in the given array and the index at which the element is present:"<<answer;
    }
    return 0;
}