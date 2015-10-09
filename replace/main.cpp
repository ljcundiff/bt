#include <iostream>
#include <fstream>

int findLocation(std::string sourceFile, std::string searchText)
{
    std::ifstream infile(sourceFile.c_str(), std::ios::binary);

    int position = 0;
    int offset = 0;

    char ch;
    while (infile.get(ch))
    {
        if (searchText.at(offset) == ch)
        {
            offset++;
        }
        else
        {
            position = position + offset + 1;
            offset = 0;
        }

        if (offset == searchText.length())
        {
            return position;
        }
    }

    return -1;
}

void replaceInFile(std::string sourceFile, std::string destFile, std::string replaceText, int position)
{
    std::ifstream infile(sourceFile.c_str(), std::ios::binary);
    std::ofstream outfile(destFile.c_str(), std::ios::binary);

    int count = 0;
    char ch;
    while (infile.get(ch))
    {
        if (count >= position && count < (position + replaceText.length()) )
        {
            outfile.put(replaceText.at((unsigned long)(count - position)));
        }
        else
        {
            outfile.put(ch);
        }
        count++;
    }
}

int main(int argc, char* argv[])
{
    if (argc < 4)
    {
        std::cout << "Usage: replace <search_text> <replace_text> <source_file> [<dest_file>]" << std::endl;
        return -1;
    }

    std::string  searchText(argv[1]);
    std::string  replaceText(argv[2]);
    std::string  sourceFile(argv[3]);

    if (searchText.length() != replaceText.length())
    {
        std::cout << "ERROR: search and replace must be the same length" << std::endl;
        return -1;
    }

    int location = findLocation(sourceFile, searchText);
    if (location < 0)
    {
        std::cout << "ERROR: search text not found" << std::endl;
        return -1;
    }

    if (argc > 4)
    {
        std::string  destFile(argv[4]);
        replaceInFile(sourceFile, destFile, replaceText, location);
        std::cout << "REPLACED: " << searchText << " with " << replaceText << " at " << location << " in " << destFile << std::endl;
    }
    else
    {
        std::cout << location << std::endl;
    }

    return 0;
}