#include <iostream>
#include <string>

#define MAX 10

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
    int idade;
    int codigocurso;
};

void mostrarMenu() {
    cout << "\n############################ MENU ############################\n";
    cout << "1 - Para Cadastrar Curso\n";
    cout << "2 - Para Cadastrar Aluno\n";
    cout << "3 - Para Mostrar Cursos Cadastrados\n";
    cout << "4 - Para Mostrar Alunos Cadastrados\n";
    cout << "5 - Para Buscar Alunos por Curso\n";
    cout << "6 - Para Exibir Relatorio Geral\n";
    cout << "7 - Para Sair\n";
    cout << "##############################################################\n";
    cout << "Digite sua opcao: ";
}

bool cadastrarCurso(Curso vet[], int i) {
    int codigo;

    cout << "\n--- Cadastro de Curso ---\n";
    cout << "Digite o codigo: ";
    cin >> codigo;

    for (int j = 0; j < i; j++) {
        if (vet[j].codigo == codigo) {
            cout << "Esse codigo ja esta cadastrado.\n";
            return false;
        }
    }

    vet[i].codigo = codigo;
    cin.ignore();

    cout << "Digite o nome: ";
    getline(cin, vet[i].nome);

    cout << "Digite a carga horaria do curso: ";
    cin >> vet[i].cargahoraria;

    cout << "Digite a quantidade de vagas: ";
    cin >> vet[i].qtvagas;

    if (vet[i].cargahoraria <= 0 || vet[i].qtvagas <= 0) {
        cout << "Carga horaria e vagas devem ser maiores que zero.\n";
        return false;
    }

    cout << "Curso cadastrado com sucesso!\n";
    return true;
}

bool cadastrarAluno(Aluno vetAlunos[], int i,
                    Curso vetCursos[], int qtdCursos) {
    int matricula, codigoCurso;
    int posicaoCurso = -1;
    int matriculados = 0;

    cout << "\n--- Cadastro de Aluno ---\n";
    cout << "Digite a matricula: ";
    cin >> matricula;

    for (int j = 0; j < i; j++) {
        if (vetAlunos[j].matricula == matricula) {
            cout << "Essa matricula ja esta cadastrada.\n";
            return false;
        }
    }

    cin.ignore();

    cout << "Digite o nome completo: ";
    getline(cin, vetAlunos[i].nomecompleto);

    cout << "Digite a idade: ";
    cin >> vetAlunos[i].idade;

    if (vetAlunos[i].idade <= 0) {
        cout << "Idade invalida.\n";
        return false;
    }

    cout << "Digite o codigo do curso: ";
    cin >> codigoCurso;

    for (int j = 0; j < qtdCursos; j++) {
        if (vetCursos[j].codigo == codigoCurso) {
            posicaoCurso = j;
            break;
        }
    }

    if (posicaoCurso == -1) {
        cout << "Curso nao encontrado. Aluno nao cadastrado.\n";
        return false;
    }

    for (int j = 0; j < i; j++) {
        if (vetAlunos[j].codigocurso == codigoCurso) {
            matriculados++;
        }
    }

    if (matriculados >= vetCursos[posicaoCurso].qtvagas) {
        cout << "Nao ha vagas disponiveis nesse curso.\n";
        return false;
    }

    vetAlunos[i].matricula = matricula;
    vetAlunos[i].codigocurso = codigoCurso;

    cout << "Aluno cadastrado com sucesso!\n";
    return true;
}

void listarCursos(Curso vet[], int n) {
    cout << "\n=== Cursos Cadastrados ===\n";

    if (n == 0) cout << "Nenhum curso cadastrado.\n";

    for (int i = 0; i < n; i++) {
        cout << "---------------------------------\n";
        cout << "Codigo: " << vet[i].codigo << endl;
        cout << "Nome: " << vet[i].nome << endl;
        cout << "Carga horaria: " << vet[i].cargahoraria << " horas\n";
        cout << "Quantidade de vagas: " << vet[i].qtvagas << endl;
    }

    cout << "---------------------------------\n";
}

string obterNomeCurso(Curso vetCursos[], int qtdCursos, int codigoBusca) {
    for (int i = 0; i < qtdCursos; i++) {
        if (vetCursos[i].codigo == codigoBusca) {
            return vetCursos[i].nome;
        }
    }

    return "Curso nao encontrado";
}

void listarAlunos(Aluno vetAlunos[], int n,
                  Curso vetCursos[], int qtdCursos) {
    cout << "\n=== Alunos Cadastrados ===\n";

    for (int i = 0; i < n; i++) {
        cout << "---------------------------------\n";
        cout << "Matricula: " << vetAlunos[i].matricula << endl;
        cout << "Nome: " << vetAlunos[i].nomecompleto << endl;
        cout << "Idade: " << vetAlunos[i].idade << endl;
        cout << "Curso: "
             << obterNomeCurso(vetCursos, qtdCursos, vetAlunos[i].codigocurso)
             << endl;
    }

    if (n == 0) {
        cout << "Nenhum aluno cadastrado.\n";
    }

    cout << "---------------------------------\n";
}

void buscarAlunosPorCurso(Aluno vetAlunos[], int qtdAlunos,
                          Curso vetCursos[], int qtdCursos) {
    int codigo;
    bool encontrou = false;

    cout << "\nDigite o codigo do curso: ";
    cin >> codigo;

    string nomeCurso = obterNomeCurso(vetCursos, qtdCursos, codigo);

    if (nomeCurso == "Curso nao encontrado") {
        cout << "Curso nao encontrado.\n";
        return;
    }

    cout << "\n=== Alunos do curso: " << nomeCurso << " ===\n";

    for (int i = 0; i < qtdAlunos; i++) {
        if (vetAlunos[i].codigocurso == codigo) {
            cout << "---------------------------------\n";
            cout << "Matricula: " << vetAlunos[i].matricula << endl;
            cout << "Nome: " << vetAlunos[i].nomecompleto << endl;
            cout << "Idade: " << vetAlunos[i].idade << endl;
            encontrou = true;
        }
    }

    if (!encontrou) {
        cout << "Nao ha alunos matriculados nesse curso.\n";
    }

    cout << "---------------------------------\n";
}

void relatorioGeral(Aluno vetAlunos[], int qtdAlunos,
                    Curso vetCursos[], int qtdCursos) {
    cout << "\n=== Relatorio Geral ===\n";

    if (qtdCursos == 0) {
        cout << "Nenhum curso cadastrado.\n";
    }

    for (int i = 0; i < qtdCursos; i++) {
        int quantidade = 0;

        for (int j = 0; j < qtdAlunos; j++) {
            if (vetAlunos[j].codigocurso == vetCursos[i].codigo) {
                quantidade++;
            }
        }

        cout << "---------------------------------\n";
        cout << "Curso: " << vetCursos[i].nome << endl;
        cout << "Codigo: " << vetCursos[i].codigo << endl;
        cout << "Alunos matriculados: " << quantidade << endl;
        cout << "Quantidade de vagas: " << vetCursos[i].qtvagas << endl;
        cout << "Vagas restantes: " << vetCursos[i].qtvagas - quantidade << endl;
    }

    cout << "---------------------------------\n";
}

int main() {
    Curso listaCursos[MAX];
    Aluno listaAlunos[MAX];

    int contCursos = 0;
    int contAlunos = 0;
    int opcao;

    while (true) {
        mostrarMenu();
        cin >> opcao;

        if (opcao == 7) {
            cout << "Saindo do sistema...\n";
            break;
        }

        switch (opcao) {
        case 1:
            if (contCursos < MAX) {
                if (cadastrarCurso(listaCursos, contCursos)) {
                    contCursos++;
                }
            } else {
                cout << "Limite de cursos atingido.\n";
            }
            break;

        case 2:
            if (contAlunos < MAX) {
                if (cadastrarAluno(listaAlunos, contAlunos,
                                   listaCursos, contCursos)) {
                    contAlunos++;
                }
            } else {
                cout << "Limite de alunos atingido.\n";
            }
            break;

        case 3:
            listarCursos(listaCursos, contCursos);
            break;

        case 4:
            listarAlunos(listaAlunos, contAlunos,
                         listaCursos, contCursos);
            break;

        case 5:
            buscarAlunosPorCurso(listaAlunos, contAlunos,
                                 listaCursos, contCursos);
            break;

        case 6:
            relatorioGeral(listaAlunos, contAlunos,
                           listaCursos, contCursos);
            break;

        default:
            cout << "Opcao invalida. Digite novamente.\n";
            break;
        }
    }

    return 0;
}
