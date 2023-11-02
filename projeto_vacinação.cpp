#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

typedef struct vacina{
  string nome;
  string cpf;
  string data;
  int dose;
  char tipo;
  struct vacina * prox;
}Vacinacao;

typedef struct{
  vacina * ponteiro;
}Lista;

void preencheDados(string * nome, string * cpf, string * data, int * dose, char * tipo){
  cout << "Nome: ";
  while(getline(cin, * nome))
   if(*nome != ""){
          break;
    }
  cout << "\nCPF: ";
  getline(cin, * cpf);
  cout << "\nData: ";
  getline(cin, * data);
  cout << "\nDose: ";
  cin >> * dose;
  cout << "\nTipo([C]ORONAVAC, [P]FIZER, [A]STRAZENECA, [J]ANSEN): ";
  cin >> * tipo;
}

void adicionar(Lista * lista){
  string nome;
  string cpf;
  string data;
  int dose;
  char tipo;

  preencheDados(&nome, &cpf, &data, &dose, &tipo);
  Vacinacao *aux, *nova = (Vacinacao *) malloc(sizeof(Vacinacao));
  nova->nome = nome;
  nova->cpf = cpf;
  nova->data = data;
  nova->dose = dose;
  nova->tipo = tipo;
  nova->prox = NULL;

  if(nova){
    if(lista->ponteiro == NULL){
      lista->ponteiro = nova;
    }else{
      aux = lista->ponteiro;
      while(aux->prox != NULL)
        aux = aux->prox;
      aux->prox = nova;
    }
  }else{
    cout << "Memoria insuficiente!";
  }

}

void imprimirTudo(Lista * lista){
  Vacinacao * imprimir = lista->ponteiro;
  while(imprimir != NULL){
    cout << "\n";
    cout << "|" << imprimir->nome << "|\n";
    cout << "|" << imprimir->cpf << "|\n";
    cout << "|" << imprimir->data << "|\n";
    cout << "|" << imprimir->dose << "|\n";
    cout << "|" << imprimir->tipo << "|\n";
    imprimir = imprimir->prox;
  }
  cout << "\n";
}

void totalVacinas(Lista * lista){
  Vacinacao * totVacina = lista->ponteiro;
  int total = 0;
  
  while(totVacina != NULL){
    if(totVacina->data == "HOJE" || 
      totVacina->data == "Hoje" ||
      totVacina->data == "hoje" ||
      totVacina->data == "hj" ||
      totVacina->data == "HJ" || 
      totVacina->data == "Hj"){
        total++;
      }
    totVacina = totVacina->prox;
  }
  cout << "\n";
  cout << "Total de pessoas vacinadas hoje: " << total << "\n";
  cout << "\n";
}

void vacinasTipo(Lista * lista){
  Vacinacao * vacTipo = lista->ponteiro;
  int C = 0, P = 0, A = 0, J = 0;
  
  while(vacTipo != NULL){
    if(vacTipo->tipo == 'C'){
      C++;
    }else if(vacTipo->tipo == 'P'){
      P++;
    }else if(vacTipo->tipo == 'A'){
      A++;
    }else if(vacTipo->tipo == 'J'){
      J++;
    }
    vacTipo = vacTipo->prox;
  }
  cout << "\n";
  cout << "CORONAVAC = " << C << "\n";
  cout << "PFIZER = " << P << "\n";
  cout << "ASTRAZENECA = " << A << "\n";
  cout << "JANSEN = " << J << "\n";
  cout << "\n";
}

void vacinasDose(Lista * lista){
  Vacinacao * vacDose = lista->ponteiro;
  int p = 0, s = 0, t = 0, q = 0;
  
  while(vacDose != NULL){
    if(vacDose->dose == 1){
      p++;
    }else if(vacDose->dose == 2){
      s++;
    }else if(vacDose->dose == 3){
      t++;
    }else if(vacDose->dose == 4){
      q++;
    }
    vacDose = vacDose->prox;
  }
  cout << "\n";
  cout << "Primeira dose: " << p << "\n";
  cout << "Segunda dose: " << s << "\n";
  cout << "Terceira dose: " << t << "\n";
  cout << "Quarta dose: " << q << "\n";
  cout << "\n";
}

int menu(){
  int opcao = 0;
  
  cout << "============== MENU ==============\n";
  cout << "| [1] Adicionar vacinacao        |\n";
  cout << "| [2] Imprimir tudo              |\n";
  cout << "| [3] Total de vacinados do dia  |\n";
  cout << "| [4] Vacinas por tipo           |\n";
  cout << "| [5] Vacinas por dose           |\n";
  cout << "| [6] Sair                       |\n";
  cout << "Informe uma opcao: ";
  cin >> opcao;
  return opcao;
}

int main() {

Lista dados;
dados.ponteiro = NULL;

int opcao = 0;
  while(opcao != 6){
    opcao = menu();

    switch(opcao){
      case 1:{
        adicionar(&dados);
        break;
      }
      case 2:{
        imprimirTudo(&dados);
        break;
      }
      case 3:{
        totalVacinas(&dados);
        break;
      }
      case 4:{
        vacinasTipo(&dados);
        break;
      }
      case 5:{
        vacinasDose(&dados);
        break;
      }
      case 6:{
        cout << "Finalizando...";
        break;
      }
      default:{
        cout << "\nOpcao Invalida!\n\n";
        break;
      }
    }
  }
  
  return 0;
}