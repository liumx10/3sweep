// 圆柱形目标采样

#ifndef CYLIEDGESAMPLE_H
#define CYLIEDGESAMPLE_H

#include "EdgeSample.h"

class CyliEdgeSample: public EdgeSample{
public:
	void init(std::vector<Vector3D> v);
	CyliEdgeSample* getNextEdge();
	void sample();
	void std::vector<Vector3D> getSample();

private:
	std::vector<Vector2D> samples;  
	Vector2D center;   
	Vector2D normal;   

	static int sampleNum;
};

int CyliEdgeSample::sampleNum;

#endif