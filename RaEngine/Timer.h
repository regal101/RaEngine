#pragma once
// Built in Libraries
#include <chrono>

// Includes


// Namespaces
namespace EngineUtils {

// Class declarations


class Timer
{
protected:

	// -------------------- Attributes -------------------- //

	// Pointer instance of Timer
	static Timer* sInstance;

	// Stored clock start time
	std::chrono::system_clock::time_point mStartTime;

	// Time difference between start time and current time
	std::chrono::duration<double> mDeltaTime;

	// Clock timescale
	float mTimeScale;

	// -------------------- Methods -------------------- //

	// Default constructor
	Timer();

	// Destructor
	~Timer();

public:

	// -------------------- Attributes -------------------- //


	// -------------------- Methods -------------------- //

	// Returns an instance of Timer
	static Timer* Instance();

	// Deletes instance of Timer
	static void Release();

	// Sets clock Start time to current time
	void Reset();

	// Calcultes time elapsed
	double DeltaTime();

	// Sets time scale
	void TimeScale(double t = 1.0);

	// Gets time scale
	double TimeScale();

	// Ticks Clock
	void Tick();

	// -------------------- Friendship -------------------- //
};


}