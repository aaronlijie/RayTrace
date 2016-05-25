#ifndef CAMERA_H
#define CAMERA_H

#include "all.h"

namespace HYF
{

class Camera
{
public:
	Camera():m_Eye(0,0,-5),m_Target(0,0,0),m_Dist(5.0),m_Width(8.0),m_Height(6.0),m_Ratio(0.01){}
	Camera(vector3 p_Eye,vector3 p_Target,double p_Dist,double p_Width,double p_Height,double p_Ratio):
		m_Eye(p_Eye),m_Target(p_Target),m_Dist(p_Dist),m_Width(p_Width),m_Height(p_Width),m_Ratio(p_Ratio){}
	inline vector3 getEye(){return m_Eye;}
	vector3 getDir(double x,double y)//�������꣬������Ҳ�����ڳ�������ȡС��
	{
		vector3 dir = m_Target - m_Eye;
		NORMALIZE(dir);
		dir = dir * m_Dist;
		//return dir;
		m_x = dir.Cross(vector3(0,1,0));
		NORMALIZE(m_x);
		m_y = m_x.Cross(dir);
		NORMALIZE(m_y);
		vector3 ret = dir + (x * m_Ratio - 0.5 * m_Width) * m_x + (y * m_Ratio - 0.5 * m_Height) * m_y;
		NORMALIZE(ret);
		return ret;
	}
private:
	vector3 m_Eye;
	vector3 m_Target;
	double m_Dist;
	double m_Width;
	double m_Height;
	vector3 m_x;//ͶӰƽ���x���������
	vector3 m_y;//ͶӰƽ���y���������
	double m_Ratio;//���������ص���ά����ϵ�����űȣ���ͼ��λ���ض�ӦͶӰƽ��������ϵ�еĳ���
};

}

#endif