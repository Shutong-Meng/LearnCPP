# SQL(Structured Query Language)       
*大小写不敏感*  
  
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
通配符:  %	替代0个或多个字符    _ 替代一个字符   [charlist] 字符列中的任何单一字符   [^charlist]或[!charlist]	不在字符列中的任何单一字符  
SELECT column_name(s) FROM table_name WHERE column_name IN (value1,value2,...); 在where子句中规定多个值  
SELECT column_name(s) FROM table_name WHERE column_name BETWEEN value1 AND value2; (数值 文本或日期)  
SELECT column_name AS alias_name FROM table_name; 别名  
  
*SQL JOIN:*  
INNER JOIN：如果表中有至少一个匹配，则返回行  
LEFT JOIN：即使右表中没有匹配，也从左表返回所有的行  
RIGHT JOIN：即使左表中没有匹配，也从右表返回所有的行  
FULL JOIN：只要其中一个表中存在匹配，则返回行  
  
*SQL UNION:*   
UNION操作符用于合并两个或多个SELECT语句的结果集。UNION内部的每个SELECT语句必须拥有相同数量的列。列也必须拥有相似的数据类型。默认地，UNION操作符选取不同的值。如果允许重复的值，请使用UNION ALL。UNION结果集中的列名总是等于UNION中第一个SELECT语句中的列名。  
SELECT column_name(s) FROM table1 UNION SELECT column_name(s) FROM table2;  
  
INSERT INTO SELECT语句从一个表复制数据，然后把数据插入到一个已存在的表中  
INSERT INTO table2 (column_name(s)) SELECT column_name(s) FROM table1;  
INSERT INTO table2 SELECT * FROM table1;  
CREATE DATABASE dbname;创建数据库
  
*创建表*  
CREATE TABLE table_name
(
column_name1 data_type(size) constraint_name,
column_name2 data_type(size) constraint_name,
column_name3 data_type(size) constraint_name,
....
);  
  
*约束*  
NOT NULL - 指示某列不能存储NULL值。  
UNIQUE - 保证某列的每行必须有唯一的值。每个表可以有多个UNIQUE约束，但是每个表只能有一个PRIMARY KEY约束。  
PRIMARY KEY - NOT NULL和UNIQUE的结合。确保某列（或两个列多个列的结合）有唯一标识，有助于更容易更快速地找到表中的一个特定的记录。  
ALTER TABLE Persons ADD/DROP PRIMARY KEY (P_Id) 已经创建表后添加或删除primary key约束  
FOREIGN KEY - 一个表中的FOREIGN KEY指向另一个表中的UNIQUE KEY(唯一约束的键)。保证一个表中的数据匹配另一个表中的值的参照完整性。  
CREATE TABLE Orders
(
O_Id int NOT NULL,
OrderNo int NOT NULL,
P_Id int,
PRIMARY KEY (O_Id),
FOREIGN KEY (P_Id) REFERENCES Persons(P_Id)
)  
ALTER TABLE Orders ADD FOREIGN KEY (P_Id) REFERENCES Persons(P_Id)  
CHECK - 保证列中的值符合指定的条件。  
DEFAULT - 规定没有给列赋值时的默认值。  
AUTO_INCREMENT - 主键自动创建并增加
  
CREATE INDEX index_name ON table_name (column_name)创建索引  
ALTER TABLE table_name DROP INDEX index_name删除索引  
DROP TABLE table_name删除表及数据库...  
  
*增加 删除 修改列*  
ALTER TABLE table_name ADD column_name datatype  
ALTER TABLE table_name DROP COLUMN column_name  
ALTER TABLE table_name MODIFY COLUMN column_name datatype  
  
*sql通用数据类型*  
CHARACTER(n)	字符/字符串。固定长度 n。  
VARCHAR(n) 或 CHARACTER VARYING(n)	字符/字符串。可变长度。最大长度 n。  
BINARY(n)	二进制串。固定长度 n。  
BOOLEAN	存储 TRUE 或 FALSE 值。  
VARBINARY(n) 或 BINARY VARYING(n)	二进制串。可变长度。最大长度 n。  
INTEGER(p)	整数值（没有小数点）。精度 p。  
SMALLINT	整数值（没有小数点）。精度 5。  
INTEGER	整数值（没有小数点）。精度 10。  
BIGINT	整数值（没有小数点）。精度 19。  
DECIMAL(p,s)	精确数值，精度 p，小数点后位数 s。例如：decimal(5,2) 是一个小数点前有 3 位数小数点后有 2 位数的数字。  
NUMERIC(p,s)	精确数值，精度 p，小数点后位数 s。（与 DECIMAL 相同）  
FLOAT(p)	近似数值，尾数精度 p。一个采用以 10 为基数的指数计数法的浮点数。该类型的 size 参数由一个指定最小精度的单一数字组成。  
REAL	近似数值，尾数精度 7。  
FLOAT	近似数值，尾数精度 16。  
DOUBLE PRECISION	近似数值，尾数精度 16。  
DATE	存储年、月、日的值。  
TIME	存储小时、分、秒的值。  
TIMESTAMP	存储年、月、日、小时、分、秒的值。  
INTERVAL 由一些整数字段组成，代表一段时间，取决于区间的类型。  
ARRAY	元素的固定长度的有序集合。  
MULTISET 元素的可变长度的无序集合。  
XML	存储XML数据。  








