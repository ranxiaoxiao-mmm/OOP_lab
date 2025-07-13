// Author: Vincent Wang
// Date  : 2025/4/9
// Purpose:
//	简单的码表类，参考
//  Stopwatch sw;
//    sw.start();
//    ....
//    sw.stop();
//   std::cout << sw.getDuration() << " ms";
//   or  
//   std::cout << sw.getDuration(TimeUnit::Seconds) << " s";

#pragma once

#include <chrono>

class Stopwatch {
  public:
    enum class TimeUnit { Nanoseconds, Microseconds, Milliseconds, Seconds };

  public:
    Stopwatch() : starttime_{}, stoptime_{}, running_{false} {}
	void reset() {
		running_ = false;
	}
    void start() {
        if (!running_) {
            starttime_ = std::chrono::high_resolution_clock::now();
            running_ = true;
        }
    }
    void stop() {
        if (running_) {
            stoptime_ = std::chrono::high_resolution_clock::now();
            running_ = false;
        }
    }
    double getDuration(TimeUnit unit=TimeUnit::Milliseconds) const {
        auto end =
            running_ ? std::chrono::high_resolution_clock::now() : stoptime_;
        auto duration = end - starttime_;
        switch (unit) {
        case TimeUnit::Nanoseconds:
            return std::chrono::duration<double, std::nano>(duration).count();
        case TimeUnit::Microseconds:
            return std::chrono::duration<double, std::micro>(duration).count();
        case TimeUnit::Seconds:
            return std::chrono::duration<double>(duration).count();
        case TimeUnit::Milliseconds:  
        default:
			return std::chrono::duration<double, std::milli>(duration).count();
        }
    }

    bool isRunning() const { return running_; }

  private:
    std::chrono::high_resolution_clock::time_point starttime_{};
    std::chrono::high_resolution_clock::time_point stoptime_{};
    bool running_{false};
};
