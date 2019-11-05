# rpc-airports

Discovered struct coordinates needs a pointer in dot x file, will move forward in new repo and retain this repo for now

## Roundtrip Successfull!

We have a roundtrip that works, I was passing a char* to a city_name type without casting ... duh!

### Current Results:

```
[chimenti@cs1 v2]$ ./places_client localhost Seattle WA
city = Seattle, state= WA

Places Server Side: Received city= Seattle, received state= WA

Places Server side: Assigned city= Seattle, assigned state= WA

places server side: assigned getairports_1_arg.lat= 122.700000, assigned getairports_1_arg.lon= 54.400000

Airport Server Side: received lat= 122.700000, received lon= 54.400000

Airport Server side: assigned lat= 122.700000, assigned lon= 54.400000

/*assign airport structures*/

airport* ap = &result.airports_ret_u.airport;

airport p;

p = (airportnode *)malloc(sizeof(airportnode));

Airport server side: p->city= Portland, p->state= OR

p->next = NULL;

*ap = p;

Returning

Places Client: p->city = Portland, p->state= OR

Server Response: City is Portland, State is OR
[chimenti@cs1 v2]$
```

