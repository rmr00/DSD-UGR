/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "calculadora.h"

bool_t
xdr_operationBasic (XDR *xdrs, operationBasic *objp)
{
	register int32_t *buf;

	 if (!xdr_double (xdrs, &objp->first))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->second))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_responseBasic (XDR *xdrs, responseBasic *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->error))
		 return FALSE;
	switch (objp->error) {
	case 0:
		 if (!xdr_double (xdrs, &objp->responseBasic_u.result))
			 return FALSE;
		break;
	default:
		break;
	}
	return TRUE;
}

bool_t
xdr_vectorData (XDR *xdrs, vectorData *objp)
{
	register int32_t *buf;

	 if (!xdr_array (xdrs, (char **)&objp->vectorData_val, (u_int *) &objp->vectorData_len, ~0,
		sizeof (double), (xdrproc_t) xdr_double))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_operationVectores (XDR *xdrs, operationVectores *objp)
{
	register int32_t *buf;

	 if (!xdr_vectorData (xdrs, &objp->first))
		 return FALSE;
	 if (!xdr_vectorData (xdrs, &objp->second))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_responseVectores (XDR *xdrs, responseVectores *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->error))
		 return FALSE;
	switch (objp->error) {
	case 0:
		 if (!xdr_vectorData (xdrs, &objp->responseVectores_u.vResult))
			 return FALSE;
		break;
	default:
		break;
	}
	return TRUE;
}

bool_t
xdr_vector3D (XDR *xdrs, vector3D *objp)
{
	register int32_t *buf;

	 if (!xdr_double (xdrs, &objp->x))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->y))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->z))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_operationVectores3D (XDR *xdrs, operationVectores3D *objp)
{
	register int32_t *buf;

	 if (!xdr_vector3D (xdrs, &objp->first))
		 return FALSE;
	 if (!xdr_vector3D (xdrs, &objp->second))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_matrizData (XDR *xdrs, matrizData *objp)
{
	register int32_t *buf;

	 if (!xdr_matriz (xdrs, objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_matriz (XDR *xdrs, matriz *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->f))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->c))
		 return FALSE;
	 if (!xdr_vectorData (xdrs, &objp->m))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_operationMatrices (XDR *xdrs, operationMatrices *objp)
{
	register int32_t *buf;

	 if (!xdr_matrizData (xdrs, &objp->first))
		 return FALSE;
	 if (!xdr_matrizData (xdrs, &objp->second))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_responseMatrices (XDR *xdrs, responseMatrices *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->error))
		 return FALSE;
	switch (objp->error) {
	case 0:
		 if (!xdr_matrizData (xdrs, &objp->responseMatrices_u.mResult))
			 return FALSE;
		break;
	default:
		break;
	}
	return TRUE;
}