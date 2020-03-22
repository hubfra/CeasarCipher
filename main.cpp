
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

	char action = '1';
	int key = 0;

	ifstream input("input.txt");
	ofstream output("output.txt");

	cout << "Encryption - 1\nDecryption - 2\nChoose action(1,2): ";
	cin >> action;
	cout << "\nEnter key: ";
	cin >> key;

	key %= 36;

	if (action == '2')
		key = 36 - key;

	char c;

	input >> noskipws;
	while (input >> c)
	{
		if (c >= 'a' && c <= 'z')
			c -= 32;

		if (c >= '0' && c <= '9')
			output << alphabet[(c - 48 + 26 + key) % 36];
		else if (c >= 'A' && c <= 'Z')
			output << alphabet[(c - 65 + key) % 36];
		else
			output << c;
	}

	input.close();
	output.close();

	return 0;
}
