/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "places.h"
#include "airports.h"
#include <stdio.h>
#include <string.h>


places_ret *
callplaces_1_svc(struct city_state *argp, struct svc_req *rqstp)
{
	// static places_ret  result;

	/*View incomming values from the client*/
	printf("\nPlaces Server Side: Received city= %s, received state= %s\n", &argp[0].city, &argp[0].state);

	static places_ret  result;
	airport_place* apsp = &result.places_ret_u.airport_place;

	/***
	*		Assign arg from client into a city_state struct
	*		that can be forwarded to airports server
	*
	*/
	struct city_state place;
	strncpy(place.city, (char*)&argp[0].city, sizeof(place.city));
	strncpy(place.state, (char*)&argp[0].state, sizeof(place.state));
	printf("\nPlaces Server side: Assigned city= %s, assigned state= %s\n", place.city, place.state);


	/**** Add file functions to retreive lat and lon here  ****/

	/****
	*		Write airport client function here
	*
	*/
	CLIENT *clnt;
	airports_ret  *result_1;
	coordinates getairports_1_arg;
	char* host = "localhost";
	double latitude = 122;
	double longitude = 54;

#ifndef	DEBUG
	clnt = clnt_create (host, AIRPORTS_PROG, AIRPORTS_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	/*assign arg from places server into coordinates struct (hardcoded)*/
	getairports_1_arg.lat = latitude;
	getairports_1_arg.lon = longitude;
	printf("\nplaces server side: assigned getairports_1_arg.lat= %f, assigned getairports_1_arg.lon= %f\n", getairports_1_arg.lat, getairports_1_arg.lon);


	result_1 = getairports_1(&getairports_1_arg, clnt);
	if (result_1 == (airports_ret *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	/* Assign result from airport server (this should be one hardcoded airport) */
	airport ap = result_1->airports_ret_u.airport;
	// strncpy(ap->city, (char*)&result_1[0]->city, sizeof(ap->city));
	// strncpy(ap->state, (char*)&result_1[0]->state, sizeof(ap->state));
	printf("\nPlaces Client: p->city = %s, p->state= %s\n", ap->city, ap->state);

	/* convert from airports struct to airport_place struct */
	airport_place airport_terminal;
	airport_terminal = (airport_place_node *)malloc(sizeof(airport_place_node));
	strncpy(airport_terminal->city, (char*)&ap->city, sizeof(airport_terminal->city) - 1);
	strncpy(airport_terminal->state, (char*)&ap->state, sizeof(airport_terminal->state) - 1);
	// airport_place p = airport_terminal;

	
	/***
	*		return result to places client
	*
	*/
	airport_terminal->next = NULL;
	*apsp = airport_terminal;

// #ifndef	DEBUG
// 	clnt_destroy (clnt);
// #endif	 /* DEBUG */

	return &result;
}
