#include "../../pch.h"

namespace i6
{
    bool Engine::is_prime(unsigned long long x)
    {
        if (x < 2)
            return false;
        for (unsigned long long i = 2; i <= floor(sqrt(x)); i++)
            if (x % i == 0)
                return false;
        return true;
    }

    unsigned long long Engine::next_prime(unsigned long long x)
    {
        for (unsigned long long i = x + 1; i < x * 2; i++)
            if (is_prime(i) == 1)
                return i;
        return 0;
    }

    bool Engine::is_prime_threaded(unsigned long long x)
    {
        //Timer timer;
        Proc proc;

        unsigned long long cpus = proc.validate_threads();

        if (x < 1000)
            return is_prime(x);

        std::vector<std::thread> threads(cpus);
        std::mutex iomutex;

        std::vector<std::vector<unsigned long long>> cpu_arr;
        cpu_arr.push_back(std::vector<unsigned long long>(cpus, 0));
        cpu_arr.push_back(std::vector<unsigned long long>(cpus, 0));

        std::vector<unsigned long long> arr;

        unsigned long long y = 2;

        for (unsigned long long i = 0; i < cpus; i++)
        {
            cpu_arr[0][i] = y;

            // Linear Distrobution
            y = ((floor(sqrt(x)) / cpus) * (i + 1)) + 1 * i;

            // Logarithmic Distrobution
            //y = (log(i + 2)/log(cpus + 1)) * floor(sqrt(x));

            cpu_arr[1][i] = y;
        }
        
        for (unsigned long long i = 0; i < cpus; i++)
        {
            threads[i] = std::thread( [&x, &cpu_arr, &arr, &iomutex, i]
            {
                for (unsigned long long j = cpu_arr[0][i]; j <= cpu_arr[1][i];)
                {
                    if (x % j == 0)
                    {
                        std::lock_guard<std::mutex> iolock(iomutex);
                        arr.push_back(j);
                    }
                    else if (arr.size() > 0)
                    {
                        std::lock_guard<std::mutex> iolock(iomutex);
                        j = cpu_arr[1][i];
                    }
                    
                    if (j < 14)
                        j++;
                    else if (j % 2 == 0)
                        j++;
                    else
                        j += 2;
                }
            } );
        }

        for (auto& t : threads)
            t.join();

        if (arr.size() == 0)
            return true;

        return false;
    }

    unsigned long long Engine::next_prime_threaded(unsigned long long x)
    {
        for (unsigned long long i = x + 1; i < x * 2; i++)
            if (is_prime_threaded(i) == 1)
                return i;
        return 0;
    }
}
