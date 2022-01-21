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

void ShellSort(int *array,int n){
    int initialSteps=n-1;
    for(int i=initialSteps;i>0;i=function(i)){
        int j=0;
        while(j+i<n){
            if(array[j]>array[j+i]){
                int swap=array[j];
                array[j]=array[j+i];
                array[j+i]=swap;
            }
            j++;
        }
        if(i==1){
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
    ShellSort(array,n);
    cout<<"\n The sorted array obtained after the Shell Sort:";
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}