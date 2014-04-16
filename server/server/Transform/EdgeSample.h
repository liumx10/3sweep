//根据现有的边缘，进行采样，转化为3D坐标后传给OBJ 

#ifndef EDGESAMPLE_H
#define EDGESAMPLE_H

#include "Boundary.h"

class EdgeSample{
public:
	EdgeSample(){

	}
	void init(std::vector<Vector2D>);   // initlize by user's input. only the first will use this function
	void sample();  // calculate the sample points' coordinates after adjusting normal and endpoint
	
	std::vector<Vector2D> getSamples();  // return the sample points' coordinates in 2D
	Vector2D getNormal() {  return normal; }
	std::vector<Vector2D> getEndpoint() { return endpoint; }
	Vector2D getCenter() { return center; }

	void setCenter(Vector2D v) { center = v; }
	void setNormal(Vector2D v) { normal = v; }
	void setEndpoint(std::vector<Vector2D> v) { endpoint[0] = v[0]; endpoint[1] = v[1]; }
	void setBoundary(Boundary* b) { boundary = b; }

	
	static void setSampleNum(int i) { sampleNum = i; }
	static int getSampleNum() { return sampleNum; }

protected:
	Boundary *boundary;
	static int sampleNum;

	Vector2D center;    
	Vector2D normal;   
	std::vector<Vector2D> endpoint;
	std::vector<Vector2D> samples;  
};

int EdgeSample::sampleNum = 24;
#endif