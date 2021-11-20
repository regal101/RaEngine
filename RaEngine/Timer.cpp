#include "Timer.h"

// Includes


// Namespaces
namespace EngineUtils {

Timer* Timer::sInstance = nullptr;

Timer* Timer::Instance() {
	if (sInstance == nullptr)
		sInstance = new Timer();
	return sInstance;
}

void Timer::Release() {
	delete sInstance;
	sInstance = nullptr;
}

Timer::Timer() {
	Reset();
	mTimeScale = 1.0;
	mDeltaTime = std::chrono::duration<double>(0.0);
}

Timer::~Timer() {}

void Timer::Reset() {
	mStartTime = std::chrono::system_clock::now();
};

double Timer::DeltaTime() {
	return mDeltaTime.count();
}

void Timer::TimeScale(double t) {
	mTimeScale = t;
}

double Timer::TimeScale() {
	return mTimeScale;
}

void Timer::Tick() {
	mDeltaTime = std::chrono::system_clock::now() - mStartTime;
}


}