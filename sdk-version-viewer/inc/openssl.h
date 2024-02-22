#ifndef OPENSSL_H
#define OPENSSL_H
#include <stdio.h>

int ssl_client_oneway();
int ssl_client_twoway();
int ssl_server_oneway ();
int ssl_server_twoway ();

int https_get_request_wait_rsp(char *ip,char *name,int portnumber,char *capath,char *keypath,char *get_str,char *rsp_str,int rsp_buf_len);


#endif
