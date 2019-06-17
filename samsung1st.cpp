#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int compute(vector<char> a, vector<char> b){
    int n = a.size();
    int cta = 0, ctb = 0;
    for(auto i : a){
        if(i == '1') cta++;
    }
    for(auto i : b){
        if(i == '1') ctb++;
    }
    if((cta+ctb)%2 != 0) return -1;
    int df = 0;
    for(int i = 0; i < n; i++){
        if(a[i] != b[i]) df++;
    }
    if(df%2 != 0) return -1;
    int c = abs(cta-ctb);
    return df/2;
}

vector<char> a1{ '1', '0', '0', '1' };
vector<char> b1{'0', '1', '0', '1'};

vector<char> a2{'1', '1', '1', '1', '1'};
vector<char> b2{'0', '0', '0', '0', '0'};

vector<char> a3{1, 1, 1, 1, 1, 1, 1, 1};
vector<char> b3{0, 0, 0, 0, 0, 0, 0, 0};

vector<char> a4{1, 1, 0, 0, 1, 1};
vector<char> b4{0, 0, 0, 0, 1, 1};

vector<char> a5{1, 0, 0, 1, 1, 0, 1, 0, 1, 1};
vector<char> b5{0, 0, 0, 0, 1, 0, 0, 1, 0, 0};

vector<char> a6{1, 1, 1, 1, 1, 1, 1};
vector<char> b6{0, 0, 0, 0, 1, 1, 1};


int main() {
    cout<<compute(a1, b1)<<"\n";
    cout<<compute(a2, b2)<<"\n";
    cout<<compute(a3, b3)<<"\n";
    cout<<compute(a4, b4)<<"\n";
    cout<<compute(a5, b5)<<"\n";
    cout<<compute(a6, b6)<<"\n";
    return 0;
}
