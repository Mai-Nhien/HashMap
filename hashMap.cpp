#include "hashMap.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	HashMap<int> h(10); //Would usually use a bigger size that is a prime number, but I kept it simple for testing purposes.
	cout << "TEST SET 1" << endl;
	vector<string> keys {"AA", "BB", "C", "ae", "h", "8", "4"};
	vector<int> values {1, 2, 3, 4, 5, 6, 7};
	for(unsigned int i = 0; i < keys.size(); i++){
		if(h.set(keys[i],values[i])){
			cout << "KEY: " << keys[i] << " VALUE: " << *(h.get(keys[i])) << endl;
		}
		else{
			cout << "false" <<endl;
		}
	}
	cout << *(h.delete_("8")) << " should be 6" << endl;
	if(!h.get("8")){
		cout << "Delete successful" << endl;
	}
	cout << *(h.delete_("BB")) << " should be 2" << endl;
	if(!h.get("BB")){
		cout << "Delete successful" << endl;
	}
	cout << *(h.get("4")) << " should be 7" << endl;
	cout << "Loading factor: " << h.load() << endl;

	h.clear();

	//Delete the only item in map
	cout << endl;
	cout << "TEST SET 2" << endl;	
	int x = 1;
	if(h.set("First", x)){
		cout << *(h.get("First")) << endl;
	}
	cout << "Deleting: " << *(h.delete_("First")) << endl;
	if(!h.get("First")){
		cout << "Delete successful" << endl;
	}

	//Try using values of type string
	cout << endl;
	cout << "TEST SET 3" << endl;
	HashMap<string> h2 (10);
	vector<string> keys2 {"AA", "BB", "C", "ae", "h", "8", "4"};
	vector<string> values2 {"AA", "BB", "C", "ae", "h", "8", "4"};
	for(unsigned int i = 0; i < keys2.size(); i++){
		if(h2.set(keys2[i],values2[i])){
			cout << "KEY: " << keys2[i] << " VALUE: " << *(h2.get(keys2[i])) << endl;
		}
		else{
			cout << "false" <<endl;
		}
	}

	//Use the set function that takes in a pointer
	cout << endl;
	cout << "TEST SET 4" << endl;
	int z = 10;
	int* y = &z;
	HashMap<int> h3(10);
	if(h3.set("hi",y)){
		cout << "KEY: " << "hi" << " VALUE: " << *(h3.get("hi")) << endl;
	}
	else{
		cout << "false" <<endl;
	}
}