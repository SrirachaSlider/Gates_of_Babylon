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

bool evalGate(const Gate &g, const vector<bool> &values) {
    bool a = values[g.ind1];
    bool b = values[g.ind2];

    if (g.type == "NOT") return !a;
    if (g.type == "AND") return a && b;
    if (g.type == "OR") return a || b;
    if (g.type == "NAND") return !(a && b);
    if (g.type == "NOR") return !(a || b);
    if (g.type == "XOR") return a ^ b;
    return false;
}

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
	cout << "Welcome to the Gates of Babylon!\nHow many inputs does your logic block have? (1 to 10)\n";
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
	
	vector<int> used(inputs + gates.size(), 0);
    for (int g = 0; g < gates.size(); g++) {
        used[gates[g].ind1]++;
        used[gates[g].ind2]++;
    }
    for (int i = 0; i < inputs; i++) {
        if (used[i] != 1) die();
    }
    for (int g = 0; g < gates.size() - 1; g++) {
        int index = inputs + g;
        if (used[index] != 1) die();
    }

	cout << "\n1) Print Circuit Block or 2) Print Truth Table\n";
	int choice;
	cin >> choice;
    if (choice == 1) {
        for (int i = 0; i < inputs; i++) {
            cout << "Gate Type: INPUT\n";
            cout << "   Input Connected to Index: N.C. and N.C.\n";

            cout << "   Output Connected to Index: ";
            bool found = false;
            for (int g = 0; g < gates.size(); g++) {
                if (gates[g].ind1 == i || gates[g].ind2 == i) {
                    cout << (inputs + g) << "\n";
                    found = true;
                    break;
            }
        }
        if (!found) cout << "OUTPUT PIN\n";
        cout << "   Value: X\n\n";
    }
    for (int g = 0; g < gates.size(); g++) {
        cout << "Gate Type: " << gates[g].type << "\n";
        cout << "   Input Connected to Index: "
             << gates[g].ind1 << " and " << gates[g].ind2 << "\n";
        if (g == gates.size() - 1)
            cout << "   Output Connected to Index: OUTPUT PIN\n";
        else
            cout << "   Output Connected to Index: " << (inputs + g + 1) << "\n";
        cout << "   Value: X\n\n";
        }
    }

    if (choice == 2) {
        for (int i = 0; i < inputs; i++) {
            cout << "In" << i << " ";
        }
        cout << "| OUT\n";
        cout << string(inputs * 4 + 5, '-') << "\n";

        int rows = 1 << inputs;
        for (int r = 0; r < rows; r++) {
            vector<bool> values;

            for (int i = 0; i < inputs; i++) {
                bool bit = (r >> (inputs - i - 1)) & 1;
                values.push_back(bit);
                cout << " " << bit << " ";
            }

            for (auto &g : gates) {
                bool out = evalGate(g, values);
                values.push_back(out);
            }

            cout << "|  " << values.back() << "\n";
        }
    }

}
