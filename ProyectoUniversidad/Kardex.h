// #include "Estudiante.h"
#include "Calificacion.h"
#include <vector>
using std::vector;
class Estudiante;
class Kardex
{
    protected:
        double promedio = 0;
        int creditos = 0;
        vector<Calificacion> calificaciones;
        Estudiante* estudiante;
    public:
        Kardex(Estudiante* estudiante = nullptr) = { this->estudiante = estudiante; };
        double GetPromedio()const { return promedio; }
        int GetCreditos()const { return creditos; }
        
        string ToString()const;
        void RegistrarCalificacion(Calificacion calif);        
        
        
};