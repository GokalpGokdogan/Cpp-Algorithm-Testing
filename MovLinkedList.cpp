#include "MovLinkedList.h"
#include "MovNode.h"
#include "Movie.h"
#include<iostream>
using namespace std;





 
MovLinkedList::MovLinkedList() {
	head = nullptr;
}

MovLinkedList::~MovLinkedList()
{
	delete head;
	head = nullptr;
}

 
void MovLinkedList::add(Movie item) {
	if (head == nullptr)
	{
		MovNode* temp = new MovNode();
		temp->data = item;
		head = temp;
	}
	else
	{
		MovNode* curr = head;
		while(curr->next != NULL)
		{

			/*if ((curr)->next->data.id == item.id) {
				return;
			}*/
			if ((curr)->next->data.id > item.id) {
				break;
			}
			curr = curr->next;
		
		}
		
		MovNode* temp = new MovNode();
		temp->data = item;
		//head = temp;


		//MovNode temp;////should implement this using stacks?
		//temp->data = item;

		if (curr == head) {
			if ((curr)->data.id > item.id) {
				head = temp;
				temp->next = curr;
				return;
			}
		}
		
		if (curr->next != nullptr) {
			temp->next = curr->next;
		}
		curr->next = temp;

	}
}

 
int MovLinkedList::size() {

	if (head == nullptr)
	{
		return 0;
	}
	else
	{
		int size = 1;
		MovNode* curr = head;
		while (curr->next != nullptr) {
			size++;
			curr = curr->next;
		}
		return size;
	}

}

 
void MovLinkedList::remove(Movie item)
{
	//int check = 0;
	if (head == nullptr)
	{
		return;
	}
	else
	{
		MovNode* curr = head;
		MovNode* prev = head;
		while (curr->next != NULL)
		{
			if (curr->data.id == item.id) {
				break;
			}
			prev = curr;
			curr = curr->next;

		}
		if (curr == head) {
			if ((curr)->data.id == item.id) {
				head = curr->next;
				curr->next = nullptr;
				
			}
		}
		if (curr->next != nullptr) {
			prev->next = curr->next;
			curr->next = nullptr;
			delete curr;
			//curr->next = nullptr;
//			cout << "Movie " << item.id << " has been removed\n";
		}
		else if(curr->data.id == item.id)
		{
			prev->next = curr->next;
			curr->next = nullptr;
			delete curr;
			//cout << "Movie " << item.id << " has been removed\n";
		}
		else
		{
//			cout << "Movie " << item.id << " does not exist\n";
		}
		
			
			
		
	}
}

 
void MovLinkedList::display() const
{
	if (head == nullptr)
	{
		return;
	}
	else
	{

		MovNode* curr = head;
		while (curr->next != nullptr) {
			cout << /*"id: " <<*/ curr->data.id << " " << curr->data.constCopies << endl;
			curr = curr->next;
		}
		cout <<  curr->data.id << " " << curr->data.constCopies << endl;
		
	}
}

bool MovLinkedList::isAvailable(Movie m)
{
	if (head == nullptr)
	{
		return 0;
	}
	else
	{
		MovNode* curr = head;
		while (curr->next != NULL)
		{

			if ((curr)->data.id == m.id) {
				if ((curr)->data.copies > 0) {
					return true;
				}
				return false;
			}
			else if ((curr)->next->data.id > m.id) {
				break;
			}
			curr = curr->next;

		}
		///change
		if (curr->next == NULL) {
			if ((curr)->data.id == m.id) {
				if ((curr)->data.copies > 0) {
					return true;
				}
				return false;
			}
		}
		///
		if (curr == head) {
			/*if ((curr)->data.id == m.id) {
				return true;

			}*/
			if ((curr)->data.copies > 0) {
				return true;
			}
		}
		return false;
	}
}

void MovLinkedList::updateCop(Movie m, int no)
{
	if (isAvailable(m)) {
		if (head == NULL) {
			return;
		}
		MovNode* curr = head;
		while (curr->next != NULL)
		{

			if ((curr)->data.id == m.id) {
				if (no > 0) {
					(curr)->data.copies++;
				}
				else
				{
					(curr)->data.copies--;
				}

				break;
			}
			
			if ((curr)->data.id == m.id) {
				if (no > 0) {
					(curr)->data.copies++;
				}
				else
				{
					(curr)->data.copies--;
				}

			}
			
			curr = curr->next;

		}
		///change
		if (curr->next == NULL)
		{
			if ((curr)->data.id == m.id) {
				if (no > 0) {
					(curr)->data.copies++;
				}
				else
				{
					(curr)->data.copies--;
				}

				
			}

			
		}
		///
	}
	else
	{
		MovNode* curr = head;
		while (curr->next != NULL)
		{

			if ((curr)->data.id == m.id) {
				if ((curr)->data.copies == 0) {
					if (no > 0) {
						(curr)->data.copies++;
					}
					else 
					{
						cout << "Movie " << m.id << " has no available copy for renting\n";
					}
				}
				

				break;
			}

			curr = curr->next;

		}

	}
}

bool MovLinkedList::doesExist(Movie m) const
{
	if (head == nullptr)
	{
		return 0;
	}
	else
	{
		MovNode* curr = head;
		while (curr->next != NULL)
		{

			if ((curr)->data.id == m.id) {

				return true;
			}
			else if ((curr)->next->data.id > m.id) {
				break;
			}
			curr = curr->next;

		}
		if ((curr)->data.id == m.id) {
			return true;

		}
		return false;
	}
}


Movie* MovLinkedList::giveMov(Movie s) const
{
	if (head == nullptr)
	{
		return nullptr;
	}
	else
	{
		MovNode* curr = head;
		while (curr->next != NULL)
		{

			if ((curr)->data.id == s.id) {
				if ((curr)->data.copies == 0) {
					curr = curr->next;
					continue;
				}
				return &curr->data;
			}
			else if ((curr)->data.id > s.id) {
				break;
			}
			curr = curr->next;

		}
		if ((curr)->data.id == s.id) {
			return &curr->data;
		}
		
		return nullptr;
	}
}