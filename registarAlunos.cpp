#include <iostream>
#include <string>
#include <vector>
#include <iomanip>  // Necessário para setprecision

using namespace std;

class Aluno {
private:
    string nome;
    int idade;
    double notaPort;
    double notaMat;
    double notaInfo;

public:
    // Método para registar um novo aluno
    void registarAluno() {
        cout << "Nome do Aluno: ";
        getline(cin, nome);
        
        cout << "Idade: ";
        cin >> idade;

        cout << "Nota Portugues: ";
        cin >> notaPort;

        cout << "Nota Matematica: ";
        cin >> notaMat;

        cout << "Nota Informatica: ";
        cin >> notaInfo;
        cin.ignore();
    }

    // Método para obter o nome do aluno
    string getNome() const {
        return nome;
    }

    // Método para obter a idade do aluno
    int getIdade() const {
        return idade;
    }

    // Método para calcular a nota final do aluno
    double calcularNotaFinal() const {
        return (notaPort + notaMat + notaInfo) / 3.0;
    }
};

// Função para calcular a média da turma
double calcularMediaTurma(const vector<Aluno>& alunos) {
    double soma = 0.0;
    for (const Aluno& aluno : alunos) {
        soma += aluno.calcularNotaFinal();
    }
    double media = soma / (alunos.size());
    return media;
}

// Função para listar todos os alunos
void listarAlunos(const vector<Aluno>& alunos) { // Passar por referencia 
    for (const Aluno& aluno : alunos) { // Percorre o vetor de alunos passado por referência
        cout << "Nome: " << aluno.getNome() << " | Idade: " << aluno.getIdade() << " | Nota Final: " << aluno.calcularNotaFinal()<< "\n" << endl;
    }
}

// Função para pesquisar um aluno pelo nome
void pesquisarAluno(const vector<Aluno>& alunos, string pnome) {
    bool encontrado = false; // Variável para verificar se o aluno foi encontrado
    for (const Aluno& aluno : alunos) {
        if (aluno.getNome().find(pnome) != string::npos) { // Verifica se o nome do aluno contém a string de pesquisa
            cout << "Nome: " << aluno.getNome() << " | Idade: " << aluno.getIdade() << " | Nota Final: " << aluno.calcularNotaFinal() << "\n" << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "Aluno nao encontrado.\n" << endl;
    }
}

int main() {

    vector<Aluno> alunos;

    int opcao;
    string nome;

    do {
        std::cout << "                  ." << std::endl;
        std::cout << "                 /_\\ " << std::endl;
        std::cout << "                 |Q|" << std::endl;
        std::cout << "           .-----' '-----." << std::endl;
        std::cout << "          /____[SCHOOL]___\\" << std::endl;
        std::cout << "           | [] .-.-. [] |" << std::endl;
        cout << "-------------------------------------" << endl;
        cout << "|        ------ Menu ------         |" << endl;
        cout << "|  1. Registar novo aluno;          |" << endl;
        cout << "|  2. Calcular media da turma;      |" << endl;
        cout << "|  3. Listar todos os alunos;       |" << endl;
        cout << "|  4. Pesquisar pelo nome do aluno; |" << endl;
        cout << "|  5. Sair.                         |" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Escolha uma opcao: ";

        // Leitura da opção do utilizador
        cin >> opcao;
        cin.ignore();

        // Switch para lidar com as opções do menu
        switch (opcao) {
            case 1:
                {
                    // Registar um novo aluno
                    Aluno novoAluno;
                    novoAluno.registarAluno();
                    alunos.push_back(novoAluno); // adicionar um novo elemento ao final do vetor
                    cout << "Aluno registado com sucesso.\n" << endl;
                }
                break;
            case 2:
                {
                    // Calcular e mostrar a média da turma
                    if (alunos.empty()) {
                        cout << "Nao ha alunos registados.\n" << endl;
                    } else {
                        double media = calcularMediaTurma(alunos);
                        cout << "Media da turma: \n"  << fixed << setprecision(2) << media << endl;
                    }
                }
                break;
            case 3:
                {
                    // Listar todos os alunos
                    if (alunos.empty()) {
                        cout << "Nao ha alunos registados.\n" << endl;
                    } else {
                        listarAlunos(alunos);
                    }
                }
                break;
            case 4:
                {
                    // Pesquisar alunos pelo nome
                    if (alunos.empty()) {
                        cout << "Nao ha alunos registados.\n" << endl;
                    } else {
                        cout << "Digite o nome do aluno a pesquisar: ";
                        cin >> nome;
                        pesquisarAluno(alunos, nome); 
                        break;
                    }
                break;
                }
            case 5:
                cout << "Programa encerrado.\n" << endl;
                break;
            default:
                cout << "Opcao invalida. Tente novamente.\n" << endl;
        }

    } while (opcao != 5);

    return 0;
}
