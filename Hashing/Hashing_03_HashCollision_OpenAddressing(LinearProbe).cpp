/*
Open Addressing is the another technique for avoiding the hashing collision.
In this, If we encounter the situation where the lement is already present in the hash position than the new element 
is placed in the next empty position.
For having this type of collision handling....we must ensure that the while adding an element there must be atleast one
position in the hash table which must empty.
The best case time complexity of this method of handling the collision is O(1) but the worst case can be O(N).
*/

#include<iostream>
using namespace std;

class hashing{
    private:
    int *hashTable=new int[10];
    public:
    hashing(){
        for(int i=0;i<10;i++){
            hashTable[i]=-1;
        }
    }
    void HashData(int n){
        int index=n%10;
        if(hashTable[index]==-1){
            hashTable[index]=n;
        }
        else{
            int i=index;
            do{
                i=(i+1)%10;
            }while(i!=index && hashTable[i]!=-1);
            if(i==index){
                cout<<"\n The Hash Table is Exhausted. No more data can be Hashed.";
            }
            else{
                hashTable[i]=n;
            }
        }
    }
    void HashedTable(){
        for(int i=0;i<10;i++){
            cout<<hashTable[i]<<" , ";
        }
    }
    int findData(int n){
        int index=n%10;
        if(hashTable[index]==n){
            return index;
        }
        else{
            int i=index;
            do{
                i=(i+1)%10;
            }while(hashTable[i]!=n && i!=index);
            if(hashTable[i]==n){
                return i;
            }
            else{
                return -1;
            }
        }
    }
};

int main(){
    int n,temp,find;
    hashing h;
    cout<<"\n Enter the data to be Hashed in the Hash Table:";
    cin>>n;
    cout<<"\n Enter the elements in the hash Table:";
    for(int i=0;i<n;i++){
        cin>>temp;
        h.HashData(temp);
    }
    cout<<"\n Enter the element to be searched in the Hash Table:";
    cin>>find;
    int answer=h.findData(find);
    if(answer==-1){
        cout<<"\n The element is not present in the Hash Table.";
    }
    else{
        cout<<"\n The element is present in the Hash Table.";
    }
    cout<<"\n The Hash Table for the verification:";
    h.HashedTable();
    return 0;
}