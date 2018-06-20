#include "GBK_UTF8.h"
#include <stdlib.h>
#include <memory.h>
#include <iconv.h>
#include <string.h>
#include <stdio.h>
using namespace std;


int code_convert(char *from_charset,char *to_charset,const char *inbuf,size_t inlen,char *outbuf,size_t outlen)
{
        iconv_t cd;
        char **pin = (char**)&inbuf;
        char **pout = &outbuf;

        cd = iconv_open(to_charset,from_charset);
        if (cd==0)
                return -1;
        memset(outbuf,0,outlen);
        if (iconv(cd,pin,&inlen,pout,&outlen) == (size_t)-1)
                return -1;
        iconv_close(cd);
        return 0;
}

int u2g(const char *inbuf,char *outbuf,size_t outlen)
{
        return code_convert((char*)"utf-8",(char*)"gb2312",inbuf,strlen(inbuf),outbuf,outlen);
}

int g2u(const char *inbuf,char *outbuf,size_t outlen)
{
        return code_convert((char*)"gb2312",(char*)"utf-8",inbuf,strlen(inbuf),outbuf,outlen);
}


const size_t maxLength=100;
std::string GBK2UTF_8(std::string gbk){
    char buf[maxLength];
    string ret;
    if(g2u(gbk.c_str(),buf,maxLength)!=-1)
        return string(buf);
    return string("err");
}
std::string UTF_82GBK(std::string utf8){
    char buf[maxLength];
    string ret;
    if(u2g(utf8.c_str(),buf,maxLength)!=-1)
        return string(buf);
    return string("err");
}
std::string UTF_82GBK_X(std::string utf8,bool upper){
    char buf[maxLength];
	u2g(utf8.c_str(),buf,maxLength);
    char buf2_2[maxLength]="";

	if(upper)
		for(unsigned int i=0;i<strlen(buf);i++)
			sprintf(buf2_2,"%s%%%X%",buf2_2,(buf[i])&0xff);
	else
		for(unsigned int i=0;i<strlen(buf);i++)
			sprintf(buf2_2,"%s%%%x%",buf2_2,(buf[i])&0xff);
	return string(buf2_2);
}
std::string GBK2UTF_8_X(std::string gbk,bool upper){
    char buf[maxLength];
	g2u(gbk.c_str(),buf,maxLength);
    char buf2_2[maxLength]="";

	if(upper)
		for(unsigned int i=0;i<strlen(buf);i++)
			sprintf(buf2_2,"%s%%%X%",buf2_2,(buf[i])&0xff);
	else
		for(unsigned int i=0;i<strlen(buf);i++)
			sprintf(buf2_2,"%s%%%x%",buf2_2,(buf[i])&0xff);
	return string(buf2_2);
}
