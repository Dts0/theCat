#ifndef SKILL_H
#define SKILL_H

#include <string>
#include <map>
#include <list>

extern int _skillId;//最后一个加载的技能的id号，同时代表技能的优先级，号越小优先级越高，需要在init时初始化为0
extern const int MaxSkillId;//技能未定义指令的skillId,指示了技能的最大数量

typedef struct skill_t{
	int id;//自动生成
	bool (*judgeFunc)(std::string cmd);//判定函数,判断是否符合执行条件,当然,您也可以在这里面顺便填充pList
	std::string (*execFunc)(int numP,std::list<long> pList);//执行函数,返回值是返回的回复
	int numP;
	std::list<long> pList;//执行函数的输入参数列表,您只能输入整数,并且应当处理所有情况的输入
	std::string name;
	std::string introduce;
} skill_t;

extern std::map<int,skill_t> skills;

void skillInit();

bool loadSkill(skill_t skill,int skillId=(++_skillId));
bool unloadSkill(std::string skillName);
bool unloadSkill(int skillId);
bool unloadSkill(skill_t skill);

void DB_showSkills();

#endif // !SKILL_H
