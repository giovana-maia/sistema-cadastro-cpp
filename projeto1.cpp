#include <iostream>
#include <string>

#define MAX 5

using namespace std;

struct Curso {
    int codigo;
    string nome;
    int cargahoraria;
    int qtvagas;
};



struct Aluno {
    int matricula;
    string nomecompleto;
    string telefone;
    int idade;
};


void mostrarMenu() {
    cout << "\n############################ MENU ############################\n";
    cout << "1 - Para Cadastrar Curso\n";
    cout << "2 - Para Cadastrar Aluno\n";
    cout << "3 - Para Mostrar Cursos Cadastrados\n";
    cout << "4 - Para Mostrar Matricula dos Alunos Cadastrados\n";
    cout << "5 - Buscar por aluno \n";
    cout << "6 - Exibir relatorio \n";
    cout << "7 - Para Sair\n";
    cout << "##############################################################\n";
    cout << "Digite sua opcao: ";
}


void cadastrarCurso(Curso vet[], int i) {
    cout << "\n--- Cadastro de Curso ---\n";

    cout << "Digite o codigo: ";
    cin >> vet[i].codigo;

    cin.ignore();

    cout << "Digite o nome: ";
    getline(cin, vet[i].nome);

    cout << "Digite a carga horaria do curso: ";
    cin >> vet[i].cargahoraria;

    cout << "Digite a quantidade de vagas: ";
    cin >> vet[i].qtvagas;

}

void cadastrarAluno(Aluno vet[], int i) {

    cout << "\n--- Cadastro de Aluno ---\n";







}



