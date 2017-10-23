#include<bits/stdc++.h>
#include<cmath>
using namespace std;

int main(){
    int n, a, b, c, P, maxx = 0;
    cin>>n>>a>>b>>c;
    for(int x = 0; x <= floor(n/a); x++){
        for(int y = 0; y <= floor(n/b); y++){
            float z = (float)(n - a*x - b*y)/c;
            if(z - floor(z) == 0 && z >= 0){
                P = x + y + z;
                if(P > maxx){
                    maxx = P;
                    cout<<maxx<<" "<<x<<" "<<y<<" "<<z<<"\n";
                }
            }
        }
    }
    cout<<maxx;
    return 0;
}
