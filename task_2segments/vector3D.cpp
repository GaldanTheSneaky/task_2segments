#include"vector3D.h"

Vector3D::Vector3D(): x(0), y(0), z(0){}

Vector3D::Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

std::ostream& operator << (std::ostream& out, Vector3D& vector3D)
{
	out << vector3D.x << ' ' << vector3D.y << ' ' << vector3D.z;

	return out;
}

double dot(Vector3D& first, Vector3D& second)
{
	return first.x * second.x + first.y * second.y + first.z*second.z;
}

Vector3D cross(Vector3D& first, Vector3D& second)
{
	Vector3D newVector;
	newVector.x = first.y * second.z - first.z * second.y;
	newVector.y = first.z * second.x - first.x * second.z;
	newVector.z = first.x * second.y - first.y * second.x;

	return newVector;

}

double Vector3D::magnitude()
{
	return(sqrt(this->x * this->x + this->y * this->y + this->z * this->z));
}

Vector3D Vector3D::operator+ (Vector3D& other)
{

	return Vector3D(this->x + other.x, this->y + other.y, this->z + other.z);
}

Vector3D Vector3D::operator- (Vector3D& other)
{
	Vector3D newVector;
	newVector.x = this->x - other.x;
	newVector.y = this->y - other.y;
	newVector.z = this->z - other.z;

	return newVector;
}

bool Vector3D::operator ==(Vector3D& other)
{
	if (this->x == other.x && this->y == other.y && this->z == other.z)
		return true;
	else 
		return false;
}



