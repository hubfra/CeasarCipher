
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	char alphabet[]{ 'A','B','C','D','E','F','G','H','I',
					 'J','K','L','M','N','O','P','Q','R',
					 'S','T','U','V','W','X','Y','Z','0',
					 '1','2','3','4','5','6','7','8','9' };


	string fileName = "";
	char action = '1';
	short key = 0;

	ifstream input;
	ofstream output;

	cout << "Enter the file name: ";
	cin >> fileName;
	cout << "\nEncrypt - 1\nDecrypt - 2\n";
	cout << "Choose action: ";
	cin >> action;
	cout << "\nEnter the key: ";
	cin >> key;

	key %= 36;

	if (action == '2')
		key = 36 - key;


	input.open(fileName);
	output.open("out" + fileName);

	if (!input.is_open() || !output.is_open())
		return 0;

	char c;

	while (input >> noskipws >> c)
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
