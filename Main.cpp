// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

const int Num_Alphabet = 26;

int mappingA(char alph) {
	return alph - 'A';
}

char mappingI(int number) {
	return 'A' + number;
}
char reflector(char alph) {
	return mappingI((mappingA(alph) + 13) % Num_Alphabet);
}

class component {
protected:
	component(int arrayIn[Num_Alphabet]);
	virtual ~component();
	int array[Num_Alphabet];
//	int arrayInput[Num_Alphabet];
	int * arrayInput;
public:
	int getposition(int position) {
		return array[position];
	}

	int findposition(int number) {
		int i;
		for (i = 0; i < Num_Alphabet; i++) {
			if (array[i] == number) {
				break;
			}
		}
		return i;
	}

	void initial() {
		int i;
		for (i = 0; i < Num_Alphabet; i++) {
			array[i] = i;
		}
	}
	virtual void process();
};

class rotor: public component {
public:
	rotor(int arrayIn[Num_Alphabet]);
	virtual ~rotor();
	virtual void process();
};

class plugboard: public component {
public:
	plugboard(int arrayIn[Num_Alphabet]);
	virtual ~plugboard();
	virtual void process();
};

plugboard::~plugboard() {
}

rotor::~rotor() {
}

component::component(int arrayIn[Num_Alphabet]) {
	arrayInput = arrayIn;
	initial();
//	array<int, 26>
}

void component::process() {
}
component::~component() {
}

rotor::rotor(int arrayIn[Num_Alphabet]) :
		component(arrayIn) {
}

plugboard::plugboard(int arrayIn[Num_Alphabet]) :
		component(arrayIn) {
}

void rotor::process() {

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

string encode(char input, int numofrotor, rotor* rotorlist, plugboard* plug) {
	(*plug).process();

	return "das";
}

int main(int argc, char **argv) {
	int numberoffile = argc - 1;
//	ifstream file[numberoffile];
	basic_ifstream<char>* file;
	int i;
	int j;
	rotor* rotorlist[numberoffile - 1];
	for (i = 0; i < numberoffile - 1; i++) {
		file[i].open(argv[i + 1]);
		string line;
		int arrayIn[26];
		for (j = 0; j < Num_Alphabet; j++) {
			file[i] >> arrayIn[j];
		}
		rotorlist[i] = new rotor(arrayIn);
		file[i].close();
	}
	int arrayIn[26];
	for (i = 0; i < Num_Alphabet; i++) {
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
	plugboard plug(arrayIn);
	string input = readinput();
	for (i = 0; i < input.length(); i++) {
		encode(input[i], numberoffile - 1, rotorlist, plug);
	}
	return 0;

}
