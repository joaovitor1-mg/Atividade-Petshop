#include "include/listapets.h"

pet **pet::inserir(pet **p, string n, string r, int i, int t) {
    pet *novo = new pet();
    novo->nome = n;
    novo->raca = r;
    novo->tipo = t;
    novo->idade = i;
    novo->prox = NULL;
    novo->ant = NULL;

    if (p[0] == NULL) {
        p[0] = novo;
        p[1] = novo;
        return p;
    }

    pet *aux;
    if (novo->tipo == 1) {
        aux = p[0];
        while ((aux != NULL) && (novo->nome > aux->nome) && (aux->tipo == 1))
            aux = aux->prox;
    } else {
        aux = p[1];
        while ((aux != NULL) && (novo->nome > aux->nome) && (aux->tipo == 2))
            aux = aux->ant;
    }

    if (aux == NULL && novo->tipo == 1) {
        p[1]->prox = novo;
        novo->ant = p[1];
        p[1] = novo;
    } else if (aux == NULL && novo->tipo == 2) {
        novo->prox = p[0];
        p[0]->ant = novo;
        p[0] = novo;
    } else if (novo->tipo == 1) {
        novo->prox = aux;
        novo->ant = aux->ant;
        if (aux->ant != NULL) {
            aux->ant->prox = novo;
        } else {
            p[0] = novo;
        }
        aux->ant = novo;
    } else {
        novo->prox = aux->prox;
        novo->ant = aux;

        if (aux->prox != NULL)
            aux->prox->ant = novo;
        else
            p[1] = novo;

        aux->prox = novo;
    }

    return p;
}

pet **pet::excluir(pet **p, string n, int t) {
    pet *aux;
    if (t == 1) {
        aux = p[0];
        while (aux->nome != n) {
            aux = aux->prox;
        }
    } else {
        aux = p[1];
        while (aux->nome != n) {
            aux = aux->ant;
        }
    }
    if (aux == p[0]) {
        p[0] = p[0]->prox;
        p[0]->ant = NULL;
    } else if (aux == p[1]) {
        p[1] = p[1]->ant;
        p[1]->prox = NULL;
    } else {
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
        delete (aux);
    };
    return p;
}

void pet::listar(pet **p, int op) {
    pet *aux;
    if (op == 0) {
        aux = p[0];
        while (aux != NULL) {
            cout << aux->nome << " (" << (aux->tipo == 1 ? "Cachorro" : "Gato") << ")" << endl;
            aux = aux->prox;
        }
    } else if (op == 1) {
        aux = p[0];
        while (aux != NULL && aux->tipo == 1) {
            cout << aux->nome << " (Cachorro)" << endl;
            aux = aux->prox;
        }
    } else {
        aux = p[1];
        while (aux != NULL && aux->tipo == 2) {
            cout << aux->nome << " (Gato)" << endl;
            aux = aux->ant;
        }
    }
}

bool pet::pesquisar(pet **p, string n, int t) {
    pet *aux;
    if (t == 1) {
        aux = p[0];
        while (aux != NULL && aux->nome != n && aux->tipo == 1) {
            aux = aux->prox;
        }
    } else {
        aux = p[1];
        while (aux != NULL && aux->nome != n && aux->tipo == 2) {
            aux = aux->ant;
        }
    }
    if ((aux == NULL) || (aux != NULL && aux->tipo != t)) {
        return false;
    }
    return true;
}

void Menu() {
    cout << "\n===== MENU PETSHOP =====" << endl;
    cout << "1. Cadastrar pet" << endl;
    cout << "2. Excluir pet" << endl;
    cout << "3. Listagem geral" << endl;
    cout << "4. Listagem de caes" << endl;
    cout << "5. Listagem de gatos" << endl;
    cout << "6. Pesquisar pet" << endl;
    cout << "7. Finalizar programa" << endl;
    cout << "Escolha uma opcao: ";
}
