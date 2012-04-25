#ifndef _C_ELEGANS_
#define _C_ELEGANS_

#include "Physics.h"
#include "CPoint.h"
#include "CNeuron.h"
#include "CConnector.h"
#include "VectorMath.h"

class CElegans
{
private:
	int size;//����������� ��������� ��� ������ �������� 26 ��������� �� � ����������� �������
	double length;//����� �������
	double time;// ��������� �������� � ����� �������������� ������ ���������

	std::vector <CMassPoint *> mPoint;//��� ����� ������� ������������� ����� ������ ������������ ����� ��������� ������
	std::vector <CSpring *> spring;//�������
	std::vector <CMuscle *> muscle;//�������
	std::vector <CNeuron *> neuron;// �������
	std::vector < std::vector<CNeuron *> > table;// ������� ���� ������� � ������������ ��������
	Vector3D vshift;
	double dl;
	double dx;
	////
	//std::vector <Vector3D> trace;
	//int traceTest;
	////
public:
	CElegans(const double i_length, const int i_size);//����������� ���������� �� ����� � ����������� ���������
	~CElegans();//����������
	void draw();// ��������� �����
	void iteration(const double dt);// ��������
	CNeuron * UpdateSelection();//���������� ������
	void ClearSelection();//������ ������
	void UpdateSelection(int direction);//���������� ������
	void savePosition();
	void rotateWormAroundAnterPosterAxis(float angle);

private:
	CElegans();// ��� ���� �����������, ������ ���������
	void addMPoint(CMassPoint * i_mPoint);//��������� �������� ����� 
	void addMPoint(const double i_mass, Vector3D & i_pos);//��������� �������� �����(������������� �����)
	void addSpring(CSpring * i_spring);//��������� �������
	void addSpring(const double i_length, const double i_stiffCoeff, const double i_frictCoeff, CMassPoint * i_p1, CMassPoint * i_p2);//��������� ������� 
	void addMuscle(CMuscle * i_muscle);//��������� �������
	void addMuscle(const double i_strength, CMassPoint * i_p1, CMassPoint * i_p2, std::string name);//��������� �������
	int  addNeuroMuscleAxonByNames(std::string i_neuronName, std::string i_muscleName,double i_weight);//��������� ������������� ����������
	void addNeuron(CNeuron * i_neuron);//��������� ������
	void addNeuron(const std::string i_name, Vector3D & i_pos, const float i_threshold, const char i_type, const int clr_index);//��������� ������
	void applyFriction();
	void neuronPosCorrection();//������������� ������� ��������
	

};
#endif