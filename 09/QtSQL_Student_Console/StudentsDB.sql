BEGIN TRANSACTION;
CREATE TABLE Student (likeSubject NUMERIC, id INTEGER PRIMARY KEY, name TEXT, surname TEXT);


INSERT INTO Student VALUES(1,1,'Иван','Иванов');
INSERT INTO Student VALUES(4,2,'Пётр','Петров');

CREATE TABLE Subject (Количество_уроков NUMERIC, name TEXT, id INTEGER PRIMARY KEY);
INSERT INTO Subject VALUES(NULL,'История',1);
INSERT INTO Subject VALUES(2,'География',2);
INSERT INTO Subject VALUES(NULL,'Музыка',3);
INSERT INTO Subject VALUES(NULL,'Информатика',4);
INSERT INTO Subject VALUES(NULL,'Интересный предмет',5);
INSERT INTO Subject VALUES(NULL,'Труд',6);
COMMIT;
