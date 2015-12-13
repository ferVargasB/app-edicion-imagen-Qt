#ifndef APLICACION_H
#define APLICACION_H

#include <QMainWindow>
#include <QGraphicsScene>

namespace Ui {
class Aplicacion;
}

class Aplicacion : public QMainWindow
{
    Q_OBJECT

public:
    explicit Aplicacion(QWidget *parent = 0);
    ~Aplicacion();

private slots:
    void on_pushButtonSeleccionarImagen_clicked();

private:
    Ui::Aplicacion *ui;
    QPixmap *primeraImagen;
    QGraphicsScene *escenaPrimeraImagen;
    QImage *imagenAtratar;


    void obtenerAnchoImagen();
};

#endif // APLICACION_H
