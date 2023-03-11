#ifndef _STOP_WATCH_H_
#define _STOP_WATCH_H_

#include <chrono>
#include <atomic>
#include <mutex>

enum class TimeLevel : int
{
    us,
    ms,
    s,
};


class StopWatch
{
public:
    StopWatch()
    {
    }

    ~StopWatch()
    {}

    void Start()
    {
        mStart = std::chrono::steady_clock::now();
    }

    void Stop()
    {
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        int64_t _time  = std::chrono::duration_cast<std::chrono::microseconds>(end - mStart).count();
        elapsed = static_cast<double>(_time);
    }

    double GetElapsed(TimeLevel category = TimeLevel::ms)
    {
        double ret = 0.0;
        if(TimeLevel::us == category){
            ret = elapsed;
        }
        else if(TimeLevel::ms == category){
            ret = static_cast<double>(elapsed) / 1000.0;
        }
        else if(TimeLevel::s == category){
            ret = static_cast<double>(elapsed) / 1000000.0;
        }

        return ret;

    }

private:
    std::chrono::steady_clock::time_point mStart;
    double elapsed = 0.0;
    int64_t mTimeLastStart = 0;
    std::mutex TimeCounterObj;
    
};
#endif // _STOP_WATCH_H_