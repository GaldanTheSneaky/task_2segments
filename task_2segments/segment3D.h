#pragma once

class Segment3D
{
public: 
	Vector3D start;
	Vector3D end;

	Segment3D();
	Segment3D(Vector3D start, Vector3D end);

	friend std::ostream& operator<< (std::ostream& out, Segment3D& segment3D);
	friend bool intersect(Segment3D& first, Segment3D& second, Vector3D& result, double eps);

};

