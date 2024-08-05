
/*Crie uma classe em C++ chamada Relogio para armazenar um hor�rio, composto por hora, minuto e segundo. A
classe deve representar esses componentes de hor�rio e deve apresentar os m�todos descritos a seguir:
� um m�todo chamado setHora, que deve receber o hor�rio desejado por par�metro (hora, minuto e
segundo);
� um m�todo chamado getHora para retornar o hor�rio atual como uma string, no formato HH:MM:SS.
Exemplo: 13:15:40.
� um m�todo para avan�ar o hor�rio para o pr�ximo segundo (lembre-se de atualizar o minuto e a hora,
quando for o caso).
Crie um programa para testar sua classe.*/

#include <iostream>
#include <string>

using namespace std;

class Relogio{

private:

    int hora;
    int minuto;
    int segundo;

public:

    Relogio(int h, int m, int s) {

    setHora(h, m, s);

    }

    void setHora(int hr, int m, int seg){

        if(hr > 24 || hr < 0 || m > 60 || m < 0 || seg > 60 || seg < 0){

            cout << "Hor�rio Inv�lido" << endl;

        }else{

        hora = hr;
        minuto = m;
        segundo = seg;

        }
    }


    string getHora(){

        string horario;

        horario = to_string(this->hora) + "" + to_string(this->minuto) + "" + to_string(this->segundo);

        return horario;

    }


};





int main(){

    int hr;
    int m;
    int seg;
    string s;


    cout << "Digite as horas";
    cin >> hr;

    cout << "Digite os minutos";
    cin >> m;

    cout << "Digite os segundos";
    cin >> seg;

Relogio relo(hr, m, seg);

 s = relo.getHora();

cout << "As horas s�o:" << relo.hora << endl;






}





