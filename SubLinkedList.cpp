#include "SubLinkedList.h"
#include "SubNode.h"
#include "Subscriber.h"
#include<iostream>
using namespace std;






SubLinkedList::SubLinkedList() {
	head = nullptr;
}

SubLinkedList::~SubLinkedList()
{
	delete head;
	head = nullptr;
}


void SubLinkedList::add(Subscriber item) {
	if (head == nullptr)
	{
		SubNode* temp = new SubNode();
		temp->data = item;
		head = temp;
	}
	else
	{
		SubNode* curr = head;
		while (curr->next != NULL)
		{
			if ((curr)->next->data.id > item.id) {
				break;
			}
			curr = curr->next;

		}

		SubNode* temp = new SubNode();
		temp->data = item;



		if (curr->data.id == item.id) {///change
			return;
		}
		//if (curr->next == nullptr) {
			if (curr==head) {
				if ((curr)->data.id > item.id) {
					head = temp;
					temp->next = curr;
					return;
				}
			}
			
		//}

		
		


		////should implement this using stacks?
		
		if (curr->next != nullptr) {
			temp->next = curr->next;
		}
		/*if (head->data.id > item.id) {
			temp->next = curr->next;
			head = temp;
		}
		else
		{
			curr->next = temp;

		}*/
		curr->next = temp;


	}
}


int SubLinkedList::size() {

	if (head == nullptr)
	{
		return 0;
	}
	else
	{
		int size = 1;
		SubNode* curr = head;
		while (curr->next != nullptr) {
			size++;
			curr = curr->next;
		}
		return size;
	}

}


void SubLinkedList::remove(Subscriber item)
{
	if (head == nullptr)
	{
		return;
	}
	else
	{
		SubNode* curr = head;
		SubNode* prev = head;
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
		}

		curr->next = nullptr;
		delete curr;
	}
}


void SubLinkedList::display() const
{
	if (head == nullptr)
	{
		return;
	}
	else
	{

		SubNode* curr = head;
		while (curr->next != nullptr) {
			cout << /*"id: " <<*/ curr->data.id << endl;
			curr = curr->next;
		}
		cout << /*"id: " <<*/ curr->data.id << endl;
	}
}

bool SubLinkedList::doesExist(Subscriber s) const
{
	if (head == nullptr)
	{
		return 0;
	}
	else
	{
		SubNode* curr = head;
		while (curr->next != NULL)
		{

			if ((curr)->data.id == s.id) {
				
				return true;
			}
			else if ((curr)->data.id > s.id) {
				break;
			}
			curr = curr->next;

		}
		///change
		if (curr->next == NULL) {
			if ((curr)->data.id == s.id) {
				
				return true;
				
				
			}
		}
		///
		return false;
	}
}

Subscriber* SubLinkedList::giveSub(Subscriber s) const
{
	if (head == nullptr)
	{
		return nullptr;
	}
	else
	{
		SubNode* curr = head;
		while (curr->next != NULL)
		{

			if ((curr)->data.id == s.id) {

				return &curr->data;
			}
			else if ((curr)->data.id > s.id) {
				break;
			}
			curr = curr->next;

		}
		///change
		if (curr->next == NULL) {
			if ((curr)->data.id == s.id) {

				return &curr->data;


			}
		}
		///
		return nullptr;
	}
}



