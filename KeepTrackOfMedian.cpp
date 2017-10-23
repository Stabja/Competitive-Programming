#include <iostream>
using namespace std;

#define MAX_HEAP_SIZE (128)
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

inline
void Exch(int &a, int &b)
{
    int aux = a;
    a = b;
    b = aux;
}

bool Greater(int a, int b)
{
    return a > b;
}

bool Smaller(int a, int b)
{
    return a < b;
}

int Average(int a, int b)
{
    return (a + b) / 2;
}

// Signum function
// = 0  if a == b  - heaps are balanced
// = -1 if a < b   - left contains less elements than right
// = 1  if a > b   - left contains more elements than right
int Signum(int a, int b)
{
    if( a == b )
        return 0;
    return a < b ? -1 : 1;
}

class Heap
{
    public:
        Heap(int *b, bool (*c)(int, int)) : A(b), comp(c){
            heapSize = -1;
        }
        virtual ~Heap(){
            if( A ){
                delete[] A;
            }
        }
        virtual bool Insert(int e) = 0;
        virtual int  GetTop() = 0;
        virtual int  ExtractTop() = 0;
        virtual int  GetCount() = 0;

    protected:
        int left(int i){
            return 2*i + 1;
        }
        int right(int i){
            return 2 * (i + 1);
        }
        int parent(int i){
            if( i <= 0 )
            {
                return -1;
            }
            return (i - 1)/2;
        }


    int   *A;
    bool  (*comp)(int, int);
    int   heapSize;
    int top(void)
    {
        int max = -1;
        if( heapSize >= 0 )
        {
            max = A[0];
        }
        return max;
    }
    int count()
    {
        return heapSize + 1;
    }
    void heapify(int i)
    {
        int p = parent(i);
        if( p >= 0 && comp(A[i], A[p]) )
        {
            Exch(A[i], A[p]);
            heapify(p);
        }
    }
    int deleteTop()
    {
        int del = -1;
        if( heapSize > -1)
        {
            del = A[0];
            Exch(A[0], A[heapSize]);
            heapSize--;
            heapify(parent(heapSize+1));
        }
        return del;
    }
    bool insertHelper(int key)
    {
        bool ret = false;
        if( heapSize < MAX_HEAP_SIZE )
        {
            ret = true;
            heapSize++;
            A[heapSize] = key;
            heapify(heapSize);
        }
        return ret;
    }
};

class MaxHeap : public Heap
{
    public:
        MaxHeap() : Heap(new int[MAX_HEAP_SIZE], &Greater)  {  }
        ~MaxHeap()  { }
        int GetTop(){
            return top();
        }
        int ExtractTop(){
            return deleteTop();
        }
        int  GetCount(){
            return count();
        }
        bool Insert(int key){
            return insertHelper(key);
        }
};

class MinHeap : public Heap
{
    public:
        MinHeap() : Heap(new int[MAX_HEAP_SIZE], &Smaller) { }
        ~MinHeap() { }
        int GetTop()
        {
            return top();
        }
        int ExtractTop()
        {
            return deleteTop();
        }
        int  GetCount()
        {
            return count();
        }
        bool Insert(int key)
        {
            return insertHelper(key);
        }
};

int getMedian(int e, int &m, Heap &l, Heap &r)
{
    int sig = Signum(l.GetCount(), r.GetCount());
    switch(sig)
    {
    case 1: // There are more elements in left (max) heap
        if( e < m ) // current element fits in left (max) heap
        {
            r.Insert(l.ExtractTop());   // Remore top element from left heap and
                                        // insert into right heap
            l.Insert(e);                // current element fits in left (max) heap
        }
        else
        {
            r.Insert(e);           // current element fits in right (min) heap
        }
        m = Average(l.GetTop(), r.GetTop());

        break;

    case 0: // The left and right heaps contain same number of elements
        if( e < m ) // current element fits in left (max) heap
        {
            l.Insert(e);
            m = l.GetTop();
        }
        else
        {
            r.Insert(e);        // current element fits in right (min) heap
            m = r.GetTop();
        }
        break;

    case -1: // There are more elements in right (min) heap
        if( e < m ) // current element fits in left (max) heap
        {
            l.Insert(e);
        }
        else
        {
            l.Insert(r.ExtractTop());   // Remove top element from right heap and
                                        // insert into left heap
            r.Insert(e);                // current element fits in right (min) heap
        }
        m = Average(l.GetTop(), r.GetTop());
        break;
    }

    return m;
}

void printMedian(int A[], int size)
{
    int m = 0; // effective median
    Heap *left  = new MaxHeap();
    Heap *right = new MinHeap();
    for(int i = 0; i < size; i++)
    {
        m = getMedian(A[i], m, *left, *right);

        cout << m << endl;
    }
    delete left;
    delete right;
}

int main()
{
    int A[] = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
    int size = ARRAY_SIZE(A);

    printMedian(A, size);
    return 0;
}

