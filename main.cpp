#include <iostream>
#include <vector>

#include "square.h" 
#include "triangle.h"
#include "octagon.h"


void print_help() {
    std::cout << "'add square'            --> Create square" << std::endl;
    std::cout << "'add triangle'          --> Create triangle" << std::endl;
    std::cout << "'add octagon'           --> Create octagon" << std::endl;
    std::cout << "'show <ID>'             --> Output figure" << std::endl;
    std::cout << "'print total'           --> Output total area" << std::endl;
    std::cout << "'print area'            --> Output area" << std::endl;
    std::cout << "'print center'          --> Output center" << std::endl;
    std::cout << "'delete <ID>'           --> Delete figure" << std::endl;
    std::cout << "'help'                  --> Get help" << std::endl;
    std::cout << "'exit'                  --> Exit" << std::endl;
}                                           

void print_errors(int&& err) {
    switch (err) {
        case 1: {
            std::cout << "Incorrect command" << std::endl;
            break;
        }
        case 2: {
            std::cout << "Incorrect coordinates for a figure" << std::endl;
            break;
        }
        case 3: {
            std::cout << "There is no item with the given index" << std::endl;
            break;
        }
        default: {
            std::cout << "Undefined error" << std::endl;
        }
    }
    char c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

int main() {
    print_help();
    std::vector<Figure*> figs;

    char com1[40];
    char com2[40];

    Figure* fig = nullptr;

    while (true) {
        std::cin >> com1;

        if (strcmp(com1, "add") == 0) {
            std::cin >> com2;

            if (strcmp(com2, "square") == 0) {
                std::cout << "input A >> B >> C >> D";
                fig = new Square;
            }
            else if (strcmp(com2, "triangle") == 0) {
                std::cout << "input A >> B >> C";
                fig = new Triangle;
            }
            else if (strcmp(com2, "octagon") == 0) {
                std::cout << "input A >> B >> C >> D >> E >> F >> G >> H";
                fig = new Octagon;
            }
            else {
                print_errors(1);
            }
            fig->Scan(std::cin);
            figs.push_back(fig);
        }
        else if (strcmp(com1, "show") == 0) {
            int id;
            std::cin >> id;
            if (id >= figs.size()) {
                print_errors(3);
                continue;
            }
            figs[id]->Print(std::cout);
        }
        else if (strcmp(com1, "print") == 0) {
            std::cin >> com2;
            if (strcmp(com2, "total") == 0) {
                double total_area = 0;
                for (Figure* fig : figs) {
                    total_area += fig->Area();
                }
                std::cout << "Total area: " << total_area << std::endl;
            }
            else if (strcmp(com2, "area") == 0) {
                std::cout << "Display area: ";
                for (Figure* fig : figs) {
                    std::cout << fig->Area() << std::endl;
                }
            }
            else if (strcmp(com2, "center") == 0) {
                std::cout << "Display center: ";
                for (Figure* fig : figs) {
                    Point tmp = fig->Center();
                    std::cout << "( " << tmp.X() << ", " << tmp.Y() << " )" << std::endl;
                }
            }
            else {
                std::cout << "Incorrect command\n";
            }
        }
        else if (strcmp(com1, "delete") == 0) {
            int id;
            std::cin >> id;
            if (id >= figs.size()) {
                print_errors(3);
                continue;
            }
            delete figs[id];
            figs.erase(figs.begin() + id);
        }
        else if (strcmp(com1, "help") == 0) {
            print_help();
            continue;
        }
        else if (strcmp(com1, "exit") == 0) {
            break;
        }
        else {
            print_errors(1);
        }
    }

    delete[] com1;
    delete[] com2;
    delete fig;
    
    for (int i = 0; i < figs.size(); ++i) {
        delete figs[i];
    }
    return 0;
}