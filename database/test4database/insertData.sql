insert into command(cmdString) values("testCmd1");
insert into relation(intent,command) values("test1",(select id from command where cmdString="testCmd1"));

insert into command(cmdString) values("testCmd1_2");
insert into relation(intent,command) values("test1",(select id from command where cmdString="testCmd1_2"));

insert into command(cmdString) values("testCmd2");
insert into relation(intent,command) values("test2",(select id from command where cmdString="testCmd2"));

select relation.id,relation.intent,command.cmdString from relation,command where intent="test1" and command.id=relation.command
