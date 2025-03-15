#include <fstream>
#include <iostream>
#include <stream>

std::ofstream
openToWrite(const std::string &name)
{
    std::ofstream file(name); // open a file to write to
    if (!file)
    {
        std::cerr << "can't open file '" << name << "'\n";
        std::exit(EXIT_FAILURE);
    }
    return file;               // return ownership (open file)
}

void
storeData(std::ofstream fstrm) // takes ownership of file (but this might change)
{
    fstrm << 42 << '\n';
} // closes the file

int
main()
{
    auto outFile{openToWrite("iostream.tmp")}; // open file
    storeData(std::move(outFile));             // store data

    // better ensure that the file is closed:
    if (outFile.is_open())
    {
        outFile.close();
    }
}
