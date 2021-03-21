#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using std::string;
using std::cout;
using std::cin;
using std::endl;


enum Theme {
    Physics,
    Prog,

    LASTTHEME
};

class Area {
public:
    string name;
    Question* question;


    Area(const string theme) {
        std::srand(std::time(nullptr));
        Theme rand_theme = static_cast<Theme>(rand() % LASTTHEME);

        switch (rand_theme) {
        case Physics:
            question = new PhysicsQuestion();
            break;
        case Prog:
            question = new ProgrammingQuestion();
            break;
        }
    }
};

class Question {
public:
    string question_body;
    int question_ans;
    
    virtual void set_question();
    bool get_question() {
        cout << question_body << endl;
        cout << "Выбери 1/2/3/4: ";
        
        while (true) {
            string choose;
            cin >> choose;
            try {
                return (std::stoi(choose) == question_ans);
            } catch (const std::invalid_argument& e) {
                cout << "ВВЕДИ ЦИФРУ\n"; 
            }
        }
    }
};



class PhysicsQuestion: public Question {
public:

    virtual void set_question() override {
        question_body = "Сколько эргов в 1 Джоуле?\n10^3\n10^5\n10^7";
        question_ans = 3;
    }
};

class ProgrammingQuestion: public Question {
public:
	
    virtual void set_question() override {
        question_body = "Как тебе эта программа?\nОна совершенна\nЛучше не видел\nИграю весь день\n";
        question_ans = 2;
    }
};


//USEFUL DATA
/*
class Math : virtual public Area {
    int set_question() {
        std::cout << "Сколько сторон в треугольника?" << "\n";
        std::cout << "1" << "\n";
        std::cout << "1" << "\n";
        std::cout << "3" << "\n";
        std::cout << "5" << "\n";
        std::cout << "Выбери -- 1, 2, 3 или 4" << "\n";
        return 3;
    }
};


class English : virtual public Area {
    int set_question() {
        std::cout << "С какой буквы пишется я в английском?" << "\n";
        std::cout << "С большой" << "\n";
        std::cout << "С маленькой" << "\n";
        std::cout << "С прописной" << "\n";
        std::cout << "Со строчной" << "\n";
        std::cout << "Выбери -- 1, 2, 3 или 4" << "\n";
        return 1;
    }
};


class Programming : virtual public Area {
    int set_question() {
        std::cout << "Нравится эта игра?" << "\n";
        std::cout << "Да, это  лучшее, что я видел" << "\n";
        std::cout << "Это прекрасно" << "\n";
        std::cout << "Играю весь день" << "\n";
        std::cout << "Конечно" << "\n";
        std::cout << "Выбери -- 1, 2, 3 или 4" << "\n";
        return 4;
    }
};


class Literature : virtual public Area {
    int set_question() {
        std::cout << "Какое отчество у Довлатова?" << "\n";
        std::cout << "Сергеевич" << "\n";
        std::cout << "Донатович" << "\n";
        std::cout << "Львович" << "\n";
        std::cout << "Клементьевич" << "\n";
        std::cout << "Выбери -- 1, 2, 3 или 4" << "\n";
        return 2;
    }
};


class Art : virtual public Area {
    int set_question() {
        std::cout << "Кто придумал лого чупа чупса?" << "\n";
        std::cout << "Пикассо" << "\n";
        std::cout << "Пикасо" << "\n";
        std::cout << "Дали" << "\n";
        std::cout << "Взяли" << "\n";
        std::cout << "Выбери -- 1, 2, 3 или 4" << "\n";
        return 3;
    }
};


class News : virtual public Area {
    int set_question() {
        std::cout << "Какая лучшая вакцина от ковида?" << "\n";
        std::cout << "Файзер5" << "\n";
        std::cout << "СпутникВи" << "\n";
        std::cout << "Эпивак" << "\n";
        std::cout << "БиоЭнТеч" << "\n";
        std::cout << "Выбери -- 1, 2, 3 или 4" << "\n";
        return 2;
    }
};
*/

