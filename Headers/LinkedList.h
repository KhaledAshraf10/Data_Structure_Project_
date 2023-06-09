#ifndef _LINKEDLIST
#define _LINKEDLIST

#include "Node.h"
#include <iostream>
#include"../Headers/process.h"

using namespace std;


template <class T>
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

	void getbeg(T& data) {


		data = Head->getItem();

		DeleteNode(data);

	}



	//[2]Find 
	//searches for a given value in the list, returns true if found; false otherwise.
	bool Find(const T& data)
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
	void DeleteNode(const T& data)
	{
		Node<T>* prevptr = Head;
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


//class Linkedlistpp :public LinkedList<Process*> {
//
//
//
//
//};





	








template<>
class LinkedList<Process*> 
{

private:
	Node<Process*>* Head;	//Pointer to the head of the list
	
public:


	LinkedList()
	{
		Head = nullptr;
	}

		~LinkedList()

	{
		DeleteAll();
		cout << "LINKEDLIST DESTRUCTOR !!";
	}

	/*
	* Function: PrintList.
	* prints the values of all nodes in a linked list.
	*/
	void PrintList()	const
	{
		cout << "\nprinting list contents:\n\n";
		Node<Process*>* p = Head;

		while (p)
		{
			cout << "[ " << p->getItem() << " ]";
			cout << "--->";
			p = p->getNext();
		}
		cout << "*\n";
	}
	void PrintListid()	const
	{
	
		Node<Process*>* p = Head;
		Node<Process*>* Tp = Head;
		if (Head == nullptr) {


			cout << 0 << "  RDY:" << endl;

			return;

		}
		
		int counter = 0;
		while (Tp->getNext()) {
			Tp=Tp->getNext();
			counter+=2;
		}
		cout << counter << "  RDY:";
		 
		while (p)
		{

			cout << "  "<<p->getItem()->getId() << "  ";
		
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
	void InsertBeg( Process*& data)
	{
		Node<Process*>* R = new Node<Process*>(data);
		R->setNext(Head);
		Head = R;
	}

	/*
	* Function: DeleteAll.
	* Deletes all nodes of the list.
	*/
	void DeleteAll()
	{
		Node<Process*>* P = Head;
		while (Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
	}

	//////////////     Requirements   ///////////////////

	int size() const {
		int count = 0;
		Node<Process*>* curr = Head;
		while (curr != nullptr) {
			count++;
			curr = curr->getNext();
		}
		return count;
	}


	
	void InsertEnd( Process*& data)
	{
		Node<Process*>* R = new Node<Process*>(data);
		Node<Process*>* P = Head;
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

	void getbeg( Process*& data) 
	{
		data = Head->getItem();
		DeleteNode(data);
	}
	Process* getRdyProcessFL(int id)
	{
		Node<Process*>* curptr = Head;
		Process* result = nullptr;
		while (curptr)
		{
			if (curptr->getItem()->getId() == id)
			{
				result = curptr->getItem();
			}
			curptr = curptr->getNext();
		}
		return result;
	}

	
	bool Find(const Process*& data)
	{
		Node<Process*>* P = Head;
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
	bool Check(int data)
	{
		Node<Process*>* P = Head;
		int counter = 0;
		while (P)
		{
			if (P->getItem()->getId() == data)
			{
				counter++;
			}
			P = P->getNext();
		}
		if (counter) return true;
		else return false;
	}


	
	
	void DeleteNode( Process*& data)
	{
		Node<Process*>* prevptr = Head;
		int counter = 0;
		if (prevptr->getNext() == nullptr) {
			Head = nullptr;
		}

		while (prevptr->getNext())
		{
			if ((prevptr->getNext())->getItem() == data) //  = curptr
			{
				Node<Process*>* curptr = prevptr->getNext();
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


	int DeleteNodeR(int data)
	{
		Node<Process*>* prevptr = Head;
		if (!prevptr)
			return 0;
		
		if(Head->getItem()->getId()== data){
			int x = Head->getItem()->getremainingtime();

			Node<Process*>* curptr = Head->getNext();
			delete Head;
			Head = curptr;
			return x;
		
		}

		while (prevptr->getNext())
		{
			if ((prevptr->getNext())->getItem()->getId() == data) //  = curptr
			{
				int x = prevptr->getItem()->getremainingtime();
				Node<Process*>* curptr = prevptr->getNext();
				prevptr->setNext(curptr->getNext());

				delete curptr;
				return x;
			}
			else
			{
				prevptr = prevptr->getNext();
			}

		}


	}
	Node<Process*>* getHead() {
		return Head;
	}
	Process* getProcessByPosition(int position) const {
		if (position < 0 || position >= size()) {
			// Invalid position, return nullptr or throw an exception
			return nullptr;
		}

		Node<Process*>* currentNode = Head;
		int currentPosition = 0;

		while (currentNode && currentPosition != position) {
			currentNode = currentNode->getNext();
			currentPosition++;
		}

		if (currentNode) {
			return currentNode->getItem();
		}

		return nullptr;
	}


	
};






#endif













