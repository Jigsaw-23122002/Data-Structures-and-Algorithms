#include<iostream>
#include<limits.h>
#include<cmath>
#include<vector>
using namespace std;

class bins{
    public:
    vector<int> list;
};

void RadixSort(int *array,int n){
    bins *b=new bins[10];
    int maximum=INT_MIN;
    for(int i=0;i<n;i++){
        if(maximum<array[i]){
            maximum=array[i];
        }
    }
    int digits=0;
    while(maximum>0){
        digits++;
        maximum=maximum/10;
    }
    for(int i=0;i<digits;i++){
        int divisionWith=pow(10,i);
        for(int j=0;j<n;j++){
            b[(array[j]/divisionWith)%10].list.push_back(array[j]);
        }
        int l=0;
        for(int j=0;j<10;j++){
            for(int k=0;k<b[j].list.size();k++){
                array[l]=b[j].list[k];
                l++;
            }
            b[j].list.clear();
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
    RadixSort(array,n);
    cout<<"\n The sorted array obtained after the Quick Sort:";
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}