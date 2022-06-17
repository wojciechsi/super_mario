#include "headers/TextBox.h"
TextBox::TextBox() {
    font->loadFromFile("../src/resources/SuperMario256.ttf"); //@todo put this to storage
    textBox.setCharacterSize(0.6*SCREEN_WIDTH);
    textBox.setScale(0.1, 0.1);
    textBox.setFillColor(sf::Color::White);
    textBox.setFont(*font);
    isSelected = true;
    if(isSelected)
    {
        textBox.setString("_");
    }
    else
    {
        textBox.setString("");
    }
}


TextBox::TextBox(int size, sf::Color color, bool sel) {
    font->loadFromFile("../src/resources/SuperMario256.ttf"); //@todo put this to storage
    textBox.setCharacterSize(size);
    textBox.setFillColor(color);
    textBox.setFont(*font);
    isSelected = sel;
    if(sel)
    {
        textBox.setString("_");
    }
    else
    {
        textBox.setString("");
    }
}

void TextBox::inputLogic(int charTyped) {
    if(charTyped !=DELETE_KEY && charTyped!= ENTER_KEY && charTyped != ESCAPE_KEY)
    {
        text << static_cast<char>(charTyped);
    }
    else if(charTyped == DELETE_KEY)
    {
        if(text.str().length() >0)
        {
            deleteLastChar();
        }
    }
    textBox.setString(text.str() + "_");
}

void TextBox::deleteLastChar() {
    std::string strText = text.str();
    std::string newText = "";
    for(int i = 0; i<strText.length() -1; i++)
    {
        newText += strText[i];
    }
    text.str("");
    text << newText;

    textBox.setString(text.str());
}

void TextBox::setPosition(sf::Vector2f pos) {
    textBox.setPosition(pos);
}

void TextBox::setLimit(bool ToF) {
    hasLimit = ToF;
}

void TextBox::setLimit(bool ToF, int lim) {
    hasLimit = ToF;
    limit = lim;
}

void TextBox::setSelected(bool sel) {
    isSelected = sel;
    if(!sel)
    {
        std::string strText = text.str();
        std::string newText = "";
        for (int i = 0; i < strText.length() - 1; i++) {
            newText += strText[i];
        }
        textBox.setString(newText);
    }
}

std::string TextBox::getText() {
    return text.str();
}

void TextBox::draw(sf::RenderWindow &window) {
    window.draw(textBox);
}

void TextBox::typed(sf::Event input) {
    if(isSelected)
    {
        int charTyped = input.text.unicode;
        if(charTyped < 128)
        {
            if(hasLimit)
            {
                if(text.str().length()<=limit)
                {
                    inputLogic(charTyped);
                }
                else if(text.str().length() > limit && charTyped == DELETE_KEY)
                {
                    deleteLastChar();
                }
            }
            else
            {
                inputLogic(charTyped);
            }
        }
    }
}

/*TextBox TextBox::createTextBox() {
    return TextBox(15, sf::Color::White, true);
}*/
