#include "gerenciadorwindow.h"
#include <QApplication>

void *thread_function(void *arg);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GerenciadorWindow w;
    w.show();


    return a.exec();
}

void *thread_function(void *arg) {
    printf("THREAD--> ATIVA");
}
