#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int leftt[100001];
int rightt[100001];
int ans[100001];
stack<int> s;

void display(int n){
    for(int i=0; i < n; i++)
        cout<<rightt[i]<<" ";
    cout<<endl;
    for(int i=0; i < n; i++)
        cout<<leftt[i]<<" ";
    cout<<endl;
    for(int i=0; i < n; i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}

void printMaxOfMin(int arr[], int n)
{
    for(int i=0; i<n; i++){
        leftt[i] = -1;
        rightt[i] = n;
    }

    for(int i=0; i<n; i++)    //Next Greater Element Logic
    {
        while (!s.empty() && arr[s.top()] <= arr[i])
            s.pop();
        if (!s.empty())
            leftt[i] = s.top();
        s.push(i);
    }
    while (!s.empty())
        s.pop();

    for(int i=n-1; i>=0; i--)    //Next Greater Element Logic
    {
        while (!s.empty() && arr[s.top()] <= arr[i])
            s.pop();
        if(!s.empty())
            rightt[i] = s.top();
        s.push(i);
    }

    for(int i=0; i<n; i++)
    {
        ans[i] = rightt[i]-leftt[i]-1;
    }
    display(n);
}

int main()
{
    int arr[] = {4, 6, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    printMaxOfMin(arr, n);
    return 0;
}
