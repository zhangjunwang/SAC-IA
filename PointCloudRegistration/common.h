#pragma once

#include <Windows.h>
#include <iostream>
#include <vector>
#include <Eigen/Core>

std::vector<float> computeEularAngles(Eigen::Matrix4f& R, bool israd = true);


class Timer{
public:
	void StartWatchTimer(){
		QueryPerformanceFrequency(&m_liPerfFreq);
		QueryPerformanceCounter(&m_liPerfStart);
	}

	float ReadWatchTimer(){
		char temp[64];
		QueryPerformanceCounter(&liPerfNow);
		dfTim = (((liPerfNow.QuadPart - m_liPerfStart.QuadPart) * 1000.0f) / m_liPerfFreq.QuadPart);//��λΪms
		return dfTim;
	}

	operator float(){
		return dfTim;
	}

protected:
	LARGE_INTEGER m_liPerfFreq;
	LARGE_INTEGER m_liPerfStart;
	LARGE_INTEGER liPerfNow;
	double dfTim;
};