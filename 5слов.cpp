#include <iostream>
#include <windows.h>
#include <string.h>
#include <random>
#include <locale>
#include <ctime>   // Для генерации случайного seed


void printCenteredMessage(const std::string& message) 
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    int len = static_cast<int>(message.length());
    int pos = (columns - len) / 2;

    for (int i = 0; i < pos; i++) 
    {
        std::cout << " ";
    }

    std::cout << message << std::endl;
}


int main()
{
    /*setlocale(LC_ALL, "RU");*/

    HWND console = GetConsoleWindow();
    RECT rect;
    GetWindowRect(console, &rect);

    MoveWindow(console, rect.left, rect.top, 400, 600, TRUE);

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    /*printCenteredMessage("Привет, давай сыграем в 5 слов?");*/
    printCenteredMessage("Hi, do you want to play 5 words?");

    std::cout << std::endl;
    /*std::cout << "Правила просты. Тебе дается 5 попыток на то, что б угадать загаданное слово. Если в       введеннном тобою слове верна одна или        несколько букв на верной позиции, то они     отобразятся в таблице." << std::endl;*/
    std::cout << "Rules are simple. You have 5 attempts to guess the word. If the word you entered is valid and in the correct position, the letters will be displayed in the table." << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    
    //std::string words[] = { "трава", "сумка", "брюки", "покой", "новый", "драка", "цветы", "дверь", "кухня", "плата", "никто", "блуза", "слива", "ведро", "щетка", "зебра", "манеж", "горох", "рынок", "пирог", "кусок", "заказ", "тонна", "корка", "горка", "вирус", "хумус", "уксус", "забор", "алмаз", "топаз", "круиз" };
    std::string words[] = { "grass", "glass", "mouth", "honor", "medal", "santa", "cover", "train", "world", "plate", "thief", "dress", "fruit", "river", "wheel", "zebra", "manor", "grave", "stock", "dough", "slice", "order", "tonne", "phone", "globe", "virus", "humus", "sugar", "board", "crown", "brear", "music"};

    int i = 0;

    std::string placeholderArray[] = { "*", "*", "*", "*", "*" };

    std::string word; 
  

    std::cout << std::endl;

    int arraySize = sizeof(words) / sizeof(words[0]);

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> distribution(1, 32);

    int random_number = distribution(gen);

    int u = 0;

    std::cout << std::endl;

    for (int i = 0; i < 6; i++)
    {
        //std::cout << "Введите слово: ";
        std::cout << "Enter the word: ";
        std::cin >> word;

        std::locale loc;
        
        for (int i = 0; i < std::size(word); i++)
        {
            word[i] = std::tolower(word[i], loc);
        }

        std::string random_word = words[random_number];

        /*std::cout << random_word << std::endl;*/

        if (word == random_word)
        {
            std::cout << std::endl;
            /*printCenteredMessage("Поздравляю! Вы выиграли!");*/
            printCenteredMessage("Congratulation! You win!");
            std::cout << std::endl;
            i = 6;
            system("pause");            
        }
        else if (int wordLength = word.length() > 5)
        {
            /*std::cout << "Слишком длинное слово" << std::endl;*/
            std::cout << "Your word is too long" << std::endl;
        }
        else if (int wordLength = word.length() < 5)
        {
            /*std::cout << "Слишком короткое слово" << std::endl;*/
            std::cout << "Your word is too short" << std::endl;
        }
        else
        {
            for (int i = 0; i < 5; i++)
            {
                if (word[i] == random_word[i])
                {
                    placeholderArray[i] = word[i];
                }
            }

            std::cout << std::endl;
            /*std::cout << "Массив после замены: ";*/
            std::cout << "Answer: " << std::endl;
            for (int i = 0; i < std::size(placeholderArray); i++)
            {
                std::cout << placeholderArray[i] << " ";

            }
        }

        std::cout << std::endl;

        if (i == 5)
        {
            std::cout << std::endl;
            /*printCenteredMessage("К сожалению вы проиграли");*/
            printCenteredMessage("You lose!");
        }
    }
}

