#pragma once
#include "Enemigo.h"
class Mago :
    public Enemigo
{
protected:
    float mana=1000;
public:
    Mago();
    virtual void LanzarHechizo();
    virtual void LanzarHechizoCurativo();
    //Es necesario sobreescribir e implementar las funciones virtuales
    //puras heredadas para que esta clase no se abstracta.


    // Inherited via Enemigo
    void Atacar() override;

    void Curarse() override;

    void Defenderse() override;

    virtual void Morir() override;

    void RecibirDanio(float danio_recibido) override;

    virtual void RegenerarMana();
};

