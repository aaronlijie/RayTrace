#ifndef CAMERA_H
#define CAMERA_H

#include "all.h"

namespace HYF
{
/*
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
*/
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
	inline void setRV(double p_R,double p_V){ m_R = p_R; m_V = p_V; }
	Ray getRandRay(double x,double y)//�����ȡ��Ȧ�������һ�����ߣ����Լ�����ɫ
	{
		//printf("%llf\n",LENGTH(m_x));
		double x0,y0;
		do
		{
			x0 = 2.0 * (double)rand() / RAND_MAX - 1.0;
			y0 = 2.0 * (double)rand() / RAND_MAX - 1.0;
		}while(x0 * x0 + y0 * y0 > 1);
		x0 *= m_R;
		y0 *= m_R;
		vector3 randPos = m_Eye + x0 * m_x + y0 * m_y;
		vector3 dir = getDir(x,y);
		vector3 focusPos = m_Eye + dir * m_V * (1.0 / m_Dist);
		vector3 rayDir = focusPos - randPos;
		NORMALIZE(rayDir);
		//return Ray(focusPos,rayDir);
		return Ray(randPos,rayDir);
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

	double m_R;//��Ȧ�İ뾶
	double m_V;//�۾�����ƽ��ľ���
};
}

#endif