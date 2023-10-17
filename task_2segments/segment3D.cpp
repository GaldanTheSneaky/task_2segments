#include"vector3D.h"
#include"segment3D.h"

Segment3D::Segment3D() :start(*new Vector3D), end(*new Vector3D) {}

Segment3D::Segment3D(Vector3D start, Vector3D end) :start(start), end(end) {}

std::ostream& operator<< (std::ostream& out, Segment3D& segment3D)
{
	out << "(" << segment3D.start << "), (" << segment3D.end << ")";

	return out;
}

bool intersect(Segment3D& first, Segment3D& second, Vector3D& result, double eps)
/* ������� ������� ����� ����c������ ���� �������� ���� ���������� ����������� ������� ����� �������, �� ������� ��� �����. 
�������� ���� �� https://paulbourke.net/geometry/pointlineplane/ by Paul Bourke.
���� � ���, ����� ����� �����������s ������������ �������� � ������� ���������� ����� �������� �������. ��� ���� ������� ������� ������ ���� ��������������� ����� ������, ����� ���� ����������.
������ �������, ��� ��� ��������� ������������ � ������ ��������� ������ ��������� 0. �� ����� �� ���������� ��������� ��� ���������� ������������� � ������ ���.
���� ����� �������� ������� ���������, �� ����� ������������. ���� ������������ ������������ �������� ����� � ��������� �� 0 �� 1, �� ����� ����������� ��������� �� ������ ��������.
*/
{
	Vector3D p1 = first.start;
	Vector3D p2 = first.end;
	Vector3D p3 = second.start;
	Vector3D p4 = second.end;

	Vector3D p13, p43, p21;
	double d1343, d4321, d1321, d4343, d2121; // ��������� ���������� ��� ��������� ������� ����������
	double ma, mb; // ������������ ������������� ������� ��� ��������� ������� ����� pa = p1 + ma*(p2-p1); pb = p3 + mb*(p4-p3)

	p13 = p1 - p3;
	p43 = p4 - p3;
	if (p43.magnitude() < eps)
		return(false);

	p21 = p2 - p1;
	if (p21.magnitude() < eps)
		return(false);

	double pm1 = p1.magnitude();
	double pm2 = p2.magnitude();
	double pm3 = p3.magnitude();
	double pm4 = p4.magnitude();

	if ((cross(p21, p43).magnitude() == 0 && // �������� �� ������, ����� ������� ����� �� ����� ������, �� ����� ���� ����� �����.
		(fabs(std::max(pm1, pm2) - std::min(pm3, pm4)) < eps || fabs(std::min(pm1, pm2) - std::max(pm3, pm4)) < eps)) || 
		(cross(p21, p43).magnitude() != 0))// (���� ����������� � ����������� ����� ������ ������� ����� ������������ ����� ������� ��� ���� �� �����������)
	{
			if ((fabs(p1.x - p3.x) < eps && fabs(p1.y - p3.y) < eps && fabs(p1.z - p3.z) < eps) || // ���������� ����� �����
				(fabs(p1.x - p4.x) < eps && fabs(p1.y - p4.y) < eps && fabs(p1.z - p4.z) < eps))
			{
				result = p1;
				return true;
			}

			if ((fabs(p2.x - p3.x) < eps && fabs(p2.y - p3.y) < eps && fabs(p2.z - p3.z) < eps) ||
				(fabs(p2.x - p4.x) < eps && fabs(p2.y - p4.y) < eps && fabs(p2.z - p4.z) < eps))
			{
				result = p2;
				return true;
			}
	}

	d1343 = dot(p13, p43);
	d4321 = dot(p43, p21);
	d1321 = dot(p13, p21);
	d4343 = dot(p43, p43);
	d2121 = dot(p21, p21);

	if (fabs(d2121 * d4343 - d4321 * d4321) < eps)
		return(0);

	ma = (d1343 * d4321 - d1321 * d4343) / (d2121 * d4343 - d4321 * d4321);
	mb = (d1343 + d4321 * (ma)) / d4343;

	Vector3D pa(p1.x + ma * p21.x, p1.y + ma * p21.y, p1.z + ma * p21.z); // ����� ����������� ������� ����� �������
	Vector3D pb(p3.x + ma * p43.x, p3.y + ma * p43.y, p3.z + ma * p43.z);

	if (fabs(pa.x - pb.x) < eps && // ��������� ��������� �� ����� ���������� ������� � ����� �� ��� �� ������ ��������
		fabs(pa.y - pb.y) < eps &&
		fabs(pa.z - pb.z) < eps &&
		ma >= 0 && ma <= 1 &&
		mb >= 0 && mb <= 1)
	{
		result = pa;
		return true;
	} 
	else 
		return false;
}

