#pragma once
#include "../Headers/Node.h"
#include<vector>
/*
This is a program that implements the queue abstract data type using a linked list.
The queue is implemented as a chain of linked nodes that has two pointers,
a frontPtr pointer for the front of the queue and a backPtr pointer for the back of the queue.
*/

/*

				The Node: item of type T and a "next" pointer
					-------------
					| item| next | --->
					-------------
General Queue case:

				 frontPtr																backPtr
					\											   						/
					 \											  					   /
					------------- 	  ------------- 	  ------------- 	  -------------
					| item| next |--->| item| next |--->  | item| next |--->  | item| next |---> NULL
					------------- 	  ------------- 	  ------------- 	  -------------

Empty Case:

				 frontptr	 backptr
						\	 /
						 \	/
					---- NULL ------


Single Node Case:
				 frontPtr	 backPtr
					\		/
					 \	   /
					-----------
					|item| next| -->NULL
					-----------

*/
//
//#ifndef Queue
//#define Queue



template <class T>
class Queue 
{
private:
	Node<T>* backPtr;
	Node<T>* frontPtr;
public:
	Queue();
	bool isEmpty() const;
	bool enqueue(const T& newEntry);
	bool dequeue(T& frntEntry);
	bool peek(T& frntEntry)  const;
	~Queue();
};
/////////////////////////////////////////////////////////////////////////////////////////









template <typename T>
Queue<T>::Queue()
{
	backPtr = nullptr;
	frontPtr = nullptr;

}
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: isEmpty
Sees whether this queue is empty.

Input: None.
Output: True if the queue is empty; otherwise false.
*/
template <typename T>
bool Queue<T>::isEmpty() const
{
	return (frontPtr == nullptr);
}

/////////////////////////////////////////////////////////////////////////////////////////

/*Function:enqueue
Adds newEntry at the back of this queue.

Input: newEntry .
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool Queue<T>::enqueue(const T& newEntry)
{
	Node<T>* newNodePtr = new Node<T>(newEntry);
	// Insert the new node
	if (isEmpty())	//special case if this is the first node to insert
		frontPtr = newNodePtr; // The queue is empty
	else
		backPtr->setNext(newNodePtr); // The queue was not empty

	backPtr = newNodePtr; // New node is the last node now
	return true;
} // end enqueue


/////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Function: dequeue
Removes the front of this queue. That is, removes the item that was added
earliest.

Input: None.
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool Queue<T>::dequeue(T& frntEntry)
{
	if (isEmpty())
		return false;

	Node<T>* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();
	// Queue is not empty; remove front
	if (nodeToDeletePtr == backPtr)	 // Special case: last node in the queue
		backPtr = nullptr;

	// Free memory reserved for the dequeued node
	delete nodeToDeletePtr;

	return true;
}



/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: peek
copies the front of this queue to the passed param. The operation does not modify the queue.

Input: None.
Output: The front of the queue.
*/

template <typename T>
bool Queue<T>::peek(T& frntEntry) const
{
	if (isEmpty())
		return false;

	frntEntry = frontPtr->getItem();
	return true;

}
///////////////////////////////////////////////////////////////////////////////////

template <typename T>
Queue<T>::~Queue()
{
	

	//Free all nodes in the queue
	T temp;
	while (dequeue(temp));

	cout << "\n Is LinkedQueue Empty now?? ==> " << boolalpha << isEmpty();
	cout << "\nEnding LinkedQueue destructor..." << endl;
}











template<>
class Queue<Process*>
{

protected:

	Node<Process*>* backPtr;
	Node<Process*>* frontPtr;
public:
	Queue() {




		backPtr = nullptr;
		frontPtr = nullptr;


	};
	bool isEmpty() const {



		return (frontPtr == nullptr);



	};



	virtual bool enqueue(Process* newEntry) {





		Node<Process*>* newNodePtr = new Node<Process*>(newEntry);
		// Insert the new node
		if (isEmpty())	//special case if this is the first node to insert
			frontPtr = newNodePtr; // The queue is empty
		else
			backPtr->setNext(newNodePtr); // The queue was not empty

		backPtr = newNodePtr; // New node is the last node now
		return true;
	};
	bool dequeue(Process*& frntEntry) {

		if (isEmpty())
			return false;

		Node<Process*>* nodeToDeletePtr = frontPtr;
		frntEntry = frontPtr->getItem();
		frontPtr = frontPtr->getNext();
		// Queue is not empty; remove front
		if (nodeToDeletePtr == backPtr)	 // Special case: last node in the queue
			backPtr = nullptr;

		// Free memory reserved for the dequeued node
		delete nodeToDeletePtr;

		return true;


	};
	bool peek(Process* frntEntry)  const {

		if (isEmpty())
			return false;

		frntEntry = frontPtr->getItem();
		return true;





	};




	int count() {    //count elements within thr Queue

		Node<Process*>* Tfrnt1 = frontPtr;
		int counter = 0;
		while (Tfrnt1) {
			Tfrnt1 = Tfrnt1->getNext();
			counter++;

		}
		return counter;


	}

	void Printlistid() {
		Node<Process*>* Tfrnt1 = frontPtr;
		Node<Process*>* Tfrnt2 = frontPtr;
		Node<Process*>* Tbck = backPtr;
		if (frontPtr == nullptr) {

			cout << 0 << "  RDY:" << endl;
			return;
		}

		int counter = 0;
		while (Tfrnt1) {
			Tfrnt1 = Tfrnt1->getNext();
			counter++;

		}
		cout << counter << " RDY";
		while (Tfrnt2) {

			cout << "  " << Tfrnt2->getItem()->getId() << "  ";

			Tfrnt2 = Tfrnt2->getNext();


		}
		cout << "*\n";


	}




	~Queue() {



	//	//Note that the cout statements here is just for learning purpose
	////They should be normally removed from the destructor
	//	cout << "\nStarting LinkedQueue destructor...";
	//	cout << "\nFreeing all nodes in the queue...";

		//Free all nodes in the queue
		Process* temp = nullptr;;
		while (dequeue(temp));

		cout << "\n Is LinkedQueue Empty now?? ==> " << boolalpha << isEmpty();
		cout << "\nEnding LinkedQueue destructor..." << endl;


	};
};




class PriorityQueue:public Queue<Process*>
{

public:
	bool enqueueS(Process* newEntry) {




		Node<Process*>* newNodePtr = new Node<Process*>(newEntry);
		// Insert the new node
		if (isEmpty()) //special case if this is the first node to insert
			frontPtr = newNodePtr; // The queue is empty
		
		
		else
			backPtr->setNext(newNodePtr); // The queue was not empty

		backPtr = newNodePtr; // New node is the last node now
	

		//sort everytime enqueue is called
		 int x = this->count();
		 if (x < 2) { return true; }
		 Process* temp = nullptr;
		 vector<Process*> myV;
		Process** AUXARR=new Process* [x];
		for (int i = 0; i < x; i++) {
			this->dequeue(temp);
			myV.push_back(temp);
			/*AUXARR[i+1] = temp;*/

		}
		//buuble sort the array
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < x-i-1; j++)
			{

				if (myV[j + 1]->getremainingtime() < myV[j]->getremainingtime())
				{
					Process* temp = myV[j+1];

					myV[j+1] = myV[j ];
					myV[j ] = temp;

				}
			}

		}
		//now we have a sorted array
		//enqueue ut back to the original Queue
		for (int i = 0; i < x; i++) {
			
			this->enqueue(myV[i]);
		}

		
		delete[] AUXARR;
		return true;

	};

};

