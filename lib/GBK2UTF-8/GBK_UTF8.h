#ifndef GBK_UTF8
#define GBK_UTF8

#include <string>

std::string GBK2UTF_8(std::string gbk);
std::string UTF_82GBK(std::string utf8);
std::string UTF_82GBK_X(std::string utf8,bool upper=true);
std::string GBK2UTF_8_X(std::string gbk,bool upper=true);

int u2g(const char *inbuf,char *outbuf,size_t outlen);
int g2u(const char *inbuf,char *outbuf,size_t outlen);

#endif // !GBK_UTF8
