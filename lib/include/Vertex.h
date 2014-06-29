#ifndef __VERTEX_H__
#define __VERTEX_H__

#include "Vector3f.h"

namespace blaze
{

class Vertex
{
public:
	Vertex(Vector3f data);

public:
	static const int SIZE = 3;

private:
	Vector3f _data;
};

}

#endif // __VERTEX_H__