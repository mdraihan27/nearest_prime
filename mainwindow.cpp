#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

long long int num, count, primes, primel, res;

void MainWindow::on_enternum_clicked()
{
    num=ui->numbox->text().toInt();
    if(num == 1){
        res=2;
         ui->resbox->setText(QString::number(res));
    } else if(num == 2){
        res=2;
          ui->resbox->setText(QString::number(res));
    } else if(num == 0){
        res=2;
           ui->resbox->setText(QString::number(res));
    }else if(num==3){
        res=3;
            ui->resbox->setText(QString::number(res));
    } else {

        num=ui->numbox->text().toInt();

        for(long long int i = num ; i>=num ; i++){

            count = 0;
            for(long long int j=2 ; j<i ; j++){
                if(i%j == 0){
                    count++;
                }
            }
            if(count == 0){
                primel=i;
                break;
            }

        }

        for(long long int i=(num-1); i>=3 ; i--){
            count=0;
            for(long long int j=2 ; j<i ; j++){
                if(i%j==0){
                    count++;
                }
            }
            if(count==0){
                primes=i;
                break;
            }
        }

        if((primel-num)==(num-primes)){

            QString dualres = QString::number(primes)+" & "+QString::number(primel);
            ui->resbox->setText(dualres);

        } else{
            if((primel-num)>(num-primes)){
                res=primes;
            }else if ((primel-num)<(num-primes)){
                res=primel;
            }

            ui->resbox->setText(QString::number(res));
        }
    }


}

