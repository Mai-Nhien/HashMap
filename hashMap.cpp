#include "hashMap.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	HashMap<int> h(997);
	vector<string> keys {"AA", "BB", "C", "ae", "h", "8", "4"};
	vector<int> values {1, 2, 3, 4, 5, 6, 7};
	cout << keys.size() << endl;
	for(unsigned int i = 0; i < keys.size(); i++){
		if(h.set(keys[i],values[i])){
			cout << *(h.get(keys[i])) << endl;
		}
		else{
			cout << "false" <<endl;
		}
	}
	cout << *(h.delete_("8")) << " should be 6" << endl;
	if(!h.get("8")){
		cout << "good delete" << endl;
	}
	cout << *(h.delete_("BB")) << " should be 2" << endl;
	if(!h.get("BB")){
		cout << "good delete" << endl;
	}
	cout << *(h.get("4")) << " should be 7" << endl;
	cout << h.load() << endl;

	// if(h.set("Aa",1)){
		
	// 	cout << h.get("Aa") << endl;
	// }
	// if(h.set("BB",2)){
		
	// 	cout << h.get("BB") << endl;
	// }
	// if(h.set("C",3)){
		
	// 	cout << h.get("C") << endl;
	// }
	// if(h.set("ae",4)){
		
	// 	cout << h.get("ae") << endl;
	// }
	// if(h.set("h",5)){
		
	// 	cout << h.get("h") << endl;
	// }
	// if(h.set("8",6)){
		
	// 	cout << h.get("8") << endl;
	// }
	// if(h.set("4",7)){
		
	// 	cout << h.get("4") << endl;
	// }
	// // if(h.set("3",8)){
		
	// // 	cout << h.get("3") << endl;
	// // }
	// cout << h.delete_("ae") << " should be 4" << endl;
	// if(!h.get("ae")){
	// 	cout << "good delete" << endl;
	// }
	// cout << h.delete_("BB") << " should be 2" << endl;
	// //cout << h.get("3") << " should be 8" << endl;
	// cout << h.load() << endl;
}