#include "../../pch.h"

namespace i6
{
    // Returns good user input; option = 0 filters non-numeric; option = 1 filters nothing (default);
    //
    // Example usage: render.input("this is the text that gets printed to the console", 0);
    //
    std::string Render::input(std::string input_text, int option)
    {
        // option = 0 filters non-numeric
        if (option == 0)
        {
            std::string user_input_string = "";
            size_t user_input_size_t = 0;

            std::cout << input_text << '\n'; // Asks user for input

            // Loop until user gives good input
            while(true)
            {
                std::cin >> user_input_size_t; // Stores in user_input_size_t

                // If user input is bad clear input; else escape loop
                if (std::cin.fail())
                {
                    std::cin.clear();

                    // Filter non-numeric input
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                else
                {
                    break;
                }
            }
            
            user_input_string = std::to_string(user_input_size_t);

            return user_input_string;
        }
        
        // option = 1 filters nothing (default)
        else if (option == 1)
        {
            std::string user_input_string = "";

            std::cout << input_text << '\n'; // Asks user for input

            // Loop until user gives good input
            while(true)
            {
                std::cin >> user_input_string; // Stores in user_input_size_t

                // If user input is bad clear input; else escape loop
                if (std::cin.fail())
                {
                    std::cin.clear();
                }
                else
                {
                    break;
                }
            }

            return user_input_string;
        }
        
        return "";
    }

    // Random Number Generator. Optinal provide start and end int distrobution.
    //
    // Example Usage: auto random = render.random(-5000, 5000);
    //
    long int Render::random(long int start, long int end)
    {
        std::random_device seeder;
        std::mt19937 engine(seeder());
        std::uniform_int_distribution<long int> dist(start, end);

        return dist(engine);
    }

    // Cross Platform clear console
    #if defined(__unix__) || defined(__linux__) || defined(__APPLE__) || defined(__MINGW32__) || defined(__MINGW64__)
    void Render::clear_console()
    {
        system("clear");
    }

    #elif defined(_WIN32) || defined(_WIN64)
    void Render::clear_console()
    {
        system("cls");
    }

    #else
    void Render::clear_console() { }

    #endif

    // Hang console on windows
    #if defined(_WIN32) || defined(_WIN64)
    void Render::hang_console()
    {
        std::cin.get();
    }

    #else
    void Render::hang_console() { }

    #endif

    // Waits for User to press Enter
    void Render::close_console()
    {
        std::cout << std::endl << std::endl << "Press enter to exit" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }
}
