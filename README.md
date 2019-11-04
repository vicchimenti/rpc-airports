# rpc-airports

test only

## Places_Server Error

When calling airports_client from within:

```
	result_1 = getairports_1(&getairports_1_arg, clnt);
	if (result_1 == (airports_ret *) NULL) {
		clnt_perror (clnt, "call failed");
	}
```

Error Message:

```
places_server.o: In function `callplaces_1_svc':
/home/st/chimenti/5520/hw/hw4/v2/places_server.c:54: undefined reference to `getairports_1'
```
