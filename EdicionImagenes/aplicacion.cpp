#include "aplicacion.h"
#include "ui_aplicacion.h"
#include <QFileDialog>

Aplicacion::Aplicacion(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Aplicacion)
{
    ui->setupUi(this);
    escenaPrimeraImagen = new QGraphicsScene(this);
}

Aplicacion::~Aplicacion()
{
    delete ui;
}

void Aplicacion::on_pushButtonSeleccionarImagen_clicked()
{
    QString rutaImagen = QFileDialog::getOpenFileName(this,
                                                      tr("Abrir Imagen"),
                                                      "/Users/fernandovargas/Desktop",
                                                      tr("Archivos de imagen (*.jpg)"));
    primeraImagen = new QPixmap(rutaImagen);
    imagenAtratar = new QImage(rutaImagen);
    escenaPrimeraImagen->addPixmap(*primeraImagen);
    ui->graphicsViewPrimeraImagen->setScene(escenaPrimeraImagen);

    obtenerAnchoImagen();
}

void Aplicacion::obtenerAnchoImagen()
{
    int anchoImagen = imagenAtratar->width();
    int tipoFormatoImagen = imagenAtratar->format();
    ui->textEditInformacionImagen->setText("El ancho de la imagen es: " + QString::number(anchoImagen) +
                                           "\ny el formato es: " + QString::number(tipoFormatoImagen));
}
