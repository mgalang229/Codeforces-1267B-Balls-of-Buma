#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	// create two pointers:
	// from = start at the beginning of the string
	// to = start at the end of the string
	int from = 0;
	int to = (int) s.size() - 1;
	int cnt = 3; // make sure that all the letters (except for the middle character) have frequency of at least 3
	while (from < to && s[from] == s[to] && cnt >= 3) {
		char letter = s[from];
		cnt = 0;
		// check if every letter at the beginning has a matching letter starting at the end of the string
		// don't forget to count the frequency of the characters (the middle character should be the only
		// letter which has a frequency that is greater than or equal to 2)
		while (s[from] == letter) {
			from++;
			cnt++;
		}
		while (s[to] == letter && to >= from) {
			to--;
			cnt++;
		}
	}
	int ans = 0;
	// the answer exists iff the two pointers (from and to) managed to go past each other and the frequency
	// of the middle character (letter) is greater than or equal to 2, otherwise we can't eliminate the colors
	if (from > to && cnt >= 2) {
		ans = cnt + 1;
	}
	cout << ans << '\n';
	return 0;
}
