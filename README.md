# rpc-airports

Discovered struct coordinates needs a pointer in dot x file, will move forward in new repo and retain this repo for now

## Roundtrip Error

We are getting good data across the socket now from places_server to airports server as we can see below. But are not getting a connection refused

### Current Results:

```
[chimenti@cs1 v2]$ ./places_client localhost Seattle WA
city = Seattle, state= WA

Places Server Side: Received city= Seattle, received state= WA

Places Server side: Assigned city= Seattle, assigned state= WA

places server side: assigned getairports_1_arg.lat= 122.000000, assigned getairports_1_arg.lon= 54.000000

Airport Server Side: received lat= 122.000000, received lon= 54.000000

Airport Server side: assigned lat= 122.000000, assigned lon= 54.000000

Airport server side: p->city= ��w��, p->state= 0�
call failed: RPC: Unable to receive; errno = Connection refused
call failed: RPC: Unable to receive; errno = Connection refused
[1]-  Segmentation fault      ./airports_server
[2]+  Segmentation fault      ./places_server
Segmentation fault
[chimenti@cs1 v2]$ 
```

