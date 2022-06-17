#include "headers/LevelReader.h"

void LevelReader()
{
    std::vector<std::string> filenames;
    std::string validNames;
    std::vector<std::string> validLevelNames;
    std::regex levelRegex("[Ll]evel.+txt");
    for(auto& p: std::filesystem::recursive_directory_iterator("../src"))
    {
        filenames.push_back(p.path().filename().string());
    }
    auto filter = [&levelRegex, &validLevelNames](const std::string& current) {if(std::regex_match(current, levelRegex)) {validLevelNames.push_back(current);} };
   std::for_each(std::ranges::begin(filenames), std::ranges::end(filenames), filter);
   //Funkcja testowa
   for(int i=0; i<validLevelNames.size(); i++)
   {
       std::cout << validLevelNames[i] << std::endl;
   }

}

