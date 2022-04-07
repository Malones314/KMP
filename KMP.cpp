#include<iostream>
#include<vector>
using namespace std;
void getNext ( vector<int>& next, string s ) {
	int i;		//后缀末尾
	int j;		//前缀末尾，并且也是i之前(包括i)字串最长相等前后缀的长度
	j = 0;
	next [0] = 0;
	for ( i = 1; i < s.size ( ); i++ ) {
		while ( j > 0 && s [i] != s [j] )
			j = next [j - 1];
		if ( s [i] == s [j] )
			j++;
		next [i] = j;
	}
	for ( auto k : next )
		cout << k << " ";
}
int main ( ) {
	string s = "12332111222";                       //待匹配的字符串
	string t = "1233211222341212332111222323111";   //原始串
	vector<int>next ( s.length ( ) );
	getNext ( next, s );
	int i, j;
	for ( i = 0, j = 0; i < t.length ( ) && j < s.length ( ); i++ ) {
		while ( j > 0 && t [i] != s [j] )
			j = next [j - 1];
		if ( t [i] == s [j] )
			j++;
	}
	if ( j == s.length ( ) )
		cout << "right";
	return 0;
}
