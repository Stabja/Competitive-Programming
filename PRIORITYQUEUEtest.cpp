 #include <iostream>
 #include <queue>
 using namespace std;

#define mp make_pair

 struct compare
 {
   bool operator()(pair<int, int>& l, pair<int, int>& r)
   {
       return l.first > r.first;
   }
 };

 int main()
 {
     //priority_queue<int,vector<int>, compare > pq;
     priority_queue<pair<int, int>,vector<pair<int, int> >, compare > pq;

     pq.push(mp(34, 1));
     pq.push(mp(27, 2));
     pq.push(mp(56, 3));
     pq.push(mp(13, 4));
     pq.push(mp(45, 5));
     while ( !pq.empty() )
     {
         cout << pq.top().second << endl;
         pq.pop();
     }
     cin.get();
 }
