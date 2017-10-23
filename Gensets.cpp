#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,a,n) for(int i=a;i<n;i++)
#define MOD 1000000007
#define LL long long int
#define mp make_pair
#define pb push_back
#define fi first
#define se second

int arr[4];

string printPowerSet(int set_size){
    unsigned int pow_set_size = pow(2, set_size);
    int counter, j;
    for(counter = 1; counter < pow_set_size; counter++){
        int sum = 0;
        for(j = 0; j < set_size; j++){
            if(counter & (1<<j)){
                sum += arr[j];
            }
        }
        if(sum == 0){
            return "Yes";
        }
    }
    return "No";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>arr[0]>>arr[1]>>arr[2]>>arr[3];
        string str = printPowerSet(4);
        cout<<str<<"\n";
    }
    return 0;
}
