#pragma once
#include<iostream>
#include"clsDblLinkList.h"
template<class T>
class clsMyStack:public clsMyQueue<T>
{


	
public:



	void push(T Item)
	{
		
		clsMyQueue<T>::
		_MyLinkList.InsertAtBeginning(Item);
	
	}
	



	


	



	T Top()
	{

		return clsMyQueue<T>::front();
	}


	T Bottom()
	{
		return clsMyQueue<T>::back();
	}

	
};

