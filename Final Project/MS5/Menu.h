/*****************************************************************************
Lib.h
Full Name : Lebna Noori
Student ID# : 157672205
Email : lnoori1@myseneca.ca
Date of completion : 18 July 2023

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments,  with using Fardad's Utils files and.*/

#ifndef MENU_H
#define MENU_H
namespace sdds {
    const unsigned int MAX_MENU_ITEMS = 20;

    class Menu;// declare this forward since it has full control over menuItem objects


    class MenuItem {



        char* m_menuContent;

        MenuItem();
        MenuItem(const char* menuInit);
        ~MenuItem();


        //ban copy assignment and copy constructor
        MenuItem(const MenuItem& copyConstructor) = delete;
        void operator=(const MenuItem& copyAssignment) = delete;
        //destructor
        operator const char* () const;
        operator bool() const;

        std::ostream& display(std::ostream& os = std::cout); // to call display later in the code


        friend class Menu;


    };
    class Menu {

        MenuItem m_menuTitle{};
        MenuItem* m_menuItems[MAX_MENU_ITEMS];
        unsigned int m_numItems = 0;
    public:

        Menu();
        ~Menu();
        Menu(const char* title);

        Menu(const Menu& M) = delete;
        void operator=(const Menu& M) = delete;


        std::ostream& displayTitle(std::ostream& os);
        std::ostream& displayMenu(std::ostream& os = std::cout);

        unsigned int run(); //use unsigned for validation

        int operator~();

        Menu& operator<<(const char* menuItemContent);

        operator int() const;
        operator unsigned int() const;
        operator bool() const;
        const char* operator[](unsigned int index) const; //mdulus

    };

    std::ostream& operator<<(std::ostream& os, Menu& menu);

}

#endif