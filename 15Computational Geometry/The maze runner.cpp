/*
One more nightmare... This time you got into a maze.

The maze is described by two polylines. 
Each of them has N + 1 points. 
The points of the first polyline are: (x0, y0), (x2, y2), ... , (xN, yN). 
The points of the second polyline are (x0, y0 + H), (x2, y2 + H), ... , (xN, yN + H).

The entrance to the maze is a segment (x0, y0) - (x0, y0 + H) 
and the exit is a segment (x0, y0) - (xN, yN + H). 
During your running in the maze you can be in any point inside the maze.

The faster you go through the maze - the more chances to survive you have.
 You know description of the the maze. 
 Find the length of the shortest path you have to run.

Input
The first line contains one integer N.
The following N + 1 
lines contains 2 space-separated integers each - description of the first polyline.
The last line contains one integer H.

Output
Ouput one real number with exactly 10 digits after dot - 
the shortest distance you have to cover.

Constraints

1 <= N <= 100
|xi|, |yi|, H <= 104
x0 < x1 < ... < xN
Sample Input(Plaintext Link)
 2
0 0
2 2
3 -1
2
Sample Output(Plaintext Link)
 3.4142135624

*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define si(a)     scanf("%d", &a)
#define sl(a)     scanf("%lld", &a)
#define pi(a)     printf("%d", a)
#define pl(a)     printf("%lld", a)
#define pm(str)   printf("%s\n",str)
#define pn        printf("\n")

int main(){

	
	return 0;
}