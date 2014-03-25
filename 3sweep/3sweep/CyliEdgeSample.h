// 圆柱形目标采样

#ifndef CYLIEDGESAMPLE_H
#define CYLIEDGESAMPLE_H

#include "EdgeSample.h"
#include "library.h"

class CyliEdgeSample: public EdgeSample{
public:
	CyliEdgeSample(){}
	void init(std::vector<Vector3D> v);
	CyliEdgeSample clone();
	void sample();
	std::vector<Vector3D> get3DSample();

	Vector2D getCenter() { return center; }
	Vector2D getNormal() { return normal; }
	double getA() { return a; }
	double getB() { return b; }
	Vector2D* getEndpoint() { return endpoint; }

	void setCenter(Vector2D v) { center = v; }
	void setNormal(Vector2D v) { normal = v; }
	void setA(double A) { a = A; }
	void setB(double B) { b = B; }
	void setEndpoint(Vector2D* v) { endpoint[0] = v[0]; endpoint[1] = v[1]; }

	void clear(){ samples.clear(); }

	std::vector<Vector2D> samples;  
private:
	Vector2D center;    
	Vector2D normal;   
	Vector2D[2] endpoint;

	double a;  // two arguments for a ellipse 
	double b;

	Vector2D getEllipsePoint(int i);
};

int CyliEdgeSample::sampleNum;

#endif