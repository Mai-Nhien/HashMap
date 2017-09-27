#include "hashMap.h"
#include <iostream>

using namespace std;

int main(){
	HashMap<int> h(4993892634952068460);
	if(h.set("a",1)){
		cout << "hi" << endl;
		//cout << h.get("test");
	}
}