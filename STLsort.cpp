#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(int i, int j){
    return (i < j);
}

int main(){
    vector<int> myVector;
    myVector.push_back(32);
    myVector.push_back(71);
    myVector.push_back(12);
    myVector.push_back(45);
    myVector.push_back(26);
    myVector.push_back(80);
    myVector.push_back(53);
    myVector.push_back(33);
    sort(myVector.begin(), myVector.begin() + 8, compare);
    //Display the contents of the vector
    cout<<"Displaying using at function\n";
    for(int i = 0; i < 8; i++){
        cout<<myVector.at(i)<<" ";
    }
    cout<<"\n\n";
    //Display using iterator
    cout<<"Displaying using iterator\n";
    for(vector<int>::iterator it = myVector.begin(); it!=myVector.end(); ++it){
        cout<<*it<<" ";
    }
    return 0;
}
