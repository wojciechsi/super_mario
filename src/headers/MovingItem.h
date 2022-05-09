#ifndef SUPER_MARIO_MOVINGITEM_H
#define SUPER_MARIO_MOVINGITEM_H

#include <tuple>
#include "Item.h"

/**
 * Struktura przechowująca informację o możliwościach ruchu
 */
struct Collisons {
    bool left = false, right = false, up = false , down = false;
};

/**
 * Klasa przechowuje informacje o poruszającym się obiekcie
 */
class MovingItem : public Item{
public:
    MovingItem() = default;

    /**
     * Konstruktor przenoszący
     */
    MovingItem(const MovingItem& other) = default;

    /**
     * Konstruktor dwuargumentowy
     */
    MovingItem(int iX, int iY);

    /**
     * Przesuwa obiekt, o ile jest taka możliwość
     * @param x przesunięcie poziome
     * @param y przesunięcie pionowe
     */
    void move(const float x, const float y);
private:
    /**
     * Przemieszcza obiekt o stałą grawitacji dla klatki.
     * Warunek możliwości ruchu jest sprawdzany wewnętrznie.
     */
    void gravityMove() {move(0, GRAVITY_FACTOR);};
protected:
    Collisons collisions;
public:
    /**
     * Metoda zwracająca informację o dolnej kolizji.
     * @return czy występuje kolizja dolna
     */
    bool isOnTopOfAny() const;

    void setOnTopOfAny(bool rvalue);



    /**
    * Aktualizuje położenie i stan
    */
    void update();
};


#endif //SUPER_MARIO_MOVINGITEM_H
