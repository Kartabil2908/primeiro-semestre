#include <iostream>
#include <string>

using namespace std;

class Cliente
{

private:
    string nome;
    string cpf;

public:

    Cliente(string nome, string cpf, Comanda comanda)
    {

        setNome(nome);
        setCpf(cpf);


    }

    void setNome(nom)
    {

        this.nome = nom;

    }

    String getNome()
    {

        return this.nome;

    }

    void setCpf(c)
    {

        this.cpf = c;

    }

    string getCpf()
    {

        return this.cpf;

    }

};


class Comanda : public Cliente{

    private:

        string data;
        string garcon;
        ItemComanda[i];


    public:

        Comanda(string data, string garcon){

            setData(data);
            setGarcon(garcon);



            }

        }


};





};
