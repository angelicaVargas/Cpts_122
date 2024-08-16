#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const* argv[]) {

    ifstream infile;
    ofstream newFile;
    string line;
    size_t lastPosition = 0;
    size_t currentPosition = 0;

    newFile.open("lorem_ipsum2.txt", ios::out);
    if (newFile.is_open()) {
        infile.open("lorem_ipsum.txt", ios::in);
        if (infile.is_open()) {
            while (infile.good()) {

                getline(infile, line);

                while ((currentPosition = line.find('.', lastPosition)) != string::npos) {

                    //currentPosition = line.find('.', lastPosition);
                    //if (currentPosition != string::npos) {
                    size_t position = currentPosition - lastPosition;

                    string sentence = line.substr(lastPosition, (position) + 1); //position, length of copy

                    cout << sentence << endl;
                    newFile << sentence << endl;

                    lastPosition = currentPosition + 1;
                }
                lastPosition = 0;
            }
        }
    }
        infile.close();
        newFile.close();

    return 0;
}
