#pragma once

#include <chrono>

namespace Library
{
	class GameTime final
	{
	public:
		GameTime();

		const std::chrono::high_resolution_clock::time_point& CurrentTime() const;
		void SetCurrentTime(const std::chrono::high_resolution_clock::time_point& currentTime);

		const std::chrono::milliseconds& TotalGameTime() const;
		void SetTotalGameTime(const std::chrono::milliseconds& totalGameTime);

		const std::chrono::milliseconds& ElapsedGameTime() const;
		void SetElapsedGameTime(const std::chrono::milliseconds& elapsedGameTime);

		std::chrono::duration<float> TotalGameTimeSeconds() const;
		std::chrono::duration<float> ElapsedGameTimeSeconds() const;

	private:
		std::chrono::high_resolution_clock::time_point mCurrentTime;
		std::chrono::milliseconds mTotalGameTime;  // total time since the clock is reset
		std::chrono::milliseconds mElapsedGameTime; // time between frames
	};
}
