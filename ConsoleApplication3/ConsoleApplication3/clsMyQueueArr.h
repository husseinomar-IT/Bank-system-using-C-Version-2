#pragma once
#include<iostream>
#include"clsDynamicArray.h"
template<class T>
class clsMyQueueArr
{

protected:

	clsDynamicArray<T> MyArray;

public:


	void push(T Item)
	{
		MyArray.InsertAtEnd(Item);
	}



	void pop()
	{
		MyArray.DeleteFirstItem();
	}



	void print()
	{
		MyArray.Print();
	}



	int size()
	{
		return 	MyArray.Size();
	}



	T front()
	{
		return MyArray.GetItem(0);
	}


	T back()
	{
		return MyArray.GetItem(size() - 1);
	}

	bool IsEmpty()
	{
		return MyArray.IsEmpty();
	}


	T GetItem(int Index)
	{
		return MyArray.GetItem(Index);
	}



	void Reverse()
	{
		MyArray.Reverce();
	}


	void UpdateItem(int Index, T Item)
	{
		MyArray.SetItem(Index, Item);
	}



	void InsertAfter(int Index, T Item)
	{
		MyArray.InsertAfter(Index, Item);
	}


	void InsertAtFront(T Item)
	{
		MyArray.InsertAtBeginning(Item);
	}

	void InsertAtBack(int Item)
	{
		MyArray.InsertAtEnd(Item);
	}




	void Clear()
	{
		MyArray.Clear();
	}


};

