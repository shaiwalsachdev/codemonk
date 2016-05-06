/*
Guess the triangle
You are given 3 points - middles of the sides of some triangle. Find coordinates of the triangle vertices.

Input
Input has 3 lines with 2 space-separated reals each - coordinates of the middles of the sides.

Output
Output 3 lines with 2 space-separated reals - 
coordinates of the triangle vertices. Each number
 should have exactly 4 digits after dot.
  Vertices should be sorted in first coordinate ascending order. 
  If two points have the same first coordinate than they should have second coordinate ascending order.

Constraints
0 <= xi, yi <= 1000

Sample Input(Plaintext Link)
 5.00 3.00
4.0 4.0
5.0 5.000
Sample Output(Plaintext Link)
 4.0000 2.0000
4.0000 6.0000
6.0000 4.0000
Time Limit: 1 sec(s) for each input file.
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
	double x[3];
	double y[3];
	
	double a,b,c,d,e,f;
	
	// Input
	scanf("%lf %lf",&a,&b);
	scanf("%lf %lf",&c,&d);
	scanf("%lf %lf",&e,&f);


	
	x[0] = a + c - e;
	y[0] = b + d - f;
	
	 
	x[1] = a - c + e;
	y[1] = b - d + f;

	
	
	x[2] = e - a + c;
	y[2] = f - b + d;
	
	
	double mx = x[0];
	double my = y[0];
	int j = 0;
	for(int i = 1;i < 3;i++){
		if(x[i] == mx){
			if(y[i] <= my){
				mx = x[i];
				my = y[i];
				j = i;
			}
		}else if(x[i] < mx){
			mx = x[i];
			my = y[i];
			j = i;
		}
	}
	printf("%.4f %.4f\n",x[j],y[j]);
	int jj;
	for(int i = 0;i < 3;i++){
		if(i==j){
			continue;
		}
		else{
			jj = i;
			break;
		}
	}
	int jj1;
	for(int i = 0;i < 3;i++){
		if(i==jj || i ==j){
			continue;
		}
		else{
			jj1 = i;
			break;
		}
	}

	if(x[jj] == x[jj1]){
		if(y[jj] <= y[jj1]){
			printf("%.4f %.4f\n",x[jj],y[jj]);
			printf("%.4f %.4f\n",x[jj1],y[jj1]);
		}
		else{
			printf("%.4f %.4f\n",x[jj1],y[jj1]);
			printf("%.4f %.4f\n",x[jj],y[jj]);
		}
	}else if(x[jj] < x[jj1]){
		printf("%.4f %.4f\n",x[jj],y[jj]);
		printf("%.4f %.4f\n",x[jj1],y[jj1]);
	}else{
		printf("%.4f %.4f\n",x[jj1],y[jj1]);
		printf("%.4f %.4f\n",x[jj],y[jj]);
	}

	pn;
	return 0;
}