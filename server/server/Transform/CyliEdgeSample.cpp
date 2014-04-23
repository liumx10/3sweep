#include "../stdafx.h"
#include "CyliEdgeSample.h"

void CyliEdgeSample::init(std::vector<Vector2D> v){
	endpoint = boundary->calcIntersection(v);
	center = endpoint[0] + endpoint[1];
	center /= 2;
	a = endpoint[0].distanceTo(endpoint[1])/2;

	normal = endpoint[1] - endpoint[0];
	normal.normalize();
	normal = normal.getNormal();

	std::vector<Vector2D> v2;
	v2.push_back(v[1]);
	v2.push_back(v[2]);
	v2 = boundary->calcIntersection(v2);
	b = v2[1].distanceTo(center)/2;

	if (normal*(v2[1] - v2[0]) > 0){
		normal *= -1;
	}
	sample();
}

void CyliEdgeSample::sample(){
	double t = b/a;
	a = endpoint[0].distanceTo(endpoint[1])/2;
	b = t*a;
	/*
	for (int i=0; i<sampleNum; i++){
		Vector2D p = getEllipsePoint(i);
		// someting may be done to make it faster here
		double angle = atan(normal.x/normal.y);
		Vector2D sample(p.x*cos(angle)-p.y*sin(angle), 
						p.x*sin(angle)+p.y*cos(angle));
		samples2D.push_back(sample+center);
	}*/
	double x[4], y[4];
	x[0] = center.x;             y[0] = center.y;
	x[1] = endpoint[1].x;        y[1] = endpoint[1].y;  
	x[2] = center.x + normal.x;	 y[2] = center.y + normal.y;
	x[3] = center.x;	         y[3] = center.y - b;

	std::vector<Vector3D> axes3D = compute3D->calcAxes(x, y);
	double R = axes3D[1].distanceTo(axes3D[0])+ axes3D[3].distanceTo(axes3D[0]);
	R /= 2;
	for (int i=0; i<sampleNum; i++){
		double angle = 2*PI*double(i)/sampleNum;
		double x = (0-R)*cos(angle);
		double z = (0-R)*sin(angle);
		Vector3D sample(axes3D[0].x + x, axes3D[0].y, axes3D[0].z + z);
		samples3D.push_back(sample);
	}
}

Vector2D CyliEdgeSample::getEllipsePoint(int i){
	Vector2D v;
	v.x = 4*a*i/sampleNum;
	if (i < sampleNum/4 || i>3*sampleNum/4){
		v.x = -1*v.x;
	}
	v.y = b*sqrt(1-v.x*v.x/(a*a));
	if (i < sampleNum/2){
		v.y = -1*v.y;
	}

	return v;
}


EdgeSample* CyliEdgeSample::clone(){
	CyliEdgeSample ces;
	ces.setCenter(center);
	ces.setNormal(normal);
	ces.setA(a);
	ces.setB(b);
	ces.setEndpoint(endpoint);

	return &ces;
}