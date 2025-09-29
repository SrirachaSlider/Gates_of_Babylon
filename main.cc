#include <iostream>
#include <string>
#include <vector>
using namespace std;

void die() {
	cout << "BAD INPUT!\n";
	exit(1);
}

struct Gate {
	string type;
	int ind1;
	int ind2;
};

void indeces(int &ind1, int &ind2) {
	cout << "Give the index for the first input:\n";
	cin >> ind1;
	if (ind1 < 0) die();
	cout << "Give the index for the second input:\n";
	cin >> ind2;
}

//bool test(const int &ind1, const int &ind2, )

/*auto get_type(auto type) {
  return type;
  }*/

int main() {
	//vector<int> index;
	int inputs = 0;
	cout << "Welcome to the Gates of Babylon\nHow many inputs does you logic block have? (1 to 10)\n";
	cin >> inputs;
	if (inputs < 1 or inputs > 10) die();
	vector<Gate> gates;
	//for (int i = 0; i < inputs; i++) gates.push_back("");
	int gate = 0;
	int ind1 = 0, ind2 = 0;
	while (cin) {
		cout << "What sort of gate do you want to add?\n0 - NOT, 1 - AND, 2 - OR, 3 - NAND, 4 - NOR, 5 - XOR, 6 - DONE\n";
		cin >> gate;
		Gate myGate;
		if (gate == 0) {
			indeces(ind1, ind2);
			myGate.ind1 = ind1;
			myGate.ind2 = ind2;
			myGate.type = "NOT";
			gates.push_back(myGate);
		}
		else if (gate == 1) {
			indeces(ind1, ind2);
			myGate.ind1 = ind1;
			myGate.ind2 = ind2;
			myGate.type = "AND";
			gates.push_back(myGate);
		}
		else if (gate == 2) {
			indeces(ind1, ind2);
			myGate.ind1 = ind1;
			myGate.ind2 = ind2;
			myGate.type = "OR";
			gates.push_back(myGate);
		}
		else if (gate == 3) {
			indeces(ind1, ind2);
			myGate.ind1 = ind1;
			myGate.ind2 = ind2;
			myGate.type = "NAND";
			gates.push_back(myGate);
		}
		else if (gate == 4) {
			indeces(ind1, ind2);
			myGate.ind1 = ind1;
			myGate.ind2 = ind2;
			myGate.type = "NOR";
			gates.push_back(myGate);
		}
		else if (gate == 5) {
			indeces(ind1, ind2);
			myGate.ind1 = ind1;
			myGate.ind2 = ind2;
			myGate.type = "XOR";
			gates.push_back(myGate);
		}
		else if (gate == 6) {
			break;
		}
		else die();
		//cout << myGate.type << endl;
	}
	cout << "\n1) Print Circuit Block or 2) Print Truth Table\n";
	int choice;
	cin >> choice;
	if (choice == 1) {}
	if (choice == 2) {
		for (int i = 0; i < inputs; i++) {
			cout << i << "|";
		}
		cout << "O\n";
	}

}
