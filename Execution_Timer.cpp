#include <iostream>     //Input/Output
#include <fstream>      //Read/Write 
#include <chrono>       //Time checker
#include <cstdlib>      //Standard C Library
using namespace std;    //Simplify

// This code takes user input as a string, writes it to a .py file and executes it, measuring the time at and after execution to estimate execution time.

int main() {

    string line;                                            // Variable to hold each line of Python entered, rewritten each new line (ends if empty, problem handling whitespace?)
    ofstream pythonFile("temp_script.py");                  // Output File Stream (OFStream) for code to be written to .py file


    //Code Read and write, Could also do this with 'for every line in input' - might fix whitespace issue
    
    cout << "Enter your Python code (end with an empty line):\n";
    while (getline(cin, line) && !line.empty()) {           // line assigned string of python code, check line isnt empty or break loop
        pythonFile << line << endl;                         // Write line through ofstream to pythonFile adding newline chr
    }
    pythonFile.close();                                     // Safely close file as it should contain all entered Python now


    //Timer Element
    auto start = chrono::high_resolution_clock::now();      // Check current time, assign to start
    system("python temp_script.py");                        // Run Python code and prints to terminal
    auto end = chrono::high_resolution_clock::now();        // Check current time, assign to end

    chrono::duration<double> duration = end - start;        // Calculate start - end, assign to duration

    //Display duration
    cout << "Execution time: " << duration.count() << " seconds" << endl;   // Display the duration, count method on duration object (double for accuracy) with seconds after it 

    return 0;
}


/* Could be a real problem with duration calculation, as start calculated before execution of code and 
end calculated after execution. Depends on delay between timechecks and running Python

Also need to rework to handle blank spaces, currently any blank line registers as a break for readwrite loop.

Must put restrictions on input, addressing security concerns.

Also it runs into some problems with larget loops, seems to just cut off and then not display exec time.
Either it finishes, calculated and runs out of terminal space to write to (unlikely) or the code cant handle larger loops as it

After some research, I could display the memory addresses of various things from the python code using a wrapper

I could also use this to show the stack. */
