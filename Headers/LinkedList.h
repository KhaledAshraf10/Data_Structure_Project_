#ifndef _LINKEDLIST
#define _LINKEDLIST

#include "Node.h"
#include <iostream>

using namespace std;


template <typename T>
class LinkedList
{
private:
	Node<T> *Head;	//Pointer to the head of the list
	//You can add tail pointer too (depending on your problem)
public:


	LinkedList()
	{
		Head = nullptr;
	}

	//List is being desturcted ==> delete all items in the list
	~LinkedList()
	{
		DeleteAll();
	}
	
	/*
	* Function: PrintList.
	* prints the values of all nodes in a linked list.
	*/
	void PrintList()	const
	{
		cout<<"\nprinting list contents:\n\n";
		Node<T> *p = Head;

		while(p)
		{
			cout << "[ " << p->getItem() << " ]";
			cout << "--->";
			p = p->getNext();
		}
		cout << "*\n";
	}
	
	/*
	* Function: InsertBeg.
	* Creates a new node and adds it to the beginning of a linked list.
	* 
	* Parameters:
	*	- data : The value to be stored in the new node.
	*/
	void InsertBeg(const T &data)
	{
		Node<T> *R = new Node<T>(data);
		R->setNext(Head);
		Head = R;
	}
	
	/*
	* Function: DeleteAll.
	* Deletes all nodes of the list.
	*/
	void DeleteAll()
	{
		Node<T> *P = Head;
		while (Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
	}

	////////////////     Requirements   ///////////////////
	//
	// Implement the following member functions


	//[1]InsertEnd 
	//inserts a new node at end if the list
	void InsertEnd(const T& data)
	{
		Node<T>* R = new Node<T>(data);
		Node<T>* P = Head;
		if (!Head)
		{
			Head = R;
			return; // de bet5rog mn void 
		}
		while (P->getNext())
		{
			P = P->getNext();
		}
		P->setNext(R);
	}

	void getbeg( T& data) {

		data = Head->getItem();

		DeleteNode(data);








	}
	
	//[2]Find 
	//searches for a given value in the list, returns true if found; false otherwise.
	bool Find(const T &data)
	{
		Node<T>* P = Head;
		int counter = 0;
		while (P)
		{
			if (P->getItem() == data)
			{
				counter++;
			}
			P = P->getNext();
		}
		if (counter) return true;
		else return false;
	}


	//[3]CountOccurance
	//returns how many times a certain value appeared in the list

	//[4] DeleteFirst
	//Deletes the first node in the list

	//[5] DeleteLast
	//Deletes the last node in the list

	//[6] DeleteNode
	//deletes the first node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted
	void DeleteNode(const T &data)
	{
		Node<T>*  prevptr = Head;
		int counter = 0;
		while (prevptr->getNext())
		{
			if ((prevptr->getNext())->getItem() == data) //  = curptr
			{
				Node<T>* curptr = prevptr->getNext();
				prevptr->setNext(curptr->getNext());
				delete curptr;
				return;
			}
			else
			{
				prevptr = prevptr->getNext();
			}
			
		}


	}

	//[7] DeleteNodes
	//deletes ALL node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted

	//[8]Merge
	//Merges the current list to another list L by making the last Node in the current list 
	//point to the first Node in list L

	//[9] Reverse
	//Reverses the linked list (without allocating any new Nodes)
};

#endif	
