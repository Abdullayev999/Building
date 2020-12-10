#include <iostream>
#include<string.h>
#include <iomanip>

/* ДОМАШНЕЕ ЗАДАНИЕ:
        1. Создайте класс Building (здание) у которого должны быть следующие поля:
            + поле в котором хранится количество этажей в здании
            + поле по которому определяется есть ли в здании лифт
        2. В классе Building должны быть следующие конструкторы:
            + конструктор по умолчанию
            + конструктор через который можно инициализировать все поля
            + конструктор через который можно установить только количество этажей
            + конструктор через который можно установить только значение поля
            которое определяет есть ли лифт в здании
        3. Реализуйте метод print который печатает всю информацию о здании*/

class Building
{
public:

    Building() {
        ++count;
        strcpy_s(m_name, "No_Name");
        m_numberFloors = 1;
        m_lift = false;

    };

    ~Building() {
        --count;
    }

    Building(const char* name) :Building() {
        strcpy_s(m_name, name);
    };

    Building(const int numberFloor) :Building() {
        m_numberFloors = numberFloor;
    };

    Building(const char* name, const int numberFloor, bool lift) {
        ++count;
        m_numberFloors = numberFloor;
        strcpy_s(m_name, name);

        if (lift) {
            m_lift = checkFloorForLift(numberFloor);
        }
    };

    void print() {
        std::cout << "\nBuild\n-----------------------\nname\t=\t" << m_name << "\nfloors\t=\t" << m_numberFloors << '\n';
        std::cout << "lift\t=\t" << std::boolalpha << m_lift << '\n';
        std::cout << "\n=======================\n\n";
    }

    void setFloor(const int numberFloor) {
        std::cout << "<< " << getName() << " >> build is changed on " << numberFloor << " - floors\n";
        m_numberFloors = numberFloor;

        if (m_lift) {
            m_lift = checkFloorForLift(numberFloor);
        }
    }

    void setName(const char* name) {
        std::cout << "The building was named :<<\n";
        strcpy_s(m_name, name);
    }

    void setLift(const bool lift) {
        if (lift && (!m_lift)) {
            m_lift = checkFloorForLift(m_numberFloors);
        }
        else if ((!lift) && m_lift) {
            std::cout << "Lift deleted in << " << getName() << " >>  build\n";
            m_lift = false;
        }
    }

    char* getName() {
        return m_name;
    }

    bool getLift() {
        return m_lift;
    }

    int getFloor() {
        return m_numberFloors;
    }

    static int getCount() {
        return count;
    }

private:
    static int count;
    char m_name[20];
    unsigned int m_numberFloors;
    bool m_lift;
    const int MAX_FLOOR = 5;

    bool checkFloorForLift(const int numberFloor) {
        if (numberFloor >= MAX_FLOOR) {
            std::cout << "Lift installed in << " << getName() << " >>  build\n";
            return true;
        }
        else {
            std::cout << "Few floors for elevator\n";
            return false;
        }
    }
};

int Building::count = 0;

int main()
{
    int floor;
    int lift;
    char name[20];

    std::cout << "Enter name \n";
    std::cin >> name;

    std::cout << "Enter quantity floor\n";
    std::cin >> floor;

    do
    {
        std::cout << "Enter lift YES(1) NOT(0)\n";
        std::cin >> lift;
        if (lift == 1 || lift == 0)
        {
            break;
        }
        else
        {
            std::cout << "wrong select , try again\n";
        }

    } while (true);

    Building build(name, floor, lift);
    build.print();
    build.setFloor(4);
    build.print();
    build.setLift(true);
    build.print();
    build.setLift(false);
    build.print();

    std::cout << "\nQuantity Buildings = " << Building::getCount() << '\n';

}

