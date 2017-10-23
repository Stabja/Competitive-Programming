#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> table;
    for(int i = 0; i < 10; i++){
        table.push_back(i*3);
    }
    for(vector<int>::iterator it = table.begin(); it != table.end(); ++it){
        cout<<*it<<"\n";
    }
    return 0;
}
