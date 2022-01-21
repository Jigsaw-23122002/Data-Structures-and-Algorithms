#include<iostream>
#include<vector>
using namespace std;

void Insert(vector<int> &dynamic,int n,int inserting_element){
    dynamic.push_back(inserting_element);
    bool status=false;
    int index=n;
    while(status==false){
        if(index%2==0){
            if(dynamic[index]>dynamic[(index-2)/2]){
                int temp=dynamic[index];
                dynamic[index]=dynamic[(index-2)/2];
                dynamic[(index-2)/2]=temp;
                index=(index-2)/2;
            }
            else{
                status=true;
            }
        }
        else{
            if(dynamic[index]>dynamic[(index-1)/2]){
                int temp=dynamic[index];
                dynamic[index]=dynamic[(index-1)/2];
                dynamic[(index-1)/2]=temp;
                index=(index-1)/2;
            }
            else{
                status=true;
            }
        }
    }
}

int main(){
    int n,inserting_element;
    cout<<"\n Enter the number of elements present in the max-heap:";
    cin>>n;
    vector<int> dynamic(n);
    cout<<"\n Enter the elements in the max-Heap:";
    for(int i=0;i<n;i++){
        cin>>dynamic[i];
    }
    cout<<"\n Enter the element to be inserted in the max-Heap:";
    cin>>inserting_element;
    Insert(dynamic,n,inserting_element);
    cout<<"\n The max-Heap obtained after inserting an element:";
    for(int i=0;i<=n;i++){
        cout<<dynamic[i]<<" ";
    }
    return 0;
}