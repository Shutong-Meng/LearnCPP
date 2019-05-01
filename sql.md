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
SELECT * FROM table LIMIT 2;从表中选取头两行记录  
SELECT column_name(s) FROM table_name WHERE column_name LIKE pattern; 搜索指定模式  
SELECT * FROM Websites WHERE name LIKE 'G%';搜索以G开头的  
通配符:   %	替代 0 个或多个字符    _	替代一个字符   [charlist]	字符列中的任何单一字符 [^charlist]或[!charlist]	不在字符列中的任何单一字符  
SELECT column_name(s) FROM table_name WHERE column_name IN (value1,value2,...); 在where子句中规定多个值  
SELECT column_name(s) FROM table_name WHERE column_name BETWEEN value1 AND value2; (数值 文本或日期)  
SELECT column_name AS alias_name FROM table_name; 别名  
SQL JOIN:  
INNER JOIN：如果表中有至少一个匹配，则返回行  
LEFT JOIN：即使右表中没有匹配，也从左表返回所有的行  
RIGHT JOIN：即使左表中没有匹配，也从右表返回所有的行  
FULL JOIN：只要其中一个表中存在匹配，则返回行  
SQL UNION:

