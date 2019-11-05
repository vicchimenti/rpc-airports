# rpc-airports

Discovered struct coordinates needs a pointer in dot x file, will move forward in new repo and retain this repo for now

## Roundtrip Error

Called all three programs successfull but it crashed both servers
Getting a call from places server to airports server via localhost, coming up with a solution to callig this correctly will help. The data is not travelling though and our lat-lon double values are undefined or zero.

### Current Results:

```
[chimenti@cs1 v2]$ ./airports_server&
[1] 13154
[chimenti@cs1 v2]$ ./places_server&
[2] 13175
[chimenti@cs1 v2]$ ./places_client localhost Seattle WA
city = Seattle, state= WA

Places Server Side: Received city= Seattle, received state= WA

Places Server side: Assigned city= Seattle, assigned state= WA

places server side: assigned getairports_1_arg.lat= 0, assigned getairports_1_arg.lon= 0

Airport Server Side: received lat= -604773584, received lon= -604773576

Airport Server side: assigned lat= 2147483575, assigned lon= 950483456

Airport server side: p->city= ����, p->state= 0
call failed: RPC: Unable to receive; errno = Connection refused
call failed: RPC: Unable to receive; errno = Connection refused
[1]-  Segmentation fault      ./airports_server
[2]+  Segmentation fault      ./places_server
Segmentation fault
[chimenti@cs1 v2]$ 
```

