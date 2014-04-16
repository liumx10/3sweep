#include "Compute3D.h"

void Compute3D::init(){
}

Vector3D Compute3D::compute3D(Vector2D){
	return Vector3D(0,0,0);
}

std::vector<Vector3D> Compute3D::compute3D(std::vector<Vector2D> v){
	std::vector<Vector3D> res;
	for (unsigned int i=0; i<v.size(); i++){
		res.push_back(compute3D(v[i]));
	}
	return res;
}
