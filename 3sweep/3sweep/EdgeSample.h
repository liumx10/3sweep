#ifndef EDGESAMPLE_H
#define EDGESAMPLE_H

#include "2DBoundary.h"

class EdgeSample{
public:
	virtual void init(std::vector<Vector3D>);   // initlize by user's input. only the first will use this function
	virtual EdgeSample* getNextEdge();   // get next EdgeSample 
	virtual void sample();  // calculate the sample points' coordinates
	virtual std::vector<Vector3D> getSample();  // return the sample points' coordinates

private:
	2DBoundary boundary;
};
#endif