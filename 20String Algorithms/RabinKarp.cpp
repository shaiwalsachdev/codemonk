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
#define MAX 100000


void rabinkarp(string text,string pattern){
	int n = text.length();
	int m = pattern.length();
	int t = 0;
	int p = 0;
	int h = 1;
	int prime = 101;
	int d = 256;  
	for(int i = 0;i < m-1;i++){
		h = (h*d)%prime;
	}

	// Hash for pattern
	for(int i = 0;i < m;i++){
		p = (d*p + pattern[i])%prime;
		t = (d*t + text[i])%prime;
	}

	for(int i = 0;i <= n-m;i++){
		if(p==t){
			int j;
			for(j = 0;j < m;j++){
				if(text[i+j] != pattern[j])
					break;
			}
			if(j==m){
				cout << "Pattern found at " << i << endl;
			}
		}
		if(i < n-m){
			t =  (d*(t - text[i]*h) + text[i+m])%prime;
			if(t < 0)
				t = t + prime;

		}
	}

}

int main(){
	string text;
	string pattern;
	cout << "Enter Text" <<endl;
 	cin >> text;
 	cout << "Enter Pattern" << endl;
 	cin >> pattern;
	rabinkarp(text,pattern);
	return 0;
}