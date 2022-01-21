#include<iostream>
using namespace std;

int function(int steps){
    if(steps%2==0){
        return steps/2;
    }
    else{
        return steps/2+1;
    }
}

int JumpSearch(int *array,int n,int m){
    int initialStep=n-1;
    for(int i=initialStep;i>0;i=function(i)){
        for(int j=0;j<n;j=j+i){
            if(array[j]==m){
                return j;
            }
        }
        if(i==1){
            break;
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
    cout<<"\n Enter the elements in the array in the sorted way:";
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    cout<<"\n Enter the element to be searched in the array:";
    cin>>m;
    int answer=JumpSearch(array,n,m);
    if(answer==-1){
        cout<<"\n The element is not present in the given array.";
    }
    else{
        cout<<"\n The element is present in the given array and the index at which the element is present:"<<answer;
    }
    return 0;
}