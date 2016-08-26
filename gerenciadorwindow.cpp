#include "gerenciadorwindow.h"
#include "ui_gerenciadorwindow.h"
#include "string.h"
#include "strings.h"
#include "iostream"

using namespace std;

string ps = "ps ";

GerenciadorWindow::GerenciadorWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GerenciadorWindow)
{
    ui->setupUi(this);
}

GerenciadorWindow::~GerenciadorWindow()
{
    delete ui;
}

void GerenciadorWindow::atualizaLista(){
    ui->listComandos->clear();
    char url[]="comandos.txt", ch;
    string linha="";
    FILE *arq;

    arq = fopen(url, "r");
    if(arq == NULL)
       printf("Erro, nao foi possivel abrir o arquivo\n");
    else{
       while((ch=fgetc(arq))!= EOF ){
           if(ch == '\n'){
               QString qlinha = QString::fromStdString(linha);
               ui->listComandos->addItem(qlinha);
               linha = " ";
           }
           linha = linha + ch;

       }
    }
    fclose(arq);
    QString espaco = QString::fromStdString(" ");
    ui->listComandos->addItem(espaco);
}

void GerenciadorWindow::enviaComando(){

    ps = "ps ";
   /* if(ui->textComando->text() != ""){
        ps = ps + " | ";
    }
    else{
        ps = "ps";
    }*/

    ui->listComandos->addItem(ps.c_str()+ui->textComando->text());
    string cmd = ps+ui->textComando->text().toStdString() + " > comandos.txt";
    ps = cmd;
    const char* cmd1 = cmd.c_str();
    system(cmd1);
    atualizaLista();
    ui->textComando->clear();

    startTimer(1000);
}

void GerenciadorWindow::timerEvent(QTimerEvent *e){
    const char* cmd1 = ps.c_str();
    system(cmd1);
    atualizaLista();
}

void GerenciadorWindow::atualizaView(){

}

void GerenciadorWindow::mataProcesso(){

  // ui->listComandos->addItem(ui->textPID->text());
   string cmd = "kill -9 "+ui->textPID->text().toStdString();
   const char* cmd_sys = cmd.c_str();
   system(cmd_sys);
   ui->textPID->clear();

}

void GerenciadorWindow::pausaProcesso(){

    string cmd = "kill -STOP "+ui->textPID->text().toStdString();
    const char* cmd_sys = cmd.c_str();
    system(cmd_sys);
    ui->textPID->clear();

}

void GerenciadorWindow::continuaProcesso(){

    string cmd = "kill -CONT "+ui->textPID->text().toStdString();
    const char* cmd_sys = cmd.c_str();
    system(cmd_sys);
    ui->textPID->clear();
}
