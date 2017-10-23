#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define edge pair<int, int>

int main(){
    vector<pair<int, int> > pieces[100];
    pieces[0].push_back(edge(7, 5));
    pieces[0].push_back(edge(1, 2));
    pieces[0].push_back(edge(47, 18));
    pieces[0].push_back(edge(71, 54));
    pieces[0].push_back(edge(39, 25));
    pieces[1].push_back(edge(10, 3));
    pieces[1].push_back(edge(41, 23));
    pieces[1].push_back(edge(63, 37));
    pieces[2].push_back(edge(45, 81));
    pieces[3].push_back(edge(12, 16));
    pieces[3].push_back(edge(17, 36));
    pieces[3].push_back(edge(56, 21));
    pieces[3].push_back(edge(76, 67));
    pieces[4].push_back(edge(39, 48));
    pieces[4].push_back(edge(14, 15));
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < pieces[i].size(); j++){
            cout<<"("<<pieces[i].at(j).first<<","<<pieces[i].at(j).second<<")   ";
        }
        cout<<"\n";
    }
    return 0;
}

