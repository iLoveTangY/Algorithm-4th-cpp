#ifndef STOPWATCH_H
#define STOPWATCH_H

/*
 * 计时器类
 */

#include <ctime>

class StopWatch
{
    public:
        StopWatch()
        {
            start = clock();
        }

        double elapsedTime()
        {
            clock_t now = clock();
            return static_cast<double>(now - start) / CLOCKS_PER_SEC;
        }

    private:
        clock_t start;
};

#endif // STOPWATCH_H
