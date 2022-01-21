/*
Hashing is the process used for the faster access of the elements from the large data.
Similar type of hashing is used in the Count/Turbo sort.
In this, we used the basic hash Function i.e
        h(x)=x
That is the index at which the element is stored is the value of that index.
But in such cases the space complexity is worst as in case of the small data having very large value of the elements...
almost 90% of the space is left un-used.
For eg:
        Consider the small data having the elements : 234 , 56 , 7 , 453 , 98
        In the above case we have to create the array of size atleast 454 so that it can accomaodate the highest element.

So inorder to avoid such exploitation of the space, we have to optimize the hashing function and the hahsing algorithm.
One such algorithm is used in the Radix Sort i.e.
        h(x,i)=(x/pow(10,i))%10

*/

//Basic trivial Hashing function of the strings.
#include<iostream>
#include<vector>
using namespace std;

class node{
    public:
    vector<string> database; 
};

class Hashing{
    private:
    node *hashTable=new node[10];
    public:
    void hashData(string &s){
        int index=s.length()%10;
        hashTable[index].database.push_back(s);
    }
    void hashedTable(){
        for(int i=0;i<10;i++){
            cout<<"\n "<<i<<" ==> ";
            for(int j=0;j<hashTable[i].database.size();j++){
                cout<<hashTable[i].database[j]<<" , ";
            }
        }
    }
    vector<int> findData(string &s){
        int search_index=s.length()%10;
        for(int i=0;i<hashTable[search_index].database.size();i++){
            if(hashTable[search_index].database[i]==s){
                return {search_index,i};
            }
        }
        return {-1,-1};
    }
};

int main(){
    int n;
    Hashing h;
    string s,find;
    cout<<"\n Enter the number of strings required to be entered:";
    cin>>n;
    cout<<"\n Enter the strings in the Hash Table:";
    for(int i=0;i<n;i++){
        cin>>s;
        h.hashData(s);
    }
    cout<<"\n Enter the string to be searched in the data entered earlier:";
    cin>>find;
    vector<int> answer=h.findData(find);
    if(answer[0]==-1){
        cout<<"\n The string was never entered in the database.";
    }
    else{
        cout<<"\n The string was entered earlier and is present in the bin "<<answer[0]<<" and the index "<<answer[1]<<" of the hashTable.";
    }
    cout<<"\n The hash Table for the verification:";
    h.hashedTable();
    return 0;
}

/*
Sample input:
number of strings=7
strings=
addncvu
axccdfgghh
wdedglikdfdf
adsd
asdfeddfgdfgdfsggggfgfd
advefcvv
adfsadfafccffgbbb
*/