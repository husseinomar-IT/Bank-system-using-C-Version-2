#pragma once
#include<iostream>
template<class T>
class clsDynamicArray
{
protected:
	int _size=0;
	T* _TempArray;
public:
	T * OriginalArray;
	clsDynamicArray(int Size=0)
	{
		if (Size < 0)
			Size = 0;

		_size = Size;
		
		OriginalArray = new T[_size];
	}


	int Size()
	{
		return _size;
	}



	bool SetItem(int Index, T Item)
	{
		if (Index >= _size || Index < 0)
		{
			return false;
		}
			
		else
		{
			OriginalArray[Index] = Item;
			return true;
		}
		
	}


	void Print()
	{
		for (int i = 0; i < _size; i++)
		{
			cout << OriginalArray[i] << " ";
		}
		cout << "\n";
	}
	bool IsEmpty()
	{
		return(_size == 0 ? true : false);
	}


	void Resize(int Newsize)
	{
		if ( Newsize< 0)
			Newsize = 0;


		_TempArray = new T[Newsize];

		if (Newsize<_size)
			_size = Newsize;

		for (int i = 0; i<_size; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		_size = Newsize;
		delete[]OriginalArray;
		OriginalArray = _TempArray;


	}

	T GetItem(int Index)
	{
		return OriginalArray[Index];
	}


	void Reverce()
	{
		_TempArray = new T[_size];
		int Counter = 0;
		for (int i = _size-1; i>=0; i--)
		{
			_TempArray[Counter] = OriginalArray[i];
			Counter++;
		}

		delete[]OriginalArray;
		OriginalArray = _TempArray;
	}


	void Clear()
	{
		_size = 0;
		_TempArray = new T[_size];
		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}

	bool DeleteItemAt(int Index)
	{
		if (Index >= _size || Index < 0)
			return false;


		_size--;

		_TempArray = new T[_size];
		for (int i = 0; i<Index; i++)
		{
			
			_TempArray[i] = OriginalArray[i];
		}


		for (int i = Index + 1; i < _size + 1; i++)
		{
			_TempArray[i-1] = OriginalArray[i];
		}


		delete[] OriginalArray;
		OriginalArray = _TempArray;
		return true;

	}


	bool InsertAt(int Index, T Value)
	{
		if (Index > _size || Index < 0)
			return false;



		_size++;
		_TempArray = new T[_size];

		for (int i = 0; i<Index; i++)
		{

			_TempArray[i] = OriginalArray[i];
		}

		_TempArray[Index] = Value;

		/*for (int i = Index; i < Index + 1; i++)
		{
			_TempArray[i] = Value;
		}*/

		for (int i = Index; i < _size - 1; i++)
		{
			_TempArray[i+1] = OriginalArray[i];
		}

		delete[] OriginalArray;
		OriginalArray = _TempArray;
		return true;

	}



	void InsertAtBeginning(T Value)
	{
		InsertAt(0, Value);
	}



	bool InsertBefore(int Index, T Value)
	{
		if (Index<1)
			return InsertAt(0, Value);
		else

	     return	InsertAt(Index-1, Value);
	}


	bool InsertAfter(int Index, T Value)
	{
		if (Index>=_size)
			return InsertAt(_size - 1, Value);
		else

		 return InsertAt(Index + 1, Value);
	}



	bool InsertAtEnd(T Value)
	{
		 return InsertAt(_size, Value);
	}

	void DeleteItem(T Value)
	{
		int Index = Find(Value);
		DeleteItemAt(Index);
	}




	void DeleteFirstItem()
	{
		 DeleteItemAt(0);
	}


	void DeleteLastItem()
	{
		 DeleteItemAt(_size-1);
	}



	int Find(T Value)
	{
		for (int i = 0; i < _size; i++)
		{
			if (OriginalArray[i] == Value)
				return i;

		}
		return -1;
	}

	~clsDynamicArray()
	{
		delete[] OriginalArray;
	}
	
};

