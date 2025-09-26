#include "include/listapets.h"


int main() {
    pet O, **L;
    L = new pet *[2];
    L[0] = L[1] = NULL;

    string nome, raca;
    int idade, tipo, op;

    //pets iniciais

L = O.inserir(L, "Thor", "Labrador", 1, 1);
L = O.inserir(L, "Nina", "Poodle", 7, 1);
L = O.inserir(L, "Bob", "Golden Retriever", 6, 1);

L = O.inserir(L, "Chloe", "Angorá", 5, 2);
L = O.inserir(L, "Tom", "Sphynx", 3, 2);
L = O.inserir(L, "Salem", "Bombay", 8, 2);

    do {
        Menu();
        cin >> op;
        switch (op) {
        case 1:
            cout << "Informe o nome, raça, idade e tipo (1=caes, 2=gatos): ";
            cin >> nome >> raca >> idade >> tipo;
            L = O.inserir(L, nome, raca, idade, tipo);
            cout << "Pet cadastrado com sucesso!" << endl;
            break;

        case 2:
            if (L[0] == NULL) {
                cout << "Sem registros!" << endl;
            } else {
                cout << "Informe o nome e o tipo (1=caes, 2=gatos): ";
                cin >> nome >> tipo;
                if (O.pesquisar(L, nome, tipo)) {
                    L = O.excluir(L, nome, tipo);
                    cout << "Cadastro de pet excluido!" << endl;
                } else {
                    cout << "Nao existe esse pet!" << endl;
                }
            }
            break;

        case 3:
            if (L[0] == NULL) cout << "Sem registros!" << endl;
            else {
                cout << "\n--- Lista completa ---" << endl;
                O.listar(L, 0);
            }
            break;

        case 4:
            if (L[0] == NULL) cout << "Sem registros!" << endl;
            else {
                cout << "\n--- Lista de cachorros ---" << endl;
                O.listar(L, 1);
            }
            break;

        case 5:
            if (L[0] == NULL) cout << "Sem registros!" << endl;
            else {
                cout << "\n--- Lista de gatos ---" << endl;
                O.listar(L, 2);
            }
            break;

        case 6:
            if (L[0] == NULL) cout << "Sem registros!" << endl;
            else {
                cout << "Informe o nome e o tipo (1=caes, 2=gatos): ";
                cin >> nome >> tipo;
                if (O.pesquisar(L, nome, tipo))
                    cout << "Pet esta cadastrado!" << endl;
                else
                    cout << "Pet ainda nao cadastrado!" << endl;
            }
            break;

        case 7:
            cout << "Saindo..." << endl;
            break;

        default:
            cout << "Opcao invalida!" << endl;
            break;
        }
        cin.ignore().get();
    } while (op != 7);

    return 0;
}
