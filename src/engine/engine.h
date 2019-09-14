#ifndef ENGINE_H
#define ENGINE_H

namespace i6
{
    class Engine
    {
    private:
    
    public:
        Engine();

        bool is_prime(unsigned long long x);
        unsigned long long next_prime(unsigned long long x);
        bool is_prime_threaded(unsigned long long x);
        unsigned long long next_prime_threaded(unsigned long long x);
        void results();
    };
}

#endif
