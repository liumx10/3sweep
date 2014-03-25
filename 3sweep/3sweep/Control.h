#ifndef CONTROL_H
#define	CONTROL_H

#include "EdgeSample.h"
#include "CyliEdgeSample.h"
#include "library.h"

enum Instruct = {draw, drag, rotate};
enum Status = {straight, bend};

class Control{
public:
	void control(Instruct is){
		switch is{
			case draw:
				break;
			case drag:
				break;
			case rotate:
				break;
			default:
				break;
		}
	}

	EdgeSample getNewEdge(Vector2D &mousePosition);

private:
	Status status;
	Vector2D oldMoustPosition;
	EdgeSample* topEdge->
}；

#endif