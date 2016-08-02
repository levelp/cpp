<!-- doc.py -->
до первого private наследования
privateA = 2; // Недоступен
т.к. private доступны только внутри класса
protected - наследуем класс A
только для себя и наследников
privateA = 2; // Недоступен
т.к. private доступны только внутри класса
В наследнике C доступны те же поля
privateA = 2; // Недоступен
т.к. private доступны только внутри класса
private - наследуем класс A
только для себя (без наследников)
privateA = 2; // Недоступен
т.к. private доступны только внутри класса
Недоступно ничего из A
A -> private B -> public C
publicA = 1;
privateA = 2; // Недоступен
т.к. private доступны только внутри класса
protectedA = 3;
a.privateA = 10; // Недоступно
a.protectedA = 10; // Недоступно
bPublic.privateA = 10; // Недоступно
bPublic.protectedA = 10; // Недоступно
bProtected.publicA = 111;
C.publicA = 12;
[main.cpp](main.cpp)

