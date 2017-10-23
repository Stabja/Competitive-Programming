#include<iostream>
#include <queue>
using namespace std;

struct vertex
{
    int v;
    int dist;
};

int MinThrows(int move[], int N)
{
    bool *visited = new bool[N];
    for (int i = 0; i < N; i++)
        visited[i] = false;

    queue<vertex> q;
    visited[0] = true;
    vertex s = {0, 0};
    q.push(s);

    vertex qe;
    while (!q.empty())
    {
        qe = q.front();
        int v = qe.v;
        if (v == N-1)
            break;

        q.pop();
        for (int j=v+1; j<=(v+6) && j<N; ++j)
        {
            if (!visited[j])
            {
                vertex a;
                a.dist = (qe.dist + 1);
                visited[j] = true;

                if (move[j] != -1)
                    a.v = move[j];
                else
                    a.v = j;
                q.push(a);
            }
        }
    }
    return qe.dist;
}

int main()
{
    int N = 100, T, x, y, a, b;
    int moves[N];
    cin>>T;
    while(T--){
        for (int i = 0; i<N; i++){
            moves[i] = -1;
        }
        cin>>x;
        while(x--){
            cin>>a>>b;
            moves[a-1] = b-1;
        }
        cin>>y;
        while(y--){
            cin>>a>>b;
            moves[a-1] = b-1;
        }
        int z = MinThrows(moves, N);
        if(z < 6){
            cout<<z;
        }else{
            cout<<-1;
        }
    }
    return 0;
}
