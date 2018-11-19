#ifndef REPERE_H
#define REPERE_H

#include <QWidget>


#define TO_RAD( deg ) (float)(deg*M_PI/180)
#define TO_DEG( rad ) (float)(rad*180/M_PI)

//! [0]
class Repere : public QWidget
{
    Q_OBJECT
    int angleIncident;
    int Vitesse_1;
    int Vitesse_2;
    double angle_Refracte;

    bool drawReflechi;
    bool drawRefracte;
    bool drawArcs;

public:
    Repere(QWidget *parent = nullptr);

    double getRefracte2();

    void computeRefracted();

signals:

public slots:
    void SetIncident(int degre);
    void setV1(int V1);
    void setV2(int V2);

    void checkReflechi(int);
    void checkRefracte(int);
    void checkArcs(int);

protected:
    void paintEvent(QPaintEvent *event) override;
};
//! [0]

#endif
