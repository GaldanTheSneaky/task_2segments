#pragma once
#include<iostream>

class Vector3D
{
public:  // добавил модификатор доступа public для упрощения, если это запрещено, то альтернатива - сделать intersect friend функцией или написать геттеры

	double x;
	double y;
	double z;

	Vector3D();
	Vector3D(double x, double y, double z);

	Vector3D operator +(Vector3D& other);
	Vector3D operator -(Vector3D& other);
	bool operator ==(Vector3D& other);
	friend std::ostream& operator<< (std::ostream& out, Vector3D& vector3D);

	friend double dot(Vector3D& first, Vector3D& second);
	friend Vector3D cross(Vector3D& first, Vector3D& second);
	double magnitude();

};
