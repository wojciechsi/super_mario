#include "headers/HighScoreModule.h"

int HighScoreModule::highScore = 0;

int HighScoreModule::getHighScore() {
    return highScore;
}

void HighScoreModule::setHighScore(int newScore) {
    if (newScore > HighScoreModule::highScore)
        HighScoreModule::highScore = newScore;
}

void HighScoreModule::saveHighScore() {
    std::ofstream f;
    f.open("../src/highScore");
    if (f.is_open()) {
        f << highScore;
        f.close();
    }
}

void HighScoreModule::loadHighScore() {
    std::filesystem::path path;
    for(auto& p: std::filesystem::recursive_directory_iterator("../src"))
    {
        if(p.path().filename().string() == "highScore")
        {
            path = p.path().string();
        }
    }
    if (!path.empty()) {
        std::ifstream f;
        f.open(path.c_str());
        if (f.is_open()) {
            f >> highScore;
            f.close();
        }
    }
}
