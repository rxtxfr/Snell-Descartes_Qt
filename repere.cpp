#include <math.h>
#include <iostream>
#include <QtWidgets>

#include "repere.h"

Repere::Repere(QWidget *parent)
    : QWidget(parent)
{
    angleIncident = 10;
    Vitesse_1 = 300000000;
    Vitesse_2 = 300000000;
    angle_Refracte = 0;

    drawReflechi = false;
    drawRefracte = true;
    drawArcs = false;

    computeRefracted();
}

void Repere::SetIncident(int degre){

    angleIncident = degre;

    computeRefracted();
}


void Repere::setV1(int V1){

    Vitesse_1 = V1;

    computeRefracted();
}

double Repere::getRefracte2(){

    return angle_Refracte;
}

void Repere::setV2(int V2){

    Vitesse_2 = V2;

    computeRefracted();
}


void Repere::computeRefracted(){

    double angle = (Vitesse_2 * ( sin((float)(TO_RAD(angleIncident))) / Vitesse_1 ) );

    if(angle <= -1 || angle >= 1)
        angle_Refracte = 90;
    else
        angle_Refracte = TO_DEG( asin((float)(angle)) );

    update();

}

void Repere::checkReflechi(int check){

    if( check == Qt::Checked )
        drawReflechi = true;
    else
        drawReflechi = false;

    update();
}

void Repere::checkRefracte(int check){

    if( check == Qt::Checked )
        drawRefracte = true;
    else
        drawRefracte = false;
    update();
}

void Repere::checkArcs(int check){

    if( check == Qt::Checked )
        drawArcs = true;
    else
        drawArcs = false;
    update();
}

void Repere::paintEvent(QPaintEvent *)

{

    QColor noir(0, 0, 0);
    QColor rouge(255, 0, 0);
    QColor vert(8, 138, 8);
    QColor bleu(0, 0, 255);
    QColor orange(255, 128, 0 );

    QColor minuteColor(0, 127, 127, 191);

    int side = qMin(width(), height());

    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);

    painter.translate(width() / 2, height() / 2);

    painter.scale(side / 200.0, side / 200.0);


    painter.setPen(noir);
    painter.drawLine(-width() + 120, 0, width() - 80, 0);
    painter.drawLine(0, -height() + 80, 0, height() - 80);

    QFont font = painter.font();
    painter.setRenderHint(QPainter::TextAntialiasing);
    font.setPixelSize(6);
    painter.setFont(font);
    painter.setPen(bleu);
    const QRect rectangle1 = QRect(-120, -10, 100, 50);
    QRect boundingRect1;
    painter.drawText(rectangle1, 0, tr("Milieu 1"), &boundingRect1);

    const QRect rectangle2 = QRect(-120, 3, 100, 50);
    QRect boundingRect2;
    painter.drawText(rectangle2, 0, tr("Milieu 2"), &boundingRect2);

    // Rayon incident
    painter.setPen(rouge);
    painter.rotate(90-angleIncident);
    painter.drawLine(-90, 0, 0, 0);
    painter.drawLine(-50, 4, -40, 0);
    painter.drawLine(-50, -4, -40, 0);

    if( drawReflechi ){

        // Rayon reflechi
        QPainter painterReflechi(this);

        painterReflechi.setRenderHint(QPainter::Antialiasing);
        painterReflechi.translate(width() / 2, height() / 2);
        painterReflechi.scale(side / 200.0, side / 200.0);

        painterReflechi.setPen(bleu);
        painterReflechi.rotate(angleIncident-90);
        painterReflechi.drawLine(90, 0, 0, 0);
        painterReflechi.drawLine(20, 4, 30, 0);
        painterReflechi.drawLine(20, -4, 30, 0);
    }

    if( drawRefracte ){
        // Rayon refracte L
        QPainter painterRefracte(this);

        painterRefracte.setRenderHint(QPainter::Antialiasing);
        painterRefracte.translate(width() / 2, height() / 2);
        painterRefracte.scale(side / 200.0, side / 200.0);

        painterRefracte.setPen(vert);
        painterRefracte.rotate(-270-angle_Refracte);
        painterRefracte.drawLine(90, 0, 0, 0);
        painterRefracte.drawLine(65, 4, 75, 0);
        painterRefracte.drawLine(65, -4, 75, 0);
    }


    if( drawArcs ){

        QPainter painterArcIncident(this);
        painterArcIncident.setRenderHint(QPainter::Antialiasing);
        painterArcIncident.translate(width() / 2, height() / 2);
        painterArcIncident.scale(side / 200.0, side / 200.0);

        painterArcIncident.setPen(rouge);
        QRectF rectangle(35.0, 35.0, -70.0, -70.0);
        int startAngle = 90*16;
        int spanAngle = ((angleIncident))*16;
        painterArcIncident.drawArc(rectangle, startAngle, spanAngle);

        if( drawReflechi ){

            QPainter painterArcReflechi(this);
            painterArcReflechi.setRenderHint(QPainter::Antialiasing);
            painterArcReflechi.translate(width() / 2, height() / 2);
            painterArcReflechi.scale(side / 200.0, side / 200.0);

            painterArcReflechi.setPen(bleu);
            QRectF rectReflechi(35.0, 35.0, -70.0, -70.0);
            startAngle = 90*16;
            spanAngle = ((-angleIncident))*16;
            painterArcReflechi.drawArc(rectReflechi, startAngle, spanAngle);
        }

        if( drawRefracte ){

            QPainter painterRefracte(this);
            painterRefracte.setRenderHint(QPainter::Antialiasing);
            painterRefracte.translate(width() / 2, height() / 2);
            painterRefracte.scale(side / 200.0, side / 200.0);

            painterRefracte.setPen(vert);
            QRectF rectRefracte(-30.0, 30.0, 60.0, -60.0);
            startAngle = -90*16;
            spanAngle = ((angle_Refracte))*16;
            painterRefracte.drawArc(rectRefracte, startAngle, spanAngle);

        }
    }
}

