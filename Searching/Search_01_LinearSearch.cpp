#include<iostream>
using namespace std;

int LinearSearch(int *array,int n,int m){
    for(int i=0;i<n;i++){
        if(array[i]==m){
            return i;
        }
    }
    return -1;
}

int main(){
    int n,m;
    int *array;
    cout<<"\n Enter the number of elements present in the array:";
    cin>>n;
    array=new int[n];
    cout<<"\n Enter the elements present in the array:";
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    cout<<"\n Enter the element to be searched in the given array:";
    cin>>m;
    int answer=LinearSearch(array,n,m);
    if(answer==-1){
        cout<<"\n The element is not present in the given array.";
    }
    else{
        cout<<"\n The element is present in the given array and the index at which the element is present:"<<answer;
    }
}