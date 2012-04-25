#ifndef _C_POINT_
#define _C_POINT_

#include  "VectorMath.h"

class CPoint
{
protected:
	Vector3D pos;

public:
	CPoint(const Vector3D &i_pos);
	virtual ~CPoint();
	virtual CPoint & operator=(const CPoint &i_point);
	void virtual draw() = 0;
	double getX();//����� X ����������
	double getY();//����� Y ����������
	double getZ();//����� Z ����������
	Vector3D getPos();
	Vector3D * getAPos();
	void setPos(Vector3D & i_pos);
	
private:
	CPoint();
};
#endif

#ifndef _C_MASS_POINT_
#define _C_MASS_POINT_
//�������� �����, � �� ����� ��������� ����� ����������� ������ 
class CMassPoint: public CPoint
{
private:
	double mass;// �����
	Vector3D vel;//��������
	Vector3D force;// ���� ����������� � ���� �����

public:
	CMassPoint(const double i_mass, const Vector3D &i_pos);//�����������
	virtual ~CMassPoint();//����������
	virtual CMassPoint & operator=(const CMassPoint &i_mpoint);//��������������� ��������� =
	void virtual draw();//��������� ����� ����
	void virtual select();//e��� �� ������� ����� �� ���������� ��� �������
	void init();//�������������
	void update();//����������
	void applyForce(const Vector3D & force);//
	void timeTick(const double dt);//
	Vector3D getVel();//
	Vector3D getForce();//
	double getMass();//
	
private:
	CMassPoint();

};
#endif