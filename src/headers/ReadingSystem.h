#ifndef SUPER_MARIO_READINGSYSTEM_H
#define SUPER_MARIO_READINGSYSTEM_H
#include <string>
#include <regex>
#include <filesystem>
#include <ranges>
#include <vector>
#include <iostream>
#include <memory>
#include <ctime>
#include <random>
#include <thread>

class ReadingSystem
{
private:

    std::vector<std::string> levelNames;
    bool userInputFlag = false;
    std::string userInput;
    static std::shared_ptr<ReadingSystem> instance;
    bool firstRun = true;
    bool firstInput = true;
    std::string filePath;
    std::string randomizedLevelName;
    static std::mutex mutex;
public:
    ReadingSystem() {};
    ~ReadingSystem() {};
    /**
     * Metoda wzorca projektowego Singleton.
     * @return Instancja klasy.
     */
    static std::shared_ptr<ReadingSystem> getInstance();
    /**
     * Metoda odpowiedzialna za wczytywanie nazw poziomów z plików.
     */
    void levelReader();
    /**
     * Metoda losująca poziom, w który gracz będzie grał.
     */
    void randomizeLevel();
    /**
     * Metoda zwraca nazwę pliku z poziomem wprowadzoną przez gracza.
     * @return Nazwa pliku z poziomem wprowadzona przez gracza.
     */
    std::string getUserInput();
    /**
     * Metoda zapisująca nazwę pliku podaną przez użytkownika.
     * @param ui Nazwa pliku.
     */
    void captureUserInput(std::string ui);
    /**
     * Flaga podania nazwy pliku przez użytkownika.
     * @return Informacja, czy użytkownik chce wczytać poziom z pliku.
     */
    bool ifUserInput();
    /**
     * Zmienia flagę wprowadzenia nazwy poziomu przez użytkownika.
     */
    void changeUserInputFlag();
    ReadingSystem(ReadingSystem& other) = delete;
    void operator=(const ReadingSystem&) = delete;
    /**
     * Metoda znajdująca ścieżkę pliku.
     */
    void findFilePath();
    /**
     * Informajca, czy kliknięcie nowej gry jest pierwszym kliknięciem. Pozwala to na optymalizacje wczytywania poziomów.
     * @return
     */
    bool ifFirstRun();
    /**
     * Zmienia flagę czy poziom jest pierwszym wczytywanym poziomem.
     */
    void changeFirstRun();
    /**
     * Zwraca ścieżkę pliku.
     * @return Ścieżka pliku.
     */
    std::string getFilePath();
    /**
     * Analogicznie jak w ifFirstRun, jednak dla wczytywania przez użytkownika.
     * @return
     */
    bool ifFirstInput();
    /**
     * Zmienia flagę wprowadzenia nazwy poziomu przez użytkownika.
     */
    void changeFirstInput();



};
#endif //SUPER_MARIO_READINGSYSTEM_H
