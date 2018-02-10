#include "Rect.h"

Rect::Rect()
{

	pos = Vector3(0);
	size = Vector3(0);
	UpdateVerticies();
}

Rect::Rect(Vector3 _size) : Rect()
{
	pos = Vector3(0);
	size = _size;
	UpdateVerticies();
}

Rect::Rect(Vector3 _pos, Vector3 _size) : Rect(_size)
{
	pos = _pos;
	UpdateVerticies();
}

void Rect::MoveBy(Vector3 by)
{
	pos = pos + by;
	UpdateVerticies();
}

void Rect::MoveTo(Vector3 to)
{
	pos = to;
	UpdateVerticies();
}

void Rect::SetSize(Vector3 _size)
{
	size = _size;
	UpdateVerticies();
}

void Rect::UpdateVerticies()
{
	lowerLeftVertex		= Vector3(pos.x - size.x / 2, pos.y - size.y / 2, 0);
	lowerRightVertex	= Vector3(pos.x + size.x / 2, pos.y - size.y / 2, 0);
	upperLeftVertex		= Vector3(pos.x - size.x / 2, pos.y + size.y / 2, 0);
	upperRightVertex	= Vector3(pos.x + size.x / 2, pos.y + size.y / 2, 0);
}

const std::vector<Vector3> Rect::ToVector()
{
	std::vector<Vector3> v;

	v.push_back(lowerLeftVertex);
	v.push_back(lowerRightVertex);
	v.push_back(upperLeftVertex);
	v.push_back(upperRightVertex);

	return v;

}


