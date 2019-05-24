#include <iostream>
#include <stdlib.h>

using namespace std;

template <typename E>
class ListNode{
	public:
	E data;

	ListNode<E>* prev;
	ListNode<E>* next;

	ListNode();
	ListNode(E d);
	~ListNode();
};

//ListNode.cpp
template <typename E>
ListNode<E>::ListNode(){
	next = NULL;
	prev = NULL;
}

template <typename E>
ListNode<E>::ListNode(E d){
	data = d;
	next = NULL;
	prev = NULL;
}

template <typename E>
ListNode<E>::~ListNode(){
	if(next != NULL){
		delete next;
	}
	next = NULL;
	prev = NULL;
}
