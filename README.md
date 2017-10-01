## HashMap

###Instructions
Since <unordered_map> has to be included in order to use the hash function, compile with -std=c++11. I've included hashMap.cpp, which is the testing file. 
+ To compile: g++ -g -Wall hashMap.cpp -o hashMap -std=c++11
+ To run: ./

###Notes
+ The instructions specified that the hash map should store data object references instead of copying the object. In c++, this has to be done using pointers, so I implemented the hash map to store the value as a pointer data member of a node in the hash map. This is why in my test cases, the values have to be assigned to some address or variable, and de-referenced when the "get" and "delete" functions are called. There are two set functions, one that accepts a reference and one that accepts a pointer. 
+ For the "set" function, I return false if the key is already in the hash map.
+ For the "get" function, I also return null if the key doesn't exist in the hash map.

