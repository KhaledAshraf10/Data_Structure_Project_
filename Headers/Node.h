#pragma once
#ifndef _NODE
#define _NODE

//First let's declare a single node in the list

template<typename T>
//yarabbbb
class Node
{
private :
	T item;	// A data item (can be any complex sturcture)
	Node<T>* next;	// Pointer to next node
public :

	Node( ) //default constructor
	{
		next= nullptr;
	} 

	Node( T newItem) //non-default constructor
	{
		item = newItem;
		next= nullptr;

	}

	void setItem( T newItem)
	{
		item = newItem;
	} // end setItem

	void setNext(Node<T>* nextNodePtr)
	{
	next = nextNodePtr;
	} // end setNext

	T getItem() const
	{
		return item;
	} // end getItem

	Node<T>* getNext() const
	{
		return next;
	}
}; // end Node

#endif	
//template<>
////yarabbbb
//class Node<Process*>
//{
//private:
//	Process* item;	// A data item (can be any complex sturcture)
//	Node<Process*>* next;	// Pointer to next node
//public:
//
//	Node() //default constructor
//	{
//		next = nullptr;
//	}
//
//	Node(Process* newItem) //non-default constructor
//	{
//		item = newItem;
//		next = nullptr;
//
//	}
//
//	void setItem(Process* newItem)
//	{
//		item = newItem;
//	} // end setItem
//
//	void setNext(Node<Process*>* nextNodePtr)
//	{
//		next = nextNodePtr;
//	} // end setNext
//
//	Process* getItem() const
//	{
//		return item;
//	} // end getItem
//
//	Node<Process*>* getNext() const
//	{
//		return next;
//	}
//}; // end Node
//



