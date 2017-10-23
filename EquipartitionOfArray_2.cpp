#include<iostream>
using namespace std;

void TOWImpl(int t[], int size)
{
   // make initial guess, put odd and even index elements into two groups
   std::sort(t, t + size); // O(nlog(n))
   int part1 = 0;
   int part2 = 0;
   for (int i = 0; i <= size - 2; i += 2)
   {
         part1 += t[i];
         part2 += t[i + 1];
   }

   int min_diff = INT_MAX;
   int curr_diff = abs(part1 - part2);
   while (curr_diff < min_diff)
   {
      min_diff = curr_diff;
      //Swap elements whos difference is most close the the part sum difference.
      //Then recalculate difference.
      int half_diff = abs(part1 - part2) / 2;
      int min_diff_sofar = INT_MAX;

      int start = 0;
      if(part1 < part2) start++;
      int id1, id2;
      for(int i = start; i < size; i += 2)
      {
         for (int j = start - 1; j < i; j += 2)
         {
            int min_diff_local = abs(t[i] - t[j] - half_diff);
            if(min_diff_local <= min_diff_sofar)
            {
               min_diff_sofar = min_diff_local;
               id1 = i;
               id2 = j;
            }
         }
      }

      std::cout << "min diff is: " << min_diff_sofar << ". t[i] = " << t[id1] << ", t[j] = " << t[id2] << "\n";
      if (id1 & 1)
      {
         part2 -= (t[id1] - t[id2]);
         part1 -= (t[id2] - t[id1]);
      }
      else
      {
         part1 -= (t[id1] - t[id2]);
         part2 -= (t[id2] - t[id1]);
      }
      if (curr_diff > abs(part1 - part2))
      {
         std::swap(t[id1], t[id2]);
         curr_diff = abs(part1 - part2);
      }

      if (curr_diff == 0 || curr_diff == 1)
         break; // found solution

   }

   // show the partition
   int sum = 0;
   for (int i = 0; i < size; i += 2)
   {
      sum += t[i];
      std::cout << t[i] << " ";
   }
   std::cout << " --> sum = " << sum << std::endl;
   sum = 0;
   for (int i = 1; i < size; i += 2)
   {
      sum += t[i];
      std::cout << t[i] << " ";
   }
   std::cout << " --> sum = " << sum << std::endl;
}

int main(){

    return 0;
}
