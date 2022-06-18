#ifndef SUPER_MARIO_LEVELREADER_H
#define SUPER_MARIO_LEVELREADER_H
#include <string>
#include <regex>
#include <filesystem>
#include <ranges>
#include <vector>
#include <iostream>
#include <memory>
#include <ctime>

class ReadingSystem
{
private:

    std::vector<std::string> levelNames;
    bool userInputFlag = false;
    std::string userInput;
    static std::shared_ptr<ReadingSystem> instance;
    bool firstRun = true;
    std::string filePath;
public:
    ReadingSystem() {};
    ~ReadingSystem() {};
    static std::shared_ptr<ReadingSystem> getInstance();
    void levelReader();
    std::string randomizeLevel();
    std::string getUserInput();
    void captureUserInput(std::string ui);
    bool ifUserInput();
    std::vector<std::string> getLevelNames();
    void changeUserInputFlag();
    ReadingSystem(ReadingSystem& other) = delete;
    void operator=(const ReadingSystem&) = delete;
    void findFilePath();
    bool ifFirstRun();
    void changeFirstRun();
    std::string getFilePath();



};
#endif //SUPER_MARIO_LEVELREADER_H
