#include"vector3D.h"
#include"segment3D.h"


int main()
{
	Vector3D a = Vector3D(6, 8, 4);
	Vector3D b = Vector3D(12, 15, 4);

	Vector3D c = Vector3D(6, 8, 2);
	Vector3D d = Vector3D(12, 15, 6);

	Vector3D testa = Vector3D(1, 1, 1);
	Vector3D testb = Vector3D(0, 2, 5);

	Vector3D testc = Vector3D(1, 1, 1);
	Vector3D testd = Vector3D(0, 0, 10);

	Segment3D teste = Segment3D(testa, testb);
	Segment3D testf = Segment3D(testc, testd);


	Segment3D e = Segment3D(a, b);
	Segment3D f = Segment3D(c, d);

	Vector3D result;
	Vector3D testresult;

	std::cout << e << std::endl;
	std::cout << f << std::endl;

	std::cout << intersect(e, f, result, 0.0001) << std::endl;
	std::cout << result << std::endl;

	std::cout << intersect(teste, testf, testresult, 0.0001) << std::endl;
	std::cout << testresult << std::endl;



	return 0;
}