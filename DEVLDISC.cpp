#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        if(n < 7){
            cout<<-1<<"\n";
        }
        else if(n == 8){
            cout<<n+1<<"\n";
            for(int i = 1; i < n; i++){
                cout<<i<<" "<<i+1<<"\n";
            }
            cout<<8<<" "<<2<<"\n";
            cout<<6<<" "<<8<<"\n";
            cout<<3<<"\n";
        }
        else{
            cout<<n<<"\n";
            if(n%2 == 1){
                for(int i = 1; i < n; i++){
                    cout<<i<<" "<<i+1<<"\n";
                }
                cout<<n<<" "<<2<<"\n";
                cout<<3<<"\n";
            }
            else{
                for(int i = 1; i < n; i++){
                    cout<<i<<" "<<i+1<<"\n";
                }
                cout<<n<<" "<<3<<"\n";
                cout<<4<<"\n";
            }
        }
    }
    return 0;
}
