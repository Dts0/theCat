#ifndef DEVICE_H
#define DEVICE_H
#include <string>
#include <map>

extern int _deviceId;
extern int maxDeviceId;

typedef struct device_t{
	int id;
	std::string ip;
	std::string name;
	std::string introduce;
} device_t;

extern std::map<int,device_t> devices;

#endif // !DEVICE_H
