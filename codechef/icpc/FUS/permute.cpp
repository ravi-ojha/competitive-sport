#include <iostream>
#include <string>
using namespace std;
void permute( string prefix, string s )
{
	if ( s.size() <= 1  )
		cout <<prefix <<s <<"\n";
	else
		for ( char *p = s.begin(); p <s.end(); p++ )
		{
			char c = *p;
			s.erase( p );
			permute( prefix + c, s );
			s.insert( p, c );
		}
}
main()
{
	permute( "", "12345" );
	return 0;
}
