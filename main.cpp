#include "Pizza.h"
#include "PizzaMargherita.h"
#include "Cheesy.h"
#include "Dracula.h"

int main() {
    short option;
    do {
        std::cout << "MENU\n";
        std::cout << "1. Tipuri de pizza\n";
        std::cout << "2. Comanda pizza\n";
        std::cout << "3. Exit\n";
        std::cin >> option;
        switch (option) {
            case 1 : {
                std::cout << "1.Pizza Margherita\n2.Pizza Cheesy\n3.Pizza Dracula\n";
                break;
            }
            case 2 : {
                std::cout << "Introduceti numarul de pizza dorite: ";
                int n;
                std::cin >> n;
                // crearea unui tablou care va putea face referire la mai multe tipuri de Pizza
                Pizza ** pizzas = new Pizza*[n];
                for (int i = 0; i < n; ++i) {
                    short choice1;
                    do {
                        std::cout << "1.Pizza Margherita\n2.Pizza Cheesy\n3.Pizza Dracula\n";
                        std::cin >> choice1;
                        int dimensiune, blat;
                        short choice2;
                        do {
                            std::cout << "Selectati dimensiunea: \n";
                            std::cout << "1. Medie\n2. Mare\n";
                            std::cin >> choice2;
                            switch (choice2) {
                                case 1: {
                                    dimensiune = 30;
                                    break;
                                }
                                case 2: {
                                    dimensiune = 50;
                                    break;
                                }
                                default: {
                                    std::cout << "Optiune invalida!\n";
                                }
                            }
                        } while (choice2 != 1 && choice2 != 2);

                        do {
                            std::cout << "Selectati blatul: \n";
                            std::cout << "1. Subtire\n2. Pufos\n";
                            std::cin >> choice2;
                            switch (choice2) {
                                case 1: {
                                    blat = 2;
                                    break;
                                }
                                case 2: {
                                    blat = 3;
                                    break;
                                }
                                default: {
                                    std::cout << "Optiune invalida!\n";
                                }
                            }
                        } while (choice2 != 1 && choice2 != 2);

                        switch (choice1) {
                            case 1: {
                                pizzas[i] = new PizzaMargherita(dimensiune, blat);
                                break;
                            }
                            case 2: {
                                pizzas[i] = new Cheesy(dimensiune, blat);
                                break;
                            }
                            case 3: {
                                pizzas[i] = new Dracula(dimensiune, blat);
                                break;
                            }
                            default: {
                                std::cout <<"Optiune invalida\n";
                            }
                        }
                    } while (choice1 != 1 && choice1 != 2 && choice1 != 3);
                }

                double total = 0;
                std::cout << "Total comanda: ";

                // Aceasta nu este o metoda corecta de a calcula totalul.
                // Este utila pentru a ilustra procedeul de downcasting
                for (int i = 0; i < n; ++i) {
                    PizzaMargherita * margherita = dynamic_cast<PizzaMargherita*>(pizzas[i]);
                    if (margherita) {
                        std::cout << "Pizza " << i << " este Pizza Margherita.\n";
                        total += margherita->getPret();
                        continue;
                    }

                    Cheesy * cheesy = dynamic_cast<Cheesy*>(pizzas[i]);
                    if (cheesy) {
                        std::cout << "Pizza " << i << " este Pizza Cheesy.\n";
                        total += cheesy->getPret();
                        continue;
                    }

                    Dracula * dracula = dynamic_cast<Dracula*>(pizzas[i]);
                    if (dracula) {
                        std::cout << "Pizza " << i << " este Pizza Dracula.\n";
                        total += dracula->getPret();
                        continue;
                    }
                }

                std::cout << "Totalul este " << total << '\n';

                total = 0;
                // Totusi avantajul utilizarii functiilor care sunt declarate ca si virtual
                // este acela ca nu mai este nevoie sa facem downcasting in mod explicit la
                // clasa derivata ci putem folosi exact metoda din clasa de baza care cu
                // ajutorul unui virtual pointer (vptr) va face referire chiar la metoda
                // din clasa derivata.

                for (int i = 0; i < n; ++i) {
                    total += pizzas[i]->getPret();
                }

                std::cout << "Totalul este " << total << '\n';
                // Dupa cum puteti observa rezultatul este acelasi cu cel anterior

                // Eliberam memoria alocata anterior
                for (int i = 0; i < n; ++i) {
                    delete pizzas[i];
                }

                delete[] pizzas;
            }
            case 3: {
                break;
            }
            default: {
                std::cout << "Optiune invalida!\n";
            }
        }
    } while (option != 3);
    return 0;
}