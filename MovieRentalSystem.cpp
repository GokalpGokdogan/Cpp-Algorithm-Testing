#include "MovieRentalSystem.h"
#include "MovLinkedList.h"
#include "SubLinkedList.h"
#include "Movie.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

MovieRentalSystem::MovieRentalSystem(const string movieInfoFileName, const string subscriberInfoFileName)
{
	ifstream movFile, subFile;
	int size = 0;
	int in1, in0;
	int check = 0;
	movFile.open(movieInfoFileName.c_str(), ios::in);
	if (movFile) 
	{
		while (movFile.eof() == false) {
			if (size == 0) {
				movFile >> size;
			}
			else
			{
				
				for (int i = 0; i < size; i++) {
					movFile >> in0 /*>> non*/ >> in1;
					Movie m(in0, in1);
					movieList.add(m);
				}
				break;

			}
		}
	}
	else
	{
		check++;
		cout << "Input file " << movieInfoFileName << " does not exist\n";
	}


	//cout << "MovFile Success!!	List Size: "<< movieList.size() << "\n";

	size = 0;
	subFile.open(subscriberInfoFileName.c_str(), ios::in);
	if (subFile)
	{
		while (subFile.eof() == false) {
			if (size == 0) {
				subFile >> size;
			}
			else
			{
				for (int i = 0; i < size; i++) {
					subFile >> in0;
					Subscriber s(in0);
					subList.add(s);
				}
				
				break;

			}
		}
	}
	else
	{
		check++;
		cout << "Input file " << subscriberInfoFileName << " does not exist\n";
	}
	
	if (check == 0) {
		cout << subList.size() << " subscribers and " << movieList.size() << " movies have been loaded\n";
	}
	//cout << "SubFile Success!!	List Size: " << subList.size() << "\n";

}
MovieRentalSystem::~MovieRentalSystem(){
	
}
void MovieRentalSystem::removeMovie(const int movieId){
	int size0 = movieList.size();
	Movie m(movieId);
	

	bool movCheck = movieList.doesExist(m);
	int rentNum = 0;
	if (movCheck) {
		SubNode* subPoint = subList.head;
		

		if (subPoint == NULL) {
			return;
		}
		SubNode* curr = subPoint;
		while (curr->next != NULL)
		{
			MovNode* iter = curr->data.rentedMovies.head;
			if (curr->data.rentedMovies.doesExist(m)) {

				while (iter->next != NULL) {
					if (iter->data.id == movieId) {
						rentNum++;
					}
					iter = iter->next;
				}
				if (iter->data.id == movieId) {
					rentNum++;
				}

			}

			curr = curr->next;

		}
		///Change
		if (curr->next == NULL) {
			MovNode* iter = curr->data.rentedMovies.head; ///pastMovies->rentedMovies
			if (curr->data.rentedMovies.doesExist(m)) {

				while (iter->next != NULL) {
					if (iter->data.id == movieId) {
						rentNum++;
					}
					iter = iter->next;
				}
				if (iter->data.id == movieId) {
					rentNum++;
				}

			}
		}
		///
	}

	if (rentNum != 0)
	{
		cout << "Movie " << movieId << " cannot be removed -- at least one copy has not been returned\n";
		return;
	}
	movieList.remove(m);
	int size1 = movieList.size();
	if (size0 == size1) {
		cout << "Movie " << movieId << " does not exist\n";
	}
	else
	{
		cout << "Movie " << movieId << " has been removed\n";
	}
}
void MovieRentalSystem::addMovie(const int movieId, const int numCopies){
	Movie m(movieId, numCopies);
	//int size0 = movieList.size();
	
	//int size1 = movieList.size();
	if (movieList.doesExist(m)){//(size0 == size1) {
		cout << "Movie " << movieId << " already exists\n";
	}
	else
	{
		movieList.add(m);
		cout << "Movie " << movieId << " has been added\n";
	}
}
void MovieRentalSystem::removeSubscriber(const int subscriberId){

	Subscriber s(subscriberId);
	bool subCheck = subList.doesExist(s);
	if (subCheck)
	{
		 if (subList.giveSub(s)->rentedMovies.size() != 0) {
			 cout << "Subscriber " << subscriberId << " cannot be removed -- at least one movie has not been returned\n";
		 }
		 else
		 {
			 subList.remove(s);
			 if (!subList.doesExist(s))
			 {
				 cout << "Subscriber " << subscriberId << " has been removed\n";
			 }
		 }
	}
	else {
		cout << "Subscriber " << subscriberId << " does not exist\n";////Change

	}
	
}
void MovieRentalSystem::rentMovie(const int subscriberId, const int movieId){
	Subscriber s(subscriberId);
	bool subCheck = subList.doesExist(s);
	Movie m(movieId);
	bool movCheck = movieList.doesExist(m);
	///TEST
	//if(subscriberId==10000){
	//	int xxx = 0;
	//}


	///end
	if (movCheck && subCheck) {
		if (movieList.isAvailable(m)) {
			/*///TEST
			if (s.id == 10000) {
				int xxx = 0;
			}


			///end*/
			(subList.giveSub(s))->rent(m);
			movieList.updateCop(m, -1);
			cout << "Movie " << m.id << " has been rented by subscriber " << subscriberId << "\n";
		}
		else {
			cout << "Movie " << m.id << " has no available copy for renting\n";
		}
	}
	else if (!movCheck && !subCheck)
	{
		cout << "Subscriber " << subscriberId << " and movie " << movieId << " do not exist\n";
	}
	else if (!movCheck)
	{
		cout << "Movie " << movieId << " does not exist\n";
	}
	
	else
	{
		cout << "Subscriber " << subscriberId << " does not exist\n";
	}

}
void MovieRentalSystem::returnMovie(const int subscriberId, const int movieId){
	Subscriber s(subscriberId);
	bool subCheck = subList.doesExist(s);
	Movie m(movieId);
	bool movCheck = movieList.doesExist(m);
	bool subMovCheck = (subList.giveSub(s))->rentedMovies.doesExist(m);
	if (movCheck && subCheck && subMovCheck) {
		if (movieList.doesExist(m)) {
			(subList.giveSub(s))->returnMov(m);
			movieList.updateCop(m, 1);
			cout << "Movie " << m.id << " has been returned by subscriber " << subscriberId << "\n";
		}
		else {
			cout << "No rental transaction for subscriber " << subscriberId << " and movie " << movieId << "\n";
		}
	}
	else if (!movCheck && !subCheck)
	{
		cout << "No rental transaction for subscriber " << subscriberId << " and movie " << movieId << "\n";
	}
	else if (!movCheck)
	{
		cout << "No rental transaction for subscriber " << subscriberId << " and movie " << movieId << "\n";
	}

	else
	{
		cout << "No rental transaction for subscriber " << subscriberId << " and movie " << movieId << "\n";
	}

}
void MovieRentalSystem::showMoviesRentedBy(const int subscriberId) const{
	Subscriber s(subscriberId);
	bool subCheck = subList.doesExist(s);
	///TEST
	/*if(subscriberId==10000){
		int xxx = 0;
	}*/


	///end
	if (subCheck) {
		MovNode* iterator_past = subList.giveSub(s)->pastMovies.head;
		if (iterator_past==NULL)
		{
			cout << "Subscriber " << subscriberId << " has not rented any movies\n";
			return;
		}
		cout << "Subscriber " << subscriberId <<" has rented the following movies:\n";
		//subList.giveSub(s)->pastMovies.display();
		
		//MovNode* iterator_now = subList.giveSub(s)->rentedMovies.head;
		//int size = subList.giveSub(s)->rentedMovies.size();



		//for (int i = 0; i < size; i++)
			//{
			//int returned = 0, notReturned = 0;
			/*if (iterator_now->data.id == iterator_past->data.id) {
				while (iterator_now->data.id == iterator_past->data.id)
				{
					notreturned++;
					if (iterator_now->data.id == iterator_now->next->data.id) {
						iterator_now = iterator_now->next;
						iterator_past = iterator_past->next;
					}
					else{
						break;
					}
					
					
				}
				while (iterator_past->data.id == iterator_past->next->data.id && iterator_past->next != null) {
					returned++;
					iterator_past = iterator_past->next;
					
				}
				for (int i = 0; i < notreturned; i++)
				{
					cout << iterator_past->data.id << " not returned\n";
				}
				for (int i = 0; i < returned; i++)
				{
					cout << iterator_past->data.id << " returned\n";
				}

				iterator_now = iterator_now->next;
				iterator_past = iterator_past->next;
			}
*/

		
			//if (iterator_now->data.id == iterator_past->data.id) {
			//	while (iterator_now->data.id == iterator_past->data.id)
			//	{
			//		//cout << iterator_past->data.id << " not returned\n";
			//		notReturned++;
			//		iterator_now = iterator_now->next;
			//	}
			//	
			//}
			//else
			//{
			//	returned++;
			//	//cout << iterator_past->data.id << " returned\n";

			//}
			//for (int i = 0; i < returned; i++)
			//{
			//	cout << iterator_past->data.id << " returned\n";
			//}
			//for (int i = 0; i < notReturned; i++)
			//{
			//	cout << iterator_past->data.id << " not returned\n";
			//}
			//i += notReturned - 1;
			//returned = 0;
			//notReturned = 0;
			//iterator_past = iterator_past->next;

			if (iterator_past == NULL) {
				return;
			}
			MovNode* curr = iterator_past;
			while (curr->next != NULL)
			{
				if (curr->data.copies == 0) {
					cout << curr->data.id << " returned\n";
				}
				else
				{
					cout << curr->data.id << " not returned\n";
				}
				

				curr = curr->next;

			}
			if (curr->data.copies == 0) {
				cout << curr->data.id << " returned\n";
			}
			else
			{
				cout << curr->data.id << " not returned\n";
			}

		//}


	}
	else
	{
		cout << "Subscriber " << subscriberId << " does not exist\n";
	}
}
void MovieRentalSystem::showSubscribersWhoRentedMovie(const int movieId) const{
	Movie m(movieId);
	bool movCheck = movieList.doesExist(m);
	int rentNum = 0;
	if (movCheck) {
		SubNode* subPoint = subList.head;
		if (subPoint == NULL)
		{
			return;
		}

		if (subPoint == NULL) {
			return;
		}
		SubNode* curr = subPoint;
		while (curr->next != NULL)
		{
			MovNode* iter = curr->data.pastMovies.head;
			if (curr->data.pastMovies.doesExist(m)) {

				while (iter->next != NULL) {
					if (iter->data.id == movieId) {
						rentNum++;
					}
					iter = iter->next;
				}
				if (iter->data.id == movieId) {
					rentNum++;
				}

			}

			curr = curr->next;

		}
		if (rentNum != 0)
		{
			cout << "Movie " << movieId << " has been rented by the following subscribers:\n";
			if (subPoint == NULL) {
				return;
			}
			SubNode* curr = subPoint;
			while (curr->next != NULL)
			{
				MovNode* iter = curr->data.pastMovies.head;
				if (curr->data.pastMovies.doesExist(m)) {



					while (iter->next != NULL) {
						if (iter->data.id == movieId) {
							if (iter->data.copies == -1)
							{
								cout << curr->data.id << " not returned\n";
							}
							else
							{
								cout << curr->data.id << " returned\n";
							}
						}
						iter = iter->next;
					}
					if (iter->data.id == movieId) {
						if (iter->data.copies == -1)
						{
							cout << curr->data.id << " not returned\n";
						}
						else
						{
							cout << curr->data.id << " returned\n";
						}
					}


					//cout << curr->data.id << " returned\n";
				}

				//MovNode* iter = curr->data.pastMovies.head;
				/*if (iter->data.id == movieId) {
					if (iter->data.copies == -1)
					{
						cout << curr->data.id << " not returned\n";
					}
					else
					{
						cout << curr->data.id << " returned\n";
					}
				}*/



				curr = curr->next;

			}

			///change
			if (curr->next == NULL)
			{
				MovNode* iter = curr->data.pastMovies.head;
				if (curr->data.pastMovies.doesExist(m)) {



					while (iter->next != NULL) {
						if (iter->data.id == movieId) {
							if (iter->data.copies == -1)
							{
								cout << curr->data.id << " not returned\n";
							}
							else
							{
								cout << curr->data.id << " returned\n";
							}
						}
						iter = iter->next;
					}
					if (iter->data.id == movieId) {
						if (iter->data.copies == -1)
						{
							cout << curr->data.id << " not returned\n";
						}
						else
						{
							cout << curr->data.id << " returned\n";
						}
					}



				}
			}
			///
		}
		else
		{
			cout << "Movie " << movieId << " has not been rented by any subscriber\n";
		}
		
		
	}
	else
	{
		cout << "Movie " << movieId << " does not exist\n";
	}

}
void MovieRentalSystem::showAllMovies() const{
	cout << "Movies in the movie rental system:\n";
	movieList.display();
}
void MovieRentalSystem::showAllSubscribers() const{
	cout << "Subscribers in the movie rental system:\n";
	subList.display();
}