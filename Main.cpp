// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

const int Num_Alphabet = 26;

class plugboard{
public:
	plugboard(int arrayIn[Num_Alphabet]);
	virtual ~plugboard();
	void process();
private:
	int array[Num_Alphabet];
	int arrayInput[Num_Alphabet];
};

plugboard::~plugboard() {
}

plugboard::plugboard(int arrayIn[Num_Alphabet]) :
{
	arrayInput = arrayIn;
	int i;
	for (i = 0; i < Num_Alphabet; i++) {
		array[i] = i;
	}
}

void plugboard::process() {
	int i;
	int exchange_a;
	int exchange_b;
	int value_a;
	int value_b;
	for (i = 0; i < Num_Alphabet; i += 2) {
		if (arrayInput[i] > 25) {
			break;
		}
		exchange_a = arrayInput[i];
		exchange_b = arrayInput[i + 1];
		value_a = array[exchange_a];
		value_b = array[exchange_b];
		array[exchange_b] = value_a;
		array[exchange_a] = value_b;
	}
}

string readinput() {
	string input;
	string tmp;
	int i = 0;
	try {
		while (!cin.fail()) {
			cin >> ws >> tmp;
			if (isupper(tmp[i])) {
				input += tmp[i];
			} else {
				throw -1;
			}
		}
		cout << input << endl;
	} catch (int e) {
		cerr << "Exception occurred. Not upper character." << endl;
	}
	return input;
}

int main(int argc, char **argv) {
	int numberoffile = argc - 1;
	basic_ifstream<char>* file;

	for (int i = 0; i < numberoffile - 1; i++) {
		file[i].open(argv[i + 1]);
		int arrayIn[26];
		for (int j = 0; j < Num_Alphabet; j++) {
			file[i] >> arrayIn[j];
		}
		file[i].close();
	}
	
	int arrayIn[26];
	for (int i = 0; i < Num_Alphabet; i++) {
		file[numberoffile - 1].open(argv[numberoffile]);
		j = 0;
		int tmp;
		while (file[numberoffile - 1] >> tmp) {
			arrayIn[j] = tmp;
			j++;
		}
		if (j < Num_Alphabet - 1) {
			arrayIn[j] = 50;
		}
	}
	
	// No idea what this part does
	{
		plugboard plug(arrayIn);
		string input = readinput();
		for (i = 0; i < input.length(); i++) {
			plug.process();
		}
	}
	
	return 0;
}
