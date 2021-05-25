#include "mainwindow.h"
#include "car.h"
#include "ui_mainwindow.h"
#include "datareader.h"
#include "datawriter.h"
#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include <QFileDialog>
#include "jsonreader.h"
#include "errbrowser.h"
#include "complexdll.h"
#include "errortaker.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto var = Make_enum_To_String();
    for(const auto& v:var){
        ui->comboBox_car_color->addItem(QString(v.c_str()));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

//on_Button_Find_clicked()
void MainWindow::on_pushButton_clicked()
{
//    DataReader datareader(std::string("input.csv"));
//    std::vector<Car> Array_Of_Car;
//    std::string read_string;
//    getline(datareader.GetInput(), read_string);
//        while (read_string.size()>0) {
//            auto struct_base = split(read_string, SPLITTER);
//            if (struct_base.size() == CAR_SPLITTER_COUNT) {
//                Array_Of_Car.push_back(make_car(struct_base[0], struct_base[1], struct_base[2], struct_base[3]));
//            }
//            getline(datareader.GetInput(), read_string);
//        }
//    std::string find_str =
//            ui->lineEdit_find_data->text().toStdString();
//    auto it = std::find_if(Array_Of_Car.begin(),Array_Of_Car.end(),[find_str](const Car& now){
//         return now.GetModel() == find_str;
//    });
//    if (it == Array_Of_Car.end()){
//        ui->label_find_data->setText("Элемент не найден");
//    }
//    else    {
//        std::string str = it->Print();
//        ui->label_find_data->setText(QString(str.c_str()));
//    }
}

void MainWindow::on_pushButton_find_clicked()
{
    ErrorTaker et;
    std::function<void()> func = std::bind(&MainWindow::on_pushButton_find_clicked_func,this);
    et.Error_Check(func,ui->errBrowser);
}

void MainWindow::on_pushButton_write_clicked()
{
    ErrorTaker et;
    std::function<void()> func = std::bind(&MainWindow::clicked_func,this);
    et.Error_Check(func,ui->errBrowser);
}

void MainWindow::on_Button_Change_File_clicked()
{
    QString fn = QFileDialog::getOpenFileName(this, tr("Open File"),"/input","Text files (*.csv));;JSON files (*.json)");
    ui->errBrowser->append(fn);
    std::string str = fn.toStdString();
    auto info = split(str,'.');
    std::vector<Car> cars;
    auto name_file = split(str,'/');
    ui->label->setText(QString(name_file.back().c_str()));
    if(info.back() == "csv"){
        DataReader dr(str);
        cars = dr.read();
    }
    else if(info.back() == "json"){
        jsonReader jr(fn.toStdString());
        cars = jr.read();
    }
    for(auto& c:cars){
        ui->errBrowser->append(QString(c.Print().c_str()));
    }
}

void MainWindow::on_pushButton_Filename_Choose_clicked()
{
    {
        Car c;
        DataReader rd("input.csv");
        while(rd>>c){
            std::cout<<c<<std::endl;
        }
    }

}

void MainWindow::clicked_func()
{

    DataReader datareader(std::string("input.csv"));
    std::vector<Car> Array_Of_Car = ReadArray<Car>(datareader);
    sort_car(Array_Of_Car);
    int number = Array_Of_Car.size() == 0 ? 0 : Array_Of_Car.back().GetNumber() + 1;
    std::string model = ui->lineEdit_car_model->text().toStdString();
    if(model.size()==0){
        return;
    }
    int year = ui->spinBox_car_year->value();
    int clr = ui->comboBox_car_color->currentIndex();
    Array_Of_Car.push_back((make_car(std::to_string(number),model,
                                    std::to_string(clr),std::to_string(year))));
    DataWriter datawriter(std::string("output.csv"));
    for(auto& c:Array_Of_Car){
        datawriter.WriteFile(c);
    }
}

void MainWindow::on_pushButton_find_clicked_func()
{
    DataReader datareader(std::string("input.csv"));
    std::vector<Car> Array_Of_Car = (ReadArray<Car>(datareader));

    std::string find_str =
            ui->lineEdit_find_data->text().toStdString();
    auto it = std::find_if(Array_Of_Car.begin(),Array_Of_Car.end(),
                           [find_str](const Car& now){
         return now.GetModel() == find_str;
    });
    if (it == Array_Of_Car.end()){
        ui->errBrowser->WriteError("Error");
        ui->errBrowser->append("Error");
        //ui->label_find_data->setText("Элемент не найден");
    }
    else    {
        std::string str = it->Print();
        ui->label_find_data->setText(QString(str.c_str()));
    }
}
