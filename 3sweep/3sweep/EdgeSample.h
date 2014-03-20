#ifndef EDGESAMPLE_H
#define EDGESAMPLE_H

class EdgeSample{
public:
	virtual void init(std::vector<Vector3D>);   // initlize by user's input. only the first will use this function
	virtual EdgeSample* getNextEdge();   // get next EdgeSample 
	virtual void sample();  // calculate the sample points' coordinates
	virtual std::vector<Vector3D> getSample();  // return the sample points' coordinates

private:
	std::vector<Vector3D> samples;
};
#endif