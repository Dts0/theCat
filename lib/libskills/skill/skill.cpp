#include "skill.h"
#include <iostream>

using namespace std;

std::map<int,skill_t> skills;
int _skillId;

void skillInit(){
	_skillId=0;
}

bool loadSkill(skill_t skill,int skillId){
	skill.id=skillId;
	skills.insert(map<int,skill_t>::value_type(skillId,skill));
	return true;
}

bool unloadSkill(skill_t skill){
	return unloadSkill(skill.id);
}

bool unloadSkill(string skillName){
    map<int, skill_t>::iterator iter;
	for(iter=skills.begin();iter!=skills.end();iter++)
		if(iter->second.name==skillName){
			skills.erase(iter);
			return true;
		}
	return false;
}
bool unloadSkill(int skillId){
    map<int,skill_t>::iterator iter;
	iter=skills.find(skillId);

	if(iter==skills.end())
		return false;
	skills.erase(iter);
	return true;
}

void DB_showSkills(){
	map<int,skill_t>::iterator iter;
	cout<<"id\tname\t\tintroduce\n";
	for(iter=skills.begin();iter!=skills.end();iter++){
		cout<<iter->first<<"\t"<<iter->second.name<<"\t\t"<<iter->second.introduce;
		cout<<endl;
	}
}
