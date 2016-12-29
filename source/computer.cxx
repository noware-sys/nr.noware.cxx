//#pragma once

#include "computer.hxx"
//#include "any.cxx"
//#include "db/sqlite.cxx"

const std::string noware::computer::query_sql_initial = //"";
//const std::string noware::computer::sql1 = //"";
			"\
				begin transaction;\
			\
			-- drop table if exists entity;\
			create table if not exists entity\
			(\
				 \"group\" 						none null default null,	-- group id\
				 \
				\"name: type\" 		none null default null,\
				 name 						none null default null,	-- name key\
				 \
				\"content: type\"		none null default null,\
				 content 					none null default null	-- content value\
			);\
			\
			-- (compound key) id[entification] uni[queness] element/entry/row /entity\
			-- drop index if exists \"entity: id\";\
			create unique index if not exists \"entity: id\" on entity (\"group\", name);\
			\
			commit transaction;\
			"
;

noware::computer::computer (void)
{
	//std::cout << "memory.query: " << 
	if (science.connect ("science.db"))
	{
		science.query (query_sql_initial);
		//memory.query (sql1);
		/*
		(
			"\
				begin transaction;\
			\
			-- drop table if exists entity;\
			create table if not exists entity\
			(\
				 id 						none null default null,	-- group id\
				 \
				\"key: type\" 		none null default null,\
				 key 						none null default null,	-- name key\
				 \
				\"value: type\"		none null default null,\
				 value 					none null default null	-- content value\
			);\
			\
			-- drop index if exists \"entity: id\";\
			create unique index if not exists \"entity: id\" on entity (id, key);\
			\
			commit transaction;\
			"
		);
		*/
	}
	
	// << std::endl;
}

noware::computer::~computer (void)
{
}

const noware::any noware::computer::evaluate (const noware::any & expression)
{
	return "";
}

/*
const bool good (/*action?* /)
{
	return true;
}
*/

