Регулярные выражения
====================

Поиск e-mail
------------

(\w+@(?:\w+\.)+\w+) \-? (\w+)

mail1@mail.ru - Petrov  mail2@mail.ru.com  Ivanov
mail2@mail.ru.ww.com - Sidorov

>> mail1@mail.ru  Petrov
>> mail2@mail.ru.com  Ivanov
>> mail2@mail.ru.ww.com  Sidorov

PCRE - Perl Comp Reg Exp