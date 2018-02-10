#ifndef EJF_RECT
#define EJF_RECT

#include "Vector3.h"
#include <vector>

class Rect
{
public:
	Rect();
	Rect(Vector3 _size);
	Rect(Vector3 _pos, Vector3 _size);


	void MoveBy(Vector3 by);
	void MoveTo(Vector3 to);
	void SetSize(Vector3 _size);

	const std::vector<Vector3> ToVector();

	Vector3 upperLeftVertex;
	Vector3 upperRightVertex;
	Vector3 lowerLeftVertex;
	Vector3 lowerRightVertex;


private:
	void UpdateVerticies();

	Vector3 pos;
	Vector3 size;





};

#endif