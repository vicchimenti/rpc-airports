/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include "airports.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

airports_ret *
getairports_1(coordinates *argp, CLIENT *clnt)
{
	static airports_ret clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, GETAIRPORTS,
		(xdrproc_t) xdr_coordinates, (caddr_t) argp,
		(xdrproc_t) xdr_airports_ret, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}
