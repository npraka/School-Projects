#pragma once
#ifndef LIST342_H
#define LIST342_H


#include <string>
#include <iostream>
#include <fstream>
using namespace std;


template<class ItemType>
class List342
{
	friend ostream& operator<<(ostream &out, const List342<ItemType> &print)
	{
		
			Node *trace;
			trace= print.head;
		
			while (trace != NULL)
			{
			out << trace->data;
				trace = trace->next;
			}
		
			return out;
	}

public:

	List342();
	~List342();

	bool BuildList(string FileName);
	bool Insert(ItemType *obj);
	bool Remove(ItemType target, ItemType &result);
	bool Peek(ItemType target, ItemType &result);
	bool isEmpty();
	void DeleteList();
	bool Merge(List342 &list1);
	List342& operator+=(const List342 &second) 
	{
		Node *copy = second.head;
		while (copy != NULL)
		{
			Insert(copy->data);
			copy = copy->next;
		}
		return *this;
	}
	List342 operator+(const List342 &second) const;
	List342 operator=(const List342 &second) const;
	bool operator==(const List342 &second) const;
	bool operator!=(const List342 &second) const;





private:
	
	struct Node {
		ItemType *data;
		Node *next;
	};
	Node *head;
};
#endif



template<class ItemType>
List342<ItemType>::List342()
{
}
template<class ItemType>
List342<ItemType> ::~List342()
{
}

template<class ItemType>
bool List342<ItemType> ::BuildList(string FileName)
{
	if (FileName.empty())
	{	return false;	
	}
	ifstream i(FileName);
	if (!i)
	{
		return false;
	}
	ItemType *trace = new ItemType;

	while (!i.eof())
	{	i >> trace;
		Insert(trace);
		
	}
	i.close();
	return true;

}

template < class ItemType> 
bool List342<ItemType> ::Insert(ItemType *obj)
{
	Node *insNode = new Node;
	insNode->data = obj;
	if (head == NULL)
	{
		head = insNode;
		return true;
	}
	if (obj < head->data)
	{
		insNode->next = head;
		head = insNode;
		return true;
	}

	Node *pNode = head;
	while ((pNode->next != NULL) && (pNode->next->data < obj))
	{
		pNode = pNode->next;
	}
	if (obj == head->data)
	{
		return false;
	}
	insNode->next = pNode->next;
	pNode->next = insNode;
	
	return true;

	
}

template <class ItemType>
bool List342<ItemType>:: Remove(ItemType target, ItemType &result)
{
	Node *temp;
	if (head = NULL)
	{
		return false;
	}
	if (*head->data == target)
	{
		temp = head;
		
		head = head->next;
		delete temp;
		temp = NULL;
		return true;
	}
	Node *pNode = head;
	while ((pNode->next != NULL) && (*pNode->next->data != target))
	{
		pNode = pNode->next;
	}
	if (pNode->next == NULL)
	{
		return false;
	}
	else
	{
		
		temp = pNode->next;
		pNode->next = pNode->next->next;
		delete temp;
		temp = NULL;
		return true;
	}
}

template <class ItemType>
bool List342<ItemType>::Peek(ItemType target, ItemType &result)
{
	
	if (head = NULL)
	{
		return false;
	}
	if (*head->data == target)
	{
		
	
		return true;
	}
	Node *pNode = head;
	while ((pNode->next != NULL) && (*pNode->next->data != target))
	{
		pNode = pNode->next;
	}
	if (pNode->next == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

template <class ItemType>
bool List342<ItemType>::isEmpty()
{
	return (head == NULL);
}

template <class ItemType>
void List342<ItemType>::DeleteList()
{
	Node *cur = head;
	Node *temp = NULL;
	while (cur!= NULL)
	{
		temp = cur;
		cur->data = NULL;
		cur = cur->next;
		delete temp;
		temp = NULL;
	}
	
}

template <class ItemType>
bool List342<ItemType>::Merge(List342 &second)
{
	Node *trace = second.head;

	while (trace != NULL)
	{
		Insert(trace->data);
	}
	second.DeleteList();
	return true;
}



template <class ItemType>
List342<ItemType> List342<ItemType>:: operator+(const List342 &second) const
{
	return *this + second;
}

template < class ItemType>
List342<ItemType> List342<ItemType>:: operator=(const List342 &second) const
{
	if (this == &second)
	{	return *this;
	
	}
	

	if (second.head == NULL) 
		return *this;
	
	Node *sNode, *dNode, *insNode;
	dNode = new Node;
	dNode->data = (second.head)->data;
	dNode->next = NULL;
	this->head = dNode;
	sNode = (second.head)->next;
	while (sNode != NULL)
	{
		insNode = new Node;
		insNode->data = sNode->data;
		insNode->next = NULL;
		dNode->next = insNode;
		dNode = dNode->next;
		sNode = sNode->next;
	}
	return *this;

}
template < class ItemType>
bool List342<ItemType>::operator==(const List342 &list1) const
{
	Node *first = head;
	Node *second = list1.head;

	if (first != NULL || &second != NULL)
	{
		return false;
	}

	while (first != NULL&&second != NULL)
	{
		if (head->data != second->data)
		{
			return false;
		}
		first = first->next;
		second = second->next;

	}
	return true;
}

template < class ItemType>
bool List342<ItemType>::operator!=(const List342 &second) const
{
	if (*this == second)
	{
		return false;
	}
	return true;
}

