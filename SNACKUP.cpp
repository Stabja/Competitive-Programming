#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define LL long long int
#define mp make_pair
#define pb push_back

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<n<<"\n";
        int k = 1;
        for(int i = 1; i <= n; i++){
            cout<<n<<"\n";
            k = 1;
            for(int j = i; j <= n; j++){
                int x = (j+n)%n;
                int y = (j+1+n)%n;
                if(x == 0){
                    cout<<k<<" "<<n<<" "<<y<<"\n";
                }
                else if(y == 0){
                    cout<<k<<" "<<x<<" "<<n<<"\n";
                }
                else{
                    cout<<k<<" "<<x<<" "<<y<<"\n";
                }
                k++;
            }
            for(int j = 1; j < i; j++){
                int x = (j+n)%n;
                int y = (j+1+n)%n;
                if(x == 0){
                    cout<<k<<" "<<n<<" "<<y<<"\n";
                }
                else if(y == 0){
                    cout<<k<<" "<<x<<" "<<n<<"\n";
                }
                else{
                    cout<<k<<" "<<x<<" "<<y<<"\n";
                }
                k++;
            }
        }
    }
    return 0;
}
