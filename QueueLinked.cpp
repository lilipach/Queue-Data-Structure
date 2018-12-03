//----------------------------------------------------------------
//
//	Laboratory  7       QueueLinked.cpp	
// Author: Liliana Pacheco
// Purpose: to create a linked queue and implement queue methods
//
//----------------------------------------------------------------

#include <iostream>
#include "QueueLinked.h"

using namespace std;
 
//Name: QueueNode
//Purpose: This is the QueueNode constructor it creates a new Queue Node with the Datatype information that is passed to
//Input: DataType nodeData and QueueNode pointer are the inputs of this functiion
template <class DataType>
QueueLinked<DataType>::QueueNode::QueueNode(const DataType& nodeData, QueueNode* nextPtr)
{
	dataItem = nodeData;
	next = nextPtr;
}

//Name: QueueLinked(int maxNumber)
//Purpose: This is one of the QueueLinked constructosrs, it is the default constructor
//Input: This takes in an int variable that gets ignored
template <class DataType>
QueueLinked<DataType>::QueueLinked(int maxNumber)
{
	front = NULL;
	back = NULL;
}

//Name: QueueLinked(const QueueLinked& other)
//Purpose: This is the copy constructor of QueuLinked
//Input: This takes in a constant QueueLinked list
template <class DataType>
QueueLinked<DataType>::QueueLinked(const QueueLinked& other)
{
	QueueNode *cursor = other.front;
	
	front = NULL;
	back = NULL;	

	while(cursor != NULL)
	{
		enqueue(cursor->dataItem);
		cursor = cursor -> next;
	}
}

//Name: operator=
//Purpose: This function overides the equal operator so that the equal sign can be used with the QueueLinked template
//Input: This takes in a constant QueueLinked item
template <class DataType>
QueueLinked<DataType>& QueueLinked<DataType>::operator=(const QueueLinked& other)
{
	if(this == &other) //make sure that the calling object and other object are not the same item
		return this;			
	
	clear(); //delete alll existing data 
	
	QueueNode *cursor = other.front;

	while(cursor != NULL)
	{
		enqueue(cursor->dataItem);
		cursor = cursor -> next;
	}

return this;

}

//Name: ~QueueLinked(
//Purpose: This is the QueueLinked destructor takes care of deleting all the allocated data from a QueueLinked item
//Input: None
template <class DataType>
QueueLinked<DataType>::~QueueLinked()
{
	clear();
}

//Name: enqueue
//Purpose: This function adds a new DataItem to the back of the queue
//Input: This takes in a constant DataType that is used to create the new Queue data item
template <class DataType>
void QueueLinked<DataType>::enqueue(const DataType& newDataItem) throw (logic_error)
{
	QueueNode *temp_node_ptr = new QueueNode(newDataItem, 0);	

	if(isEmpty()) //if queue is empty then the newly created node is the front and back of the list
	{
		front = temp_node_ptr;
		back = temp_node_ptr;
	}
	else
	{
		back -> next = temp_node_ptr;
		back = temp_node_ptr;
	}

}

//Name: dequeue
//Purpose: This functino removes the first data item of the Queue list
//Input: None
template <class DataType>
DataType QueueLinked<DataType>::dequeue() throw (logic_error)
{

	if(isEmpty())
	{
		throw logic_error("dequeue() queue empty");
	}
	
	DataType temp = front -> dataItem;
	if(front == back)
	{
		delete front;
		front = NULL;
		back = NULL;
	}
	else if (!isFull())
	{
		QueueNode *temp_ptr = front;
		front = front -> next;
		delete temp_ptr;
	}

return temp;
}

//Name: clear
//Purpose: This function deletes all the existing QueueNodes of the QueueLinked list by deallocating the data of the nodes
//Input: None
template <class DataType>
void QueueLinked<DataType>::clear()
{
	QueueNode * temp_ptr;
	
	while(!isEmpty())
	{
		temp_ptr = front;
		front = front -> next;
		delete temp_ptr;
	}
	back = NULL;
}

//Name: isEmpty
//Purpose: This function checks if there is any node items in the queue if there is the function returns false other wise true 
//Input: None
template <class DataType>
bool QueueLinked<DataType>::isEmpty() const
{
	if (front == NULL)
		return true;
	else 
		return false;
}

//Name: isFull
//Purpose: This function is supposed to check if the queue is full but for our purposes the list will never be full thus this functio will always return false 
//Input: None
template <class DataType>
bool QueueLinked<DataType>::isFull() const
{
	return false;
}

//Name: putFront
//Purpose: This function adds a New node to the front of the queue list mad from the past in DataType
//Input: A constant DataType reference
template <class DataType>
void QueueLinked<DataType>::putFront(const DataType& newDataItem) throw (logic_error)
{
	if(isEmpty())
	{
		enqueue(newDataItem);	
	}
	else
	{
		QueueNode *temp_node = new QueueNode(newDataItem,0);
		temp_node -> next = front;
		front = temp_node;
	}	
}

//Name: getRear
//Purpose: This function removes the last node on the list
//Input: None
template <class DataType>
DataType QueueLinked<DataType>::getRear() throw (logic_error)
{

	if (isEmpty())
	{	
		throw logic_error("getRear() queue empty");
	}
	
	DataType temp = back -> dataItem;

	if(back == front)
	{
		return dequeue();	
	}
	else if (!isFull())
	{	
		QueueNode * temp_node = back;

		back = front;

		while(back -> next != temp_node)
		{
			back = back -> next;
		}
		back -> next = NULL;
		
		delete temp_node;
	}
return temp;		
}

//Name: getLength
//Purpose: The purpose of this function is to count the number of nodes in the list and return the value aka the length of the list
//Input: None
template <class DataType>
int QueueLinked<DataType>::getLength() const
{
	int length;
	QueueNode *cursor = front;
		
	
	for(length = 0; cursor != NULL; length++)
	{
		cursor = cursor -> next;	
	}

return length;
}

//--------------------------------------------------------------------
// show7.cpp: includes implementation of showStructure
//--------------------------------------------------------------------

//--------------------------------------------------------------------

template <typename DataType>
void QueueLinked<DataType>:: showStructure () const

// Linked list implementation. Outputs the elements in a queue. If
// the queue is empty, outputs "Empty queue". This operation is
// intended for testing and debugging purposes only.

{
    // Iterates through the queue
	QueueNode* p;

    if ( isEmpty() )
	cout << "Empty queue" << endl;
    else
    {
	cout << "Front\t";
	for ( p = front ; p != NULL ; p = p->next )
	{
	    if( p == front )
	    {
		cout << '[' << p->dataItem << "] ";
	    }
	    else
	    {
		cout << p->dataItem << " ";
	    }
	}
	cout << "\trear" << endl;
    }
}







