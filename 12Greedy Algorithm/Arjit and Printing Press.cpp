/*
Arjit has his own printing press, Bainik Dhaskar (BD). 
He feels that words on their own simply aren't beautiful enough. 
So, he wishes to make a Super Manuscript (SM) machine. Now what does this machine do?
The SM machine aims to make words as beautiful as they can be by making a 
word as lexicographically small as possible. Arjit, being the resourceful person he is, 
has a reserve string from which we can choose characters that will 
replace characters in the original word that BD's SM machine wishes to transform.
Keep in mind that once you have used a letter in the reserve string, it is removed from the reserve.
As Arjit is busy with other work at BD, it's your work to take care of programming SM :)
Note that you cannot modify the original order of the 
letters in the word that has to be transformed. 
You can only replace its letters with those in the reserve.

Input:
The first line of input contains T. T test cases follow.
Each test case has 2 lines.
The first line of each test case has the word W, that has to be transformed.
The second line of each test case has a reserve R from which we will pick letters.

Output:
The output should contain T lines with the answer to each test on a new line.
Print a word P which is the lexicographically smallest 
that can be obtained on replacing letters of W with letters from R.

Constraints:
1 ≤ T ≤ 10
1 ≤ |W| ≤ 104
1 ≤ |R| ≤ 104
W and R will contain only lowercase characters.

See the example to understand this better.

Sample Input(Plaintext Link)
 3
bbbb
aaa
zxewya
abcd
ac
zzzb
Sample Output(Plaintext Link)
 aaab
abcdya
ab
Explanation
In the first test case, we have 3 a's, so we simply replace the first 3 letters of the word.
In the second test case, again we just replace the first 4 letters with 'a', 'b', 'c' and 'd'.
In the third case, 'b' is lexicographically smaller than 'c', so 'ac' becomes 'ab'.

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

int main()
{
	int t;
	si(t);
	while(t--){
		string s,r;

		cin >> s;
		cin >> r;
		vector<char> v;
		for(int i = 0;i < r.length();i++){
			v.push_back(r[i]);
		}
		sort(v.begin(),v.end());
		int y = 0;
		for(int i = 0;i < s.length();i++){
			if(v[y] < s[i] && y < r.length()){
				s[i] = v[y];
				y++;
			}
		}
		printf("%s\n",s.c_str());
	}
	return 0;
}