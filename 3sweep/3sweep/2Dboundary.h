#ifndef 2DBOUNDARY_H
#define 2DBOUNDARY_H

class 2DBoundary{
public:
	void init();
	std::vector<Vector2D> intersection(Vector2D v[2]); 
};
#endif