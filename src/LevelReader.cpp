#include "headers/LevelReader.h"

std::shared_ptr<ReadingSystem> ReadingSystem::instance = 0;

std::shared_ptr<ReadingSystem> ReadingSystem::getInstance() {
    if (instance == 0) {
        instance = std::make_shared<ReadingSystem>();
    }
    return instance;
}

void ReadingSystem::levelReader()
{
    std::vector<std::string> filenames;
    std::string validNames;
    std::vector<std::string> validLevelNames;
    std::regex levelRegex("[Ll]evel.+txt");
    if(userInputFlag)
    {
        validLevelNames.clear();
        validLevelNames.push_back(userInput);
    }
    else {
        for (auto &p: std::filesystem::recursive_directory_iterator("../src")) {
            filenames.push_back(p.path().filename().string());
        }
        auto filter = [&levelRegex, &validLevelNames](const std::string &current) {
            if (std::regex_match(current, levelRegex)) {
                validLevelNames.push_back(current);
            }
        };
        std::for_each(std::ranges::begin(filenames), std::ranges::end(filenames), filter);
    }
   //Funkcja testowa
   for(int i=0; i<validLevelNames.size(); i++)
   {
       std::cout << validLevelNames[i] << std::endl;
   }
    levelNames = validLevelNames;
}

bool ReadingSystem::ifUserInput()
{
    return userInputFlag;
}

std::string ReadingSystem::getUserInput()
{
    return userInput;
}

void ReadingSystem::changeUserInputFlag()
{
    userInputFlag = true;
}

void ReadingSystem::captureUserInput(std::string ui) {
    userInput = ui;
}

std::string ReadingSystem::randomizeLevel() {
   /* std::srand(time(0));
    int levelNumber = rand() % levelNames.size();*/
    return levelNames[0];

}

void ReadingSystem::findFilePath()
{
    for(auto& p: std::filesystem::recursive_directory_iterator("../src"))
    {
        if(p.path().filename().string() == randomizeLevel())
        {
            filePath = p.path().string();
            return;
        }
    }
}

bool ReadingSystem::ifFirstRun()
{
    return firstRun;
}

void ReadingSystem::changeFirstRun() {
    firstRun = false;
}
std::string ReadingSystem::getFilePath() {
    return filePath;
}

bool ReadingSystem::ifFirstInput() {
    return  firstInput;
}

void ReadingSystem::changeFirstInput() {
    firstInput = false;
}