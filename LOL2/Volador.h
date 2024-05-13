#pragma once
class Volador
{
protected:
	bool volando = false;
public:
	Volador() = default;
	bool IsFlying() const { return volando; };
	virtual void Volar() { volando = true; };
	virtual void Aterrizar() { volando = false; };
};

