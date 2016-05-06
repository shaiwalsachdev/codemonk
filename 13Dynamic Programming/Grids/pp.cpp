#include <iostream>
#include <stdio.h>
 
using namespace std;
 
int main() {
	int t, n;
	int a,b,c, a1, b1, c1;
 
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		a1 = b1 = c1 = 0;
		for(int i = 1; i <= n; ++i) {
			scanf("%d %d %d",&a, &b, &c);
			a += min(b1, c1);
			b += min(a1, c1);
			c += min(a1, b1);
			a1 = a;
			b1 = b;
			c1 = c;
		}
 
		printf("%d\n", min(min(a, b), c));
 
	}
 
	return 0;
}