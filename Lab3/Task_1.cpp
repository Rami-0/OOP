#include <iomanip>
#include <iostream>
#include <string>
#include <thread> // for the alternative timer
#include <time.h> // for the alternative timer
#include <csignal> 

using namespace std;

clock_t start, stop;
// CLK_TCK is CLOCKS_PER_SEC; 

class Timer
{
private:
    int initialTime;
    int remainingTime;

public:
    // Constructor with integer input (seconds)
    Timer(int seconds)
    {
        initialTime = seconds;
        remainingTime = seconds;
    }

    // Constructor with string input (parsing as seconds)
    Timer(const string& timeString)
    {
        initialTime = stoi(timeString);
        remainingTime = initialTime;
    }
`                                                                                                                                                       1
    // Constructor with minutes and seconds input
    Timer(int minutes, int seconds)
    {
        initialTime = minutes * 60 + seconds;
        remainingTime = initialTime;
    }

    // Function to handle interrupt signal (SIGINT)
    static void handleInterrupt(int signal)
    {
        cout << "\nTimer interrupted. Exiting...\n";
        exit(0);
    }

    // Countdown timer function
    void run()
    {
        signal(SIGINT, handleInterrupt);

        cout << "Timer started for " << initialTime << " seconds." << endl;

        // while (remainingTime > 0) {
        //     cout << "Time remaining: " << setw(2) << remainingTime << " seconds." << endl;
        //     cout << "------------------------" << endl;
        //     this_thread::sleep_for(chrono::seconds(1));
        //     remainingTime--;
        // }

        clock_t startTime = clock(); // Record the starting time
        start = clock(); // this is for the timer validation
        while (remainingTime > 0)
        {
            if (clock() - startTime >= CLOCKS_PER_SEC)
            {
                // One second has passed
                std::cout << "Time remaining: " << std::setw(2) << remainingTime << " seconds." << std::endl;
                std::cout << "------------------------" << std::endl;
                startTime = clock(); // Reset the starting time for the next second
                remainingTime--;
            }
        }
        stop = clock(); // close the timer

        cout << "Time's up! Bell rings.\a" << endl;
        cout << "Time taken: " << (double)(stop - start) / CLOCKS_PER_SEC << " seconds\n\n\n" << endl;
    }
};

int runTask1()
{
    // Example usage of Timer class
    Timer timer1(3); // Timer with initial time in seconds
    timer1.run();

    Timer timer2("7"); // Timer with initial time in seconds (from string)
    timer2.run();

    Timer timer3(1, 1); // Timer with initial time in minutes and seconds
    timer3.run();

    return 0;
}
