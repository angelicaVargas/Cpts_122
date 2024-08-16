#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const* argv[])
{
    ifstream infile;
    string line;
    int lastPosition = 0;
    int currentPosition = 0;

    infile.open("lorem_ipsum.txt");
    if (infile.is_open()) {
        while (infile.good())
        {
            getline(infile, line);

            currentPosition = line.find('.', lastPosition);
            if (currentPosition != std::string::npos) {
                std::cout << "period found at: " << currentPosition << '\n';
                cout << line << endl;
            }
        }

    return 0;
}

