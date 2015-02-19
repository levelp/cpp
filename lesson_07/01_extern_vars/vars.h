#ifndef VARS_H
#define VARS_H

#define SHOW(x) cout << #x << " = " << x << endl;
#define D(x) cout << __FILE__ << ":" << \
                  __FUNCTION__ << " " << #x << endl; x;

/// Глобальная переменная в **vars.h**
///-->
extern int globalVar;
///<--

#endif // VARS_H
