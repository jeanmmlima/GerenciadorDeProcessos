#ifndef GERENCIADORWINDOW_H
#define GERENCIADORWINDOW_H

#include <QMainWindow>
#include <stdlib.h>
#include <sys/aio.h>

namespace Ui {
class GerenciadorWindow;
}

class GerenciadorWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GerenciadorWindow(QWidget *parent = 0);
    ~GerenciadorWindow();
    //metodo para atualizar o widget list
    void atualizaLista();
    void timerEvent(QTimerEvent *e);


public slots:
    void enviaComando();
    void mataProcesso();
    void pausaProcesso();
    void continuaProcesso();
    void atualizaView();

private:
    Ui::GerenciadorWindow *ui;
};

#endif // GERENCIADORWINDOW_H
