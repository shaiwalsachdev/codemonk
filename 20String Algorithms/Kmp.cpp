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
int lps[MAX];


void kmpmatcher(string text,string pattern){
	int n = text.length();
	int m = pattern.length();
	int j = 0;
	int i = 0;
	while(i < n){
		if(text[i] == pattern[j]){
			i++;
			j++;
		}
		if(j == m){
			cout << "Found at positon  " << (i-j)<< endl;
			j = lps[j-1];
		}
		else if(i < n && text[i] != pattern[j]){
			if(j != 0){
				j = lps[j-1];
			}
			else{
				i++;
			}
		}

	}
}

void buildlps(string pattern){
	int m = pattern.length();
	lps[0] = 0;
	int len = 0;
	int i = 1;
	while(i < m){
		if(pattern[i] == pattern[len]){
			len++;
			lps[i] = len;
			i++;
		}
		else {
			if(len==0){
				lps[i] = 0;
				i++;
			}
			else{
				len = lps[len-1];
			}
		}

	}
}


int main(){
	string text;
	string pattern;
	cout << "Enter the Text" << endl;
	cin >> text;

	cout << "Pattern to search" << endl;
	cin >> pattern;

	
	buildlps(pattern);
	kmpmatcher(text,pattern);

	return 0;
}