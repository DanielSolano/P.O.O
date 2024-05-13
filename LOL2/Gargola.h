#pragma once
#include "Enemigo.h"
#include "Volador.h"

class Gargola :
    public Enemigo, public Volador
{
protected:
public:
    Gargola();
    void Atacar() override;
    void Curarse() override;
    void Defenderse() override;
    virtual void Morder();
    virtual void Volar() override;
    virtual void Aterrizar() override;
    virtual void Araniar();
    virtual void RecibirDanio(float danio_recibido) override;
    virtual void Morir() override;
};

