#include "Movie.h"

Movie::Movie(int id, int copies)
{
	this->id = id;
	this->copies = copies;
	this->constCopies = copies;
}
