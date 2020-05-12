#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int GROUPE_A = 1, GROUPE_B = 2, GROUPE_AB = 4, GROUPE_O = 8;

const int GROUPE_POSSIBLE = GROUPE_A | GROUPE_B | GROUPE_AB | GROUPE_O;
const int GROUPE_IMPOSSIBLE = 0;


int getUnknownParent(const string & parent, const string & enfant) {
	
	if(enfant =="O"){
		if (parent == "AB"){
			return GROUPE_IMPOSSIBLE;
		}
		else {
			return GROUPE_A | GROUPE_B | GROUPE_O;
		}
	}

	else if (enfant == "A"){
		if (parent == "A" || parent == "AB") { // seulement 2 garantissant un A 
			return GROUPE_POSSIBLE;
		}
		else {
			return GROUPE_A | GROUPE_AB;
		}
	}

	else if (enfant == "B"){
		if(parent == "B" || parent == "AB") { // seulement 2 garantissant un B
			return GROUPE_POSSIBLE;
		}else {
			return GROUPE_B | GROUPE_AB;
		}

	}

	// ce qui signifie que l'enfant est 'AB'
	else {
		if(parent =="O"){
			return GROUPE_IMPOSSIBLE;
		}
		else if (parent == "AB") {
			return GROUPE_A | GROUPE_B | GROUPE_AB;
		}
		else if (parent == "A") {
			return GROUPE_B | GROUPE_AB;
		}
		else {
			return GROUPE_A | GROUPE_AB;
		}
	}
}

bool getValue(const string & parent_one, const string & parent_two, const string & value) {
	return parent_one == value || parent_two == value;
}

int findChildUnknown(const string & parent_one, const string & parent_two) {
	if (getValue(parent_one, parent_two, "O")) {
		if (getValue(parent_one, parent_two, "AB")) {
			return GROUPE_A | GROUPE_B;
		}
		else if (getValue(parent_one, parent_two, "A")) {
			return GROUPE_A | GROUPE_O;	
		}
		else if (getValue(parent_one, parent_two, "B")) {
			return GROUPE_B | GROUPE_O;	
		}else {
			return GROUPE_O;	
		}
	}
	else if (getValue(parent_one, parent_two, "AB")) {
		return GROUPE_A | GROUPE_B | GROUPE_AB;	
	}
	
	else if (getValue(parent_one, parent_two, "A")) {
			if (getValue(parent_one, parent_two, "B")) {
				return GROUPE_POSSIBLE;
			}else {
				return GROUPE_A | GROUPE_O;
			}
	}else { // ils sont tous les deux du groupe B
		return GROUPE_B | GROUPE_O;
	}
}

bool NegativeParent(const char & parent, const char & enfant) {
	return (enfant == '-' || parent == '+');
}

bool PositiveChild(const char & parent_one, const char & parent_two) {
	return parent_one == '+' || parent_two == '+';
}

string Separation(const string & full_type, char & facteur_rh) {
	int taille = full_type.size();
	facteur_rh = full_type[taille - 1];
	
	return full_type.substr(0, taille-1);
}

vector<string> generationTypePossible(const int & valeur) {
	vector<string> toute_valeur_possible;
	const int GROUPE_A = 1, GROUPE_B = 2, GROUPE_AB = 4, GROUPE_O = 8;
	
	if(valeur & GROUPE_A)
		toute_valeur_possible.push_back("A");
	if(valeur & GROUPE_AB)
		toute_valeur_possible.push_back("AB");
	if(valeur & GROUPE_B)
		toute_valeur_possible.push_back("B");
	if(valeur & GROUPE_O)
		toute_valeur_possible.push_back("O");
	return toute_valeur_possible;
	
}

vector<string> ParentUnknown(const string & parent, const string & enfant, bool & positive, bool & negative) {

	char autre_parent;
	string autre_parentABO = Separation(parent, autre_parent);
	
	char enfantRh;
	string enfantABO = Separation(enfant, enfantRh);
	
	positive = true;
	negative = NegativeParent(autre_parent, enfantRg);
	
	return generationTypePossible(getUnknownParent(autre_parentABO, enfantABO));

}

vector<string>ChildUnknown(const string & parent_one, const string & parent_two, bool & positive, bool & negative) {
	char parent_oneRh;
	string parent_oneABO = Separation(parent_one, parent_oneRh);
	
	char parent_twoRh;
	string parent_twoABO = Separation(parent_two, parent_twoRh);
	
	positive = PositiveChild(parent_oneRh, parent_twoRh);
	negative = true;
	
	return generationTypePossible(findChildUnknown(parent_oneABO, parent_twoABO))
	
}

void Affichage(const vector<string> & valeur_possible, const bool & positive, const bool & negative) {
	if (valeur_possible.size() == 0) {
		cout << "IMPOSSIBLE" << endl;
	}
	else if (valeur_possible.size() == 1 && (positive ^ negative)) {
		cout << valeur_possible[0] << (positive ? '+' : '-');	
	}
	else {
		cout << '{';
		bool premier = true;
		
		for (int i = 0; i < valeur_possible.size(); i++) {
			if (positive) {
				if (!first) {
					cout << ", ";
				}
				first = false;
				cout << valeur_possible[i] << '+';
			}
			if (negative) {
				if (!first) {
					cout << ", ";
				}
				first = false;
				cout << valeur_possible[i] << '-';
			}
			
		}
		coout << "}";
	}
}

int main() {
	string	parent_one, parent_two, enfant;
	
	int Type = 1;
	
	while (cin >> parent_one >> parent_two >> enfant, parent_one != "E") {
	
		bool positive = false, negative = false;
		
		cout << "Case " << type++ << ": ";
		
		if (parent_one == "?") {
			vector<string> valeur_possible = ParentUnknown(parent_two, positive, negative);
			Affichage(valeur_possible, positive, negative);
		}
		else {
			cout << parent_one;	
		}
		cout << ' ';
		if (parent_two == "?") {
			vector<string> valeur_possible = ParentUnknown(parent_one, positive, negative);
			Affichage(valeur_possible, positive, negative);
		}
		else {
			cout << parent_two;	
		}
		cout << ' ';
		
		if(enfant == "?") {
			vector<string> valeur_possible = ChildUnknown(parent_one,parent_two, positive, negative);
			Affichage(valeur_possible, positive, negative);	
		}
		else {
			cout << enfant;	
		}
		cout << '\n';
	}
	
	return 0;
}

