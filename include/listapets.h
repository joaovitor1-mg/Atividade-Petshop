#include <iostream>
using namespace std;

class pet {
public:
    string nome, raca;
    int tipo, idade;
    pet *ant, *prox;

    pet **inserir(pet **, string, string, int, int);
    pet **excluir(pet **, string, int);
    void listar(pet **, int);
    bool pesquisar(pet **, string, int);
};

void Menu();


