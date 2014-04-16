#ifndef CONTROL_H
#define	CONTROL_H

#include "library.h"

class Control{
public:
	Control(){
		obj = new Obj;
		topEdge = NULL;
		compute3D = new Compute3D;		
	}
	~Control(){
		delete compute3D;
		delete obj;
		delete topEdge;
		delete boundary;
	}

	void control(char* buffer){
		switch (instruct){
			case setImage:
				setImage(buffer);
				break;
			case draw:
				Vector2D  v[3];
				v = (Vector2D*)buffer;
				std::vector<Vector2D> p;
				for (int i =0; i<3; i++){
					p[i] = v[i];
				} 
				setFirstEdge(p);
				break;
			case drag:
				Vector2D v = *((Vector2D*)buffer);
				buildObj(v);
				break;
			case rotate:
				break;
			default:
				break;
		}
	}

	EdgeSample getNewEdge(Vector2D &mousePosition);

	void setImage() {}
	void buildObj(Vector2D &mousePosition);
	void initBoundary(){
		boundary = new Boundary;
		boundary->init();
	}

	void setInstruct(Instruct i) { instruct = i; }
	void setStatus(Status &s) { status = s; }
	void setFirstEdge(std::vector<Vector2D> &v);
	void setBottomShape(BottomShape b) { bottomShape = b; }

	Obj* getObj() { return &obj; }
	void objAddSample() { obj.insertSample(compute3D->compute3D(topEdge->getSample())); }
private:
	Status status;
	Instruct instruct;
	BottomShape bottomShape;
	Obj* obj;
	Vector2D oldMoustPosition;
	EdgeSample* topEdge;
	Compute3D* compute3D;
	Boundary* boundary;

	enum Instruct = {setImage, draw, drag, rotate};
	enum Status = {straight, bend};
	enum BottomShape = { circle, square};
}；

#endif