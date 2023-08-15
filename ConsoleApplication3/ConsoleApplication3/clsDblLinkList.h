#pragma once
#include<iostream>
template<class T>
class clsDblLinkList
{

protected:
	int _Size = 0;
	
	
	
public:



	clsDblLinkList()
	{

	}

	class Node
	{
	public:
		T value;
		Node * next;
		Node * Prev;
	
	};


	Node * head = NULL;

	void InsertAtBeginning( T Value)
	{
		
		Node *new_node =  new Node ();
		new_node->value = Value;
		new_node->next = head;
		new_node->Prev = NULL;
		if (head != NULL)
		{
			head->Prev = new_node;
		}
		head = new_node;
		_Size++;
	}


	void PrintList()
	{
		Node* Current = head;

		while (Current != NULL)
		{
			cout << Current->value << " ";
			Current = Current->next;
		}
		cout << "\n";
	}





	Node * Find(T Value)
	{
		Node *Current = head;

		while (Current != NULL)
		{

			if (Current->value == Value)

				return Current;


			Current = Current->next;
		}
		return NULL;


	}


	void InsertAfter(Node *Current, T Value)
	{
		if (Current == NULL)
		{
			cout << "\nThe Given Prives Node can not be Null \n\n";
			return;
		}
		Node* new_Node = new Node();
		new_Node->value = Value;
		new_Node->next = Current->next;
		new_Node->Prev = Current;
		if (Current->next != NULL)
		{
			Current->next->Prev = new_Node;
		}
		Current->next = new_Node;
		_Size++;
	}




	bool InsertAfter(int Index, T Value)
	{
		Node* Current = GetNode(Index);
		if (Current != NULL)
		{
			InsertAfter(Current, Value);
			return true;
		}
		else
			return false;
		
	}




	void InsertAtEnd(T Value)
	{

		Node* new_Node = new Node();
		new_Node->value = Value;
		new_Node->next = NULL;
		if (head == NULL)
		{
			new_Node->Prev = NULL;
			head = new_Node;
			_Size++;
			return;
		}

		else
		{
			Node* Current = head;
			while (Current->next != NULL)
			{
				Current = Current->next;
			}
			Current->next = new_Node;
			new_Node->Prev = Current;
			_Size++;
			return;
		}

	}



	void DeleteNode(Node * NodeToDeleted)
	{
		if (head == NULL || NodeToDeleted == NULL)
		{
			return;
		}



		if (head == NodeToDeleted)
		{
			head = NodeToDeleted->next;
		}

		if (NodeToDeleted->next != NULL)
		{
			NodeToDeleted->next->Prev = NodeToDeleted->Prev;
		}

		if (NodeToDeleted->Prev != NULL)
		{
			NodeToDeleted->Prev->next = NodeToDeleted->next;
		}

		delete NodeToDeleted;
		_Size--;
	}

	
	


	void DeleteFirstNode()
	{
		if (head == NULL)
		{
			return;
		}


		Node *Current = head;
		head = head->next;
		if (head != NULL)
		{
			head->Prev = NULL;
		}
		delete Current;
		_Size--;

	}






	void DeleteLastNode()
	{
		if (head == NULL)
		{
			return;
		}



		if (head->next == NULL)
		{
			delete head;
			head = NULL;
			_Size--;
			return;
		}
		Node *Current = head;
		while (Current->next->next != NULL)
		{
			Current = Current->next;
		}
		Node *LastNode = Current->next;
		Current->next = NULL;
		delete LastNode;
		_Size--;
	}


	int Size()
	{
		return _Size;

	}
	bool IsEmpty()
	{
		return(_Size == 0 ? true : false);
	}

	void Clear()
	{

		while (_Size > 0)
		{
			DeleteFirstNode();
		}
	}




	void Reverce()
	{
		Node* Current = head;
		Node* Temp = NULL;
		while (Current != NULL)
		{
			Temp = Current->Prev;
			Current->Prev = Current->next;
			Current->next = Temp;
			Current = Current->Prev;
		}
		if (Temp != NULL)
		{
			head = Temp->Prev;
		}
	}



	Node *GetNode(int Index)
	{

		int Counter = 0;

		if (Index > _Size - 1 || Index < 0)
		{
			return NULL;
		}

			
		Node* Current = head;
		
		while (Current != NULL && (Current->next!=NULL))
		{
			

			if (Counter == Index)
				break;
		
			Current = Current->next;
			Counter++;
		}
		return Current;

	}

	T GetItem(int Index)
	{
		Node *N = GetNode(Index);
		if (N == NULL)
			return NULL;
		else
		return N->value;
	}


	bool UpdateItem(int Index, T newValue)
	{
		Node *N = GetNode(Index);
		if (N!= NULL)
		{
			N->value = newValue;
			return true;
		}
		return false;
		
	}



};

