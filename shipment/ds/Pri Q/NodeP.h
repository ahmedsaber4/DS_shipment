#pragma once
#include <iostream>
using namespace std;
template <typename T>
class NodeP {

private:
	T item;			// data
	NodeP<T>* next; // Pointer to next node
	double priority;
public:
	NodeP();
	NodeP(const T& r_Item , double pri);
	NodeP(const T& r_Item ,  double pri , NodeP<T>* nextNodePtr);
	void setItem(const T& r_Item);
	void setNext(NodeP<T>* nextNodePtr);
	void setpriority(double);
	double getpriority();
	T getItem() const;
	NodeP<T>* getNext() const;
};



template < typename T>
NodeP<T>::NodeP()
{
	next = nullptr;
}

template < typename T>
NodeP<T>::NodeP(const T& r_Item , double pri)
{
	item = r_Item;
	next = nullptr;
	priority = pri;
}

template < typename T>
NodeP<T>::NodeP(const T& r_Item  , double pri , NodeP<T>* nextNodePtr)
{
	item = r_Item;
	priority = pri;
	next = nextNodePtr;
}
template < typename T>
void NodeP<T>::setItem(const T& r_Item)
{
	item = r_Item;
}

template < typename T>
void NodeP<T>::setNext(NodeP<T>* nextNodePtr)
{
	next = nextNodePtr;
}

template < typename T>
T NodeP<T>::getItem() const
{
	return item;
}

template < typename T>
NodeP<T>* NodeP<T>::getNext() const
{
	return next;
}


template < typename T>
double NodeP<T>::getpriority()
{
	return priority;
}

template < typename T>
void NodeP<T>::setpriority(double pri)
{
	priority = pri;
}