#include "headers/ReadingSystem.h"

std::shared_ptr<ReadingSystem> ReadingSystem::instance = 0;
std::mutex ReadingSystem::mutex;

std::shared_ptr<ReadingSystem> ReadingSystem::getInstance() {
    std::lock_guard<std::mutex> lock(mutex);
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
    randomizeLevel();
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

void ReadingSystem::randomizeLevel() {
   /* std::srand(time(0));
    int levelNumber = rand() % levelNames.size();*/
    std::random_device r;
    std::default_random_engine e(r());
    std::uniform_int_distribution<int> uniform_dist(0, levelNames.size()-1);
    int randomNumber = uniform_dist(e);
    randomizedLevelName = levelNames[randomNumber];
    return;

}

void ReadingSystem::findFilePath()
{
    for(auto& p: std::filesystem::recursive_directory_iterator("../src"))
    {
        if(p.path().filename().string() == randomizedLevelName)
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