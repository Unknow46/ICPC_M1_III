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
