// Naive algorithm for building suffix array of a given text
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct suffix
{
    int index;
    char *suff;
};

bool cmp(struct suffix a, struct suffix b)
{
    return strcmp(a.suff, b.suff) < 0? 1 : 0;
}

int *buildSuffixArray(char *txt, int n)
{
    struct suffix suffixes[n];
    for (int i = 0; i < n; i++)
    {
        suffixes[i].index = i;
        suffixes[i].suff = (txt+i);        //This copies the entire suffix, not just the character
    }
    /*for(int i = 0; i < n; i++){
        cout<<suffixes[i].suff<<"\n";
    }*/
    sort(suffixes, suffixes+n, cmp);
    int *suffixArr = new int[n];
    for (int i = 0; i < n; i++){
        suffixArr[i] = suffixes[i].index;
        cout<<suffixes[i].suff<<"\n";
    }
    return  suffixArr;
}

void printArr(int arr[], int n)
{
    cout<<"\n";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    char txt[] = "thisisfuckinbullshit";
    int n = strlen(txt);
    int *suffixArr = buildSuffixArray(txt,  n);
    printArr(suffixArr, n);
    return 0;
}
