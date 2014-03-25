#ifndef BOUNDARY_H
#define BOUNDARY_H

#include "library.h"

class Boundary{
public:
	void init();
	std::vector<Vector2D> intersection(std::vector<Vector2D> v); 
};
#endif