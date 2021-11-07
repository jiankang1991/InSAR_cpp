#pragma once
#ifndef __COMPLEXMAT__H__
#define __COMPLEXMAT__H__
#include"Package.h"

using cv::Mat;
using namespace std;
class InSAR_API ComplexMat
{
public:
	ComplexMat();
	ComplexMat(Mat& real, Mat& imagine);
	ComplexMat(int rows, int cols);
	/*�������캯��*/
	ComplexMat(const ComplexMat& b);
	~ComplexMat();
	void SetRe(Mat& re);
	void SetIm(Mat& im);
	Mat GetRe() const;
	Mat GetIm() const;
	Mat GetMod() const;
	/*���㸴�������λ*/
	Mat GetPhase();
	int type() const;
	int GetRows() const;
	int GetCols() const;
	/*���㸴����������*/
	int Mul(const ComplexMat& Src, ComplexMat& Dst, bool bConj) const;
	/*���㸴���˻�(���,elementwise)*/
	ComplexMat operator*(const ComplexMat& b) const;
	/*����������ʵ�������Ӧ���*/
	ComplexMat operator*(const Mat& a) const;
	/*����������Գ���*/
	ComplexMat operator*(const double& a) const;
	/*ȡ�����ָ�������*/
	ComplexMat operator()(cv::Range _rowRange, cv::Range _colRange) const;
	/*���������󲿷ֽ��и�ֵ*/
	int SetValue(cv::Range _rowRange, cv::Range _colRange, ComplexMat& src);
	/*��������ӷ�*/
	ComplexMat operator+(const ComplexMat& b) const;
	/*�����ֵ*/
	ComplexMat operator=(const ComplexMat&);
	/*�������������
	* ����1 ��ͷ���0Ϊ����ÿ����ͣ�1Ϊ����ÿ����ͣ�
	*/
	ComplexMat sum(int dim = 0) const;
	/*��ȡ������*/
	ComplexMat conj() const;
	/*�������Ԫ�ظ���*/
	int countNonzero() const;
	/*�����Ƿ�Ϊ��*/
	bool isempty()const;
	/*ת������*/
	void convertTo(ComplexMat& out, int type) const;
	Mat re;
	Mat im;
private:

	Mat mod;
	Mat Phase;
};


#endif // !__COMPLEXMAT__H__
