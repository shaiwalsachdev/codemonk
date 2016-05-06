/*Our code monk, high on excitement after solving the rest of the problems ,
 goes on a trek in the mountains . 
On his way, he encounters Janemba, the evil magician! 
Janemba takes our monk to a poison field and plays a game with him described as follows: 
The poison field is described as NxN matrix,divided into N * N cells. 
Each cell of the field has a value of discomfort in it pertaining to the poison content. 
Monk has been cursed with K curses. In each curse, the monk must do one of the following: 

1) Choose one row of the field and consume the poisonous fumes 
from all the cells in that row. 
The discomfort caused is the sum of discomfort from each cell in the row. 
After consuming, the discomfort of all cells in the row increases by one.

2) Choose one column of the field and consume the poisonous fumes from all the 
cells in that column. 
The discomfort caused is the sum of discomfort from each cell in the column. 
After consuming, the discomfort of all cells in the column increases by one. 

Our monk has a level of tolerance. A very high level of discomfort will cause him to die! 
Help him out by finding the Minimum discomfort possible by optimally completing the curses.

Input:
First line contains T, the number of test cases. T test cases follow. 
First line of each test case contains two space separated integers N and K. N lines follow. Each of the lines contains N space-separated integers representing Mij, the value of discomfort of cells in that row.

Output: 
For each test case, output the minimum discomfort possible in a new line.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 200
1 ≤ K ≤ 400
1 ≤ Mij ≤ 1000

Sample Input(Plaintext Link)
 4
2 1
1 3
2 4
2 2
1 3
2 4
2 3
1 3
2 4
2 4
1 3
2 4
Sample Output(Plaintext Link)
 3
8
14
22
Explanation
Test Case #4: 
Initial state:
1 3
2 4
The monk chooses the first column, discomfort=3 . Elements change to 
2 3
3 4 
He now chooses the first row, discomfort=3+5=8 . Elements change to 
3 4
3 4
He chooses the first column, discomfort= 8+6=14. Elements change to
4 4
4 4
He chooses the second column, discomfort=14+8=22


*/
/*Now , we can see that we have to store all of the row sums and column sums separately . Let them be stored in R and C array. Now , we can see that if we sort both of the arrays , then in each operation if we choose a row the relative order of the sorted C does not change just that each value increases by 1 and vice versa .

So , we can calculate the two arrays SR[i] and SC[i] which are defined as , SR[i] is the minimum sum of rowsum if i times a row was chosen and similarly SC[i] is the minimum sum of colsum if i times a column was chosen .

Let us see how SC[i] will be built :

for i = 1 to K :
      IR = row index with minimum rowsum from the current set of rowsums
      SR[i] = SR[i-1] + IR
      update the IRth row's sum by adding N
Similarly SC[i] can be calculated. Now the step where we find IR can be done using a priority queue or simple traversing the rowsum array since the constraints and time limit allow for it . The time complexity of the respective methods will be O(KlogN) and O(KN).

Now , the use of this two arrays in calculating the answer is like this , we try to choose row operations i times , due to which we will choose the column operations K - i times . The discomfort value would then be val = SR[i] + SC[k-i] + i*(K-i) .

The term i*(K-i) is the increment due to each operation which needs to be added to the final calculation of discomfort value.

Then if ans is the minimum discomfort value then it can be calculated as ,

ans = INF
for i = 0 to K :
      ans = min(ans,SR[i] + SC[K-i] + i*(K-i))
Thus the overall will be O(TKlogN) if priority queue is used , else it will be O(TKN).

Complexity : O(TKlogN)
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


int main()
{
	int t;
	int n,k;
	si(t);

	while(t--){
		scanf("%d %d",&n,&k);
		vector<ll> row,column;
		vector<ll> timesrow,timescolumn; // Number Of Times Row selected timesrow[i] i times row selected min sum
		
		row.clear();
		row.resize(n+1);
		column.resize(n+1);
		timesrow.clear();
		timescolumn.clear();
		timesrow.resize(k+1);
		timescolumn.resize(k+1);
		int a[n+1][n+1]; // Matrix
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= n;j++){
				si(a[i][j]);
				row[i] += a[i][j];
				column[j] += a[i][j]; 
			}
		}
		// Storing row and column sum into row and column

		row[0] = column[0] = -1; // This is so bcoz when we sort first element is this
		for(int i=1;i<=k;i++){
			sort(row.begin(),row.end());
			sort(column.begin(),column.end());

			ll min = row[1];
			
			timesrow[i] = timesrow[i-1] + min;
			row[1] += n;
			 min = column[1];
			timescolumn[i] = timescolumn[i-1] + min;
			column[1] += n;
		}

		// Now for all combinations of number of times row chosen or column chosen
		// We will find the min sum  
		ll answer = 1e18;
		for(int i =0;i<=k;i++)
			answer = min(answer,timesrow[i]+timescolumn[k-i]+(i*(k-i)));
		pl(answer);
		pn;
	}
	return 0;

}