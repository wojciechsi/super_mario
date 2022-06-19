#ifndef SUPER_MARIO_HIGHSCOREMODULE_H
#define SUPER_MARIO_HIGHSCOREMODULE_H

#include <filesystem>
#include <fstream>



class HighScoreModule {
    static int highScore;
public:
    static int getHighScore();

    static void setHighScore(int newScore);

public:
    static void loadHighScore ();
    static void saveHighScore();
};


#endif //SUPER_MARIO_HIGHSCOREMODULE_H
