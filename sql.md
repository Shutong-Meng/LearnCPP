# SQL(Structured Query Language)  

大小写不敏感  
SELECT * FROM table  
SELECT column_name FROM table  
SELECT DISTINCT column_name FROM table 用于返回唯一不同的值  
SELECT * FROM table WHERE column_name='c' 从表选取column_name等于c的  
不等于 <>  
AND OR  
SELECT * FROM table ORDER BY column_name; column_name升序排列  
SELECT * FROM table ORDER BY column_name DESC;降序  
INSERT INTO table_name (column1,column2,column3,...) VALUES (value1,value2,value3,...);  
INSERT INTO table_name VALUES (value1,value2,value3,...);  
UPDATE table_name SET column1=value1,column2=value2 WHERE some_column=some_value;更新已存在的记录  
DELETE FROM table_name WHERE some_column=some_value;删除满足条件的某些行  

