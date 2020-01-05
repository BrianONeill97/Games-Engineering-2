-module(records). 
-export([start/0]). 
-record(person, {name = "", address}). 
-record(employee, {person, id}). 

start() ->
	A = [{"A1", "B1"}],
	P =#employee{person=#person{name="John",address="A"},id=1},
	io:fwrite("~p~n",[P#employee.id]).