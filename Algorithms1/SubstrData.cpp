#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    string numletter="0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	string password = numletter.substring(11,12);
	password = password + numletter.substring(18,19);
	password = password + numletter.substring(23,24);
	password = password + numletter.substring(16,17);
	password = password + numletter.substring(24,25);
	cout<<password;
    system("PAUSE");
    return EXIT_SUCCESS;
}
