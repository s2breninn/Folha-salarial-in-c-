#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "portuguese");

    int filhos, classe;
    float salarioBase,
          salarioBruto,
          salarioLiq,
          valeAli = 308.59,
          boniFilhoTotal,
          valeTransp,
          adicional,
          salarioBaseAdi,
          impRenda,
          inss;
    string categoria;

    cout << "+---------------------------------+" << endl;
    cout << "|    C�LCULO DE FOLHA SALARIAL    |" << endl;
    cout << "+---------------------------------+" << endl << endl;

    cout << "- Digite o valor do sal�rio: R$";
    cin >> salarioBase;

    if(salarioBase>00){
        cout << endl << "- Informe o total de filhos: ";
        cin >> filhos;

        if(filhos>0){
            cout << endl << "- Informe a classe que se enquadra (1-J�nior, 2-Pleno, 3-S�nior): ";
            cin >> classe;

            if(classe== 1 || classe==2 || classe==3){
                //C�lculo de vale transporte
                if(salarioBase<=800){
                    valeTransp = 285.85;
                } else if(salarioBase>800 && salarioBase<=1546.50){
                    valeTransp = 201.43;
                } else if(salarioBase>1546.50 && salarioBase<=2143.56){
                    valeTransp = 185.71;
                } else if(salarioBase>2143.56 && salarioBase<=3002.17){
                    valeTransp = 121.33;
                } else if(salarioBase>3002.17 && salarioBase<=3702.29){
                    valeTransp = 85.18;
                } else if(salarioBase>3002.17){
                    valeTransp = 78.41;
                }

                //C�lculo de adicionais da classe e soma com sal�rio base
                if(classe==1){
                    adicional = 289.70;
                    salarioBaseAdi = salarioBase + adicional;
                    categoria = "JUNIOR";
                } else if (classe==2){
                    adicional = 831.67;
                    salarioBaseAdi = salarioBase + adicional;
                    categoria = "PLENO";
                } else if (classe==3){
                    adicional = 2100.31;
                    salarioBaseAdi = salarioBase + adicional;
                    categoria = "S�NIOR";
                }
                boniFilhoTotal = ((1.9876/100.0)*salarioBase)*filhos;
                salarioBruto = salarioBase + valeAli + boniFilhoTotal + valeTransp + adicional;

                //C�lculo do imposto de renda
                if(salarioBaseAdi<=1499.15){
                    impRenda = 0;
                } else if (salarioBaseAdi>1499.15 && salarioBaseAdi<=2146.75){
                    impRenda = (7.5/100.0)*salarioBaseAdi;
                } else if (salarioBaseAdi>2146.75 && salarioBaseAdi<=2995.70){
                    impRenda = (15/100.0)*salarioBaseAdi;
                } else if (salarioBaseAdi>2995.70 && salarioBaseAdi<=3441.16){
                    impRenda = (22/100.0)*salarioBaseAdi;
                } else if (salarioBaseAdi>3441.16 && salarioBaseAdi<=4543.11){
                    impRenda = (24.5/100.0)*salarioBaseAdi;
                } else if (salarioBaseAdi>4543.11){
                    impRenda = (28.5/100.0)*salarioBaseAdi;
                }

                //C�lculo do INSS
                if(salarioBaseAdi<=1417.07){
                    inss = (8/100.0)*salarioBaseAdi;
                } else if(salarioBaseAdi>1417.07 && salarioBaseAdi<=2195.12){
                    inss = (9/100.0)*salarioBaseAdi;
                } else if(salarioBaseAdi>2195.12 && salarioBaseAdi<=3396.11){
                    inss = (11/100.0)*salarioBaseAdi;
                } else if (salarioBaseAdi>3396.11) {
                    inss = (14/100.0)*salarioBaseAdi;
                }
                salarioLiq = salarioBase - impRenda - inss;

                cout << endl << "--------------------------------------------------------------------";
                cout << endl << endl << "Vale alimenta��o: R$" << valeAli;
                cout << endl << "Valor de bonifica��o: R$" << boniFilhoTotal;
                cout << endl << "Vale transporte: R$" << valeTransp;
                cout << endl << "Total dos benef�cios (VA, BF, VT): R$" << valeAli+boniFilhoTotal+valeTransp;
                cout << endl << "Valor da classe para " << categoria << ": R$" << adicional;
                cout << endl << "Sal�rio bruto: R$" << salarioBruto;
                cout << endl << "Imposto de renda: R$" << impRenda;
                cout << endl << "Imposto do INSS: R$" << inss;
                cout << endl << "Total de descontos (IR e INSS): R$" << impRenda+inss;
                cout << endl << "S�lario L�quido: R$" << salarioLiq;
            } else {
                cout << endl << "Classe informada inv�lida.";
            }
        } else {
            cout << endl << "Total de filhos informado inv�lido";
        }
    } else {
        cout << endl << "S�lario base informado inv�lido.";
    }

    return 0;
}
