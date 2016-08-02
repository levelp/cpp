#include <QCoreApplication>
#include <QFile>
#include <QString>
#include <QTextStream>

class Sort {
 public:
  int N; // Количество элементов
  long* A; // Элементы массива

  void load(QString fileName) {
    QFile file(fileName);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    in >> N;
    A = new long[N];
    for(int i = 0; i < N; i++)
      in >> A[i];
    file.close();
  }

  void save(QString fileName) {
    QFile file(fileName);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    out << N << endl;
    for(int i = 0; i < N; i++)
      out << A[i] << " ";
    out << endl;
    file.close();
  }

  // Сортировка
  virtual void execute() = 0;
};

class BubbleSort : public Sort {
  // Сортировка
  void execute() {
    for(int i = 0; i < N; i++)
      for(int j = i + 1; j < N; j++)
        if(A[i] > A[j])
          A[i] ^= A[j] ^= A[i] ^= A[j];
  }
};

class InsertSort : public Sort {
  // Сортировка
  void execute() {
    bool changes = false;
    do {
      changes = false;
      for(int i = 0; i < N - 1; i++)
        if(A[i] > A[i + 1]) {
          A[i] ^= A[i + 1] ^= A[i] ^= A[i + 1];
          changes = true;
        }
    } while(changes);
  }
};

int main(int argc, char* argv[]) {
  Sort* sort[2] = { new BubbleSort(), new InsertSort() };

  for(int i = 0; i < 2; i++) {
    sort[i]->load("in.txt");
    sort[i]->execute();
    sort[i]->save("out.txt");

    delete sort[i];
  }

  return 0;
}
