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
#include <stdio.h>

#define RESET_COLOR	"\x1b[0m"
#define NEGRO_T		"\x1b[30m"
#define NEGRO_F		"\x1b[40m"
#define ROJO_T		"\x1b[31m"
#define ROJO_F		"\x1b[41m"
#define VERDE_T		"\x1b[32m"
#define VERDE_F 	"\x1b[42m"
#define AMARILLO_T	"\x1b[33m"
#define AMARILLO_F	"\x1b[43m"
#define AZUL_T		"\x1b[34m"
#define AZUL_F		"\x1b[44m"
#define MAGENTA_T	"\x1b[35m"
#define MAGENTA_F	"\x1b[45m"
#define CYAN_T		"\x1b[36m"
#define CYAN_F		"\x1b[46m"
#define BLANCO_T	"\x1b[37m"
#define BLANCO_F	"\x1b[47m"

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
	//printf("El resultado de la operación %f %c %f = %f\n", a, operation, b, result->responseBasic_u.result);
	printf(ROJO_T"%f"RESET_COLOR"\n", result->responseBasic_u.result);
	

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

#define MAXIMA_LONGITUD_PETICION 50

int
main (int argc, char *argv[])
{
	//Declaracion de variables
	char *host;
	double a, b;
	char operation;

	char peticion[MAXIMA_LONGITUD_PETICION];

	if (argc  != 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}

	//Se almacena la peticion
	host = argv[1];
	//a = atof(argv[2]);
	//b = atof(argv[4]);
	//operation = *argv[3];

	//-------------------MENU---------------

	//calculadoraprog_basicas (host,a,operation,b);

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


	//calculadoraprog_vectores(host, v1, operation, v2);

	//Vectores3D
	vector3D v3D1, v3D2;

	v3D1.x = 3.0;
	v3D1.y = 2.0;
	v3D1.z = 1.0;

	v3D2.x = 1.0;
	v3D2.y = 20.0;
	v3D1.z = 3.0;

	//calculadoraprog_vectores3D(host, v3D1, operation, v3D2);
	
	//Matrices
	matrizData m1, m2;
	//calculadoraprog_matrices(host, m1, operation, m2);

	int peticionValida=1;

	int menuPrincipal=0;
	while( menuPrincipal != 5){
		printf("\nOpciones disponibles:\n");
		printf("  1: Operaciones Básicas\n");
		printf("  2: Operaciones con vectores\n");
		printf("  3: Operaciones con vectores 3D\n");
		printf("  4: Operaciones con matrices\n");
		printf("  5: Salir \n");

		printf("\n--Introducce una opción: ");
		scanf("%d",&menuPrincipal);

		switch(menuPrincipal){
			case 1: //Menu Operaciones basicas
				printf("   ----OPERACIÓN BÁSICA----\n");
				//printf("   Introduce una operacion <operando> '+' '-' '*' '/' 'log' '^' <operabdo>: (ej: 5 + 5)\n");

				//Obtener los operandos y la operacion
				printf("   Introduce la operacion '+' '-' '*' '/' 'log' '^': ");
				scanf("%s",peticion);

				if( strcmp(peticion, "+") == 0 ){
					printf("\n(es suma)\n");
					operation='+';
					peticionValida=1;
				}
				else if(strcmp(peticion, "-") == 0){
					printf("\n(es resta)\n");
					operation='-';
					peticionValida=1;
				}
				else if(strcmp(peticion, "*") == 0){
					printf("\n(es mult)\n");
					operation='*';
					peticionValida=1;
				}
				else if(strcmp(peticion, "/") == 0){
					printf("\n(es div)\n");
					operation='/';
					peticionValida=1;
				}
				else if(strcmp(peticion, "log") == 0){
					printf("\n(es log)\n");
					operation='l';
					peticionValida=1;
				}
				else if(strcmp(peticion, "^") == 0){
					printf("\n(es pot)\n");
					operation='^';
					peticionValida=1;
				}
				else{
					peticionValida=0;
				}

				//Si la peticon es valida entonces se obtienen los operandos
				if(peticionValida){

					if( operation != 'l' && operation != '^'){
						printf("   Introduce el primer operando: ");
						scanf("%lf",&a);

						printf("   Introduce el segundo operando: ");
						scanf("%lf",&b);
					}
					else if(operation == 'l')  {
						printf("   Introduce el argumento: ");
						scanf("%lf",&a);

						printf("   Introduce la base: ");
						scanf("%lf",&b);
					}
					else if(operation == '^')  {
						printf("   Introduce la base: ");
						scanf("%lf",&a);

						printf("   Introduce el exponente: ");
						scanf("%lf",&b);
					}

					printf( ROJO_T" El resultado de la operación"AZUL_T"%f %s %f"ROJO_T"= "RESET_COLOR, a , peticion, b);
					//Realizar peticion al servidor y Mostrar resultado
					calculadoraprog_basicas (host,a,operation,b);
				}
				else{
					printf(" NO ES CORRECTA LA PETICION\n");
				}	

				break;
				
			case 2: //Menu vectores
			break;

			case 3: //Menu Vectores3D
				printf("   ---------GESTION DE PIEZAS--------------");
				/*int menuPiezas=0;
				while( menuPiezas != 11){
					printf("\t\n    Opciones Gestion de piezas:");
					printf("\t   1: Dar de alta una pieza");
					printf("\t   2: Consultar una pieza");
					printf("\t   3: Modificar una pieza");
					printf("\t   4: Dar de baja una pieza");
					printf("\t   5: Crear un pedido de Exportacion");
					printf("\t   6: Crear un pedido de Importacion");
					printf("\t   7: Consultar un pedido");
					printf("\t   8: Consultar todas las compras de piezas");
					printf("\t   9: Consultar todas las ventas de piezas");
					printf("\t   10: Eliminar un pedido");
					printf("\t   11: Atras\n");
					
					menuPiezas = scanner.nextInt();

					//Gestion piezas y pedidos
					String CPieza,nombrePieza; int cantPieza; String pcompraPieza, pventaPieza;
					int CPedido; String NIFExpPedido , NIFImpPedido; String precioPedido;
					String salidaGestPie;

					switch(menuPiezas){
						case 1:
							printf("\t------Alta de Pieza------");
							printf("\tCodigo:");
							CPieza = scanner.next();
							printf("\n\tNombre:");
							nombrePieza = scanner.next();
							printf("\n\tCantidad:");
							cantPieza = scanner.nextInt();
							printf("\n\tPrecio Compra (formato nn.nn):");
							pcompraPieza = scanner.next();
							printf("\n\tPrecio Venta (formato nn.nn):");
							pventaPieza = scanner.next();
							
							gestPiezas.insertarPieza(CPieza, nombrePieza, cantPieza, pcompraPieza, pventaPieza);
							
							con.commit();
							break;
						
						case 2:
							printf("\t------Consulta Pieza------");
							printf("\tIntroduce el codigo de la pieza:");
							CPieza = scanner.next();
							salidaGestPie = gestPiezas.consultarPieza(CPieza);
							if(salidaGestPie == ""){
								printf("\tNo existe ninguna pieza con ese código");
							}
							else{
								printf("\t"+salidaGestPie);
							}
							
							
							break;
						
						case 3:
							printf("\t------Modificar Pieza------");
							printf("\tIntroduce el codigo de la pieza:");
							CPieza = scanner.next();
							Savepoint sp = con.setSavepoint("spModificarPieza");
							String nuevoNombre; int nuevaCant; String nuevoPcompra, nuevoPventa; 
							int menuModificarPieza=0;
							while(menuModificarPieza!=5 && menuModificarPieza!=6){
								printf("\t\tOpciones Modificar Pieza:");
								printf("\t\t  1: Modificar nombre");
								printf("\t\t  2: Modificar cantidad");
								printf("\t\t  3: Modificar precio compra");
								printf("\t\t  4: Modificar precio venta");
								printf("\t\t  5: Cancelar modificaciones");
								printf("\t\t  6: Guardar modificaciones");

								menuModificarPieza = scanner.nextInt();

								switch(menuModificarPieza){
									case 1:
										printf("\t\tNuevo nombre:");
										nuevoNombre = scanner.next();
										
										gestPiezas.modificarNombrePieza(CPieza, nuevoNombre);
										
										break;

									case 2:
										printf("\n\t\tNueva cantidad:");
										nuevaCant = scanner.nextInt();
										
										gestPiezas.modificarCantidadPieza(CPieza, nuevaCant);
										
										break;
									case 3:
										printf("\n\t\tNuevo Precio Compra:");
										nuevoPcompra = scanner.next();
										
										gestPiezas.modificarPrecioCompraPieza(CPieza, nuevoPcompra);
										
										break;
									case 4:
										printf("\n\t\tNuevo Precio Venta:");
										nuevoPventa = scanner.next();
										
										gestPiezas.modificarPrecioVentaPieza(CPieza, nuevoPventa);
										
										break;
									case 5:
										con.rollback(sp);
										break;
									case 6:
										con.commit();
										break;

								}
							}
							break;

						case 4:
							printf("\t------Dar de baja una Pieza------");
							printf("\tIntroduce el codigo de la pieza:");
							CPieza = scanner.next();
							
							//Se borra la pieza con CPieza tanto de Pieza como de Contiene
							//y se borra el pedido que iba asociado a esa pieza
							gestPiezas.borrarPieza(CPieza);

							con.commit();
							break;
						
						case 5:
							printf("\t------Crear un pedido de Exportacion------");
							printf("\tIntroduce el codigo de la pieza:");
							CPieza = scanner.next();
							CPedido = gestPiezas.generacionAutomaticaCodigoPedido();
							
							printf("\n\tNIF empresa Importadora:");
							NIFImpPedido = scanner.next();
							
							printf("\n\tCantidad de piezas:");
							cantPieza = scanner.nextInt();
							boolean resultExport;                    
							resultExport = gestPiezas.crearPedidoExportacion(CPieza, NIFImpPedido, cantPieza); 
							
							if(!resultExport)
								printf("\tINCORRECTO.Pieza o empresa no existen o la cantidad no es válida");
							else
								printf("\tPedido creado de forma correcta");
							
							con.commit();
							break;

						case 6:
							printf("\t------Crear un pedido de Importacion------");
							printf("\tIntroduce el codigo de la pieza:");
							CPieza = scanner.next();
							//CPedido = gestPiezas.generacionAutomaticaCodigoPedido();
							
							printf("\n\tNIF empresa Exportadora:");
							NIFExpPedido = scanner.next();

							printf("\n\tCantidad de piezas:");
							cantPieza = scanner.nextInt();
												
							gestPiezas.crearPedidoImportacion(CPieza, NIFExpPedido, cantPieza); 
							
							con.commit();
							break;

						case 7:
							printf("\t------Consulta un pedido------");
							printf("\tIntroduce el codigo del pedido:");
							CPedido = scanner.nextInt();
							
							salidaGestPie = gestPiezas.consultarPedido(CPedido);
							if(salidaGestPie == ""){
								printf("\tNo existe ningun pedido con ese código");
							}
							else{
								printf("\t"+salidaGestPie);
							}
							break;

						case 8:
							printf("\t------Consulta compras realizadas------");
							salidaGestPie = gestPiezas.consultarCompras();
							if(salidaGestPie == ""){
								printf("\tNo se ha realizado ninguna compra");
							}
							else{
								printf(salidaGestPie);
							}
							break;

						case 9:
							printf("\t------Consulta ventas realizadas------");
							salidaGestPie = gestPiezas.consultarVentas();
							if(salidaGestPie == ""){
								printf("\tNo se ha realizado ninguna venta");
							}
							else{
								printf(salidaGestPie);
							}
							break;
			
						case 10:
							printf("\t------Eliminar un pedido------ ");
							printf("\tIntroduce el codigo del pedido:");
							CPedido = scanner.nextInt();
							
							//Se borra el pedido con CPedido tanto de Pedido como de Contiene
							gestPiezas.borrarPedido(CPedido);
							con.commit();
							break;

						case 11:
							// Exit
							printf("Volviendo al Menu principal...\n");
							break;
						default:
						printf("ERROR: Opcion no valida\n");
					}
				}*/
			break;

			case 4: //Menu Matrices
			break;

			case 5:
				printf("Saliendo...\n");
				// Exit
			break;

			default:
				printf("ERROR: Opcion no valida\n");
		}
	}
	
exit (0);
}

