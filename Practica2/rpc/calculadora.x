/* Archivo calculadora.x: Realización de operaciones aritméticas de forma remota */

struct operation{
    double first;
    double second;
};

union response switch (int error){
    case 0:
        double result;
    default:
        void;
};

program CALCULADORAPROG {

    version CALCULADORAVERS {
        response SUMA (operation) = 1;
        response RESTA (operation) = 2;
        response MULTIPLICACION (operation) = 3;
        response DIVISION (operation) = 4;
    } = 1;

} = 0x20000001;
