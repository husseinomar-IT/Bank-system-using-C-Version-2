#pragma once
#include<iostream>
#include"clsDblLinkList.h"
template<class T>
 class clsMyQueue
{

protected:

	clsDblLinkList<T> _MyLinkList;

public:


	void push(T Item)
	{
		_MyLinkList.InsertAtEnd(Item);
	}



	void pop()
	{
		_MyLinkList.DeleteFirstNode();
	}



	void print()
	{
		_MyLinkList.PrintList();
	}



	int size()
	{
	   return 	_MyLinkList.Size();
	}



	T front()
	{
		return _MyLinkList.GetItem(0);
	}


	T back()
	{
		return _MyLinkList.GetItem(size() - 1);
	}

	bool IsEmpty()
	{
		return _MyLinkList.IsEmpty();
	}


	T GetItem(int Index)
	{
		return _MyLinkList.GetItem(Index);
	}



	void Reverse()
	{
		_MyLinkList.Reverce();
	}


	void UpdateItem(int Index,T Item)
	{
		 _MyLinkList.UpdateItem(Index, Item);
	}



	void InsertAfter(int Index, T Item)
	{
		 _MyLinkList.InsertAfter(Index, Item);
	}


	void InsertAtFront(T Item)
	{
		_MyLinkList.InsertAtBeginning(Item);
	}

	void InsertAtBack(int Item)
	{
		_MyLinkList.InsertAtEnd(Item);
	}




	void Clear()
	{
		_MyLinkList.Clear();
	}


};

