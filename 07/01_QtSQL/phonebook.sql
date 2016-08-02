DROP TABLE IF EXISTS "contacts";
CREATE TABLE "contacts" ("id" INTEGER PRIMARY KEY NOT NULL,
  "surname" TEXT,
  "name" TEXT,
  "middlename" TEXT,
  "sex" VARCHAR(1) DEFAULT ('M') );
INSERT INTO "contacts" VALUES(1,'Иванов','Иван','Иванович','M');
INSERT INTO "contacts" VALUES(2,'Петров','Иван','Иванович','M');
INSERT INTO "contacts" VALUES(3,'Сидоров','Иван','Иванович',NULL);
INSERT INTO "contacts" VALUES(4,'Иванов','Иван','Иванович',NULL);
INSERT INTO "contacts" VALUES(6,'Иванова','Мария','Петровна','F');
INSERT INTO "contacts" VALUES(7,'Иванова','Ирина','Олеговна','F');
DROP TABLE IF EXISTS "phone_type";
CREATE TABLE "phone_type" ("id" INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL  UNIQUE , "name" TEXT NOT NULL );
INSERT INTO "phone_type" VALUES(1,'Рабочий телефон');
INSERT INTO "phone_type" VALUES(2,'Мобильный телефон');
INSERT INTO "phone_type" VALUES(3,'Домашний телефон');
DROP TABLE IF EXISTS "phones";
CREATE TABLE "phones" ("id" INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL  UNIQUE , "id_contact" INTEGER NOT NULL , "phone" TEXT, "id_type" INTEGER NOT NULL );
INSERT INTO "phones" VALUES(1,1,'79111234567',1);
