#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H


#include "ListNode.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

template <typename E>
//.h
class DoublyLinkedList{
public:
	int size;
	ListNode<E>* front;
	ListNode<E>* back;

	DoublyLinkedList();
	~DoublyLinkedList();

	void insertFront(E data);
	void insertBack(E data);

	E removeFront();
	E deletePos(E key);
};

//.cpp
template <typename E>
DoublyLinkedList<E>::DoublyLinkedList(){
	front = new ListNode<E>();
	back = new ListNode<E>();
	front ->next = back;
	back->prev = front;
	size = 0;
}

template <typename E>
DoublyLinkedList<E>::~DoublyLinkedList(){}


//inserts from the front
template <typename E>
void DoublyLinkedList<E>::insertFront(E data){

	ListNode<E> *node = new ListNode<E>(data);
	if(size==0){
		back = node;
	} else {
		node->next = front;
		front->prev = node;
	}
	front = node;
	++size;
}


//inserts from the back
template <typename E>
void DoublyLinkedList<E>::insertBack(E data){
	ListNode<E> *node = new ListNode<E>(data);

	if(size == 0){
		front = node;
	} else {
		back->next = node;
		node->prev = back;
	}
	back = node;
	size ++;
}


//removes the first node
template <typename E>
E DoublyLinkedList<E>::removeFront(){
	//nmake neccessary checks

	ListNode<E> *temp = front;

	if(front->next == NULL){
		back = NULL;
	} else {
		front->next->prev = NULL;
	}

	front = front ->next;
	E val = temp -> data;
	temp->next = NULL;

	delete temp;

	--size;
	return val;
}

//deletes from any position
template <typename E>
E DoublyLinkedList<E>::deletePos(E key){
	E temp;
	ListNode<E> *current = front;
	//search
	while(!(current->data == key)){
		current = current->next;
		if(current == NULL){
			return -1;
		}
	}
	//ok we found it lets check our conditions
	temp = current->data;

	if(current == front){
		front = current -> next;
	} else if (current == back){
		back = current->prev;
		back->next = NULL;
	} else {
		current->prev->next = current -> next;
		current->next->prev = current -> prev;
	}
	current->next = NULL;
	current->prev = NULL;
	--size;

	//create temp to hold value
	delete current;
	return temp;
}
#endif
