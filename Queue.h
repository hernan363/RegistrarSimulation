#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;
template <typename E>
class Queue{
public:
	Queue();
	// Queue(int maxSize);
	~Queue();

	void insert(E data); // enqueue
	E remove(); // dequeue
	E peek();

	int getSize();
	int isEmpty();

	int numElements;
	int mSize;

	DoublyLinkedList<E> D;


};
//.cpp

//generic queue
template<typename E>
Queue<E>::Queue():D(){
}

template<typename E>
Queue<E>::~Queue(){}

//inserts into the queue
template<typename E>
void Queue<E>::insert(E data){
	D.insertBack(data);
}

//removes from the front
template <typename E>
E Queue<E>::remove(){
	E temp;
 	temp = D.removeFront();
 	return temp;
}

//returns the next node in line
template<typename E>
E Queue<E>::peek(){
	return D.front->data;
}

//gets the size of the queue
template<typename E>
int Queue<E>::getSize(){
	return D.size;
}

//returns if the queue is empty
template<typename E>
int Queue<E>::isEmpty(){
	return (D.size == 0);
}
#endif
