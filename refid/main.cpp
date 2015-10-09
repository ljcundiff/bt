#include <iostream>
#include <string>
#include <boost/random.hpp>

const char CHARS[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','P','Q','R','S','T','U','V','W','X','Y','Z','2','3','4','5','6','7','8'};

int main()
{
    boost::mt19937 randomSeed;
    randomSeed.seed((unsigned int)std::time(NULL));

    boost::uniform_int<> distribution(0, sizeof(CHARS)-1);

    std::string refid;

    for (int i=0; i<12; i++)
    {
        refid += CHARS[distribution(randomSeed)];
    }
    std::cout << refid << std::endl;
    return 0;
}