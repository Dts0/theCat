#ifndef TYPE_H
#define TYPE_H

#include <string>
#include <map>

typedef struct skill{
	bool (*judgeFunc)(std::string cmd);
	std::string (*execFunc)(int numP,...);
	std::string introduce;
	std::string reply_success;
	std::string reply_faith;
} skill;

extern std::map<std::string,skill> skills;

#endif // !TYPE_H
