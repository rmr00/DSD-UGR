/* Archivo calculadora.x: Realización de operaciones aritméticas de forma remota */

struct operationBasic{
    double first;
    double second;
};

union responseBasic switch (int error){
    case 0:
        double result;
    default:
        void;
};


typedef struct s_vector vector; 

struct s_vector{
	int vectorDim;
	double *vectorValues;
};

union responseVectores switch (int error){
    case 0:
       vector v;
    default:
        void;
};

program CALCULADORAPROG {

    version CALCULADORAVERS {
        //Operaciones básicas
        responseBasic SUMA (operationBasic) = 1;
        responseBasic RESTA (operationBasic) = 2;
        responseBasic MULTIPLICACION (operationBasic) = 3;
        responseBasic DIVISION (operationBasic) = 4;

        //Operaciones con vectores
        responseVectores SUMAVECTORES(vector v1, vector v2) = 5;

    } = 1;

} = 0x20000001;
