///#############################################################################################
///###                   Program tworzacy stos                                               ###
///###                   Bartosz Gebura                                                      ###
///#############################################################################################

#include <iostream>

using namespace std;

struct Stack_{ /// struktura Stack_
    int value; /// zmienna do wpisania wartosci do stosu
    Stack_ * prev = nullptr; /// zerowany wskaznik na wczesniejszy element
};

Stack_ * top = nullptr; /// wskaznik na element wyzej, globalny, aby uzyc w main do wyswietlania

void push_stack(int value) /// dodanie elementu na szczyt stosu
{
    Stack_ * _new = new Stack_; /// rezerwowanie na stercie pamieci o wielkosci struktury Stack_
    _new->value = value; /// dopisanie nowej wartosci
    _new->prev = top; /// ustawiamy wskaznik top wczesniejszego elementu jako prev nowego elementu
    top = _new; /// wskaznik top teraz wskazuje na nowy element (szczyt stosu)
}

int pop_stack() /// zdejmowanie elementu ze stosu
{
    int stack_top_value = top->value; /// do zmiennej stack_top_value wpisujemy aktualna wartosc ze szczytu stosu, aby wiedziec co zdejmujemy
    Stack_ * temporary = top; /// tworzymy wskaznik tymczasowy, bo za chwile przepiszemy i stracimy top
    top = top->prev; /// przesuwamy na nastepny element stosu, tracimy dostep do top
    delete(temporary); /// zwalniamy obszar wskazywany przez temporary
    return stack_top_value; /// zwracamy stack_top_value, aby wyswietlic
}

int main()
{
    push_stack(1);
    push_stack(2);
    push_stack(3);
    push_stack(4);
    push_stack(5);
    while(top) /// dopoki wskaznik top nie bedzie null
        cout << pop_stack() << endl; /// wypisywanie zawartosc i zdejmujemy ze stosu
    return 0;
}
