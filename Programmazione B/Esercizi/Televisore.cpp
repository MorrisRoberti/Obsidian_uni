// Si implementi in C++ una classe Televisore. Un televisore è caratterizzato da:
// - il fatto che il televisore è acceso o spento
// - il volume (che è compreso tra 0 e 10)
// - un canale (che è compreso tra 0 e 99)

// Implementare i seguenti metodi della classe Televisore:
// - un unico costruttore che prende come parametro il canale ed inizializza il campo corrispondente, setta il televisore ad acceso e il volume a 5.
// -  pulsanteAccendi: ad ogni chiamata, spegne o accende il televisore (se il televisore è accesso la chiamata a questo metodo la spegne e viceversa)
// - impostaCanale: se la tv è accesa, setta il televisore su un canale passato come parametro
// - canaleSuccessivo: se la tv è accesa, passa al canale successivo, se possibile
// - canalePrecedente: se la tv è accesa, passa al canale precedente, se possibile
// - aumentaVolume: se la tv è accesa, aumenta di 1 il volume, se possibile
// - abbassaVolume: se la tv è accesa, diminuisce di 1 il volume, se possibile
// - silenzia: se la tv è accesa, setta a 0 il volume del televisore
// - stampaTelevisore: se la tv è accesa, visualizza lo stato del televisore (cioè il valore di tutte le sue proprietà in quell'istante)
#include <iostream>
using namespace std;

class Televisore
{
private:
    bool isOn;
    int volume;
    int canale;

public:
    Televisore(int canale)
    {
        if (canale >= 0 && canale <= 99)
        {
            this->canale = canale;
        }
        else
        {
            cout << "Errore: il canale inserito non e' valido, verra' impostato 0";
            this->canale = 0;
        }

        this->isOn = true;
        this->volume = 5;
    }

    void pulsanteAccendi()
    {
        this->isOn = !this->isOn;
    }

    void impostaCanale(int canale)
    {
        if (this->isOn == true)
        {
            if (canale >= 0 && canale <= 99)
            {
                this->canale = canale;
            }
            else
            {
                cout << "Errore: il canale inserito non e' valido";
            }
        }
        else
        {
            cout << "La tv e' spenta, accenderla prima di impostare il canale";
        }
    }

    void canaleSuccessivo()
    {
        if (this->isOn == true)
        {
            if (canale < 99)
            {
                this->canale += 1;
            }
            else
            {
                cout << "Il canale 99 e' il massimo";
            }
        }
        else
        {
            cout << "La tv e' spenta, accenderla prima di impostare il canale";
        }
    }
    void canalePrecedente()
    {
        if (this->isOn == true)
        {
            if (canale > 0)
            {
                this->canale -= 1;
            }
            else
            {
                cout << "Il canale 0 e' il minimo";
            }
        }
        else
        {
            cout << "La tv e' spenta, accenderla prima di impostare il canale";
        }
    }
    void aumentaVolume()
    {
        if (this->isOn == true)
        {
            if (this->volume < 10)
            {
                this->volume += 1;
            }
            else
            {
                cout << "Il volume 10 e' il massimo";
            }
        }
        else
        {
            cout << "La tv e' spenta, accenderla prima di aumentare il volume";
        }
    }
    void abbassaVolume()
    {
        if (this->isOn == true)
        {
            if (this->volume > 0)
            {
                this->volume -= 1;
            }
            else
            {
                cout << "Il volume 0 e' il minimo";
            }
        }
        else
        {
            cout << "La tv e' spenta, accenderla prima di abbassare il volume";
        }
    }

    void silenzia()
    {
        if (this->isOn == true)
        {
            this->volume = 0;
        }
        else
        {
            cout << "La tv e' spenta, accenderla prima di silenziare";
        }
    }

    void stampaTelevisore()
    {
        if (this->isOn == true)
        {
            cout << "Stato: Accesa" << endl;
            cout << "Canale: " << this->canale << endl;
            cout << "Volume: " << this->volume << endl;
        }
        else
        {
            cout << "La tv e' spenta, accenderla prima di stampare";
        }
    }
};

int main()
{
    return 0;
}