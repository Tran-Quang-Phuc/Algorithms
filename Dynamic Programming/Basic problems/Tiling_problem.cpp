// Given a “2 x n” board and tiles of size “2 x 1”, 
// count the number of ways to tile the given board using the 2 x 1 tiles. 

/* Let count(n) be the count of ways to place tiles on a "2 * n" grid
   1. If the first tile is vertical, count(n) = count(n-1)
   2. If the first tile is hozirontal, count(n) = count(n -2)
   => count(n) = count(n-1) + count(n-2)   // a fibonaci sequence
*/

#include <bits/stdc++.h>

using namespace std;

int count(int n) {
    
    int count_ways_1 = 1;
    int count_ways_2 = 2;

    for(int i = 3; i <= n; i++)
    {
        count_ways_2 = count_ways_1 + count_ways_2;
        count_ways_1 = count_ways_2 - count_ways_1;
    }
   
    return count_ways_2;
}

// Time complexcity: O(n)
// Space complexity: O(1)

int main() {
    int n;
    cin >> n;
    cout << "The numbers of ways to tile the board has size of 2 * n are: " <<  count(n);
    cout << endl;
}