#include <iostream>
#include <string>
#include <iterator> 
#include <fstream>   // Required for ifstream and ofstream
#include <vector>    // Required for vector
#include <algorithm> // Required for sort and unique_copy

using namespace std;

int main() {
    string from, to;
    
    // It's helpful to add a prompt so the program doesn't just stare at you blankly!
    cout << "Enter source and target file names: ";
    cin >> from >> to; // get source and target file names
    
    ifstream is{from}; // input stream for file "from"
    
    // Good practice: check if the file actually opened
    if (!is) {
        cerr << "Error: Could not open input file '" << from << "'\n";
        return 1;
    }

    istream_iterator<string> ii{is}; // input iterator for stream
    istream_iterator<string> eos{};  // input sentinel
    
    ofstream os{to}; // output stream for file "to"
    
    if (!os) {
        cerr << "Error: Could not open output file '" << to << "'\n";
        return 1;
    }

    ostream_iterator<string> oo{os, "\n"}; // output iterator for stream
    
    vector<string> b{ii, eos}; // b is a vector initialized from input [ii:eos)
    
    sort(b.begin(), b.end()); // sort the buffer
    unique_copy(b.begin(), b.end(), oo); // copy buffer to output, discard replicated values
    
    return !is.eof() || !os; // return error state (§2.2.1, §38.3)
}