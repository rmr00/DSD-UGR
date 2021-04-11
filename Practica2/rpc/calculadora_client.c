/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

/**
 *	Autor: Raquel Molina Reche
 * 
 *	Compilación:  gcc calculadora_client.c calculadora_clnt.c calculadora_xdr.c -o cliente -lnsl
 */

#include "calculadora.h"

void
calculadoraprog_basicas(char *host, double a, char operation, double b)
{
	CLIENT *clnt;
	responseBasic  *result;

	//Se define la estructura operation que contiene los operandos a y b 
	// que será el argumento de las operaciones
	struct operationBasic operands;
	operands.first = a;
	operands.second = b;


	#ifndef	DEBUG
		clnt = clnt_create (host, CALCULADORAPROG, CALCULADORAVERS, "udp");
		if (clnt == NULL) {
			clnt_pcreateerror (host);
			exit (1);
		}
	#endif	/* DEBUG */

	//Se realiza la operacion según el tipo de operando
	switch (operation)
    {
        case '+': //Suma
            result = suma_1(operands, clnt);
			if (result == (responseBasic *) NULL) {
				clnt_perror (clnt, "call failed");
			}
            break;

        case '-'://Resta
           	result = resta_1(operands, clnt);
			if (result == (responseBasic *) NULL) {
				clnt_perror (clnt, "call failed");
			}
            break;

        case '*': //Multiplicacion
            result = multiplicacion_1(operands, clnt);
			if (result == (responseBasic *) NULL) {
				clnt_perror (clnt, "call failed");
			}
            break;

        case '/':  //Division
            result = division_1(operands, clnt);
			if (result == (responseBasic *) NULL) {
				clnt_perror (clnt, "call failed");
			}
            break;
		case 'l':
			result = logaritmo_1(operands, clnt);
			if (result == (responseBasic *) NULL) {
				clnt_perror (clnt, "call failed");
			}
			break;
		case '^':
			result = potencia_1(operands, clnt);
			if (result == (responseBasic *) NULL) {
				clnt_perror (clnt, "call failed");
			}
			break;
        
        default:
            break;
    }

	//Se muestra el resultado
	printf("El resultado de la operación %f %c %f = %f\n", a, operation, b, result->responseBasic_u.result);
	

	//Se libera la memoria asignada por la llamada RPC
	xdr_free (xdr_responseBasic, result);

	#ifndef	DEBUG
		clnt_destroy (clnt);
	#endif	 /* DEBUG */
}

void
calculadoraprog_vectores(char *host, vectorData v1, char operation, vectorData v2)
{
	CLIENT *clnt;
	responseVectores  *result;
	responseBasic  *resultProdEscalar;

	//Se define la estructura operation que contiene los operandos v1 y v2 
	// que será el argumento de las operaciones
	struct operationVectores operands;
	operands.first = v1;
	operands.second = v2;

	#ifndef	DEBUG
		clnt = clnt_create (host, CALCULADORAPROG, CALCULADORAVERS, "udp");
		if (clnt == NULL) {
			clnt_pcreateerror (host);
			exit (1);
		}
	#endif	/* DEBUG */

	switch (operation)
    {
        case '+': //Suma
            result = sumavectores_1(operands, clnt);
			if (result == (responseVectores *) NULL) {
				clnt_perror (clnt, "call failed");
			}

            break;

        case '-'://Resta
           	result = restavectores_1(operands, clnt);
			if (result == (responseVectores *) NULL) {
				clnt_perror (clnt, "call failed");
			}
            break;
		default:
            break;
    }
	
	//Se muestra el resultado
	switch (operation)
    {
        case '+': //Suma
            printf("El resultado de sumar los vectores es: ");
			for(int i = 0; i < result->responseVectores_u.vResult.vectorData_len; i++){
				printf("%f  ", result->responseVectores_u.vResult.vectorData_val[i]);
			}
            break;

        case '-'://Resta
           	printf("El resultado de restar los vectores es: ");
			for(int i = 0; i < result->responseVectores_u.vResult.vectorData_len; i++){
				printf("%f  ", result->responseVectores_u.vResult.vectorData_val[i]);
			}
            break;
		default:
            break;
    }
		
	printf("\n");

	//Se libera la memoria asignada por la llamada RPC
	xdr_free (xdr_responseVectores, result);

	#ifndef	DEBUG
		clnt_destroy (clnt);
	#endif	 /* DEBUG */
}

void
calculadoraprog_vectores3D(char *host, vector3D v1,  char operation, vector3D v2)
{
	CLIENT *clnt;
	responseVectores  *resultProdVectorial;
	responseBasic  *resultProdEscalar;


	//Se define la estructura operation que contiene los operandos v1, v2 y v3 
	// que será el argumento de las operaciones
	struct operationVectores3D operands;
	operands.first = v1;
	operands.second = v2;

	#ifndef	DEBUG
		clnt = clnt_create (host, CALCULADORAPROG, CALCULADORAVERS, "udp");
		if (clnt == NULL) {
			clnt_pcreateerror (host);
			exit (1);
		}
	#endif	/* DEBUG */

	switch (operation)
    {
        case '*': //Producto escalar
            resultProdEscalar = prodescalar3d_1(operands, clnt);
			if (resultProdEscalar == (responseBasic *) NULL) {
				clnt_perror (clnt, "call failed");
			}

            break;

        case 'x': //Producto vectorial
           	resultProdVectorial = prodvectorial3d_1(operands, clnt);
			if (resultProdVectorial == (responseVectores *) NULL) {
				clnt_perror (clnt, "call failed");
			}
            break;
		default:
            break;
    }
	
	//Se muestra el resultado
	switch (operation)
    {
        case '*': //Producto escalar
            printf("El resultado del producto escalar es %f",resultProdEscalar->responseBasic_u.result);
            break;

        case 'x': //Producto vectorial
           	printf("El resultado de restar los vectores es: ");
			for(int i = 0; i < resultProdVectorial->responseVectores_u.vResult.vectorData_len; i++){
				printf("%f  ", resultProdVectorial->responseVectores_u.vResult.vectorData_val[i]);
			}
            break;
		default:
            break;
    }
		
	printf("\n");

	//Se libera la memoria asignada por la llamada RPC
	xdr_free (xdr_responseVectores, resultProdEscalar);
	xdr_free (xdr_responseVectores, resultProdVectorial);

	#ifndef	DEBUG
		clnt_destroy (clnt);
	#endif	 /* DEBUG */
}


void
calculadoraprog_matrices(char *host, matrizData a, char operation, matrizData b)
{
	CLIENT *clnt;
	responseMatrices  *result;

	struct operationMatrices operands;
	operands.first = a;
	operands.second = b;

	#ifndef	DEBUG
		clnt = clnt_create (host, CALCULADORAPROG, CALCULADORAVERS, "udp");
		if (clnt == NULL) {
			clnt_pcreateerror (host);
			exit (1);
		}
	#endif	/* DEBUG */

	//Se realiza la operacion según el tipo de operando
	switch (operation)
    {
        case '+': //Suma
            result = sumamatrices_1(operands, clnt);
			if (result == (responseMatrices *) NULL) {
				clnt_perror (clnt, "call failed");
			}
            break;

        case '-'://Resta
           	
            break;

        default:
            break;
    }

	//Se muestra el resultado
	//printf("El resultado de la operación %f %c %f = %f\n", a, operation, b, result->responseMatrices_u.mResult.c);
	

	//Se libera la memoria asignada por la llamada RPC
	xdr_free (xdr_responseMatrices, result);
	
	
	#ifndef	DEBUG
		clnt_destroy (clnt);
	#endif	 /* DEBUG */
}

int
main (int argc, char *argv[])
{
	//Declaracion de variables
	char *host;
	double a, b;
	char operation;

	if (argc  != 5) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}

	//Se almacena la peticion
	host = argv[1];
	a = atof(argv[2]);
	b = atof(argv[4]);
	operation = *argv[3];

	//-------------------MENU---------------

	calculadoraprog_basicas (host,a,operation,b);

	//Vectores
	vectorData v1, v2;

	printf("	1: adios\n");

	v1.vectorData_len = 5;
	v1.vectorData_val = malloc(5*sizeof(double));

	for(int i = 0; i < v1.vectorData_len; i++){
		v1.vectorData_val[i] = 1.0;
		//scanf("%lf",&v1.vectorData_val[i]);
	}

	printf("	2: adios\n");


	v2.vectorData_len = 5;
	v2.vectorData_val = malloc(5*sizeof(double));
	
	for(int i = 0; i < v2.vectorData_len; i++){
		v2.vectorData_val[i] = 5.0;
	}

	printf("	3: adios\n");


	calculadoraprog_vectores(host, v1, operation, v2);

	//Vectores3D
	vector3D v3D1, v3D2;

	v3D1.x = 3.0;
	v3D1.y = 2.0;
	v3D1.z = 1.0;

	v3D2.x = 1.0;
	v3D2.y = 20.0;
	v3D1.z = 3.0;

	calculadoraprog_vectores3D(host, v3D1, operation, v3D2);
	
	//Matrices
	matrizData m1, m2;
	//calculadoraprog_matrices(host, m1, operation, m2);
	
exit (0);
}

