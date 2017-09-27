#ifndef HASHMAP_H
#define HASHMAP_H


#include <iostream>
#include <string>
#include <functional>
#include <unordered_map>


template <typename Value>
class Node {
public:
	Node(const std::string key, const Value& val);
	virtual ~Node();
	const std::string getKey() const;
	const Value& getValue() const;
	std::string getKey();
	Value& getValue();
	Node* getNext() const;
	void setNext(Node* next);
	void setKey(const std::string key);
	void setValue(const Value &val);

private:
	std::string key;
	Value val;
	Node* next;
};

//Implentations for Node class
template <typename Value> 
Node<Value>::Node(const std::string k, const Value& v) {
	key = k;
	val = v;
	next = NULL;
}

template <typename Value>
Node<Value>::~Node() {

}

template <typename Value>
const std::string Node<Value>::getKey() const {
	return key;
}

template<typename Value>
const Value& Node<Value>::getValue() const {
	return val;
}

template <typename Value>
std::string Node<Value>::getKey() {
	return key;
}

template<typename Value>
Value& Node<Value>::getValue() {
	return val;
}

template <typename Value>
Node<Value>* Node<Value>::getNext() const {
	return next;
}

template <typename Value>
void Node<Value>::setNext(Node<Value>* n) {
	next = n;
}

template <typename Value>
void Node<Value>::setKey(const std::string k) {
	key = k;
}


template <typename Value>
void Node<Value>::setValue(const Value& v) {
	val = v; 
}

template <typename Value>
class HashMap {
public:
	HashMap(int size);
	~HashMap();
	bool set(std::string k, Value v);
	Value get(std::string k);
	//delete is a keyword in C++, needed to add underscore in the function name
	Value delete_(std::string k);
	float load();

private:
	Node<Value> **table;
	int tableSize;
	int numItems;
	std::hash<std::string> hashFn;
};

template<typename Value>
HashMap<Value>::HashMap(int size) {
	tableSize = size;
	numItems = 0;
	table = new Node<Value>*[tableSize];
	for (int i = 0; i < tableSize; i++) {
		table[i] = NULL;
	}
}

template<typename Value>
HashMap<Value>::~HashMap(){

}

template<typename Value>
bool HashMap<Value>::set(std::string k, Value v) {
	unsigned long hashVal= hashFn(k);
	std::cout << hashVal <<std::endl;
	Node<Value> *start = table[hashVal];
	if (start == NULL) {
		//First entry in table chain
		Node<Value> *entry = new Node<Value>(k, v);
		table[hashVal] = entry;
		numItems++;
		return true;
	}
	else {
		while (start->getNext() != NULL && start->getKey() != k) {
			start = start->getNext();
		}
		if (start->getNext() == NULL) {
			Node<Value> *entry = new Node<Value>(k, v);
			start->setNext(entry);
			numItems++;
			return true;
		}
		else {
			//The key already exists in the table
			return false;
		}
	}
}

template<typename Value>
Value HashMap<Value>::get(std::string k) {
	unsigned long hashVal = hashFn(k);
	Node<Value> *start = table[hashVal];
	if (start == NULL) {
		return NULL;
	}
	else {
		while (start != NULL) {
			if (start->getKey() == k) {
				return start->getValue();
			}
			start = start->getNext();
		}
		return NULL;
	}
}

template<typename Value>
Value HashMap<Value>::delete_(std::string k) {
	unsigned long hashVal = hashFn(k);
	Node<Value> *start = table[hashVal];
	if (start == NULL) {
		return NULL;
	}
	else {
		while (start != NULL) {
			if (start->getNext()->getKey() == k) {
				Node<Value> *deleteNode = start->getNext();
				Value returnValue = deleteNode->getValue();
				start->setNext(deleteNode->getNext());
				numItems--;
				delete deleteNode;
				return returnValue;
			}
			start = start->getNext();
		}
		if (start == NULL) {
			return NULL;
		}
	}
}

template<typename Value>
float HashMap<Value>::load() {
	float loadingFactor = (float)numItems / tableSize;
	return loadingFactor;
}

#endif